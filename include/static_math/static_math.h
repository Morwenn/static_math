/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
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
#ifndef SMATH_STATIC_MATH_H_
#define SMATH_STATIC_MATH_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/cmath.h>
#include <static_math/complex.h>
#include <static_math/constant.h>
#include <static_math/constants.h>
#include <static_math/formula.h>
#include <static_math/rational.h>
#include <static_math/trigonometry.h>

/**
 * @file static_math/static_math.h
 * @brief Main library file.
 *
 * This file includes the whole library.
 */

/**
 * @namespace smath
 * Global namespace of static_math.
 *
 * Every function of static_math lives in this namespace.
 * The library does not contain any other namespace.
 *
 * All the functions in this library are meant to be used
 * at compile time. Though can also be used at runtime, it's
 * generally not a good idea: the functions are implemented
 * in a way they can actually run at compile time, often at
 * the expense of performance. The global idea is that
 * performance of the functions is not an issue since all
 * will just be computed once.
 *
 * If you want some powerful and fast mathematical functions,
 * you better use those in the standard library or Boost or
 * any library dedicated to maths.
 */

#endif // SMATH_STATIC_MATH_H_
