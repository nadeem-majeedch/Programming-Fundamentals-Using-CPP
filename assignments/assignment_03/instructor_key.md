# Assignment 3 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// collatz.cpp — Assignment 3 reference solution.
#include <iostream>
#include <iomanip>
#include <string>

// next: one Collatz step. Precondition: n > 1. Postcondition: returns successor.
long long next(long long n)
{
    if (n % 2 == 0) return n / 2;
    return 3 * n + 1;                 // long long: 3n+1 can exceed int for n near 10^6
}

// collatzLength: steps from n down to 1. Precondition: n >= 1. Postcondition: step count (0 for n==1).
int collatzLength(long long n)
{
    int steps{0};
    while (n > 1) { n = next(n); ++steps; }
    return steps;
}

// collatzMax: largest value on the path, including n itself. Precondition: n >= 1.
long long collatzMax(long long n)
{
    long long mx{n};
    while (n > 1) { n = next(n); if (n > mx) mx = n; }
    return mx;
}

// printPath: comma-separated path ending at 1. Precondition: n >= 1.
void printPath(long long n)
{
    std::cout << n;
    while (n > 1) {
        n = next(n);
        std::cout << ", " << n;
    }
    std::cout << '\n';
}

int main()
{
    long long n{};
    if (!(std::cin >> n) || n < 1 || n > 1000000) {
        std::cout << "bad n\n";
        return 1;
    }
    std::cout << "steps: " << collatzLength(n) << '\n';
    std::cout << "max: " << collatzMax(n) << '\n';
    printPath(n);
    return 0;
}
```

## Verified runs

| Input | Exit | Output |
|---|---|---|
| `6` | 0 | `steps: 8` / `max: 16` / `6, 3, 10, 5, 16, 8, 4, 2, 1` |
| `1` | 0 | `steps: 0` / `max: 1` / `1` |
| `27` | 0 | `steps: 111` / `max: 9232` / path |
| `1000000` | 0 | `steps: 152` / `max: 2974984576` (fits long long; overflows int) |
| `0` | 1 | `bad n` |
| `abc` | 1 | `bad n` |

## Hidden-case classes

- n = 2 (smallest multi-step); n = 3.
- Path single-element formatting (no trailing comma) for n = 1.
- Overflow probe near the top of the range (n = 1000000 exactly).
- Read-failure with a trailing token.

## Common student defects

1. `3*n+1` in `int` — overflow probe catches it.
2. Max tracker excludes n itself (spec includes it).
3. Trailing comma after the final `1`.
4. Rule duplicated with a drift (one copy uses `/2` correctly, other doesn't) — the single-sourcing constraint exists to surface this in review.
