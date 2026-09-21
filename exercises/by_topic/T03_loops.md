# T03 · Loops

Covers: `while`, `do-while`, `for`, sentinel loops, nested loops,
accumulators, loop invariants, tracing, input-validation loops.
Lectures L09–L10 (and validation threads in L04, L30).
Outcomes PF-5.1–PF-5.4.

13 exercises · ladder 🟢 → 🔴.

---

### PF-E-027 · Count-Up
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.1
**Prerequisites:** E-003
**Problem:** Read `n` (1–20). Print the numbers 1 to n, one per line, with a `for` loop.
**Input:** one integer · **Output:** n lines.
**Sample:** `3` → `1` / `2` / `3`
**Hints:** `for (int i{1}; i <= n; ++i)`.

### PF-E-028 · Count-Down Timer
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.1
**Prerequisites:** E-027
**Problem:** Read a start count (1–20). Print the countdown to 1, then print `LIFT OFF`.
**Input:** one integer · **Output:** countdown lines + final phrase.
**Sample:** `3` → `3` / `2` / `1` / `LIFT OFF`
**Hints:** decrement the counter — don't reuse E-027's loop unchanged.

### PF-E-029 · Multiplication Table (Single)
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.1
**Prerequisites:** E-027
**Problem:** Read a number (2–12) and print its multiplication table from 1× to 12×, each line `n x k = product`.
**Input:** one integer · **Output:** 12 lines.
**Sample:** for `3`: `3 x 1 = 3` … `3 x 12 = 36`
**Hints:** the loop variable is the *multiplier*, not `n`.

### PF-E-030 · Sum of First n Naturals
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.2
**Prerequisites:** E-027
**Problem:** Read `n` (0–10,000). Print the sum 1+2+…+n using a loop (no formula).
**Input:** one integer · **Output:** one integer.
**Sample:** `10` → `55`
**Hints:** accumulate in a variable declared *before* the loop.

### PF-E-031 · Sentinel-Triggered Averager
**Difficulty:** Foundational · **Lecture:** L09 · **Outcomes:** PF-5.2, PF-5.3
**Prerequisites:** E-030
**Problem:** Read integers until the user enters `-1` (which is *not* data). Print how many values were read and their average (2 decimals). If the sentinel arrives first, print `no data`.
**Input:** integers terminated by -1 · **Output:** count and average, or message.
**Sample:** `80 90 70 -1` → `count: 3` / `average: 80.00`
**Hints:** priming read before the loop, update read as the last statement; guard division by zero.

### PF-E-032 · Digit Sum (again, on purpose)
**Difficulty:** Foundational · **Lecture:** L09 · **Outcomes:** PF-5.3
**Prerequisites:** E-007, E-030
**Problem:** Read a positive integer; print the sum of its digits with a `while` loop. Then print how many digits it has.
**Input:** one positive integer · **Output:** two integers.
**Sample:** `907` → `digit sum: 16` / `digits: 3`
**Hints:** the digit-count loop can run in the same pass — count iterations.

### PF-E-033 · Digit Reversal
**Difficulty:** Foundational · **Lecture:** L09 · **Outcomes:** PF-5.3
**Prerequisites:** E-032
**Problem:** Read a positive integer; print it reversed (e.g. 1234 → 4321) using arithmetic only.
**Input:** one positive integer · **Output:** one integer.
**Sample:** `1234` → `4321`
**Hints:** `rev = rev * 10 + n % 10;` per pass — trace it on paper first.

### PF-E-034 · Do-While Age Gate
**Difficulty:** Foundational · **Lecture:** L09 · **Outcomes:** PF-5.1
**Prerequisites:** E-031
**Problem:** Using `do-while`, repeatedly read an age until it is in 3–120. Print the accepted age. Count and print how many attempts were made.
**Input:** integers (possibly invalid first) · **Output:** accepted age + attempts.
**Sample:** `0 200 45` → `accepted: 45` / `attempts: 3`
**Hints:** `do-while` fits because the body must run at least once.

### PF-E-035 · Power Table
**Difficulty:** Foundational · **Lecture:** L09 · **Outcomes:** PF-5.2
**Prerequisites:** E-029
**Problem:** Read a base (2–5) and exponent limit (1–10). Print base^1 through base^k, using a loop that multiplies (no `<cmath>`).
**Input:** two integers · **Output:** k lines.
**Sample:** base 2, k 5 → `2 4 8 16 32` (one per line)
**Hints:** keep a running power; multiply once per pass.

### PF-E-036 · Factorial with Overflow Watch
**Difficulty:** Intermediate · **Lecture:** L09 · **Outcomes:** PF-5.2, PF-5.4
**Prerequisites:** E-035
**Problem:** Read n (0–20). Print n! using `long long`. State (in a printed note) the largest n whose factorial still fits in `int` — determine it experimentally, then print it.
**Input:** one integer · **Output:** factorial + note.
**Sample:** `10` → `3628800` / `note: 13 is the largest safe n for int`
**Hints:** `0! = 1` is a boundary case; compare `long long` accumulation against `int` for the note.

### PF-E-037 · Fibonacci Sequence
**Difficulty:** Intermediate · **Lecture:** L09 · **Outcomes:** PF-5.2, PF-5.4
**Prerequisites:** E-035
**Problem:** Read how many Fibonacci terms to print (1–45). Print them space-separated on one line. Then print the largest term that still fits in `int`.
**Input:** one integer · **Output:** one line of terms + a note.
**Sample:** `8` → `1 1 2 3 5 8 13 21`
**Hints:** two rolling variables; 45 terms fits `long long` but not `int`.

### PF-E-038 · Rectangle of Stars (nested)
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.2, PF-5.3
**Prerequisites:** E-029
**Problem:** Read rows (1–10) and columns (1–10). Print a filled rectangle of `*` with that shape, then print its blank *outline* (border only) of the same size.
**Input:** two integers · **Output:** two rectangles.
**Sample:** `3 5` → filled 3×5 block, then outline with spaces inside.
**Hints:** outline test: row is first/last OR column is first/last.

### PF-E-039 · Prime Checker
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-036
**Problem:** Read n (2–1,000,000). Print `prime` or `composite`, testing divisors only up to √n (integer arithmetic, no `<cmath>`: test `i * i <= n`).
**Input:** one integer · **Output:** one word.
**Sample:** `97` → `prime` / `1000000` → `composite`
**Hints:** break on the first divisor; 2 is the only even prime — handle it before the loop.

### PF-E-040 · Right-Angled Number Triangle
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-038
**Problem:** Read n (1–9). Print a triangle where row r contains the digits 1..r. Then print the *mirrored* version (right-aligned). Compute alignment with loop-controlled spaces, not `setw`.
**Input:** one integer · **Output:** two triangles.
**Sample:** n = 4 → rows `1`, `1 2`, `1 2 3`, `1 2 3 4`, then the right-aligned twin.
**Hints:** the mirror needs a spaces loop whose count *depends on* n − r.

### PF-E-041 · Collatz Length
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-039
**Problem:** Read a starting value (1–10,000). Repeatedly apply: even → n/2, odd → 3n+1, until n = 1. Print the number of steps taken and the largest value reached. Print `invalid` for non-positive starts.
**Input:** one integer · **Output:** steps + peak, or message.
**Sample:** `6` → `steps: 8` / `peak: 16`
**Hints:** track the peak in the same loop; the sequence always reaches 1 for these inputs.

### PF-E-042 · Number Pyramid with Digit Rules
**Difficulty:** Advanced Introductory · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-040, E-041
**Problem:** Read rows (1–15). Print a centered pyramid where row r contains the digits of r² reversed, separated by single spaces (e.g. row 3 → `9 1` because 3² = 91 reversed... compute r², extract digits, print in reverse order). Center by padding with `(rows − r)` space-pairs. Validate rows; for rows > 9 the squares are multi-digit — your digit loop must handle that.
**Input:** one integer · **Output:** the pyramid.
**Sample:** rows = 4 → `1` / `4` / `9 1` / `61 6`
**Hints:** reuse E-033's reversal logic per row; centering is a spaces loop.
