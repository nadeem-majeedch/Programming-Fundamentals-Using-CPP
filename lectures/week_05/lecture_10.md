# L10 · `for`, Nested Loops, `break`/`continue`, and Loop Patterns

**Module 5 — Loops and Repetition · Week 5 · Lecture 10 of 32 · 120 minutes**
**Outcomes:** CLO-3 · PF-5.3, PF-5.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Quiz 1 (Modules 1–4)**

## Learning objectives

1. Write `for` loops for counted iteration (including step ≠ 1, downward
   counting, and accumulation), mapping `for` headers onto the
   init/test/update discipline from L09 (PF-5.3).
2. Build nested loops producing tables, shapes, and pair enumerations, and
   trace their total iteration counts (PF-5.3).
3. Predict `break`/`continue` behavior in single and nested loops, and
   select the right pattern — accumulate, search, validate, enumerate pairs —
   for a task (PF-5.4).

## Prerequisites

L09 (while/do-while, trace tables, accumulator patterns).

## Concept sequence

1. `for` as packaged loop discipline (init; test; update in one line)
2. Counting variants: downward, step-2, character loops
3. Accumulator patterns in `for` form
4. Nested loops: tables, rectangles/triangles, all-pairs
5. `break`/`continue` semantics (+ the nested-loop caveat)
6. The pattern catalogue (naming the reusable shapes)

## Teaching topics (detailed)

- **`for` equivalence:** `for (int i{0}; i < n; ++i)` ≡ the while form;
  scope rule: `i` exists *inside* the loop only (demo of the after-loop
  compile error and why it's a feature); prefer `for` when the count is
  known, `while` when it isn't.
- **Counted variants:** `for (int i{n}; i > 0; --i)`, step-2, `for (char c{'a'}; c <= 'e'; ++c)`.
- **Nested loops:** iteration-count arithmetic (outer n × inner m);
  multiplication table; right-triangle of stars (outer rows, inner columns
  depend on row — the key generalization); all-pairs comparison
  (`for i, for j>i`).
- **`break`/`continue`:** exits nearest loop / skips to next iteration;
  demo of the "break exits inner only" surprise; course style: allowed for
  search loops and input handling, sparingly elsewhere.
- **Pattern catalogue (named for reuse in M9–M12):** ACCUMULATE, COUNT-IF,
  FIND-FIRST (with `break`), VALIDATE-EVERY (with early `false`), ENUMERATE
  PAIRS, TABLE RENDER. Each gets a 5-line skeleton.

## C++ examples required

| File | Role |
|---|---|
| `loop_patterns.cpp` ✅ | all six named patterns as runnable mini-demos with printed traces |
| (live) `shapes_nested.cpp` | square → triangle → pyramid progression of nested loops |

## Common student misconceptions

- "`for` and `while` are different kinds of loops." (Same semantics,
  different packaging; any `for` can be rewritten as `while`.)
- "`break` exits all loops." (Nearest enclosing loop only — the classic
  nested-loop surprise.)
- "Nested loop bodies always run n × m times." (Only when the inner count is
  independent of the outer variable — triangle shows dependence.)
- "`continue` restarts the whole loop including initialization." (It jumps to
  the update/test, not the init.)

## Conceptual explanation (beginner-first)

One loop repeats a single pass of work. But many problems are grids:
a multiplication table needs every (row, column) pair; a class photo
needs every (row, seat). The answer is **a loop inside a loop**. The
outer loop picks a row; the inner loop sweeps across every column of
that row; then the outer loop advances. The key mental model: **for
each pass of the outer loop, the inner loop runs completely**.

Nested loops also give the first honest answer to "how slow is my
program?" If the outer runs *n* times and the inner runs *n* times for
each outer pass, the body runs n×n = n² times. Compare a *n* line with
a *n²* line: for n = 1,000 that's 1,000 steps versus 1,000,000. Doubling
n doubles linear work but quadruples quadratic work. That intuition —
**growth rate, not stopwatch seconds** — is what computer scientists
call algorithmic complexity, and this lecture builds it by counting,
not by memorizing notation.

## Terminology and definitions

| Term | Definition |
|---|---|
| Nested loop | A loop inside the body of another loop |
| Outer / inner loop | The enclosing / enclosed loop; inner runs fully per outer pass |
| n² (quadratic) growth | Work grows with the square of input size |
| Linear growth | Work grows in step with input size |
| Growth rate | How work scales as n grows — independent of machine speed |
| Statement count | Number of executed statements — the concrete way to count work |
| Loop invariant (nested) | A claim true before every pass of *either* loop |
| Pair enumeration | Visiting all (i, j) combinations — the job nested loops do |

## Syntax and C++ examples

```cpp
// the canonical nested loop: every (row, col) pair
for (int row{1}; row <= 3; ++row)
{
    for (int col{1}; col <= 4; ++col)
    {
        std::cout << row * col << '\t';   // inner body: 3 × 4 = 12 times
    }
    std::cout << '\n';                    // newline ONCE per row
}

// right triangle: row r prints r stars
for (int r{1}; r <= n; ++r)
{
    for (int s{1}; s <= r; ++s)          // inner bound DEPENDS on r
    {
        std::cout << '*';
    }
    std::cout << '\n';
}

// counting statements: this double loop runs n² times
for (int i{0}; i < n; ++i)
    for (int j{0}; j < n; ++j)
        ++steps;                          // executed n × n times total
```

## Line-by-line code explanation

`examples/loop_patterns.cpp` (nested section, revisited from L09):

1. The outer `for` chooses the row; its body contains *two* statements:
   the inner `for` and the row's final `std::cout << '\n'`.
2. The inner `for` runs its whole sweep — every column — for that one
   row, *then* control returns to the outer loop's update.
3. The newline is outside the inner loop but inside the outer: placement
   of statements relative to the loops determines output shape. Moving it
   one line up flattens the triangle into one long line.

`examples/grid_basics.cpp` (used again here for its multiplication-table
section):

1. Row and column indices both start at 1 (not 0) so the table reads
   naturally — indices are a design choice, not a law.
2. `row * col` fills each cell; the `\t` aligns columns, the `\n` closes
   rows.
3. Predict-then-run: students write the output grid before compiling.

## Output prediction questions (with answers)

1. Outer 1..3, inner 1..3, body prints `i*j` — how many body executions?
   — 9; the 3×3 table's cell count.
2. Triangle with n = 4 — how many stars total? — 1+2+3+4 = 10.
3. If the body prints and inner/outer both run 1..n, moving the newline
   inside the inner loop — ? — every number on its own line (no rows).
4. n = 1000 in an n² loop: roughly how many body executions? — one
   million; state it before computing it.
5. Doubling n from 500 to 1000 in an n² loop multiplies work by — ? —
   four; in a linear loop, two.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Same name for both loop variables | Inner reuses/reshadows `i` — chaos | `i` outer, `j` inner, always |
| Newline in the wrong loop | Output on one line, or one number per line | Ask "per cell or per row?" and place accordingly |
| Inner bound not reset | (Rare in C++ — for-loop scoping prevents it; a classic in languages with loop variables) | Declare inner counters in the inner `for` |
| Off-by-one in inner bound | Missing or extra column per row | Trace one row by hand |
| Accidental n³ | A third loop added thoughtlessly | Count the nesting depth — it multiplies |

## Classroom demonstrations

1. **Table on the board:** for outer 1..3 × inner 1..3, list the nine
   (i, j) pairs in execution order — students see i change slowly, j
   quickly.
2. **Break the triangle:** move the `\n` line-by-line (inside inner, at
   outer level, outside everything) and run each — placement is visual.
3. **Count-to-a-million:** have the class count the n² body executions
   for n = 1000 out loud, then compare with a linear loop's 1000 — the
   gap is the lesson.

## Guided student activities

**Human loops (15 min):** students execute a counted loop physically —
counter card passed with each iteration; then a sentinel loop with a
student sentry who refuses `0`; finally the off-by-one version misses the
last pass and the class must fix the condition.

## Practice problems

- Trace tables for 5 loops (mix of while/for, incl. one sentinel).
- Write: multiplication-table printer (nested); sum-until-sentinel;
  do-while menu skeleton.
- Find and fix the 3 seeded bugs in `buggy_off_by_one.cpp` by trace first.
- (🞡 stretch) Convert a given for-loop into an equivalent while-loop and
  argue which reads better.

## Summary

Nested loops enumerate combinations: outer picks the row, inner sweeps
the columns, and the body runs (outer count) × (inner count) times.
Statement placement — especially the newline — shapes the output. The
same counting gives complexity intuition: linear work scales with n,
nested work with n², and doubling the input multiplies work by 2 or by
4. Next (L11): week 6 turns from writing loops into *designing* —
problem-solving and algorithm design.

## Exit ticket / formative assessment

1. Write the nested loop printing a 4×6 rectangle of `#` characters.
2. A nested loop with outer bound n and inner bound n runs its body how
   many times? In growth-rate words?
3. Where does the `\n` go to make each row of the triangle appear on its
   own line, and why exactly there?

1. `for (int i{0}; i < 4; ++i) for (int j{0}; j < i; ++j) ++k;` — final `k`?
2. In a nested loop, `break` exits __________.
3. Which pattern fits: "print the first student below 40, then stop"?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (while quiz) + `for` packaging | 10 |
| Counted variants + accumulators | 25 |
| **Quiz 1 (Modules 1–4, 15 min, closed book)** | 15 |
| Break | 10 |
| Nested loops + shapes + break/continue | 30 |
| Pattern relay + exit ticket | 30 |
