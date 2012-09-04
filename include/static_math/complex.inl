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
