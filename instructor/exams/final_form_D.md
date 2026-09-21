# Final Examination — Form D
**Programming Fundamentals Using C++ · All 16 modules · 180 minutes · 100 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form D differs from Forms A–C in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (8 × 1 = 8 marks)
1. `[M9]` A frequency table for ratings 1..5 conventionally uses: A. counts[5] direct B. counts[6] with slot 0 unused / shift C. a string D. two arrays
2. `[M10]` The signature `void f(int g[][COLS], int rows)` requires which dimension inside? A. rows B. COLS C. both D. neither
3. `[M11]` `isalpha('3')` returns: A. true B. false C. 3 D. '3'
4. `[M12]` Binary search on n = 1000 makes about: A. 1000 B. 500 C. 10 D. 1 comparisons
5. `[M13]` Null-dereference (`*p` where p == nullptr) is: A. fine B. undefined behavior C. compile error D. sets p
6. `[M14]` `delete` (not `delete[]`) on `new int[10]` is: A. fine B. undefined behavior C. leak only D. compile error
7. `[M15]` In-class try/catch demos use exceptions for: A. every validation B. exceptional structural failures (stream-state is the everyday tool) C. loops D. opening only
8. `[M16]` Encapsulation's benefit for invariants: A. smaller binaries B. small attack surface: writes pass guarded methods C. faster I/O D. auto testing

## Q2 · Output tracing (5 × 2 = 10 marks)
1. (M9) `a[5]{}` with `a[i]=i*i` — print `a[1]+a[4]`.
2. (M10) Row 1 sum of {{1,2,3},{4,5,6}}?
3. (M12) Binary search {2,4,6,8,10}, key 8 — mids checked?
4. (M13) `int x{4}; int* p{&x}; *p = *p+5; p = nullptr; cout << x;`
5. (M14) `P a{3}; P b{a}; b.x = 9;` — print `a.x`.

## Q3 · Debugging (4 × 2 = 8 marks)
1. (M10) Corner double-count in a border sum — describe + single-pass predicate.
2. (M12) `high = n` mixed with `low <= high` — failure + one-discipline fix.
3. (M14) Leak on the early-return path in the allocation loop — classify + two fixes.
4. (M16) Balance invariant broken by direct member write — where does validation live?

## Q4 · Short conceptual (4 × 2 = 8 marks)
1. (M9) Why initialize max from `a[0]`?
2. (M13) One-sentence rule: when references beat pointers.
3. (M14) The record-misalignment bug class — what is it and which construct removes it?
4. (M16) Invariant: define + one example for a Wallet.

## Q5 · Complexity intuition (3 × 2 = 6 marks)
1. Selection vs insertion sort on nearly-sorted data — which does less work and why (one sentence)?
2. Binary search absent-key on n = 10⁶ — about how many comparisons?
3. What single property of the input makes the halving in binary search sound?

## Q6 · Algorithm design (3 × 3 = 9 marks)
1. (M11) Whole-word "cat" counter — boundary predicate.
2. (M12) First-duplicate finder — algorithm, complexity, boundaries.
3. (M14) Top-N from parallel arrays via struct — design + removed defect class.

## Q7 · Coding (4 × 6 = 24 marks)
1. (M9) Second-largest distinct or `N/A`.
2. (M11) Vowel/consonant/digit counts of a line.
3. (M12) Insertion sort with per-pass output.
4. (M16) `Counter` with guarded `dec()`; main demonstrates rejection.

## Q8 · Code completion (3 × 3 = 9 marks)
1. (M10) Diagonal sum completion: `diag += g[r]__(a)__[__(b)__];`
2. (M13) After `delete[] data;` — the guard statements.
3. (M16) Wallet spend guard + subtraction.

## Q9 · Extended synthesis (18 marks)
Choose ONE:
- **Option 1:** Three G-pool coding items (array, string, class), 6 each.
- **Option 2:** Scaled practical variant: extend the vowel/consonant program to also report the most frequent letter (ties: first alphabetically) — 6 design, 6 code, 6 test table with expected outputs.

---
**END**
