/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Morwenn
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
#include <ciso646>
#include <cstdlib>
#include <type_traits>
#include <static_math/constant.h>
#include <static_math/bit.h>

int main()
{
    ////////////////////////////////////////////////////////////
    // Regular functions

    static_assert(not smath::ispow2(0u), "");
    static_assert(smath::ispow2(1u), "");
    static_assert(smath::ispow2(2u), "");
    static_assert(not smath::ispow2(255u), "");
    static_assert(smath::ispow2(256u), "");

    static_assert(smath::ceil2(0u) == 1u, "");
    static_assert(smath::ceil2(1u) == 1u, "");
    static_assert(smath::ceil2(2u) == 2u, "");
    static_assert(smath::ceil2(3u) == 4u, "");
    static_assert(smath::ceil2(4u) == 4u, "");
    static_assert(smath::ceil2(123u) == 128u, "");

    static_assert(smath::floor2(0u) == 0u, "");
    static_assert(smath::floor2(1u) == 1u, "");
    static_assert(smath::floor2(2u) == 2u, "");
    static_assert(smath::floor2(3u) == 2u, "");
    static_assert(smath::floor2(4u) == 4u, "");
    static_assert(smath::floor2(5u) == 4u, "");
    static_assert(smath::floor2(123u) == 64u, "");

    static_assert(smath::log2p1(0u) == 0u, "");
    static_assert(smath::log2p1(1u) == 1u, "");
    static_assert(smath::log2p1(2u) == 2u, "");
    static_assert(smath::log2p1(3u) == 2u, "");
    static_assert(smath::log2p1(4u) == 3u, "");
    static_assert(smath::log2p1(123u) == 7u, "");

    ////////////////////////////////////////////////////////////
    // smath::constant overloads

#ifndef STATIC_MATH_NO_INTEGRAL_CONSTANT
    using namespace smath::constant_literals;

    static_assert(
        std::is_same<
            decltype(smath::ispow2(0_cu)),
            smath::false_type
        >::value, "");
    static_assert(
        std::is_same<
            decltype(smath::ispow2(1_cu)),
            smath::true_type
        >::value, "");
    static_assert(
        std::is_same<
            decltype(smath::ispow2(2_cu)),
            smath::true_type
        >::value, "");
    static_assert(
        std::is_same<
            decltype(smath::ispow2(255_cu)),
            smath::false_type
        >::value, "");
    static_assert(
        std::is_same<
            decltype(smath::ispow2(256_cu)),
            smath::true_type
        >::value, "");

    static_assert(smath::ceil2(0_cu) == 1_cu, "");
    static_assert(smath::ceil2(1_cu) == 1_cu, "");
    static_assert(smath::ceil2(2_cu) == 2_cu, "");
    static_assert(smath::ceil2(3_cu) == 4_cu, "");
    static_assert(smath::ceil2(4_cu) == 4_cu, "");
    static_assert(smath::ceil2(123_cu) == 128_cu, "");

    static_assert(smath::floor2(0_cu) == 0_cu, "");
    static_assert(smath::floor2(1_cu) == 1_cu, "");
    static_assert(smath::floor2(2_cu) == 2_cu, "");
    static_assert(smath::floor2(3_cu) == 2_cu, "");
    static_assert(smath::floor2(4_cu) == 4_cu, "");
    static_assert(smath::floor2(5_cu) == 4_cu, "");
    static_assert(smath::floor2(123_cu) == 64_cu, "");

    static_assert(smath::log2p1(0_cu) == 0_cu, "");
    static_assert(smath::log2p1(1_cu) == 1_cu, "");
    static_assert(smath::log2p1(2_cu) == 2_cu, "");
    static_assert(smath::log2p1(3_cu) == 2_cu, "");
    static_assert(smath::log2p1(4_cu) == 3_cu, "");
    static_assert(smath::log2p1(123_cu) == 7_cu, "");
#endif
}
