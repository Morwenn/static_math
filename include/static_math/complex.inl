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
constexpr imaginary<T>::imaginary(T real):
    _value(real)
{}

template<typename T>
constexpr T imaginary<T>::value() const
{
    return _value;
}

template<typename T>
constexpr complex<T>::complex(T real, T imag):
    _real(real),
    _imag(imaginary<T>(imag))
{}

template<typename T>
constexpr complex<T>::complex(T real, const imaginary<T>& imag):
    _real(real),
    _imag(imag)
{}

template<typename T>
constexpr T complex<T>::real() const
{
    return _real;
}

template<typename T>
constexpr const imaginary<T>& complex<T>::imag() const
{
    return _imag;
}

template<typename T>
constexpr T complex<T>::imag_value() const
{
    return _imag.value();
}

template<typename T>
constexpr imaginary<T> operator+(const imaginary<T>& imag)
{
    return imag;
}

template<typename T>
constexpr imaginary<T> operator-(const imaginary<T>& imag)
{
    return imaginary<T>(-imag.value());
}

template<typename T>
constexpr complex<T> operator+(const complex<T>& ratio)
{
    return ratio;
}

template<typename T>
constexpr complex<T> operator-(const complex<T>& ratio)
{
    return complex<T>(
        -ratio.real(),
        -ratio.imag()
    );
}

template<typename T, typename U>
constexpr bool operator==(const imaginary<T>& lhs, const imaginary<U>& rhs)
{
        return lhs.value() == rhs.value();
}

template<typename T, typename U>
constexpr bool operator!=(const imaginary<T>& lhs, const imaginary<U>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr bool operator==(const complex<T>& lhs, const complex<U>& rhs)
{
    return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
}

template<typename T, typename U>
constexpr bool operator!=(const complex<T>& lhs, const complex<U>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
operator==(const complex<T>& lhs, const U& rhs)
{
    return lhs.real() == rhs && lhs.imag_value() == 0;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
operator!=(const complex<T>& lhs, const U& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
operator==(const U& lhs, const complex<T>& rhs)
{
    return rhs.real() == lhs && rhs.imag_value() == 0;
}

template<typename T, typename U>
constexpr
typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
operator!=(const U& lhs, const complex<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr bool operator==(const complex<T>& lhs, const imaginary<U>& rhs)
{
    return lhs.imag() == rhs && lhs.real() == 0;
}

template<typename T, typename U>
constexpr bool operator!=(const complex<T>& lhs, const imaginary<U>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr bool operator==(const imaginary<T>& lhs, const complex<U>& rhs)
{
    return rhs.imag() == lhs && rhs.real() == 0;
}

template<typename T, typename U>
constexpr bool operator!=(const imaginary<T>& lhs, const complex<U>& rhs)
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr
imaginary<typename std::common_type<T, U>::type>
operator+(const imaginary<T>& lhs, const imaginary<U>& rhs)
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() + rhs.value());
}

template<typename T, typename U>
constexpr
imaginary<typename std::common_type<T, U>::type>
operator-(const imaginary<T>& lhs, const imaginary<U>& rhs)
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() - rhs.value());
}

template<typename T, typename U>
constexpr
typename std::common_type<T, U>::type
operator*(const imaginary<T>& lhs, const imaginary<U>& rhs)
{
    return -lhs.value() * rhs.value();
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const imaginary<T>& lhs, const U& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        rhs,
        lhs
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const imaginary<T>& lhs, const U& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        -rhs,
        lhs
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
imaginary<typename std::common_type<T, U>::type>
operator*(const imaginary<T>& lhs, const U& rhs)
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() * rhs);
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const U& lhs, const imaginary<T>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs,
        rhs
    );
}
template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const U& lhs, const imaginary<T>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs,
        -rhs
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
imaginary<typename std::common_type<T, U>::type>
operator*(const U& lhs, const imaginary<T>& rhs)
{
    return imaginary<typename std::common_type<T, U>::type>(lhs * rhs.value());
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const complex<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() + rhs.real(),
        lhs.imag() + rhs.imag()
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const complex<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() - rhs.real(),
        lhs.imag() - rhs.imag()
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator*(const complex<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real()*rhs.real() + lhs.imag()*rhs.imag(),
        lhs.real()*rhs.imag() + lhs.imag()*rhs.real()
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const complex<T>& lhs, const U& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() + rhs,
        lhs.imag()
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const complex<T>& lhs, const U& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() - rhs,
        lhs.imag()
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator*(const complex<T>& lhs, const U& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() * rhs,
        lhs.imag_value() * rhs
    );
}

template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const U& lhs, const complex<T>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs + rhs.real(),
        rhs.imag()
    );
}
template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const U& lhs, const complex<T>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs - rhs.real(),
        -rhs.imag()
    );
}
template<typename T, typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr
complex<typename std::common_type<T, U>::type>
operator*(const U& lhs, const complex<T>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs * rhs.real(),
        lhs * rhs.imag_value()
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const complex<T>& lhs, const imaginary<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real(),
        lhs.imag() + rhs
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const complex<T>& lhs, const imaginary<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real(),
        lhs.imag() - rhs
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator*(const complex<T>& lhs, const imaginary<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.imag() * rhs,
        lhs.real() * rhs
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator+(const imaginary<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        rhs.real(),
        rhs.imag() + lhs
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator-(const imaginary<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        -rhs.real(),
        lhs - rhs.imag()
    );
}

template<typename T, typename U>
constexpr
complex<typename std::common_type<T, U>::type>
operator*(const imaginary<T>& lhs, const complex<U>& rhs)
{
    return complex<typename std::common_type<T, U>::type>(
        lhs * rhs.imag(),
        lhs * rhs.real()
    );
}

template<typename T>
constexpr T real(const complex<T>& x)
{
    return x.real();
}

template<typename T>
constexpr imaginary<T> imag(const complex<T>& x)
{
    return x.imag();
}

template<typename T>
constexpr complex<T> conj(const complex<T>& x)
{
    return complex<T>(
        x.real(),
        -x.imag()
    );
}
