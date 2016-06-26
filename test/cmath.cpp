/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2016 Morwenn
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
#include <static_math/cmath.h>
#include <static_math/constants.h>
#include <static_math/formula.h>

int main()
{
    ////////////////////////////////////////////////////////////
    // Regular functions

    static_assert(smath::abs(-5) == 5, "");
    static_assert(smath::abs(8) == 8, "");
    static_assert(smath::abs(-82L) == 82, "");

    static_assert(smath::min(1, 2) == 1, "");
    static_assert(smath::min(0, 0) == 0, "");
    static_assert(smath::min(-2, -1, 0, 1, 2) == -2, "");
    static_assert(smath::min(2, 1, 0, -1, -2) == -2, "");

    static_assert(smath::max(3, 8) == 8, "");
    static_assert(smath::max(-8, -8) == -8, "");
    static_assert(smath::max(8, -1, 6, 3, 5, 2, -8) == 8, "");
    static_assert(smath::max(-1, 0, 1, 2, 3, 2, 1, 0, -1) == 3, "");

    static_assert(smath::floor(2.5) == 2.0, "");
    static_assert(smath::floor(2.01) == 2.0, "");
    static_assert(smath::floor(2.8) == 2.0, "");
    static_assert(smath::floor(-2.5) == -3.0, "");

    static_assert(smath::ceil(2.5) == 3.0, "");
    static_assert(smath::ceil(2.01) == 3.0, "");
    static_assert(smath::ceil(2.8) == 3.0, "");
    static_assert(smath::ceil(-2.5) == -2.0, "");

    static_assert(smath::round(2.5) == 3.0, "");
    static_assert(smath::round(2.01) == 2.0, "");
    static_assert(smath::round(2.8) == 3.0, "");
    static_assert(smath::round(-2.1) == -2.0, "");

    static_assert(smath::trunc(2.5) == 2.0, "");
    static_assert(smath::trunc(2.01) == 2.0, "");
    static_assert(smath::trunc(2.8) == 2.0, "");
    static_assert(smath::trunc(-2.1) == -2.0, "");

    static_assert(smath::is_close(smath::exp(0.0), 1.0), "");
    static_assert(smath::is_close(smath::exp(1.0), smath::constants::e<>), "");

    static_assert(smath::pow(2, -1) == 0, "");
    static_assert(smath::pow(2, 0) == 1, "");
    static_assert(smath::pow(2, 1) == 2, "");
    static_assert(smath::pow(2, 2) == 4, "");

    static_assert(smath::pow(5.8, 0) == 1.0, "");
    static_assert(smath::is_close(smath::pow(5.8, 2), 33.64), "");
    static_assert(smath::is_close(smath::pow(2.0, -1), 0.5), "");
    static_assert(smath::is_close(smath::pow(2.0, -2), 0.25), "");

    static_assert(smath::is_close(smath::sqrt(4.0), 2.0), "");
    static_assert(smath::is_close(smath::sqrt(2.0), 1.414213562373095), "");
    static_assert(smath::is_close(smath::sqrt(3.0), 1.732050807568877), "");

    static_assert(smath::is_close(smath::hypot(3.0f, 4), 5.0), "");

    static_assert(smath::is_close(smath::exp(5.0), 148.4131591025766), "");

    static_assert(smath::log2(256) == 8, "");
    static_assert(smath::log10(100) == 2, "");
    static_assert(smath::is_close(smath::log(1.0), 0.0), "");
    static_assert(smath::is_close(smath::log(2.0),    0.693147180559945286226763982995180413126945496), "");
    static_assert(smath::is_close(smath::log(0.5),   -0.693147180559945286226763982995180413126945496), "");
    static_assert(smath::is_close(smath::log(0.1),   -2.302585084356761679913461193791590631008148193), "");
    static_assert(smath::is_close(smath::log(256.0),  5.545177444479563177992531564086675643920898438), "");

    ////////////////////////////////////////////////////////////
    // smath::constant overloads

    using namespace smath::constant_literals;

    static_assert(smath::abs(-5_c) == 5_c, "");
    static_assert(smath::abs(8_c) == 8_c, "");
    static_assert(smath::abs(-82_cl) == 82_cl, "");

    static_assert(
        std::is_same<
            decltype(smath::abs(-5_c)),
            smath::constant<int, 5>
        >::value, "");

    static_assert(
        smath::min(1_c, 2_c) == 1_c, "");
    static_assert(
        smath::min(0_c, 0_c) == 0_c, "");
    static_assert(
        smath::min(-2_c, -1_c, 0_c, 1_c, 2_c) == -2_c, "");
    static_assert(
        smath::min(2_c, 1_c, 0_c, -1_c, -2_c) == -2_c, "");

    static_assert(
        smath::max(3_c, 8_c) == 8_c, "");
    static_assert(
        smath::max(-8_c, -8_c) == -8_c, "");
    static_assert(
        smath::max(8_c, -1_c, 6_c, 3_c, 5_c, 2_c, -8_c) == 8_c, "");
    static_assert(
        smath::max(-1_c, 0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c, -1_c) == 3_c, "");

    static_assert(smath::pow(2_c, 0_c) == 1_c, "");
    static_assert(smath::pow(2_c, 1_c) == 2_c, "");
    static_assert(smath::pow(5_c, 1_c) == 5_c, "");
    static_assert(smath::pow(5_c, 0_c) == 1_c, "");
    static_assert(smath::pow(2_c, 1_c) == 2_c, "");
    static_assert(smath::pow(2_c, 2_c) == 4_c, "");

    static_assert(
        std::is_same<
            decltype(smath::pow(5_c, 2_c)),
            smath::constant<int, 25_c>
        >::value, "");
}
