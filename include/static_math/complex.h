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
#ifndef SMATH_COMPLEX_H_
#define SMATH_COMPLEX_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <type_traits>
#include <static_math/formula.h>

namespace smath
{
    /**
     * @brief Imaginary numbers
     */
    template<typename T>
    class imaginary
    {
        static_assert(std::is_arithmetic<T>::value,
                      "an imaginary number can only contain arithmetic values");

        public:

            using value_type = T;

            // Constructor
            constexpr imaginary(value_type real);

            // Getter
            constexpr auto value() const
                -> value_type;

        private:

            T _value;
    };

    /**
     * @brief Complex numbers
     */
    template<typename T>
    class complex
    {
        static_assert(std::is_arithmetic<T>::value,
                      "A complex number can only contain arithmetic values.");

        public:

            using value_type = T;

            // Constructors
            constexpr complex(value_type real, value_type imag);
            constexpr complex(value_type real, const imaginary<T>& img);

            // Getters
            constexpr auto real() const
                -> value_type;
            constexpr auto imag() const
                -> const imaginary<T>&;
            constexpr auto imag_value() const
                -> value_type;

        private:

            const value_type _real;
            const imaginary<T> _imag;
    };

    ////////////////////////////////////////////////////////////
    // Unary arithmetic operators

    template<typename T>
    constexpr auto operator+(const imaginary<T>& imag)
        -> imaginary<T>;
    template<typename T>
    constexpr auto operator-(const imaginary<T>& imag)
        -> imaginary<T>;

    template<typename T>
    constexpr auto operator+(const complex<T>& ratio)
        -> complex<T>;
    template<typename T>
    constexpr auto operator-(const complex<T>& ratio)
        -> complex<T>;

    ////////////////////////////////////////////////////////////
    // Binary arithmetic operators

    template<typename T, typename U>
    constexpr auto operator+(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> std::common_type_t<T, U>;
    template<typename T, typename U>
    constexpr auto operator/(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> std::common_type_t<T, U>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator+(const imaginary<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator-(const imaginary<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator*(const imaginary<T>& lhs, const U& rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator/(const imaginary<T>& lhs, const U& rhs)
        -> imaginary<std::common_type_t<T, U>>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator+(const U& lhs, const imaginary<T>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator-(const U& lhs, const imaginary<T>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator*(const U& lhs, const imaginary<T>& rhs)
        -> imaginary<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator/(const U& lhs, const imaginary<T>& rhs)
        -> imaginary<std::common_type_t<T, U>>;

    template<typename T, typename U>
    constexpr auto operator+(const complex<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(const complex<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(const complex<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(const complex<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator+(const complex<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator-(const complex<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator*(const complex<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator/(const complex<T>& lhs, const U& rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator+(const U& lhs, const complex<T>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator-(const U& lhs, const complex<T>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator*(const U& lhs, const complex<T>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator/(const U& lhs, const complex<T>& rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename U>
    constexpr auto operator+(const complex<T>& lhs, const imaginary<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(const complex<T>& lhs, const imaginary<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(const complex<T>& lhs, const imaginary<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(const complex<T>& lhs, const imaginary<U>& rhs)
        -> complex<std::common_type_t<T, U>>;

    template<typename T, typename U>
    constexpr auto operator+(const imaginary<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator-(const imaginary<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator*(const imaginary<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;
    template<typename T, typename U>
    constexpr auto operator/(const imaginary<T>& lhs, const complex<U>& rhs)
        -> complex<std::common_type_t<T, U>>;

    ////////////////////////////////////////////////////////////
    // Comparison operators

    template<typename T, typename U>
    constexpr auto operator==(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(const imaginary<T>& lhs, const imaginary<U>& rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(const complex<T>& lhs, const complex<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(const complex<T>& lhs, const complex<U>& rhs)
        -> bool;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator==(const complex<T>& lhs, const U& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator!=(const complex<T>& lhs, const U& rhs)
        -> bool;

    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator==(const U& lhs, const complex<T>& rhs)
        -> bool;
    template<typename T, typename U,
             typename = std::enable_if_t<std::is_arithmetic<U>::value, void>>
    constexpr auto operator!=(const U& lhs, const complex<T>& rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(const complex<T>& lhs, const imaginary<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(const complex<T>& lhs, const imaginary<U>& rhs)
        -> bool;

    template<typename T, typename U>
    constexpr auto operator==(const imaginary<T>& lhs, const complex<U>& rhs)
        -> bool;
    template<typename T, typename U>
    constexpr auto operator!=(const imaginary<T>& lhs, const complex<U>& rhs)
        -> bool;

    ////////////////////////////////////////////////////////////
    // Mathematical functions

    template<typename T>
    constexpr auto real(const complex<T>& x)
        -> T;

    template<typename T>
    constexpr auto imag(const complex<T>& x)
        -> imaginary<T>;

    template<typename T>
    constexpr auto conj(const complex<T>& x)
        -> complex<T>;

    inline namespace literals
    {
    inline namespace complex_literals
    {
        ////////////////////////////////////////////////////////////
        // Float user-defined literals

        constexpr auto operator"" _if(long double n)
            -> smath::imaginary<float>;

        constexpr auto operator"" _i(long double n)
            -> smath::imaginary<double>;

        constexpr auto operator"" _il(long double n)
            -> smath::imaginary<long double>;

        ////////////////////////////////////////////////////////////
        // Integer user-defined literals

        constexpr auto operator"" _i(unsigned long long n)
            -> smath::imaginary<int>;

        constexpr auto operator"" _il(unsigned long long n)
            -> smath::imaginary<long>;

        constexpr auto operator"" _ill(unsigned long long n)
            -> smath::imaginary<long long>;

        constexpr auto operator"" _ui(unsigned long long n)
            -> smath::imaginary<unsigned>;

        constexpr auto operator"" _uil(unsigned long long n)
            -> smath::imaginary<unsigned long>;

        constexpr auto operator"" _uill(unsigned long long n)
            -> smath::imaginary<unsigned long long>;
    }}

    #include <static_math/complex.inl>
}

#endif // SMATH_COMPLEX_H_
