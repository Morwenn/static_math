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

////////////////////////////////////////////////////////////
// Helper functions

namespace details
{
    template<typename T>
    constexpr auto is_prime_helper(T n, T div)
        -> bool
    {
        return (div*div > n) ? true :
            (n % div == 0) ? false :
                is_prime_helper(n, div+2);
    }

    template<typename T, typename U>
    constexpr auto gcd_helper(T b, U r)
        -> std::common_type_t<T, U>
    {
        return (r == 0) ? b : gcd_helper(r, b % r);
    }
}

////////////////////////////////////////////////////////////
// Basic functions

template<typename Number>
constexpr auto sign(Number x)
    -> int
{
    return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}

template<typename T, typename U>
constexpr auto sum(T first, U second)
    -> std::common_type_t<T, U>
{
    return first + second;
}

template<typename T, typename U, typename... Rest>
constexpr auto sum(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>
{
    return first + sum(second, rest...);
}

template<typename... Numbers>
constexpr auto mean(Numbers... args)
    -> decltype(sum(args...) / sizeof...(args))
{
    return sum(args...) / sizeof...(args);
}

template<typename Number>
constexpr auto sqr(Number x)
    -> Number
{
    return x * x;
}

template<typename Number>
constexpr auto clamp(Number x, Number min, Number max)
    -> Number
{
    return (x < min) ? min : (x > max) ? max : x;
}

////////////////////////////////////////////////////////////
// Integer-related functions

template<typename Integer,
         typename = std::enable_if_t<is_integral<Integer>::value, void>>
constexpr auto is_even(Integer n)
    -> bool
{
    return not bool(n % 2);
}

template<typename Integer,
         typename = std::enable_if_t<is_integral<Integer>::value, void>>
constexpr auto is_odd(Integer n)
    -> bool
{
    return bool(n % 2);
}

template<typename Integer,
         typename = std::enable_if_t<is_integral<Integer>::value, void>>
constexpr auto is_prime(Integer n)
    -> bool
{
    return (n < 2) ? false :
        (n == 2) ? true :
            (n % 2 == 0) ? false :
                details::is_prime_helper(n, 3);
}

template<typename Integer,
         typename = std::enable_if_t<is_integral<Integer>::value, void>>
constexpr auto fibonacci(Integer n)
    -> Integer
{
    return (n < 2) ? n : fibonacci(n-2) + fibonacci(n-1);
}

template<typename Integer,
         typename = std::enable_if_t<is_integral<Integer>::value, void>>
constexpr auto factorial(Integer n)
    -> Integer
{
    return (n > 1) ? n * factorial(n - 1) : 1;
}

template<typename T, typename U,
         typename = std::enable_if_t<is_integral<T, U>::value, void>>
constexpr auto gcd(T a, U b)
    -> std::common_type_t<T, U>
{
    return (a == 0 || b == 0) ? 0 :
        (a >= b) ? details::gcd_helper(b, a % b) :
            details::gcd_helper(a, b % a);
}

template<typename T, typename U,
         typename = std::enable_if_t<is_integral<T, U>::value, void>>
constexpr auto lcm(T a, U b)
    -> std::common_type_t<T, U>
{
    return (a == 0 || b == 0) ? 1 :
        a * b / gcd(a, b);
}

////////////////////////////////////////////////////////////
// Angle conversions

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto degrees(Float x)
    -> Float
{
    return x * 180.0L / PI;
}

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto radians(Float x)
    -> Float
{
    return x * PI / 180.0L;
}
