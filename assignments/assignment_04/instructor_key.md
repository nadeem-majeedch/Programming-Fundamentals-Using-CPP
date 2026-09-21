# Assignment 4 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// intervals.cpp — Assignment 4 reference solution.
#include <iostream>

bool isValid(int lo, int hi) { return lo <= hi; }

bool contains(int lo, int hi, int v) { return lo <= v && v <= hi; }

bool overlap(int lo1, int hi1, int lo2, int hi2)
{
    return lo1 <= hi2 && lo2 <= hi1;   // touching intervals share a point -> true
}

int clamp(int v, int lo = 0, int hi = 100)   // defaults declared here (callers see them)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

// sumRange: recursive sum lo..hi. Base case: lo > hi -> 0.
int sumRange(int lo, int hi)
{
    if (lo > hi) return 0;
    return lo + sumRange(lo + 1, hi);
}

void swapInts(int& a, int& b)
{
    int t{a};
    a = b;
    b = t;
}

int length2d(int w, int h, int depth) { return w * h * depth; }
int length2d(int w, int h)            { return length2d(w, h, 1); }

int main()
{
    std::cout << std::boolalpha;
    std::cout << "isValid(3,1)     -> " << (isValid(3, 1) ? "yes" : "no") << '\n';
    std::cout << "contains(0,10,5) -> " << (contains(0, 10, 5) ? "yes" : "no") << '\n';
    std::cout << "overlap(0,5,5,9) -> " << (overlap(0, 5, 5, 9) ? "yes" : "no") << '\n';
    std::cout << "clamp(150)       -> " << clamp(150) << '\n';
    std::cout << "clamp(150,0,50)  -> " << clamp(150, 0, 50) << '\n';
    std::cout << "sumRange(1,5)    -> " << sumRange(1, 5) << '\n';
    int a{2}, b{9};
    swapInts(a, b);
    std::cout << "swap 2,9         -> " << a << ',' << b << '\n';
    std::cout << "length2d(3,4)    -> " << length2d(3, 4) << '\n';
    std::cout << "length2d(3,4,2)  -> " << length2d(3, 4, 2) << '\n';
    return 0;
}
```

## Verified output (exact)

```
isValid(3,1)     -> no
contains(0,10,5) -> yes
overlap(0,5,5,9) -> yes
clamp(150)       -> 100
clamp(150,0,50)  -> 50
sumRange(1,5)    -> 15
swap 2,9         -> 9,2
length2d(3,4)    -> 12
length2d(3,4,2)  -> 24
```

## Hidden-case classes

- Degenerate `[5,5]`: contains(5) yes; overlap(5,5,5,5) yes.
- `sumRange(7,7)` → 7; `sumRange(1,100)` → 5050 (recursion depth fine).
- Default vs explicit clamp on same value.
- Swap via two references to the same int (self-swap = no-op) — test-table item;
  students must document observing the no-op.

## Common student defects

1. Overlap as `lo2 < hi1` — misses touching case.
2. `sumRange` written iteratively after all — loses recursion line.
3. Overload ambiguity by giving the 3-arg version a default on `depth` *and* a
   2-arg overload — ambiguity compile error; the fix is defaults *or* overload,
   not both.
4. Clamp with `lo > hi` silently inverted — precondition note required, silent
   fix penalized under the honesty rule.
