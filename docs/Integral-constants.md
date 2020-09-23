```cpp
#include <static_math/constant.h>
```

This header defines the class template `constant` which is a mere wrapper around [`std::integral_constant`](http://en.cppreference.com/w/cpp/types/integral_constant). However, its arithmetic, logical, comparison and relational operators are overloaded so that `constant<int, N> @ constant<int, M>` returns an instance of `constant<int, N @ M>` where `@` represents any of the aforementioned operators.

Some of the library's mathematical functions are overload so that, for any such function `func`, `func(constant<int, N>)` returns an instance of `constant<int, func(N)>`.

```cpp
template<typename Integer, Integer N>
struct constant:
    std::integral_constant<Integer, N>
{};

template<bool B>
using bool_constant = constant<bool, B>;

using true_type     = bool_constant<true>;
using false_type    = bool_constant<false>;
```

While the library's main purpose is to provide `constexpr` value-level mathematical functions, this class template also provides type-level integer arithmetics with almost the same syntax as the value-level features. Moreover, this module defines user-defined literals so that it is possible to write things such as `3_c + sqr(2_c) == 7_c` (this expression returns a `true_type`). This achieves expressive type-level integer arithmetics.

Since all the arithmetic, logical, comparison and relational operators are implemented exactly as described above, repeating them all here would be nothing but noise. The library functions overloaded for `constant` are marked as such in this documentation. If you think that more functions should be able to handle integral constants, don't hesitate to submit an issue.

### User-defined literals

static_math provides user-defined literals for the class template `constant` when templated over standard integral types. To make them as usable as possible and to reflect the use of user-defined literals in the standard library, they are defined in the inline namespace `constant_literals` in the inline namespace `smath::literals`.

```cpp
template<char... Digits>
constexpr auto operator"" _c()
    -> constant</* implementation detail */>;

template<char... Digits>
constexpr auto operator"" _cl()
    -> constant</* implementation detail */>;

template<char... Digits>
constexpr auto operator"" _cll()
    -> constant</* implementation detail */>;

template<char... Digits>
constexpr auto operator"" _cu()
    -> constant</* implementation detail */>;

template<char... Digits>
constexpr auto operator"" _cul()
    -> constant</* implementation detail */>;

template<char... Digits>
constexpr auto operator"" _cull()
    -> constant</* implementation detail */>;
```

These user-defined literals do mostly what you would expect them to do: `_c` returns a `constant<int, /* ... */>`, `_cul` returns a `constant<unsigned long, /* ... */>`, etc... However, they are enhanced to behave a bit more like regular integer literals in the sense that, if the integer parsed by `_c` is too big to fit in an `int`, the returned type will be `constant<long, /* ... */>` instead, then `constant<long long, /* ... */>`. These user-defined literals make this kind of thing possible:

```cpp
static_assert(-8_c + 5_c == -3_c, "");
```

### Compatibility

Integral constants do not work with MSVC++ versions older than 19.12 because of a few bugs and are thus automatically disabled for these versions. If needed, it can be manually disabled by defining the macro `STATIC_MATH_NO_INTEGRAL_CONSTANT`.