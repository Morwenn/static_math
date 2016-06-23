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
#ifndef SMATH_VECTOR_H_
#define SMATH_VECTOR_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <array>
#include <cstddef>
#include <utility>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-braces"
#endif

namespace smath
{
    /**
     * @brief Fixed-size vector.
     */
    template<typename T, std::size_t N>
    struct vector
    {
        ////////////////////////////////////////////////////////////
        // Types

        using value_type    = typename std::array<T, N>::value_type;
        using size_type     = typename std::array<T, N>::size_type;
        using const_pointer = typename std::array<T, N>::const_pointer;

        ////////////////////////////////////////////////////////////
        // Operators

        constexpr auto operator[](size_type i) const
            -> value_type;

        ////////////////////////////////////////////////////////////
        // Accessors

        constexpr auto at(size_type i) const
            -> value_type;

        constexpr auto front() const
            -> value_type;

        constexpr auto back() const
            -> value_type;

        constexpr auto data() const
            -> const_pointer;

        ////////////////////////////////////////////////////////////
        // Capacity

        constexpr auto empty() const
            -> bool;

        constexpr auto size() const
            -> size_type;

        constexpr auto max_size() const
            -> size_type;

        ////////////////////////////////////////////////////////////
        // Member data

        // Internal array holding the elements.
        // Should be private, but that would prevent
        // aggregate initialization.
        const std::array<T, N> elems;
    };

    ////////////////////////////////////////////////////////////
    // Element-wise operations

    template<typename T, std::size_t N>
    constexpr auto operator+(vector<T, N> lhs, vector<T, N> rhs)
        -> vector<T, N>;

    template<typename T, std::size_t N>
    constexpr auto operator-(vector<T, N> lhs, vector<T, N> rhs)
        -> vector<T, N>;

    #include "detail/vector.inl"
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // SMATH_VECTOR_H_
