```cpp
#include <static_math/constants.h>
```

`static_math` provides a few mathematical constants exposed as `constexpr` variable template with a default `double` precision, mainly corresponding to the ones defined in a POSIX-compliant `<math.h>`. The constants provided mostly correspond to the ones that can't be created by the library's function. All the constants in this module live in the namespace `smath::constants`.

### POSIX-compliant constants

```cpp
/** e */
template<typename T=double>
constexpr T e = static_cast<T>(2.71828182845904523540L);

/** log2(e) */
template<typename T=double>
constexpr T log2e = static_cast<T>(1.44269504088896340740L);

/** log10(e) */
template<typename T=double>
constexpr T log10e = static_cast<T>(0.43429448190325182765L);

/** ln(2) */
template<typename T=double>
constexpr T ln2 = static_cast<T>(0.69314718055994530942L);

/** ln(10) */
template<typename T=double>
constexpr T ln10 = static_cast<T>(2.30258509299404568402L);

/** pi */
template<typename T=double>
constexpr T pi = static_cast<T>(3.14159265358979323846L);
```

### Other mathematical constants

```cpp
/** Golden ratio */
template<typename T=double>
constexpr T phi = static_cast<T>(1.61803398874989484820L);
```