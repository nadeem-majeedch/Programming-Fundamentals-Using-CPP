# T09 · Pointers and References

Covers: address-of, dereference, pointers with arrays, pointer
parameters, references, dynamic memory, RAII with `std::vector`, memory
safety disciplines. Lectures L25–L27. Outcomes PF-13.x, PF-14.1–14.2.

10 exercises · ladder 🟢 → 🔴.

---

### PF-E-102 · Address Bookkeeping
**Difficulty:** Beginner · **Lecture:** L25 · **Outcomes:** PF-13.1
**Prerequisites:** E-003
**Problem:** Declare `int x{42};` and a pointer `p` to it. Print `x`, `&x`, `p`, and `*p` with labels. Then reassign `p` to a second variable `y` and print the four values again, plus `*p = 7`'s effect on `y`.
**Input:** none · **Output:** labeled address/value lines.
**Sample:** (addresses vary) → `x: 42` / `p == &y: yes` / `after *p=7, y: 7`
**Hints:** box-and-arrow diagram first; addresses print with `std::hex`-style formatting via the stream by default.

### PF-E-103 · Read and Write Through a Pointer
**Difficulty:** Beginner · **Lecture:** L25 · **Outcomes:** PF-13.1, PF-13.2
**Prerequisites:** E-102
**Problem:** Read two integers into variables. Using *only* pointer dereferences (no direct variable names after setup), swap their values. Print before/after using the variables directly to prove it worked.
**Input:** two integers · **Output:** before/after lines.
**Sample:** `3 8` → `before: 3 8` / `after: 8 3`
**Hints:** pointer-based swap = the three-assignment swap with `*pa`, `*pb`.

### PF-E-104 · Null Discipline
**Difficulty:** Foundational · **Lecture:** L25 · **Outcomes:** PF-13.2
**Prerequisites:** E-103
**Problem:** Write `void safePrint(const int* p)` that prints `null pointer` when `p == nullptr`, else the value. Demonstrate with a null pointer, a valid one, and one nulled *after* delete (allocate, delete, null-out, call again).
**Input:** none · **Output:** three safePrint results.
**Sample:** — → `null pointer` / `42` / `null pointer`
**Hints:** the null-after-delete discipline turns "may crash" into "testable".

### PF-E-105 · Pointer Walk Over an Array
**Difficulty:** Foundational · **Lecture:** L25 · **Outcomes:** PF-13.1, PF-13.3
**Prerequisites:** E-104
**Problem:** Read n (1–10) and n integers into an array. Compute the sum twice: once with indexing, once with a moving pointer (`for (const int* p = a; p != a + n; ++p)`). Print both sums and the first/last element addresses' difference in *elements* (not bytes).
**Input:** n + values · **Output:** two sums + element-distance.
**Sample:** `3 10 20 30` → `sum: 60` / `sum(p): 60` / `span: 2`
**Hints:** pointer arithmetic scales by element size — that's why the span is n−1.

### PF-E-106 · Reference vs Pointer vs Value
**Difficulty:** Foundational · **Lecture:** L26 · **Outcomes:** PF-13.3
**Prerequisites:** E-105
**Problem:** Write three functions `bumpByValue(int)`, `bumpByPointer(int*)`, `bumpByReference(int&)`. Read one integer; call all three in sequence, printing the variable's value after each. Then answer in comments: which two produce identical memory effects, and what can the pointer version do that the reference cannot?
**Input:** one integer · **Output:** value after each call + commentary.
**Sample:** `10` → `after value: 10` / `after pointer: 11` / `after reference: 12`
**Hints:** comments: pointer can be null / be repointed; reference is a one-time alias.

### PF-E-107 · Min/Max Finder Returning Two Results
**Difficulty:** Intermediate · **Lecture:** L26 · **Outcomes:** PF-13.3
**Prerequisites:** E-106
**Problem:** Write `void findMinMax(const int* a, int n, int& minOut, int& maxOut)` (empty array → print error and leave outputs untouched). Read n (1–20) + values; demonstrate. Then write the pointer-returning variant `const int* findMax(const int* a, int n)` returning a *pointer to the max element* or `nullptr`; print the max through the returned pointer.
**Input:** n + values · **Output:** min/max + pointer-found max.
**Sample:** `4 7 2 9 5` → `min: 2` / `max: 9` / `via pointer: 9`
**Hints:** returning `a + bestIndex` — the pointer *is* the position.

### PF-E-108 · Runtime Array with new[]/delete[]
**Difficulty:** Intermediate · **Lecture:** L27 · **Outcomes:** PF-14.1, PF-14.2
**Prerequisites:** E-107
**Problem:** Read n (1–100,000 — far beyond stack arrays). Allocate `new long long[n]`, fill with the first n squares, print the first 5 and last 2, compute the sum, then `delete[]` correctly. Also demonstrate in comments why `delete` (no brackets) here is wrong.
**Input:** one integer · **Output:** sample elements + sum.
**Sample:** n = 7 → first 5 `1 4 9 16 25`, last 2 `25 36`... (n=7: 1..49) / `sum: 140`
**Hints:** long long — 100,000² overflows int; one allocation, one delete, exactly.

### PF-E-109 · Leak Hunt (fix the broken version)
**Difficulty:** Intermediate · **Lecture:** L27 · **Outcomes:** PF-14.2
**Prerequisites:** E-108
**Problem:** You are given (in comments) a loop that allocates a new block each iteration, copies one value, and reassigns the pointer — leaking every old block. (1) State the leak. (2) Fix it *with raw new/delete*. (3) Rewrite the whole task with `std::vector<long long>` and note which failure modes disappeared.
**Input:** one integer n (1–50) · **Output:** final vector contents + notes.
**Sample:** n = 5 → `0 1 2 3 4` (values = indices) / `raw version: freed every iteration`
**Hints:** fix = delete before reassign; vector version = no delete anywhere (RAII).

### PF-E-110 · Dangling Pointer Demonstration (safe version)
**Difficulty:** Advanced Introductory · **Lecture:** L27 · **Outcomes:** PF-14.2
**Prerequisites:** E-109
**Problem:** Construct the *three* classic hazards as labeled, commented code blocks: (1) leak, (2) use-after-delete, (3) double-delete. Compile-time-rule the dangerous ones: keep them commented, and instead print a *written explanation* of what undefined behavior each would cause, plus the corrected idiom for each (delete→null→check; single ownership; RAII alternative).
**Input:** none · **Output:** explanation lines for the three hazards.
**Sample:** — → `hazard 2: use-after-delete = UB (garbage or crash) → fix: null-out after delete`
**Hints:** this exercise's discipline is *not running* the dangerous code — describing UB is the deliverable.

### PF-E-111 · Dynamic 2-D Grid
**Difficulty:** Advanced Introductory · **Lecture:** L27 · **Outcomes:** PF-14.1, PF-14.3
**Prerequisites:** E-110
**Problem:** Read rows r and columns c (1–50). Allocate a dynamic r×c grid (array of row pointers OR flat array with manual `r*c+c` indexing — pick one and justify in a comment). Fill row-major with `(row*10+col)`, print the grid, free **all** memory in the correct order.
**Input:** two integers · **Output:** the grid + `freed`.
**Sample:** 2×3 → `0 1 2 / 10 11 12` / `freed`
**Hints:** the flat version has one allocation and one delete; the row-pointer version must delete every row then the row array — order matters.
