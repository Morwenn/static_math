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

 /*
 * This file is the work of theLOLflashlight's GitHub account.
 */

#ifndef SMATH_TRIGONOMETRY_H_
#define SMATH_TRIGONOMETRY_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <type_traits>
#include <static_math/cmath.h>
#include <static_math/constants.h>
#include <static_math/formula.h>

namespace smath
{
    /**
    * @brief Exponential function.
    */
    template<typename Float>
    constexpr auto exp(Float x)
        -> Float;

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

    /**
    * @brief Cotangent function.
    * @param x Angle in radians
    */
    template<typename Float>
    constexpr auto cot(Float x)
        -> Float;

    /**
    * @brief Secant function.
    * @param x Angle in radians
    */
    template<typename Float>
    constexpr auto sec(Float x)
        -> Float;

    /**
    * @brief Cosecant function.
    * @param x Angle in radians
    */
    template<typename Float>
    constexpr auto csc(Float x)
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

    /**
    * @brief Hyperbolic cotangent function.
    * @param x Hyperbolic angle in radians
    */
    template<typename Float>
    constexpr auto coth(Float x)
        -> Float;

    /**
    * @brief Hyperbolic secant function.
    * @param x Hyperbolic angle in radians
    */
    template<typename Float>
    constexpr auto sech(Float x)
        -> Float;

    /**
    * @brief Hyperbolic cosecant function.
    * @param x Hyperbolic angle in radians
    */
    template<typename Float>
    constexpr auto csch(Float x)
        -> Float;

    #include <static_math/trigonometry.inl>
}

#endif // SMATH_TRIGONOMETRY_H_
