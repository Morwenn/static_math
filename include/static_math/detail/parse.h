/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Morwenn
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
