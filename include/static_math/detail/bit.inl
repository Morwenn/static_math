/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Morwenn
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

template<typename Unsigned>
constexpr auto ispow2(Unsigned x) noexcept
    -> bool
{
    return (x != 0) && !(x & (x - 1));
}

#ifndef STATIC_MATH_NO_INTEGRAL_CONSTANT
template<typename Unsigned, Unsigned N>
constexpr auto ispow2(constant<Unsigned, N>) noexcept
    -> bool_constant<ispow2(N)>
{
    return {};
}
#endif

template<typename Unsigned>
constexpr auto ceil2(Unsigned x) noexcept
    -> Unsigned
{
    if (x == 0) {
        return 1;
    }

    constexpr auto bound = std::numeric_limits<Unsigned>::digits / 2u;
    --x;
    for (std::size_t i = 1 ; i <= bound ; i <<= 1) {
        x |= (x >> i);
    }
    return x + 1u;
}

#ifndef STATIC_MATH_NO_INTEGRAL_CONSTANT
template<typename Unsigned, Unsigned N>
constexpr auto ceil2(constant<Unsigned, N>) noexcept
    -> constant<Unsigned, ceil2(N)>
{
    return {};
}
#endif

template<typename Unsigned>
constexpr auto floor2(Unsigned x) noexcept
    -> Unsigned
{
    constexpr auto bound = std::numeric_limits<Unsigned>::digits / 2u;
    for (std::size_t i = 1 ; i <= bound ; i <<= 1) {
        x |= (x >> i);
    }
    return x & ~(x >> 1);
}

#ifndef STATIC_MATH_NO_INTEGRAL_CONSTANT
template<typename Unsigned, Unsigned N>
constexpr auto floor2(constant<Unsigned, N>) noexcept
    -> constant<Unsigned, floor2(N)>
{
    return {};
}
#endif

template<typename Unsigned>
constexpr auto log2p1(Unsigned x) noexcept
    -> Unsigned
{
    if (x == 0) {
        return 0;
    }

    Unsigned log = 1;
    while (x >>= 1) {
        ++log;
    }
    return log;
}

#ifndef STATIC_MATH_NO_INTEGRAL_CONSTANT
template<typename Unsigned, Unsigned N>
constexpr auto log2p1(constant<Unsigned, N>) noexcept
    -> constant<Unsigned, log2p1(N)>
{
    return {};
}
#endif
