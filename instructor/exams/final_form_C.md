# Final Examination — Form C
**Programming Fundamentals Using C++ · All 16 modules · 180 minutes · 100 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form C differs from Forms A/B in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (8 × 1 = 8 marks)
1. `[M9]` In-place reversal of n elements performs: A. n swaps B. n/2 swaps C. n−1 D. n²
2. `[M10]` Per-row accumulators are reset: A. never B. before each row's inner loop C. after the grid D. each cell
3. `[M11]` `s.size()` of an empty string is: A. −1 B. 0 C. 1 D. undefined
4. `[M12]` Stability of a sort promises: A. speed B. equal keys keep relative order C. no swaps D. memory bounds
5. `[M13]` A reference, once bound: A. can be reseated B. cannot be reseated C. can be null D. must be const
6. `[M14]` struct assignment copies: A. nothing B. the address C. all members D. first member
7. `[M15]` getline + istringstream per line is preferred because: A. faster B. malformed lines become data to classify C. no headers D. files must be line-based
8. `[M16]` A const member function promises: A. speed B. no modification of the object's state C. no parameters D. private access

## Q2 · Output tracing (5 × 2 = 10 marks)
1. (M9) In-place reversal of {1,2,3,4,5} — the array after the loop?
2. (M10) Grid {{1,2},{3,4}} row totals print?
3. (M11) `s.find("ll")` on "hello" and `s.find('z') == npos` — the two printed values?
4. (M14) `P a{3}; P b{a}; b.x = 9;` — `a.x` prints?
5. (M16) After `c.set(7)`, `c.get()` prints?

## Q3 · Debugging (4 × 2 = 8 marks)
1. (M9) Max-tracker initialized to 0 fails on all-negative arrays — why, and the correct init.
2. (M11) After `cin >> age;` the next getline is empty — cause + course stream-state fix.
3. (M13) Use-after-delete crash — name both course guards.
4. (M15) Loader exits on the first malformed line — why wrong for batch data + the fixing pattern.

## Q4 · Short conceptual (4 × 2 = 8 marks)
1. (M9) The off-by-one classes of `i < n` vs `i <= n` on arrays — one sentence each.
2. (M12) What selection sort's pass 0 guarantees (and what it does not).
3. (M14) RAII in one sentence as the course uses it.
4. (M15) Exit-code discipline 0/1/2.

## Q5 · Complexity intuition (3 × 2 = 6 marks)
1. Binary search on n = 1000 — comparisons?
2. Linear on the same — comparisons?
3. One sentence: why the gap widens at n = 10⁶.

## Q6 · Algorithm design (3 × 3 = 9 marks)
1. (M10) Design the in-place transpose loop; why only j > i swaps?
2. (M14) Parallel arrays → struct Record migration: what changes in the sort, what bug class dies?
3. (M15) Robust CSV loader: algorithm + exit codes.

## Q7 · Coding (4 × 6 = 24 marks)
1. (M9) Second-largest distinct or `N/A`.
2. (M11) Vowel/consonant/digit counts of a line.
3. (M12) Insertion sort with per-pass output.
4. (M16) `Counter` with guarded `dec()`; main demonstrates rejection.

## Q8 · Code completion (3 × 3 = 9 marks)
1. (M9) Reversal loop completion (bound and index update).
2. (M14) `new int[n]{}` … `delete` … `nullptr` completion sequence.
3. (M16) Wallet spend guard + subtraction.

## Q9 · Extended synthesis (18 marks)
Choose ONE:
- **Option 1:** Three G-pool coding items (array, string, class), 6 each.
- **Option 2:** Scaled practical variant: add `allBelow(int cap)` to Counter returning true iff every recorded peak value stayed below cap (6 design, 6 code, 6 test table with expected outputs).

---
**END**
