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
        -> decltype(auto);

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
        -> decltype(auto);

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
        -> decltype(auto);

    /**
     * @brief Tells whether the given number is odd
     * @param n Integer value
     * @return Whether \a n is odd or not
     */
    template<typename Integer>
    constexpr auto is_odd(Integer n)
        -> decltype(auto);

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
        -> decltype(auto);

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
