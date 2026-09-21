# Midterm Examination — Form A
**Programming Fundamentals Using C++ · Weeks 1–8 · 100 minutes · 50 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.

## Q1 · MCQ (6 × 1 = 6 marks)
Circle exactly one answer per item.

1. `[M1]` The tool that combines object files into an executable: A. preprocessor B. compiler C. assembler D. linker
2. `[M2]` `int x{2.9};` is: A. stores 2 B. stores 3 C. compile error D. UB
3. `[M3]` `9 % 4` evaluates to: A. 2 B. 1 C. 2.25 D. 0
4. `[M4]` Grade ladder thresholds must be tested: A. ascending B. descending C. any order D. via switch
5. `[M5]` `for (int i{0}; i < 5; ++i)` runs: A. 4 B. 5 C. 6 D. n−1 times
6. `[M6]` IPO stands for: A. Input-Process-Output B. Iterate-Parse-Order C. Input-Program-Object D. Instruction-Parse-Order

## Q2 · Output tracing (4 × 2 = 8 marks)
Show the exact output.

1. (M3) `int x{2}; x += 3 * 4 % 5; cout << x;`
2. (M3) `int s{0}; for (int i{1}; i <= 3; ++i) s += i * i; cout << s;`
3. (M5) `int n{25}, c{0}; while (n > 0) { n /= 2; ++c; } cout << c;`
4. (M7) `int f(int x){return x*x-1;} cout << f(3)+f(4);`

## Q3 · Debugging (3 × 2 = 6 marks)
For each: state the defect and the minimal fix.

1. (M2) Average of inputs 3 and 4 prints 3. Code: `cout << (a+b)/2;` with int a, b.
2. (M5) Sentinel loop with −1 never stops; body prints v but never re-reads.
3. (M7) `void addTax(double p){p *= 1.17;}` — caller's price unchanged.

## Q4 · Short conceptual (3 × 2 = 6 marks)
1. (M1) Give one example each of a syntax error and a logic error (one sentence each).
2. (M2) Why does the course prefer `int x{5};` over `int x = 5;`?
3. (M6) State the three IPO stages for "average of a sentinel-terminated list."

## Q5 · Algorithm design (2 × 3 = 6 marks)
1. (M6) Decision table for parking fee: ≤30 min free; ≤2 h: 20; ≤5 h: 50; then 10/hour beyond, cap 120. List boundary minutes.
2. (M7) Decompose "receipt for n items with 17% tax" into functions: give signatures and pre/post for each.

## Q6 · Coding (3 × 4 = 12 marks)
1. (M2) Read a double temperature; validate the read; print F = 9C/5 + 32 to 1 decimal.
2. (M5) Read ints until 0; print count, sum, mean (2 dp) of non-zero values, or `no data`.
3. (M7) Write `bool isPerfect(int n)` and print all perfect numbers ≤ 10000.

## Q7 · Code completion (2 × 3 = 6 marks)
1. (M5) Every third number 3..30: `for (int i{__(a)__}; i <= 30; i __(b)__)`
2. (M7) `clamp(v,lo,hi)`: `if (v __(a)__ lo) return lo; if (v > __(b)__) return hi; __(c)__;`

---
**END**
