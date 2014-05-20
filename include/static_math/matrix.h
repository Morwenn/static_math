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
#ifndef SMATH_MATRIX_H_
#define SMATH_MATRIX_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstddef>

namespace smath
{
    /**
     * @brief Fixed-size matrix
     *
     * All the members of a matrix are public. Otherwise,
     * the aggregate initialization would not be have been
     * possible.
     *
     * The matrix is constructed from a 2D C array. However,
     * until the application of N3526, the 2D array initializer
     * has to be put into an extra pair of curly braces in
     * order to work fine.
     *
     * @tparam H Matrix height
     * @tparam W Matriw width
     * @tparam T Type of the data stored in the matrix
     */
    template<std::size_t H, std::size_t W, typename T=double>
    struct matrix
    {
        ////////////////////////////////////////////////////////////
        // Types
        ////////////////////////////////////////////////////////////
        using value_type = T;

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        value_type _data[H][W];

        ////////////////////////////////////////////////////////////
        // Operators
        ////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////
        // Miscellaneous functions
        ////////////////////////////////////////////////////////////

        constexpr auto width() const
            -> std::size_t;
        constexpr auto height() const
            -> std::size_t;
        constexpr auto size() const
            -> std::size_t;
    };

    ////////////////////////////////////////////////////////////
    // Operators
    ////////////////////////////////////////////////////////////

    #include <static_math/matrix.inl>
}

#endif // SMATH_MATRIX_H_
