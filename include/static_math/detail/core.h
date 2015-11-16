/*
 * Copyright (C) 2015 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef SMATH_DETAIL_CORE_H_
#define SMATH_DETAIL_CORE_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <limits>
#include <type_traits>
#include <static_math/constant.h>

// This header contains very basic functions that are
// often used by many headers but may introduce some
// annoying circular dependencies if not isolated

namespace smath
{
namespace detail
{
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

    template<typename T, typename U>
    constexpr auto min(T first, U second)
        -> std::common_type_t<T, U>
    {
        return (first < second) ? first : second;
    }

    template<typename T, typename U, typename... Rest>
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

    template<typename T, typename U>
    constexpr auto max(T first, U second)
        -> std::common_type_t<T, U>
    {
        return (first > second) ? first : second;
    }

    template<typename T, typename U, typename... Rest>
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
            not std::is_floating_point<T>::value || not std::is_floating_point<U>::value,
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
