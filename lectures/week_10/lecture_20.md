# L20 · 2-D Operations: Row/Column Totals, Matrix Addition, Transpose, Passing to Functions

**Module 10 — Two-Dimensional Arrays · Week 10 · Lecture 20 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-10.3, PF-10.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 5 week · Assignment 3 due**

## Learning objectives

1. Implement row totals, column totals, matrix addition, and in-place
   transpose with correct loop bounds and destination indexing (PF-10.3).
2. Detect shape errors at design time: when transpose/addition are defined,
   and what "not square" breaks (PF-10.3).
3. Pass 2-D arrays to functions in fixed-column form
   (`void print(const int g[][COLS], int rows)`) and explain *why the column
   bound must be fixed* (PF-10.4).

## Prerequisites

L19 (2-D declaration, traversals); L13–L15 (functions, `const` reference
discipline).

## Concept sequence

1. From traversal to computation: per-row and per-column aggregation
2. Matrix addition: the shape precondition
3. Transpose: in-place (square only) vs into a new grid (any shape)
4. 2-D arrays as function parameters: the fixed-column rule
5. A small application: exam-seating score grid analytics
6. Lab 5 launch

## Teaching topics (detailed)

- **Row totals:** `row_sum[i]` accumulated in an inner loop (result array
  from M9); **column totals:** accumulate `col_sum[j] += g[i][j]` — the
  *column-wise* traversal from L19 finally earns its keep.
- **Matrix addition:** `c[i][j] = a[i][j] + b[i][j]` — defined only when
  shapes match; precondition check pattern (`if (ROWS_A != ROWS_B || ...)`)
  printed as error and early return.
- **Transpose:** `t[j][i] = g[i][j]` into a new grid (any shape); in-place
  swap `g[i][j] ↔ g[j][i]` for `j > i` (square only — why `j > i` prevents
  double-swapping: mini trace table); when each is right.
- **Function parameters:** `void print_grid(const int g[][COLS], int rows)`
  — rows passed separately, COLS fixed; the compiler needs the column bound
  to compute `r * COLS + c` offsets (connects to L19 linearization);
  multi-dimensional discipline for this course: fixed COLS + `const` + rows
  parameter.
- **Application worked end-to-end:** 5-student × 3-exam grid → per-student
  average (row), per-exam average (column), highest single score
  (aggregation trio) — the exact structure of Lab 5's tasks.

## C++ examples required

| File | Role |
|---|---|
| `matrix_ops.cpp` ✅ | row/col totals, addition with shape check, transpose (both forms) — each function ≤ 10 lines |
| (live) `score_grid.cpp` | the exam-analytics application assembled live from the matrix_ops pieces |

## Common student misconceptions

- "Transpose works in place on any grid." (In-place requires square;
  otherwise use a destination grid.)
- "`void f(int g[][], int rows)` is legal." (It is not — column bound
  required; show the exact compiler error.)
- "Column totals need a separate array-of-columns data structure." (Same
  grid, swapped loops.)
- "Matrix addition adds rows to columns." (Element-wise, shape-matched.)

## Conceptual explanation (beginner-first)

Last lecture you could *walk* a grid; today you *work* one. Three jobs
come up constantly: **aggregation** (one number per row, one per
column, one for the whole table), **element-wise combination** (add
matching cells of two grids), and **rearrangement** (transpose — the
rows become columns). Each is a nested loop with the output statement
placed at the right level: inside both loops (per cell), inside the
outer only (per row/column), or after all loops (single answer).

The transpose deserves special attention because it carries two
lessons. Conceptually, it maps `dst[c][r] = src[r][c]` — indices
swapped. Practically, it introduces the **in-place vs. copy**
distinction: transposing into a second grid is easy and safe, while
transposing in place is only possible for square grids and only works
every cell pair *once* (hence the inner loop starting at `i+1`).

Finally: a function that receives a 2-D array must declare the column
count — `void f(const int g[][COLS], int rows)` — because the compiler
uses the column width to compute each element's address (row-major,
from L19). The row count stays a free parameter.

## Terminology and definitions

| Term | Definition |
|---|---|
| Row total / column total | Sum across one row / down one column |
| Grand total | Sum of all elements (or of the row totals — same answer) |
| Element-wise operation | Matching cells combined: `c[i][j] = a[i][j] + b[i][j]` |
| Shape match | Both operands have identical rows × columns (precondition) |
| Precondition | What a function requires of its inputs (checked, then trusted) |
| Transpose (copy form) | `dst[c][r] = src[r][c]` into a new grid |
| Transpose (in-place) | Square grids only; swap `(i,j)` with `(j,i)` for `j > i` |
| Symmetric swap | Visiting each unordered pair once — the `j > i` condition |
| 2-D array parameter | `const int g[][COLS], int rows` — column bound mandatory |

## Syntax and C++ examples

```cpp
const int ROWS{3};
const int COLS{4};

// per-row total: accumulate inside the row, flush outside the inner loop
void rowTotals(const int g[][COLS], int rows, long long out[])
{
    for (int r{0}; r < rows; ++r)
    {
        long long total{0};
        for (int c{0}; c < COLS; ++c)
            total += g[r][c];
        out[r] = total;                  // per-ROW statement
    }
}

// element-wise addition with a shape precondition (here: same constants)
void addGrids(const int a[][COLS], const int b[][COLS], int sum[][COLS], int rows)
{
    for (int r{0}; r < rows; ++r)
        for (int c{0}; c < COLS; ++c)
            sum[r][c] = a[r][c] + b[r][c];
}

// transpose, copy form: indices swap, destination must be COLS x ROWS
void transposeCopy(const int src[][COLS], int dst[][ROWS], int rows)
{
    for (int r{0}; r < rows; ++r)
        for (int c{0}; c < COLS; ++c)
            dst[c][r] = src[r][c];
}

// transpose, in-place (square only): j > i visits each pair ONCE
void transposeInPlace(int sq[][3], int n)
{
    for (int i{0}; i < n; ++i)
        for (int j{i + 1}; j < n; ++j)
        {
            int tmp{sq[i][j]};
            sq[i][j] = sq[j][i];
            sq[j][i] = tmp;
        }
}
```

## Line-by-line code explanation

`examples/matrix_ops.cpp`:

1. `rowTotals` — the declaration `long long total{0};` sits *inside*
   the outer loop: fresh accumulator per row. Moving it outside is the
   classic wrong answer (rows 2 and 3 inherit row 1's total).
2. `out[r] = total;` — placed after the inner loop: the per-row
   statement. The placement ladder from L10 is now a design tool, not
   a formatting trick.
3. `addGrids` — element-wise; shape agreement is a precondition stated
   in a comment (same COLS constant, rows passed). Teaching point: the
   function cannot verify shapes it was never told; the *caller*
   carries that responsibility.
4. `transposeCopy` — `dst[c][r] = src[r][c]`; note the dst type is
   `[COLS][ROWS]`-shaped. In `transposeInPlace`, `j` starts at `i + 1`:
   strictly above the diagonal, so each pair swaps exactly once and a
   diagonal cell swaps with itself (i.e., not at all).

## Output prediction questions (with answers)

1. Grid `{{1,2,3},{4,5,6}}` — row totals? — `6` and `15`.
2. Same grid transposed — shape and contents? — 3×2 with rows
   `{1,4}`, `{2,5}`, `{3,6}`.
3. In-place transpose of a 4×4 run twice returns what? — the original
   grid; transpose is its own inverse (a nice self-check).
4. If `total` were declared outside the outer loop, row 2's total on
   `{{1,2},{3,4},{5,6}}` would be — ? — `6+7=13`, not 7 — accumulator
   placement bug made concrete.
5. `void f(int g[][], int rows)` — compiles? — **no**: the compiler
   needs the column bound to compute addresses (exact error message
   shown in the demo).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Accumulator outside the outer loop | Later rows include earlier rows' sums | Declare `total` inside the row loop |
| `int g[][]` parameter | Compile error: missing column bound | `const int g[][COLS], int rows` |
| Transposing non-square in place | Overwrites unread cells — data destroyed | Copy form, or square-only precondition |
| Inner loop from `j = 0` in-place | Double swap = no change (or corruption) | `j = i + 1` — each pair once |
| Adding grids of different shapes | Garbage cells / OOB reads | Shape precondition checked by caller |
| Row/col totals swapped | Totals are the wrong length | Outer loop selects which axis |

## Classroom demonstrations

1. **The inherited accumulator:** run the buggy version with `total`
   outside — watch row 2's number balloon; the placement rule lands.
2. **Transpose twice = identity:** transpose the same grid twice and
   print — students see the original return.
3. **Compiler as teacher:** type `int g[][]` live; read the error
   aloud; fix with `[][COLS]` — the "columns mandatory" rule is earned.

## Guided student activities
**Lab 5 (2 h, this lecture slot):** [labs/README.md](../../labs/README.md)
— grid analytics tasks: per-row/per-column aggregations, addition with
precondition checks, transpose (both forms), then the score-grid application.
Lecture hour 2 = lab launch + live build of `score_grid.cpp`.

## Practice problems

- Implement `col_totals` and `row_totals` for a 4×6 grid; annotate loop
  bounds.
- Matrix addition program with shape-mismatch error handling.
- In-place transpose of a 4×4 with a trace table of the swap sequence
  (proving `j > i` prevents double-swap).
- (🟡 stretch) Multiply a 2×3 by 3×2 matrix — defined shape, triple loop;
  justification that the inner dot-product loop is the M12 seed.

## Summary

Grid work is nested loops plus placement: per-cell, per-row/column, or
whole-table statements each live at their own level. Transpose remaps
indices; copy-form always works, in-place demands square symmetry with
the `j > i` discipline. 2-D parameters declare `[][COLS]` — the column
bound feeds the address arithmetic. Next (L21): strings as objects —
the friendlier face of text processing.

## Exit ticket / formative assessment

1. Write the full signature for a function that prints a `double g[3][5]`
   read-only.
2. Why does the column bound appear in the parameter but not the row bound?
3. Transpose condition: which pairs swap in an in-place 4×4 transpose?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (traversal quiz) + aggregation motivation | 10 |
| Row/col totals + addition + transpose | 35 |
| Break | 10 |
| 2-D parameters + score-grid application build | 35 |
| **Lab 5 launch** + supervised start | 20 |
| Assignment 3 hand-in + exit ticket | 10 |
