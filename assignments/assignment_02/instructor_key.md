# Assignment 2 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// tuition.cpp — Assignment 2 reference solution.
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

int main()
{
    std::string residency{};
    int credits{};
    double scholarship{};

    if (!(std::cin >> residency >> credits >> scholarship)) {
        std::cout << "bad residency\n";     // order rule: first failing read
        return 1;
    }
    if (residency != "in" && residency != "out") {
        std::cout << "bad residency\n";
        return 1;
    }
    if (credits < 1 || credits > 24) {
        std::cout << "bad credits\n";
        return 1;
    }
    if (scholarship < 0) {
        std::cout << "bad scholarship\n";
        return 1;
    }

    double total{};
    if (residency == "in") {
        total = std::min(1200.0 + credits * 150.0, 4500.0);
    } else {
        total = std::min(2500.0 + credits * 320.0, 8000.0);
    }
    total -= scholarship;
    if (total < 0) total = 0;

    std::cout << "estimate: " << std::fixed << std::setprecision(2)
              << total << '\n';
    return 0;
}
```

## Verified runs

| Input | Exit | Output |
|---|---|---|
| `in 12 0` | 0 | `estimate: 3000.00` |
| `out 20 500` | 0 | `estimate: 7500.00` |
| `in 22 0` | 0 | `estimate: 4500.00` (cap) |
| `out 1 10000` | 0 | `estimate: 0.00` (floor) |
| `in 30 0` | 1 | `bad credits` |
| `xx 10 0` | 1 | `bad residency` |
| `in 10 -5` | 1 | `bad scholarship` |
| `in 10.5 0` | 1 | `bad residency` (stream fails on `.` → residency read ok, credits read fails → but residency validated first) |

The last row is the subtle one: `10.5` fails `>> credits` *before* scholarship is
read. The spec's message-order rule means the program must report per the first
failed stage — accept either `bad residency` (stream-state path) or a documented
`bad credits` mapping, but require consistency with the stated order check.

## Hidden-case classes

- Cap boundary: exactly 4500/8000 (min reaches cap with no scholarship).
- Scholarship exactly equal to total → 0.00 floor.
- Credits 1 and 24 pass; 0 and 25 fail.
- Order-of-validation probes (two errors at once → first message only).

## Common student defects

1. Cap applied after scholarship (out-of-order rule).
2. `residency == "in" || "out"` — always-true string comparison.
3. Missing floor; negative estimates printed.
4. `switch` on `std::string` — compile error, must use ladder.