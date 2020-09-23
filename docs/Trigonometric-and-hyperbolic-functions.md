```cpp
#include <static_math/trigonometry.h>
```
This header contains the standard [trigonometric functions](https://en.wikipedia.org/wiki/Trigonometric_functions) and [hyperbolic functions](https://en.wikipedia.org/wiki/Hyperbolic_function). The functions `sin`, `cos`, `tan`, `sinh`, `cosh` and `tanh` are also available in the header `<static_math/cmath.h>` for consistency with the standard library header `<cmath>`.

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

```cpp
template<typename Float>
constexpr auto cot(Float x)
    -> Float;
```

Computes the cotangent of `x` (measured in radians). 

```cpp
template<typename Float>
constexpr auto sec(Float x)
    -> Float;
```

Computes the secant of `x` (measured in radians). 

```cpp
template<typename Float>
constexpr auto csc(Float x)
    -> Float;
```

Computes the cosecant of `x` (measured in radians). 

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

```cpp
template<typename Float>
constexpr auto coth(Float x)
    -> Float;
```

Computes the hyperbolic cotangent of `x` (measured in radians). 

```cpp
template<typename Float>
constexpr auto sec(Float x)
    -> Float;
```

Computes the hyperbolic secant of `x` (measured in radians). 

```cpp
template<typename Float>
constexpr auto csc(Float x)
    -> Float;
```

Computes the hyperbolic cosecant of `x` (measured in radians). 
