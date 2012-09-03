/*
 * Copyright (C) 2011-2012 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <static_math/rational.h>

using namespace smath;


int main()
{
    // Constructor tests
    constexpr auto ratio = rational<int>(4, 2);
    static_assert(ratio.numerator() == 4, "");
    static_assert(ratio.denominator() == 2, "");

    constexpr auto ratio2 = rational<int>(5);
    static_assert(ratio2.numerator() == 5, "");
    static_assert(ratio2.denominator() == 1, "");

    constexpr auto r1 = rational<int>(1, 2);
    constexpr auto r2 = rational<int>(2, 4);
    constexpr auto r3 = rational<int>(1, 3);
    constexpr auto r4 = rational<int>(5, 1);

    // rational-rational comparison
    static_assert(r1 == r2, "");
    static_assert(r1 != r3, "");
    static_assert(r1 > r3, "");
    static_assert(r3 < r2, "");
    static_assert(r1 >= r2, "");
    static_assert(r3 <= r2, "");

    // rational-integral comparison
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

    // rational-rational arithmetic operations
    static_assert(r1 + r2 == 1, "");
    static_assert(r4 - r1 == rational<int>(9, 2), "");
    static_assert(r2 * r3 == rational<int>(1, 6), "");
    static_assert(r1 / r3 == rational<int>(3, 2), "");

    // rational-integral arithmetic operations
    static_assert(r1 + 1 == rational<int>(3, 2), "");
    static_assert(2 + r2 == rational<int>(5, 2), "");
    static_assert(r3 - 3 == rational<int>(-8, 3), "");
    static_assert(2 - r1 == rational<int>(3, 2), "");
    static_assert(r4 * 2 == 10, "");
    static_assert(6 * r2 == r1 * 6, "");
    static_assert(1 / r2 == 2, "");
    static_assert(r3 / 3 == rational<int>(1, 9), "");

    return 0;
}
