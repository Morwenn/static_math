```cpp
#include <static_math/formula.h>
```

This header includes mathematical functions that do not belong anywhere else in the library.

### Basic functions

```cpp
template<typename Number>
constexpr auto sign(Number x)
    -> int;
```

[Signum function](https://en.wikipedia.org/wiki/Sign_function). It returns the sign of `x`.

```cpp
template<typename T, typename U>
constexpr auto is_close(T a, U b)
    -> bool;
```

Compares whether two floating point numbers `a` and `b` are close from each other. The formula used is similar to the one used by Python's [`math.isclose`](https://docs.python.org/3/library/math.html#math.isclose) function. For types other than floating point numbers, a regular comparison is performed.

```cpp
template<typename T, typename U, typename... Rest>
constexpr auto sum(T first, U second, Rest... rest)
    -> std::common_type_t<T, U, Rest...>;
```

Computes the sum of a collection of values.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename... Numbers>
constexpr auto mean(Numbers... args)
    -> decltype(sum(args...) / sizeof...(args));
```

Computes the [mean](https://en.wikipedia.org/wiki/Mean) of a collection of values.

```cpp
template<typename Number>
constexpr auto sqr(Number x)
    -> Number;
```

Returns the square of `x`.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Number>
constexpr auto clamp(Number x, Number min, Number max)
    -> Number;
```

Returns the value of `x` [clamped](https://en.wikipedia.org/wiki/Clamping_%28graphics%29) to the range `[min, max]`.

### Integer-related functions

```cpp
template<typename Integer>
constexpr auto is_even(Integer n)
    -> bool;
```

Computes whether the integer `n` is even.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Integer>
constexpr auto is_odd(Integer n)
    -> bool;
```

Computes whether the integer `n` is odd.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Integer>
constexpr auto is_prime(Integer n)
    -> bool;
```

Computes whether the integer `n` is a [prime number](https://en.wikipedia.org/wiki/Prime_number).

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Integer>
constexpr auto fibonacci(Integer n)
    -> Integer;
```

Computes the nth [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number).

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Integer>
constexpr auto factorial(Integer n)
    -> Integer;
```

Computes the [factorial](https://en.wikipedia.org/wiki/Factorial) of `n`.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename T, typename U>
constexpr auto gcd(T a, U b)
    -> std::common_type_t<T, U>;
```

Computes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of `a` and `b`.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename T, typename U>
constexpr auto lcm(T a, U b)
    -> std::common_type_t<T, U>;
```

Computes the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of `a` and `b`.

*This function is overloaded so that it can handle [[integral constants]].*

### Angle conversions

```cpp
template<typename Float>
constexpr auto degrees(Float x)
    -> Float;
```

Converts an angle `x` in radians into an angle in degrees.

```cpp
template<typename Float>
constexpr auto radians(Float x)
    -> Float;
```

Converts an angle `x` in degrees into an angle in radians.
