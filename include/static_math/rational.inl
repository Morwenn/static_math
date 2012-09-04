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

template<typename T>
constexpr rational<T>::rational(T numerator):
    _numerator(numerator),
    _denominator(1)
{}

template<typename T>
constexpr rational<T>::rational(T numerator, T denominator):
    _numerator(
        denominator < 0 ? (
            numerator < 0 ?
                abs(numerator) / gcd(abs(numerator), abs(denominator)) :
            numerator > 0 ?
                - (numerator / gcd(numerator, abs(denominator))) :
            0
        ):
            numerator < 0 ?
                - abs(numerator) / gcd(abs(numerator), denominator) :
            numerator > 0 ?
                numerator / gcd(numerator, denominator) :
            0
    ),
    _denominator(
        numerator != 0 ?
            abs(denominator) / gcd(abs(numerator), abs(denominator))
        : 1
    )
{}

template<typename T>
constexpr T rational<T>::numerator() const
{
    return _numerator;
}

template<typename T>
constexpr T rational<T>::denominator() const
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

template<typename T>
constexpr rational<T> operator+(const rational<T>& lhs)
{
    return lhs;
}

template<typename T>
constexpr rational<T> operator-(const rational<T>& lhs)
{
    return rational<T>(
        -lhs.numerator(),
        lhs.denominator()
    );
}

template<typename T, typename U>
constexpr bool operator==(const rational<T>& lhs, const rational<U>& rhs)
{
    return lhs.numerator() * rhs.denominator() == lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr bool operator!=(const rational<T>& lhs, const rational<U>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr bool operator<(const rational<T>& lhs, const rational<U>& rhs)
{
    return lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr bool operator>(const rational<T>& lhs, const rational<U>& rhs)
{
    return lhs.numerator() * rhs.denominator() > lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr bool operator<=(const rational<T>& lhs, const rational<U>& rhs)
{
    return lhs.numerator() * rhs.denominator() <= lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr bool operator>=(const rational<T>& lhs, const rational<U>& rhs)
{
    return lhs.numerator() * rhs.denominator() >= lhs.denominator() * rhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator==(const rational<T>& lhs, const U& rhs)
{
    return rhs * lhs.denominator() == lhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator!=(const rational<T>& lhs, const U& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator<(const rational<T>& lhs, const U& rhs)
{
    return lhs.numerator() < lhs.denominator() * rhs;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator>(const rational<T>& lhs, const U& rhs)
{
    return lhs.numerator() > lhs.denominator() * rhs;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator<=(const rational<T>& lhs, const U& rhs)
{
    return lhs.numerator() <= lhs.denominator() * rhs;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator>=(const rational<T>& lhs, const U& rhs)
{
    return lhs.numerator() >= lhs.denominator() * rhs;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator==(const U& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() == rhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator!=(const U& lhs, const rational<T>& rhs)
{
    return !(rhs == lhs);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator<(const U& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() < rhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator>(const U& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() > rhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator<=(const U& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() <= rhs.numerator();
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, bool>::type
operator>=(const U& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() >= rhs.numerator();
}

template<typename T, typename U>
constexpr
rational<typename greater_of<T, U>::type>
operator+(const rational<T>& lhs, const rational<U>& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
rational<typename greater_of<T, U>::type>
operator-(const rational<T>& lhs, const rational<U>& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
rational<typename greater_of<T, U>::type>
operator*(const rational<T>& lhs, const rational<U>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
rational<typename greater_of<T, U>::type>
operator/(const rational<T>& lhs, const rational<U>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.denominator(),
        lhs.denominator() * rhs.numerator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator+(const rational<T>& lhs, const U& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator() + rhs * lhs.denominator(),
        lhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator-(const rational<T>& lhs, const U& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator() - rhs * lhs.denominator(),
        lhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator*(const rational<T>& lhs, const U& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator() * rhs,
        lhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator/(const rational<T>& lhs, const U& rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs.numerator(),
        lhs.denominator() * rhs
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator+(const U& lhs, const rational<T> rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs * rhs.denominator() + rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator-(const U& lhs, const rational<T> rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs * rhs.denominator() - rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator*(const U& lhs, const rational<T> rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs * rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_integral<U>::value, rational<typename greater_of<T, U>::type>>::type
operator/(const U& lhs, const rational<T> rhs)
{
    return rational<typename greater_of<T, U>::type>(
        lhs * rhs.denominator(),
        rhs.numerator()
    );
}

template<typename T>
constexpr int sign(const rational<T>& ratio)
{
    return (ratio.numerator() > 0) ? 1 : (ratio.numerator() < 0) ? -1 : 0;
}

template<typename T>
constexpr rational<T> abs(const rational<T>& ratio)
{
    return (ratio >= 0) ? ratio : -ratio;
}

template<typename T>
constexpr T floor(const rational<T>& ratio)
{
    return floor((long double) ratio);
}

template<typename T>
constexpr T ceil(const rational<T>& ratio)
{
    return ceil((long double) ratio);
}

template<typename T>
constexpr T round(const rational<T>& ratio)
{
    return round((long double) ratio);
}

template<typename T>
constexpr T trunc(const rational<T>& ratio)
{
    return T((long double) ratio);
}

template<typename T>
constexpr rational<T> reciprocal(const rational<T>& ratio)
{
    return rational<T>(
        ratio.denominator(),
        ratio.numerator()
    );
}

template<typename T, typename Integral>
constexpr
typename std::enable_if<std::is_integral<Integral>::value, rational<T>>::type
pow(const rational<T>& ratio, Integral exp)
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
