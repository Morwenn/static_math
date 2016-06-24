/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

////////////////////////////////////////////////////////////
// Check whether a type is an integral constant

namespace detail
{
    template<typename T>
    struct is_integral_constant:
        std::false_type
    {};

    template<typename Integer, Integer N>
    struct is_integral_constant<constant<Integer, N>>:
        std::true_type
    {};
}

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
