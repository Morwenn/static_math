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
constexpr rational<T>::rational(T numerator, T denominator):
    _numerator(numerator),
    _denominator(denominator)
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
constexpr bool operator==(const rational<T>& lhs, const rational<T>& rhs)
{
    return lhs.numerator() * rhs.denominator() == lhs.denominator() * rhs.numerator();
}

template<typename T>
constexpr bool operator!=(const rational<T>& lhs, const rational<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T>
constexpr bool operator<(const rational<T>& lhs, const rational<T>& rhs)
{
    return lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator();
}

template<typename T>
constexpr bool operator>(const rational<T>& lhs, const rational<T>& rhs)
{
    return lhs.numerator() * rhs.denominator() > lhs.denominator() * rhs.numerator();
}

template<typename T>
constexpr bool operator<=(const rational<T>& lhs, const rational<T>& rhs)
{
    return lhs.numerator() * rhs.denominator() <= lhs.denominator() * rhs.numerator();
}

template<typename T>
constexpr bool operator>=(const rational<T>& lhs, const rational<T>& rhs)
{
    return lhs.numerator() * rhs.denominator() >= lhs.denominator() * rhs.numerator();
}

template<typename T>
constexpr bool operator==(const rational<T>& lhs, const T& rhs)
{
    return rhs * lhs.denominator() == lhs.numerator();
}

template<typename T>
constexpr bool operator!=(const rational<T>& lhs, const T& rhs)
{
    return !(lhs == rhs);
}

template<typename T>
constexpr bool operator<(const rational<T>& lhs, const T& rhs)
{
    return rhs * lhs.denominator() > lhs.numerator();
}

template<typename T>
constexpr bool operator>(const rational<T>& lhs, const T& rhs)
{
    return rhs * lhs.denominator() < lhs.numerator();
}

template<typename T>
constexpr bool operator<=(const rational<T>& lhs, const T& rhs)
{
    return rhs * lhs.denominator() >= lhs.numerator();
}

template<typename T>
constexpr bool operator>=(const rational<T>& lhs, const T& rhs)
{
    return rhs * lhs.denominator() <= lhs.numerator();
}

template<typename T>
constexpr bool operator==(const T& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() == rhs.numerator();
}

template<typename T>
constexpr bool operator!=(const T& lhs, const rational<T>& rhs)
{
    return !(rhs == lhs);
}

template<typename T>
constexpr bool operator<(const T& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() < rhs.numerator();
}

template<typename T>
constexpr bool operator>(const T& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() > rhs.numerator();
}

template<typename T>
constexpr bool operator<=(const T& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() <= rhs.numerator();
}

template<typename T>
constexpr bool operator>=(const T& lhs, const rational<T>& rhs)
{
    return lhs * rhs.denominator() >= rhs.numerator();
}

template<typename T>
constexpr rational<T> operator+(const rational<T>& lhs, const rational<T>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator-(const rational<T>& lhs, const rational<T>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator*(const rational<T>& lhs, const rational<T>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.numerator(),
        lhs.denominator() * rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator/(const rational<T>& lhs, const rational<T>& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs.denominator(),
        lhs.denominator() * rhs.numerator()
    );
}

template<typename T>
constexpr rational<T> operator+(const rational<T>& lhs, const T& rhs)
{
    return rational<T>(
        lhs.numerator() + rhs * lhs.denominator(),
        lhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator-(const rational<T>& lhs, const T& rhs)
{
    return rational<T>(
        lhs.numerator() - rhs * lhs.denominator(),
        lhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator*(const rational<T>& lhs, const T& rhs)
{
    return rational<T>(
        lhs.numerator() * rhs,
        lhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator/(const rational<T>& lhs, const T& rhs)
{
    return rational<T>(
        lhs.numerator(),
        lhs.denominator() * rhs
    );
}

template<typename T>
constexpr rational<T> operator+(const T& lhs, const rational<T> rhs)
{
    return rational<T>(
        lhs * rhs.denominator() + rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator-(const T& lhs, const rational<T> rhs)
{
    return rational<T>(
        lhs * rhs.denominator() - rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator*(const T& lhs, const rational<T> rhs)
{
    return rational<T>(
        lhs * rhs.numerator(),
        rhs.denominator()
    );
}

template<typename T>
constexpr rational<T> operator/(const T& lhs, const rational<T> rhs)
{
    return rational<T>(
        lhs * rhs.denominator(),
        rhs.numerator()
    );
}
