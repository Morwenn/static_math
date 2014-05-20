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
#ifndef SMATH_STATIC_MATH_H_
#define SMATH_STATIC_MATH_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/cmath.h>
#include <static_math/complex.h>
#include <static_math/constants.h>
#include <static_math/formula.h>
#include <static_math/rational.h>

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

