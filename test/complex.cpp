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

    constexpr auto imag0 = imaginary<int>(0);
    constexpr auto imag1 = imaginary<int>(1);
    constexpr auto comp0 = complex<int>(5, 0);
    constexpr auto comp1 = complex<int>(0, 1);
    constexpr auto comp3 = complex<long long int>(5, 0);

    // Unary + and -
    static_assert(-imag1 == imaginary<int>(-1), "");
    static_assert(+imag1 == imaginary<int>(1), "");
    static_assert(+comp0 == complex<int>(5, 0), "");
    static_assert(-comp0 == complex<int>(-5, 0), "");

    // Comparison tests
    static_assert(comp0 == 5, "");
    static_assert(comp1 == imag1, "");
    static_assert(comp0 == comp3, "");
    static_assert(comp0 != 3, "");
    static_assert(imag0 != imag1, "");
    static_assert(comp0 != comp1, "");

    return 0;
}
