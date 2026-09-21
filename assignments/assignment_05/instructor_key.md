# Assignment 5 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// sensors.cpp — Assignment 5 reference solution.
#include <iostream>
#include <iomanip>

const int CAP{1000};
const int LO{-50};
const int HI{60};

// readReadings: fills a with valid readings; returns valid count.
// Invalid readings are consumed and counted through invRef. Precondition: cap >= 1.
int readReadings(int a[], int cap, int& invRef)
{
    int n{};
    if (!(std::cin >> n) || n < 1 || n > cap) return -1;
    int valid{0};
    invRef = 0;
    for (int i{0}; i < n; ++i) {
        int v{};
        std::cin >> v;
        if (v < LO || v > HI) { ++invRef; continue; }
        a[valid] = v;
        ++valid;
    }
    return valid;
}

int minOf(const int a[], int n)   // precondition n >= 1
{
    int m{a[0]};
    for (int i{1}; i < n; ++i) if (a[i] < m) m = a[i];
    return m;
}

int maxOf(const int a[], int n)   // precondition n >= 1
{
    int m{a[0]};
    for (int i{1}; i < n; ++i) if (a[i] > m) m = a[i];
    return m;
}

double meanOf(const int a[], int n)   // precondition n >= 1
{
    long long sum{0};
    for (int i{0}; i < n; ++i) sum += a[i];
    return static_cast<double>(sum) / n;
}

int countAbove(const int a[], int n, double threshold)
{
    int c{0};
    for (int i{0}; i < n; ++i) if (a[i] > threshold) ++c;
    return c;
}

int main()
{
    int readings[CAP]{};
    int invalid{0};
    int valid{readReadings(readings, CAP, invalid)};
    if (valid < 0) { std::cout << "bad n\n"; return 1; }

    std::cout << "valid : " << valid << '\n';
    std::cout << "invalid: " << invalid << '\n';
    if (valid == 0) {
        std::cout << "min   : n/a\nmax   : n/a\nmean  : n/a\nabove : n/a\n";
        return 0;
    }
    double mean{meanOf(readings, valid)};
    std::cout << "min   : " << minOf(readings, valid) << '\n';
    std::cout << "max   : " << maxOf(readings, valid) << '\n';
    std::cout << "mean  : " << std::fixed << std::setprecision(1) << mean << '\n';
    std::cout << "above : " << countAbove(readings, valid, mean) << '\n';
    return 0;
}
```

## Verified runs

| Input | Output |
|---|---|
| `7 / 20 -99 22 19 999 22 21` | `5 / 2 / 19 / 22 / 20.8 / 3` |
| `2 / -99 999` | `0 / 2 / n/a ×4` |
| `1 / -50` | `1 / 0 / -50 / -50 / -50.0 / 0` |
| `2 / 20 20` | mean `20.0`, above `0` |
| `3 / 60 60 -50` | mean `23.3`, above `2` |
| `1000 / 0 …` (1000 zeros) | valid 1000, mean 0.0, above 0 |

## Hidden-case classes

- All-invalid → n/a block exact.
- Boundaries −50 and 60 included; −51/61 excluded.
- Mean rounding: `1 / 20` → `20.0` (not `20`).
- countAbove uses strict `>` — equal-to-mean excluded.
- bad n (0, 1001, non-numeric) → `bad n`, exit 1.

## Common student defects

1. `int` sum overflow at n = 1000 × 60 — fits, but students using `short`-like casts fail; `long long` habit matters for the negative sum case anyway.
2. Invalid readings not consumed → next reading misaligned.
3. min/max initialized to 0 → wrong on all-negative valid sets.
4. `above` computed with `>=`.
5. mean printed with default precision (6 digits) — formatting line lost.
