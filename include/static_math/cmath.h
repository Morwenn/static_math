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


namespace smath
{
    /**
     * @brief Absolute value of a number
     */
    template<typename T>
    constexpr
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    abs(T x);

    /**
     * @brief Min of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr
    typename std::common_type<T, U>::type
    min(T first, U second, Rest... rest);

    template<typename T, typename U>
    constexpr
    typename std::common_type<T, U>::type
    min(T first, U second);

    /**
     * @brief Max of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr
    typename std::common_type<T, U>::type
    max(T first, U second, Rest... rest);

    template<typename T, typename U>
    constexpr
    typename std::common_type<T, U>::type
    max(T first, U second);

    template<typename Float>
    constexpr
    typename std::enable_if<std::is_floating_point<Float>::value, int>::type
    floor(Float value);

    template<typename Float>
    constexpr
    typename std::enable_if<std::is_floating_point<Float>::value, int>::type
    ceil(Float value);

    template<typename Float>
    constexpr
    typename std::enable_if<std::is_floating_point<Float>::value, int>::type
    round(Float value);

    template<typename Float>
    constexpr
    typename std::enable_if<std::is_floating_point<Float>::value, int>::type
    trunc(Float value);

    /**
     * @brief Power function
     *
     * @warning This functions is only available for the integer
     * @warning exponent right now.
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_integral<U>::value && std::is_arithmetic<T>::value, T>::type
    pow(T value, U exponent);

    #include <static_math/cmath.inl>

} // namespace smath


#endif // _SMATH_CMATH_H
