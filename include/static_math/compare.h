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
#ifndef SMATH_COMPARE_H_
#define SMATH_COMPARE_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <limits>
#include <static_math/utils/type_traits.h>

////////////////////////////////////////////////////////////
// Macros

// Avoid circular dependency with cmath.h

#define STATIC_MATH_ABS(x) \
    (((x) >= 0) ? (x) : -(x))

#define STATIC_MATH_MAX(x, y) \
    (((x) >= (y)) ? (x) : (y))

////////////////////////////////////////////////////////////
// Functions

namespace smath
{
    /**
     * @brief Approximative comparison.
     *
     * Compares two floating point numbers by checking whether
     * the difference between the two of them is lower than a
     * given value.
     *
     * For other types, it performs a regular comparison.
     */
    template<typename T, typename U>
    constexpr auto is_close(T a, U b)
        -> std::enable_if_t<std::is_floating_point<T>::value && std::is_floating_point<U>::value, bool>
    {
        return STATIC_MATH_ABS(a-b) <=
            std::numeric_limits<lesser_of<T, U>>::epsilon() *
            STATIC_MATH_MAX(STATIC_MATH_ABS(a), STATIC_MATH_ABS(b));
    }

    template<typename T, typename U>
    constexpr auto is_close(T a, U b)
        -> std::enable_if_t<not std::is_floating_point<T>::value || not std::is_floating_point<U>::value, bool>
    {
        return a == b;
    }
}

////////////////////////////////////////////////////////////
// End macros

// Not to pollute the global namespace
#undef STATIC_MATH_ABS
#undef STATIC_MATH_MAX

#endif // SMATH_COMPARE_H_
