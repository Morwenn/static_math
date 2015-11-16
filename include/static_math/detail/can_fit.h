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
