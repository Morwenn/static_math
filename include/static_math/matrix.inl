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

/*template<size_t H, size_t W, typename T>
constexpr matrix<H, W, T>::matrix(const T(&array)[H][W]):
    _data(array)
{}*/

template<size_t H, size_t W, typename T>
constexpr auto matrix<H, W, T>::height()
    -> size_t
{
    return H;
}

template<size_t H, size_t W, typename T>
constexpr auto matrix<H, W, T>::width()
    -> size_t
{
    return W;
}

template<size_t H, size_t W, typename T>
constexpr auto matrix<H, W, T>::size()
    -> size_t
{
    return H * W;
}
