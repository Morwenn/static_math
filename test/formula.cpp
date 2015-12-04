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
#include <static_math/formula.h>

int main()
{
    ////////////////////////////////////////////////////////////
    // Regular functions

    static_assert(smath::sign(5) == 1, "");
    static_assert(smath::sign(-3) == -1, "");
    static_assert(smath::sign(2.0) == 1, "");
    static_assert(smath::sign(-5.8) == -1, "");
    static_assert(smath::sign(0) == 0, "");
    static_assert(smath::sign(0.0) == 0, "");

    static_assert(smath::is_even(5) == false, "");
    static_assert(smath::is_even(-4) == true, "");
    static_assert(smath::is_even(0) == true, "");

    static_assert(smath::is_odd(8) == false, "");
    static_assert(smath::is_odd(0) == false, "");
    static_assert(smath::is_odd(-5) == true, "");

    static_assert(smath::is_prime(0) == false, "");
    static_assert(smath::is_prime(1) == false, "");
    static_assert(smath::is_prime(2) == true, "");
    static_assert(smath::is_prime(3) == true, "");
    static_assert(smath::is_prime(4) == false, "");
    static_assert(smath::is_prime(5) == true, "");
    static_assert(smath::is_prime(7) == true, "");
    static_assert(smath::is_prime(8) == false, "");
    static_assert(smath::is_prime(9) == false, "");
    static_assert(smath::is_prime(128) == false, "");

    static_assert(smath::fibonacci(0) == 0, "");
    static_assert(smath::fibonacci(1) == 1, "");
    static_assert(smath::fibonacci(2) == 1, "");
    static_assert(smath::fibonacci(3) == 2, "");
    static_assert(smath::fibonacci(4) == 3, "");
    static_assert(smath::fibonacci(5) == 5, "");
    static_assert(smath::fibonacci(6) == 8, "");
    static_assert(smath::fibonacci(7) == 13, "");
    static_assert(smath::fibonacci(8) == 21, "");

    static_assert(smath::factorial(0) == 1, "");
    static_assert(smath::factorial(1) == 1, "");
    static_assert(smath::factorial(2) == 2, "");
    static_assert(smath::factorial(3) == 6, "");
    static_assert(smath::factorial(4) == 24, "");
    static_assert(smath::factorial(5) == 120, "");
    static_assert(smath::factorial(6) == 720, "");
    static_assert(smath::factorial(7) == 5040, "");

    static_assert(
        smath::sum(1, 2, 3, 4, 5) == 15,
    "");

    static_assert(smath::gcd(1071, 1029) == 21, "");
    static_assert(smath::gcd(1029, 1071) == 21, "");
    static_assert(smath::gcd(270, 84) == 6, "");
    static_assert(smath::gcd(84, 270) == 6, "");

    static_assert(smath::gcd(3, 6) == 3, "");
    static_assert(smath::gcd(-3, 6) == 3, "");
    static_assert(smath::gcd(3, -6) == 3, "");
    static_assert(smath::gcd(-3, -6) == 3, "");

    static_assert(smath::lcm(60, 168) == 840, "");
    static_assert(smath::lcm(168, 60) == 840, "");

    static_assert(smath::clamp(3, 2, 4) == 3, "");
    static_assert(smath::clamp(1, 2, 4) == 2, "");
    static_assert(smath::clamp(5, 2, 4) == 4, "");

    ////////////////////////////////////////////////////////////
    // smath::constant overloads

    using namespace smath::constant_literals;

    static_assert(not smath::is_even(5_c), "");
    static_assert(    smath::is_even(-4_c), "");
    static_assert(    smath::is_even(0_c), "");

    static_assert(not smath::is_odd(8_c), "");
    static_assert(not smath::is_odd(0_c), "");
    static_assert(    smath::is_odd(-5_c), "");

    static_assert(not smath::is_prime(0_c), "");
    static_assert(not smath::is_prime(1_c), "");
    static_assert(    smath::is_prime(2_c), "");
    static_assert(    smath::is_prime(3_c), "");
    static_assert(not smath::is_prime(4_c), "");
    static_assert(    smath::is_prime(5_c), "");
    static_assert(    smath::is_prime(7_c), "");
    static_assert(not smath::is_prime(8_c), "");
    static_assert(not smath::is_prime(9_c), "");
    static_assert(not smath::is_prime(128_c), "");

    static_assert(smath::fibonacci(0_c) == 0_c, "");
    static_assert(smath::fibonacci(1_c) == 1_c, "");
    static_assert(smath::fibonacci(2_c) == 1_c, "");
    static_assert(smath::fibonacci(3_c) == 2_c, "");
    static_assert(smath::fibonacci(4_c) == 3_c, "");
    static_assert(smath::fibonacci(5_c) == 5_c, "");
    static_assert(smath::fibonacci(6_c) == 8_c, "");
    static_assert(smath::fibonacci(7_c) == 13_c, "");
    static_assert(smath::fibonacci(8_c) == 21_c, "");

    static_assert(smath::factorial(0_c) == 1_c, "");
    static_assert(smath::factorial(1_c) == 1_c, "");
    static_assert(smath::factorial(2_c) == 2_c, "");
    static_assert(smath::factorial(3_c) == 6_c, "");
    static_assert(smath::factorial(4_c) == 24_c, "");
    static_assert(smath::factorial(5_c) == 120_c, "");
    static_assert(smath::factorial(6_c) == 720_c, "");
    static_assert(smath::factorial(7_c) == 5040_c, "");

    static_assert(
        smath::sum(1_c, 2_c, 3_c, 4_c, 5_c) == 15_c,
    "");

    static_assert(
        std::is_same<
            decltype(smath::sum(1_c, 2_c, 3_c, 4_c, 5_c)),
            smath::constant<int, 15>
        >::value, "");

    static_assert(smath::gcd(1071_c, 1029_c) == 21_c, "");
    static_assert(smath::gcd(1029_c, 1071_c) == 21_c, "");
    static_assert(smath::gcd(270_c, 84_c) == 6_c, "");
    static_assert(smath::gcd(84_c, 270_c) == 6_c, "");

    static_assert(smath::gcd(3_c, 6_c) == 3_c, "");
    static_assert(smath::gcd(-3_c, 6_c) == 3_c, "");
    static_assert(smath::gcd(3_c, -6_c) == 3_c, "");
    static_assert(smath::gcd(-3_c, -6_c) == 3_c, "");

    static_assert(smath::lcm(60_c, 168_c) == 840_c, "");
    static_assert(smath::lcm(168_c, 60_c) == 840_c, "");

    static_assert(smath::clamp(3_c, 2_c, 4_c) == 3_c, "");
    static_assert(smath::clamp(1_c, 2_c, 4_c) == 2_c, "");
    static_assert(smath::clamp(5_c, 2_c, 4_c) == 4_c, "");

    static_assert(
        std::is_same<
            decltype(smath::clamp(5_c, 2_c, 4_c)),
            smath::constant<int, 4>
        >::value, "");
}
