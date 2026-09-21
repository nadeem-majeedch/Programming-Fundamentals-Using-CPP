# L15 · Function Overloading, Default Arguments, and Reference Parameters

**Module 8 — Advanced Function Concepts · Week 8 · Lecture 15 of 32 · 120 minutes**
**Outcomes:** CLO-5 · PF-8.1, PF-8.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Create valid overloaded function sets (distinct parameter lists), predict
   which overload a call selects, and recognize ambiguity errors (PF-8.1).
2. Write functions with default arguments and state the two rules (defaults
   rightmost; declaration-only) (PF-8.1).
3. Implement reference parameters (`T&`, `const T&`) for genuine
   multiple-output patterns (swap, min/max pair, statistics bundle) and
   justify value vs `const T&` vs `T&` for a given parameter (PF-8.2).

## Prerequisites

L13–L14 (copy semantics, scope); L07 (booleans for overload selection
examples).

## Concept sequence

1. One job, many shapes: why overloading exists
2. Overload resolution: the compiler's matching rules
3. Ambiguity: when the compiler refuses to choose
4. Default arguments: rightmost rule, declaration placement
5. References as parameters: the alias model
6. The output-parameter pattern + `const T&` for big inputs

## Teaching topics (detailed)

- **Overloading:** same name, different parameter *lists* (count or types —
  return type alone never distinguishes); resolution walk-through for
  `print(int)`, `print(double)`, `print(const std::string&)` with calls
  `print(3)`, `print(3.0)`, `print('x')` (char → int! — teachable surprise).
- **Ambiguity:** `f(int)` + `f(double)` called with `f(3.5f)`; exact-match
  vs promotion tiers shown as a ladder; compiler error read live.
- **Default arguments:** `double power(double base, int exp = 2);` —
  rightmost-only rule; defaults declared in the prototype once; interaction
  with overloads (when two functions become viable — avoid the design).
- **Reference parameters:** `void swap(int& a, int& b);` — alias, not copy;
  the L13 failed-swap fixed; diagram of the two names pointing at one box;
  `const T&` read-only contract (why big structs/strings want it — full
  payoff in M14); course rule: `T&` only for values the caller *wants
  written back*.
- **Multi-output patterns:** min-max finder with two outputs; stats bundle
  (sum, avg, count) — contrast with "return one value" from L13; when
  `struct` (M14) will replace output-parameter lists (honest forward
  pointer).

## C++ examples required

| File | Role |
|---|---|
| `overload_ref_demo.cpp` ✅ | overloaded `print` set with resolution prints; working swap; min-max output pattern; an intentionally ambiguous call (commented) |
| (live) `stats_outparams.cpp` | statistics function with 3 output references, called with pre-declared result variables |

## Common student misconceptions

- "Overloading = same function called flexibly." (They are *distinct*
  functions that share a name; resolution is at compile time.)
- "Return type can distinguish overloads." (It cannot — parameter list
  only.)
- "References pass the variable's *address* around freely." (Conceptually an
  alias; no pointer syntax appears — pointers are M13.)
- "`const T&` is just decoration." (It's a contract: caller knows nothing
  changes; enables passing big objects cheaply.)

## Conceptual explanation (beginner-first)

Week 7's functions processed a *row* of numbers. But much data is a
*table*: rows of students, columns of test scores; a chessboard; an
image's pixels. A two-dimensional array is literally "an array of
arrays" — `int grid[3][4]` is 3 rows, each with 4 columns, stored row
by row in memory. We process tables with **nested loops** from week 5:
the outer loop steps through rows, the inner loop through columns.

Two new skills matter here. First, **parameter passing**: a 2D array
parameter must declare the column count (`int g[][4]`), because the
compiler needs to know how wide each row is to compute addresses —
the row count stays free. Second, **aggregation**: the most common real
jobs are totals per row, totals per column, and grand totals — each is
a small loop pattern placed at the right nesting level.

## Terminology and definitions

| Term | Definition |
|---|---|
| Two-dimensional array | `T name[rows][cols]` — a table of rows × columns elements |
| Row-major storage | Rows stored one after another in memory |
| 2D array parameter | `T g[][cols]` — column count required, row count free |
| Row sum / column sum | Total across one row / down one column |
| Grand total | Sum over all elements |
| Aggregation | Reducing many values to one (sum, max, count) |
| Indexing | `g[row][col]` — row first, then column |

## Syntax and C++ examples

```cpp
const int ROWS{3};
const int COLS{4};

int grid[ROWS][COLS] =
{
    { 1,  2,  3,  4},
    { 5,  6,  7,  8},
    { 9, 10, 11, 12}
};

// column count mandatory; row count free — the compiler needs the width
long long rowSum(const int g[][COLS], int rows, int r)
{
    long long total{0};
    for (int c{0}; c < COLS; ++c)
        total += g[r][c];
    return total;
}

// grand total — nested loops, the week-5 pattern returns
long long grandTotal(const int g[][COLS], int rows)
{
    long long total{0};
    for (int r{0}; r < rows; ++r)
        for (int c{0}; c < COLS; ++c)
            total += g[r][c];
    return total;
}
```

## Line-by-line code explanation

`examples/matrix_ops.cpp`:

1. The matrix is initialized with a brace list of brace lists — each
   inner list is one row.
2. `printMatrix(const int m[][COLS], int rows)` — outer loop rows, inner
   loop columns, `\t` between cells, `\n` after each row: the placement
   rules from the triangle exercise, now printing data instead of stars.
3. `rowSums(...)` fills an output 1D array: for each row, sums across,
   stores into `sums[r]`. A 2D-in, 1D-out function — the workhorse shape
   of data processing.
4. `transpose(...)` writes `dst[c][r] = src[r][c]` — swapping the
   indices mirrors the table across its diagonal.

## Output prediction questions (with answers)

1. `int a[2][3]{{1,2,3},{4,5,6}};` — what is `a[1][0]`? — 4.
2. For that `a`, `rowSum(a, 2, 0)` — ? — 6.
3. Grand total of `a` — ? — 21.
4. After transpose, the element at `[0][2]` came from — ? — `[2][0]` of
   the original.
5. A function declares `int g[3][]` (rows fixed, columns blank) — why
   does it not compile? — the compiler needs the column stride to compute
   element addresses; rows are the free dimension.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| `int g[3][]` in a parameter | Compile error: missing column bound | `int g[][COLS]` |
| Swapped `[row][col]` | Data lands in the wrong cell | Say "row first" aloud while writing |
| `<=` in a row/col loop | Reads past the row into the next | `c < COLS`, `r < rows` |
| Row sum inside the inner loop | Resets/accumulates wrongly | Accumulate per row, store after inner loop |
| Flat initializer mismatch | Zeros fill the gaps silently | Brace one inner list per row |

## Classroom demonstrations

1. **Spreadsheet on the board:** draw the 3×4 grid with indices on both
   axes; students call out `g[r][c]` values as you point.
2. **Row-major reveal:** print the six bytes of a small `char` grid with
   addresses — memory shows the rows lying end to end.
3. **Transpose theater:** write the matrix on paper, fold along the
   diagonal — the indices swap visually.

## Guided student activities

1. **Row/column sum trio:** in pairs, write `rowSum`, `colSum`, and
   `grandTotal`; test all three on a 2×2 matrix where the answers are
   obvious.
2. **Largest per row:** extend `rowSums` to `rowMaxes` — seed with the
   row's first element (the L11 lesson, reused).
3. **Trace the transpose:** hand-trace `transpose` on a 2×3 input; the
   output is 3×2 — verify against the program.

## Practice problems

- Implement `rowSum`, `colSum`, and `grandTotal`; test on a 2×2 where
  answers are hand-computable.
- Write `rowMaxes` (largest per row) — seed with the row's first element
  (the all-negative edge case from L11).
- Transpose a 2×3 into a 3×2 destination; print before/after.
- (🞡 stretch) Find the largest per *column* — which loop nesting changes?

## Summary

A 2D array is an array of arrays: `g[r][c]`, row-major in memory, and
as a parameter it needs `int g[][COLS]` — columns fixed, rows free.
Nested loops walk the table; totals per row, per column, and overall
are the same aggregation patterns from week 5 wearing table clothes.
Next (L16): the midterm — everything through two-dimensional arrays.

## Exit ticket / formative assessment

1. Declare a 2×5 table of `double` named `rates` and initialize both
   rows explicitly.
2. Write the full header of `colSum(const int g[][COLS], int rows, int
   c)` returning `long long`.
3. Why must the column count appear in a 2D array parameter but not the
   row count?

1. `print('A')` with `print(int)` and `print(double)` overloads — which runs?
2. Two rules for default arguments?
3. Mark each as value / `const T&` / `T&`: (a) 1000-element vector to
   search; (b) result collector; (c) small int input.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (scope quiz) + why overloading | 10 |
| Overload resolution + ambiguity ladder | 30 |
| Break | 10 |
| Default args + reference parameters + output patterns | 40 |
| Resolution court activity | 20 |
| Exit ticket + midterm preview | 10 |
