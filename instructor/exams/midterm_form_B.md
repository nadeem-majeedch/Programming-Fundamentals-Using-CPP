# Midterm Examination — Form B
**Programming Fundamentals Using C++ · Weeks 1–8 · 100 minutes · 50 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form B differs from Form A in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (6 × 1 = 6 marks)
1. `[M1]` The stage that handles `#include`: A. assembler B. linker C. preprocessor D. optimizer
2. `[M2]` `sizeof(int)` is: A. guaranteed 2 B. typically 4, implementation-defined C. always 8 D. equals sizeof(char)
3. `[M3]` `2 + 3 * 4 % 5` = A. 20 B. 14 C. 4 D. 0
4. `[M4]` `switch` rejects controlling type: A. int B. char C. std::string D. long
5. `[M5]` `do { } while (c);` guarantees: A. body never runs B. at least one pass C. c true at entry D. termination
6. `[M6]` A boundary test set for an n-item loop is: A. one typical value B. n = 0, 1, larger C. only large n D. negative only

## Q2 · Output tracing (4 × 2 = 8 marks)
1. (M3) `int a{7}, b{2}; cout << a/b << ' ' << a%b;`
2. (M5) `int t{0}; for (int i{1}; i <= 10; ++i){ if (i%2==0) continue; if (i>7) break; t += i;} cout << t;`
3. (M8) `int g(int n){return n<=0?0:n+g(n-2);} cout << g(7);`
4. (M6) Digit reversal loop, input 508 — output?

## Q3 · Debugging (3 × 2 = 6 marks)
1. (M2) Inner `int total{v};` shadows the accumulator; total prints 0.
2. (M4) Switch prints "Low" for x==2 as well as 1 (case 1 lacks break).
3. (M8) `int fact(int n){return n*fact(n-1);}` — overflows the stack for any input.

## Q4 · Short conceptual (3 × 2 = 6 marks)
1. (M2) Why is `double` avoided for exact money totals in course design discussions?
2. (M6) What is a trace table and what defect classes does it expose?
3. (M7) Why return a value instead of printing inside a function?

## Q5 · Algorithm design (2 × 3 = 6 marks)
1. (M6) Pseudocode + IPO + boundaries: read ints until 0; print second-largest distinct or `N/A`.
2. (M8) Convert "sum of squares 1..n" to recursion; state base case and shrinking measure.

## Q6 · Coding (3 × 4 = 12 marks)
1. (M4) Read three ints; print the median value.
2. (M5) Read ints until sentinel 0; print count, sum, mean (2 dp) or `no data`.
3. (M7) `bool isPerfect(int n)` + print all ≤ 10000.

## Q7 · Code completion (2 × 3 = 6 marks)
1. (M5) Reversal visit order: `for (int i{0}; i __(a)__ n/2; ++i) swap(a[i], a[__(b)__]);`
2. (M7) `safeDivide`: `if (b == __(a)__) return false; out = __(b)__ / __(a)__; return __(c)__;`

---
**END**
