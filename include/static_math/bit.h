/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Morwenn
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
#ifndef SMATH_BIT_H_
#define SMATH_BIT_H_

/**
 * @file static_math/bit.h
 * @brief compile-time clone of functions from <bit>.
 *
 * This header provides mathematical functions to work on unsigned
 * integers, mostly related to power-of-2 operations, which happen
 * to use bit tricks under the hood. Most of them are direct clones
 * of functions from the C++20 <bit> header.
 */

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstddef>
#include <limits>
#include <static_math/constant.h>

namespace smath
{
    /**
     * @brief Returns whether \p x is a power of 2.
     */
    template<typename Unsigned>
    constexpr auto ispow2(Unsigned x) noexcept
        -> bool;

    /**
     * @brief Minimal power of 2 greater or equal to \p x.
     */
    template<typename Unsigned>
    constexpr auto ceil2(Unsigned x) noexcept
        -> Unsigned;

    /**
     * @brief Maximal power of two lesser or equal to \p x.
     */
    template<typename Unsigned>
    constexpr auto floor2(Unsigned x) noexcept
        -> Unsigned;

    /**
     * @brief 0 if \p x == 0, otherwise base-2 logarithm of \p x.
     */
    template<typename Unsigned>
    constexpr auto log2p1(Unsigned x) noexcept
        -> Unsigned;

    #include "detail/bit.inl"
}

#endif // SMATH_BIT_H_
