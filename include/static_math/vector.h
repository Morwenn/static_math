/*
 * Copyright (C) 2014 Morwenn
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
#ifndef SMATH_VECTOR_H_
#define SMATH_VECTOR_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <array>
#include <cstddef>

namespace smath
{
    /**
     * @brief Fixed-size vector.
     */
    template<typename T, std::size_t N>
    struct vector
    {
        ////////////////////////////////////////////////////////////
        // Types

        using value_type    = typename std::array<T, N>::value_type;
        using size_type     = typename std::array<T, N>::size_type;
        using const_pointer = typename std::array<T, N>::const_pointer;

        ////////////////////////////////////////////////////////////
        // Operators

        constexpr auto operator[](size_type i) const
            -> value_type;

        ////////////////////////////////////////////////////////////
        // Accessors

        constexpr auto at(size_type i) const
            -> value_type;

        constexpr auto front() const
            -> value_type;

        constexpr auto back() const
            -> value_type;

        constexpr auto data() const
            -> const_pointer;

        ////////////////////////////////////////////////////////////
        // Capacity

        constexpr auto empty() const
            -> bool;

        constexpr auto size() const
            -> size_type;

        constexpr auto max_size() const
            -> size_type;

        ////////////////////////////////////////////////////////////
        // Member data

        // Internal array holding the elements.
        // Should be private, but that would prevent
        // aggregate initialization.
        const std::array<T, N> elems;
    };

    #include "vector.inl"
}

#endif // SMATH_VECTOR_H_
