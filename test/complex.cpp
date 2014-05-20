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
    constexpr auto imag2 = imaginary<int>(-2);
    constexpr auto comp0 = complex<int>(5, 0);
    constexpr auto comp1 = complex<int>(0, 1);
    constexpr auto comp2 = complex<int>(-1, 3);
    constexpr auto comp3 = complex<long long int>(5, 0);
    constexpr auto comp4 = complex<int>(-2, 4);
    constexpr auto comp5 = complex<int>(3, -1);

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

    // imaginary-imaginary arithmetic
    static_assert(imag1 + imag1 == 2_i, "");
    static_assert(imag1 - imag0 == 1_i, "");
    static_assert(imag1 * imag1 == -1, "");
    static_assert(4_i / 2_i == 2, "");

    // imaginary-scalar arithmetic
    static_assert(imag1 + 2 == complex<int>(2, 1), "");
    static_assert(-3 + imag1 == complex<int>(-3, 1), "");
    static_assert(imag2 - 5 == complex<int>(-5, -2), "");
    static_assert(2 - imag2 == complex<int>(2, 2), "");
    static_assert(imag1 * 3 == imaginary<int>(3), "");
    static_assert(-4 * imag2 == imaginary<int>(8), "");
    static_assert(imag2 / 2 == -1_i, "");
    static_assert(5 / imag1 == 5_i, "");

    // complex-complex arithmetic
    static_assert(comp4 + comp5 == complex<int>(1, 3), "");
    static_assert(comp5 - comp4 == complex<int>(5, -5), "");
    static_assert(comp4 * comp5 == complex<int>(-2, 14), "");
    static_assert(comp4 / comp5 == complex<int>(-1, 1), "");

    // complex-scalar arithmetic
    static_assert(comp4 + 5 == complex<int>(3, 4), "");
    static_assert(-2 + comp5 == complex<int>(1, -1), "");
    static_assert(comp1 - 2 == complex<int>(-2, 1), "");
    static_assert(3 - comp2 == complex<int>(4, -3), "");
    static_assert(comp4 * 5 == complex<int>(-10, 20), "");
    static_assert(-2 * comp5 == complex<int>(-6, 2), "");
    static_assert(comp4 / 2 == complex<int>(-1, 2), "");
    static_assert(4 / complex<int>(2, 2) == complex<int>(1, -1), "");

    // complex-imaginary arithmetic
    static_assert(comp1 + 5_i == complex<int>(0, 6), "");
    static_assert(-2_i + comp0 == complex<int>(5, -2), "");
    static_assert(comp2 - -1_i == complex<int>(-1, 4), "");
    static_assert(8_i - comp3 == complex<int>(-5, 8), "");
    static_assert(comp4 * 2_i == complex<int>(-8, -4), "");
    static_assert(-3_i * comp5 == complex<int>(-3, -9), "");
    static_assert(comp4 / 2_i == complex<int>(2, 1), "");
    static_assert(4_i / complex<int>(2, 2) == complex<int>(1, 1), "");

    // Mathematical functions
    static_assert(real(comp5) == 3, "");
    static_assert(imag(comp4) == 4_i, "");
    static_assert(conj(comp4) == complex<int>(-2, -4), "");
    static_assert(conj(comp5) == complex<int>(3, 1), "");
}
