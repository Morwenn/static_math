/*
 * Copyright (C) 2013-2015 Morwenn
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

namespace detail
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
        return detail::is_close(x, y*y) ? y :
            sqrt_helper(x, (y + x/y) / 2);
    }

    // x^n / n!
    template<typename T>
    constexpr auto xn_nfac(T x, int n)
        -> T
    {
        return smath::pow(x, n) / detail::factorial<T>(n);
    }

    constexpr std::size_t EXP_MAX_DEPTH = 50;

    template<std::size_t N>
    struct exponential
    {
        exponential() = delete;

        static_assert(N < EXP_MAX_DEPTH, "exceeded maximum recursion depth");

        template<typename T>
        static constexpr auto compute(T x)
            -> T
        {
            return xn_nfac(x, N) + exponential<N + 1>::compute(x);
        }
    };

    template<>
    struct exponential<EXP_MAX_DEPTH>
    {
        exponential() = delete;

        template<typename T>
        static constexpr auto compute(T)
            -> T
        {
            return T();
        }
    };

    template<std::size_t N, typename T>
    constexpr auto exp_helper(T x)
        -> T
    {
        return exponential<N>::compute(x);
    }
}

////////////////////////////////////////////////////////////
// Basic functions

template<typename Number>
constexpr auto abs(Number x)
    -> Number
{
    return detail::abs(x);
}

template<typename T, typename U, typename... Rest>
constexpr auto min(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>
{
    return detail::min(first, second, rest...);
}

template<typename T, typename U, typename... Rest>
constexpr auto max(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>
{
    return detail::max(first, second, rest...);
}

////////////////////////////////////////////////////////////
// Number-theoretic and representation functions

template<typename Float>
constexpr auto floor(Float x)
    -> decltype(std::floor(x))
{
    return (int(x) == x) ? int(x) :
        (x >= 0.0) ? int(x) :
            int(x) - 1;
}

template<typename Float>
constexpr auto ceil(Float x)
    -> decltype(std::ceil(x))
{
    return (int(x) == x) ? int(x) :
        (x >= 0.0) ? int(x) + 1 :
            int(x);
}

template<typename Float>
constexpr auto round(Float x)
    -> decltype(std::round(x))
{
    return (x >= 0.0) ? int(x + 0.5) : int(x - 0.5);
}

template<typename Float>
constexpr auto trunc(Float x)
    -> decltype(std::trunc(x))
{
    return int(x);
}

////////////////////////////////////////////////////////////
// Power and logarithmic functions

template<typename Float>
constexpr auto exp(Float x)
    -> decltype(std::exp(x))
{
    return 1 + x + detail::exp_helper<2>(x);
}

template<typename Number, typename Integer>
constexpr auto pow(Number x, Integer exponent)
    -> std::common_type_t<Number, Integer>
{
    static_assert(std::is_integral<Integer>::value,
                  "pow only accepts integer exponents");

    return (exponent == 0) ? 1 :
        (exponent > 0) ? detail::pow_helper(x, exponent) :
            1 / detail::pow_helper(x, -exponent);
}

template<typename Float>
constexpr auto sqrt(Float x)
    -> decltype(std::sqrt(x))
{
    return detail::sqrt_helper(x, x);
}
