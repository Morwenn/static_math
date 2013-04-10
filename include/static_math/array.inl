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

template<typename T>
constexpr array<T>::array(const std::initializer_list<T>& values):
    _size(values.size()),
    _data(values.begin())
{}

template<typename T>
constexpr auto array<T>::operator[](std::size_t n)
    -> value_type
{
    return _data[n];
}

template<typename T>
constexpr auto array<T>::size() const
    -> std::size_t
{
    return _size;
}
