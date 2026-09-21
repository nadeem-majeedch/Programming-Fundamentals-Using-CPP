# T01 · Variables and Calculations

Covers: declaration, initialization, types, `const`, arithmetic, operator
precedence, type conversion, `static_cast`, formatted output.
Lectures L03–L06 (and L01–L02 warm-ups). Outcomes PF-1.x, PF-2.x, PF-3.x.

13 exercises · difficulty ladder runs 🟢 → 🔴.

---

### PF-E-001 · Hello, You
**Difficulty:** Beginner · **Lecture:** L01 · **Outcomes:** PF-1.1
**Prerequisites:** none
**Problem:** Print two lines: `Hello, world!` then `Ready to learn C++.` Compile and run.
**Input:** none · **Output:** exactly the two lines.
**Sample:** — → `Hello, world!` / `Ready to learn C++.`
**Hints:** one statement per line of output; end each with `\n`.

### PF-E-002 · Blank-Frame Printer
**Difficulty:** Beginner · **Lecture:** L02 · **Outcomes:** PF-1.1
**Prerequisites:** E-001
**Problem:** Print a 5-line frame of asterisks (width 12) with two blank interior lines.
**Input:** none · **Output:** the frame.
**Sample:** — → `************` / `` / `` / `` / `************`
**Hints:** count the lines before typing; every line is a separate statement.

### PF-E-003 · Age in Days
**Difficulty:** Beginner · **Lecture:** L03 · **Outcomes:** PF-2.1
**Prerequisites:** E-001
**Problem:** Read an age in whole years; print the (approximate) age in days, assuming 365 days per year.
**Input:** one integer (years) · **Output:** one integer (days).
**Sample:** `20` → `7300`
**Hints:** one multiplication; store the result in a variable before printing.

### PF-E-004 · Temperature Converter (C→F)
**Difficulty:** Beginner · **Lecture:** L03 · **Outcomes:** PF-2.1, PF-3.2
**Prerequisites:** E-003
**Problem:** Read a Celsius temperature (may have decimals); print Fahrenheit with one decimal place.
**Input:** one double · **Output:** one double, one decimal place.
**Sample:** `36.6` → `97.9`
**Hints:** F = C × 9/5 + 32; use `9.0/5.0` — why does `9/5` fail?

### PF-E-005 · Circle Report
**Difficulty:** Beginner · **Lecture:** L03 · **Outcomes:** PF-2.1, PF-2.3
**Prerequisites:** E-004
**Problem:** Read a radius; print diameter, circumference, and area, each labeled, each with 2 decimals. Declare π as a `const double`.
**Input:** one double (radius) · **Output:** three labeled values.
**Sample:** `2.5` → `diameter: 5.00` / `circumference: 15.71` / `area: 19.63`
**Hints:** `const double PI{3.141592653589793};`

### PF-E-006 · Receipt Line
**Difficulty:** Beginner · **Lecture:** L04 · **Outcomes:** PF-2.2, PF-2.3
**Prerequisites:** E-005
**Problem:** Read an item name (one word), unit price, and quantity. Print a fixed-width receipt line: name left-aligned width 12, quantity width 4, total price (price × qty) width 10 with 2 decimals.
**Input:** string, double, int · **Output:** one formatted line.
**Sample:** `Mouse 499.50 3` → `Mouse             3    1498.50`
**Hints:** `<iomanip>`: `std::setw`, `std::left`, `std::fixed`, `std::setprecision`.

### PF-E-007 · Digit Splitter
**Difficulty:** Foundational · **Lecture:** L05 · **Outcomes:** PF-3.1, PF-3.3
**Prerequisites:** E-003
**Problem:** Read a two-digit integer; print its tens digit and units digit, separated by a space. Then print their sum and product.
**Input:** one integer 10–99 · **Output:** digits, then sum, then product.
**Sample:** `47` → `4 7` / `sum: 11` / `product: 28`
**Hints:** `% 10` and `/ 10`; no strings allowed.

### PF-E-008 · Seconds Decomposer
**Difficulty:** Foundational · **Lecture:** L05 · **Outcomes:** PF-3.1
**Prerequisites:** E-007
**Problem:** Read a total number of seconds; print it as hours, minutes, seconds.
**Input:** one non-negative integer · **Output:** `H:MM:SS` with zero-padded minutes/seconds.
**Sample:** `7385` → `2:03:05`
**Hints:** `std::setw(2) << std::setfill('0')` for padding; decompose from the largest unit.

### PF-E-009 · Coin Change (Static)
**Difficulty:** Foundational · **Lecture:** L05 · **Outcomes:** PF-3.1, PF-3.3
**Prerequisites:** E-008
**Problem:** Read an amount in cents (0–999); print the fewest coins (25, 10, 5, 1) that make it.
**Input:** one integer (cents) · **Output:** four labeled counts.
**Sample:** `187` → `25c: 7` / `10c: 1` / `5c: 0` / `1c: 2`
**Hints:** greedy: take as many of the largest coin as possible, then move down.

### PF-E-010 · Swap Visualization
**Difficulty:** Foundational · **Lecture:** L05 · **Outcomes:** PF-3.1, PF-3.2
**Prerequisites:** E-003
**Problem:** Read two integers into `a` and `b`. Print them, swap their values using a temporary variable, and print them again. Then predict (in a comment) what happens without the temporary — and demonstrate it in a second, labeled block.
**Input:** two integers · **Output:** values before and after each swap.
**Sample:** `3 8` → `before: 3 8` / `after good swap: 8 3` / `after bad swap: 0 8`
**Hints:** the "bad swap" is `a = b; b = a;` — trace why the first value is lost.

### PF-E-011 · Expression Forensics
**Difficulty:** Intermediate · **Lecture:** L05 · **Outcomes:** PF-3.1, PF-3.4
**Prerequisites:** E-007, E-009
**Problem:** Given the declarations `int a{7}; double b{2.0}; int c{3};`, write a program that prints the value and type-behavior of five expressions: `a / c`, `a / b`, `a % c`, `a + b * c`, `(a + b) * c`. First write your predicted answers in comments, then print actual values and compare.
**Input:** none · **Output:** five labeled lines with actual values.
**Sample:** — → `a/c: 2` / `a/b: 3.5` / …
**Hints:** decide integer vs floating-point per expression *before* compiling.

### PF-E-012 · Salary Calculator
**Difficulty:** Intermediate · **Lecture:** L06 · **Outcomes:** PF-2.1, PF-3.2
**Prerequisites:** E-006, E-011
**Problem:** Read hourly wage, regular hours, and overtime hours. Overtime pays 1.5×. Compute gross pay, deduct 11% income tax and 180 fixed transport levy, print a payslip (gross, each deduction, net) with aligned columns and 2 decimals.
**Input:** double, double, double · **Output:** four labeled money values.
**Sample:** `50 40 5` → `gross: 2375.00` / `tax: 261.25` / `levy: 180.00` / `net: 1933.75`
**Hints:** compute overtime at the multiplied rate; one variable per payslip line keeps printing trivial.

### PF-E-013 · Deterministic Chaos (Integer Overflow)
**Difficulty:** Advanced Introductory · **Lecture:** L06 · **Outcomes:** PF-3.2, PF-3.4
**Prerequisites:** E-011
**Problem:** Starting from `int n{1};`, repeatedly print `n`, then compute `n *= 10; n += 7;` ten times, printing each step. After each step also print the value computed as `long long` from the same formula. Write a short comment explaining exactly where (and why) the `int` version stops matching the `long long` version.
**Input:** none · **Output:** 10 lines: step, int value, long long value.
**Sample:** first lines → `1: 17 17` / `2: 177 177` / … then they diverge.
**Hints:** `int` is 32-bit on our toolchain — *typical, not guaranteed* (say so in the comment).
