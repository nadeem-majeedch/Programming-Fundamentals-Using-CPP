# Assignment 6 · Campus Grid — 2-D Arrays
**Module 10 (L19–L20) · 40 marks · due end of Week 11**
Outcomes: CLO-6 (PF-10.x)

A campus map is an R×C grid of zone codes (integers 0..9). You will compute
map statistics with correct 2-D traversal.

## Input

`R C` (1 ≤ R, C ≤ 20), then R rows × C columns of zone codes.

## Report (exact labels, in order)

```
sum     : S           (all cells)
maxrow  : i v         (row index with the largest row total, and that total; ties → lowest index)
diagonal: D           (sum of g[i][i] for i < min(R,C))
border  : B           (sum of all edge cells, corners counted once)
zeros   : Z           (count of cells equal to 0)
```

## Sample run

Input `3 4 / 1 2 3 4 / 5 0 0 2 / 9 1 1 1` →
```
sum     : 29
maxrow  : 2 12
diagonal: 5
border  : 27
zeros   : 2
```
Check: row totals 10 / 7 / 12 → row 2 wins; diagonal = 1 + 0 + 1 = 2 … careful:
min(R,C) = 3 → g[0][0]+g[1][1]+g[2][2] = 1+0+1 = 2. If your program prints 5
you summed the wrong diagonal direction. **The expected value is 2** — fix the
sample reasoning before coding.

## Required functions

- `int totalSum(const int g[][20], int r, int c);`
- `void maxRow(const int g[][20], int r, int c, int& idx, int& tot);`
- `int diagonalSum(const int g[][20], int r, int c);` — main-diagonal only, i < min(r,c).
- `int borderSum(const int g[][20], int r, int c);` — single pass, predicate form.
- `int countZeros(const int g[][20], int r, int c);`

## Constraints

- Column dimension must be literal 20 in signatures (per the course rule).
- `borderSum` must be one pass with the edge predicate — no four separate loops.
- No vectors; fixed `int grid[20][20]`.

## Deliverables

`campus.cpp` (contract, zero warnings) · `test_table.md` — 1×1 grid, 1×C and
R×1 (whole grid is border!), diagonal on non-square grid, all-zero grid, tie
between two rows · `postmortem.md` (10 marks).

## Note

The worked sample above contains one deliberately wrong intermediate claim
(diagonal 5) — your test table must list **2** as the expected diagonal with
your own hand-check. Reading specs critically is part of the assignment.
