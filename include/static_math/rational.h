/*
 * Copyright (C) 2013-2014 Morwenn
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
    class rational
    {
        static_assert(std::is_integral<T>::value,
                      "a rational can only contain integral values");

        public:

            using value_type = T;

            constexpr rational(T numerator);
            constexpr rational(T numerator, T denominator);

            constexpr auto numerator() const
                -> value_type;
            constexpr auto denominator() const
                -> value_type;

            constexpr explicit operator float() const;
            constexpr explicit operator double() const;
            constexpr explicit operator long double() const;

            constexpr explicit operator bool() const;

        private:

            T _numerator;
            T _denominator;
    };

    ////////////////////////////////////////////////////////////
    // Unary arithmetic operators

    template<typename T>
    constexpr auto operator+(const rational<T>& lhs)
        -> rational<T>;
    template<typename T>
    constexpr auto operator-(const rational<T>& lhs)
        -> rational<T>;

    ////////////////////////////////////////////////////////////
    // Binary arithmetic operators

    template<typename T, typename U>
    constexpr auto operator+(const rational<T>& lhs, const rational<U>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(const rational<T>& lhs, const rational<U>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(const rational<T>& lhs, const rational<U>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(const rational<T>& lhs, const rational<U>& rhs)
        -> rational<std::common_type_t<T, U>>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator+(const rational<T>& lhs, const U& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator-(const rational<T>& lhs, const U& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator*(const rational<T>& lhs, const U& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator/(const rational<T>& lhs, const U& rhs)
        -> rational<std::common_type_t<T, U>>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator+(const U& lhs, const rational<T>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator-(const U& lhs, const rational<T>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator*(const U& lhs, const rational<T>& rhs)
        -> rational<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator/(const U& lhs, const rational<T>& rhs)
        -> rational<std::common_type_t<T, U>>;

    ////////////////////////////////////////////////////////////
    // Relational operators

    template<typename T, typename U>
    constexpr auto operator==(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator<(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator>(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator<=(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator>=(const rational<T>& lhs, const rational<U>& rhs)
        -> bool;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator==(const rational<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator!=(const rational<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator<(const rational<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator>(const rational<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator<=(const rational<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator>=(const rational<T>& lhs, const U& rhs)
        -> bool;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator==(const U& lhs, const rational<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator!=(const U& lhs, const rational<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator<(const U& lhs, const rational<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator>(const U& lhs, const rational<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator<=(const U& lhs, const rational<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_integral<U>::value, void>>
    constexpr auto operator>=(const U& lhs, const rational<T>& rhs)
        -> bool;

    ////////////////////////////////////////////////////////////
    // Mathematical functions

    template<typename T>
    constexpr auto sign(const rational<T>& ratio)
        -> int;

    template<typename T>
    constexpr auto abs(const rational<T>& ratio)
        -> rational<T>;

    template<typename T>
    constexpr auto floor(const rational<T>& ratio)
        -> decltype(std::floor(T{}));

    template<typename T>
    constexpr auto ceil(const rational<T>& ratio)
        -> decltype(std::ceil(T{}));

    template<typename T>
    constexpr auto round(const rational<T>& ratio)
        -> decltype(std::round(T{}));

    template<typename T>
    constexpr auto trunc(const rational<T>& ratio)
        -> decltype(std::trunc(T{}));

    template<typename T>
    constexpr auto reciprocal(const rational<T>& ratio)
        -> rational<T>;

    template<typename T, typename Integral,
             typename = std::enable_if_t<std::is_integral<Integral>::value, void>>
    constexpr auto pow(const rational<T>& ratio, Integral exp)
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

    #include <static_math/rational.inl>
}

#endif // SMATH_RATIONAL_H_
