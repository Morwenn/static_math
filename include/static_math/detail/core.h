/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef SMATH_DETAIL_CORE_H_
#define SMATH_DETAIL_CORE_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <limits>
#include <type_traits>
#include <static_math/constant.h>
#include "logical_traits.h"

// This header contains very basic functions that are
// often used by many headers but may introduce some
// annoying circular dependencies if not isolated

namespace smath
{
namespace detail
{
    ////////////////////////////////////////////////////////////
    // Trait to delay instantiation of value_type

    template<typename T, typename U>
    struct is_same_value_type:
        std::is_same<
            typename T::value_type,
            typename U::value_type
        >
    {};

    ////////////////////////////////////////////////////////////
    // Absolute value

    template<typename Number>
    constexpr auto abs(Number x)
        -> Number
    {
        return (x >= 0) ? x : -x;
    }

    template<typename Integer, Integer N>
    constexpr auto abs(constant<Integer, N>)
        -> constant<Integer, abs(N)>
    {
        return {};
    }

    ////////////////////////////////////////////////////////////
    // Minimal and maximal values

    template<
        typename T, typename U,
        typename = std::enable_if_t<negation<conjunction<
            is_integral_constant<T>,
            is_integral_constant<U>,
            is_same_value_type<T, U>
        >>::value>
    >
    constexpr auto min(T first, U second)
        -> std::common_type_t<T, U>
    {
        return (first < second) ? first : second;
    }

    template<
        typename T, typename U, typename... Rest,
        typename = std::enable_if_t<negation<conjunction<
            is_integral_constant<T>,
            is_integral_constant<U>,
            is_same_value_type<T, U>
        >>::value>
    >
    constexpr auto min(T first, U second, Rest... rest)
        -> std::common_type_t<T, U, Rest...>
    {
        return (first < second) ?
            detail::min(first, rest...) :
            detail::min(second, rest...);
    }

    template<typename Integer, Integer... Numbers>
    constexpr auto min(constant<Integer, Numbers>...)
        -> constant<Integer, detail::min(Numbers...)>
    {
        return {};
    }

    template<
        typename T, typename U,
        typename = std::enable_if_t<negation<conjunction<
            is_integral_constant<T>,
            is_integral_constant<U>,
            is_same_value_type<T, U>
        >>::value>
    >
    constexpr auto max(T first, U second)
        -> std::common_type_t<T, U>
    {
        return (first > second) ? first : second;
    }

    template<
        typename T, typename U, typename... Rest,
        typename = std::enable_if_t<negation<conjunction<
            is_integral_constant<T>,
            is_integral_constant<U>,
            is_same_value_type<T, U>
        >>::value>
    >
    constexpr auto max(T first, U second, Rest... rest)
        -> std::common_type_t<T, U, Rest...>
    {
        return (first > second) ?
            detail::max(first, rest...) :
            detail::max(second, rest...);
    }

    template<typename Integer, Integer... Numbers>
    constexpr auto max(constant<Integer, Numbers>...)
        -> constant<Integer, max(Numbers...)>
    {
        return {};
    }

    ////////////////////////////////////////////////////////////
    // Whether two values are close

    template<typename T, typename U>
    using lesser_of = std::conditional_t<
        sizeof(T) <= sizeof(U),
        T,
        U
    >;

    template<typename T, typename U>
    constexpr auto is_close(T a, U b)
        -> std::enable_if_t<
            std::is_floating_point<T>::value && std::is_floating_point<U>::value,
            bool
        >
    {
        return smath::detail::abs(a - b) <=
            std::numeric_limits<lesser_of<T, U>>::epsilon() *
            max(smath::detail::abs(a), smath::detail::abs(b));
    }

    template<typename T, typename U>
    constexpr auto is_close(T a, U b)
        -> std::enable_if_t<
            !std::is_floating_point<T>::value || !std::is_floating_point<U>::value,
            bool
        >
    {
        return a == b;
    }

    ////////////////////////////////////////////////////////////
    // Odd & even checks

    template<typename Integer>
    constexpr auto is_even(Integer n)
        -> decltype(auto)
    {
        using namespace constant_literals;
        return not (n % 2_c);
    }

    template<typename Integer>
    constexpr auto is_odd(Integer n)
        -> decltype(auto)
    {
        return not detail::is_even(n);
    }

    ////////////////////////////////////////////////////////////
    // Factorial function

    template<typename Integer>
    constexpr auto factorial(Integer n)
        -> Integer
    {
        Integer res = 1;
        for (Integer i = 2 ; i <= n ; ++i)
        {
            res *= i;
        }
        return res;
    }

    template<typename Integer, Integer N>
    constexpr auto factorial(constant<Integer, N>)
        -> constant<Integer, factorial(N)>
    {
        return {};
    }
}}

#endif // SMATH_DETAIL_CORE_H_
