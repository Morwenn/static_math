```cpp
#include <static_math/bit.h>
```

The functions in this header correspond to ones in the C++20 standard library header <bit>. Those are mostly bitwise operations that work on unsigned integer types.

### Integral power-of-2 operations

```cpp
template<typename Unsigned>
constexpr auto ispow2(Unsigned x) noexcept
    -> bool;
```

Computes whether the unsigned integer `x` is a power of two. 

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Unsigned>
constexpr auto ceil2(Unsigned x) noexcept
    -> Unsigned;
```

Computes the minimal value `y` such that `ispow2(y)` is `true` and `y >= x`; if `y` is not representable as a value of type `Unsigned`, the result is an unspecified value.

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Unsigned>
constexpr auto floor2(Unsigned x) noexcept
    -> Unsigned;
```

If `x == 0`, returns `0`; otherwise computes the maximal value `y` such that `ispow2(y)` is `true` and `y <= x`. 

*This function is overloaded so that it can handle [[integral constants]].*

```cpp
template<typename Unsigned>
constexpr auto log2p1(Unsigned x) noexcept
    -> Unsigned;
```

If `x == 0`, returns `0`; otherwise one plus the base-2 logarithm of `x`, with any fractional part discarded. 

*This function is overloaded so that it can handle [[integral constants]].*