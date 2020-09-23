```cpp
#include <static_math/vector.h>
```

Vectors are a work-in-progress feature. The long-term goal is to add some basic [linear algebra](https://en.wikipedia.org/wiki/Linear_algebra) features to `static_math`, including vector and matrix operations. As of now, `smath::vector` is but a thin wrapper around `std::array`. Some features will be added in the future; some features may disappear too, such as regular container operations that have little to do with linear algebra.

```cpp
template<typename T, std::size_t N>
struct vector;
```

### Types

```cpp
using value_type    = typename std::array<T, N>::value_type;
using size_type     = typename std::array<T, N>::size_type;
using const_pointer = typename std::array<T, N>::const_pointer;
```

### Element access

```
constexpr auto operator[](size_type i) const
    -> value_type;

constexpr auto at(size_type i) const
    -> value_type;

constexpr auto front() const
    -> value_type;

constexpr auto back() const
    -> value_type;

constexpr auto data() const
    -> const_pointer;
```

### Capacity

```cpp
constexpr auto empty() const
    -> bool;

constexpr auto size() const
    -> size_type;

constexpr auto max_size() const
    -> size_type;
```

### Vectors algebra

```cpp
template<typename T, std::size_t N>
constexpr auto operator+(vector<T, N> lhs, vector<T, N> rhs)
    -> vector<T, N>;

template<typename T, std::size_t N>
constexpr auto operator-(vector<T, N> lhs, vector<T, N> rhs)
    -> vector<T, N>;
```
