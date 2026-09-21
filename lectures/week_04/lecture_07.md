# L07 · `if`, `if/else`, and Nested Selection

**Module 4 — Decision-Making Statements · Week 4 · Lecture 7 of 32 · 120 minutes**
**Outcomes:** CLO-3 · PF-4.1, PF-4.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Evaluate relational (`< <= > >= == !=`) and logical (`&& || !`)
   expressions, including short-circuit behavior and the `!`-of-comparison
   form (PF-4.1).
2. Implement `if`, `if/else`, and `if/else if/else` chains whose branches
   jointly cover every case of a specification, with no unreachable or
   contradictory conditions (PF-4.2).
3. Rewrite nested selections as guard clauses (early exit) and justify which
   form is clearer for a given rule set (PF-4.2).

## Prerequisites

L06 (bool conversion rule: nonzero → true); L03 (`const`, comparisons of
computed values).

## Concept sequence

1. From straight-line to branching programs
2. Conditions as bool-producing expressions
3. `==` vs `=` — the assignment-in-condition trap
4. `&&`, `||`, `!` + short-circuit evaluation with side-effect-free demos
5. `if / else if / else` as ordered rule sets
6. Nesting vs guard clauses

## Teaching topics (detailed)

- **Comparison operators** on numbers and chars; `bool` output prints as
  `1/0` (tie back to L06's conversion rule).
- **`==` vs `=`:** `if (x = 5)` compiles (assign, nonzero → true) — live
  demo with the warning the course's `-Wall` contract catches; braces always
  (dangling-else shown as a "why braces" argument).
- **Short-circuit:** `(n != 0) && (total / n > 10)` — the guard idiom;
  division-by-zero avoided *by order*; `||` stops on first true.
- **Range checks done right:** `0 <= score && score <= 100` (not math
  notation `0 <= score <= 100`, which is a silent logic bug — predict-then-run
  demo).
- **Branch design:** mutually exclusive, collectively exhaustive; ordered
  `else if` from most-specific to most-general; grade-scale worked example
  with deliberate first-version bug (descending order mistake) fixed live.
- **Guard clauses:** validate-and-return style previewed (functions arrive in
  Module 7; here it stays within `main`).

## C++ examples required

| File | Role |
|---|---|
| `decisions_grade.cpp` ✅ | grade classifier: naive → corrected → guard-clause refactor, all three kept in the file for comparison |
| (live) `short_circuit_demo.cpp` | printed evaluation trace showing which side of `&&`/`||` ran |

## Conceptual explanation (beginner-first)

Everything so far ran top to bottom, unconditionally. Real decisions need
the program to ask yes/no questions and take different paths. In C++, a
"yes/no question" is an **expression whose value is `true` or `false`** —
built from comparisons (`>=`, `==`) and combined with **and/or/not**
(`&&`, `||`, `!`). The `if` statement then runs (or skips) a block based on
that answer.

Two ideas make branch-writing safe. First, **short-circuit evaluation**:
in `A && B`, if `A` is false, `B` is never evaluated — C++ promises this.
That turns `(n != 0) && (total / n > 10)` into a *safety pattern*: the
guard `n != 0` protects the division behind it. Second, **branch order
matters** in `if / else if` chains: the first matching branch wins, so
ranges must run from most specific (highest) to least, with the `else`
catching everything left. A chain whose branches are mutually exclusive
and collectively exhaustive covers every case — the property the branch-
coverage workshop drills.

## Terminology and definitions

| Term | Definition |
|---|---|
| Condition | An expression of type bool controlling a branch |
| Relational operators | `< <= > >= == !=` — produce bool |
| Logical operators | `&&` (and), `||` (or), `!` (not) |
| Short-circuit evaluation | `&&`/`||` skip the right side when the left decides |
| Guard | A check placed *before* a risky operation, enabled by short-circuiting |
| `else if` chain | Ordered multi-way selection; first match wins |
| Guard clause | Early return/branch for invalid cases, flattening nesting |
| Mutually exclusive | Conditions that cannot both be true |
| Collectively exhaustive | Some branch matches for every possible input |
| Range check | `lo <= x && x <= hi` — never math-style `lo <= x <= hi` |

## Syntax and C++ examples

```cpp
if (score >= 90)                  // condition in parentheses, ALWAYS
{
    std::cout << "A\n";           // runs when condition is true
}
else if (score >= 80)             // checked only if the first was false
{
    std::cout << "B\n";
}
else                              // everything left lands here
{
    std::cout << "keep going\n";
}

// combining conditions
if (age >= 13 && age <= 19) { }            // teenager
if (day == "Sat" || day == "Sun") { }      // weekend
if (!(score >= 60)) { }                    // failing (same as score < 60)

// the short-circuit guard
if (n != 0 && total / n > 10) { }          // safe: division only when n != 0
```

## Line-by-line code explanation

`examples/decisions_grade.cpp`:

1. Input is validated first (`if (!(std::cin >> score))`) — decisions on
   unvalidated data are decisions on garbage.
2. **Version 1 (commented) is deliberately wrong:** `score >= 60` first
   means 95 matches immediately and prints "D". The lesson: an `if/else if`
   chain is an *ordered* rule set.
3. **Version 2 (active)** runs from 90 down to 60, ending in `else` —
   mutually exclusive by construction (each branch implies all later
   conditions are false), collectively exhaustive (the `else` catches all).
4. **Version 3** shows the correct range check `score >= 0 && score <= 100`
   beside the commented math-notation bug `0 <= score <= 100` — which C++
   reads as `(0 <= score) <= 100`, i.e. a bool compared to 100: always true.
5. Style: every branch uses braces even for one statement — the dangling-
else insurance.

## Output prediction questions (with answers)

1. `int x{7}; if (x = 5) { ... }` — runs? — Yes, ALWAYS: `x = 5` *assigns*
   (value 5 → true) and clobbers x. `==` compares; `-Wall` warns here.
2. `int n{0}; (n != 0) && (10 / n > 2)` — value? crash? — `false`, and the
   division never runs (short-circuit) — no crash.
3. `if (0 <= s && s <= 100)` with `s = 150` — ? — false (correct range
   form).
4. `(true || anything)` and `(false && anything)` — ? — true / false — the
   right side is *not even evaluated*.
5. Chain: score = 85 in the corrected grade program — ? — "B" (80 branch;
   the 90 test failed first).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| `=` instead of `==` | Condition always (or never) true; variable clobbered | `==`; compile with `-Wall` |
| Math range notation `0 <= x <= 100` | Always true — silent logic bug | `0 <= x && x <= 100` |
| Ascending `else if` chain | High scores classified as low grades | Order descending; else catches the rest |
| Missing `else` when needed | Both messages print (two independent ifs) | Chain with `else if` when paths are exclusive |
| Dangling else | The `else` binds to the *nearest* `if` | Braces on every branch |
| Un-protected division | Runtime crash when n = 0 | Short-circuit guard first |

## Common student misconceptions

- **"`=` and `==` are interchangeable in conditions."** `if (x = 5)`
  assigns and is truthy; a dedicated trace example makes the damage
  visible (after this lecture `x` is `5`, not the tested value).
- **"The `else` belongs to the nearest visible `if` on screen."** It
  binds to the nearest *unmatched* `if` regardless of indentation —
  show the braceless nested example that renders the wrong program.
- **"`if (0 <= x <= 10)` checks a range."** It parses as
  `(0 <= x) <= 10` — always true for any `x`; the correct form is the
  logical and of two comparisons.
- **"A `switch` falls out after each case."** Without `break`, control
  falls through into the next case; accidental fallthrough is the
  classic switch bug.
- **"Negative numbers compare differently."** `-3 < 5` uses ordinary
  arithmetic order; students who memorized ASCII tables sometimes
  flinch here.

## Classroom demonstrations

1. **Order-of-branches autopsy:** run version 1 (buggy) with 95, watch "D"
   print; then version 2 — the ordering lesson needs no lecture notes.
2. **Short-circuit proof:** a function that prints before dividing, placed
   after `&&` — the print does not appear when the guard fails.
3. **Coverage hunting:** feed the corrected program the boundary values
   0, 59, 60, 89, 90, 100, 101 — students see every branch fire.

## Guided student activities
**Branch-coverage workshop (20 min):** teams receive a bugged ticket-pricing
rule set (child/adult/senior, weekend multiplier, discount stacking); they
write the `if/else` chain, then adversarially list inputs that break other
teams' chains (coverage hunting). Best "killer input" wins.

## Practice problems
- Evaluate 10 boolean expressions (incl. short-circuit order, `!`, mixed
  int/bool).
- Implement 3 rule sets as full programs (shipping cost, password length +
  digit check with `&&`, leap year).
- Rewrite a 3-deep nested `if` as guard clauses.
- (🟡 stretch) Explain the dangling-else problem with a 6-line example.

## Summary

Decisions are bool-valued expressions: comparisons joined by `&&`/`||`/
`!`, with short-circuiting making guards possible. `if / else if / else`
is an *ordered* rule set — descending ranges, `else` as the catch-all,
braces always. The three classic bugs (`=` for `==`, math-range notation,
ascending chains) are silent, so branch coverage discipline is the defense.
Next (L08): the other half of selection — `switch` for discrete cases and
the `?:` operator for choosing values.

- "`if (0 <= x <= 100)` checks a range." (It checks `(0 <= x) <= 100` —
  always true; classic silent bug.)
- "`else if` is a different statement." (It's `else` + nested `if`; the
  chain is syntax sugar — draw the nesting.)
- "`&&`/`||` always evaluate both sides." (Short-circuit by standard.)
- "Comparing with `=` is a type error." (It's a legal int assignment →
  truthiness; needs the warning set to catch.)

## Exit ticket / formative assessment

1. Evaluate with short-circuit order: `int n{0}; n != 0 && 10 / n > 2` —
   value? did the division run?
2. Why is `if (x = 5)` always true?
3. Write the range check for a valid percentage (0–100 inclusive) the way
   the course requires.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (conversions quiz) + branching motivation | 10 |
| Conditions: relational/logical operators, short-circuit | 35 |
| Break | 10 |
| `if/else if/else` design + guard clauses (grade example) | 35 |
| Branch-coverage workshop | 20 |
| Exit ticket + L08 preview | 10 |
