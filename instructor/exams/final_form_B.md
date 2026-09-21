# Final Examination — Form B
**Programming Fundamentals Using C++ · All 16 modules · 180 minutes · 100 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form B differs from Form A in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (8 × 1 = 8 marks)
1. `[M9]` Out-of-range `a[i]` is: A. compile error B. exception C. undefined behavior D. returns 0
2. `[M10]` Main diagonal cells satisfy: A. r == c B. r + c == ROWS C. r > c D. c == 0
3. `[M11]` Reading a full line with spaces: A. cin >> s B. getline(cin, s) C. scanf D. s.read()
4. `[M12]` Insertion sort on sorted input does: A. O(n²) B. O(n) comparisons C. none D. O(n log n)
5. `[M13]` `&x` yields: A. x's value B. x's address C. a copy D. dereference
6. `[M14]` Forgetting delete causes: A. compile error B. silent leak C. immediate crash D. warning
7. `[M15]` `ios::app` mode: A. truncates B. creates-or-continues C. read-only D. deletes file
8. `[M16]` An invariant is: A. loop condition B. property held after every public method C. a comment D. private member

## Q2 · Output tracing (5 × 2 = 10 marks)
1. (M9) `a[5]{}` filled `a[i]=i*i`; print `a[1]+a[4]`.
2. (M10) Grid {{1,2,3},{4,5,6}}: print sum of row 1.
3. (M11) "Data-42": count digits via isdigit → prints?
4. (M13) `int x{4}; int* p{&x}; *p = *p + 5; p = nullptr; cout << x;`
5. (M12) Binary search on {2,4,6,8,10}, key 8 — how many mids checked before success?

## Q3 · Debugging (4 × 2 = 8 marks)
1. (M9) Sum loop bound `i < 3` on `int a[4]` — which element is skipped?
2. (M10) Border sum double-counts corners — defect description + one-pass predicate fix.
3. (M12) Binary search `high = n` with `low <= high` — failure mode + the one-discipline fix.
4. (M14) Early `return` inside the allocation loop skips `delete[]` — classify + two fixes.

## Q4 · Short conceptual (4 × 2 = 8 marks)
1. (M10) Signature rule for passing 2-D arrays to functions.
2. (M11) Boundary rule for whole-word "cat" matching.
3. (M14) Why is std::vector the course default over manual new/delete?
4. (M16) What does "has-a" composition mean for Garage/Cars?

## Q5 · Complexity intuition (3 × 2 = 6 marks)
1. Why is insertion sort O(n) on sorted input but O(n²) worst case?
2. Selection sort on 4 elements — exactly how many swaps does pass 0 perform?
3. When does the sortedness investment of binary search pay off, in one sentence?

## Q6 · Algorithm design (3 × 3 = 9 marks)
1. (M12) First-duplicate finder in ≤ 1000 ints: algorithm choice, complexity, boundaries.
2. (M13) Trace-and-correct: design the null-out guard protocol as an algorithm (birth, release, use).
3. (M15) Robust CSV loader: per-line algorithm, skip counting, exit codes.

## Q7 · Coding (4 × 6 = 24 marks)
1. (M9) Second-largest distinct or `N/A` (n up to 100).
2. (M11) Vowel/consonant/digit counts for a whole line.
3. (M12) Insertion sort with per-pass printing.
4. (M16) `Counter` class with guarded `dec()`; main shows rejection at 0.

## Q8 · Code completion (3 × 3 = 9 marks)
1. (M10) Diagonal sum: `diag += g[r]__(a)__[__(b)__];`
2. (M13) Null-out: after `delete[] data;` write the two statements that complete the guard.
3. (M16) `bool spend(int amt)` completion: guard condition and the subtraction operator.

## Q9 · Extended synthesis (18 marks)
Choose ONE:
- **Option 1:** Three more coding items from the G pool (array, string, class), 6 each.
- **Option 2:** Scaled practical variant: extend the CSV loader to also compute mean and max of loaded scores (6 design, 6 code, 6 test table with your own expected outputs).

---
**END**
