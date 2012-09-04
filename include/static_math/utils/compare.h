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
#include <type_traits>

namespace smath
{

    /**
     * @brief Floating point comparison
     *
     * Compares two floting point numbers by checking whether
     * the difference between the two of them is lower than a
     * given value.
     */
    template<typename Float>
    constexpr
    typename std::enable_if<std::is_floating_point<Float>::value, bool>::type
    equals(Float a, Float b)
    {
        return abs(a-b) <= std::numeric_limits<Float>::epsilon() * max(abs(a), abs(b));
    }

} // namespace smath


#endif // _SMATH_UTILS_COMPARE_H
