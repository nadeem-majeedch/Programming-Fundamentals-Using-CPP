# Demonstrations · Group 2 — Variables, Operators, Conversions, Decisions (L05–L08)

**Instructor-only scripts.** Conventions as in
[demo_group1_basics.md](demo_group1_basics.md): edit-in-place planned errors,
contract build, verified output, 3-step diagnostic ritual.

---

## DEMO-05 · Integer vs Floating-Point Division, Modulo, Cast Placement (L05)

- **Objective:** make precedence an *agreement*, and integer division a *picture* (quotient/remainder), not a memorized rule.
- **Preparation:** compile `examples/precedence_demo.cpp`; rehearse negative-operand outputs on the teaching machine and have the truncation-toward-zero note ready (documented behavior).
- **Source:** [examples/precedence_demo.cpp](../../examples/precedence_demo.cpp); DS-angle companion `instructor/demonstrations/demo05_ds_conversions.cpp` (below).
- **Delivery sequence:**
  1. Predict-then-run in three blocks: pure precedence (`2 + 3 * 4`); division/modulo pairs (`17 / 5`, `17 % 5`); negatives (`-7 / 2`, `-7 % 2`).
  2. Build the quotient-remainder picture on the board: `17 = 5·3 + 2` — `/` answers "how many 5s", `%` answers "what's left".
  3. **Planned error:** the average bug `(a + b) / 2` on ints — silent, wrong; classify it (logic, *silent*) and park the fix for DEMO-06's `static_cast` payoff.
- **Questions:** "Why does `2 + 3 * 4` not need parentheses — who decided?" · "For `-7 / 2`: what does *discarding the remainder* give?" · "Name one real quantity where `%` is exactly what you want."
- **Expected observations:** 14; 3 & 2; -3 & -1 (documented truncation toward zero); the silent 8-instead-of-8.5 average.
- **Common student mistakes:** "mod gives the decimal part" (it's integer remainder); casting after dividing; parenthesizing everything instead of learning the ladder.
- **Debugging variation:** minutes→h:mm converter where `hours = mins / 60` on an int output prints h correctly but `minutes = mins / 60 - hours*60`... wrong — re-derive with `%`.
- **Extension:** `n % 10` digit extraction pipeline (feeds L09's digit problems); predict `x % 2` for negative x.
- **Verified output (demo05_ds_conversions.cpp, fixed data):**
  ```
  static_cast<int>(82.75) = 82
  sum=332 n=4
  wrong  sum/n (int)  = 83
  right  cast first    = 83.25
  proportion even = 0.75
  ```
- **Instructor notes:** the negative-modulo moment must end with "documented, compiler-consistent behavior — we *checked* ours" — that sentence is the standard-vs-implementation distinction in miniature. The DS companion makes the mean/proportion stakes concrete for the BSDS half of the room.

**Companion source — `instructor/demonstrations/demo05_ds_conversions.cpp`:** (source on file in this folder; see `demo05_ds_conversions.cpp` — fixed demonstration data, no input required; verified output above).

---

## DEMO-06 · Type Conversion: Implicit, Narrowing, `static_cast` (L06)

- **Objective:** show conversions happening *silently* and how to make them deliberate — the payoff of L05's parked average bug.
- **Preparation:** compile `examples/conversion_demo.cpp`; rehearse warning output for narrowing under contract flags.
- **Source:** [examples/conversion_demo.cpp](../../examples/conversion_demo.cpp).
- **Delivery sequence:**
  1. Predict-then-run: `int x = 7.9;` → 7 (truncation); `double d = 3;` → 3.0.
  2. The average bug returns: `(a + b) / 2` on ints → silent whole number; the class' L05 memory activated.
  3. Fix live with `static_cast<double>(a + b) / 2` — the fix is *documentation as much as computation*.
  4. **Planned error:** assign `double` to `int` with a fractional value → narrowing warning under the contract; read it, then remove the warning by making the conversion explicit (`static_cast<int>`), showing "explicit beats implicit."
- **Questions:** "Which direction of conversion loses information — and why does the compiler allow it at all?" · "Where exactly does the conversion happen in `double avg = a + b / 2;`?" (Order-of-operations + conversion — two lessons, one line.)
- **Expected observations:** truncation outputs; the silent integer average; the narrowing warning; identical final outputs for explicit vs implicit — but one has a warning and one doesn't.
- **Common student mistakes:** casting *after* dividing (`(double)(a/b)`); believing `static_cast` rounds (it truncates, like assignment would).
- **Debugging variation:** `double avg = total / count;` with `total=17, count=2` → 8.0 not 8.5; trace to the *expression's* type, not the variable's.
- **Extension:** `(int)c` on `'A'` — the L03 parked mystery resolved here; char arithmetic tease.
- **Verified output:** deterministic (fixed literals) — e.g. `x = 7`, `d = 3`, `avg = 8.5` after the fix; verify locally before class.
- **Instructor notes:** this demo is the *payoff* of L05's integer-division trap; reference it by name for the rest of the term whenever a student's average comes out whole.

---

## DEMO-07 · Conditions: the Assignment-in-Condition Trap (L07)

- **Objective:** produce the silent `=` vs `==` bug *in public* and make the warning-based defense habitual.
- **Preparation:** compile `examples/decisions_grade.cpp`; prepare the edit (single `=`) as a typed-live change.
- **Source:** [examples/decisions_grade.cpp](../../examples/decisions_grade.cpp); bank entry [MC-01](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Grade ladder predict-then-run at boundary values (59, 60, 90, 101).
  2. **Planned error:** change `if (mark >= 60)` to `if (mark = 60)`. Predict *before compiling*: error, warning, or silence? (Answer: warning under contract flags; silent under default flags — both facts matter.)
  3. Run: "Distinction" no matter the input. Trace *why* on the board: assignment's value is 60, non-zero, true — and mark is destroyed.
  4. Fix (`==`), re-run, boundary values again.
- **Questions:** "Why didn't the compiler *refuse*?" · "Which flag family caught it for us?" · "How would you defend your teammate's code against this?" (Code review — the rubric's style row.)
- **Expected observations:** wrong behavior on every input; the contract warning; correct behavior after fix.
- **Common student mistakes:** "fixing" by adding `==` to *all* comparisons without understanding; believing the warning is optional noise.
- **Debugging variation:** the `while (count = 10)` variant — infinite loop edition of the same bug (foreshadows L09).
- **Extension:** chain-of-responsibility refactor: convert the ladder to guard-style early returns; compare readability.
- **Verified output:** deterministic per input; e.g. input `55` → `F`, input `60` → `D` (verify against the lecture notes' expected table before class).
- **Instructor notes:** the vote before compiling is the entire lesson — most of the room says "error". Learning that *silence* is possible (without flags) is the security lesson of Module 4.

---

## DEMO-08 · `switch`, `break`, and Fall-Through (L08)

- **Objective:** make the switch walk-off *visible* — then install the break discipline and the default case habit.
- **Preparation:** compile `examples/switch_menu.cpp`; board plan: menu options 1–4 + exit.
- **Source:** [examples/switch_menu.cpp](../../examples/switch_menu.cpp); bank entry [MC-02](../misconception-bank/misconception_bank.md) (fall-through variant).
- **Delivery sequence:**
  1. Predict-then-run the menu: each option's output; note the `default:` arm's role for invalid choices.
  2. **Planned error:** remove one `break` → observe the walk-off live (option 1 also prints option 2's line). Name it: fall-through.
  3. Fix, re-run, contrast. Then swap `break` for `continue`/`return` where legal — why each behaves differently.
  4. Boundary votes: case labels as `const int` vs literals; what happens with an unmatched choice (default).
- **Questions:** "After `case 1:` runs with no break, where does control *walk*?" · "Why do switch cases share one scope — and when does that bite?" · "When is `switch` better than `else if`, honestly?" (Discrete known values.)
- **Expected observations:** the walk-off; correct isolation after fix; the default arm catching bad input.
- **Common student mistakes:** switch on a `double` or string (not allowed in standard C++ — say why ranges don't fit); forgetting `default:`; putting a `break` *outside* the switch block by brace slip.
- **Debugging variation:** symptom-only: "choosing 2 prints both lines 2 and 3" — one missing break; locate by reading the case order, not by running.
- **Extension:** refactor a 3-arm `else if` ladder into `switch` — which direction was clearer? (Honest answer varies; the *criteria* are the lesson.)
- **Verified output:** deterministic per input; e.g. choice `1` → `Add record` (and, when broken, also `List records`); choice `9` → the default message. Verify exact wording locally before class.
- **Instructor notes:** the walk-off is physical — draw the control arrow *falling through* the case labels on the board; the picture prevents a semester of confusion. The `char`-switch (menu letters) is the extension that makes switch feel native.

---

**Companion source — `instructor/demonstrations/demo05_ds_conversions.cpp`:**

```cpp
// DEMO-05 companion · Three type conversions for the data student: truncating
// cast, correct cast-before-divide mean, and safe proportion (empty-data guard).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic demo05_ds_conversions.cpp -o demo05
// input:   none (fixed demonstration data)
//
// Used in demo_group2_operators.md (DEMO-05, DS angle) to make integer
// division, cast placement, and 0..1 proportions observable.

#include <iostream>
#include <vector>

int main()
{
    // Act 1: truncating cast — double to int discards the fraction.
    double reading = 82.75;
    int whole = static_cast<int>(reading);
    std::cout << "static_cast<int>(82.75) = " << whole << '\n';

    // Act 2: mean of integer readings. Division happens BEFORE any cast
    // unless we cast first — the classic silent bug.
    std::vector<int> readings{88, 92, 79, 73};
    int sum = 0;
    for (int r : readings)
        sum += r;
    int n = static_cast<int>(readings.size());

    std::cout << "sum=" << sum << " n=" << n << '\n';
    std::cout << "wrong  sum/n (int)  = " << sum / n << '\n';
    std::cout << "right  cast first    = "
              << static_cast<double>(sum) / n << '\n';

    // Act 3: proportion of even values — a 0..1 quantity needs floating math.
    int evens = 0;
    for (int r : readings)
        if (r % 2 == 0)
            ++evens;
    std::cout << "proportion even = "
              << (n > 0 ? static_cast<double>(evens) / n : 0.0) << '\n';
    return 0;
}
```
