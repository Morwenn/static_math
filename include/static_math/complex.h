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
#ifndef SMATH_COMPLEX_H_
#define SMATH_COMPLEX_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <type_traits>
#include <static_math/cmath.h>
#include <static_math/formula.h>

namespace smath
{
    /**
     * @brief Imaginary numbers
     */
    template<typename T>
    struct imaginary
    {
        static_assert(std::is_arithmetic<T>::value,
                      "an imaginary number can only contain arithmetic values");

        using value_type = T;

        // Constructor
        constexpr imaginary();
        constexpr imaginary(const imaginary& other) = default;

        constexpr explicit imaginary(value_type real);
        template<typename X>
        constexpr explicit imaginary(imaginary<X> other);

        // Operators
        template<typename X>
        constexpr auto operator+=(imaginary<X> other)
            -> imaginary&;
        template<typename X>
        constexpr auto operator-=(imaginary<X> other)
            -> imaginary&;
        constexpr auto operator*=(T real)
            -> imaginary&;
        constexpr auto operator/=(T real)
            -> imaginary&;

        // Member data
        value_type value = T{};
    };

    /**
     * @brief Complex numbers
     */
    template<typename T>
    struct complex
    {
        static_assert(std::is_arithmetic<T>::value,
                      "a complex number can only contain arithmetic values");

        using value_type = T;

        ////////////////////////////////////////////////////////////
        // Constructors

        constexpr complex();
        constexpr complex(const complex& other) = default;

        constexpr complex(value_type real, value_type imag);
        constexpr complex(value_type real, imaginary<T> imag);
        constexpr complex(value_type real);
        constexpr complex(imaginary<T> imag);
        template<typename X>
        constexpr explicit complex(complex<X> other);

        ////////////////////////////////////////////////////////////
        // Augmented assignment operators

        constexpr auto operator+=(T other)
            -> complex&;
        constexpr auto operator-=(T other)
            -> complex&;
        constexpr auto operator*=(T other)
            -> complex&;
        constexpr auto operator/=(T other)
            -> complex&;

        constexpr auto operator+=(imaginary<T> other)
            -> complex&;
        constexpr auto operator-=(imaginary<T> other)
            -> complex&;
        constexpr auto operator*=(imaginary<T> other)
            -> complex&;
        constexpr auto operator/=(imaginary<T> other)
            -> complex&;

        template<typename X>
        constexpr auto operator+=(complex<X> other)
            -> complex&;
        template<typename X>
        constexpr auto operator-=(complex<X> other)
            -> complex&;
        template<typename X>
        constexpr auto operator*=(complex<X> other)
            -> complex&;
        template<typename X>
        constexpr auto operator/=(complex<X> other)
            -> complex&;

        ////////////////////////////////////////////////////////////
        // Member data

        value_type real = T{};
        imaginary<T> imag = imaginary<T>{};
    };

    ////////////////////////////////////////////////////////////
    // Unary arithmetic operators

    template<typename T>
    constexpr auto operator+(imaginary<T> imag)
        -> imaginary<T>;
    template<typename T>
    constexpr auto operator-(imaginary<T> imag)
        -> imaginary<T>;

    template<typename T>
    constexpr auto operator+(complex<T> ratio)
        -> complex<T>;
    template<typename T>
    constexpr auto operator-(complex<T> ratio)
        -> complex<T>;

    ////////////////////////////////////////////////////////////
    // Binary arithmetic operators

    template<typename T, typename U>
    constexpr auto operator+(imaginary<T> lhs, imaginary<U> rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(imaginary<T> lhs, imaginary<U> rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(imaginary<T> lhs, imaginary<U> rhs)
        -> std::common_type_t<T, U>;
    template<typename T, typename U>
    constexpr auto operator/(imaginary<T> lhs, imaginary<U> rhs)
        -> std::common_type_t<T, U>;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator+(imaginary<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator-(imaginary<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator*(imaginary<T> lhs, Number rhs)
        -> imaginary<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator/(imaginary<T> lhs, Number rhs)
        -> imaginary<std::common_type_t<T, Number>>;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator+(Number lhs, imaginary<T> rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator-(Number lhs, imaginary<T> rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator*(Number lhs, imaginary<T> rhs)
        -> imaginary<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator/(Number lhs, imaginary<T> rhs)
        -> imaginary<std::common_type_t<T, Number>>;

    template<typename T, typename U>
    constexpr auto operator+(complex<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(complex<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(complex<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(complex<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator+(complex<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator-(complex<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator*(complex<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator/(complex<T> lhs, Number rhs)
        -> complex<std::common_type_t<T, Number>>;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator+(Number lhs, complex<T> rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator-(Number lhs, complex<T> rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator*(Number lhs, complex<T> rhs)
        -> complex<std::common_type_t<T, Number>>;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator/(Number lhs, complex<T> rhs)
        -> complex<std::common_type_t<T, Number>>;

    template<typename T, typename U>
    constexpr auto operator+(complex<T> lhs, imaginary<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(complex<T> lhs, imaginary<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(complex<T> lhs, imaginary<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(complex<T> lhs, imaginary<U> rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename U>
    constexpr auto operator+(imaginary<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(imaginary<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(imaginary<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(imaginary<T> lhs, complex<U> rhs)
        -> complex<std::common_type_t<T, U>>;

    ////////////////////////////////////////////////////////////
    // Comparison operators

    template<typename T, typename U>
    constexpr auto operator==(imaginary<T> lhs, imaginary<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(imaginary<T> lhs, imaginary<U> rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(complex<T> lhs, complex<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(complex<T> lhs, complex<U> rhs)
        -> bool;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator==(complex<T> lhs, Number rhs)
        -> bool;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator!=(complex<T> lhs, Number rhs)
        -> bool;

    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator==(Number lhs, complex<T> rhs)
        -> bool;
    template<typename T, typename Number,
             typename = std::enable_if_t<std::is_arithmetic<Number>::value>>
    constexpr auto operator!=(Number lhs, complex<T> rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(complex<T> lhs, imaginary<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(complex<T> lhs, imaginary<U> rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(imaginary<T> lhs, complex<U> rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(imaginary<T> lhs, complex<U> rhs)
        -> bool;

    ////////////////////////////////////////////////////////////
    // Mathematical functions

    template<typename T>
    constexpr auto abs(complex<T> z)
        -> T;

    template<typename T>
    constexpr auto norm(complex<T> z)
        -> T;
    template<typename T>
    constexpr auto norm(T value)
        -> T;

    template<typename T>
    constexpr auto conj(complex<T> z)
        -> complex<T>;
    template<typename T>
    constexpr auto conj(T value)
        -> complex<T>;

    template<typename T>
    constexpr auto polar(T rho, T theta)
        -> complex<T>;

    inline namespace literals
    {
    inline namespace complex_literals
    {
        ////////////////////////////////////////////////////////////
        // Float user-defined literals

        constexpr auto operator"" _if(long double n)
            -> imaginary<float>;

        constexpr auto operator"" _i(long double n)
            -> imaginary<double>;

        constexpr auto operator"" _il(long double n)
            -> imaginary<long double>;

        ////////////////////////////////////////////////////////////
        // Integer user-defined literals

        constexpr auto operator"" _i(unsigned long long n)
            -> imaginary<int>;

        constexpr auto operator"" _il(unsigned long long n)
            -> imaginary<long>;

        constexpr auto operator"" _ill(unsigned long long n)
            -> imaginary<long long>;

        constexpr auto operator"" _ui(unsigned long long n)
            -> imaginary<unsigned>;

        constexpr auto operator"" _uil(unsigned long long n)
            -> imaginary<unsigned long>;

        constexpr auto operator"" _uill(unsigned long long n)
            -> imaginary<unsigned long long>;
    }}

    #include "detail/complex.inl"
}

#endif // SMATH_COMPLEX_H_
