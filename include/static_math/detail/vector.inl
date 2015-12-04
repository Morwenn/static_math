/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2015 Morwenn
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
// Details

namespace detail
{
    template<typename T, std::size_t N, std::size_t... Ind>
    constexpr auto add(vector<T, N> lhs, vector<T, N> rhs, std::index_sequence<Ind...>)
        -> vector<T, N>
    {
        return { (lhs[Ind] + rhs[Ind])... };
    }

    template<typename T, std::size_t N, std::size_t... Ind>
    constexpr auto sub(vector<T, N> lhs, vector<T, N> rhs, std::index_sequence<Ind...>)
        -> vector<T, N>
    {
        return { (lhs[Ind] - rhs[Ind])... };
    }
}

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

////////////////////////////////////////////////////////////
// Element-wise operations

template<typename T, std::size_t N>
constexpr auto operator+(vector<T, N> lhs, vector<T, N> rhs)
    -> vector<T, N>
{
    using Indices = std::make_index_sequence<N>;
    return detail::add(lhs, rhs, Indices{});
}

template<typename T, std::size_t N>
constexpr auto operator-(vector<T, N> lhs, vector<T, N> rhs)
    -> vector<T, N>
{
    using Indices = std::make_index_sequence<N>;
    return detail::sub(lhs, rhs, Indices{});
}
