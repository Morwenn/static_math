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

////////////////////////////////////////////////////////////
// Helper functions

namespace details
{
    template<typename T, typename U>
    constexpr auto pow_helper(T acc, T value, U times)
        -> T
    {
        return (times > 1) ?
            pow_helper(acc*value, value, times-1) :
                acc;
    }

    template<typename T>
    constexpr auto sqrt_helper(T x, T y)
        -> T
    {
        return equals(x, y*y) ? y :
            sqrt_helper(x, (y + x/y) / 2.0);
    }
}

////////////////////////////////////////////////////////////
// Basic functions

template<typename T>
constexpr auto abs(T x)
    -> typename std::enable_if<std::is_arithmetic<T>::value, T>::type
{
    return (x >= 0) ? x : -x;
}

template<typename T, typename U>
constexpr auto min(T first, U second)
    -> typename std::common_type<T, U>::type
{
    return (first < second) ? first : second;
}

template<typename T, typename U, typename... Rest>
constexpr auto min(T first, U second, Rest... rest)
    -> typename std::common_type<T, U, Rest...>::type
{
    return (first < second) ? min(first, rest...) : min(second, rest...);
}

template<typename T, typename U>
constexpr auto max(T first, U second)
    -> typename std::common_type<T, U>::type
{
    return (first > second) ? first : second;
}

template<typename T, typename U, typename... Rest>
constexpr auto max(T first, U second, Rest... rest)
    -> typename std::common_type<T, U, Rest...>::type
{
    return (first > second) ? max(first, rest...) : max(second, rest...);
}

////////////////////////////////////////////////////////////
// Number-theoretic and representation functions

template<typename Float>
constexpr auto floor(Float value)
    -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type
{
    return (int(value) == value) ? int(value) :
        (value >= 0.0) ? int(value) :
            int(value) - 1;
}

template<typename Float>
constexpr auto ceil(Float value)
    -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type
{
    return (int(value) == value) ? int(value) :
        (value >= 0.0) ? int(value) + 1 :
            int(value);
}

template<typename Float>
constexpr auto round(Float value)
    -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type
{
    return (value >= 0.0) ? int(value + 0.5) : int(value - 0.5);
}

template<typename Float>
constexpr auto trunc(Float value)
    -> typename std::enable_if<std::is_floating_point<Float>::value, int>::type
{
    return int(value);
}

////////////////////////////////////////////////////////////
// Power and logarithmic functions

template<typename T, typename U>
constexpr auto pow(T value, U exponent)
    -> typename std::enable_if<std::is_integral<U>::value
                               && std::is_arithmetic<T>::value, T>::type
{
    return (exponent == 0) ? 1 :
        (exponent > 0) ? details::pow_helper(value, value, exponent) :
            1 / details::pow_helper(value, value, exponent);
}

template<typename Float>
constexpr auto sqrt(Float x)
    -> typename std::enable_if<std::is_floating_point<Float>::value, Float>::type
{
    return details::sqrt_helper(x, x);
}
