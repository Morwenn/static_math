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
#ifndef _SMATH_CMATH_H
#define _SMATH_CMATH_H

/**
 * @file static_math/cmath.h
 * @brief compile-time clone of the standard header cmath
 *
 * This header provides functions aimed to have at least the
 * same functionnalities as the ones in the standard header
 * cmath.
 * The names can be changed (for example fabs, fmin and fmax
 * do not exist here) and some functionnalities can be added
 * such as a variadic number of arguments or a support for
 * more types.
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <type_traits>
#include <static_math/utils/compare.h>


namespace smath
{
    /**
     * @brief Absolute value of a number
     */
    template<typename T>
    constexpr auto abs(T x)
        -> typename std::enable_if<std::is_arithmetic<T>::value, T>::type;

    /**
     * @brief Min of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr auto min(T first, U second, Rest... rest)
        -> typename std::common_type<T, U, Rest...>::type;

    template<typename T, typename U>
    constexpr auto min(T first, U second)
        -> typename std::common_type<T, U>::type;

    /**
     * @brief Max of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr auto max(T first, U second, Rest... rest)
        -> typename std::common_type<T, U, Rest...>::type;

    template<typename T, typename U>
    constexpr auto max(T first, U second)
        -> typename std::common_type<T, U>::type;

    template<typename Float>
    constexpr auto floor(Float value)
        -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type;

    template<typename Float>
    constexpr auto ceil(Float value)
        -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type;

    template<typename Float>
    constexpr auto round(Float value)
        -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type;

    template<typename Float>
    constexpr auto trunc(Float value)
        -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type;

    /**
     * @brief Power function
     *
     * @warning This functions is only available for the integer
     * @warning exponent right now.
     */
    template<typename T, typename U>
    constexpr auto pow(T value, U exponent)
        -> typename std::enable_if<std::is_integral<U>::value && std::is_arithmetic<T>::value, T>::type;

    /**
     * @brief Square root function
     *
     * Square root computation with the babylonian method until
     * the best possible precision for the given floating point
     * type.
     */
    template<typename Float>
    constexpr auto sqrt(Float x)
        -> typename std::enable_if<std::is_floating_point<Float>::value, Float>::type;

    #include <static_math/cmath.inl>

} // namespace smath


#endif // _SMATH_CMATH_H
