# T08 · Searching and Sorting

Covers: linear and binary search, sort algorithms (selection, bubble),
sorted-array workflows, comparison counting, complexity observation.
Lectures L23–L24. Outcomes PF-12.x.

11 exercises · ladder 🟢 → 🔴.

---

### PF-E-091 · Linear Search (with sentinel)
**Difficulty:** Beginner · **Lecture:** L23 · **Outcomes:** PF-12.1
**Prerequisites:** E-069
**Problem:** Read n (1–20), n integers, then a sequence of keys terminated by `-1`. For each key print its first position or `not found`.
**Input:** n, values, keys… −1 · **Output:** one line per key.
**Sample:** values `5 7 5 9`, keys `5 9 2 -1` → `0` / `3` / `not found`
**Hints:** reuse ONE search function per key; first occurrence wins.

### PF-E-092 · Count Comparisons (linear)
**Difficulty:** Beginner · **Lecture:** L23 · **Outcomes:** PF-12.1, PF-12.4
**Prerequisites:** E-091
**Problem:** Like E-091, but the search also counts comparisons. Print position **and** comparison count for each key, then print the theoretical best/worst for n.
**Input:** as E-091 · **Output:** per-key results + theory line.
**Sample:** n=4, key at index 2 → `2 (3 comparisons)` / `theory: best 1, worst 4`
**Hints:** a `long long&` counter parameter (L23's harness).

### PF-E-093 · Is It Sorted?
**Difficulty:** Beginner · **Lecture:** L23 · **Outcomes:** PF-12.2
**Prerequisites:** E-092
**Problem:** Read n (1–20) then n integers. Print `ascending`, `descending`, or `unsorted`. Equal neighbors are allowed in both sorted orders.
**Input:** n + values · **Output:** one verdict.
**Sample:** `4 9 7 7 2` → `descending`
**Hints:** track *violations* of each order; both-zero means constant → call it `ascending`.

### PF-E-094 · Binary Search on Sorted Input
**Difficulty:** Foundational · **Lecture:** L23 · **Outcomes:** PF-12.1, PF-12.2
**Prerequisites:** E-093
**Problem:** Read n (1–20) then n **ascending** integers, then keys terminated by `-1`. Binary-search each key; print position or `not found`. If the input isn't sorted, print `input not sorted` and refuse to search.
**Input:** n + sorted values + keys · **Output:** per-key result.
**Sample:** values `2 4 6 8`, key `6` → `2` / key `5` → `not found`
**Hints:** reuse E-093's check as the precondition gate; `low + (high-low)/2`.

### PF-E-095 · Selection Sort with Snapshots
**Difficulty:** Foundational · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-12.3
**Prerequisites:** E-094
**Problem:** Read n (2–15) then n integers. Selection-sort the array, printing the array after every pass, plus final comparison and swap counts.
**Input:** n + values · **Output:** n−1 snapshots + counts.
**Sample:** `5 5 2 9 1 7` → pass lines ending `1 2 5 7 9`, `comparisons: 10`, `swaps: 3`
**Hints:** swap only when `minIdx != i` — the swap count can be less than the pass count.

### PF-E-096 · Bubble Sort with Early Exit
**Difficulty:** Foundational · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-12.3
**Prerequisites:** E-095
**Problem:** Same I/O as E-095 but bubble sort with the swapped-flag early exit. On already-sorted input demonstrate: 1 pass, n−1 comparisons, 0 swaps.
**Input:** n + values · **Output:** snapshots + counts.
**Sample:** `4 1 2 3 4` → `passes: 1` / `comparisons: 3` / `swaps: 0`
**Hints:** reset the flag at the top of each pass; `break` when a pass is clean.

### PF-E-097 · Sort Then Binary Search (full workflow)
**Difficulty:** Intermediate · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-12.1
**Prerequisites:** E-096
**Problem:** Read n (5–30) then n integers (any order) and one key. Sort with your selection sort, print the sorted array, then binary-search the key, printing the position **in the original array** (map positions through the sort).
**Input:** n + values + key · **Output:** sorted array + original index.
**Sample:** `5 9 1 7 3 5` key `7` → sorted `1 3 5 7 9` / `7 was originally at index 2`
**Hints:** sort a parallel index array alongside the values — every value swap moves both.

### PF-E-098 · Median and Quartiles
**Difficulty:** Intermediate · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-3.2
**Prerequisites:** E-097
**Problem:** Read n (4–20) then n integers. Sort them, then print the median (mean of two middles for even n, 1 decimal) and the lower/upper quartile (medians of the lower/upper halves).
**Input:** n + values · **Output:** three numbers.
**Sample:** `6 3 1 9 7 5 11` → sorted `1 3 5 7 9 11` / `median: 6.0` / `Q1: 3` / `Q3: 9`
**Hints:** index arithmetic on the sorted array; halves exclude the overall median for odd n.

### PF-E-099 · Deduplicate (sorted)
**Difficulty:** Intermediate · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-9.3
**Prerequisites:** E-098
**Problem:** Read n (1–30) then n integers. Sort, then remove duplicates *in place* (two-finger compaction on the sorted order). Print the unique count and the deduplicated array.
**Input:** n + values · **Output:** count + array.
**Sample:** `7 4 1 4 9 4 1 7` → `unique: 4` / `1 4 7 9`
**Hints:** in sorted order, duplicates are adjacent — a single pass suffices.

### PF-E-100 · Frequency Sort (two-key ordering)
**Difficulty:** Advanced Introductory · **Lecture:** L24 · **Outcomes:** PF-12.2, PF-12.3
**Prerequisites:** E-099
**Problem:** Read n (1–30) then n integers (values 0–99). Print each distinct value sorted by **descending frequency**, ties broken by ascending value, with counts.
**Input:** n + values · **Output:** value:count lines.
**Sample:** `8 2 2 9 2 9 1 2 9` → `2:4` / `9:3` / `1:1` (1 before... actually `1:1` last)
**Hints:** count into a 100-slot table, then selection-sort the *distinct* values by (count desc, value asc).

### PF-E-101 · Search Strategy Showdown
**Difficulty:** Advanced Introductory · **Lecture:** L24 · **Outcomes:** PF-12.1, PF-12.4
**Prerequisites:** E-100
**Problem:** Read n (100–2000, sorted input guaranteed) and k (10–50) keys. For the whole key set, compare total comparisons: (a) linear search for each key; (b) selection-sort (0 — already sorted) + binary search for each key. Print both totals and a one-line verdict explaining when sort+binary wins.
**Input:** n + n sorted values + k + k keys · **Output:** two totals + verdict.
**Sample:** n=1000, k=20 → `linear: 20000` / `sort+binary: ~200` / `verdict: binary wins when k << n`
**Hints:** reuse E-092 and E-094 counters; the break-even point is the L24 cost-model lesson.
