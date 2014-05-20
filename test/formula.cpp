/*
 * Copyright (C) 2013-2014 Morwenn
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
#include <static_math/formula.h>

using namespace smath;


int main()
{
    static_assert(sign(5) == 1, "");
    static_assert(sign(-3) == -1, "");
    static_assert(sign(2.0) == 1, "");
    static_assert(sign(-5.8) == -1, "");
    static_assert(sign(0) == 0, "");
    static_assert(sign(0.0) == 0, "");

    static_assert(is_even(5) == false, "");
    static_assert(is_even(-4) == true, "");
    static_assert(is_even(0) == true, "");

    static_assert(is_odd(8) == false, "");
    static_assert(is_odd(0) == false, "");
    static_assert(is_odd(-5) == true, "");

    static_assert(is_prime(0) == false, "");
    static_assert(is_prime(1) == false, "");
    static_assert(is_prime(2) == true, "");
    static_assert(is_prime(3) == true, "");
    static_assert(is_prime(4) == false, "");
    static_assert(is_prime(5) == true, "");
    static_assert(is_prime(7) == true, "");
    static_assert(is_prime(8) == false, "");
    static_assert(is_prime(9) == false, "");
    static_assert(is_prime(128) == false, "");

    static_assert(fibonacci(0) == 0, "");
    static_assert(fibonacci(1) == 1, "");
    static_assert(fibonacci(2) == 1, "");
    static_assert(fibonacci(3) == 2, "");
    static_assert(fibonacci(4) == 3, "");
    static_assert(fibonacci(5) == 5, "");
    static_assert(fibonacci(6) == 8, "");
    static_assert(fibonacci(7) == 13, "");
    static_assert(fibonacci(8) == 21, "");

    static_assert(factorial(0) == 1, "");
    static_assert(factorial(1) == 1, "");
    static_assert(factorial(2) == 2, "");
    static_assert(factorial(3) == 6, "");
    static_assert(factorial(4) == 24, "");
    static_assert(factorial(5) == 120, "");
    static_assert(factorial(6) == 720, "");
    static_assert(factorial(7) == 5040, "");

    static_assert(
        sum(1, 2, 3, 4, 5) == 15,
    "");

    static_assert(gcd(1071, 1029) == 21, "");
    static_assert(gcd(1029, 1071) == 21, "");
    static_assert(gcd(270, 84) == 6, "");
    static_assert(gcd(84, 270) == 6, "");

    static_assert(lcm(60, 168) == 840, "");
    static_assert(lcm(168, 60) == 840, "");

    static_assert(clamp(3, 2, 4) == 3, "");
    static_assert(clamp(1, 2, 4) == 2, "");
    static_assert(clamp(5, 2, 4) == 4, "");
}
