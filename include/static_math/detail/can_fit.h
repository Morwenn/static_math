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
#ifndef SMATH_DETAIL_CAN_FIT_H_
#define SMATH_DETAIL_CAN_FIT_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cstdint>
#include <limits>
#include <type_traits>

namespace smath
{
namespace detail
{
    ////////////////////////////////////////////////////////////
    // Integer literals trait
    //
    // These functions are meant to help the parsing
    // of integer literals.

    /**
     * @brief Unsigned integer fit.
     *
     * This functions checks whether a given integer
     * value can fit in a given type of integer.
     */
    template<typename Integer>
    constexpr auto can_fit(std::uintmax_t n)
        -> bool
    {
        return n <= std::numeric_limits<Integer>::max();
    }

    /**
     * @brief Suitable integer type selection.
     *
     * This class will select the smallest type at least
     * as big as the given one where the given unsigned
     * long long value can fit.
     */
    template<typename T, unsigned long long N>
    struct integer_fit;

    template<typename T, unsigned long long N>
    using integer_fit_t = typename integer_fit<T, N>::type;

    template<unsigned long long N>
    struct integer_fit<int, N>
    {
        using type = std::conditional_t<
            can_fit<int>(N),
            int,
            integer_fit_t<long, N>
        >;
    };

    template<unsigned long long N>
    struct integer_fit<long, N>
    {
        using type = std::conditional_t<
            can_fit<long>(N),
            long,
            long long
        >;
    };

    template<unsigned long long N>
    struct integer_fit<long long, N>
    {
        using type = long long;
    };

    template<unsigned long long N>
    struct integer_fit<unsigned, N>
    {
        using type = std::conditional_t<
            can_fit<unsigned>(N),
            unsigned,
            integer_fit_t<unsigned long long, N>
        >;
    };

    template<unsigned long long N>
    struct integer_fit<unsigned long, N>
    {
        using type = std::conditional_t<
            can_fit<unsigned long>(N),
            unsigned long,
            unsigned long long
        >;
    };

    template<unsigned long long N>
    struct integer_fit<unsigned long long, N>
    {
        using type = unsigned long long;
    };
}}

#endif // SMATH_DETAIL_CAN_FIT_H_
