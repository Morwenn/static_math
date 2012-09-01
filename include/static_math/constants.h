/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * POLDER is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * POLDER is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SMATH_CONSTANTS_H
#define _SMATH_CONSTANTS_H


namespace smath
{


////////////////////////////////////////////////////////////
// Non-standard constants from math.h
////////////////////////////////////////////////////////////

/**
 * e
 */
constexpr double E        = 2.71828182845904523540;

/**
 * log2(e)
 */
constexpr double LOG2E    = 1.44269504088896340740;

/**
 * log10(e)
 */
constexpr double LOG10E   = 0.43429448190325182765;

/**
 * ln(2)
 */
constexpr double LN2      = 0.69314718055994530942;

/**
 * ln(10)
 */
constexpr double LN10     = 2.30258509299404568402;

/**
 * pi
 */
constexpr double PI       = 3.14159265358979323846;

/**
 * sqrt(2)
 */
constexpr double SQRT2    = 1.41421356237309504880;

/**
 * sqrt(1/2)
 */
constexpr double SQRT1_2  = 0.70710678118654752440;


////////////////////////////////////////////////////////////
// Constants related to the unit circle
////////////////////////////////////////////////////////////

/**
 * sqrt(2) / 2
 */
constexpr double SQRT2_2  = 0.70710678118654752440;

/**
 * sqrt(2) / 3
 */
constexpr double SQRT2_3  = 0.47140452079103168293;


////////////////////////////////////////////////////////////
// Other mathematical constants
////////////////////////////////////////////////////////////

/**
 * Golden ratio
 */
constexpr double PHI      = 1.61803398874989484820;

/**
 * sqrt(3)
 */
constexpr double SQRT3    = 1.73205080756887729352;


} // namespace smath


#endif // _SMATH_CONSTANTS_H

