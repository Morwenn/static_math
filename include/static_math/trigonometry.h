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
    ////////////////////////////////////////////////////////////
    // Trigonometric functions

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

    #include "detail/trigonometry.inl"
}

#endif // SMATH_TRIGONOMETRY_H_
