```cpp
#include <static_math/cmath.h>
```

All the functions in this header more or less correspond to their equivalents in the standard library header `<cmath>`, reworked as `constexpr` functions. Some of the functions are less powerful than the standard library ones (`smath::pow` only works with integral exponents) while other functions are more powerful (most functions are templated, `hypot` is variadic...).

### Basic functions

```cpp
template<typename Number>
constexpr auto abs(Number x)
    -> Number;
```

Computes the [absolute value](https://en.wikipedia.org/wiki/Absolute_value) of a given number. Unlike the corresponding standard library function, this function also accepts unsigned integer values and returns them unchanged.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Number>
constexpr auto div(Number x, Number y)
    -> smath::div_t<Number>;
```

Computes both the quotient and the remainder of the division of the numerator `x` by the denominator `y`. The return type `smath::div_t` contains two members variables `quot` and `rem` which denote the quotient and the remainder. If `Number` is either `int`, `long int` or `long long int`, the corresponding `smath::div_t` wil respectively inherit from `std::div_t`, `std::ldiv_t` or `std::lldiv_t` to make conversion from existing code easier. If `std::intmax_t` is different from `long long int`, then `smath::div_t<std::intmax_t>` will inherit from `std::imaxdiv_t`.

```cpp
template<typename T, typename U, typename... Rest>
constexpr auto min(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>;
```

Returns the smallest value among a given number of values.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename T, typename U, typename... Rest>
constexpr auto max(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>;
```

Returns the greatest value among a given number of values.

*This function is overloaded so that it can handle [[integral constants]].*

### Number-theoretic and representation functions

```cpp
template<typename Float>
constexpr auto floor(Float x)
    -> decltype(std::floor(x));
```

Computes the largest integer value not greater than `x`.

```cpp
template<typename Float>
constexpr auto ceil(Float x)
    -> decltype(std::ceil(x));
```

Computes the smallest integer value not less than `x`.

```cpp
template<typename Float>
constexpr auto round(Float x)
    -> decltype(std::round(x));
```

Computes the nearest integer value to `x` (in floating-point format), rounding halfway cases away from zero, regardless of the current rounding mode.

For usability reasons, the functions `lround` and `llround` are also available, providing the same type conversions than their standard library equivalents.

```cpp
template<typename Float>
constexpr auto trunc(Float x)
    -> decltype(std::trunc(x));
```

Computes the nearest integer not greater in magnitude than `x`.

### Power and logarithmic functions

```cpp
template<typename Float>
constexpr auto exp(Float x)
    -> decltype(std::exp(x));
```

Computes the [exponential](https://en.wikipedia.org/wiki/Exponential_function) of `x`.

```cpp
template<typename Number, typename Integer>
constexpr auto pow(Number x, Integer exponent)
    -> std::common_type_t<Number, Integer>;
```

Computes the value of `x` raised to the power `exponent`. Note however that this function only accepts integer exponents.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Float>
constexpr auto log(Float x)
    -> decltype(std::log(x));
```

Computes the the [natural logarithm](https://en.wikipedia.org/wiki/Natural_logarithm) (base *e*) of `x`.

```cpp
template<typename Float>
constexpr auto log2(Float x)
    -> decltype(std::log2(x));
```

Computes the the [binary logarithm](https://en.wikipedia.org/wiki/Binary_logarithm) (base 2) of `x`.

```cpp
template<typename Float>
constexpr auto log10(Float x)
    -> decltype(std::log10(x));
```

Computes the the [common logarithm](https://en.wikipedia.org/wiki/Common_logarithm) (base 10) of `x`.

```cpp
template<typename Float>
constexpr auto sqrt(Float x)
    -> decltype(std::sqrt(x));
```

Computes the [square root](https://en.wikipedia.org/wiki/Square_root) of `x`, using the [Babylonian method](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method). This function recurses until the best possible precision for a given floating point type is found.

```cpp
template<typename... Args>
constexpr auto hypot(Args... args)
    -> decltype(auto);
```

Computes the square root of the sum of the squares of `args...`, without undue overflow or underflow at intermediate stages of the computation. The passed parameters are converted to the appropriate floating point type prior to the computation; the return type is the type common to these converted types. 

### Trigonometric functions

```cpp
template<typename Float>
constexpr auto sin(Float x)
    -> Float;
```

Computes the sine of `x` (measured in radians).

```cpp
template<typename Float>
constexpr auto cos(Float x)
    -> Float;
```

Computes the cosine of `x` (measured in radians).

```cpp
template<typename Float>
constexpr auto tan(Float x)
    -> Float;
```

Computes the tangent of `x` (measured in radians).

### Hyperbolic functions

```cpp
template<typename Float>
constexpr auto sinh(Float x)
    -> Float;
```

Computes hyperbolic the sine of `x` (measured in radians).

```cpp
template<typename Float>
constexpr auto cosh(Float x)
    -> Float;
```

Computes the hyperbolic cosine of `x` (measured in radians).

```cpp
template<typename Float>
constexpr auto tanh(Float x)
    -> Float;
```

Computes the hyperbolic tangent of `x` (measured in radians).
