/*
 * Copyright (C) 2014 Morwenn
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
#include <static_math/vector.h>

int main()
{
    using namespace smath;

    // TEST: basics
    // - construction
    // - accessors
    // - capacity
    {
        constexpr vector<int, 1> v0 { 5 };
        constexpr vector<int, 3> v1 = { 1, 2, 3 };

        static_assert(v0[0] == 5, "");
        static_assert(v0.at(0) == 5, "");
        static_assert(v0.front() == 5, "");
        static_assert(v0.back() == 5, "");
        static_assert(v1[2] == 3, "");
        static_assert(v1.at(1) == 2, "");
        static_assert(v1.front() == 1, "");
        static_assert(v1.back() == 3, "");

        static_assert(not v0.empty(), "");
        static_assert(v0.size() == 1, "");
        static_assert(v0.max_size() == 1, "");
        static_assert(not v1.empty(), "");
        static_assert(v1.size() == 3, "");
        static_assert(v1.max_size() == v1.size(), "");
    }
}
