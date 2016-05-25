[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

`static_math` is a C++ library dedicated to compile time mathematics.

## Compatibility

`static_math` heavily relies on C++ features from the latest standard (C++14 at the
time of writing), therefore only recent compilers will be able to compile it. The
latest g++ and clang++ should be able to compile it, but the `constexpr` support in
Microsoft Visual Studio may not be sufficient yet.

## Principle

`static_math` makes a heavy use of the C++11 keyword `constexpr` to reimplement
a number of existing mathematical functions and some new ones. It also provides
a range of classes (`rational`, `complex`, etc...) whose functions can be used
at compile time too. The library also contains some common mathematical constants.

The library also offers compile-time mathematics at the template parameter level
thanks to it [`constant`](https://github.com/Morwenn/static_math/wiki/Integral-constants)
class, which is a bit like `std::integral_constant` but with an an explicit math
support: for example `constant<int, 5>{} + constant<int, 3>{}` will return an
instance of `constant<int, 8>`. One could also write `5_c + 3_c` thanks to the
provided user-defined literals.

## Design choices

### Compile time library

`static_math` has only been made to be usable at compile time and shall not be
used at runtime. It's still possible to use it at runtime though, but it's not
well advised.

Since the library is only meant to be used at compile time, some design choices
have been made to improve usability, convenience or safety over performance. For
example, the rational numbers are simplified after each operation, which could
badly alter the performance in a runtime context, but which greatly lessens the
risk of overflow in rational operations.

### Intuitive feel

One of `static_math`'s aims is to be easy to use. The functions are implemented
so that they can be used in a straightforward way. This implies that the user will
not have to deal with complex metaprogramming tricks - even though some are used in
the implementation.

This intuitive feel is the one reason why `static_math` needs a recent compiler
since the library will need a heavy support for `constexpr`, `std::initializer_list`
and variadic templates in order to work fine.

Some classes (*e.g.* `rational` and `complex`) use public member variables instead
of getters. This simplifies the access to the internals and also ensures that they
cannot be modified after construction.

### Flexibility

Some classes such as `rational` or `complex` make a heavy use of some type traits
facilities such as `std::common_type` in order to offer some flexibility. Many
functions accept different number types and return and instance of the common type
of the arguments::

```cpp
// Two different types used to represent numbers
int a = 5;
long int b = 100000;

// The bigger of them is used as the output type
auto c = gcd(a, b); // type is long int
```

## Documentation

You can find some documentation in the [associated wiki](https://github.com/Morwenn/static_math/wiki).
You can also generate some anemic documentation thanks to the Doxygen comments in
the code. If you want to know more about the details, reading the source code might
still be an interesting solution: the code should be pretty straightforward and
readable enough. Never hesiste to open a documentation issue if you ever feel that
some parts of the documentation are not complete enough or need more examples.
