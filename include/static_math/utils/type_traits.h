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
#ifndef SMATH_UTILS_TYPE_TRAITS_H_
#define SMATH_UTILS_TYPE_TRAITS_H_


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <type_traits>

namespace smath
{

    template<typename T, typename U>
    using greater_of = std::conditional<
        sizeof(T) >= sizeof(U),
        T,
        U
    >;

    template<typename T, typename U>
    using lesser_of = std::conditional<
        sizeof(T) <= sizeof(U),
        T,
        U
    >;

    template<typename...>
    struct is_integral;

    template<typename T>
    struct is_integral<T>:
        public std::is_integral<T>
    {};

    template<typename T, typename U, typename... Args>
    struct is_integral<T, U, Args...>:
        public std::conditional<
            is_integral<T>::value,
            is_integral<U, Args...>,
            std::false_type
        >::type
    {};

} // namespace smath


#endif // SMATH_UTILS_TYPE_TRAITS_H_
