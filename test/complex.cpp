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
#include <static_math/utils/compare.h>
#include <static_math/complex.h>

using namespace smath;


int main()
{
    // Constructor tests
    constexpr auto i1 = imaginary<float>(5.8f);
    static_assert(equals(i1.value(), 5.8f), "");

    constexpr auto c1 = complex<float>(1.2f, 2.5f);
    static_assert(equals(c1.real(), 1.2f), "");
    static_assert(equals(c1.imag_value(), 2.5f), "");

    return 0;
}
