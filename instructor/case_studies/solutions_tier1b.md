# Tier 1 Instructor Companion — CS-011–CS-020

Same structure as part 1. Worked solutions for CS-011, CS-013, CS-015,
CS-016, CS-017 were compiled and executed (see audit report); the rest are
design-level with verified outlines.

---

## PF-CS-011 · Traffic Light Cycle

**Expected concepts:** modular arithmetic replacing simulation, range
mapping (PF-3.2, PF-5.1).

**Common incorrect approaches:**
- Simulating second-by-second with a loop — O(t); the mod insight is O(1).
- Wrong boundaries: YELLOW is seconds 30–34 *inclusive* (5 seconds).

**Discussion points:** t mod 55 ∈ [0,54] locates the second within one
cycle; ranges map to colors. Connect: same trick as day-of-week from
epoch days. Generalization question in the case (per-direction cycles) is
about parameters, not new math.

**Solution outline:** r = t % 55; r<30 GREEN; r<35 YELLOW; else RED.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-011 — signal color by cycle position
#include <iostream>

int main()
{
    long long t{};
    std::cin >> t;
    long long r{t % 55};
    if (r < 30)
        std::cout << "GREEN\n";
    else if (r < 35)
        std::cout << "YELLOW\n";
    else
        std::cout << "RED\n";
    return 0;
}
```

**Test cases:** t=0→GREEN, 29→GREEN, 30→YELLOW, 34→YELLOW, 35→RED,
54→RED, 55→GREEN (wraps), 10⁶→RED (r=10? 10⁶ mod 55: 10⁶=55×18181+45→45
RED ✓).

**Extension:** second input = direction offset; same math, shifted phase.

---

## PF-CS-012 · Rainfall Logger (design-level)

**Expected concepts:** accumulators, max-update discipline, tie policy
(PF-5.2).

**Common incorrect approaches:**
- Initializing max to 0 — breaks all-dry input... unless you *define* max
  as 0.0 for all-zero data: the tie policy decides. State it!
- Re-initializing accumulators inside the loop.

**Discussion points:** Day numbering: 1-based vs 0-based must be declared.
Ties: first occurrence vs last — either is defensible, silence is not.
Hint 3's "or can 0 be right?" is the discussion seed.

**Solution outline:** total, dry, bestVal (init first reading),
bestDay=1; loop from day 2: update best on >. All-zero case: bestVal=0.0,
bestDay=1 — correct under "first tie wins" policy.

**Test cases:** `3 0 0 0` → total 0, max 0.0 day 1, dry 3. `4 5 12 12 3`
→ max 12 day 2 (first tie). `1 7` → max 7 day 1, dry 0.

**Extension:** wettest *week* (7-day sliding window) — preview of L18.

---

## PF-CS-013 · The Cashier's Change Maker

**Expected concepts:** greedy with denominations, loop over parallel data
(PF-5.2, PF-6.2).

**Common incorrect approaches:**
- Seven nested ifs instead of one loop over a denomination array.
- Wrong remainder order (must go largest→smallest, updating remainder each pass).

**Discussion points:** Invariant: after processing coin c, remaining < c.
Why 20 exists in the set and greedy still works (20 divides the 10/5/1
tail cleanly). Minimal-count proof sketch mirrors CS-009.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-013 — change with denomination loop
#include <iostream>

int main()
{
    const int DENOMS[7]{500, 100, 50, 20, 10, 5, 1};
    int price{};
    std::cin >> price;
    int change{1000 - price};

    std::cout << "change: " << change << '\n';
    for (int d : DENOMS)
    {
        int count{change / d};
        change %= d;
        if (count > 0)
            std::cout << d << ": " << count << '\n';
    }
    return 0;
}
```

**Test cases:**

| price | change | breakdown |
|---|---|---|
| 350 | 650 | 500×1, 100×1, 50×1 |
| 987 | 13 | 10×1, 1×3 |
| 1000 | 0 | (no lines) |
| 495 | 505 | 500×1, 5×1 |

**Extension:** make change from a limited coin tray (counts per
denomination) — greedy needs a guard now.

---

## PF-CS-014 · Class Attendance Percentages (design-level)

**Expected concepts:** integer-vs-double division trap, static_cast,
two-level accumulation (PF-2.4, PF-5.2).

**Common incorrect approaches:**
- `count/16*100` in int math → 0 for counts <16.
- Averaging the *rounded* percentages instead of computing the class mean
  from raw counts (or vice versa — the policy must be stated).

**Discussion points:** Where exactly does the cast go?
`static_cast<double>(count)/16*100`. Class average: sum of raw counts /
(16n) — different from mean of percentages? (Equal mathematically; rounding
at print differs.) Great precision-policy discussion.

**Solution outline:** per student: pct = cast; accumulate raw counts at
class level; class avg = cast(sum)/(16n); print both at 1 dp.

**Test cases:** one student 12/16 → 75.0; class of 1 avg 75.0.
12 and 16 → avg 87.5. 0/16 → 0.0 (valid, not absent).

**Extension:** flag students below 75% — threshold policy discussion.

---

## PF-CS-015 · The Left-to-Right Largest

**Expected concepts:** running maximum, one-pass counting (PF-5.2).

**Common incorrect approaches:**
- Re-scanning all predecessors for each scout — O(n²), unneeded.
- Counting ties as records (`>=`) — "equal height" blocks the view equally;
  standard definition says not a record.

**Discussion points:** The running max *summarizes* the prefix — the whole
point of the pattern. First scout always counts (empty prefix). Bridge to
L17 arrays: same loop, stored data.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-015 — record-breaking scouts
#include <iostream>

int main()
{
    int n{};
    std::cin >> n;
    int records{0};
    int best{-1};
    for (int i{0}; i < n; ++i)
    {
        int h{};
        std::cin >> h;
        if (i == 0 || h > best)
        {
            ++records;
            best = h;
        }
    }
    std::cout << records << '\n';
    return 0;
}
```

**Test cases:** `5 170 165 180 180 175` → 2 (170, 180 — tie not counted).
`1 200` → 1. `4 100 101 102 103` → 4.

**Extension:** count from the *right* too; a scout visible from both ends
is special — find them.

---

## PF-CS-016 · Sum Until the Sentinel

**Expected concepts:** sentinel loops, priming read, loop-and-a-half
avoidance (PF-5.3).

**Common incorrect approaches:**
- Processing the sentinel (total includes −1) because the check comes after the update.
- Missing the priming read; the loop condition tests garbage.
- Sentinel inside the legal range — design flaw students must name.

**Discussion points:** Two canonical shapes: priming read + while, and
read-inside-loop with break. Which keeps exit condition visible? Why
−1 cannot be a legal fare (constraints say 1..500).

**Worked solution (compiled ✓):**

```cpp
// PF-CS-016 — sentinel total
#include <iostream>

int main()
{
    const int SENTINEL{-1};
    int fare{};
    std::cin >> fare;                    // priming read
    int total{0}, count{0};
    while (fare != SENTINEL)
    {
        total += fare;
        ++count;
        std::cin >> fare;
    }
    std::cout << count << " fares, total " << total << '\n';
    return 0;
}
```

**Test cases:** `100 200 -1` → `2 fares, total 300`. `-1` → `0 fares,
total 0`. Trailing sentinel only after data — always.

**Extension:** reject out-of-range fares mid-stream (count them) — nested
validation.

---

## PF-CS-017 · The Pyramid Builder

**Expected concepts:** nested loops, fence-post spaces, formula-first
design (PF-5.4).

**Common incorrect approaches:**
- Space count off by one (h−i vs h−i−1 depending on 0/1-based rows).
- Stars loop bound tied to the wrong variable.

**Discussion points:** Derive the formula from h=3 by hand BEFORE code:
row1: 2 spaces 1 star; row2: 1,2; row3: 0,3 → spaces = h−i (i 1-based).
Fence-post thinking: n gaps vs n posts.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-017 — centered star pyramid
#include <iostream>

int main()
{
    int h{};
    std::cin >> h;
    for (int i{1}; i <= h; ++i)
    {
        for (int s{0}; s < h - i; ++s)
            std::cout << ' ';
        for (int k{0}; k < i; ++k)
            std::cout << '*';
        std::cout << '\n';
    }
    return 0;
}
```

**Test cases:** h=1 → `*`. h=3 →
```
  *
 **
***
```
h=15 runs without overflow (width 29).

**Extension:** hollow pyramid (border stars only) — predicate per cell.

---

## PF-CS-018 · Bus Fare Zoner (design-level)

**Expected concepts:** branch elimination, conditional operator, boundary
equivalence (PF-4.2, PF-6.1).

**Common incorrect approaches:**
- Applying the per-km rate to all km (first 5 km double-charged).
- Off-by-one at exactly 5 km (fare is 20, not 25).

**Discussion points:** max(0, km−5) is the whole branch in one expression
— is it clearer than if/else? Test the seam: km=5 → 20; km=6 → 25. Both
forms must agree on every input (exhaustive check for km ≤ 100 is
feasible — mention loop-based testing).

**Solution outline:** fare = 20 + 5*max(0, km−5); equivalently if/else.

**Test cases:** 1→20, 5→20, 6→25, 100→495.

**Extension:** day cap + child discount — composition of policies.

---

## PF-CS-019 · The Recipe Scaler (design-level)

**Expected concepts:** scale factors, rounding at the boundary, why order
matters (PF-3.1, PF-6.1).

**Common incorrect approaches:**
- Rounding each ingredient to int *then* scaling (compounding error).
- Integer scale factor k/4 (loses 3/4, 5/4...).

**Discussion points:** Compute exact: amount × k / 4.0; round to nearest
5 at the END: 5*floor(x/5+0.5). Discussion: does rounding to 5 g ever
change proportions materially? (For small amounts, yes — state the
threshold policy.)

**Solution outline:** factor = k/4.0; scaled = amt*factor; printed =
5*floor(scaled/5+0.5).

**Test cases:** k=6, amt=100 → 150.0 → 150; amt=50 → 75 → 75; k=3,
amt=100 → 75 → 75; k=1, amt=7 → 1.75 → nearest 5 = 0 (discuss: floor
policy or minimum-5 rule — kitchen pragmatics!).

**Extension:** preserve *ratios* under rounding: scale then adjust largest
ingredient to absorb rounding drift.

---

## PF-CS-020 · Exam Averages with an Absence Rule (design-level)

**Expected concepts:** counting-while-summing, zero-division guard,
policy transparency (PF-5.2, PF-4.2).

**Common incorrect approaches:**
- Averaging with count=3 always (absences as 0 — destroys the mean).
- Returning 0 for all-absent (indistinguishable from a real 0).

**Discussion points:** The −1 flag is a *presence* marker, not data. The
comparability question (2-test vs 3-test averages) has no technical
answer — it's a policy. Make students defend: flag, asterisk, or
per-test-type normalization.

**Solution outline:** sum,count over non-negative scores; count==0 →
print −1 (or `ABS`); else sum/count. Class-level: report how many
all-absent.

**Test cases:** `80 90 -1` → 85.0. `-1 -1 -1` → ABS. `0 0 0` → 0.0
(valid, distinct from ABS).

**Extension:** weighted average (final worth more) — weights must sum to
1; who validates that?
