/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2016 Morwenn
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
// imaginary<T> functions

template<typename T>
constexpr imaginary<T>::imaginary():
    value(T{})
{}

template<typename T>
constexpr imaginary<T>::imaginary(value_type real):
    value(real)
{}

template<typename T>
template<typename X>
constexpr imaginary<T>::imaginary(imaginary<X> other):
    value(other.value)
{}

template<typename T>
template<typename X>
constexpr auto imaginary<T>::operator+=(imaginary<X> other)
    -> imaginary&
{
    value += other.value;
    return *this;
}

template<typename T>
template<typename X>
constexpr auto imaginary<T>::operator-=(imaginary<X> other)
    -> imaginary&
{
    value -= other.value;
    return *this;
}

template<typename T>
constexpr auto imaginary<T>::operator*=(T real)
    -> imaginary&
{
    value *= real;
    return *this;
}

template<typename T>
constexpr auto imaginary<T>::operator/=(T real)
    -> imaginary&
{
    value /= real;
    return *this;
}

////////////////////////////////////////////////////////////
// complex<T> functions

template<typename T>
constexpr complex<T>::complex():
    real(T{}),
    imag(imaginary<T>{})
{}

template<typename T>
constexpr complex<T>::complex(value_type real, value_type imag):
    real(real),
    imag(imag)
{}

template<typename T>
constexpr complex<T>::complex(value_type real, imaginary<T> imag):
    real(real),
    imag(imag)
{}

template<typename T>
constexpr complex<T>::complex(value_type real):
    real(real)
{}

template<typename T>
constexpr complex<T>::complex(imaginary<T> imag):
    imag(imag)
{}

template<typename T>
template<typename X>
constexpr complex<T>::complex(complex<X> other):
    real(other.real),
    imag(other.imag)
{}

template<typename T>
constexpr auto complex<T>::operator+=(T other)
    -> complex&
{
    real += other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator-=(T other)
    -> complex&
{
    real -= other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator*=(T other)
    -> complex&
{
    real *= other;
    imag *= other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator/=(T other)
    -> complex&
{
    real /= other;
    imag /= other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator+=(imaginary<T> other)
    -> complex&
{
    imag += other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator-=(imaginary<T> other)
    -> complex&
{
    imag -= other;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator*=(imaginary<T> other)
    -> complex&
{
    T temp = imag * other;
    imag = real * other;
    real = temp;
    return *this;
}

template<typename T>
constexpr auto complex<T>::operator/=(imaginary<T> other)
    -> complex&
{
    T temp = imag / other;
    imag = real / other;
    real = temp;
    return *this;
}

template<typename T>
template<typename X>
constexpr auto complex<T>::operator+=(complex<X> other)
    -> complex&
{
    real += other.real;
    imag += other.imag;
    return *this;
}

template<typename T>
template<typename X>
constexpr auto complex<T>::operator-=(complex<X> other)
    -> complex&
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}

template<typename T>
template<typename X>
constexpr auto complex<T>::operator*=(complex<X> other)
    -> complex&
{
    real = real*other.real + imag*other.imag;
    imag = real*other.imag + imag*other.real;
    return *this;
}

template<typename T>
template<typename X>
constexpr auto complex<T>::operator/=(complex<X> other)
    -> complex&
{
    real = (real*other.real - imag*other.imag) / (sqr(other.real) + sqr(other.imag.value));
    imag = (imag*other.real - real*other.imag) / (sqr(other.real) + sqr(other.imag.value));
    return *this;
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
    return imaginary<T>(-imag.value);
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
        -ratio.real,
        -ratio.imag
    };
}

////////////////////////////////////////////////////////////
// Binary arithmetic operators

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return imaginary<std::common_type_t<T, U>>(lhs.value + rhs.value);
}

template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>
{
    return imaginary<std::common_type_t<T, U>>(lhs.value - rhs.value);
}

template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>
{
    return { -lhs.value * rhs.value };
}

template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>
{
    return { lhs.value*rhs.value / sqr(rhs.value) };
}

template<typename T, typename Number, typename>
constexpr auto operator+(imaginary<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return { rhs, lhs };
}

template<typename T, typename Number, typename>
constexpr auto operator-(imaginary<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return { -rhs, lhs };
}

template<typename T, typename Number, typename>
constexpr auto operator*(imaginary<T> lhs, Number rhs)
    -> imaginary<std::common_type_t<T, Number>>
{
    return imaginary<std::common_type_t<T, Number>>(lhs.value * rhs);
}

template<typename T, typename Number, typename>
constexpr auto operator/(imaginary<T> lhs, Number rhs)
    -> imaginary<std::common_type_t<T, Number>>
{
    return imaginary<std::common_type_t<T, Number>>(lhs.value / rhs);
}

template<typename T, typename Number, typename>
constexpr auto operator+(Number lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return { lhs, rhs };
}

template<typename T, typename Number, typename>
constexpr auto operator-(Number lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return { lhs, -rhs };
}

template<typename T, typename Number, typename>
constexpr auto operator*(Number lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, Number>>
{
    return imaginary<std::common_type_t<T, Number>>(lhs * rhs.value);
}

template<typename T, typename Number, typename>
constexpr auto operator/(Number lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, Number>>
{
    return imaginary<std::common_type_t<T, Number>>(lhs / rhs.value);
}

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real + rhs.real,
        lhs.imag + rhs.imag
    };
}

template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real - rhs.real,
        lhs.imag - rhs.imag
    };
}

template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real*rhs.real + lhs.imag*rhs.imag,
        lhs.real*rhs.imag + lhs.imag*rhs.real
    };
}

template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        (lhs.real*rhs.real + lhs.imag.value*rhs.imag.value) / (sqr(rhs.real) + sqr(rhs.imag.value)),
        (lhs.imag.value*rhs.real - lhs.real*rhs.imag.value) / (sqr(rhs.real) + sqr(rhs.imag.value))
    };
}

template<typename T, typename Number, typename>
constexpr auto operator+(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs.real + rhs,
        lhs.imag
    };
}

template<typename T, typename Number, typename>
constexpr auto operator-(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs.real - rhs,
        lhs.imag
    };
}

template<typename T, typename Number, typename>
constexpr auto operator*(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs.real * rhs,
        lhs.imag.value * rhs
    };
}

template<typename T, typename Number, typename>
constexpr auto operator/(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs.real / rhs,
        lhs.imag / rhs
    };
}

template<typename T, typename Number, typename>
constexpr auto operator+(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs + rhs.real,
        rhs.imag
    };
}

template<typename T, typename Number, typename>
constexpr auto operator-(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs - rhs.real,
        -rhs.imag
    };
}
template<typename T, typename Number, typename>
constexpr auto operator*(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs * rhs.real,
        lhs * rhs.imag.value
    };
}

template<typename T, typename Number, typename>
constexpr auto operator/(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>
{
    return {
        lhs * rhs.real / (sqr(rhs.real) + sqr(rhs.imag.value)),
        -lhs * rhs.imag.value / (sqr(rhs.real) + sqr(rhs.imag.value))
    };
}

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real,
        lhs.imag + rhs
    };
}

template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.real,
        lhs.imag - rhs
    };
}

template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.imag * rhs,
        lhs.real * rhs
    };
}

template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.imag.value * rhs.value / sqr(rhs.value),
        -lhs.real * rhs.value / sqr(rhs.value)
    };
}

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        rhs.real,
        rhs.imag + lhs
    };
}

template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        -rhs.real,
        lhs - rhs.imag
    };
}

template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs * rhs.imag,
        lhs * rhs.real
    };
}

template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>
{
    return {
        lhs.value * rhs.imag.value / (sqr(rhs.real) + sqr(rhs.imag.value)),
        lhs.value * rhs.real / (sqr(rhs.real) + sqr(rhs.imag.value))
    };
}

////////////////////////////////////////////////////////////
// Comparison operators

template<typename T, typename U>
constexpr auto operator==(imaginary<T> lhs, imaginary<U> rhs)
    -> bool
{
    return lhs.value == rhs.value;
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
    return lhs.real == rhs.real
        && lhs.imag == rhs.imag;
}

template<typename T, typename U>
constexpr auto operator!=(complex<T> lhs, complex<U> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename Number, typename>
constexpr auto operator==(complex<T> lhs, Number rhs)
    -> bool
{
    return lhs.real == rhs
        && lhs.imag.value == 0;
}

template<typename T, typename Number, typename>
constexpr auto operator!=(complex<T> lhs, Number rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename Number, typename>
constexpr auto operator==(Number lhs, complex<T> rhs)
    -> bool
{
    return rhs.real == lhs
        && rhs.imag_value == 0;
}

template<typename T, typename Number, typename>
constexpr auto operator!=(Number lhs, complex<T> rhs)
    -> bool
{
    return !(lhs == rhs);
}

template<typename T, typename U>
constexpr auto operator==(complex<T> lhs, imaginary<U> rhs)
    -> bool
{
    return lhs.imag == rhs
        && lhs.real == 0;
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
    return rhs.imag == lhs
        && rhs.real == 0;
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
constexpr auto abs(complex<T> z)
    -> T
{
    return smath::hypot(z.real, z.imag.value);
}

template<typename T>
constexpr auto norm(complex<T> z)
    -> T
{
    return smath::sqr(z.real) + smath::sqr(z.imag.value);
}

template<typename T>
constexpr auto norm(T value)
    -> T
{
    return norm(complex<T>(value));
}

template<typename T>
constexpr auto conj(complex<T> z)
    -> complex<T>
{
    return {
        z.real,
        -z.imag
    };
}

template<typename T>
constexpr auto conj(T value)
    -> complex<T>
{
    return conj(complex<T>(value));
}

template<typename T>
constexpr auto polar(T rho, T theta)
    -> complex<T>
{
    return {
        rho * smath::cos(theta),
        rho * smath::sin(theta)
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
        return imaginary<float>(static_cast<float>(n));
    }

    constexpr auto operator"" _i(long double n)
        -> imaginary<double>
    {
        return imaginary<double>(static_cast<double>(n));
    }

    constexpr auto operator"" _il(long double n)
        -> imaginary<long double>
    {
        return imaginary<long double>(n);
    }

    ////////////////////////////////////////////////////////////
    // Integer user-defined literals

    constexpr auto operator"" _i(unsigned long long n)
        -> imaginary<int>
    {
        return imaginary<int>(static_cast<int>(n));
    }

    constexpr auto operator"" _il(unsigned long long n)
        -> imaginary<long>
    {
        return imaginary<long>(static_cast<long>(n));
    }

    constexpr auto operator"" _ill(unsigned long long n)
        -> imaginary<long long>
    {
        return imaginary<long long>(static_cast<long long>(n));
    }

    constexpr auto operator"" _ui(unsigned long long n)
        -> imaginary<unsigned>
    {
        return imaginary<unsigned>(static_cast<unsigned>(n));
    }

    constexpr auto operator"" _uil(unsigned long long n)
        -> imaginary<unsigned long>
    {
        return imaginary<unsigned long>(static_cast<unsigned long>(n));
    }

    constexpr auto operator"" _uill(unsigned long long n)
        -> imaginary<unsigned long long>
    {
        return imaginary<unsigned long long>(n);
    }
}}
