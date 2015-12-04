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
// Construction

template<typename T>
constexpr rational<T>::rational(value_type numerator):
    numer(numerator),
    denom(1)
{}

template<typename T>
constexpr rational<T>::rational(value_type numerator, value_type denominator):
    numer(
        numerator != 0 ?
            numerator * sign(denominator)
                / gcd(abs(numerator), abs(denominator))
        : 0
    ),
    denom(
        numerator != 0 ?
            abs(denominator)
                / gcd(abs(numerator), abs(denominator))
        : 1
    )
{}

////////////////////////////////////////////////////////////
// Casts

template<typename T>
constexpr rational<T>::operator float() const
{
    return static_cast<float>(numer) /
           static_cast<float>(denom);
}

template<typename T>
constexpr rational<T>::operator double() const
{
    return static_cast<double>(numer) /
           static_cast<double>(denom);
}

template<typename T>
constexpr rational<T>::operator long double() const
{
    return static_cast<long double>(numer) /
           static_cast<long double>(denom);
}

template<typename T>
constexpr rational<T>::operator bool() const
{
    return numer == 0;
}

////////////////////////////////////////////////////////////
// Unary arithmetic operators

template<typename T>
constexpr auto operator+(rational<T> lhs)
    -> rational<T>
{
    return lhs;
}

template<typename T>
constexpr auto operator-(rational<T> lhs)
    -> rational<T>
{
    return {
        -lhs.numer,
        lhs.denom
    };
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename T, typename U>
constexpr auto operator+(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>
{
    return {
        lhs.numer * rhs.denom + rhs.numer * lhs.denom,
        lhs.denom * rhs.denom
    };
}

template<typename T, typename U>
constexpr auto operator-(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>
{
    return {
        lhs.numer * rhs.denom - rhs.numer * lhs.denom,
        lhs.denom * rhs.denom
    };
}

template<typename T, typename U>
constexpr auto operator*(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>
{
    return {
        lhs.numer * rhs.numer,
        lhs.denom * rhs.denom
    };
}

template<typename T, typename U>
constexpr auto operator/(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>
{
    return {
        lhs.numer * rhs.denom,
        lhs.denom * rhs.numer
    };
}

template<typename T, typename Integer>
constexpr auto operator+(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs.numer + rhs * lhs.denom,
        lhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator-(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs.numer - rhs * lhs.denom,
        lhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator*(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs.numer * rhs,
        lhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator/(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs.numer,
        lhs.denom * rhs
    };
}

template<typename T, typename Integer>
constexpr auto operator+(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs * rhs.denom + rhs.numer,
        rhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator-(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs * rhs.denom - rhs.numer,
        rhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator*(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs * rhs.numer,
        rhs.denom
    };
}

template<typename T, typename Integer>
constexpr auto operator/(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>
{
    return {
        lhs * rhs.denom,
        rhs.numer
    };
}

////////////////////////////////////////////////////////////
// Relational operators

template<typename T, typename U>
constexpr auto operator==(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return lhs.numer == rhs.numer
        && lhs.denom == rhs.denom;
}

template<typename T, typename U>
constexpr auto operator!=(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator<(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return lhs.numer * rhs.denom < lhs.denom * rhs.numer;
}

template<typename T, typename U>
constexpr auto operator>(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return lhs.numer * rhs.denom > lhs.denom * rhs.numer;
}

template<typename T, typename U>
constexpr auto operator<=(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return lhs.numer * rhs.denom <= lhs.denom * rhs.numer;
}

template<typename T, typename U>
constexpr auto operator>=(rational<T> lhs, rational<U> rhs)
    -> bool
{
    return lhs.numer * rhs.denom >= lhs.denom * rhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator==(rational<T> lhs, Integer rhs)
    -> bool
{
    return rhs * lhs.denom == lhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator!=(rational<T> lhs, Integer rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename Integer>
constexpr auto operator<(rational<T> lhs, Integer rhs)
    -> bool
{
    return lhs.numer < lhs.denom * rhs;
}

template<typename T, typename Integer>
constexpr auto operator>(rational<T> lhs, Integer rhs)
    -> bool
{
    return lhs.numer > lhs.denom * rhs;
}

template<typename T, typename Integer>
constexpr auto operator<=(rational<T> lhs, Integer rhs)
    -> bool
{
    return lhs.numer <= lhs.denom * rhs;
}

template<typename T, typename Integer>
constexpr auto operator>=(rational<T> lhs, Integer rhs)
    -> bool
{
    return lhs.numer >= lhs.denom * rhs;
}

template<typename T, typename Integer>
constexpr auto operator==(Integer lhs, rational<T> rhs)
    -> bool
{
    return lhs * rhs.denom == rhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator!=(Integer lhs, rational<T> rhs)
    -> bool
{
    return !(rhs == lhs);
}

template<typename T, typename Integer>
constexpr auto operator<(Integer lhs, rational<T> rhs)
    -> bool
{
    return lhs * rhs.denom < rhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator>(Integer lhs, rational<T> rhs)
    -> bool
{
    return lhs * rhs.denom > rhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator<=(Integer lhs, rational<T> rhs)
    -> bool
{
    return lhs * rhs.denom <= rhs.numer;
}

template<typename T, typename Integer>
constexpr auto operator>=(Integer lhs, rational<T> rhs)
    -> bool
{
    return lhs * rhs.denom >= rhs.numer;
}

////////////////////////////////////////////////////////////
// Mathematical functions

template<typename T>
constexpr auto sign(rational<T> ratio)
    -> int
{
    return (ratio.numer > 0) ? 1 : (ratio.numer < 0) ? -1 : 0;
}

template<typename T>
constexpr auto abs(rational<T> ratio)
    -> rational<T>
{
    return (ratio >= 0) ? ratio : -ratio;
}

template<typename T>
constexpr auto floor(rational<T> ratio)
    -> decltype(std::floor(T{}))
{
    return smath::floor((long double) ratio);
}

template<typename T>
constexpr auto ceil(rational<T> ratio)
    -> decltype(std::ceil(T{}))
{
    return smath::ceil((long double) ratio);
}

template<typename T>
constexpr auto round(rational<T> ratio)
    -> decltype(std::round(T{}))
{
    return smath::round((long double) ratio);
}

template<typename T>
constexpr auto trunc(rational<T> ratio)
    -> decltype(std::trunc(T{}))
{
    return T((long double) ratio);
}

template<typename T>
constexpr auto reciprocal(rational<T> ratio)
    -> rational<T>
{
    return { ratio.denom, ratio.numer };
}

template<typename T, typename Integer>
constexpr auto pow(rational<T> ratio, Integer exp)
    -> rational<T>
{
    static_assert(std::is_integral<Integer>::value,
                  "pow only accepts integer exponents");

    return (exp == 0) ? rational<T>(1) :
        (exp > 0) ? rational<T>(
                        pow(ratio.numer, exp),
                        pow(ratio.denom, exp)
                    ) :
                    rational<T>(
                        pow(ratio.denom, -exp),
                        pow(ratio.numer, -exp)
                    );
}

inline namespace literals
{
inline namespace rational_literals
{
    ////////////////////////////////////////////////////////////
    // User-defined literals

    constexpr auto operator "" _r(unsigned long long n)
        -> rational<int>
    {
        return { static_cast<int>(n) };
    }

    constexpr auto operator "" _rl(unsigned long long n)
        -> rational<long>
    {
        return { static_cast<long>(n) };
    }

    constexpr auto operator "" _rll(unsigned long long n)
        -> rational<long long>
    {
        return { static_cast<long long>(n) };
    }

    constexpr auto operator "" _ru(unsigned long long n)
        -> rational<unsigned>
    {
        return { static_cast<unsigned>(n) };
    }

    constexpr auto operator "" _rul(unsigned long long n)
        -> rational<unsigned long>
    {
        return { static_cast<unsigned long>(n) };
    }

    constexpr auto operator "" _rull(unsigned long long n)
        -> rational<unsigned long long>
    {
        return { n };
    }
}}
