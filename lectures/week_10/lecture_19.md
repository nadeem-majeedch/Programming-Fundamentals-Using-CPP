# L19 · 2-D Arrays: Declaration, Row/Column Indexing, Nested Traversal

**Module 10 — Two-Dimensional Arrays · Week 10 · Lecture 19 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-10.1, PF-10.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Declare, initialize, and index 2-D arrays with row/column addressing
   `a[r][c]`, and explain row-major memory layout with a linearized address
   diagram (PF-10.1).
2. Implement the four traversal patterns — row-wise, column-wise, diagonal,
   boundary — with correct loop bounds and nesting order (PF-10.2).
3. Predict output of 2-D traversal programs by annotating row/column
   iteration tables (PF-10.2).

## Prerequisites

M9 (1-D arrays, traversal discipline); L10 (nested loops, iteration-count
arithmetic).

## Concept sequence

1. From lists to tables: the grid motivation (seating chart, spreadsheet)
2. Declaration + row/column indexing (`a[2][3]` — row 2, column 3)
3. Row-major memory layout: the grid is a *view* over a linear array
4. Row-wise traversal (outer = rows, inner = columns) and its transpose
5. Diagonal and boundary traversals
6. Initialization forms for 2-D arrays

## Teaching topics (detailed)

- **Declaration/semantics:** `int grid[3][4];` — 3 rows × 4 columns = 12
  contiguous ints; row-major linearization: element `[r][c]` lives at
  offset `r * COLS + c` (COLS as `const int`); address arithmetic demo
  printing `&grid[r][c]` to *show* the linear layout (foreshadows M13
  pointer arithmetic).
- **Indexing discipline:** rows then columns (`a[row][col]`, never
  `a[col][row]` by accident); valid ranges `0..ROWS-1`, `0..COLS-1`; non-
  square grids as the classic source of transposed bugs.
- **Row-major traversal:** `for r: for c:` — cache-friendly order (brief
  practical note); column-wise swaps the loops; when each is needed (row
  totals vs column totals — L20's lab).
- **Diagonal traversal:** `a[i][i]` (main), `a[i][N-1-i]` (anti-diagonal) —
  square-grid only; boundary: first/last row full, first/last column
  excluding corners (the fence-post corners discussion).
- **Initialization:** `int g[2][3] = {{1,2,3},{4,5,6}};` and the flattened
  form `{1,2,3,4,5,6}` (legal, unreadable — style verdict); `int g[2][3]{}`
  zeroed.

## C++ examples required

| File | Role |
|---|---|
| `grid_basics.cpp` ✅ | declare/init a 3×4 grid; row-wise and column-wise prints; addresses showing row-major layout |
| (live) `traversal_patterns.cpp` | diagonal sum + boundary sum with loop-bound walk-through |

## Common student misconceptions

- "`a[2][3]` means 2 columns × 3 rows." (Rows first: row 2, col 3.)
- "A 2-D array is an array of pointers to rows." (One contiguous block;
  row-major offset arithmetic — pointer-of-arrays is a different construct
  not taught.)
- "`a[i][j]` and `a[j][i]` are interchangeable for square grids." (Only if
  the grid is square *and* the operation is symmetric.)
- "Column-wise traversal needs different syntax." (Same `[][]`; only the
  loop nesting order changes.)

## Conceptual explanation (beginner-first)

A one-dimensional array is a row of boxes. A two-dimensional array is a
*sheet* of boxes — like graph paper. `int grid[3][4]` announces "3 rows,
4 columns each," and you point at any cell with two numbers:
`grid[row][col]`. The surprise worth showing early: the computer's
memory is a single line, not a sheet. C++ stores the grid **row by
row** (row-major): all of row 0, then all of row 1. The grid is a
convenient *view* over a linear array — the offset of `grid[r][c]` is
`r * COLS + c` elements from the start. This is why the column count
must be known to the compiler whenever a function receives a 2-D array
parameter, and why row-wise traversal matches memory order.

Traversal is Module 5's nested loops wearing table clothes: outer loop
= rows, inner = columns (or swapped, for column-wise work). New this
week: two special-purpose walks — the **diagonal** (`a[i][i]` on square
grids) and the **boundary** (the grid's edge cells, with corners
counted once — a fence-post question in two dimensions).

## Terminology and definitions

| Term | Definition |
|---|---|
| 2-D array | `T name[ROWS][COLS]` — ROWS × COLS elements, one type |
| Element access | `name[r][c]` — row index first, then column index |
| Row-major layout | Rows stored consecutively; `[r][c]` at offset `r*COLS + c` |
| Row-wise traversal | Outer rows, inner columns — natural reading order |
| Column-wise traversal | Outer columns, inner rows — walks down each column |
| Diagonal traversal | `a[i][i]` (main) or `a[i][N-1-i]` (anti) — square grids |
| Boundary traversal | First/last row and first/last column — edge cells |
| Fence-post corners | Cells belonging to two edges; count them once |
| Linearized offset | Element position in the underlying linear memory |

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

// row-wise: reading order
for (int r{0}; r < ROWS; ++r)
{
    for (int c{0}; c < COLS; ++c)
        std::cout << grid[r][c] << '\t';
    std::cout << '\n';                     // newline per ROW
}

// column-wise: swap the loops
for (int c{0}; c < COLS; ++c)
{
    for (int r{0}; r < ROWS; ++r)
        std::cout << grid[r][c] << '\t';
    std::cout << '\n';
}

// main diagonal (square grid only)
int sq[3][3]{{1,2,3},{4,5,6},{7,8,9}};
for (int i{0}; i < 3; ++i)
    std::cout << sq[i][i] << ' ';          // 1 5 9

// boundary: full first & last rows; side columns between them
for (int c{0}; c < COLS; ++c) std::cout << grid[0][c] << ' ';
for (int c{0}; c < COLS; ++c) std::cout << grid[ROWS-1][c] << ' ';
for (int r{1}; r < ROWS-1; ++r)
    std::cout << grid[r][0] << ' ' << grid[r][COLS-1] << ' ';
```

## Line-by-line code explanation

`examples/grid_basics.cpp`:

1. The brace-list initializer nests one inner list per row — the
   readable form; the flattened `{1,2,3,4,5,6}` is legal but unreadable
   (style verdict: never in course code).
2. Row-wise print: `\t` *inside* the inner loop (per cell), `\n`
   *outside* it but inside the outer loop (per row) — the placement
   rule from the triangle exercise, now printing data.
3. The address demo prints `static_cast<void*>(&grid[r][c])` for each
   cell: addresses step by `sizeof(int)` across a row and jump by
   `COLS * sizeof(int)` between rows — row-major made visible.
4. `grid[0][0]` is the first element, `grid[ROWS-1][COLS-1]` the last;
   `grid[3][0]` here is out of bounds — same UB discipline as 1-D.

## Output prediction questions (with answers)

1. `int a[2][3]{{1,2,3},{4,5,6}};` — what is `a[1][0]`? — **4**.
2. Same `a`: the column-wise walk prints which pair first? — `1 4`
   (down column 0).
3. On the 3×4 grid above: `grid[0][2] + grid[2][0]` — ? — `3 + 9 = 12`.
4. Main diagonal of `sq` — ? — `1 5 9`; anti-diagonal — `3 5 7` via
   `sq[i][3-1-i]`.
5. Boundary cells of a 3×4 grid — how many? — `2*COLS + 2*(ROWS-2) =
   8 + 2 = 10` — corners counted once.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Swapped indices (`a[c][r]`) | Transposed data | Say "row first" while writing |
| `<=` in either bound | Reads into the next row / past the array | `r < ROWS`, `c < COLS` |
| Newline inside the inner loop | One cell per line | Newline belongs to the row level |
| Diagonal code on non-square grids | Wrong cells / OOB reads | Diagonals are square-grid-only |
| Double-counted corners | Boundary sum too high | Full rows, then columns `1..ROWS-2` |
| Flat initializer list | Row boundaries invisible | One inner brace-list per row |

## Classroom demonstrations

1. **The address march:** print every cell's address; the class calls
   the pattern out (step 4 across, jump 16 down on a 4-wide int grid):
   row-major without hand-waving.
2. **Transpose on paper:** write a 2×3 grid, rotate the paper 90° —
   reading row-wise reproduces the original column-wise walk.
3. **Corner census:** walk a hand-drawn 3×4 boundary; students count 10
   and defend why it is not 12.

## Guided student activities
**Grid walk (15 min):** 4×5 seating arrangement; students physically are
elements; instructor calls coordinates and traversal orders (row-wise,
column-wise, boundary) — students stand when "visited"; anti-diagonal gets a
deliberate wrong call first, corrected by the class.

## Practice problems

- Annotate a printed 3×3 grid with linear-memory offsets for all 9 elements.
- Write row-wise, column-wise, main-diagonal, and boundary printers for a
  4×4 grid; annotate iteration counts.
- Predict output of 4 traversal programs (one non-square trap).
- (🟡 stretch) Sum the "checkerboard" cells ((r+c) even) — predicate inside
  the inner loop.

## Summary

A 2-D array is a sheet of cells over linear memory: `a[r][c]`, stored
row-major, traversed with Module 5's nested loops. Row-wise and
column-wise walks swap loop order; diagonals and boundaries are
square-grid and edge-cell specialties with fence-post corners.
Next (L20): aggregation — row sums, column sums, and the transpose that
remaps the grid.

## Exit ticket / formative assessment
- Annotate a printed 3×3 grid with linear-memory offsets for all 9 elements.
- Write row-wise, column-wise, main-diagonal, and boundary printers for a
  4×4 grid; annotate iteration counts.
- Predict output of 4 traversal programs (one non-square trap).
- (🟡 stretch) Sum the "checkerboard" cells ((r+c) even) — predicate inside
  the inner loop.

## Exit ticket / formative assessment

1. For `int a[5][6]`, what is the offset of `a[3][4]` in elements?
2. Which loop is outer for *column totals* preparation traversal?
3. Write the anti-diagonal access expression for an N×N grid.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (arrays quiz) + grid motivation | 10 |
| Declaration, indexing, row-major layout | 35 |
| Break | 10 |
| Traversal patterns (row/column/diagonal/boundary) | 35 |
| Grid-walk activity | 15 |
| Exit ticket + L20 preview | 15 |
