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

/*
 * Part of this file is the work of theLOLflashlight's GitHub account.
 */

////////////////////////////////////////////////////////////
// Helper functions

namespace detail
{
    // x^n / n!
    template<typename T>
    constexpr auto xn_nfac(T x, int n)
        -> T
    {
        return smath::pow(x, n) / detail::factorial<T>(n);
    }

    template<typename T>
    constexpr auto trig_helper(T x, int n, bool s)
        -> T
    {
        return s ? detail::xn_nfac(x, n) : -detail::xn_nfac(x, n);
    }

    ////////////////////////////////////////////////////////////
    // pow

    template<typename T, typename Unsigned>
    constexpr auto pow_helper(T x, Unsigned exponent)
        -> std::common_type_t<T, Unsigned>
    {
        // Exponentiation by squaring
        return (exponent == 0) ? 1 :
            (exponent % 2 == 0) ? pow_helper(x*x, exponent/2) :
                x * pow_helper(x*x, (exponent-1)/2);
    }

    ////////////////////////////////////////////////////////////
    // sqrt

    template<typename T>
    constexpr auto sqrt_helper(T x, T y)
        -> decltype(std::sqrt(x))
    {
        return detail::is_close(x, y*y) ? y :
            sqrt_helper(x, (y + x/y) / 2);
    }

    ////////////////////////////////////////////////////////////
    // exp

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

    ////////////////////////////////////////////////////////////
    // sin & sinh

    constexpr std::size_t SIN_MAX_DEPTH = 51;
    static_assert(detail::is_odd(SIN_MAX_DEPTH), "");

    template<std::size_t N>
    struct sine
    {
        sine() = delete;

        static_assert(detail::is_odd(N), "N must be odd for sin functions");
        static_assert(N < SIN_MAX_DEPTH, "exceeded maximum recursion depth");

        template<typename T>
        static constexpr auto trig(T x)
            -> T
        {
            return trig_helper(x, N, detail::is_even((N - 1) / 2)) + sine<N + 2>::trig(x);
        }

        template<typename T>
        static constexpr auto hyper(T x)
            -> T
        {
            return xn_nfac(x, N) + sine<N + 2>::hyper(x);
        }
    };

    template<>
    struct sine<SIN_MAX_DEPTH>
    {
        sine() = delete;

        template<typename T>
        static constexpr auto trig(T)
            -> T
        {
            return T();
        }

        template<typename T>
        static constexpr auto hyper(T)
            -> T
        {
            return T();
        }
    };

    template<std::size_t N, typename T>
    constexpr auto sin_helper(T x)
        -> T
    {
        return sine<N>::trig(x);
    }

    template<std::size_t N, typename T>
    constexpr auto sinh_helper(T x)
        -> T
    {
        return sine<N>::hyper(x);
    }

    ////////////////////////////////////////////////////////////
    // cos & cosh

    constexpr std::size_t COS_MAX_DEPTH = 50;
    static_assert(detail::is_even(COS_MAX_DEPTH), "");

    template<std::size_t N>
    struct cosine
    {
        cosine() = delete;

        static_assert(detail::is_even(N), "N must be even for cos functions");
        static_assert(N < COS_MAX_DEPTH, "exceeded maximum recursion depth");

        template<typename T>
        static constexpr auto trig(T x)
            -> T
        {
            return trig_helper(x, N, is_even(N / 2)) + cosine<N + 2>::trig(x);
        }

        template<typename T>
        static constexpr auto hyper(T x)
            -> T
        {
            return xn_nfac(x, N) + cosine<N + 2>::hyper(x);
        }
    };

    template<>
    struct cosine<COS_MAX_DEPTH>
    {
        cosine() = delete;

        template<typename T>
        static constexpr auto trig(T)
            -> T
        {
            return T();
        }

        template<typename T>
        static constexpr auto hyper(T)
            -> T
        {
            return T();
        }
    };

    template<std::size_t N, typename T>
    constexpr auto cos_helper(T x)
        -> T
    {
        return cosine<N>::trig(x);
    }

    template<std::size_t N, typename T>
    constexpr auto cosh_helper(T x)
        -> T
    {
        return cosine<N>::hyper(x);
    }
}

////////////////////////////////////////////////////////////
// Basic functions

template<typename Number>
constexpr auto abs(Number x)
    -> decltype(auto)
{
    return detail::abs(x);
}

template<typename... Args>
constexpr auto min(Args... args)
    -> decltype(auto)
{
    return detail::min(args...);
}

template<typename... Args>
constexpr auto max(Args... args)
    -> decltype(auto)
{
    return detail::max(args...);
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

template<typename Integer, Integer N, Integer M>
constexpr auto pow(constant<Integer, N>, constant<Integer, M>)
    -> constant<Integer, smath::pow(N, M)>
{
    return {};
}

template<typename Float>
constexpr auto sqrt(Float x)
    -> decltype(std::sqrt(x))
{
    return detail::sqrt_helper(x, x);
}

////////////////////////////////////////////////////////////
// Trigonometric functions

template<typename Float>
constexpr auto sin(Float x)
    -> Float
{
    return x + detail::sin_helper<3>(x);
}

template<typename Float>
constexpr auto cos(Float x)
    -> Float
{
    return 1 + detail::cos_helper<2>(x);
}

template<typename Float>
constexpr auto tan(Float x)
    -> Float
{
    return sin(x) / cos(x);
}

////////////////////////////////////////////////////////////
// Hyperbolic functions

template<typename Float>
constexpr auto sinh(Float x)
    -> Float
{
    return x + detail::sinh_helper<3>(x);
}

template<typename Float>
constexpr auto cosh(Float x)
    -> Float
{
    return 1 + detail::cosh_helper<2>(x);
}

template<typename Float>
constexpr auto tanh(Float x)
    -> Float
{
    return sinh(x) / cosh(x);
}
