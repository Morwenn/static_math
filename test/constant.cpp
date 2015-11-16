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
}
