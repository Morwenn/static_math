/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Morwenn
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
    // hypot (contributed by Orson Peters)

    template<typename T>
    constexpr auto hypot_impl_var(T s, T t)
        -> T
    {
        return t * smath::sqrt(s);
    }

    template<typename T, typename... Args>
    constexpr auto hypot_impl_var(T s, T t, T x, Args... args)
        -> T
    {
        return t < x  ? hypot_impl_var(T(1) + s * ((t/x)*(t/x)), x, args...) :
               t != 0 ? hypot_impl_var(s + (x/t)*(x/t), t, args...) :
                        hypot_impl_var(s, t, args...);
    }

    template<typename T>
    constexpr auto hypot_impl(T x, T y)
        -> T
    {
        return x < y  ? y * smath::sqrt(T(1) + (x/y)*(x/y)) :
               x != 0 ? x * smath::sqrt(T(1) + (y/x)*(y/x)) :
                        0;
    }

    template<typename T, typename... Args>
    constexpr auto hypot_impl(T x, T y, Args... args)
        -> T
    {
        return x < y  ? hypot_impl_var(T(1) + (x/y)*(x/y), y, args...) :
               x != 0 ? hypot_impl_var(T(1) + (y/x)*(y/x), x, args...) :
                        hypot_impl_var(T(1), T(0), args...);
    }

    template<typename... Args>
    using common_ftype_t = typename std::common_type_t<
        decltype(std::fabs(std::declval<Args>()))...
    >;

    template<typename... Args>
    constexpr auto hypot_helper(Args... args)
        -> common_ftype_t<Args...>
    {
        return hypot_impl(smath::abs(common_ftype_t<Args...>(args))...);
    }

    ////////////////////////////////////////////////////////////
    // exp (contributed by theLOLflashlight)

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
            const T term = xn_nfac(x, N);

            if (term <= std::numeric_limits<T>::epsilon())
            {
                return term;
            }
            else 
            {
                return term + exponential<N + 1>::compute(x);
            }
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
    // logarithm (contributed by Nava2)
    
    constexpr std::size_t LOG_MAX_DEPTH = 150;

    constexpr const auto NAT_LOG_10 = 2.302585092994045684017991454;
    constexpr const auto NAT_LOG_2 =  0.693147180559945309417232121;

    template<size_t base = 2>
    struct ilogarithm
    {
        ilogarithm() = delete;
        
        template <typename Type>
        static constexpr auto compute(Type x)
            -> decltype(std::log(x))
        {
            const auto EPSILON = std::numeric_limits<Type>::epsilon() * x;

            const Type x_div = x/base;
            return (x_div > EPSILON 
                        ? 1 + ilogarithm<base>::compute(x_div) 
                        : 0);
        }
    };

    // We specialize the integer version, it's much simpler
    template <size_t base, typename Integer,
              typename = std::enable_if_t<std::numeric_limits<Integer>::is_integer>>
    static constexpr auto logi_helper(Integer N)
        -> decltype(std::log(N))
    {
        if (N < 0)
        {
            return std::numeric_limits<Integer>::quiet_NaN();
        }
        else if (N == 0)
        {
            return -1.0 * std::numeric_limits<Integer>::infinity();
        }
        else if (N < base)
        {
            return 0;
        }
        else 
        {
            return ilogarithm<base>::compute(N);
        }
    }

    template<size_t N>
    struct logarithm_lte2
    {        
        logarithm_lte2() = delete;
        
        template <typename Type>
        static constexpr auto compute(Type x)
            -> decltype(std::log(x))
        {
            // Use ln x = \sigma (-1)^(N+1)/ N * (x - 1)^(N)
            const Type term = (pow_helper(-1.0, N + 1) / N) * pow_helper(x - 1.0, N);

            return term + logarithm_lte2<N + 1>::compute(x);
        }
    };
    
    template <>
    struct logarithm_lte2<LOG_MAX_DEPTH>
    {
        logarithm_lte2() = delete;

        template <typename Type>
        static constexpr auto compute(Type x)
        -> decltype(std::log(x))
        {
            return Type(0.0);
        }
    };

    template<typename Type>
    static constexpr 
    void get_fast_converge_params(Type* const A, size_t* const n, Type x)
    {
        const size_t _x = trunc(x);
        const size_t _n = logi_helper<10>(_x);
        *n = _n;
        *A = x / pow_helper(10, _n);
    }

    template <size_t N>
    struct fast_converge_log
    {
        fast_converge_log() = delete;

        template <typename Type>
        static constexpr Type compute(Type x)
        {
            Type A(0);
            size_t n(0);

            get_fast_converge_params(&A, &n, x);

            const Type y = (A - 1.0)/(A + 1.0);

            return n * NAT_LOG_10 + 2.0 * fast_converge_log<0>::S(y);
        }

        template <typename Type>
        static constexpr Type S(Type y)
        {
            const auto EPSILON = std::numeric_limits<Type>::epsilon() * y;

            const auto NNP1 = 2 * N + 1;
            const auto term = (pow_helper(y, NNP1) / NNP1);

            return term + fast_converge_log<N+1>::S(y);
        }
    };
    
    template <>
    struct fast_converge_log<LOG_MAX_DEPTH>
    {
        fast_converge_log() = delete;

        template <typename Type>
        static constexpr Type S(Type y)
        {
            return Type(0);
        }
    };
    
    template <typename Type,
              typename = std::enable_if_t<std::is_floating_point<Type>::value>>
    static constexpr auto logf_helper(Type x)
        -> decltype(std::log(x))
    {
        if (x < 0.0)
        {
            return std::numeric_limits<Type>::quiet_NaN();
        }
        else if (is_close(x, 0.0))
        {
            return -1.0 * std::numeric_limits<Type>::infinity();
        }
        else if (x < 2.0)
        {
            return logarithm_lte2<1>::compute(x);
        }
        else
        {
            return fast_converge_log<0>::compute(x);
        }
    }

    template <typename Type>
    constexpr auto log10_helper(std::enable_if_t<!std::is_floating_point<Type>::value, Type> x) -> decltype(std::log10(x))
    {
        return detail::logi_helper<10>(x);
    }

    template <typename Type>
    constexpr auto log10_helper(std::enable_if_t<std::is_floating_point<Type>::value, Type> x) -> decltype(std::log10(x))
    {
        return detail::logf_helper(x) / NAT_LOG_10;
    }

    template <typename Type>
    constexpr auto log2_helper(std::enable_if_t<!std::is_floating_point<Type>::value, Type> x) -> decltype(std::log2(x))
    {
        return detail::logi_helper<2>(x);
    }

    template <typename Type>
    constexpr auto log2_helper(std::enable_if_t<std::is_floating_point<Type>::value, Type> x) -> decltype(std::log2(x))
    {
        return detail::logf_helper(x) / NAT_LOG_2;
    }
    ////////////////////////////////////////////////////////////
    // sin & sinh (contributed by theLOLflashlight)

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
    // cos & cosh (contributed by theLOLflashlight)

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

template<typename... Args>
constexpr auto hypot(Args... args)
    -> decltype(auto)
{
    return detail::hypot_helper(args...);
}

template <typename Type>
constexpr auto log(Type x) -> decltype(std::log(x))
{
    return detail::logf_helper(x);
}

template <typename Type>
constexpr auto log2(Type x) -> decltype(std::log2(x))
{
    return detail::log2_helper<Type>(x);
}

template <typename Type>
constexpr auto log10(Type x) -> decltype(std::log10(x))
{
    return detail::log10_helper<Type>(x);
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
