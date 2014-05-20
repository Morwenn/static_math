/*
 * Copyright (C) 2013 Morwenn
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
#ifndef SMATH_FORMULA_H_
#define SMATH_FORMULA_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/constants.h>
#include <static_math/utils/type_traits.h>

namespace smath
{
    ////////////////////////////////////////////////////////////
    // Basic functions

    /**
     * @brief signum function
     * @param val Any number
     * @return Sign of \a val
     */
    template<typename Number>
    constexpr auto sign(Number x)
        -> int;

    /**
     * @brief Sum of a number of variables
     */
    template<typename Numeric, typename... Rest>
    constexpr
    Numeric sum(Numeric first, Numeric second, Rest... rest);

    /**
     * @brief Mean of a number of variables
     */
    template<typename... Numbers>
    constexpr
    long double mean(Numbers... args);

    /**
     * @brief Square function
     * @param x Some number
     * @return Square of \a x
     */
    template<typename Number>
    constexpr Number sqr(Number x);

    /**
     * @brief Limits a value to a range
     * @param val Number to clamp
     * @param min Lower limit
     * @param max Higher limit
     * @return \a val clamped between \a min and \a max
     */
    template<typename Number>
    constexpr Number clamp(Number x, Number min, Number max);

    ////////////////////////////////////////////////////////////
    // Integer-related functions

    /**
     * @brief Tells whether the given number is even
     * @param n Integer value
     * @return Whether \a n is even or not
     */
    template<typename T>
    constexpr
    typename std::enable_if<is_integral<T>::value, bool>::type
    is_even(T n);

    /**
     * @brief Tells whether the given number is odd
     * @param n Integer value
     * @return Whether \a n is odd or not
     */
    template<typename T>
    constexpr
    typename std::enable_if<is_integral<T>::value, bool>::type
    is_odd(T n);

    /**
     * @brief Tells whether the given number is a prime number
     * @param n Integer value
     * @return True if \a n is a prime number
     */
    template<typename T>
    constexpr
    typename std::enable_if<is_integral<T>::value, bool>::type
    is_prime(T n);

    /**
     * @brief Fibonacci function
     * @param n Some integer
     * @return nth Fibonacci number
     */
    template<typename T>
    constexpr
    typename std::enable_if<is_integral<T>::value, T>::type
    fibonacci(T n);

    /**
     * @brief Factorial function
     * @param n Some integer
     * @return Factorial of n
     */
    template<typename T>
    constexpr
    typename std::enable_if<is_integral<T>::value, T>::type
    factorial(T n);

    /**
     * @brief Greatest common divisor
     * @param a Some integer
     * @param b Some integer
     * @return Greatest common divisor of a and b
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<is_integral<T, U>::value, typename std::common_type<T, U>::type>::type
    gcd(T a, U b);

    /**
     * @brief Least common multiple
     * @param a Some integer
     * @param b Some integer
     * @return Least common multiple of a and b
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<is_integral<T, U>::value, typename std::common_type<T, U>::type>::type
    lcm(T a, U b);

    ////////////////////////////////////////////////////////////
    // Angle conversions

    /**
     * @brief Converts an angle in radians into an angle in degrees.
     * @param x Angle in radians
     * @return The degrees value
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    degrees(T x);

    /**
     * @brief Converts an angle in degrees into an angle in radians.
     * @param x Angle in degrees
     * @return The radians value
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    radians(T x);

    #include <static_math/formula.inl>
}

#endif // SMATH_FORMULA_H_
