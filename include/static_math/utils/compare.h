/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SMATH_UTILS_COMPARE_H
#define _SMATH_UTILS_COMPARE_H


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <limits>
#include <static_math/utils/type_traits.h>


////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////

// To avoid circular dependancy with cmath.h

#define STATIC_MATH_ABS(x) \
    (((x) >= 0) ? (x) : -(x))

#define STATIC_MATH_MAX(x, y) \
    (((x) >= (y)) ? (x) : (y))


////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////

namespace smath
{

    /**
     * @brief Floating point comparison
     *
     * Compares two floting point numbers by checking whether
     * the difference between the two of them is lower than a
     * given value.
     */
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_floating_point<T>::value && std::is_floating_point<U>::value, bool>::type
    equals(T a, U b)
    {
        return STATIC_MATH_ABS(a-b) <=
            std::numeric_limits<typename lesser_of<T, U>::type>::epsilon() *
            STATIC_MATH_MAX(STATIC_MATH_ABS(a), STATIC_MATH_ABS(b));
    }

} // namespace smath


////////////////////////////////////////////////////////////
// End macros
////////////////////////////////////////////////////////////

// Cause it's wee-known that macros are evil
#undef STATIC_MATH_ABS
#undef STATIC_MATH_MAX


#endif // _SMATH_UTILS_COMPARE_H
