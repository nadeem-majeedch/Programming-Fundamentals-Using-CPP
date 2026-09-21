# T05 · Functions

Covers: prototypes, parameters, return values, `void`, pass-by-value,
overloading, decomposition, reference parameters for outputs, `const`
parameters. Lectures L13–L16, L26. Outcomes PF-7.x, PF-8.x, PF-13.x.

12 exercises · ladder 🟢 → 🔴. From E-056 on, decomposition into
functions *is* the graded skill — a correct monolith doesn't earn full
credit.

---

### PF-E-054 · First Function
**Difficulty:** Beginner · **Lecture:** L13 · **Outcomes:** PF-7.1
**Prerequisites:** E-003
**Problem:** Write `int square(int n)` and call it from `main` on the values 3, 7, and −4, printing each result. Write the prototype above `main` and the definition below it.
**Input:** none · **Output:** three squares.
**Sample:** — → `9` / `49` / `16`
**Hints:** prototype, call, definition — three separate locations.

### PF-E-055 · Max of Three (reusing Max of Two)
**Difficulty:** Beginner · **Lecture:** L13 · **Outcomes:** PF-7.1, PF-7.3
**Prerequisites:** E-054
**Problem:** Write `int max2(int a, int b)`, then write `int max3(int a, int b, int c)` that *calls* `max2` twice. Read three integers and print the maximum.
**Input:** three integers · **Output:** one integer.
**Sample:** `5 9 2` → `9`
**Hints:** `max2(a, max2(b, c))` — composition is the point.

### PF-E-056 · Temperature Suite
**Difficulty:** Foundational · **Lecture:** L13 · **Outcomes:** PF-7.1, PF-7.2
**Prerequisites:** E-004, E-055
**Problem:** Write `double toFahrenheit(double c)` and `double toKelvin(double c)`. Read a Celsius temperature and print a small table (C, F, K) for that value and for 0, 25, 100.
**Input:** one double · **Output:** 4 rows × 3 columns, labeled.
**Sample:** input `37.0` → row `37.0 98.6 310.2`
**Hints:** both functions take Celsius — no function calls another conversion.

### PF-E-057 · Even/Odd/Prime Classifier Functions
**Difficulty:** Foundational · **Lecture:** L13 · **Outcomes:** PF-7.1, PF-7.2
**Prerequisites:** E-039, E-056
**Problem:** Write `bool isEven(int)`, `bool isOdd(int)`, and `bool isPrime(int)`. Read one integer (2–1000) and print all three classifications. isOdd must call isEven.
**Input:** one integer · **Output:** three words.
**Sample:** `17` → `even: no` / `odd: yes` / `prime: yes`
**Hints:** isPrime reuses your E-039 loop, wrapped in a bool return.

### PF-E-058 · Multiplication-Table Generator
**Difficulty:** Foundational · **Lecture:** L13 · **Outcomes:** PF-7.1, PF-7.2
**Prerequisites:** E-029, E-057
**Problem:** Write `void printTable(int n, int rows)` that prints n × 1 … n × rows in aligned columns (width 6). `main` reads n and rows and calls it.
**Input:** two integers · **Output:** the table.
**Sample:** `7 5` → `     7    14    21    28    35` (one per line)
**Hints:** a `void` function does the printing; `main` does the reading — separation of I/O.

### PF-E-059 · Rounding and Casting Helpers
**Difficulty:** Foundational · **Lecture:** L13 · **Outcomes:** PF-7.1, PF-3.2
**Prerequisites:** E-056
**Problem:** Write `int roundToNearest(double x)` (round half away from zero, correctly handling negatives) and `double truncateTo2(double x)` (truncate toward zero to 2 decimals). Demonstrate both on `2.5, -2.5, 3.14159, -3.14159`.
**Input:** none · **Output:** labeled results.
**Sample:** `round(2.5) = 3` / `round(-2.5) = -3` / `trunc2(3.14159) = 3.14`
**Hints:** rounding: compare `x - static_cast<int>(x)`; truncation: `static_cast<int>(x * 100) / 100.0` — think about why negatives work.

### PF-E-060 · Min/Max/Average with Out-Parameters
**Difficulty:** Intermediate · **Lecture:** L26 · **Outcomes:** PF-8.1, PF-13.3
**Prerequisites:** E-057, E-031
**Problem:** Write `void stats(double a, double b, double c, double& minOut, double& maxOut, double& avgOut)`. Read three doubles and print the three results using the out-parameters. Also demonstrate (in comments) that a by-value version cannot deliver the same results.
**Input:** three doubles · **Output:** min, max, average.
**Sample:** `4.5 2 9` → `min: 2` / `max: 9` / `avg: 5.17`
**Hints:** three reference parameters; the by-value comment is part of the deliverable.

### PF-E-061 · Function Overloading: area()
**Difficulty:** Intermediate · **Lecture:** L15 · **Outcomes:** PF-8.1
**Prerequisites:** E-060
**Problem:** Write three overloaded `double area(...)`: circle (one double), rectangle (two doubles), triangle (base and height — same signature problem: use three doubles for triangle by Heron's formula with sides). Demonstrate each; explain in comments how the compiler picks.
**Input:** none (fixed demonstration calls) · **Output:** labeled areas.
**Sample:** — → `circle r=2: 12.57` / `rect 3x4: 12.00` / `triangle 3-4-5: 6.00`
**Hints:** rect vs triangle can't both be (double, double) — Heron takes three sides.

### PF-E-062 · Recursive Countdown + Sum
**Difficulty:** Intermediate · **Lecture:** L16 · **Outcomes:** PF-8.2
**Prerequisites:** E-061
**Problem:** Write `void countdown(int n)` (prints n..1 then `done`) and `long long sumTo(int n)` (1+2+…+n), both **recursive**. Read n (1–500) and demonstrate both. Add a comment: what happens with n = 0 for each, and why?
**Input:** one integer · **Output:** countdown lines, sum, note.
**Sample:** n = 3 → `3 2 1 done` / `sum: 6`
**Hints:** base case first; recursion is introduced in L16 as a *concept*, keep the calls shallow.

### PF-E-063 · Unit Conversion Library
**Difficulty:** Intermediate · **Lecture:** L15 · **Outcomes:** PF-8.1, PF-8.2
**Prerequisites:** E-062
**Problem:** Build `convert.cpp` with functions: `kmToMiles`, `milesToKm`, `kgToLbs`, `lbsToKg`, `cToF`, `fToC`. Each validates its domain (non-negative where sensible) and returns a sentinel `-1` on invalid input. `main` offers a small `switch` menu driving them.
**Input:** menu choice + value · **Output:** converted value or error.
**Sample:** choice 1, value `10` → `10 km = 6.21 miles`
**Hints:** the menu loop is do-while; conversion factors as `const double`.

### PF-E-064 · Deadduck Debugging (fix the signatures)
**Difficulty:** Intermediate · **Lecture:** L26 · **Outcomes:** PF-8.1, PF-13.3
**Prerequisites:** E-060, E-063
**Problem:** You are given (in comments) five *broken* function designs: (1) a `swap` by value, (2) a "returns two values" function, (3) an array parameter with no size, (4) a read-only string taken by value, (5) a getter that prints instead of returning. For each: state the defect in one line, then write the corrected version and demonstrate it.
**Input:** none · **Output:** five demonstration blocks.
**Sample:** — → `defect 1: copies cannot swap → fixed with int&` …
**Hints:** the fixes use references, split returns, size parameters, `const&`, and return values respectively.

### PF-E-065 · Menu-Driven Geometry Toolkit
**Difficulty:** Advanced Introductory · **Lecture:** L16 · **Outcomes:** PF-8.1, PF-8.2, PF-5.3
**Prerequisites:** E-063, E-064
**Problem:** Write a menu program: 1) circle area 2) rectangle area 3) triangle area (Heron) 4) quit. Each computation lives in its own function; input validation lives in a reusable `double readPositive(const std::string& prompt)`; the menu loops until quit; invalid menu choices are rejected with a re-prompt (bounded to 5 bad attempts then quit). Print results with 2 decimals.
**Input:** menu choices + values · **Output:** computed areas or errors.
**Sample:** choice 1, r = 2 → `12.57`; choice 9 → re-prompt.
**Hints:** `readPositive` is the reusable validator — every other function assumes clean input; that division of labor is the design lesson.
