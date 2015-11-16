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
// Trigonometric functions

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
