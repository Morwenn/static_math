/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SMATH_FORMULA_H
#define _SMATH_FORMULA_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/utils/type_traits.h>
#include <static_math/constants.h>


namespace smath
{
    /**
     * @brief Tells whether the given number is even
     * @param n Integer value
     * @return Whether \a n is even or not
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_integral<T>::value, bool>::type
    is_even(T n);

    /**
     * @brief Tells whether the given number is odd
     * @param n Integer value
     * @return Whether \a n is odd or not
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_integral<T>::value, bool>::type
    is_odd(T n);

    /**
     * @brief Tells whether the given number is a prime number
     * @param n Integer value
     * @return True if \a n is a prime number
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_integral<T>::value, bool>::type
    is_prime(T n);

    /**
     * @brief Converts an angle in radians into an angle in degrees.
     * @param radians Angle in radians
     * @return The degrees value
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    degrees(T radians);

    /**
     * @brief Converts an angle in degrees into an angle in radians.
     * @param degrees Angle in degrees
     * @return The radians value
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    radians(T degrees);

    /**
     * @brief Fibonacci function
     * @param n Some integer
     * @return nth Fibonacci number
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_integral<T>::value, T>::type
    fibonacci(T n);

    /**
     * @brief Factorial function
     * @param n Some integer
     * @return Factorial of n
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_integral<T>::value, T>::type
    factorial(T n);

    /**
     * @brief Sum of a number of variables
     */
    template<typename Numeric, typename... Rest>
    constexpr
    Numeric sum(Numeric first, Numeric second, Rest... rest);

    template<typename Numeric>
    constexpr
    Numeric sum(Numeric first, Numeric second);

    /**
     * @brief Mean of a number of variables
     */
    template<typename... Args>
    constexpr
    long double mean(Args... args);

    /**
     * @brief Greatest common divisor
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<T>::value && std::is_integral<U>::value, typename greater_of<T, U>::type>::type
    gcd(T a, U b);

    /**
     * @brief Least common multiple
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<T>::value && std::is_integral<U>::value, typename greater_of<T, U>::type>::type
    lcm(T a, U b);

    #include <static_math/formula.inl>

} // namespace smath


#endif // _SMATH_FORMULA_H

