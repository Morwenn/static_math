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
    constexpr T ln2 = static_cast<T>(0.69314718055994530942L);

    /** ln(10) */
    template<typename T=double>
    constexpr T ln10 = static_cast<T>(2.30258509299404568402L);

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
