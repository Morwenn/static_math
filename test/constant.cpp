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
#include <type_traits>
#include <static_math/constant.h>

int main()
{
    using namespace smath::constant_literals;

    // Constant literals
    {
        static_assert(0_c == 0, "");
        static_assert(1_c == 1, "");
        static_assert(-1_c == -1, "");
        static_assert(45_cl == 45l, "");
        static_assert(52_cll == 52ll, "");
        static_assert(decltype(45_cu)::value == 45u, "");
        static_assert(91_cul == 91ul, "");
        static_assert(23_cull == (long long unsigned)23, "");

        static_assert(
            std::is_same<
                decltype(58_c),
                smath::constant<int, 58>
            >::value, "");

        // Should be too big for an int but will either fit
        // a long or a long long depending on the platform
        // (assume well-known reasonable platforms)
        using big_type = decltype(1844674407370955161_c);
        static_assert(
            std::is_same<big_type::value_type, long>::value ||
            std::is_same<big_type::value_type, long long>::value,
            "");

        constexpr auto a = 42_c;
        constexpr auto b = +a;
        static_assert(b == 42, "");
        static_assert(b == +42_c, "");
        static_assert(b == 42_c, "");

        static_assert(
            std::is_same<
                decltype(+58_c),
                smath::constant<int, 58>
            >::value, "");
    }

    // Constant unary operators
    {
        constexpr auto a = 42_c;
        constexpr auto b = -a;
        static_assert(b == -42, "");
        static_assert(b == -42_c, "");

        static_assert(
            std::is_same<
                decltype(-58_c),
                smath::constant<int, -58>
            >::value, "");

        static_assert(smath::true_type{}, "");
        static_assert(!smath::false_type{}, "");
        static_assert(!!smath::true_type{}, "");

        static_assert(
            std::is_same<
                decltype(!smath::false_type{}),
                smath::true_type
            >::value, "");

        static_assert(
            std::is_same<
                decltype(!!smath::false_type{}),
                smath::false_type
            >::value, "");
    }

    // Constant binary arithmetic operators
    {
        static_assert(0_c + 0_c == 0_c, "");
        static_assert(1_c + 0_c == 1_c, "");
        static_assert(0_c + 1_c == 1_c, "");
        static_assert(88_c + 22_c == 110_c, "");

        static_assert(0_c - 0_c == 0_c, "");
        static_assert(1_c - 0_c == 1_c, "");
        static_assert(0_c - 1_c == -1_c, "");
        static_assert(88_c - 22_c == 66_c, "");

        static_assert(0_c * 0_c == 0_c, "");
        static_assert(1_c * 0_c == 0_c, "");
        static_assert(0_c * 1_c == 0_c, "");
        static_assert(88_c * 22_c == 1936_c, "");

        static_assert(0_c / 1_c == 0_c, "");
        static_assert(88_c / 22_c == 4_c, "");

        static_assert(0_c + 0_c == 0_c, "");
        static_assert(1_c + 0_c == 1_c, "");
        static_assert(0_c + 1_c == 1_c, "");
        static_assert(88_c + 22_c == 110_c, "");

        static_assert(27_c % 16_c == 11_c, "");
        static_assert(30_c % 3_c == 0_c, "");
        static_assert(35_c % 3_c == 2_c, "");
        static_assert(16_c % 6_c == 4_c, "");
        static_assert(15_c % 12_c == 3_c, "");
    }

    // Constant comparison operators
    {
        static_assert(52_c == 52_c, "");
        static_assert(0_c != 1_c, "");

        static_assert(
            std::is_same<
                decltype(45_c == 23_c),
                smath::false_type
            >::value, "");

        static_assert(
            std::is_same<
                decltype(45_c != 23_c),
                smath::true_type
            >::value, "");
    }

    // Constant relational operators
    {
        static_assert(51_c < 52_c, "");
        static_assert(23_c <= 42_c, "");
        static_assert(23_c <= 23_c, "");
        static_assert(29_c > 17_c, "");
        static_assert(85_c >= 53_c, "");
        static_assert(87_c >= 87_c, "");

        static_assert(
            std::is_same<
                decltype(45_c < 23_c),
                smath::false_type
            >::value, "");

        static_assert(
            std::is_same<
                decltype(45_c <= 23_c),
                smath::false_type
            >::value, "");

        static_assert(
            std::is_same<
                decltype(45_c > 23_c),
                smath::true_type
            >::value, "");

        static_assert(
            std::is_same<
                decltype(45_c >= 23_c),
                smath::true_type
            >::value, "");
    }
}
