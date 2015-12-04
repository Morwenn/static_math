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

/*
 * This file is the work of theLOLflashlight's GitHub account.
 */

////////////////////////////////////////////////////////////
// Trigonometric functions

template<typename Float>
constexpr auto cot(Float x)
    -> Float
{
    return smath::cos(x) / smath::sin(x);
}

template<typename Float>
constexpr auto sec(Float x)
    -> Float
{
    return 1 / smath::cos(x);
}

template<typename Float>
constexpr auto csc(Float x)
    -> Float
{
    return 1 / smath::sin(x);
}

////////////////////////////////////////////////////////////
// Hyperbolic functions

template<typename Float>
constexpr auto coth(Float x)
    -> Float
{
    return smath::cosh(x) / smath::sinh(x);
}

template<typename Float>
constexpr auto sech(Float x)
    -> Float
{
    return 1 / smath::cosh(x);
}

template<typename Float>
constexpr auto csch(Float x)
    -> Float
{
    return 1 / smath::sinh(x);
}
