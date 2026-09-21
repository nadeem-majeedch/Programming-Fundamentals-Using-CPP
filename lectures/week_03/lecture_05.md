# L05 · Arithmetic Operators, Precedence, and Integer vs Floating-Point Division

**Module 3 — Operators and Expressions · Week 3 · Lecture 5 of 32 · 120 minutes**
**Outcomes:** CLO-2 · PF-3.1, PF-3.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Evaluate arithmetic expressions (`+ - * / %`, unary minus) honoring
   precedence and left-associativity, and annotate an expression tree for any
   single-operator step (PF-3.1).
2. Predict exactly when `/` truncates (both operands integral) and compute
   `%` for positive **and negative** operands, and exploit `/`+`%` for digit
   extraction (PF-3.2).
3. Use parentheses to make intent explicit and explain why "it works" is not
   the standard for readable expressions (PF-3.1).

## Prerequisites

L03–L04 (typed variables; can read/print values).

## Concept sequence

1. Expressions produce values (everything on the right of `=`)
2. The arithmetic operator set + unary minus
3. Precedence & associativity: `* / %` above `+ -`, left to right
4. Integer division & modulo — the week's star trap
5. Digit extraction with `/ 10` and `% 10` (first real "algorithm")
6. Operator expressions inside output (`cout << 7 / 2`)

## Teaching topics (detailed)

- **Operator table** with examples; `%` defined as *remainder*; sign rule
  shown by machine experiment (`-7 % 2` → `-1` in C++, sign follows the
  dividend) — students *predict-then-run*.
- **Precedence ladder:** parentheses → unary → `* / %` → binary `+ -`;
  associativity left-to-right for same tier; expression-tree drawing on the
  board for `2 + 3 * 4 - 6 / 2` (→ `2+12-3 = 11`).
- **Integer division:** `7/2 = 3`, `-7/2 = -3` (truncation toward zero, not
  floor); `7.0/2 = 3.5`; the classic bug: `avg = a + b / 2;` (precedence) vs
  `(a + b) / 2` (truncation!) — both wrong differently.
- **Modulo uses:** even/odd (`n % 2`), divisibility, last digit
  (`n % 10`), clock arithmetic; digit-drop (`n / 10`).
- **Style:** parenthesize even when redundant; one operation per line in
  complex formulas.

## C++ examples required

| File | Role |
|---|---|
| `precedence_demo.cpp` ✅ | 10 expressions with printed results: precedence, associativity, int vs double division, negative `%` |
| (live) `digit_extractor.cpp` | takes a 3-digit number, extracts/sprints each digit with `/` and `%` |

## Conceptual explanation (beginner-first)

Arithmetic in C++ looks like school math and behaves like it *almost* always.
The `almost` hides two traps that break real programs:

1. **Operator precedence**: multiplication binds tighter than addition, so
   `2 + 3 * 4` is 14, not 20. When in doubt, parenthesize — parentheses are
   free and make your intent readable.
2. **Integer division**: `/` between two *whole numbers* produces a whole
   number — the fraction is discarded, not rounded. `7 / 2` is `3`. This is
   not a bug in C++; it is the *definition*: int / int → int. The moment one
   operand is `double` (`7.0 / 2`), you get `3.5`.

The companion operator `%` (modulo) gives the *remainder* of that whole-
number division: `7 % 2` is `1`. Modulo is the Swiss-army knife of
programming: even/odd tests, "every Nth item", clock arithmetic, and — as
students will see in five minutes — extracting the digits of a number.

## Terminology and definitions

| Term | Definition |
|---|---|
| Operand | A value an operator works on (`2` and `3` in `2 + 3`) |
| Binary / unary operator | Takes two operands (`a + b`) / one (`-x`) |
| Precedence | Which operator binds first (`*` before `+`) |
| Associativity | Same-precedence tie-break: left-to-right for `+ - * / %` |
| Integer division | `int / int` → `int`; fraction truncated toward zero |
| Truncation | Discarding the fraction (`7/2 → 3`, `-7/2 → -3`) — NOT rounding |
| Modulo `%` | Remainder of integer division; sign follows the dividend |
| Expression tree | A diagram showing which operation happens when |
| Parenthesization | Explicit grouping that overrides precedence |

## Syntax and C++ examples

```cpp
int a{17};
int b{5};
a + b      // 22      a - b      // 12
a * b      // 85      a / b      // 3   (int / int!)
a % b      // 2       -a         // -17 (unary minus)
a / 2.0    // 8.5     (one double promotes the division)
(a + b) * 2   // 44   (parentheses first)
```

Precedence ladder (high → low): `()` → unary `-` → `* / %` → `+ -`.

## Line-by-line code explanation

`examples/precedence_demo.cpp` (each printed line is a prediction exercise
first):

1. `2 + 3 * 4` → 14 — `*` first. `(2 + 3) * 4` → 20 — parentheses override.
2. `20 / 2 * 5` → 50, not 2 — same tier, left-to-right: `(20/2)*5`.
3. `7 / 2` → 3 and `-7 / 2` → **-3**: truncation is toward zero. `7.0 / 2`
   → 3.5 — one double changes the whole division.
4. `7 % 2` → 1; `-7 % 2` → **-1**: the remainder takes the *dividend's*
   sign. (Standard C++ defines this since C++11; older quirks are history.)
5. Digit extraction: `927 % 10` → 7 (last digit); `927 / 10 % 10` → 2;
   `927 / 100` → 9. This pair (`% 10`, `/ 10`) returns in L09's digit-sum
   loop.
6. The average bugs: `a + b / 2` → 5 (precedence: `b/2` first);
   `(a + b) / 2` → 3 (truncation); `(a + b) / 2.0` → 3.5 (correct). Two
   different wrongs, one right — the exact trio on every midterm.

## Output prediction questions (with answers)

1. `10 + 4 / 2` — ? — `12` (division first).
2. `10 % 3` and `-10 % 3` — ? — `1` and `-1` (sign follows dividend).
3. `9 / 2 * 2` — ? — `8`, not 9 (`9/2` truncates to 4 first!).
4. `7 / 2.0 + 1` — ? — `4.5` (`7/2.0` is 3.5, then `+ 1` promotes to 4.5).
5. `static int` trick-free warm-up: `15 / 4` vs `15 % 4` — ? — `3` and `3`
   (quotient and remainder of the same division).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Average via `(a + b) / 2` | Whole-number averages only (3 instead of 3.5) | Divide by `2.0` (or cast) |
| Precedence bug `a + b / 2` | Slightly-off results, no diagnostic | Parenthesize: `(a + b) / 2.0` |
| Expecting `-7 / 2 == -4` | Off-by-one in symmetry checks | Truncation is toward zero |
| `n % 2` used for "is divisible by 3" | Logic error | `n % 3 == 0` |
| Modulo by zero | Runtime crash (integer division by zero) | Validate the divisor first |

## Common student misconceptions

- **"`%` works on floating-point numbers."** `%` is an integer operator
  in C++; for floating point there is `std::fmod` (show, don't require).
- **"Division by zero just gives 0 or an error message."** Integer
  division by zero is *undefined behavior* — the program may crash, lie,
  or appear fine; guard every divisor.
- **"My program computes `a/b` correctly for any two ints."** `/`
  truncates toward zero (e.g. `7 / 2` is `3`); many "wrong answer" bugs
  are silent truncation, not logic errors.
- **"Parentheses are only for readability."** They change the tree the
  compiler builds — `(2 + 3) * 4` vs `2 + 3 * 4` compute different
  values; precedence is about structure, not style.
- **"`-7 % 2` is 1."** In C++ the result of `%` has the sign of the
  *left* operand (`-7 % 2` is `-1`); students trained on other languages
  predict differently.

## Classroom demonstrations

1. **Predict-then-run:** reveal each printed line of `precedence_demo.cpp`
   one at a time; students commit answers before the line prints.
2. **Expression trees:** build the tree for `2 + 3 * 4 - 6 / 2` on the
   board step by step, then verify with the program.
3. **The digit machine:** type any 3-digit number; extract digits live with
   `/` and `%`, connecting L05 to the L09 loop.

## Guided student activities
**Predict-then-run tournament (20 min):** 12 expressions on slides; pairs
write predictions on whiteboards, then we run the program and score points;
every miss gets a 30-second why. The negative-`%` round is the guaranteed
upset.

## Practice problems
- Evaluate 10 expressions by hand (2 with unary minus, 3 mixed-type).
- Write digit-extractor for an arbitrary 4-digit input.
- Fix 3 broken average/percentage programs (precedence bug, truncation bug,
  both).
- (🟡 stretch) Compute minutes-and-seconds split of total seconds with one
  `/` and one `%`.

## Summary

C++ arithmetic follows precedence (`* / %` above `+ -`, left-to-right
within a tier), and parenthesization is the readable way to be explicit.
Integer division truncates toward zero; modulo gives the remainder with the
dividend's sign — and together they power digit extraction. The two average
bugs (precedence and truncation) are the canonical traps. Next (L06): what
happens when types *mix* — conversions, casts, and the increment family.

- "`%` gives the decimal part." (It's the *remainder* of integer division.)
- "`7/2` is 3.5 that gets rounded." (Truncation, not rounding; and it happens
  at *evaluation*, before any assignment.)
- "Precedence differences are just style." (They change the computed value.)
- "`-7/2` is -4." (Truncation toward zero: -3; floor is a different operator
  they'll meet in other languages.)

## Exit ticket / formative assessment

1. Evaluate: `17 % 5`, `-17 % 5`, `17 / 5`, `17.0 / 5`.
2. Insert one pair of parentheses to make `2 + 3 * 4` equal 20.
3. One sentence: when does `/` truncate?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (I/O quiz) + expressions-produce-values | 10 |
| Operator set + precedence with expression trees | 30 |
| Break | 10 |
| Integer division, `%` (incl. negatives), digit extraction | 35 |
| Predict-then-run tournament | 25 |
| Exit ticket + L06 preview | 10 |
