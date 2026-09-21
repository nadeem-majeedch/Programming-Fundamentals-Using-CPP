# L09 · `while` and `do-while`: Sentinel and Input-Controlled Loops

**Module 5 — Loops and Repetition · Week 5 · Lecture 9 of 32 · 120 minutes**
**Outcomes:** CLO-3 · PF-5.1, PF-5.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Write `while` loops with all three loop parts present and correct —
   initialization before, condition at top, update inside — and diagnose
   which part is missing when a loop misbehaves (PF-5.1).
2. Build sentinel-controlled (e.g. `-1` stops) and count-controlled loops,
   and distinguish *sentinel* from *valid data* (PF-5.1).
3. Implement `do-while` post-test loops for input validation and menus, and
   state exactly when post-test is the right choice (PF-5.2).

## Prerequisites

L07–L08 (conditions, menu structure); L04 (stream-state reading — sentinels
ride on it).

## Concept sequence

1. The problem: repeating statements without copy-paste
2. `while` anatomy: init / test / update discipline
3. Trace tables for loops (state before each test)
4. Sentinel-controlled input loops
5. `do-while`: test-at-bottom, run-at-least-once
6. Input-validation idiom with `do-while`

## Teaching topics (detailed)

- **Loop discipline:** every loop must (1) initialize, (2) test, (3) update;
  the three classic failures: infinite (no update / never-false test),
  never-runs (init off), one-off (update misplaced).
- **Trace tables:** columns = variables, rows = passes; first big practice
  with `sum += i` style loops; desk-checking formalized (full treatment in
  Module 6).
- **Sentinel loops:** `while (mark != -1)` — read-then-check structure;
  "priming read" pattern; why sentinel must be impossible data; connection
  to stream-state checks (`while (cin >> x)` idiom introduced here, formal
  treatment in Module 15).
- **`do-while`:** post-test; menus and re-prompt validators
  (`do { ... } while (choice != 'q');`); warn: no `do-while` when zero
  iterations must be possible.
- **Accumulators & counters:** `sum`, `count`, `product` initialization
  rules (0/0/1) — the pattern vocabulary used in every later module.

## C++ examples required

| File | Role |
|---|---|
| `loops_sum_digits.cpp` ✅ | sentinel sum loop + digit-sum via `% 10` / `/ 10` inside `while` (ties to L05 digit extraction) |
| (live) `validation_loop.cpp` | `do-while` re-prompt validator with `clear()`/`ignore()` recovery |

## Common student misconceptions

- "The loop condition checks *after* the body." (Pre-test for `while` —
  body may run zero times; that's why `do-while` exists.)
- "Sentinel values are just any negative number." (Must be *impossible* for
  the data domain — a `-1` temperature is valid in some places!)
- "While loops always update at the bottom." (Update placement *is* the bug
  source; placement is a design decision.)
- "`do-while` runs at least twice."

## Conceptual explanation (beginner-first)

A **loop** is the program's way of repeating work without repeating text.
When we needed three numbers summed, writing `cin >> a; ... >> b; ... >> c;`
worked — but summing a thousand would need a thousand lines. Instead, we
keep *one* variable and let the computer do the repetition, updating that
variable each time around. Every loop answers three questions: **what to
repeat** (the body), **whether to go again** (the condition), and **what
changes between attempts** (the update — in a `for`, the third clause).
Forgetting the update is the classic bug: the condition never changes, so
the loop never ends.

The three loop forms are one idea with different emphasis. `while` asks
the condition *before* each attempt — good when you don't know how many
times (reading until EOF or a sentinel). `do-while` asks *after* — good
for menus that must show at least once. `for` bundles initialization,
condition, and update into one readable line — good when the count is
known or when an index marches across a range. Choosing the wrong form
rarely breaks the program; choosing it well makes the intent obvious.

Loop design has a discipline: state the **loop invariant** — what is true
before every pass — then make sure initialization establishes it, the
body maintains it, and after the loop the job is done. "`sum` holds the
total of all values seen so far" is the invariant of the sum loop. When a
loop goes wrong, trace it: a table of every variable, updated line by
line, and the bug is usually visible by row three.

## Terminology and definitions

| Term | Definition |
|---|---|
| Loop | A construct that repeats a block while a condition holds |
| Iteration | One execution of the loop body |
| Loop condition | The bool expression checked each pass; false ends the loop |
| Loop variable / counter | The variable the condition watches and the update advances |
| Update (third clause) | Code run after each pass; omitting it is the #1 bug |
| Initialization (first clause) | Run once before the first condition check |
| Infinite loop | A loop whose condition never becomes false |
| Off-by-one error | Loop runs one time too many or too few (the `<= n` vs `< n` trap) |
| Sentinel value | A special input marking "stop reading" (e.g. 0, or -1) |
| Input as the condition | `(std::cin >> x)` is a bool: true when a value was read |
| Loop invariant | A statement true before every iteration; the backbone of correct loop design |
| Dry run / trace | Step-by-step table of variable values — the debugging skill of the week |

## Syntax and C++ examples

```cpp
// for — known count, everything in one line
for (int i{0}; i < 5; ++i)
{
    std::cout << i << ' ';              // 0 1 2 3 4
}

// while — repeat until a condition fails; check happens FIRST
int n{};
std::cin >> n;
while (n > 0)                            // condition before every pass
{
    std::cout << n << ' ';
    --n;                                 // the update — forget it = infinite loop
}

// do-while — body runs at least once; check happens AFTER the body
char again{};
do
{
    std::cout << "again? ";
    std::cin >> again;
} while (again == 'y');

// sentinel-controlled reading — the input itself ends the loop
int value{};
long long total{0};
while (std::cin >> value && value != 0)  // stop at 0 OR on bad input
{
    total += value;
}

// sum of digits — while's natural shape: unknown pass count
int m{1234};
int digitSum{0};
while (m > 0)
{
    digitSum += m % 10;                  // take the last digit
    m /= 10;                             // drop it
}
// digitSum == 10
```

## Line-by-line code explanation

`examples/loops_sum_digits.cpp`:

1. `std::cin >> number` — reads the value whose digits will be summed.
2. **Input validation loop** (before the main loop): re-prompts until the
   user actually supplies an integer — the `(std::cin >> x)` condition is
   the reading pattern from L04, now reused as a gate.
3. `int work{number};` — a copy of the input is destroyed digit by digit;
   keeping the original intact is deliberate (good practice: don't eat
   your inputs).
4. `while (work > 0)` — invariant: `digitSum` equals the sum of digits
   removed so far; `work` still holds the digits not yet removed.
5. `digitSum += work % 10;` — `% 10` isolates the last digit (1234 % 10
   = 4).
6. `work /= 10;` — integer division drops that digit (1234 / 10 = 123).
7. After the loop, `work == 0` and `digitSum` is the complete answer — the
   invariant plus the exit condition *is* the proof of correctness.

`examples/loop_patterns.cpp` — four labeled patterns, each one small:
counting (`for` with a counter), accumulation (`sum += value`),
max-finding (track the best so far, initialize with the first value), and
a nested `for` printing a right triangle — rows outer, columns inner.

`examples/buggy_off_by_one.cpp`:

1. **Bug 1 (infinite loop)** — a `while` with no update inside; watch the
   terminal fill, then Ctrl+C.
2. **Bug 2 (off-by-one)** — `for (int i{1}; i <= n; ++i)` used where the
   array-style 0..n-1 range was intended: runs n times but with the wrong
   values, or n+1 times where the caller assumed n.
3. Each bug is commented; students predict the symptom, run, compare.

## Output prediction questions (with answers)

1. `for (int i{0}; i < 3; ++i) cout << i;` — ? — `012`.
2. Same loop with `i <= 3` — ? — `0123` — the off-by-one is visible in
   the last value printed.
3. `int x{3}; while (x > 0) cout << x;` (no update) — ? — `333...`
   forever — Ctrl+C is the lesson.
4. Sum-digits of 907 — ? — 16 (9+0+7); the 0 digit contributes nothing
   but the loop still processes a full pass on `work == 90`.
5. Sentinel loop with input `4 7 0` — how many values summed, what total?
   — 2 values, total 11; the 0 is the sentinel, never added.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Missing update | Program hangs (infinite loop) | Advance the watched variable every pass |
| `i <= n` instead of `< n` | One extra iteration | Decide the range, match the bound to it |
| Body of `while` on one line without braces | Only the first statement repeats | Braces around every body |
| `for(;;)` left in by accident | Hangs | Every `for` clause earns its place |
| Updating the counter twice | Skips values | One update, in the third clause |
| Sentinel chosen badly | A legitimate value (e.g. 0) terminates early | Pick a value outside the data domain, or use EOF |

Debugging ritual: **print and trace** — add a `std::cout` of every
relevant variable inside the loop, run a tiny input, read the table row
by row against the invariant. The first row that breaks the invariant
circles the bug.

## Classroom demonstrations

1. **Live trace:** run `loops_sum_digits` on 907 with the trace table on
   the board — pass, work, digit, digitSum — and have the class call out
   each row.
2. **The infinite loop, safely:** run the no-update `while`, let it fill
   a few lines, then Ctrl+C — naming the symptom before fixing it.
3. **Sentinel theater:** feed the sum loop `10 20 30 0` then `10 20 0 30`
   — same digits, different totals; students explain why before you say
   it.

## Guided student activities

**Loop-autopsy pairs (20 min):** 6 broken loops (infinite, off-by-one,
skipped-body, wrong sentinel, missing update, inverted condition); pairs
diagnose by *trace table only* — no running allowed — then we run and
compare. Diagnosis-before-execution is the point.

## Practice problems

- Complete 5 partial trace tables for `while` loops.
- Write: sentinel grade-averager; count-down timer; `do-while` age validator
  (3–120 range with recovery).
- Convert 2 `while` loops to `do-while` (and one where it's *wrong* —
  justify).
- (🞡 stretch) Digit reversal with `while` (foreshadows palindrome, M11).

## Summary

Loops repeat work: `while` checks first (unknown count), `do-while`
checks last (must-run-once menus), `for` bundles init/condition/update
(known counts and marching indices). The four classic bugs — missing
update, off-by-one, wrong bound, missing braces — are all caught by one
habit: trace the loop with a variable table against its invariant.
Next (L10): composing loops — nested iteration, the patterns that turn
loops into real algorithms, and the first honest look at running time.

## Exit ticket / formative assessment

1. Write a `for` loop printing 10 down to 1, each on its own line.
2. What two things are missing from `while (n != 0) { ... }` if the body
   never changes `n`?
3. Trace `while (m > 0) { d += m % 10; m /= 10; }` for `m = 47`: give the
   table (m, d) for each pass and the final value of `d`.

1. A `while` loop never ends. Name the two most likely missing parts.
2. How many times does a `do-while` body run at minimum?
3. Trace: `int i{1}, s{0}; while (i <= 3) { s += i; ++i; }` — final `s`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (switch quiz) + repetition motivation | 10 |
| `while` discipline + trace tables | 35 |
| Break | 10 |
| Sentinels + `do-while` + validation idiom | 35 |
| Loop-autopsy activity | 20 |
| Exit ticket + L10 preview | 10 |
