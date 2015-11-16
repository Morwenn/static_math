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
#ifndef SMATH_CMATH_H_
#define SMATH_CMATH_H_

/**
 * @file static_math/cmath.h
 * @brief compile-time clone of the standard header <cmath>.
 *
 * This header provides functions aimed to have at least the
 * same features as the ones in the standard header <cmath>.
 * The names can be changed (for example fabs, fmin and fmax
 * do not exist here) and some additional features can be
 * added to some of the functions, such as a variadic number
 * of arguments or a support for more different types.
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cmath>
#include <cstddef>
#include <type_traits>
#include <static_math/constant.h>
#include "detail/core.h"

namespace smath
{
    ////////////////////////////////////////////////////////////
    // Basic functions

    /**
     * @brief Absolute value of a number
     */
    template<typename Number>
    constexpr auto abs(Number x)
        -> decltype(auto);

    /**
     * @brief Min of a number of variables
     */
    template<typename... Args>
    constexpr auto min(Args... args)
        -> decltype(auto);

    /**
     * @brief Max of a number of variables
     */
    template<typename... Args>
    constexpr auto max(Args... args)
        -> decltype(auto);

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
     * @brief Exponential function.
     */
    template<typename Float>
    constexpr auto exp(Float x)
        -> decltype(std::exp(x));

    /**
     * @brief Power function
     *
     * @warning This functions is only available for the integer
     * @warning exponent right now.
     */
    template<typename Number, typename Integer>
    constexpr auto pow(Number x, Integer exponent)
        -> std::common_type_t<Number, Integer>;

    /**
     * @brief Square root function
     *
     * Square root computation with the Babylonian method until
     * the best possible precision for the given floating point
     * type.
     */
    template<typename Float>
    constexpr auto sqrt(Float x)
        -> decltype(std::sqrt(x));

    ////////////////////////////////////////////////////////////
    // Trigonometric functions

    /**
     * @brief Sine function.
     * @param x Angle in radians
     */
    template<typename Float>
    constexpr auto sin(Float x)
        -> Float;

    /**
     * @brief Cosine function.
     * @param x Angle in radians
     */
    template<typename Float>
    constexpr auto cos(Float x)
        -> Float;

    /**
     * @brief Tangent function.
     * @param x Angle in radians
     */
    template<typename Float>
    constexpr auto tan(Float x)
        -> Float;

    ////////////////////////////////////////////////////////////
    // Hyperbolic functions

    /**
     * @brief Hyperbolic sine function.
     * @param x Hyperbolic angle in radians
     */
    template<typename Float>
    constexpr auto sinh(Float x)
        -> Float;

    /**
     * @brief Hyperbolic cosine function.
     * @param x Hyperbolic angle in radians
     */
    template<typename Float>
    constexpr auto cosh(Float x)
        -> Float;

    /**
     * @brief Hyperbolic tangent function.
     * @param x Hyperbolic angle in radians
     */
    template<typename Float>
    constexpr auto tanh(Float x)
        -> Float;

    #include "detail/cmath.inl"
}

#endif // SMATH_CMATH_H_
