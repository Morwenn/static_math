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
 * This file is the work of theLOLflashlight's GitHub account.
 */

////////////////////////////////////////////////////////////
// Helper functions

namespace detail
{
    constexpr std::size_t SIN_MAX_DEPTH = 51;
    constexpr std::size_t COS_MAX_DEPTH = 50;

    static_assert(smath::is_odd(SIN_MAX_DEPTH), "");
    static_assert(smath::is_even(COS_MAX_DEPTH), "");

    template<typename T>
    constexpr auto trig_helper(T x, int n, bool s)
        -> T
    {
        return s ? detail::xn_nfac(x, n) : -detail::xn_nfac(x, n);
    }

    ////////////////////////////////////////////////////////////
    // Function helpers

    template<std::size_t N>
    struct sine
    {
        sine() = delete;

        static_assert(smath::is_odd(N), "N must be odd for sin functions");
        static_assert(N < SIN_MAX_DEPTH, "exceeded maximum recursion depth");

        template<typename T>
        static constexpr auto trig(T x)
            -> T
        {
            return trig_helper(x, N, is_even((N - 1) / 2)) + sine<N + 2>::trig(x);
        }

        template<typename T>
        static constexpr auto hyper(T x)
            -> T
        {
            return xn_nfac(x, N) + sine<N + 2>::hyper(x);
        }
    };

    template<std::size_t N>
    struct cosine
    {
        cosine() = delete;

        static_assert(smath::is_even(N), "N must be even for cos functions");
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

    ////////////////////////////////////////////////////////////
    // Trigonometric helpers

    template<std::size_t N, typename T>
    constexpr auto sin_helper(T x)
        -> T
    {
        return sine<N>::trig(x);
    }

    template<std::size_t N, typename T>
    constexpr auto cos_helper(T x)
        -> T
    {
        return cosine<N>::trig(x);
    }

    ////////////////////////////////////////////////////////////
    // Hyperbolic helpers

    template<std::size_t N, typename T>
    constexpr auto sinh_helper(T x)
        -> T
    {
        return sine<N>::hyper(x);
    }

    template<std::size_t N, typename T>
    constexpr auto cosh_helper(T x)
        -> T
    {
        return cosine<N>::hyper(x);
    }
}

////////////////////////////////////////////////////////////
// Other functions

template<typename Float>
constexpr auto exp(Float x)
    -> Float
{
    return 1 + x + detail::exp_helper<2>(x);
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

template<typename Float>
constexpr auto cot(Float x)
    -> Float
{
    return cos(x) / sin(x);
}

template<typename Float>
constexpr auto sec(Float x)
    -> Float
{
    return 1 / cos(x);
}

template<typename Float>
constexpr auto csc(Float x)
    -> Float
{
    return 1 / sin(x);
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

template<typename Float>
constexpr auto coth(Float x)
    -> Float
{
    return cosh(x) / sinh(x);
}

template<typename Float>
constexpr auto sech(Float x)
    -> Float
{
    return 1 / cosh(x);
}

template<typename Float>
constexpr auto csch(Float x)
    -> Float
{
    return 1 / sinh(x);
}


////////////////////////////////////////////////////////////
// Helper function specializations

namespace detail
{
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
}
