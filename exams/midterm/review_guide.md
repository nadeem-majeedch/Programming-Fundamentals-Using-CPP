# Midterm Review Guide — Weeks 1–8 (L01–L16)

**Exam format:** 100 minutes · 50 marks. Conceptual ≈ 40 %, applied ≈ 60 %.
Question shapes: MCQ, output tracing, debugging, short conceptual, algorithm
design (IPO/decision tables), coding, code completion. A closed-book paper —
no compiler, so *practice writing code by hand*.

## What to be fluent in

| Module | Must-have skills | Practice from |
|---|---|---|
| M1 · Intro & toolchain | 4 translation stages; error classes (syntax/runtime/logic) | Quiz 01, L01–L02 notes |
| M2 · Variables & I/O | brace init vs narrowing; `cin >>` whitespace rules; `fixed`/`setprecision` | Quiz 02, exercises T01 |
| M3 · Operators | precedence, integer division vs `%`, cast for averages | Quiz 03, `examples/precedence_demo.cpp` |
| M4 · Decisions | ladder ordering, switch fall-through, short-circuit guards | Quiz 04, exercises T02 |
| M5 · Loops | for/while/do-while boundaries; priming read; missing-update class | Quiz 05, exercises T03 |
| M6 · Problem solving | IPO charts, trace tables, boundary test sets, decomposition | Quiz 06, case studies Tier 1–2 |
| M7 · Functions | prototypes, pass-by-value vs reference, contracts, overloading | Quiz 07, exercises T05 |
| M8 · Advanced functions | recursion base cases, scope/shadowing, default arguments | Quiz 08, `examples/recursion_towers.cpp` |

## Hand-trace drills (answers at the week's lecture notes)

1. `int s{0}; for (int i{1}; i <= 3; ++i) s += i * i;` → ?
2. `int n{25}, c{0}; while (n > 0) { n /= 2; ++c; }` → c?
3. `int g(int n){ return n <= 0 ? 0 : n + g(n - 2); }` — g(7)?
4. `void tweak(int a, int& b){ ++a; ++b; }` with p = q = 4 → p, q?

## Debugging patterns to recognize

- Shadowed accumulator (redeclared inside the loop).
- Missing loop update (sentinel never re-read).
- Integer division where a mean was intended.
- Missing recursion base case.
- `>=` vs `>` boundary off-by-one.
- Fall-through `switch` without `break`.

## Coding practice set (closed-book)

1. Temperature C→F with input validation, 1 decimal.
2. Median of three integers.
3. Sentinel-0 stats: count, sum, mean (2 dp) or `no data`.
4. `bool isPerfect(int n)` + all perfect numbers ≤ 10000.

## Exam technique

- Trace questions: write the variable table, not just the answer.
- Coding questions: a correct skeleton with one small defect earns most marks — always declare, read, compute, print in that order and validate the read.
- Budget: ≈ 2 minutes per MCQ-block item, 15 minutes per coding item.

See also [../final/review_guide.md](../final/review_guide.md) after Week 8.
