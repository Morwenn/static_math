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
    constexpr auto ratio = rational<int>(4, 2);

    static_assert(ratio.numerator() == 4, "");
    static_assert(ratio.denominator() == 2, "");

    constexpr auto r1 = rational<int>(1, 2);
    constexpr auto r2 = rational<int>(2, 4);
    constexpr auto r3 = rational<int>(1, 3);

    static_assert(r1 == r2, "");
    static_assert(r1 != r3, "");
    static_assert(r1 > r3, "");
    static_assert(r3 < r2, "");
    static_assert(r1 >= r2, "");
    static_assert(r3 <= r2, "");

    return 0;
}
