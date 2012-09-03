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

template<typename T>
constexpr
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
abs(T x)
{
    return (x >= 0) ? x : -x;
}

template<typename Numeric, typename... Rest>
constexpr
Numeric min(Numeric first, Numeric second, Rest... rest)
{
    return (first < second) ? min(first, rest...) : min(second, rest...);
}

template<typename Numeric>
constexpr
Numeric min(Numeric first, Numeric second)
{
    return (first < second) ? first : second;
}

template<typename Numeric, typename... Rest>
constexpr
Numeric max(Numeric first, Numeric second, Rest... rest)
{
    return (first > second) ? max(first, rest...) : max(second, rest...);
}

template<typename Numeric>
constexpr
Numeric max(Numeric first, Numeric second)
{
    return (first > second) ? first : second;
}
