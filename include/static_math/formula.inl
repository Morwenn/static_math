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

////////////////////////////////////////////////////////////
// Helper functions

namespace details
{
    template<typename T>
    constexpr bool is_prime_helper(T n, T div)
    {
        return (div*div > n) ? true :
            (n % div == 0) ? false :
                is_prime_helper(n, div+2);
    }

    template<typename T, typename U>
    constexpr
    typename std::common_type<T, U>::type
    gcd_helper(T b, U r)
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

template<typename Numeric>
constexpr
Numeric sum(Numeric first, Numeric second)
{
    return first + second;
}

template<typename Numeric, typename... Rest>
constexpr
Numeric sum(Numeric first, Numeric second, Rest... rest)
{
    return first + sum(second, rest...);
}

template<typename... Numbers>
constexpr
long double mean(Numbers... args)
{
    return (long double) sum(args...) / (long double) sizeof...(args);
}

template<typename Number>
constexpr Number sqr(Number x)
{
    return x * x;
}

template<typename Number>
constexpr Number clamp(Number x, Number min, Number max)
{
    return (x < min) ? min : (x > max) ? max : x;
}

////////////////////////////////////////////////////////////
// Integer-related functions

template<typename T>
constexpr
typename std::enable_if<is_integral<T>::value, bool>::type
is_even(T n)
{
    using res_type = typename std::make_unsigned<T>::type;
    return !((res_type) n & 1);
}

template<typename T>
constexpr
typename std::enable_if<is_integral<T>::value, bool>::type
is_odd(T n)
{
    using res_type = typename std::make_unsigned<T>::type;
    return (res_type) n & 1;
}

template<typename T>
constexpr
typename std::enable_if<is_integral<T>::value, bool>::type
is_prime(T n)
{
    return (n < 2) ? false :
        (n == 2) ? true :
            (n % 2 == 0) ? false :
                details::is_prime_helper(n, 3);
}

template<typename T>
constexpr
typename std::enable_if<is_integral<T>::value, T>::type
fibonacci(T n)
{
    return (n < 2) ? n : fibonacci(n-2) + fibonacci(n-1);
}

template<typename T>
constexpr
typename std::enable_if<is_integral<T>::value, T>::type
factorial(T n)
{
    return (n > 1) ? n * factorial(n - 1) : 1;
}

template<typename T, typename U>
constexpr
typename std::enable_if<is_integral<T, U>::value, typename std::common_type<T, U>::type>::type
gcd(T a, U b)
{
    return (a == 0 || b == 0) ? 0 :
        (a >= b) ? details::gcd_helper(b, a % b) :
            details::gcd_helper(a, b % a);
}

template<typename T, typename U>
constexpr
typename std::enable_if<is_integral<T, U>::value, typename std::common_type<T, U>::type>::type
lcm(T a, U b)
{
    return (a == 0 || b == 0) ? 1 :
        a * b / gcd(a, b);
}

////////////////////////////////////////////////////////////
// Angle conversions

template<typename T>
constexpr
typename std::enable_if<std::is_floating_point<T>::value, T>::type
degree(T x)
{
    return x * 180.0L / PI;
}

template<typename T>
constexpr
typename std::enable_if<std::is_floating_point<T>::value, T>::type
radian(T x)
{
    return x * PI / 180.0L;
}
