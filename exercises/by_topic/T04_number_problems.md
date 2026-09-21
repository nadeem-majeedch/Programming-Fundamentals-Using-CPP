# T04 · Number Problems

Covers: classic number algorithms — divisibility, digit tricks, series,
number-theory-lite, numeric reasoning combining loops and conditions.
Lectures L09–L11 (builds on loops/conditions; feeds search/sort fluency).
Outcomes PF-5.2–PF-5.4, PF-6.x.

11 exercises · ladder 🟢 → 🔴. Distinct from T03: these are *algorithmic*
tasks **about numbers**; T03 tasks were about **loop mechanics** themselves.

---

### PF-E-043 · Even/Odd Reporter (range)
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.1, PF-4.1
**Prerequisites:** E-027, E-016
**Problem:** Read two integers `lo` ≤ `hi` (−50 to 50). Print each number in the range labeled `even` or `odd`, all on one line, space-separated.
**Input:** two integers · **Output:** one line of labeled numbers.
**Sample:** `3 6` → `3 odd 4 even 5 odd 6 even`
**Hints:** `% 2` inside the loop; negative numbers: `-3 % 2` is `-1` in C++ — handle it.

### PF-E-044 · Multiples Counter
**Difficulty:** Beginner · **Lecture:** L09 · **Outcomes:** PF-5.2, PF-4.1
**Prerequisites:** E-043
**Problem:** Read `k` (2–9) and `n` (1–1000). Count how many integers in 1..n are divisible by k, and print their sum.
**Input:** two integers · **Output:** count and sum.
**Sample:** `3 10` → `count: 3` / `sum: 18`
**Hints:** `i % k == 0` — accumulate two things in one loop.

### PF-E-045 · Perfect Number Check
**Difficulty:** Foundational · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-044, E-039
**Problem:** Read n (1–10,000). A number is *perfect* if it equals the sum of its proper divisors. Print `perfect` or `not perfect`, then list the divisors found.
**Input:** one integer · **Output:** verdict + divisor list.
**Sample:** `28` → `perfect (1 2 4 7 14)`
**Hints:** loop divisors to √n in pairs (i and n/i) to keep it fast.

### PF-E-046 · GCD (Euclid, iterative)
**Difficulty:** Foundational · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-045
**Problem:** Read two positive integers; compute their GCD with the Euclidean algorithm (while loop, `%`), and print the GCD and the number of reduction steps.
**Input:** two integers · **Output:** GCD + steps.
**Sample:** `48 36` → `gcd: 12` / `steps: 3`
**Hints:** `while (b != 0) { t = b; b = a % b; a = t; }` — trace once by hand.

### PF-E-047 · Armstrong Numbers (range)
**Difficulty:** Foundational · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-032
**Problem:** Print all Armstrong numbers (a number equal to the sum of its digits each raised to the digit-count power) between 1 and 999, one per line, with their digit decomposition in parentheses.
**Input:** none · **Output:** the list.
**Sample:** `153 (1^3 + 5^3 + 3^3)` is among the lines.
**Hints:** nest the digit-extraction loop inside the range loop; digit count varies per number.

### PF-E-048 · Binary Representation
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-033, E-047
**Problem:** Read a non-negative integer (< 2³¹); print its binary representation (no leading zeros; `0` prints as `0`). Build it with `% 2` / `/ 2` arithmetic only — no bitset.
**Input:** one integer · **Output:** one binary string.
**Sample:** `13` → `1101`
**Hints:** remainders come out reversed — reuse the reversal idea or collect then reverse.

### PF-E-049 · Prime Twins Gap Report
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-039, E-045
**Problem:** For all primes p ≤ 500, find consecutive prime pairs (p, q) with q − p = 2. Print each twin pair, then print how many twin pairs were found and the largest gap between consecutive primes in that range.
**Input:** none · **Output:** pairs + two summary numbers.
**Sample:** `(3, 5) (5, 7) (11, 13) …` / `pairs: …` / `largest gap: …`
**Hints:** generate primes once into an array (or reuse a helper); track previous prime to compute gaps.

### PF-E-050 · Harmonic Series with Cutoff
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.2, PF-3.2
**Prerequisites:** E-030, E-012
**Problem:** Sum H = 1 + 1/2 + 1/3 + … until the first term that is smaller than a read threshold ε (0.001–0.5). Print the number of terms used and the partial sum (6 decimals).
**Input:** one double · **Output:** terms + sum.
**Sample:** `0.1` → `terms: 11` / `H: 3.019877`
**Hints:** loop with `double term = 1.0 / i;` — floating comparison `<` (not `==`).

### PF-E-051 · Palindromic Number Iterator
**Difficulty:** Intermediate · **Lecture:** L10 · **Outcomes:** PF-5.3
**Prerequisites:** E-033
**Problem:** Read bounds `lo` ≤ `hi` (1–100,000). Print all palindromic numbers in the range (one line, space-separated), then their count.
**Input:** two integers · **Output:** list + count.
**Sample:** `120 131` → `121 131` / `count: 2`
**Hints:** reuse E-033's reversal as the palindrome test — numbers only, no strings.

### PF-E-052 · Collatz Longest Chain Under N
**Difficulty:** Advanced Introductory · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-041
**Problem:** Read N (2–10,000). Find the starting value ≤ N whose Collatz chain is longest; print that start, its chain length, and the chain's peak. Ties: smallest start wins.
**Input:** one integer · **Output:** start, length, peak.
**Sample:** `10` → `start: 9` / `length: 19` / `peak: 52`
**Hints:** reuse E-041's chain logic per candidate; track best (length, start) pairs carefully.

### PF-E-053 · Goldbach Verification Sweep
**Difficulty:** Advanced Introductory · **Lecture:** L10 · **Outcomes:** PF-5.3, PF-5.4
**Prerequisites:** E-049
**Problem:** For every even number 4 ≤ 2k ≤ 200, find *one* pair of primes (p, q), p ≤ q, with p + q = 2k. Print each even number with its pair, and print `verified` when all cases succeed.
**Input:** none · **Output:** 99 lines + `verified`.
**Sample:** `4 = 2 + 2` / `6 = 3 + 3` / `10 = 3 + 7`
**Hints:** primality helper + a nested search loop with early exit once a pair is found.
