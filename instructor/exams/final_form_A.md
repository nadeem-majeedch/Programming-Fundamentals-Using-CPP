# Final Examination — Form A
**Programming Fundamentals Using C++ · All 16 modules · 180 minutes · 100 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
All items are drawn from the Modules 9–16 pool; Modules 9–16 carry 76 % of the marks
(≥ 60 % required), and the section skills themselves are cumulative from Modules 1–8.

## Q1 · MCQ (8 × 1 = 8 marks)
1. `[M9]` Valid indices of `int a[8]`: A. 1..8 B. 0..8 C. 0..7 D. 1..7
2. `[M10]` Row-major traversal: A. outer columns B. outer rows, inner columns C. diagonal D. reverse
3. `[M11]` `s.find("xy")` absent returns: A. 0 B. −1 C. npos D. throws
4. `[M12]` Binary search requires: A. unique values B. sorted data C. numeric data D. linked structure
5. `[M13]` `p++` on `int* p` advances by: A. bit B. byte C. one element D. always 8 bytes
6. `[M14]` `new int[10]` pairs with: A. delete B. delete[] C. free D. nothing
7. `[M15]` `!in` after open tests: A. empty B. open failure C. read error D. EOF
8. `[M16]` Private members accessible from: A. anywhere B. class members (+friends) C. derived only D. same file

## Q2 · Output tracing (5 × 2 = 10 marks)
1. (M9) `{4,1,7}` max-tracker prints?
2. (M11) `s{"hello"}: cout << s.size() << ' ' << s.substr(1,3);`
3. (M12) Selection sort pass 0 on {5,2,9,1}: array becomes?
4. (M14) `struct P{int x;}; P a{3}; P b{a}; b.x=9; cout << a.x;`
5. (M16) `c.set(7); cout << c.get();` with private `int x_{0};`

## Q3 · Debugging (4 × 2 = 8 marks)
1. (M9) `for (int i{0}; i <= 3; ++i) sum += a[i];` on `int a[3]` — defect class and fix.
2. (M11) getline reads an empty line right after `cin >> age;` — cause + course fix.
3. (M13) Crash on second use after `delete p;` — name the hazard and both guards.
4. (M16) `withdraw(999999)` on balance 500 succeeds — which invariant, where is validation placed?

## Q4 · Short conceptual (4 × 2 = 8 marks)
1. (M9) Why initialize max from `a[0]` rather than 0?
2. (M12) Binary search's precondition and its guarantee.
3. (M13) When is a reference parameter preferable to a pointer?
4. (M15) Course exit-code discipline (0/1/2).

## Q5 · Complexity intuition (3 × 2 = 6 marks)
1. Linear search, n = 1000, absent key — about how many comparisons?
2. Binary search, n = 1000 — about how many?
3. Measured counters: binary ≈ 10, linear ≈ 1000. One sentence on scaling to n = 10⁶.

## Q6 · Algorithm design (3 × 3 = 9 marks)
1. (M11) Whole-word "cat" counter — boundary predicate that rejects "category".
2. (M14) Top-N report from parallel arrays using a struct — which defect class disappears?
3. (M15) Robust CSV loader (name,score): per-line algorithm, skip counting, exit codes.

## Q7 · Coding (4 × 6 = 24 marks)
1. (M9) Read n (1..100) + n ints; print second-largest distinct or `N/A`.
2. (M11) Count vowels, consonants, digits in a whole input line.
3. (M12) Insertion sort `int a[], int n`; print array after each pass.
4. (M16) Class `Counter`: private count (0), `inc()`, guarded `dec()` → bool, `value() const`; main shows the rejected decrement.

## Q8 · Code completion (3 × 3 = 9 marks)
1. (M9) In-place reversal: `for (int i{0}, j{n-1}; i __(a)__ j; ++i, __(b)__) { swap }`
2. (M14) Guarded allocation: fill loop, then `__(a)__[] data;` then `data = __(b)__;`
3. (M16) Wallet: `if (amt < 0 __(a)__ amt > balance_) return false; balance_ __(b)__ amt;`

## Q9 · Extended synthesis (18 marks)
Choose ONE:
- **Option 1:** Three more coding items from the G pool (one array-processing, one string-processing, one class-based), 6 marks each.
- **Option 2:** Scaled practical variant: extend Q7.4's Counter with `reset()` and a 3-case main; 6 marks design + 6 marks code + 6 marks test table (your own cases with expected outputs).

---
**END**
