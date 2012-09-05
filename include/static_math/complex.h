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
#ifndef _SMATH_COMPLEX_H
#define _SMATH_COMPLEX_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <static_math/utils/type_traits.h>


namespace smath
{

    /**
     * @brief Imaginary numbers
     */
    template<typename T>
    class imaginary
    {
        static_assert(std::is_arithmetic<T>::value, "An imaginary number can only contain arithmetic values.");

        public:

            constexpr imaginary(T real);

            constexpr T value() const;

        private:

            T _value;
    };

    /**
     * @brief Complex numbers
     */
    template<typename T>
    class complex
    {
        static_assert(std::is_arithmetic<T>::value, "A complex number can only contain arithmetic values.");

        public:

            constexpr complex(T real, T imag);
            constexpr complex(T real, const imaginary<T>& img);

            constexpr T real() const;
            constexpr const imaginary<T>& imag() const;
            constexpr T imag_value() const;

        private:

            T _real;
            imaginary<T> _imag;
    };

    ////////////////////////////////////////////////////////////
    // Comparison operators
    ////////////////////////////////////////////////////////////

    template<typename T>
    constexpr imaginary<T> operator+(const imaginary<T>& imag);
    template<typename T>
    constexpr imaginary<T> operator-(const imaginary<T>& imag);

    template<typename T>
    constexpr complex<T> operator+(const complex<T>& ratio);
    template<typename T>
    constexpr complex<T> operator-(const complex<T>& ratio);

    template<typename T, typename U>
    constexpr bool operator==(const imaginary<T>& lhs, const imaginary<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator!=(const imaginary<T>& lhs, const imaginary<U>& rhs);

    template<typename T, typename U>
    constexpr bool operator==(const complex<T>& lhs, const complex<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator!=(const complex<T>& lhs, const complex<U>& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
    operator==(const complex<T>& lhs, const U& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
    operator!=(const complex<T>& lhs, const U& rhs);

    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
    operator==(const U& lhs, const complex<T>& rhs);
    template<typename T, typename U>
    constexpr
    typename std::enable_if<std::is_arithmetic<U>::value, bool>::type
    operator!=(const U& lhs, const complex<T>& rhs);

    template<typename T, typename U>
    constexpr bool operator==(const complex<T>& lhs, const imaginary<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator!=(const complex<T>& lhs, const imaginary<U>& rhs);

    template<typename T, typename U>
    constexpr bool operator==(const imaginary<T>& lhs, const complex<U>& rhs);
    template<typename T, typename U>
    constexpr bool operator!=(const imaginary<T>& lhs, const complex<U>& rhs);

    #include <static_math/complex.inl>

} // namespace smath


constexpr smath::imaginary<long double>
operator "" _static_i(long double n)
{
    return smath::imaginary<long double>(n);
}

#endif // _SMATH_COMPLEX_H
