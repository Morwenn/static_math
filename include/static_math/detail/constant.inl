/*
 * Copyright (C) 2015 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more detail.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */

////////////////////////////////////////////////////////////
// Unary arithmetic operators

template<typename Integer, Integer N>
constexpr auto operator+(constant<Integer, N>)
    -> constant<Integer, N>
{
    return {};
}

template<typename Integer, Integer N>
constexpr auto operator-(constant<Integer, N>)
    -> constant<Integer, -N>
{
    return {};
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename Integer, Integer N, Integer M>
constexpr auto operator+(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, N + M>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator-(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, N - M>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator*(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, N * M>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator/(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, N / M>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator%(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, N % M>
{
    return {};
}

////////////////////////////////////////////////////////////
// Equality operators

template<typename Integer, Integer N, Integer M>
constexpr auto operator==(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, N == M>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator!=(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, N != M>
{
    return {};
}

////////////////////////////////////////////////////////////
// Relational operators

template<typename Integer, Integer N, Integer M>
constexpr auto operator<(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N < M)>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator<=(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N <= M)>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator>(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N > M)>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator>=(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N >= M)>
{
    return {};
}

////////////////////////////////////////////////////////////
// Logical operators

template<typename Integer, Integer N, Integer M>
constexpr auto operator&&(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N && M)>
{
    return {};
}

template<typename Integer, Integer N, Integer M>
constexpr auto operator||(constant<Integer, N>, constant<Integer, M>)
    -> constant<bool, (N || M)>
{
    return {};
}

template<typename Integer, Integer N>
constexpr auto operator!(constant<Integer, N>)
    -> constant<bool, !N>
{
    return {};
}

////////////////////////////////////////////////////////////
// User-defined literals

inline namespace literals
{
inline namespace constant_literals
{
    template<char... Digits>
    constexpr auto operator"" _c()
        -> constant<
            detail::parse_t<int, Digits...>,
            detail::parse<int, Digits...>::value
        >
    {
        return {};
    }

    template<char... Digits>
    constexpr auto operator"" _cl()
        -> constant<
            detail::parse_t<long, Digits...>,
            detail::parse<long, Digits...>::value
        >
    {
        return {};
    }

    template<char... Digits>
    constexpr auto operator"" _cll()
        -> constant<
            detail::parse_t<long long, Digits...>,
            detail::parse<long long, Digits...>::value
        >
    {
        return {};
    }

    template<char... Digits>
    constexpr auto operator"" _cu()
        -> constant<
            detail::parse_t<unsigned, Digits...>,
            detail::parse<unsigned, Digits...>::value
        >
    {
        return {};
    }

    template<char... Digits>
    constexpr auto operator"" _cul()
        -> constant<
            detail::parse_t<unsigned long, Digits...>,
            detail::parse<unsigned long, Digits...>::value
        >
    {
        return {};
    }

    template<char... Digits>
    constexpr auto operator"" _cull()
        -> constant<
            detail::parse_t<unsigned long long, Digits...>,
            detail::parse<unsigned long long, Digits...>::value
        >
    {
        return {};
    }
}}
