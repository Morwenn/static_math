/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014-2015 Morwenn
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
#include <static_math/vector.h>

int main()
{
    using namespace smath;

    // TEST: basics
    // - construction
    // - accessors
    // - capacity
    {
        constexpr vector<int, 1> v0 { 5 };
        constexpr vector<int, 3> v1 = { 1, 2, 3 };

        static_assert(v0[0] == 5, "");
        static_assert(v0.at(0) == 5, "");
        static_assert(v0.front() == 5, "");
        static_assert(v0.back() == 5, "");
        static_assert(v1[2] == 3, "");
        static_assert(v1.at(1) == 2, "");
        static_assert(v1.front() == 1, "");
        static_assert(v1.back() == 3, "");

        static_assert(not v0.empty(), "");
        static_assert(v0.size() == 1, "");
        static_assert(v0.max_size() == 1, "");
        static_assert(not v1.empty(), "");
        static_assert(v1.size() == 3, "");
        static_assert(v1.max_size() == v1.size(), "");
    }

    // TEST: addition and subtraction
    {
        constexpr vector<int, 2> v0 = { 1, 2 };
        constexpr vector<int, 2> v1 = { 3, 8 };

        constexpr auto res0 = v0 + v1;
        static_assert(res0[0] == 4, "");
        static_assert(res0[1] == 10, "");

        constexpr auto res1 = v1 - v0;
        static_assert(res1[0] == 2, "");
        static_assert(res1[1] == 6, "");
    }
}
