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


////////////////////////////////////////////////////////////
// Other mathematical constants
////////////////////////////////////////////////////////////

/**
 * Golden ratio
 */
constexpr double PHI      = 1.61803398874989484820;


} // namespace smath


#endif // _SMATH_CONSTANTS_H

