/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2016 Morwenn
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
#include <tuple>
#include <type_traits>
#include <utility>
#include <static_math/constant.h>
#include <static_math/constants.h>
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
     * @brief Natural Log function
     */
    template<typename Float>
    constexpr auto log(Float x)
        -> decltype(std::log(x));

    /**
     * @brief Log base 2 function
     */
    template<typename Float>
    constexpr auto log2(Float x)
        -> decltype(std::log2(x));

    /**
     * @brief Log base 10 function
     */
    template<typename Float>
    constexpr auto log10(Float x)
        -> decltype(std::log10(x));

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

    /**
     * @brief Hypotenuse function
     *
     * Computes the square root of the sum of the squares of \a x
     * and \a y, without undue overflow or underflow during the
     * intermediate stages of the computation.
     */
    template<typename... Args>
    constexpr auto hypot(Args... args)
        -> decltype(auto);

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
