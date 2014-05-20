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
// Construction

template<typename T>
constexpr rational<T>::rational(T numerator):
    _numerator(numerator),
    _denominator(1)
{}

template<typename T>
constexpr rational<T>::rational(T numerator, T denominator):
    _numerator(
        numerator != 0 ?
            sign(numerator) * sign(denominator) * abs(numerator)
                / gcd(abs(numerator), abs(denominator))
        : 0
    ),
    _denominator(
        numerator != 0 ?
            abs(denominator) / gcd(abs(numerator), abs(denominator))
        : 1
    )
{}

////////////////////////////////////////////////////////////
// Accessors

template<typename T>
constexpr auto rational<T>::numerator() const
    -> value_type
{
    return _numerator;
}

template<typename T>
constexpr auto rational<T>::denominator() const
    -> value_type
{
    return _denominator;
}

template<typename T>
constexpr rational<T>::operator long double() const
{
    return (long double) _numerator / (long double) _denominator;
}

template<typename T>
constexpr rational<T>::operator bool() const
{
    return _numerator == 0;
}

////////////////////////////////////////////////////////////
// Unary arithmetic operators

template<typename T>
constexpr auto operator+(const rational<T>& lhs)
    -> rational<T>
{
    return lhs;
}

template<typename T>
constexpr auto operator-(const rational<T>& lhs)
    -> rational<T>
{
    return {
        -lhs.numerator(),
        lhs.denominator()
    };
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename T, typename U>
constexpr auto operator+(const rational<T>& lhs, const rational<U>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    };
}

template<typename T, typename U>
constexpr auto operator-(const rational<T>& lhs, const rational<U>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    };
}

template<typename T, typename U>
constexpr auto operator*(const rational<T>& lhs, const rational<U>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator()
    };
}

template<typename T, typename U>
constexpr auto operator/(const rational<T>& lhs, const rational<U>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() * rhs.denominator(),
        lhs.denominator() * rhs.numerator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator+(const rational<T>& lhs, const U& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() + rhs * lhs.denominator(),
        lhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator-(const rational<T>& lhs, const U& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() - rhs * lhs.denominator(),
        lhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator*(const rational<T>& lhs, const U& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator() * rhs,
        lhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator/(const rational<T>& lhs, const U& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs.numerator(),
        lhs.denominator() * rhs
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator+(const U& lhs, const rational<T>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs * rhs.denominator() + rhs.numerator(),
        rhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator-(const U& lhs, const rational<T>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs * rhs.denominator() - rhs.numerator(),
        rhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator*(const U& lhs, const rational<T>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs * rhs.numerator(),
        rhs.denominator()
    };
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator/(const U& lhs, const rational<T>& rhs)
    -> rational<typename std::common_type<T, U>::type>
{
    return {
        lhs * rhs.denominator(),
        rhs.numerator()
    };
}

////////////////////////////////////////////////////////////
// Relational operators

template<typename T, typename U>
constexpr auto operator==(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return lhs.numerator() == rhs.numerator()
        && lhs.denominator() == rhs.denominator();
}

template<typename T, typename U>
constexpr auto operator!=(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator<(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr auto operator>(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return lhs.numerator() * rhs.denominator() > lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr auto operator<=(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return lhs.numerator() * rhs.denominator() <= lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr auto operator>=(const rational<T>& lhs, const rational<U>& rhs)
    -> bool
{
    return lhs.numerator() * rhs.denominator() >= lhs.denominator() * rhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator==(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return rhs * lhs.denominator() == lhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator!=(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator<(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return lhs.numerator() < lhs.denominator() * rhs;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator>(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return lhs.numerator() > lhs.denominator() * rhs;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator<=(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return lhs.numerator() <= lhs.denominator() * rhs;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator>=(const rational<T>& lhs, const U& rhs)
    -> bool
{
    return lhs.numerator() >= lhs.denominator() * rhs;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator==(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return lhs * rhs.denominator() == rhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator!=(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return !(rhs == lhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator<(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return lhs * rhs.denominator() < rhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator>(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return lhs * rhs.denominator() > rhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator<=(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return lhs * rhs.denominator() <= rhs.numerator();
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_integral<U>::value, void>::type>
constexpr auto operator>=(const U& lhs, const rational<T>& rhs)
    -> bool
{
    return lhs * rhs.denominator() >= rhs.numerator();
}

////////////////////////////////////////////////////////////
// Mathematical functions

template<typename T>
constexpr auto sign(const rational<T>& ratio)
    -> int
{
    return (ratio.numerator() > 0) ? 1 : (ratio.numerator() < 0) ? -1 : 0;
}

template<typename T>
constexpr auto abs(const rational<T>& ratio)
    -> rational<T>
{
    return (ratio >= 0) ? ratio : -ratio;
}

template<typename T>
constexpr auto floor(const rational<T>& ratio)
    -> T
{
    return floor((long double) ratio);
}

template<typename T>
constexpr auto ceil(const rational<T>& ratio)
    -> T
{
    return ceil((long double) ratio);
}

template<typename T>
constexpr auto round(const rational<T>& ratio)
    -> T
{
    return round((long double) ratio);
}

template<typename T>
constexpr auto trunc(const rational<T>& ratio)
    -> T
{
    return T((long double) ratio);
}

template<typename T>
constexpr auto reciprocal(const rational<T>& ratio)
    -> rational<T>
{
    return {
        ratio.denominator(),
        ratio.numerator()
    };
}

template<typename T, typename Integral,
         typename = typename std::enable_if<std::is_integral<Integral>::value, void>::type>
constexpr auto pow(const rational<T>& ratio, Integral exp)
    -> rational<T>
{
    return (exp == 0) ? rational<T>(1) :
        (exp > 0) ? rational<T>(
                        pow(ratio.numerator(), exp),
                        pow(ratio.denominator(), exp)
                    ) :
                    rational<T>(
                        pow(ratio.denominator(), -exp),
                        pow(ratio.numerator(), -exp)
                    );
}
