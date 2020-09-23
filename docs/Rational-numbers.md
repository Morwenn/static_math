```cpp
#include <static_math/rational.h>
```

This header implements [rational numbers](https://en.wikipedia.org/wiki/Rational_number) through the `rational` class template. It supports basic rational-rational and rational-integer arithmetics and common rational functions. A rational instance has two public member data: `numer` and `denom`, corresponding to the numerator and the denominator; `numer` holds the sign information. A rational number is always automatically simplified after an operation has been performed.

```cpp
template<typename Integer>
struct rational;
```

### Construction functions

```cpp
constexpr rational(value_type numerator);
```

Constructs a rational number with `numerator` and 1 as the denominator.

```cpp
constexpr rational(value_type numerator, value_type denominator);
```

Constructs a rational number with `numerator` and `denominator` and 1 as the denominator.

### Conversion functions

```cpp
constexpr explicit operator float() const;
constexpr explicit operator double() const;
constexpr explicit operator long double() const;
```

Converts the rational number to a floating point number `numerator / denominator`.

```cpp
constexpr explicit operator bool() const;
```

Returns `false` when `numerator == 0` and `true` otherwise.

### Arithmetic operations

```cpp
template<typename T>
constexpr auto operator+(rational<T> lhs)
    -> rational<T>;
template<typename T>
constexpr auto operator-(rational<T> lhs)
    -> rational<T>;

template<typename T, typename U>
constexpr auto operator+(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator-(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator*(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator/(rational<T> lhs, rational<U> rhs)
    -> rational<std::common_type_t<T, U>>;

template<typename T, typename Integer>
constexpr auto operator+(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator-(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator*(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator/(rational<T> lhs, Integer rhs)
    -> rational<std::common_type_t<T, Integer>>;

template<typename T, typename Integer>
constexpr auto operator+(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator-(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator*(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>;
template<typename T, typename Integer>
constexpr auto operator/(Integer lhs, rational<T> rhs)
    -> rational<std::common_type_t<T, Integer>>;
```

### Relational operations

```cpp
template<typename T, typename U>
constexpr auto operator==(rational<T> lhs, rational<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator!=(rational<T> lhs, rational<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator<(rational<T> lhs, rational<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator>(rational<T> lhs, rational<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator<=(rational<T> lhs, rational<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator>=(rational<T> lhs, rational<U> rhs)
    -> bool;

template<typename T, typename Integer>
constexpr auto operator==(rational<T> lhs, Integer rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator!=(rational<T> lhs, Integer rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator<(rational<T> lhs, Integer rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator>(rational<T> lhs, Integer rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator<=(rational<T> lhs, Integer rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator>=(rational<T> lhs, Integer rhs)
    -> bool;

template<typename T, typename Integer>
constexpr auto operator==(Integer lhs, rational<T> rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator!=(Integer lhs, rational<T> rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator<(Integer lhs, rational<T> rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator>(Integer lhs, rational<T> rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator<=(Integer lhs, rational<T> rhs)
    -> bool;
template<typename T, typename Integer>
constexpr auto operator>=(Integer lhs, rational<T> rhs)
    -> bool;
```

### Mathematical functions

```cpp
template<typename T>
constexpr auto sign(rational<T> ratio)
    -> int;
```

Computes the sign of `ratio`.

```cpp
template<typename T>
constexpr auto abs(rational<T> ratio)
    -> rational<T>;
```

Computes the absolute value of `ratio`.

```cpp
template<typename T>
constexpr auto floor(rational<T> ratio)
    -> decltype(std::floor(T{}));
```

Computes the largest integer value not greater than `ratio`.

```cpp
template<typename T>
constexpr auto ceil(rational<T> ratio)
    -> decltype(std::ceil(T{}));
```

Computes the smallest integer value not greater than `ratio`.

```cpp
template<typename T>
constexpr auto round(rational<T> ratio)
    -> decltype(std::round(T{}));
```

Computes the nearest integer value to `ratio` (converted to floating-point format), rounding halfway cases away from zero, regardless of the current rounding mode.

```cpp
template<typename T>
constexpr auto trunc(rational<T> ratio)
    -> decltype(std::trunc(T{}));
```

Computes the nearest integer not greater in magnitude than `ratio`.

```cpp
template<typename T>
constexpr auto reciprocal(rational<T> ratio)
    -> rational<T>;
```

Computes the [multiplicative inverse](https://en.wikipedia.org/wiki/Multiplicative_inverse) of `ratio`.

```cpp
template<typename T, typename Integer>
constexpr auto pow(rational<T> ratio, Integer exponent)
    -> rational<T>;
```

Computes `ratio` to the power `exponent` where `exponent` is an integral type.

### User-defined literals

`static_math` provides user-defined literals for the class template `rational` when templated over standard integral types. To make them as usable as possible, they are defined in the inline namespace `rational_literals` in the inline namespace `smath::literals`.

```cpp
constexpr auto operator "" _r(unsigned long long n)
    -> rational<int>;

constexpr auto operator "" _rl(unsigned long long n)
    -> rational<long>;

constexpr auto operator "" _rll(unsigned long long n)
    -> rational<long long>;

constexpr auto operator "" _ru(unsigned long long n)
    -> rational<unsigned>;

constexpr auto operator "" _rul(unsigned long long n)
    -> rational<unsigned long>;

constexpr auto operator "" _rull(unsigned long long n)
    -> rational<unsigned long long>;
```