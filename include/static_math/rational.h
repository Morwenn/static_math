/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
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
#ifndef SMATH_RATIONAL_H_
#define SMATH_RATIONAL_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cmath>
#include <type_traits>
#include <static_math/cmath.h>
#include <static_math/formula.h>

namespace smath
{
    /**
     * @brief Rational numbers
     */
    template<typename T>
    struct rational
    {
        static_assert(std::is_integral<T>::value,
                      "a rational can only contain integral values");

        ////////////////////////////////////////////////////////////
        // Types

        using value_type = T;

        ////////////////////////////////////////////////////////////
        // Constructors

        constexpr rational(value_type numerator);
        constexpr rational(value_type numerator, value_type denominator);

        ////////////////////////////////////////////////////////////
        // Cast

        constexpr explicit operator float() const;
        constexpr explicit operator double() const;
        constexpr explicit operator long double() const;

        constexpr explicit operator bool() const;

        ////////////////////////////////////////////////////////////
        // Member data

        const value_type numer;
        const value_type denom;
    };

    ////////////////////////////////////////////////////////////
    // Unary arithmetic operators

    template<typename T>
    constexpr auto operator+(rational<T> lhs)
        -> rational<T>;
    template<typename T>
    constexpr auto operator-(rational<T> lhs)
        -> rational<T>;

    ////////////////////////////////////////////////////////////
    // Binary arithmetic operators

    template<typename T, typename U>
    constexpr auto operator+(rational<T> lhs, rational<U> rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(rational<T> lhs, rational<U> rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(rational<T> lhs, rational<U> rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(rational<T> lhs, rational<U> rhs)
        -> rational<std::common_type_t<T, U>>;

    template<typename T, typename Integer>
    constexpr auto operator+(rational<T> lhs, Integer rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator-(rational<T> lhs, Integer rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator*(rational<T> lhs, Integer rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator/(rational<T> lhs, Integer rhs)
        -> rational<std::common_type_t<T, Integer>>;

    template<typename T, typename Integer>
    constexpr auto operator+(Integer lhs, rational<T> rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator-(Integer lhs, rational<T> rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator*(Integer lhs, rational<T> rhs)
        -> rational<std::common_type_t<T, Integer>>;
    template<typename T, typename Integer>
    constexpr auto operator/(Integer lhs, rational<T> rhs)
        -> rational<std::common_type_t<T, Integer>>;

    ////////////////////////////////////////////////////////////
    // Relational operators

    template<typename T, typename U>
    constexpr auto operator==(rational<T> lhs, rational<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(rational<T> lhs, rational<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator<(rational<T> lhs, rational<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator>(rational<T> lhs, rational<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator<=(rational<T> lhs, rational<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator>=(rational<T> lhs, rational<U> rhs)
        -> bool;

    template<typename T, typename Integer>
    constexpr auto operator==(rational<T> lhs, Integer rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator!=(rational<T> lhs, Integer rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator<(rational<T> lhs, Integer rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator>(rational<T> lhs, Integer rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator<=(rational<T> lhs, Integer rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator>=(rational<T> lhs, Integer rhs)
        -> bool;

    template<typename T, typename Integer>
    constexpr auto operator==(Integer lhs, rational<T> rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator!=(Integer lhs, rational<T> rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator<(Integer lhs, rational<T> rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator>(Integer lhs, rational<T> rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator<=(Integer lhs, rational<T> rhs)
        -> bool;
    template<typename T, typename Integer>
    constexpr auto operator>=(Integer lhs, rational<T> rhs)
        -> bool;

    ////////////////////////////////////////////////////////////
    // Mathematical functions

    template<typename T>
    constexpr auto sign(rational<T> ratio)
        -> int;

    template<typename T>
    constexpr auto abs(rational<T> ratio)
        -> rational<T>;

    template<typename T>
    constexpr auto floor(rational<T> ratio)
        -> decltype(std::floor(T{}));

    template<typename T>
    constexpr auto ceil(rational<T> ratio)
        -> decltype(std::ceil(T{}));

    template<typename T>
    constexpr auto round(rational<T> ratio)
        -> decltype(std::round(T{}));

    template<typename T>
    constexpr auto trunc(rational<T> ratio)
        -> decltype(std::trunc(T{}));

    template<typename T>
    constexpr auto reciprocal(rational<T> ratio)
        -> rational<T>;

    template<typename T, typename Integer>
    constexpr auto pow(rational<T> ratio, Integer exp)
        -> rational<T>;

    inline namespace literals
    {
    inline namespace rational_literals
    {
        ////////////////////////////////////////////////////////////
        // User-defined literals

        constexpr auto operator "" _r(unsigned long long n)
            -> rational<int>;

        constexpr auto operator "" _rl(unsigned long long n)
            -> rational<long>;

        constexpr auto operator "" _rll(unsigned long long n)
            -> rational<long long>;

        constexpr auto operator "" _ru(unsigned long long n)
            -> rational<unsigned>;

        constexpr auto operator "" _rul(unsigned long long n)
            -> rational<unsigned long>;

        constexpr auto operator "" _rull(unsigned long long n)
            -> rational<unsigned long long>;
    }}

    #include "detail/rational.inl"
}

#endif // SMATH_RATIONAL_H_
