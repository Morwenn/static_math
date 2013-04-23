/*
 * Copyright (C) 2011-2013 Morwenn
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
#ifndef _SMATH_ARRAY_H
#define _SMATH_ARRAY_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstddef>
#include <initializer_list>


namespace smath
{
    /**
     * @brief Array of values
     *
     * Inspired from std::valarray more than std::array.
     * It stores a number of values determined once and
     * which can not be changed later.
     *
     * @tparam T Type of the data stored in the array
     */
    template<typename T>
    struct array:
        public std::initializer_list<T>
    {
        ////////////////////////////////////////////////////////////
        // Types
        ////////////////////////////////////////////////////////////
        using value_type        = T;
        using reference         = T&;
        using const_reference   = const T&;
        using size_type         = std::size_t;
        using iterator          = T*;
        using const_iterator    = const T*;

        ////////////////////////////////////////////////////////////
        // Constructors
        ////////////////////////////////////////////////////////////
        constexpr array(std::initializer_list<T> values);

        ////////////////////////////////////////////////////////////
        // Operators
        ////////////////////////////////////////////////////////////
        constexpr auto operator[](std::size_t n)
            -> value_type;
    };

    ////////////////////////////////////////////////////////////
    // Operators
    ////////////////////////////////////////////////////////////

    #include <static_math/array.inl>

} // namespace smath


#endif // _SMATH_ARRAY_H
