# Assignment 1 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 (sample 10 + hidden 20) · testing table 0 (via testing.md) —
*total on the student sheet says 40: correctness 30, postmortem 10, test table is
scored inside correctness B/robustness lines.* See mark-math note at the end.

## Reference solution (compiled & executed, GCC 16.2, contract flags)

```cpp
// record_card.cpp — Assignment 1 reference solution.
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::string name{};
    int age{};
    double lab{}, midterm{}, final{};

    if (!(std::cin >> name >> age >> lab >> midterm >> final)) {
        std::cout << "bad input\n";
        return 1;
    }
    if (lab < 0 || lab > 100 || midterm < 0 || midterm > 100 ||
        final < 0 || final > 100) {
        std::cout << "bad input\n";
        return 1;
    }

    double avg{lab * 0.25 + midterm * 0.35 + final * 0.40};

    std::cout << "=== COURSE RECORD ===\n";
    std::cout << "name   : " << name << '\n';
    std::cout << "age    : " << age << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "lab    : " << lab << '\n';
    std::cout << "midterm: " << midterm << '\n';
    std::cout << "final  : " << final << '\n';
    std::cout << "average: " << avg
              << " (weighted: lab 25% / midterm 35% / final 40%)\n";
    return 0;
}
```

## Verified runs

| Input | Exit | Output tail |
|---|---|---|
| `Ayesha 20 88 79 91` | 0 | `average: 86.05 (weighted: …)` |
| `Ben 19 0 0 100` | 0 | `average: 40.00` |
| `Cara 21 100 100 100` | 0 | `average: 100.00` |
| `Dan 20 88 79 101` | 1 | `bad input` |
| `Eve 20 88` + EOF | 1 | `bad input` |

(The sample-card hint in the student sheet is deliberate: students who compute
`88*25/100` in int arithmetic print 86.00 and discover the defect.)

## Hidden-case classes (B lines)

- Age negative — spec is silent; accept either pass-through or validation if
  *stated in a comment* (spec-ambiguity rule in `../../instructor/assessment-rubrics/correctness.md`).
- Grades 0 and 100 exactly — boundaries pass.
- Non-numeric grade (`abc`) → `bad input`, exit 1.
- Name with trailing spaces — single-word read only; leading spaces tolerated.

## Common student defects

1. `lab*25/100` integer-style math despite doubles (precedence/truncation mix) — sample line catches it.
2. `setprecision` before `std::fixed` — prints 6 significant digits.
3. Validating after printing the card — order-of-exits defect.
4. Reading grades as `int` then "fixing" by cast — loses the point of types.

## Mark math (matches sheet totals)

Correctness 30 + postmortem 10 = **40** ✓ (testing table feeds correctness lines
per `../../instructor/assessment-rubrics/testing.md` §relationship note).
