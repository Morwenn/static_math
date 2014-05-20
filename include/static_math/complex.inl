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
// imaginary<T> functions

template<typename T>
constexpr imaginary<T>::imaginary(T real):
    _value(real)
{}

template<typename T>
constexpr T imaginary<T>::value() const
{
    return _value;
}

////////////////////////////////////////////////////////////
// complex<T> functions

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
constexpr auto complex<T>::real() const
    -> value_type
{
    return _real;
}

template<typename T>
constexpr auto complex<T>::imag() const
    -> const imaginary<T>&
{
    return _imag;
}

template<typename T>
constexpr auto complex<T>::imag_value() const
    -> value_type
{
    return _imag.value();
}

////////////////////////////////////////////////////////////
// Unary arithmetic operators

template<typename T>
constexpr auto operator+(const imaginary<T>& imag)
    -> imaginary<T>
{
    return imag;
}

template<typename T>
constexpr auto operator-(const imaginary<T>& imag)
    -> imaginary<T>
{
    return imaginary<T>(-imag.value());
}

template<typename T>
constexpr auto operator+(const complex<T>& ratio)
    -> complex<T>
{
    return ratio;
}

template<typename T>
constexpr auto operator-(const complex<T>& ratio)
    -> complex<T>
{
    return complex<T>(
        -ratio.real(),
        -ratio.imag()
    );
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename T, typename U>
constexpr auto operator+(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() + rhs.value());
}

template<typename T, typename U>
constexpr auto operator-(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() - rhs.value());
}

template<typename T, typename U>
constexpr auto operator*(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> typename std::common_type<T, U>::type
{
    return -lhs.value() * rhs.value();
}

template<typename T, typename U>
constexpr auto operator/(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> typename std::common_type<T, U>::type
{
    return lhs.value()*rhs.value() / sqr(rhs.value());
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator+(const imaginary<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        rhs,
        lhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator-(const imaginary<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        -rhs,
        lhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator*(const imaginary<T>& lhs, const U& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() * rhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator/(const imaginary<T>& lhs, const U& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs.value() / rhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator+(const U& lhs, const imaginary<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs,
        rhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator-(const U& lhs, const imaginary<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs,
        -rhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator*(const U& lhs, const imaginary<T>& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs * rhs.value());
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator/(const U& lhs, const imaginary<T>& rhs)
    -> imaginary<typename std::common_type<T, U>::type>
{
    return imaginary<typename std::common_type<T, U>::type>(lhs / rhs.value());
}

template<typename T, typename U>
constexpr auto operator+(const complex<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() + rhs.real(),
        lhs.imag() + rhs.imag()
    );
}

template<typename T, typename U>
constexpr auto operator-(const complex<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() - rhs.real(),
        lhs.imag() - rhs.imag()
    );
}

template<typename T, typename U>
constexpr auto operator*(const complex<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real()*rhs.real() + lhs.imag()*rhs.imag(),
        lhs.real()*rhs.imag() + lhs.imag()*rhs.real()
    );
}

template<typename T, typename U>
constexpr auto operator/(const complex<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        (lhs.real()*rhs.real() + lhs.imag_value()*rhs.imag_value()) / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        (lhs.imag_value()*rhs.real() - lhs.real()*rhs.imag_value()) / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator+(const complex<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() + rhs,
        lhs.imag()
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator-(const complex<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() - rhs,
        lhs.imag()
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator*(const complex<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() * rhs,
        lhs.imag_value() * rhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator/(const complex<T>& lhs, const U& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real() / rhs,
        lhs.imag() / rhs
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator+(const U& lhs, const complex<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs + rhs.real(),
        rhs.imag()
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator-(const U& lhs, const complex<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs - rhs.real(),
        -rhs.imag()
    );
}
template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator*(const U& lhs, const complex<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs * rhs.real(),
        lhs * rhs.imag_value()
    );
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator/(const U& lhs, const complex<T>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs * rhs.real() / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        -lhs * rhs.imag_value() / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    );
}

template<typename T, typename U>
constexpr auto operator+(const complex<T>& lhs, const imaginary<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real(),
        lhs.imag() + rhs
    );
}

template<typename T, typename U>
constexpr auto operator-(const complex<T>& lhs, const imaginary<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.real(),
        lhs.imag() - rhs
    );
}

template<typename T, typename U>
constexpr auto operator*(const complex<T>& lhs, const imaginary<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.imag() * rhs,
        lhs.real() * rhs
    );
}

template<typename T, typename U>
constexpr auto operator/(const complex<T>& lhs, const imaginary<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.imag_value() * rhs.value() / sqr(rhs.value()),
        -lhs.real() * rhs.value() / sqr(rhs.value())
    );
}

template<typename T, typename U>
constexpr auto operator+(const imaginary<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        rhs.real(),
        rhs.imag() + lhs
    );
}

template<typename T, typename U>
constexpr auto operator-(const imaginary<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        -rhs.real(),
        lhs - rhs.imag()
    );
}

template<typename T, typename U>
constexpr auto operator*(const imaginary<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs * rhs.imag(),
        lhs * rhs.real()
    );
}

template<typename T, typename U>
constexpr auto operator/(const imaginary<T>& lhs, const complex<U>& rhs)
    -> complex<typename std::common_type<T, U>::type>
{
    return complex<typename std::common_type<T, U>::type>(
        lhs.value() * rhs.imag_value() / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        lhs.value() * rhs.real() / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    );
}

////////////////////////////////////////////////////////////
// Comparison operators

template<typename T, typename U>
constexpr auto operator==(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> bool
{
        return lhs.value() == rhs.value();
}

template<typename T, typename U>
constexpr auto operator!=(const imaginary<T>& lhs, const imaginary<U>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(const complex<T>& lhs, const complex<U>& rhs)
    -> bool
{
    return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
}

template<typename T, typename U>
constexpr auto operator!=(const complex<T>& lhs, const complex<U>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator==(const complex<T>& lhs, const U& rhs)
    -> bool
{
    return lhs.real() == rhs && lhs.imag_value() == 0;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator!=(const complex<T>& lhs, const U& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator==(const U& lhs, const complex<T>& rhs)
    -> bool
{
    return rhs.real() == lhs && rhs.imag_value() == 0;
}

template<typename T, typename U,
         typename = typename std::enable_if<std::is_arithmetic<U>::value, void>::type>
constexpr auto operator!=(const U& lhs, const complex<T>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(const complex<T>& lhs, const imaginary<U>& rhs)
    -> bool
{
    return lhs.imag() == rhs && lhs.real() == 0;
}

template<typename T, typename U>
constexpr auto operator!=(const complex<T>& lhs, const imaginary<U>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(const imaginary<T>& lhs, const complex<U>& rhs)
    -> bool
{
    return rhs.imag() == lhs && rhs.real() == 0;
}

template<typename T, typename U>
constexpr auto operator!=(const imaginary<T>& lhs, const complex<U>& rhs)
    -> bool
{
    return !(lhs == rhs);
}

////////////////////////////////////////////////////////////
// Mathematical functions

template<typename T>
constexpr auto real(const complex<T>& x)
    -> T
{
    return x.real();
}

template<typename T>
constexpr auto imag(const complex<T>& x)
    -> imaginary<T>
{
    return x.imag();
}

template<typename T>
constexpr auto conj(const complex<T>& x)
    -> complex<T>
{
    return complex<T>(
        x.real(),
        -x.imag()
    );
}
