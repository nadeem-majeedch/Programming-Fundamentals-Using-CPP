# T06 · Arrays

Covers: 1-D and 2-D arrays — declaration, traversal, fill/print,
accumulate/count-if/find-first/min-max, in-place algorithms, 2-D
traversals and aggregation, arrays with functions. Lectures L17–L20.
Outcomes PF-9.x, PF-10.x.

13 exercises · ladder 🟢 → 🔴.

---

### PF-E-066 · Array Echo
**Difficulty:** Beginner · **Lecture:** L17 · **Outcomes:** PF-9.1
**Prerequisites:** E-027
**Problem:** Read n (1–20) then n integers into an array; print them back space-separated on one line, then in reverse order on a second line.
**Input:** n, then n integers · **Output:** two lines.
**Sample:** `4 5 6 7 8` → `5 6 7 8` / `8 7 6 5`
**Hints:** two loops over the same array — one forward, one with a decreasing index.

### PF-E-067 · Array Sum and Mean
**Difficulty:** Beginner · **Lecture:** L17 · **Outcomes:** PF-9.1, PF-9.3
**Prerequisites:** E-066
**Problem:** Read n (1–20) then n integers. Print the sum (int) and mean (2 decimals, correctly non-truncating).
**Input:** n, then n integers · **Output:** sum + mean.
**Sample:** `3 1 2 4` → `sum: 7` / `mean: 2.33`
**Hints:** L05's truncation lesson — cast *after* the sum.

### PF-E-068 · Fill with Pattern
**Difficulty:** Beginner · **Lecture:** L17 · **Outcomes:** PF-9.1
**Prerequisites:** E-067
**Problem:** Declare an array of 10 ints. Fill it so `a[i] = 3*i + 2` using a loop, print it, then re-fill with the first 10 squares and print again.
**Input:** none · **Output:** two arrays.
**Sample:** first → `2 5 8 11 14 17 20 23 26 29`
**Hints:** the fill loop *computes* — no input needed.

### PF-E-069 · Count Occurrences
**Difficulty:** Beginner · **Lecture:** L18 · **Outcomes:** PF-9.3
**Prerequisites:** E-067
**Problem:** Read n (1–20), n integers, and a key. Print how many times the key appears and the positions (0-based) of every occurrence.
**Input:** n, integers, key · **Output:** count + positions.
**Sample:** `6 4 8 4 1 4 9` key `4` → `count: 3` / `positions: 0 2 4`
**Hints:** COUNT-IF with an index side-report.

### PF-E-070 · Min and Max with Positions
**Difficulty:** Foundational · **Lecture:** L18 · **Outcomes:** PF-9.3
**Prerequisites:** E-069
**Problem:** Read n (1–20) then n integers. Print the minimum and maximum *values* and *their first positions*. Handle the all-equal array.
**Input:** n, then n integers · **Output:** four numbers.
**Sample:** `5 7 7 2 9 2` → `min: 2 (pos 3)` / `max: 9 (pos 4)`
**Hints:** seed with `a[0]` (L11's lesson), loop from index 1, update value *and* index together.

### PF-E-071 · Reverse In Place
**Difficulty:** Foundational · **Lecture:** L18 · **Outcomes:** PF-9.3
**Prerequisites:** E-070
**Problem:** Read n (1–20) then n integers. Reverse the array **in place** (two-index swap, no second array) and print before/after.
**Input:** n, then n integers · **Output:** two lines.
**Sample:** `4 1 2 3 4` → `before: 1 2 3 4` / `after: 4 3 2 1`
**Hints:** swap `a[i]` with `a[n-1-i]` for i < n/2.

### PF-E-072 · Remove All Occurrences (compact)
**Difficulty:** Foundational · **Lecture:** L18 · **Outcomes:** PF-9.3
**Prerequisites:** E-071
**Problem:** Read n (1–20), n integers, and a key. Build a *compacted* array with all occurrences of key removed (preserve order); print the new logical size and contents.
**Input:** n, integers, key · **Output:** size + compacted array.
**Sample:** `6 4 8 4 1 4 9` key `4` → `size: 3` / `8 1 9`
**Hints:** write-index walks slower than read-index — the classic two-finger compaction.

### PF-E-073 · Merge Two Sorted Arrays
**Difficulty:** Intermediate · **Lecture:** L20 · **Outcomes:** PF-9.3, PF-9.4
**Prerequisites:** E-072
**Problem:** Read two sorted arrays (n₁, n₁ values; n₂, n₂ values — each ascending). Merge into one sorted array *without re-sorting* (two-finger walk). Print the merged result.
**Input:** n₁ + values, n₂ + values (each ascending) · **Output:** merged line.
**Sample:** `3 1 4 9` + `3 2 4 10` → `1 2 4 4 9 10`
**Hints:** take the smaller head each time; then append the remainder.

### PF-E-074 · Rotate Left by K
**Difficulty:** Intermediate · **Lecture:** L20 · **Outcomes:** PF-9.3
**Prerequisites:** E-073
**Problem:** Read n (1–20), n integers, and k (0–n−1). Rotate the array left by k positions *in place* is hard; instead produce the rotated result in a second array and print it. Then state (comment) how in-place could be done with three reversals.
**Input:** n, values, k · **Output:** rotated array.
**Sample:** `5 1 2 3 4 5` k=2 → `3 4 5 1 2`
**Hints:** `b[i] = a[(i + k) % n]` — modulo does the wrap.

### PF-E-075 · Histogram of Scores
**Difficulty:** Intermediate · **Lecture:** L20 · **Outcomes:** PF-9.3, PF-2.3
**Prerequisites:** E-070
**Problem:** Read n (1–100) scores (0–100). Print a star histogram: one row per 10-point band (0–9, 10–19, …, 90–100), labeled, with `#` repeated per count. Reject out-of-range scores with a re-prompt.
**Input:** n + scores · **Output:** 10 labeled rows.
**Sample:** with three scores in 80s → `80-89: ###`
**Hints:** band index = score/10 (with 100 folded into the last band); an array of 10 counters beats 10 variables.

### PF-E-076 · Matrix Addition and Scale
**Difficulty:** Intermediate · **Lecture:** L20 · **Outcomes:** PF-10.1, PF-10.2
**Prerequisites:** E-075
**Problem:** Read a 2×3 and a 2×3 matrix of ints. Print A+B, then 3×A (each element tripled), matrices formatted in rows.
**Input:** 6 ints, then 6 ints · **Output:** two matrices.
**Sample:** A = {{1,2,3},{4,5,6}} → 3×A is `3 6 9 / 12 15 18`
**Hints:** nested loops with `const int ROWS{2}; const int COLS{3};`.

### PF-E-077 · Row and Column Totals (2-D)
**Difficulty:** Intermediate · **Lecture:** L20 · **Outcomes:** PF-10.2
**Prerequisites:** E-076
**Problem:** Read a 3×4 matrix. Print row totals (one line), column totals (one line), and the grand total. Then print which row has the largest total.
**Input:** 12 ints · **Output:** three lines + winning row.
**Sample:** — → `rows: 22 15 40` / `cols: …` / `grand: 77` / `largest row: 2`
**Hints:** accumulator *placement* (L20's inherited-accumulator bug) decides correctness.

### PF-E-078 · Diagonal Difference (square matrix)
**Difficulty:** Advanced Introductory · **Lecture:** L20 · **Outcomes:** PF-10.2, PF-10.3
**Prerequisites:** E-077
**Problem:** Read n (2–8) and an n×n matrix. Compute |main diagonal − anti-diagonal| and print it. Also print whether the matrix is symmetric (a[i][j] == a[j][i] for all pairs).
**Input:** n + n² ints · **Output:** difference + symmetric verdict.
**Sample:** n=2, {{1,2},{2,1}} → `diff: 0` / `symmetric: yes`
**Hints:** diagonals are single loops; symmetry is a j > i half-matrix check.
