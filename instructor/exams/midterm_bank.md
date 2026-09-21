# Midterm Question Bank — Weeks 1–8 (L01–L16)
**INSTRUCTOR-ONLY.** 42 items · 94 marks in pool (papers select subsets).
Tags: `[type · module · lecture · CLO · difficulty · marks]`.

Difficulty legend: E = easy, M = medium, H = hard.
Type legend: MCQ / TRACE / DEBUG / SHORT / DESIGN / CODE / CCOMP (code completion).

Answers are in the **Answer** line immediately after each item — keep together
when printing instructor copies; strip for papers. All tracing and coding answers
below were machine-verified with GCC 16.2 under the course contract (see
`ASSESSMENT_AUDIT.md` §5).

---

## Section A — MCQ (8 items · 1 mark each · CLO-1/2/3)

**A1** `[MCQ · M1 · L01 · CLO-1 · E · 1]`
Which tool combines object files and libraries into an executable?
A. preprocessor  B. compiler  C. assembler  D. linker
**Answer:** D

**A2** `[MCQ · M2 · L03 · CLO-2 · E · 1]`
Which declaration rejects the initializer 2.9 at compile time?
A. `int x = 2.9;`  B. `int x{2.9};`  C. `double x{2.9};`  D. `int x(2.9);`
**Answer:** B — brace initialization forbids narrowing.

**A3** `[MCQ · M2 · L04 · CLO-2 · E · 1]`
`cin >> a >> b;` with input `4 9` gives:
A. a=4, b=9  B. a=49, b=0  C. a=4, b=4  D. error
**Answer:** A — whitespace-separated extraction.

**A4** `[MCQ · M3 · L05 · CLO-2 · E · 1]`
`7 / 2` evaluates to:
A. 3.5  B. 3  C. 4  D. 3 r 1
**Answer:** B — integer division truncates.

**A5** `[MCQ · M3 · L06 · CLO-2 · M · 1]`
After `int n{5}; n += n++ * 2;` the standard says this expression is:
A. well-defined, n == 15  B. well-defined, n == 16  C. undefined (unsequenced modification)  D. a compile error
**Answer:** C — modifying n twice without sequencing is UB; accept "unsequenced/undefined".

**A6** `[MCQ · M4 · L07 · CLO-3 · E · 1]`
For ladder grading, thresholds must be tested:
A. ascending  B. descending  C. any order  D. with switch only
**Answer:** B

**A7** `[MCQ · M4 · L08 · CLO-3 · E · 1]`
`switch(x)` is illegal when x is:
A. int  B. char  C. std::string  D. long
**Answer:** C

**A8** `[MCQ · M5 · L09 · CLO-3 · E · 1]`
How many times does `for (int i{0}; i < 5; ++i)` run its body?
A. 4  B. 5  C. 6  D. 0
**Answer:** B

---

## Section B — Output tracing (10 items · 2 marks each · CLO-2/3/5)

**B1** `[TRACE · M2 · L03 · CLO-2 · E · 2]`
```cpp
int a{7}, b{2};
std::cout << a / b << " " << a % b << '\n';
```
**Answer:** `3 1`

**B2** `[TRACE · M3 · L05 · CLO-2 · E · 2]`
```cpp
int x{2};
x += 3 * 4 % 5;
std::cout << x << '\n';
```
**Answer:** `4` (12 % 5 = 2; 2 + 2 = 4)

**B3** `[TRACE · M3 · L06 · CLO-2 · M · 2]`
```cpp
int s{0};
for (int i{1}; i <= 3; ++i)
    s += i * i;
std::cout << s << '\n';
```
**Answer:** `14` (1 + 4 + 9)

**B4** `[TRACE · M5 · L10 · CLO-3 · M · 2]`
```cpp
int n{25}, count{0};
while (n > 0) { n /= 2; ++count; }
std::cout << count << '\n';
```
**Answer:** `5` (25→12→6→3→1→0; the halving count of 25)

**B5** `[TRACE · M5 · L10 · CLO-3 · M · 2]`
```cpp
int total{0};
for (int i{1}; i <= 10; ++i) {
    if (i % 2 == 0) continue;
    if (i > 7) break;
    total += i;
}
std::cout << total << '\n';
```
**Answer:** `16` (1 + 3 + 5 + 7)

**B6** `[TRACE · M7 · L13 · CLO-5 · M · 2]`
```cpp
int f(int x) { return x * x - 1; }
int main() { std::cout << f(3) + f(4) << '\n'; }
```
**Answer:** `24` (8 + 16)

**B7** `[TRACE · M7 · L14 · CLO-5 · M · 2]`
```cpp
void tweak(int a, int& b) { ++a; ++b; }
int main() {
    int p{4}, q{4};
    tweak(p, q);
    std::cout << p << " " << q << '\n';
}
```
**Answer:** `4 5` (a is a copy; b is a reference)

**B8** `[TRACE · M8 · L15 · CLO-5 · H · 2]`
```cpp
int g(int n) { return n <= 0 ? 0 : n + g(n - 2); }
int main() { std::cout << g(7) << '\n'; }
```
**Answer:** `16` (7 + 5 + 3 + 1)

**B9** `[TRACE · M8 · L16 · CLO-5 · H · 2]`
```cpp
void shadow() { int x{99}; std::cout << x; }
int x{1};
int main() { std::cout << x; shadow(); std::cout << x << '\n'; }
```
**Answer:** `1991`

**B10** `[TRACE · M6 · L12 · CLO-4 · M · 2]`
```cpp
// digit reversal loop; input n = 508
int rev{0};
while (n > 0) { rev = rev * 10 + n % 10; n /= 10; }
std::cout << rev << '\n';
```
**Answer:** `805`

---

## Section C — Debugging (8 items · 2 marks each · CLO-2/3/5)

**C1** `[DEBUG · M2 · L04 · CLO-2 · E · 2]`
Program prints `total: 0` for input 3 4 5 instead of 12.
```cpp
int total{};                    // A
for (int i{0}; i < 3; ++i) {
    int v{};
    std::cin >> v;
    int total{v};               // B
    total += v;                 // C
}
std::cout << "total: " << total << '\n';
```
**Answer:** Line B shadows the accumulator — a *new local* `total` is created per iteration. Delete line B and C's shadow; accumulate into the outer `total` (`total += v;`).

**C2** `[DEBUG · M5 · L09 · CLO-3 · E · 2]`
Sentinel loop with `-1` never stops reading.
```cpp
int v{};
std::cin >> v;
while (v != -1) { std::cout << v << '\n'; }
```
**Answer:** Missing update — no re-read inside the loop. Add `std::cin >> v;` at the end of the body (priming read exists; update read missing).

**C3** `[DEBUG · M4 · L08 · CLO-3 · M · 2]`
Switch prints `Low` for x == 2 as well as 1.
```cpp
switch (x) {
    case 1:  std::cout << "Low";
    case 2:  std::cout << "Mid"; break;
    default: std::cout << "High";
}
```
**Answer:** Fall-through: case 1 lacks `break`, so it falls into case 2. Add `break;` after the "Low" print.

**C4** `[DEBUG · M7 · L13 · CLO-5 · M · 2]`
Function returns the right answer but the caller's variable never changes.
```cpp
void normalize(double& v) { if (v > 100) v = 100; }
// caller:  double t{250}; normalize(t);  // t still 250
```
**Answer:** The code shown is correct as a signature — the defect is at the call site: the caller passed a copy (e.g., `normalize(t + 0)`, a literal, or an unwrapped local). Fix: pass a named lvalue, `normalize(t);`. Accept an answer explaining that temporaries cannot bind to non-const lvalue references.

**C5** `[DEBUG · M3 · L06 · CLO-2 · M · 2]`
Average of inputs 3 and 4 prints 3 instead of 3.5.
```cpp
int a{}, b{};
std::cin >> a >> b;
std::cout << (a + b) / 2 << '\n';
```
**Answer:** Integer division. Fix: `(a + b) / 2.0` (or `static_cast<double>(a + b) / 2`).

**C6** `[DEBUG · M8 · L15 · CLO-5 · M · 2]`
Factorial of 0 hangs/stack-overflows.
```cpp
int fact(int n) { return n * fact(n - 1); }
```
**Answer:** No base case; n decreases forever. Add `if (n <= 1) return 1;` before the recursive call (and note fact(0) then correctly returns 1).

**C7** `[DEBUG · M5 · L10 · CLO-3 · H · 2]`
Count-down from n prints n values then one extra 0.
```cpp
while (n >= 0) { std::cout << n << '\n'; --n; }
```
**Answer:** Off-by-one boundary — `>=` includes 0, printing n+1 values. Fix per spec: `n > 0` if zero must not print (or accept spec "inclusive of zero" if intended — the *defect* is a mismatch between spec and boundary).

**C8** `[DEBUG · M6 · L11 · CLO-4 · M · 2]`
Validation loop accepts the empty first entry.
```cpp
std::string name;
do { std::getline(std::cin, name); } while (name == "");
std::cout << "ok: " << name << '\n';
```
**Answer:** do-while runs before any check and the *first* empty getline falls through on the second empty line only — actually the defect: condition `name == ""` exits when empty is *entered twice*, because the loop only re-tests after the second read. Taught fix: while-form with the test *before* use: `while (!(std::getline(std::cin, name)) || name.empty());` or explicit re-prompt loop.
*(Grading note: accept any answer that identifies do-while's test-after-body as the cause.)*

---

## Section D — Short conceptual (6 items · 2 marks each · CLO-1/4/5)

**D1** `[SHORT · M1 · L01 · CLO-1 · E · 2]`
Explain, in one sentence each, the difference between a *syntax error*, a *runtime error*, and a *logic error*, with one example of each.
**Answer:** Syntax error — caught by the compiler (missing `;`). Runtime error — occurs during execution (failed `cin` at EOF, out-of-range vector index). Logic error — compiles and runs, wrong behavior (sum initialized to 1).

**D2** `[SHORT · M2 · L03 · CLO-2 · E · 2]`
Why does the course prefer brace initialization (`int x{5};`)?
**Answer:** It forbids narrowing conversions, so `int x{2.9};` is a compile error instead of a silent truncation.

**D3** `[SHORT · M6 · L11 · CLO-4 · M · 2]`
State the three IPO stages for "average of a sentinel-terminated list of scores."
**Answer:** Input — scores until sentinel; Processing — accumulate count and sum, divide once at end; Output — the single average (guard count == 0).

**D4** `[SHORT · M6 · L12 · CLO-4 · M · 2]`
What is a trace table and what is its pedagogical purpose?
**Answer:** A per-iteration table of variable values; it makes loop behavior predictable *before* running and exposes off-by-one and initialization defects.

**D5** `[SHORT · M7 · L13 · CLO-5 · E · 2]`
Why return a computed value rather than print it inside a function?
**Answer:** Returning makes the function testable and reusable; printing hard-codes one side effect and prevents composition.

**D6** `[SHORT · M8 · L16 · CLO-5 · H · 2]`
When is recursion preferable to iteration? Give one concrete pattern from this course.
**Answer:** When the problem is self-similar with a shrinking argument and an obvious base case — e.g., digit processing (`digitSum`) or divide-and-conquer (later: binary search).

---

## Section E — Algorithm design (4 items · 3 marks each · CLO-4/5)

**E1** `[DESIGN · M6 · L12 · CLO-4 · M · 3]`
Design (pseudocode + IPO + boundary set) a program that reads integers until 0 and prints the second-largest distinct value or `N/A` if fewer than two distinct values appeared.
**Answer:** Track `best` and `second` as int sentinels (use "none" flags or very small values); per input v: skip v == 0; if v == best or v == second continue; if best is none → best = v; else if v > best → second = best, best = v; else if second is none or v > second → second = v. Boundaries: no input (N/A), one distinct (N/A), all equal (N/A), negative inputs, second arrives after best. Complexity O(1) memory.

**E2** `[DESIGN · M6 · L12 · CLO-4 · M · 3]`
Produce a decision table for a campus parking fee: first 30 min free; ≤ 2 h: 20; ≤ 5 h: 50; > 5 h: 50 + 10 per extra hour beyond 5, capped at 120. Include the boundary minutes.
**Answer:** Table rows: t ≤ 30 → 0; 30 < t ≤ 120 → 20; 120 < t ≤ 300 → 50; 300 < t → min(120, 50 + 10·⌈(t−300)/60⌉). Boundaries: 30, 31, 120, 121, 300, 301, cap-reached (≥ 490).

**E3** `[DESIGN · M7 · L14 · CLO-5 · M · 3]`
Decompose "print a receipts block for n purchased items with prices and a 17% tax line" into functions; give each signature and its contract (pre/post).
**Answer:** `double readPrice(int item)` (pre: item ≥ 1; post: returns a price ≥ 0); `double subtotal(const double p[], int n)` (pre: n ≥ 0; post: returns Σp); `double taxOf(double s)` (pre: s ≥ 0; post: returns 0.17·s); `void printLine(label, amount)` (post: formatted line). Main composes.

**E4** `[DESIGN · M8 · L16 · CLO-5 · H · 3]`
Convert this iterative specification to a recursive one and state the base case(s) and shrinking measure: "sum of squares 1..n".
**Answer:** `sos(n) = n<=0 ? 0 : n*n + sos(n-1)`; base case n ≤ 0 → 0; shrinking measure: n decreases by 1. (Alternative: halving form `sos2(lo, hi)`; either accepted if invariants stated.)

---

## Section F — Coding (4 items · 5 marks each · CLO-2/3/5)

**F1** `[CODE · M2 · L04 · CLO-2 · E · 5]`
Read a temperature as a double and print it in both °C and °F rounded to 1 decimal (formula F = 9C/5 + 32). Validate that the input succeeded.
**Answer:**
```cpp
#include <iostream>
#include <iomanip>
int main()
{
    double c{};
    if (!(std::cin >> c)) { std::cout << "bad input\n"; return 1; }
    double f{9.0 * c / 5.0 + 32.0};
    std::cout << std::fixed << std::setprecision(1)
              << c << "C = " << f << "F\n";
    return 0;
}
```
Verified: 36.6 → `36.6C = 97.9F`.

**F2** `[CODE · M4 · L07 · CLO-3 · E · 5]`
Read three integers and print the median (middle value when sorted).
**Answer:**
```cpp
#include <iostream>
#include <algorithm>
int main()
{
    int a{}, b{}, c{};
    if (!(std::cin >> a >> b >> c)) return 1;
    int mx{std::max({a, b, c})}, mn{std::min({a, b, c})};
    std::cout << a + b + c - mx - mn << '\n';
    return 0;
}
```
Verified: 3 9 5 → `5`; equal values fine (1 1 2 → `1`).

**F3** `[CODE · M5 · L09 · CLO-3 · M · 5]`
Read integers until sentinel 0; print count, sum, and mean (2 decimals) of the non-zero values; print `no data` if none.
**Answer:**
```cpp
#include <iostream>
#include <iomanip>
int main()
{
    int count{0}; long long sum{0}; int v{};
    while (std::cin >> v && v != 0) { ++count; sum += v; }
    if (count == 0) { std::cout << "no data\n"; return 0; }
    std::cout << count << ' ' << sum << ' '
              << std::fixed << std::setprecision(2)
              << static_cast<double>(sum) / count << '\n';
    return 0;
}
```
Verified: `4 5 0` → `2 9 4.50`; `4 5 6 0` → `3 15 5.00`; immediate `0` → `no data`.

**F4** `[CODE · M7 · L13 · CLO-5 · M · 5]`
Write `bool isPerfect(int n)` (sum of proper divisors equals n) and a main that prints all perfect numbers ≤ 10000.
**Answer:**
```cpp
#include <iostream>
bool isPerfect(int n)
{
    if (n < 2) return false;
    int sum{1};
    for (int d{2}; d * d <= n; ++d)
        if (n % d == 0) { sum += d; int o{n / d}; if (o != d) sum += o; }
    return sum == n;
}
int main()
{
    for (int n{2}; n <= 10000; ++n)
        if (isPerfect(n)) std::cout << n << '\n';
    return 0;
}
```
Verified: prints `6 28 496 8128`.

---

## Section G — Code completion (2 items · 3 marks each · CLO-3/5)

**G1** `[CCOMP · M5 · L10 · CLO-3 · M · 3]`
Complete the loop so it prints every third number from 3 to 30 inclusive.
```cpp
for (int i{/*(a)*/}; i <= 30; i /*(b)*/) {
    std::cout << i << ' ';
}
```
**Answer:** (a) `3`  (b) `+= 3`

**G2** `[CCOMP · M7 · L14 · CLO-5 · M · 3]`
Complete the function so `clamp(v, lo, hi)` returns v forced into [lo, hi].
```cpp
int clamp(int v, int lo, int hi)
{
    if (v /*(a)*/ lo) return lo;
    if (v > /*(b)*/) return hi;
    /*(c)*/;
}
```
**Answer:** (a) `<`  (b) `hi`  (c) `return v`

---

### Pool marks total
8·1 + 10·2 + 8·2 + 6·2 + 4·3 + 4·5 + 2·3 = 8 + 20 + 16 + 12 + 12 + 20 + 6 = **94 marks across 42 items** (papers select subsets to reach their blueprint totals — see `PAPER_ASSEMBLY.md`).
