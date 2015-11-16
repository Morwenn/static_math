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
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#include <type_traits>
#include <static_math/cmath.h>
#include <static_math/constant.h>
#include <static_math/formula.h>

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

        // Should be too big for an int
        static_assert(
            std::is_same<
                decltype(1844674407370955161_c),
                smath::constant<long long, 1844674407370955161>
            >::value, "");

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

    // Constant cmath functions
    {
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

    // Constant formula functions
    {
        static_assert(smath::sqr(0_c) == 0_c, "");
        static_assert(smath::sqr(1_c) == 1_c, "");
        static_assert(smath::sqr(2_c) == 4_c, "");
        static_assert(smath::sqr(3_c) == 9_c, "");
        static_assert(smath::sqr(4_c) == 16_c, "");
        static_assert(smath::sqr(5_c) == 25_c, "");
        static_assert(smath::sqr(10_c) == 100_c, "");

        static_assert(
            std::is_same<
                decltype(smath::sqr(8_c)),
                smath::constant<int, 64>
            >::value, "");

        static_assert(not smath::is_even(5_c), "");
        static_assert(smath::is_even(-4_c), "");
        static_assert(smath::is_even(0_c), "");

        static_assert(not smath::is_odd(8_c), "");
        static_assert(not smath::is_odd(0_c), "");
        static_assert(smath::is_odd(-5_c), "");

        static_assert(
            std::is_same<
                decltype(smath::is_odd(64_c)),
                smath::false_type
            >::value, "");
    }
}
