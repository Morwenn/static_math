/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
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
#include <static_math/rational.h>

using namespace smath;


int main()
{
    // Constructor tests
    constexpr auto ratio = rational<int>(4, 3);
    static_assert(ratio.numer == 4, "");
    static_assert(ratio.denom == 3, "");

    constexpr auto ratio2 = rational<int>(5);
    static_assert(ratio2.numer == 5, "");
    static_assert(ratio2.denom == 1, "");

    constexpr auto r1 = rational<int>(1, 2);
    constexpr auto r2 = rational<int>(2, 4);
    constexpr auto r3 = rational<int>(1, 3);
    constexpr auto r4 = rational<int>(5, 1);
    constexpr auto r5 = rational<int>(-1, 2);
    constexpr auto r6 = rational<int>(1, -2);
    constexpr auto r7 = rational<int>(4, 5);

    // Rational-rational comparison
    static_assert(r1 == r2, "");
    static_assert(r1 != r3, "");
    static_assert(r1 > r3, "");
    static_assert(r3 < r2, "");
    static_assert(r1 >= r2, "");
    static_assert(r3 <= r2, "");
    static_assert(r5 == r6, "");

    // Rational-integral comparison
    static_assert(r4 == 5, "");
    static_assert(5 == r4, "");
    static_assert(r1 != 3, "");
    static_assert(8 != r2, "");
    static_assert(0 < r1, "");
    static_assert(r2 < 1, "");
    static_assert(8 > r4, "");
    static_assert(r2 > -1, "");
    static_assert(5 <= r4, "");
    static_assert(r3 <= 1, "");
    static_assert(1 >= r3, "");
    static_assert(r1 >= -8, "");
    static_assert(r5 <= 0, "");
    static_assert(r6 <= 0, "");

    // Rational-rational arithmetic operations
    static_assert(r1 + r2 == 1, "");
    static_assert(r4 - r1 == rational<int>(9, 2), "");
    static_assert(r2 * r3 == rational<int>(1, 6), "");
    static_assert(r1 / r3 == rational<int>(3, 2), "");

    // Rational-integral arithmetic operations
    static_assert(r1 + 1 == rational<int>(3, 2), "");
    static_assert(2 + r2 == rational<int>(5, 2), "");
    static_assert(r3 - 3 == rational<int>(-8, 3), "");
    static_assert(2 - r1 == rational<int>(3, 2), "");
    static_assert(r4 * 2 == 10, "");
    static_assert(6 * r2 == r1 * 6, "");
    static_assert(1 / r2 == 2, "");
    static_assert(r3 / 3 == rational<int>(1, 9), "");

    // Cast
    static_assert(rational<int>(1, 2) == rational<long int>(1, 2), "");
    static_assert(rational<unsigned long long>(3, 2) == rational<short>(3, 2), "");
    static_assert(float(r1) == 0.5f, "");
    static_assert(double(r1) == 0.5, "");
    static_assert((long double)(r1) == 0.5l, "");

    // User-defined literal
    static_assert(2 / 3_r == rational<unsigned long long>(2, 3), "");
    static_assert(1_r / 8 == rational<unsigned long long>(1, 8), "");
    static_assert(3 / 5_r == 3_r / 5, "");

    constexpr auto a0 = rational<int>(0, 1);
    constexpr auto a1 = rational<int>(1, 2);
    constexpr auto a2 = rational<int>(-3, 8);
    constexpr auto a3 = rational<int>(6, -7);

    // Math functions
    static_assert(smath::sign(a0) == 0, "");
    static_assert(smath::sign(a1) == 1, "");
    static_assert(smath::sign(a2) == -1, "");
    static_assert(smath::sign(a3) == -1, "");

    static_assert(smath::abs(a1) == 1 / 2_r, "");
    static_assert(smath::abs(a2) == 3 / 8_r, "");
    static_assert(smath::abs(a3) == 6 / 7_r, "");

    static_assert(smath::round(a1) == 1.0, "");
    /* No more tests for ceil, floor, trunc
     * and round since they are based on
     * the floating point functions after
     * a simple cast.
     */

    static_assert(smath::reciprocal(a1) == 2, "");
    static_assert(smath::reciprocal(a2) == rational<int>(8, -3), "");

    static_assert(smath::pow(a1, 2) == 1 / 4_r, "");
    static_assert(smath::pow(a2, 3) == -27 / 512_r, "");
    static_assert(smath::pow(a3, -2) == 49 / 36_r, "");
    static_assert(smath::pow(r1, 0) == 1_r, "");
    static_assert(smath::pow(r2, 1) == r2, "");
    static_assert(smath::pow(r7, 3) == 64 / 125_r, "");
}
