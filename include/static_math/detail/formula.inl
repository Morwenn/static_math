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

////////////////////////////////////////////////////////////
// Helper functions

namespace detail
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
constexpr auto is_close(T a, U b)
    -> bool
{
    return detail::is_close(a, b);
}

template<typename T, typename U>
constexpr auto sum(T first, U second)
    -> decltype(auto)
{
    return first + second;
}

template<typename T, typename U, typename... Rest>
constexpr auto sum(T first, U second, Rest... rest)
    -> decltype(auto)
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
    -> decltype(auto)
{
    return x * x;
}

template<typename Number>
constexpr auto clamp(Number x, Number min, Number max)
    -> Number
{
    return (x < min) ? min : (x > max) ? max : x;
}

template<typename Integer, Integer N, Integer M, Integer O>
constexpr auto clamp(constant<Integer, N>, constant<Integer, M>, constant<Integer, O>)
    -> constant<Integer, clamp(N, M, O)>
{
    return {};
}

////////////////////////////////////////////////////////////
// Integer-related functions

template<typename Integer>
constexpr auto is_even(Integer n)
    -> decltype(auto)
{
    return detail::is_even(n);
}

template<typename Integer>
constexpr auto is_odd(Integer n)
    -> decltype(auto)
{
    return detail::is_odd(n);
}

template<typename Integer>
constexpr auto is_prime(Integer n)
    -> bool
{
    return (n < 2) ? false :
        (n == 2) ? true :
            (n % 2 == 0) ? false :
                detail::is_prime_helper(n, 3);
}

template<typename Integer, Integer N>
constexpr auto is_prime(constant<Integer, N>)
    -> constant<Integer, is_prime(N)>
{
    return {};
}

template<typename Integer>
constexpr auto fibonacci(Integer n)
    -> Integer
{
    return (n < 2) ? n : fibonacci(n-2) + fibonacci(n-1);
}

template<typename Integer, Integer N>
constexpr auto fibonacci(constant<Integer, N>)
    -> constant<Integer, fibonacci(N)>
{
    return {};
}

template<typename Integer>
constexpr auto factorial(Integer n)
    -> decltype(auto)
{
    return detail::factorial(n);
}

template<typename T, typename U>
constexpr auto gcd(T a, U b)
    -> std::common_type_t<T, U>
{
    return (a == 0 || b == 0) ? 0 :
        (a < 0 || b < 0) ? gcd(detail::abs(a), detail::abs(b)) :
            (a >= b) ? detail::gcd_helper(b, a % b) :
                detail::gcd_helper(a, b % a);
}

template<typename Integer, Integer N, Integer M>
constexpr auto gcd(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, gcd(N, M)>
{
    return {};
}

template<typename T, typename U>
constexpr auto lcm(T a, U b)
    -> std::common_type_t<T, U>
{
    return (a == 0 || b == 0) ? 1 :
        a * b / gcd(a, b);
}

template<typename Integer, Integer N, Integer M>
constexpr auto lcm(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, lcm(N, M)>
{
    return {};
}

////////////////////////////////////////////////////////////
// Angle conversions

template<typename Float>
constexpr auto degrees(Float x)
    -> Float
{
    return x * 180.0L / PI;
}

template<typename Float>
constexpr auto radians(Float x)
    -> Float
{
    return x * PI / 180.0L;
}
