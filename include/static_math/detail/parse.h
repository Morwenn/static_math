/*
 * Copyright (C) 2015 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more detail.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef SMATH_DETAIL_PARSE_H_
#define SMATH_DETAIL_PARSE_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstdint>
#include "can_fit.h"

namespace smath
{
namespace detail
{
    ////////////////////////////////////////////////////////////
    // Helper functions

    constexpr auto is_decimal_digit(char c)
        -> bool
    {
        return c >= '0' && c <= '9';
    }

    template<typename... Chars>
    constexpr auto is_decimal_digit(char c, Chars... digits)
        -> bool
    {
        return is_decimal_digit(c)
            && is_decimal_digit(digits...);
    }

    constexpr auto combine(std::uintmax_t value)
        -> std::uintmax_t
    {
        return value;
    }

    template<typename... Integers>
    constexpr auto combine(std::uintmax_t value, std::uintmax_t first, Integers... digits)
        -> std::uintmax_t
    {
        return combine(value*10 + first, digits...);
    }

    ////////////////////////////////////////////////////////////
    // Parsing interface

    template<typename T, char C, char... Digits>
    class parse
    {
        static_assert(C != '0' || sizeof...(Digits) == 0,
                      "parse cannot handle octal literals");

        static_assert(is_decimal_digit(C, Digits...),
                      "parse only handles decimal digits");

        private:

            static constexpr std::uintmax_t raw_value =
                combine(0, C-'0', Digits-'0'...);

        public:

            using type = integer_fit_t<T, raw_value>;

            static constexpr type value =
                static_cast<type>(raw_value);
    };

    template<typename T, char... Digits>
    using parse_t = typename parse<T, Digits...>::type;
}}

#endif // SMATH_DETAIL_PARSE_H_
