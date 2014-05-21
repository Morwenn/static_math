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

////////////////////////////////////////////////////////////
// Helper functions

namespace details
{
    template<typename T, typename Unsigned>
    constexpr auto pow_helper(T x, Unsigned exponent)
        -> std::common_type_t<T, Unsigned>
    {
        // Exponentiation by squaring
        return (exponent == 0) ? 1 :
            (exponent % 2 == 0) ? pow_helper(x*x, exponent/2) :
                x * pow_helper(x*x, (exponent-1)/2);
    }

    template<typename T>
    constexpr auto sqrt_helper(T x, T y)
        -> decltype(std::sqrt(x))
    {
        return float_equal(x, y*y) ? y :
            sqrt_helper(x, (y + x/y) / 2.0);
    }
}

////////////////////////////////////////////////////////////
// Basic functions

template<typename Number,
         typename = std::enable_if_t<std::is_arithmetic<Number>::value, void>>
constexpr auto abs(Number x)
    -> Number
{
    return (x >= 0) ? x : -x;
}

template<typename T, typename U>
constexpr auto min(T first, U second)
    -> std::common_type_t<T, U>
{
    return (first < second) ? first : second;
}

template<typename T, typename U, typename... Rest>
constexpr auto min(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>
{
    return (first < second) ? min(first, rest...) : min(second, rest...);
}

template<typename T, typename U>
constexpr auto max(T first, U second)
    -> std::common_type_t<T, U>
{
    return (first > second) ? first : second;
}

template<typename T, typename U, typename... Rest>
constexpr auto max(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>
{
    return (first > second) ? max(first, rest...) : max(second, rest...);
}

////////////////////////////////////////////////////////////
// Number-theoretic and representation functions

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto floor(Float x)
    -> decltype(std::floor(x))
{
    return (int(x) == x) ? int(x) :
        (x >= 0.0) ? int(x) :
            int(x) - 1;
}

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto ceil(Float x)
    -> decltype(std::ceil(x))
{
    return (int(x) == x) ? int(x) :
        (x >= 0.0) ? int(x) + 1 :
            int(x);
}

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto round(Float x)
    -> decltype(std::round(x))
{
    return (x >= 0.0) ? int(x + 0.5) : int(x - 0.5);
}

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto trunc(Float x)
    -> decltype(std::trunc(x))
{
    return int(x);
}

////////////////////////////////////////////////////////////
// Power and logarithmic functions

template<typename Number, typename Integer,
         typename = std::enable_if_t<std::is_integral<Integer>::value
                          && std::is_arithmetic<Number>::value, void>>
constexpr auto pow(Number x, Integer exponent)
    -> std::common_type_t<Number, Integer>
{
    return (exponent == 0) ? 1 :
        (exponent > 0) ? details::pow_helper(x, exponent) :
            1 / details::pow_helper(x, -exponent);
}

template<typename Float,
         typename = std::enable_if_t<std::is_floating_point<Float>::value, void>>
constexpr auto sqrt(Float x)
    -> decltype(std::sqrt(x))
{
    return details::sqrt_helper(x, x);
}
