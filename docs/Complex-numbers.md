```cpp
#include <static_math/complex.h>
```

This header implements [complex numbers](https://en.wikipedia.org/wiki/Complex_number) through the class templates `complex` and `imaginary`. `imaginary` is a mere wrapper around a value of another arithmetic type (public member data `value`) while `complex` is a simple structure wrapping a value of an arithmetic type and a value of the equivalent `imaginary` type (public member data `real` and `imag` to match the standard library names). It should offer a bit stronger typing than `std::complex`.

```cpp
template<typename T>
struct imaginary
{
    using value_type = T;

    // Constructors
    constexpr imaginary() = default;
    constexpr imaginary(const imaginary& other) = default;

    constexpr explicit imaginary(value_type real);
    template<typename X>
    constexpr explicit imaginary(imaginary<X> other);

    // Operators
    template<typename X>
    constexpr auto operator+=(imaginary<X> other)
        -> imaginary&;
    template<typename X>
    constexpr auto operator-=(imaginary<X> other)
        -> imaginary&;
    constexpr auto operator*=(T real)
        -> imaginary&;
    constexpr auto operator/=(T real)
        -> imaginary&;

    // Member data
    value_type value = T{};
};


template<typename T>
struct complex
{
    using value_type = T;

    // Constructors
    constexpr complex() = default;
    constexpr complex(const complex& other) = default;
    constexpr complex(value_type real, value_type imag);
    constexpr complex(value_type real, imaginary<T> imag);
    constexpr complex(value_type real);
    constexpr complex(imaginary<T> imag);
    template<typename X>
    constexpr explicit complex(complex<X> other);

    // Augmented assignment operators
    constexpr auto operator+=(T other)
        -> complex&;
    constexpr auto operator-=(T other)
        -> complex&;
    constexpr auto operator*=(T other)
        -> complex&;
    constexpr auto operator/=(T other)
        -> complex&;

    constexpr auto operator+=(imaginary<T> other)
        -> complex&;
    constexpr auto operator-=(imaginary<T> other)
        -> complex&;
    constexpr auto operator*=(imaginary<T> other)
        -> complex&;
    constexpr auto operator/=(imaginary<T> other)
        -> complex&;

    template<typename X>
    constexpr auto operator+=(complex<X> other)
        -> complex&;
    template<typename X>
    constexpr auto operator-=(complex<X> other)
        -> complex&;
    template<typename X>
    constexpr auto operator*=(complex<X> other)
        -> complex&;
    template<typename X>
    constexpr auto operator/=(complex<X> other)
        -> complex&;

    // Member data
    value_type real = T{};
    imaginary<T> imag = imaginary<T>{};
};

```

### Arithmetic operators

```cpp
template<typename T>
constexpr auto operator+(imaginary<T> imag)
    -> imaginary<T>;
template<typename T>
constexpr auto operator-(imaginary<T> imag)
    -> imaginary<T>;

template<typename T>
constexpr auto operator+(complex<T> ratio)
    -> complex<T>;
template<typename T>
constexpr auto operator-(complex<T> ratio)
    -> complex<T>;

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, imaginary<U> rhs)
    -> imaginary<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>;
template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, imaginary<U> rhs)
    -> std::common_type_t<T, U>;

template<typename T, typename Number>
constexpr auto operator+(imaginary<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator-(imaginary<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator*(imaginary<T> lhs, Number rhs)
    -> imaginary<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator/(imaginary<T> lhs, Number rhs)
    -> imaginary<std::common_type_t<T, Number>>;

template<typename T, typename Number>
constexpr auto operator+(Number lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator-(Number lhs, imaginary<T> rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator*(Number lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator/(Number lhs, imaginary<T> rhs)
    -> imaginary<std::common_type_t<T, Number>>;

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;

template<typename T, typename Number>
constexpr auto operator+(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator-(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator*(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator/(complex<T> lhs, Number rhs)
    -> complex<std::common_type_t<T, Number>>;

template<typename T, typename Number>
constexpr auto operator+(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator-(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator*(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>;
template<typename T, typename Number>
constexpr auto operator/(Number lhs, complex<T> rhs)
    -> complex<std::common_type_t<T, Number>>;

template<typename T, typename U>
constexpr auto operator+(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator-(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator*(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator/(complex<T> lhs, imaginary<U> rhs)
    -> complex<std::common_type_t<T, U>>;

template<typename T, typename U>
constexpr auto operator+(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator-(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator*(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
template<typename T, typename U>
constexpr auto operator/(imaginary<T> lhs, complex<U> rhs)
    -> complex<std::common_type_t<T, U>>;
```

### Comparison operators

```cpp
template<typename T, typename U>
constexpr auto operator==(imaginary<T> lhs, imaginary<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator!=(imaginary<T> lhs, imaginary<U> rhs)
    -> bool;

template<typename T, typename U>
constexpr auto operator==(complex<T> lhs, complex<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator!=(complex<T> lhs, complex<U> rhs)
    -> bool;

template<typename T, typename Number>
constexpr auto operator==(complex<T> lhs, Number rhs)
    -> bool;
template<typename T, typename Number>
constexpr auto operator!=(complex<T> lhs, Number rhs)
    -> bool;

template<typename T, typename Number>
constexpr auto operator==(Number lhs, complex<T> rhs)
    -> bool;
template<typename T, typename Number>
constexpr auto operator!=(Number lhs, complex<T> rhs)
    -> bool;

template<typename T, typename U>
constexpr auto operator==(complex<T> lhs, imaginary<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator!=(complex<T> lhs, imaginary<U> rhs)
    -> bool;

template<typename T, typename U>
constexpr auto operator==(imaginary<T> lhs, complex<U> rhs)
    -> bool;
template<typename T, typename U>
constexpr auto operator!=(imaginary<T> lhs, complex<U> rhs)
    -> bool;
```

### Mathematical functions

```cpp
template<typename T>
constexpr auto abs(complex<T> z)
    -> T;
```

Computes the magnitude of a complex number `z`.


```cpp
template<typename T>
constexpr auto norm(complex<T> z)
    -> T;

template<typename T>
constexpr auto norm(T value)
    -> T;
```

Computes the squared magnitude of a complex number `z`. If a built-in arithmetic type or an imaginary type is passed, it is converted to a `complex<T>` prior to the operation.

```cpp
template<typename T>
constexpr auto conj(complex<T> z)
    -> complex<T>;

template<typename T>
constexpr auto conj(T value)
    -> complex<T>;
```

Computes the [complex conjugate](https://en.wikipedia.org/wiki/Complex_conjugate) of `z` by reversing the sign of the imaginary part. If a built-in arithmetic type or an imaginary type is passed, it is converted to a `complex<T>` prior to the operation.

```
template<typename T>
constexpr auto polar(T rho, T theta)
    -> complex<T>;
```

Returns a complex number with a magnitude `rho` and a phase angle `theta`.

### User-defined literals

`static_math` provides user-defined literals for the types `imaginary` and `complex` when they are templated over standard integral or floating point types. To make them as usable as possible, they are defined in the inline namespace `complex_literals` in the inline namespace `smath::literals`.

```cpp
constexpr auto operator"" _if(long double n)
    -> imaginary<float>;

constexpr auto operator"" _i(long double n)
    -> imaginary<double>;

constexpr auto operator"" _il(long double n)
    -> imaginary<long double>;

constexpr auto operator"" _i(unsigned long long n)
    -> imaginary<int>;

constexpr auto operator"" _il(unsigned long long n)
    -> imaginary<long>;

constexpr auto operator"" _ill(unsigned long long n)
    -> imaginary<long long>;

constexpr auto operator"" _ui(unsigned long long n)
    -> imaginary<unsigned>;

constexpr auto operator"" _uil(unsigned long long n)
    -> imaginary<unsigned long>;

constexpr auto operator"" _uill(unsigned long long n)
    -> imaginary<unsigned long long>;
```