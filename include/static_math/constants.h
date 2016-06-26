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
#ifndef SMATH_CONSTANTS_H_
#define SMATH_CONSTANTS_H_

namespace smath
{
namespace constants
{
    ////////////////////////////////////////////////////////////
    // POSIX constants from cmath

    /** e */
    template<typename T=double>
    constexpr T e = static_cast<T>(2.71828182845904523540L);

    /** log2(e) */
    template<typename T=double>
    constexpr T log2e = static_cast<T>(1.44269504088896340740L);

    /** log10(e) */
    template<typename T=double>
    constexpr T log10e = static_cast<T>(0.43429448190325182765L);

    /** ln(2) */
    template<typename T=double>
    constexpr T ln2 = static_cast<T>(0.693147180559945309417232121L);

    /** ln(10) */
    template<typename T=double>
    constexpr T ln10 = static_cast<T>(2.302585092994045684017991454L);

    /** pi */
    template<typename T=double>
    constexpr T pi = static_cast<T>(3.14159265358979323846L);

    ////////////////////////////////////////////////////////////
    // Other mathematical constants

    /** Golden ratio */
    template<typename T=double>
    constexpr T phi = static_cast<T>(1.61803398874989484820L);
}}

#endif // SMATH_CONSTANTS_H_
