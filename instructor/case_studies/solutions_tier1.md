# Tier 1 Instructor Companion — CS-001–CS-010

Per case: expected concepts · common incorrect approaches · discussion
points · solution outline · worked solution · test cases · extension.
Worked solutions for CS-001–008 were compiled and executed (see audit
report); CS-009–010 are design-level with verified outlines.

---

## PF-CS-001 · The Vending Machine

**Expected concepts:** state (accumulator), loop termination, remainder
arithmetic, algorithm-as-numbered-steps (PF-1.1, PF-5.1).

**Common incorrect approaches:**
- Counting *coins* instead of totaling *value* (a 25 is not "one unit of credit").
- Checking `total == 45` exactly — misses overpay; dispense must fire at `total >= 45`.
- Forgetting to define behavior when the customer aborts mid-transaction (refund path).

**Discussion points:** What is the machine's *memory* (one int)? Why does
"walk away" need a rule even though no input signals it (time-out policy —
a design decision, not code)? Connect to L01's algorithm = state + steps.

**Solution outline:**
1. `total = 0`.
2. Loop: read coin; `total += coin`.
3. If `total >= 45`: dispense; change = `total − 45`; stop.
4. If customer aborts: refund `total`.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-001 — vending machine simulator
#include <iostream>

int main()
{
    const int PRICE{45};
    int total{0};
    int coin{0};

    while (total < PRICE && std::cin >> coin)
    {
        if (coin == 5 || coin == 10 || coin == 25)
            total += coin;
        else
            std::cout << "rejected coin " << coin << '\n';
    }

    if (total >= PRICE)
        std::cout << "dispense; change " << total - PRICE << '\n';
    else
        std::cout << "aborted; refund " << total << '\n';
    return 0;
}
```

**Test cases:**

| Input | Expected output |
|---|---|
| `25 10 10` | `dispense; change 0` |
| `25 25` | `dispense; change 5` |
| `10 5` then EOF | `aborted; refund 15` |
| `30` | `rejected coin 30` (then continues/aborts per remaining input) |

**Extension:** two item prices (45 and 60) with an item-choice step —
which checks change order?

---

## PF-CS-002 · Three-Cup Order

**Expected concepts:** comparison logic, minimal comparisons, order of
operations (PF-3.1, PF-4.1).

**Common incorrect approaches:**
- Fixed two comparisons ("A<B and B<C") — misses A vs C entirely.
- Swapping mentally without stating which comparisons are *needed* vs *sufficient*.
- Claiming 2 comparisons suffice: two binary results = 4 outcomes < 6 orderings.

**Discussion points:** Information-theory flavor: each comparison yields 1
bit; 3! = 6 orderings need ⌈log₂ 6⌉ = 3. Equal values: stability of the
method. Bridge to L07's if/else and to sorting later (L22).

**Solution outline:**
1. Compare A,B → smaller is a minimum candidate, larger a maximum candidate.
2. Compare the B-loser with C for the true minimum.
3. Compare the A-winner with C for the true maximum; middle is the remainder.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-002 — three-way order with comparison count
#include <iostream>

int main()
{
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;
    int comparisons{0};
    int lo{a}, hi{a};

    ++comparisons;                       // a vs b
    if (b < a) lo = b; else hi = b;
    ++comparisons;                       // loser vs c for min
    if (c < lo) lo = c;
    ++comparisons;                       // winner vs c for max
    if (c > hi) hi = c;

    int mid{a + b + c - lo - hi};
    std::cout << lo << ' ' << mid << ' ' << hi << '\n'
              << "comparisons: " << comparisons << '\n';
    return 0;
}
```

**Test cases:**

| Input | Expected output |
|---|---|
| `3 1 2` | `1 2 3`, comparisons 3 |
| `5 5 5` | `5 5 5`, comparisons 3 |
| `9 2 7` | `2 7 9`, comparisons 3 |

**Extension:** prove 2 comparisons cannot distinguish all 6 orderings.

---

## PF-CS-003 · The Receipt Printer

**Expected concepts:** type selection, `iomanip` field widths, fixed
precision (PF-2.3, PF-2.4).

**Common incorrect approaches:**
- Storing price in `int` (truncates 12.50) or quantity in `double` (invites 2.5 items).
- Forgetting `std::fixed` before `setprecision` (precision then means significant digits).
- Computing line total as int product.

**Discussion points:** Money as double is a course-level simplification —
flag that professionals use integer cents (revisited in CS-025). Widths vs
precision are different knobs.

**Solution outline:** read string, double, int; print with
`setw(12) << name`, `setw(8) << fixed << setprecision(2) << price`,
`setw(4) << qty`, total = price×qty same formatting.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-003 — aligned receipt line
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::string name;
    double price{0.0};
    int qty{0};
    std::cin >> name >> price >> qty;

    double total{price * qty};
    std::cout << std::left << std::setw(12) << name
              << std::right << std::fixed << std::setprecision(2)
              << std::setw(8) << price
              << std::setw(4) << qty
              << std::setw(10) << total << '\n';
    return 0;
}
```

**Test cases:**

| Input | Expected output (columns 12,8,4,10) |
|---|---|
| `Pen 12.5 3` | `Pen            12.50   3     37.50` |
| `Notebook 49.99 10` | `Notebook       49.99  10    499.90` |

**Extension:** n receipt lines + a grand-total line — which accumulator?

---

## PF-CS-004 · Elevator Logic

**Expected concepts:** decision tables, complete case coverage, equality
branch (PF-4.1).

**Common incorrect approaches:**
- Two branches only (`cur<req` → up, else down) — "else" silently eats STAY.
- Testing only the happy paths 1→2, 2→1 in traces.

**Discussion points:** The decision table *is* the specification; code is
its transcription. Ask: how do you prove 4 cells covered? (Enumerate them
— the table's whole point.)

**Solution outline:**

| cur | req | verdict |
|---|---|---|
| 1 | 1 | STAY |
| 1 | 2 | MOVE UP |
| 2 | 1 | MOVE DOWN |
| 2 | 2 | STAY |

Code: `if (cur == req) STAY; else if (cur < req) UP; else DOWN;`

**Worked solution (compiled ✓):**

```cpp
// PF-CS-004 — elevator decision table
#include <iostream>

int main()
{
    int cur{}, req{};
    std::cin >> cur >> req;

    if (cur == req)
        std::cout << "STAY\n";
    else if (cur < req)
        std::cout << "MOVE UP\n";
    else
        std::cout << "MOVE DOWN\n";
    return 0;
}
```

**Test cases:** all four cells: `1 1`→STAY, `1 2`→MOVE UP, `2 1`→MOVE
DOWN, `2 2`→STAY.

**Extension:** 3 floors + a door-open state that blocks movement —
add the guard branch.

---

## PF-CS-005 · The Grading Curve Debate

**Expected concepts:** if/else-if ladder semantics, first-true-wins,
threshold ordering (PF-4.2).

**Common incorrect approaches:**
- Belving ladder order is irrelevant "because each test is exact".
- Testing `>= 60` first: a 95 gets D and the ladder never re-checks.

**Discussion points:** score 95 on the reversed ladder: 95≥60 → D. One
counterexample kills the design. Generalize: with `>=` tests, sort
thresholds descending; with `<=`, ascending.

**Solution outline:** ladder `if (s>=90) A else if (s>=80) B ... else F`.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-005 — correct ladder order
#include <iostream>

int main()
{
    int s{};
    std::cin >> s;
    char grade;
    if (s >= 90)       grade = 'A';
    else if (s >= 80)  grade = 'B';
    else if (s >= 70)  grade = 'C';
    else if (s >= 60)  grade = 'D';
    else               grade = 'F';
    std::cout << grade << '\n';
    return 0;
}
```

**Test cases:** `95`→A, `90`→A, `89`→B, `0`→F, `60`→D, `59`→F.

**Extension:** add the ± system (A− 87–89) — where do the extra branches go?

---

## PF-CS-006 · Parking Fee

**Expected concepts:** ceiling arithmetic, tiered pricing, cap logic
(PF-4.2, PF-3.1).

**Common incorrect approaches:**
- Billing `hours − 1` even for 1 hour (negative extra!).
- Using floating ceil on ints; integer math is cleaner: any part-hour = next hour.
- Applying the cap before computing extras.

**Discussion points:** billed hours = hours (arrival≠departure means ≥1
hour). Extra hours = hours−1. Fee = min(50+30×extra, 200). 24h stay:
50+30×23=740 → capped 200.

**Solution outline:** 1) hours = dep−arr. 2) extra = hours−1. 3) fee =
50+30×extra. 4) if fee>200, fee=200.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-006 — garage fee with cap
#include <iostream>
#include <algorithm>

int main()
{
    int arr{}, dep{};
    std::cin >> arr >> dep;
    int hours{dep - arr};
    int fee{50 + 30 * (hours - 1)};
    std::cout << std::min(fee, 200) << '\n';
    return 0;
}
```

**Test cases:**

| arr, dep | hours | fee |
|---|---|---|
| 9, 10 | 1 | 50 |
| 9, 10.5→(9,11) | 2 | 80 |
| 0, 24 | 24 | 200 (capped) |
| 8, 9 | 1 | 50 |

**Extension:** per-15-minute granularity — what changes in the ceiling?

---

## PF-CS-007 · Password Strength Meter

**Expected concepts:** character classification, flag variables, early
exit, `<cctype>` (PF-4.4, PF-5.2).

**Common incorrect approaches:**
- Using `else` between categories (a char can be both uppercase AND in an 8+ password — but per-char categories are exclusive; the *flags* are independent).
- Testing `isdigit(password)` on the whole string instead of per character.
- Counting length in a loop when `size()` exists.

**Discussion points:** Four independent booleans; the loop finds three.
Early exit per flag vs one combined pass — trade-offs. (One pass tracking
all flags is optimal.)

**Solution outline:** flags digit/upper/symbol = false. One pass: set
flags via cctype; symbol = !alnum. Score = (len≥8) + digit + upper + symbol.
Ladder → label.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-007 — password strength
#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string pw;
    std::cin >> pw;

    bool hasDigit{false}, hasUpper{false}, hasSymbol{false};
    for (char ch : pw)
    {
        unsigned char u{static_cast<unsigned char>(ch)};
        if (std::isdigit(u)) hasDigit = true;
        else if (std::isupper(u)) hasUpper = true;
        else if (!std::isalnum(u)) hasSymbol = true;
    }

    int score{(pw.size() >= 8 ? 1 : 0) + (hasDigit ? 1 : 0)
            + (hasUpper ? 1 : 0) + (hasSymbol ? 1 : 0)};
    const char* label = score <= 1 ? "WEAK" : score == 2 ? "FAIR"
                      : score == 3 ? "GOOD" : "STRONG";
    std::cout << label << '\n';
    return 0;
}
```

**Test cases:**

| Password | Score | Label |
|---|---|---|
| `abc` | 0 | WEAK |
| `abcdefg1` | 2 | FAIR |
| `Abcdefg1` | 3 | GOOD |
| `Abcdef1!` | 4 | STRONG |

**Extension:** forbid adjacent repeats (reuses CS-026's adjacency idea).

---

## PF-CS-008 · The Countdown Timer

**Expected concepts:** for vs while choice, mm:ss formatting, inclusive
bounds (PF-5.1, PF-2.3).

**Common incorrect approaches:**
- Looping `> 0` and never printing 00:00.
- Printing raw seconds and calling it mm:ss; %02d-style padding via iomanip.

**Discussion points:** Inclusive final iteration: `for (int s = n; s >= 0; --s)`.
Why for-loop fits (known count); while equally valid. setw(2)+setfill('0')
gives mm:ss.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-008 — mm:ss countdown
#include <iostream>
#include <iomanip>

int main()
{
    int n{};
    std::cin >> n;
    for (int s{n}; s >= 0; --s)
        std::cout << std::setw(2) << std::setfill('0') << s / 60 << ':'
                  << std::setw(2) << s % 60 << '\n';
    return 0;
}
```

**Test cases:** `65` → `01:05` … `00:00` (66 lines, first `01:05`, last
`00:00`); `1` → `00:01`, `00:00`; `600` → first `10:00`.

**Extension:** stop at a pause key value — sentinel inside the countdown.

---

## PF-CS-009 · Coin Split for Pocket Money (design-level)

**Expected concepts:** greedy correctness argument, integer division
(PF-3.2, PF-6.2).

**Common incorrect approaches:** working from smallest coin (needs proof
too, and obfuscates); forgetting amounts not multiple of 5 (excluded by
constraints — say so).

**Discussion points:** Greedy safe because each denomination divides the
value structure cleanly: after 25s, remainder <25 is expressible in
10s/5s (any multiple of 5 <25 is: 5,10,15,20 — check each). Counterexample
culture: with a 7-coin, 14 = 7+7 beats greedy 10+? — greedy breaks.

**Solution outline:** n25 = amt/25; r=amt%25; n10=r/10; r%=10; n5=r/5.

**Test cases:** 95 → 3×25, 2×10, 0×5; 40 → 1,1,1; 5 → 0,0,1; 0 → all 0.

**Extension:** prove optimality: any solution using fewer big coins needs
more small coins — same total count or worse.

---

## PF-CS-010 · The Secret Number Hunt (design-level)

**Expected concepts:** binary search *idea* pre-dating L23, invariants,
logarithmic intuition (PF-5.4, PF-6.3).

**Common incorrect approaches:**
- Random guessing with no memory (expected ~100 tries vs 7).
- Halving the *value* not the *range*; forgetting to update the range after each guess.

**Discussion points:** Invariant: secret ∈ [lo, hi] always. Choosing mid
and hearing HIGH/LOW discards half the range. 2⁷ = 128 > 100 → ≤7 guesses.
This is binary search wearing a game costume — flag the L23 connection.

**Solution outline:** lo=1, hi=100; guess mid=(lo+hi)/2; HIGH → hi=mid−1;
LOW → lo=mid+1; repeat until correct.

**Test cases (mental trace):** secret 37: guesses 50(H),25(L),37✓ — 3
guesses. Secret 1: 50,25,12,6,3,1(HI?),... trace carefully — 7 max.
Secret 100: 50,75,88,94,97,99,100 — 7.

**Extension:** worst-case count for 1–1000 (10); for 1–n generally (⌈log₂ n⌉).
