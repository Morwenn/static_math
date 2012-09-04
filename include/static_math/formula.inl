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


////////////////////////////////////////////////////////////
// Static variables, Initialization & Helpers
////////////////////////////////////////////////////////////

namespace
{
    // Helper for the is_prime() function
    template<typename T>
    constexpr bool _is_prime_helper(T n, T div)
    {
        return (div*div > n) ? true :
            (n % div == 0) ? false :
                _is_prime_helper(n, div+2);
    }

    template<typename T, typename U>
    constexpr
    typename greater_of<T, U>::type
    _gcd_helper(T b, U r)
    {
        return (r == 0) ? b : _gcd_helper(r, b % r);
    }
}


////////////////////////////////////////////////////////////
// Functions definitions
////////////////////////////////////////////////////////////

template<typename T>
constexpr int sign(const T& value)
{
    return (value > 0) ? 1 : (value < 0) ? -1 : 0;
}

template<typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_even(T n)
{
    using res_type = typename std::make_unsigned<T>::type;
    return !((res_type) n & 1);
}

template<typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T n)
{
    using res_type = typename std::make_unsigned<T>::type;
    return (res_type) n & 1;
}

template<typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_prime(T n)
{
    return (n < 2) ? false :
                     (n == 2) ? true :
                              _is_prime_helper(n, 2);
}

template<typename T>
constexpr
typename std::enable_if<std::is_floating_point<T>::value, T>::type
degree(T rad)
{
    return rad * 180.0L / PI;
}

template<typename T>
constexpr
typename std::enable_if<std::is_floating_point<T>::value, T>::type
radian(T deg)
{
    return deg * PI / 180.0L;
}

template<typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, T>::type
fibonacci(T n)
{
    return (n < 2) ? n : fibonacci(n-2) + fibonacci(n-1);
}

template<typename T>
constexpr
typename std::enable_if<std::is_integral<T>::value, T>::type
factorial(T n)
{
    return (n > 1) ? n * factorial(n - 1) : 1;
}

template<typename Numeric, typename... Rest>
constexpr
Numeric sum(Numeric first, Numeric second, Rest... rest)
{
    return first + sum(second, rest...);
}

template<typename Numeric>
constexpr
Numeric sum(Numeric first, Numeric second)
{
    return first + second;
}

template<typename... Args>
constexpr
long double mean(Args... args)
{
    return (long double) sum(args...) / (long double) sizeof...(args);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<T>::value && std::is_integral<U>::value, typename greater_of<T, U>::type>::type
gcd(T a, U b)
{
    return (a == 0 || b == 0) ? 0 :
        (a >= b) ? _gcd_helper(b, a % b) :
            _gcd_helper(a, b % a);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<T>::value && std::is_integral<U>::value, typename greater_of<T, U>::type>::type
lcm(T a, U b)
{
    return (a == 0 || b == 0) ? 1 :
        a * b / gcd(a, b);
}
