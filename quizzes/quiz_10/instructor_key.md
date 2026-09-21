# Quiz 10 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 10 · lectures L19–L20 · Two-Dimensional Arrays · total 10 marks · CLO-6

**Q1 (1 mk) — B**



**Q2 (1 mk) — A**



**Q3 (1 mk) — B**



**Q4 (2 mk) — 3 7**

Row 0: 1+2=3; row 1: 3+4=7.

**Q5 (2 mk) — Left/right column loops cover all rows including the corners already added by the row pass; fix with the single-pass predicate r==0 || r==ROWS-1 || c==0 || c==COLS-1.**



**Q6 (2 mk) — The column dimension (and ideally ROWS) must appear: `void f(int g[][COLS], int rows)`.**



**Q7 (1 mk) — B**



## Common wrong answers to watch for

Q2/Q3: diagonal relations are commonly swapped; Q4: expect 1 2 3 4 (column-major answer).