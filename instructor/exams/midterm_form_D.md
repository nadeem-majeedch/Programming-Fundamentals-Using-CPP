# Midterm Examination — Form D
**Programming Fundamentals Using C++ · Weeks 1–8 · 100 minutes · 50 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form D differs from Forms A–C in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (6 × 1 = 6 marks)
1. `[M1]` An algorithm is: A. a program B. precise numbered steps solving a task C. hardware D. a file format
2. `[M2]` `std::fixed << std::setprecision(2)` on 3.14159 prints: A. 3.14 B. 3.1 C. 3.142 D. 3
3. `[M3]` `x += 3` is equivalent to: A. x = 3 B. x = x + 3 C. x =+ 3 D. x == 3
4. `[M4]` `fee = hours > 5 ? 20 : 10;` assigns: A. 20 always B. 10 always C. 20 if hours>5 else 10 D. 10 if hours>5 else 20
5. `[M5]` The priming read belongs to: A. for loops B. sentinel while loops C. do-while D. infinite loops
6. `[M6]` Trace tables are produced: A. only after running B. by hand, before/without running C. by the linker D. only recursively

## Q2 · Output tracing (4 × 2 = 8 marks)
1. (M3) `int x{5}; x += 3 * 2; cout << x;`
2. (M5) `int n{25}, c{0}; while (n > 0){ n /= 2; ++c; } cout << c;`
3. (M7) `int f(int x){return x*x-1;} cout << f(3) + f(4);`
4. (M8) `int g(int n){return n<=0?0:n+g(n-2);} cout << g(7);`

## Q3 · Debugging (3 × 2 = 6 marks)
1. (M2) `(a+b)/2` prints 3 for inputs 3 and 4 — expected 3.5.
2. (M8) Recursive digitSum has no base case — state the missing piece.
3. (M6) Validation accepts the empty first entry in a do-while loop — identify the structural cause.

## Q4 · Short conceptual (3 × 2 = 6 marks)
1. (M2) Name the property of brace initialization that rejects `int x{2.9};`.
2. (M6) Give the three IPO stages for "second-largest distinct value" tracking.
3. (M7) What belongs in a function's contract comment? (pre/post, one example each)

## Q5 · Algorithm design (2 × 3 = 6 marks)
1. (M6) Pseudocode + IPO + boundaries: second-largest distinct until 0, or `N/A`.
2. (M8) Recursive digit reversal: base case, shrinking measure, and why the accumulator is a parameter.

## Q6 · Coding (3 × 4 = 12 marks)
1. (M5) Sentinel-0 stats: count, sum, mean (2 dp) or `no data`.
2. (M4) Median of three integers.
3. (M7) `bool isPerfect(int n)` + all ≤ 10000.

## Q7 · Code completion (2 × 3 = 6 marks)
1. (M5) `for (int i{30}; i >= 3; i __(a)__) cout << i;` — every third downward.
2. (M7) `clamp`: `if (v < lo) return __(a)__; if (v > hi) return __(b)__; return __(c)__;`

---
**END**
