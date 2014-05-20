/*
 * Copyright (C) 2013 Morwenn
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
#include <static_math/cmath.h>

using namespace smath;


int main()
{
    static_assert(abs(-5) == 5, "");
    static_assert(abs(8) == 8, "");
    static_assert(abs(-82L) == 82, "");

    static_assert(min(1, 2) == 1, "");
    static_assert(min(0, 0) == 0, "");
    static_assert(min(-2, -1, 0, 1, 2) == -2, "");
    static_assert(min(2, 1, 0, -1, -2) == -2, "");

    static_assert(max(3, 8) == 8, "");
    static_assert(max(-8, -8) == -8, "");
    static_assert(max(8, -1, 6, 3, 5, 2, -8) == 8, "");
    static_assert(max(-1, 0, 1, 2, 3, 2, 1, 0, -1) == 3, "");

    static_assert(floor(2.5) == 2.0, "");
    static_assert(floor(2.01) == 2.0, "");
    static_assert(floor(2.8) == 2.0, "");
    static_assert(floor(-2.5) == -3.0, "");

    static_assert(ceil(2.5) == 3.0, "");
    static_assert(ceil(2.01) == 3.0, "");
    static_assert(ceil(2.8) == 3.0, "");
    static_assert(ceil(-2.5) == -2.0, "");

    static_assert(round(2.5) == 3.0, "");
    static_assert(round(2.01) == 2.0, "");
    static_assert(round(2.8) == 3.0, "");
    static_assert(round(-2.1) == -2.0, "");

    static_assert(trunc(2.5) == 2.0, "");
    static_assert(trunc(2.01) == 2.0, "");
    static_assert(trunc(2.8) == 2.0, "");
    static_assert(trunc(-2.1) == -2.0, "");

    static_assert(pow(2, 0) == 1, "");
    static_assert(pow(5.8, 0) == 1.0, "");
    static_assert(pow(2, 1) == 2, "");
    static_assert(pow(2, 2) == 4, "");

    static_assert(equals(sqrt(4.0), 2.0), "");
    static_assert(equals(sqrt(2.0), 1.414213562373095), "");
    static_assert(equals(sqrt(3.0), 1.732050807568877), "");
}
