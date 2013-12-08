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
#include <static_math/matrix.h>

using namespace smath;


int main()
{
    constexpr matrix<2, 3> a = {{
        { 1.0, 2.5, 5.2 },
        { 2.0, 3.8, 6.8 }
    }};

    static_assert(a.height() == 2, "");
    static_assert(a.width() == 3, "");
    static_assert(a.size() == 6, "");
}
