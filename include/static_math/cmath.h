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
#ifndef SMATH_CMATH_H_
#define SMATH_CMATH_H_

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
#include <cmath>
#include <type_traits>
#include <static_math/utils/compare.h>

namespace smath
{
    ////////////////////////////////////////////////////////////
    // Basic functions

    /**
     * @brief Absolute value of a number
     */
    template<typename Number>
    constexpr auto abs(Number x)
        -> Number;

    /**
     * @brief Min of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr auto min(T first, U second, Rest... rest)
        -> std::common_type_t<T, U, Rest...>;

    /**
     * @brief Max of a number of variables
     */
    template<typename T, typename U, typename... Rest>
    constexpr auto max(T first, U second, Rest... rest)
        -> std::common_type_t<T, U, Rest...>;

    ////////////////////////////////////////////////////////////
    // Number-theoretic and representation functions

    template<typename Float>
    constexpr auto floor(Float x)
        -> decltype(std::floor(x));

    template<typename Float>
    constexpr auto ceil(Float x)
        -> decltype(std::ceil(x));

    template<typename Float>
    constexpr auto round(Float x)
        -> decltype(std::round(x));

    template<typename Float>
    constexpr auto trunc(Float x)
        -> decltype(std::trunc(x));

    ////////////////////////////////////////////////////////////
    // Power and logarithmic functions

    /**
     * @brief Power function
     *
     * @warning This functions is only available for the integer
     * @warning exponent right now.
     */
    template<typename Number, typename Integer>
    constexpr auto pow(Number x, Integer exponent)
        -> typename std::common_type_t<Number, Integer>;

    /**
     * @brief Square root function
     *
     * Square root computation with the babylonian method until
     * the best possible precision for the given floating point
     * type.
     */
    template<typename Float>
    constexpr auto sqrt(Float x)
        -> decltype(std::sqrt(x));

    #include <static_math/cmath.inl>
}

#endif // SMATH_CMATH_H_
