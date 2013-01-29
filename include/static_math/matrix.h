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
#ifndef _SMATH_MATRIX_H
#define _SMATH_MATRIX_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstddef>


namespace smath
{

    /**
     * @brief Fixed-size matrix
     *
     * @tparam H Matrix height
     * @tparam W Matriw width
     * @tparam T Type of the data stored in the matrix
     */
    template<size_t H, size_t W, typename T=double>
    class matrix
    {
        public:

            using value_type = T;

        private:

            static constexpr size_t _size = H * W;  /** Number of elements */

        public:

            ////////////////////////////////////////////////////////////
            // Constructors
            ////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////
            // Operators
            ////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////
            // Miscellaneous functions
            ////////////////////////////////////////////////////////////

            constexpr auto width()  const -> size_t;
            constexpr auto height() const -> size_t;
            constexpr auto size()   const -> size_t;
    };

    ////////////////////////////////////////////////////////////
    // Operators
    ////////////////////////////////////////////////////////////

    #include <static_math/matrix.inl>

} // namespace smath


#endif // _SMATH_MATRIX_H
