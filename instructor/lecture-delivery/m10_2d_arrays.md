# Delivery Guide — Module 10 · Two-Dimensional Arrays (Week 10)

**Guides:** L19, L20 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L19 · 2-D Arrays: Declaration, Row/Column Indexing, Nested Traversal

1. **Lecture/title:** L19 — 2-D Arrays: Declaration, Row/Column Indexing, Nested Traversal
2. **Module/week:** Module 10 · Week 10 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_10/lecture_19.md): [lecture_19.md](../../lectures/week_10/lecture_19.md)): declare and initialize 2-D arrays; navigate with `[row][col]` indexing under the row-of-rows memory picture; write nested traversals (row-major and column-major); predict traversal output.
4. **Prerequisite knowledge:** L17 arrays; L10 nested loops (the clock model becomes the grid).
5. **Prep checklist:** compile `examples/grid_basics.cpp` this morning; board plan for the grid picture (rows *and* columns labelled); load PF-CS-049; chalk/markers for the human-grid activity.
6. **Materials & files:** `examples/grid_basics.cpp`; case PF-CS-049 Seat Map Query Engine; [MC-12](../misconception-bank/misconception_bank.md) snippet.
7. **Opening question (10):** "A classroom of seats — rows and columns. How would you store *every student's attendance* with one name?" — from 1-D box-row to grid; the two-index answer is elicited, not told.
8. **Concept sequence (30):** (a) `int g[3][4]` as *array of 3 rows, each of 4 boxes* — the memory picture: rows side by side, contiguous (10); (b) `[r][c]` indexing: row = which sub-array, col = which box in it (8); (c) nested traversal: row-major vs column-major — the loops' order *is* the visit order (12).
9. **Explanation guidance:** the grid on the board gets both index rulers (rows 0–2 left edge, cols 0–3 top edge) — students must *say* "row r, column c" aloud when writing `g[r][c]`. Row-major vs column-major taught as *visit order* (which matters for printing shape), with the memory-contiguity note as the CS-deepening and the "columns of a spreadsheet" as the DS anchor.
10. **Demonstration (15):** [DEMO-20](../demonstrations/demo_group4_arrays_strings.md) — `grid_basics.cpp`: init-list grid printed row-major, then column-major — same data, two shapes; planned error: swapped loop bounds (`c < ROWS` inside) → rectangular-grid garbage/silence; trace resolves which index marched past the edge.
11. **Output prediction:** print-shape votes for row-major vs column-major of a 2×3 grid; then the swapped-bounds prediction — most will miss it, the trace finds it (bounds-in-nested-loops is the week's exam face).
12. **Case study (15):** **PF-CS-049 Seat Map Query Engine** — queries over a grid (find seat, count occupied row); query design from the traversal vocabulary.
13. **Guided coding (20):** pairs build an attendance grid (5×4): fill with input, print with row labels, count absentees per row; TAs check loop-bound pairing (`r < ROWS` with `c < COLS` — the [MC-12](../misconception-bank/misconception_bank.md) discipline).
14. **Common misconceptions:** [MC-12](../misconception-bank/misconception_bank.md) (swapped indices/bounds) — home lecture; "g[r][c] equals g[c][r]" (transposition confusion — the demo's second act shows a symmetric-looking grid lie).
15. **Debugging activity:** symptom: "my column totals print row totals" — indices swapped in the accumulator; paper-grid trace locates which loop wrote which axis.
16. **Independent practice (20):** T06 2-D opening items (declare, print, row-sum); DS students: the DS grid cases as stretch.
17. **Exit ticket (5):** (1) `int g[2][3];` — how many ints? Which is `g[1][2]`, the last or second-to-last? (2) What loop-order prints a grid's *columns* as lines?
18. **Summary (5):** derive: "a 2-D array is an array of rows — the first index chooses the row, the second the box."
19. **Support:** human-grid activity: 12 students as boxes, two "index" callers announce [r][c]; the called student raises their hand — kinesthetic indexing, 5 minutes, worth it.
20. **Extension:** transpose on paper before L20 teaches it; predict whether `g[r][c]` and `gT[c][r]` agree for symmetric inputs.
21. **Reflection:** did the human-grid land? Who swapped bounds in guided work? (Names feed L20's demo choice.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L20 · 2-D Operations: Row/Column Totals, Matrix Addition, Transpose, Passing to Functions

1. **Lecture/title:** L20 — 2-D Operations: Row/Column Totals, Matrix Addition, Transpose, Passing to Functions
2. **Module/week:** Module 10 · Week 10 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 6)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_10/lecture_20.md): [lecture_20.md](../../lectures/week_10/lecture_20.md)): compute row/column totals and other per-axis aggregates; add matrices element-wise; transpose; pass 2-D arrays to functions with declared column counts; choose axes correctly for a stated aggregate.
4. **Prerequisite knowledge:** L19 indexing/traversal; L18 algorithm-pattern transfer.
5. **Prep checklist:** quiz 6 staged; compile `examples/matrix_ops.cpp`; prepare the border-double-count snippet; load PF-CS-052.
6. **Materials & files:** `examples/matrix_ops.cpp`; case PF-CS-052 Matrix Border Sum; quiz 6 + key.
7. **Opening question (10):** "Monday's attendance grid: I need *each row's* total. How many loops? Which axes?" — elicit the outer-rows/inner-cols pattern before any code; then "and each *column's* total?" — the swap that trips everyone.
8. **Concept sequence (30):** (a) per-axis aggregates: row totals (outer rows) vs column totals (outer cols) — the accumulator *outside* the swapped loop (12); (b) matrix addition (element-wise, shape-guarded) + transpose (write to a *new* grid, indices swap) (10); (c) passing 2-D arrays: the column-count rule and why (8).
9. **Explanation guidance:** the axis-choice rule stated once, sharply: "the outer loop names the axis of the *result*; the inner loop walks the *other* axis." Border sums introduce the multi-region walk (top row, bottom row, side cols — no double-counting corners); the class designs the region boundaries on the grid before code.
10. **Demonstration (15):** [DEMO-20/21](../demonstrations/demo_group4_arrays_strings.md) — `matrix_ops.cpp`: addition, transpose, row/col totals; planned error: border sum double-counts corners — silent wrong answer; the paper-grid trace (colour the counted cells) exposes the overlap.
11. **Output prediction:** column totals of a 3×4 grid (votes); transpose print of a non-square grid (shape votes — non-square makes the lie visible).
12. **Case study (15):** **PF-CS-052 Matrix Border Sum** — region-walking design; the 5-minute protocol; debrief lands the "design regions, then code" habit.
13. **Guided coding (15 — quiz-day trim):** pairs implement transpose + column totals; TAs check the function signatures (`int g[][COLS]`, `const` where read-only).
14. **Common misconceptions:** corner double-count (today's demo); axis-swap in per-axis totals (concept-sequence rule); "transpose modifies in place" — corrected via the new-grid requirement.
15. **Debugging activity:** symptom: "my border sum is too big by exactly the corners" — count the overlap on paper first, fix second.
16. **Independent practice (10 — quiz-day trim):** one transpose + one column-total item from T06.
17. **Quiz 6 (15):** per cadence.
18. **Exit ticket (5):** (1) Row totals vs column totals — which loop is outer, and why, in one sentence? (2) Why must transpose write to a new grid?
19. **Summary (5):** the axis rule derived from the class's own guided-work errors; Module 11 tease: "strings are arrays of characters that learned manners."
20. **Support:** grid-template with colourable cells (border/overlap activities); axis-rule sticky note for notebooks.
21. **Reflection:** quiz 6 → who still swaps axes under time pressure? (Module 12's sorting uses flat arrays, but Module 13's pointer arithmetic will revisit contiguity — note who has the memory picture.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 6 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
