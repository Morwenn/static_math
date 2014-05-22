/*
 * Copyright (C) 2013-2014 Morwenn
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
constexpr imaginary<T>::imaginary(value_type real):
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
constexpr complex<T>::complex(value_type real, value_type imag):
    _real(real),
    _imag(imaginary<T>(imag))
{}

template<typename T>
constexpr complex<T>::complex(value_type real, imaginary<T> imag):
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
    -> imaginary<T>
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
constexpr auto operator+(imaginary<T> imag)
    -> imaginary<T>
{
    return imag;
}

template<typename T>
constexpr auto operator-(imaginary<T> imag)
    -> imaginary<T>
{
    return { -imag.value() };
}

template<typename T>
constexpr auto operator+(complex<T> ratio)
    -> complex<T>
{
    return ratio;
}

template<typename T>
constexpr auto operator-(complex<T> ratio)
    -> complex<T>
{
    return {
        -ratio.real(),
        -ratio.imag()
    };
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs.value() + rhs.value() };
}

template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs.value() - rhs.value() };
}

template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>
{
    return -lhs.value() * rhs.value();
}

template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>
{
    return lhs.value()*rhs.value() / sqr(rhs.value());
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator+(imaginary<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        rhs,
        lhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator-(imaginary<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        -rhs,
        lhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator*(imaginary<T> lhs, U rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs.value() * rhs };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator/(imaginary<T> lhs, U rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs.value() / rhs };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator+(U lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs,
        rhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator-(U lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs,
        -rhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator*(U lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs * rhs.value() };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator/(U lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return { lhs / rhs.value() };
}

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() + rhs.real(),
        lhs.imag() + rhs.imag()
    };
}

template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() - rhs.real(),
        lhs.imag() - rhs.imag()
    };
}

template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real()*rhs.real() + lhs.imag()*rhs.imag(),
        lhs.real()*rhs.imag() + lhs.imag()*rhs.real()
    };
}

template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        (lhs.real()*rhs.real() + lhs.imag_value()*rhs.imag_value()) / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        (lhs.imag_value()*rhs.real() - lhs.real()*rhs.imag_value()) / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator+(complex<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() + rhs,
        lhs.imag()
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator-(complex<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() - rhs,
        lhs.imag()
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator*(complex<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() * rhs,
        lhs.imag_value() * rhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator/(complex<T> lhs, U rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real() / rhs,
        lhs.imag() / rhs
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator+(U lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs + rhs.real(),
        rhs.imag()
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator-(U lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs - rhs.real(),
        -rhs.imag()
    };
}
template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator*(U lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs * rhs.real(),
        lhs * rhs.imag_value()
    };
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator/(U lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs * rhs.real() / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        -lhs * rhs.imag_value() / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    };
}

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real(),
        lhs.imag() + rhs
    };
}

template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real(),
        lhs.imag() - rhs
    };
}

template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.imag() * rhs,
        lhs.real() * rhs
    };
}

template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.imag_value() * rhs.value() / sqr(rhs.value()),
        -lhs.real() * rhs.value() / sqr(rhs.value())
    };
}

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        rhs.real(),
        rhs.imag() + lhs
    };
}

template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        -rhs.real(),
        lhs - rhs.imag()
    };
}

template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs * rhs.imag(),
        lhs * rhs.real()
    };
}

template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.value() * rhs.imag_value() / (sqr(rhs.real()) + sqr(rhs.imag_value())),
        lhs.value() * rhs.real() / (sqr(rhs.real()) + sqr(rhs.imag_value()))
    };
}

////////////////////////////////////////////////////////////
// Comparison operators

template<typename T, typename U>
constexpr auto operator==(imaginary<T> lhs, imaginary<U> rhs)
    -> bool
{
        return lhs.value() == rhs.value();
}

template<typename T, typename U>
constexpr auto operator!=(imaginary<T> lhs, imaginary<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(complex<T> lhs, complex<U> rhs)
    -> bool
{
    return lhs.real() == rhs.real()
        && lhs.imag() == rhs.imag();
}

template<typename T, typename U>
constexpr auto operator!=(complex<T> lhs, complex<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator==(complex<T> lhs, U rhs)
    -> bool
{
    return lhs.real() == rhs
        && lhs.imag_value() == 0;
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator!=(complex<T> lhs, U rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator==(U lhs, complex<T> rhs)
    -> bool
{
    return rhs.real() == lhs
        && rhs.imag_value() == 0;
}

template<typename T, typename U,
         typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
constexpr auto operator!=(U lhs, complex<T> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(complex<T> lhs, imaginary<U> rhs)
    -> bool
{
    return lhs.imag() == rhs
        && lhs.real() == 0;
}

template<typename T, typename U>
constexpr auto operator!=(complex<T> lhs, imaginary<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(imaginary<T> lhs, complex<U> rhs)
    -> bool
{
    return rhs.imag() == lhs
        && rhs.real() == 0;
}

template<typename T, typename U>
constexpr auto operator!=(imaginary<T> lhs, complex<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

////////////////////////////////////////////////////////////
// Mathematical functions

template<typename T>
constexpr auto real(complex<T> x)
    -> T
{
    return x.real();
}

template<typename T>
constexpr auto imag(complex<T> x)
    -> imaginary<T>
{
    return x.imag();
}

template<typename T>
constexpr auto conj(complex<T> x)
    -> complex<T>
{
    return {
        x.real(),
        -x.imag()
    };
}

inline namespace literals
{
inline namespace complex_literals
{
    ////////////////////////////////////////////////////////////
    // Float user-defined literals

    constexpr auto operator"" _if(long double n)
        -> imaginary<float>
    {
        return { static_cast<float>(n) };
    }

    constexpr auto operator"" _i(long double n)
        -> imaginary<double>
    {
        return { static_cast<double>(n) };
    }

    constexpr auto operator"" _il(long double n)
        -> imaginary<long double>
    {
        return { n };
    }

    ////////////////////////////////////////////////////////////
    // Integer user-defined literals

    constexpr auto operator"" _i(unsigned long long n)
        -> imaginary<int>
    {
        return { static_cast<int>(n) };
    }

    constexpr auto operator"" _il(unsigned long long n)
        -> imaginary<long>
    {
        return { static_cast<long>(n) };
    }

    constexpr auto operator"" _ill(unsigned long long n)
        -> imaginary<long long>
    {
        return { static_cast<long long>(n) };
    }

    constexpr auto operator"" _ui(unsigned long long n)
        -> imaginary<unsigned>
    {
        return { static_cast<unsigned>(n) };
    }

    constexpr auto operator"" _uil(unsigned long long n)
        -> imaginary<unsigned long>
    {
        return { static_cast<unsigned long>(n) };
    }

    constexpr auto operator"" _uill(unsigned long long n)
        -> imaginary<unsigned long long>
    {
        return { n };
    }
}}
