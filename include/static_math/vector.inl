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

////////////////////////////////////////////////////////////
// In-class operators

template<typename T, std::size_t N>
constexpr auto vector<T, N>::operator[](size_type i) const
    -> value_type
{
    return elems[i];
}

////////////////////////////////////////////////////////////
// Accessors

template<typename T, std::size_t N>
constexpr auto vector<T, N>::at(size_type i) const
    -> value_type
{
    return elems.at(i);
}

template<typename T, std::size_t N>
constexpr auto vector<T, N>::front() const
    -> value_type
{
    return elems.front();
}

template<typename T, std::size_t N>
constexpr auto vector<T, N>::back() const
    -> value_type
{
    return elems.back();
}

template<typename T, std::size_t N>
constexpr auto vector<T, N>::data() const
    -> const_pointer
{
    return elems.data();
}

////////////////////////////////////////////////////////////
// Capacity

template<typename T, std::size_t N>
constexpr auto vector<T, N>::empty() const
    -> bool
{
    return elems.empty();
}

template<typename T, std::size_t N>
constexpr auto vector<T, N>::size() const
    -> size_type
{
    return elems.size();
}

template<typename T, std::size_t N>
constexpr auto vector<T, N>::max_size() const
    -> size_type
{
    return elems.max_size();
}
