/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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
    return x * 180.0L / constants::pi<Float>;
}

template<typename Float>
constexpr auto radians(Float x)
    -> Float
{
    return x * constants::pi<Float> / 180.0L;
}
