/*
 * Copyright (C) 2013-2015 Morwenn
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

int main()
{
    static_assert(smath::sign(5) == 1, "");
    static_assert(smath::sign(-3) == -1, "");
    static_assert(smath::sign(2.0) == 1, "");
    static_assert(smath::sign(-5.8) == -1, "");
    static_assert(smath::sign(0) == 0, "");
    static_assert(smath::sign(0.0) == 0, "");

    static_assert(smath::is_even(5) == false, "");
    static_assert(smath::is_even(-4) == true, "");
    static_assert(smath::is_even(0) == true, "");

    static_assert(smath::is_odd(8) == false, "");
    static_assert(smath::is_odd(0) == false, "");
    static_assert(smath::is_odd(-5) == true, "");

    static_assert(smath::is_prime(0) == false, "");
    static_assert(smath::is_prime(1) == false, "");
    static_assert(smath::is_prime(2) == true, "");
    static_assert(smath::is_prime(3) == true, "");
    static_assert(smath::is_prime(4) == false, "");
    static_assert(smath::is_prime(5) == true, "");
    static_assert(smath::is_prime(7) == true, "");
    static_assert(smath::is_prime(8) == false, "");
    static_assert(smath::is_prime(9) == false, "");
    static_assert(smath::is_prime(128) == false, "");

    static_assert(smath::fibonacci(0) == 0, "");
    static_assert(smath::fibonacci(1) == 1, "");
    static_assert(smath::fibonacci(2) == 1, "");
    static_assert(smath::fibonacci(3) == 2, "");
    static_assert(smath::fibonacci(4) == 3, "");
    static_assert(smath::fibonacci(5) == 5, "");
    static_assert(smath::fibonacci(6) == 8, "");
    static_assert(smath::fibonacci(7) == 13, "");
    static_assert(smath::fibonacci(8) == 21, "");

    static_assert(smath::factorial(0) == 1, "");
    static_assert(smath::factorial(1) == 1, "");
    static_assert(smath::factorial(2) == 2, "");
    static_assert(smath::factorial(3) == 6, "");
    static_assert(smath::factorial(4) == 24, "");
    static_assert(smath::factorial(5) == 120, "");
    static_assert(smath::factorial(6) == 720, "");
    static_assert(smath::factorial(7) == 5040, "");

    static_assert(
        smath::sum(1, 2, 3, 4, 5) == 15,
    "");

    static_assert(smath::gcd(1071, 1029) == 21, "");
    static_assert(smath::gcd(1029, 1071) == 21, "");
    static_assert(smath::gcd(270, 84) == 6, "");
    static_assert(smath::gcd(84, 270) == 6, "");

    static_assert(smath::gcd(3, 6) == 3, "");
    static_assert(smath::gcd(-3, 6) == 3, "");
    static_assert(smath::gcd(3, -6) == 3, "");
    static_assert(smath::gcd(-3, -6) == 3, "");

    static_assert(smath::lcm(60, 168) == 840, "");
    static_assert(smath::lcm(168, 60) == 840, "");

    static_assert(smath::clamp(3, 2, 4) == 3, "");
    static_assert(smath::clamp(1, 2, 4) == 2, "");
    static_assert(smath::clamp(5, 2, 4) == 4, "");
}
