/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Morwenn
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

 /*
 * This file is the work of theLOLflashlight's GitHub account.
 */

#ifndef SMATH_TRIGONOMETRY_H_
#define SMATH_TRIGONOMETRY_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/cmath.h>

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
