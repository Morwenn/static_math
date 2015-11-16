/*
 * Copyright (C) 2013-2015 Morwenn
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
#include <type_traits>
#include <static_math/constants.h>
#include "detail/core.h"

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
     * @brief Approximative comparison.
     *
     * Compares two floating point numbers by checking whether
     * the difference between the two of them is lower than a
     * given value.
     *
     * For other types, it performs a regular comparison.
     */
    template<typename T, typename U>
    constexpr auto is_close(T a, U b)
        -> bool;

    /**
     * @brief Sum of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr auto sum(T first, U second, Rest... rest)
        -> std::common_type_t<T, U, Rest...>;

    /**
     * @brief Mean of a number of variables
     */
    template<typename... Numbers>
    constexpr auto mean(Numbers... args)
        -> decltype(sum(args...) / sizeof...(args));

    /**
     * @brief Square function
     * @param x Some number
     * @return Square of \a x
     */
    template<typename Number>
    constexpr auto sqr(Number x)
        -> Number;

    /**
     * @brief Limits a value to a range
     * @param val Number to clamp
     * @param min Lower limit
     * @param max Higher limit
     * @return \a val clamped between \a min and \a max
     */
    template<typename Number>
    constexpr auto clamp(Number x, Number min, Number max)
        -> Number;

    ////////////////////////////////////////////////////////////
    // Integer-related functions

    /**
     * @brief Tells whether the given number is even
     * @param n Integer value
     * @return Whether \a n is even or not
     */
    template<typename Integer>
    constexpr auto is_even(Integer n)
        -> bool;

    /**
     * @brief Tells whether the given number is odd
     * @param n Integer value
     * @return Whether \a n is odd or not
     */
    template<typename Integer>
    constexpr auto is_odd(Integer n)
        -> bool;

    /**
     * @brief Tells whether the given number is a prime number
     * @param n Integer value
     * @return True if \a n is a prime number
     */
    template<typename Integer>
    constexpr auto is_prime(Integer n)
        -> bool;

    /**
     * @brief Fibonacci function
     * @param n Some integer
     * @return nth Fibonacci number
     */
    template<typename Integer>
    constexpr auto fibonacci(Integer n)
        -> Integer;

    /**
     * @brief Factorial function
     * @param n Some integer
     * @return Factorial of n
     */
    template<typename Integer>
    constexpr auto factorial(Integer n)
        -> Integer;

    /**
     * @brief Greatest common divisor
     * @param a Some integer
     * @param b Some integer
     * @return Greatest common divisor of a and b
     */
    template<typename T, typename U>
    constexpr auto gcd(T a, U b)
        -> std::common_type_t<T, U>;

    /**
     * @brief Least common multiple
     * @param a Some integer
     * @param b Some integer
     * @return Least common multiple of a and b
     */
    template<typename T, typename U>
    constexpr auto lcm(T a, U b)
        -> std::common_type_t<T, U>;

    ////////////////////////////////////////////////////////////
    // Angle conversions

    /**
     * @brief Converts an angle in radians into an angle in degrees.
     * @param x Angle in radians
     * @return The degrees value
     */
    template<typename Float>
    constexpr auto degrees(Float x)
        -> Float;

    /**
     * @brief Converts an angle in degrees into an angle in radians.
     * @param x Angle in degrees
     * @return The radians value
     */
    template<typename Float>
    constexpr auto radians(Float x)
        -> Float;

    #include "detail/formula.inl"
}

#endif // SMATH_FORMULA_H_
