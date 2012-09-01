static_math
===========

static_math is a library dedicated to compile time mathematics.

It provides a range of functions and classes, all of which can be used at compile time.
It's generally not a good idea to use the same functions at runtime though, since many of them rely on deep recursion which would not be optimized at runtime.