# Tier 2 Instructor Companion — CS-021–CS-040

Per case: expected concepts · common incorrect approaches · discussion
points · solution outline · worked solution · test cases · extension.
Worked solutions marked **compiled ✓** were built with the course
contract and executed; others are design-level with verified outlines.

---

## PF-CS-021 · Leap Year Interrogation

**Expected concepts:** boolean composition, pure functions, minimal test
sets (PF-7.1, PF-4.1).

**Common incorrect approaches:** `y%4==0` alone (1900 is not leap);
nested ifs that double-test divisibility; testing years only near today.

**Discussion points:** The minimal branch-covering set: {2000 (400-rule
true), 1900 (100-rule true, 400 false), 2024 (plain), 2023 (false)}.
One-expression vs nesting: both correct; the expression is *testable in
one assert per case*.

**Solution outline:**
`bool isLeap(int y){ return (y%4==0 && y%100!=0) || y%400==0; }`

**Worked solution (compiled ✓):**

```cpp
// PF-CS-021 — leap year with test sweep
#include <iostream>

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main()
{
    for (int y : {1900, 2000, 2023, 2024, 2100, 2400})
        std::cout << y << (isLeap(y) ? ": leap\n" : ": common\n");
    return 0;
}
```

**Test cases:** 1900 common, 2000 leap, 2023 common, 2024 leap, 2100
common, 2400 leap.

**Extension:** days-in-month function consuming isLeap — composition.

---

## PF-CS-022 · The Safe Division Service

**Expected concepts:** error channels, out-parameters vs sentinels, caller
policy (PF-7.2, PF-8.1).

**Common incorrect approaches:** sentinel −99999 (collides with legal
quotients); printing the error *inside* the function (steals caller
policy); returning double INFINITY (not yet taught, non-portable
printing).

**Discussion points:** The interface question is *architectural*: who
decides what failure means? Reference-flag version:
`bool divide(int a, int b, int& out)`. Pair with CS-064 (tier 4) for the
long-arc reuse.

**Solution outline:**
`bool divide(int a, int b, int& quotient)` — false on b==0, out untouched.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-022 — division with an explicit failure channel
#include <iostream>

bool divide(int a, int b, int& quotient)
{
    if (b == 0)
        return false;
    quotient = a / b;
    return true;
}

int main()
{
    int q{};
    if (divide(84, 12, q))
        std::cout << "84/12 = " << q << '\n';
    else
        std::cout << "undefined\n";

    if (divide(5, 0, q))
        std::cout << q << '\n';          // unreachable by contract
    else
        std::cout << "5/0 rejected, q untouched\n";
    return 0;
}
```

**Test cases:** 84 12 → 7; 7 2 → 3 (integer division!); 5 0 → rejected.

**Extension:** add remainder out-param — divmod, two channels.

---

## PF-CS-023 · Unit Converter with Contracts (design-level)

**Expected concepts:** pre/postconditions as comments, rejection policy,
inverse functions (PF-7.1).

**Common incorrect approaches:** converting below −273.15 silently
(nonsense output); no documentation of the valid range.

**Discussion points:** Contracts are promises: precondition = caller's
duty, postcondition = callee's guarantee. Below-absolute-zero: reject via
bool channel (consistent with CS-022) — or clamp? Reject communicates;
clamp hides bugs.

**Solution outline:** `bool c2f(double c, double& f)` with
pre: c ≥ −273.15; post: |f − (c*9/5+32)| < 1e-9. Inverse mirrors.

**Test cases:** 100→212; 0→32; −40→−40 (the crossover!); −300→rejected.

**Extension:** add K (kelvin) — three units, one internal truth.

---

## PF-CS-024 · The Collatz Witness

**Expected concepts:** single-responsibility functions, max-tracking
loops, helper decomposition (PF-7.3, PF-5.2).

**Common incorrect approaches:** inlining step-counting inside the scan
loop (untestable, unreadable); long long vs int for 3n+1 at large n
(fine ≤100, but state it).

**Discussion points:** The scan loop tracks (bestN, bestSteps); the helper
answers one n. Testing the helper alone (n=6 → 8 steps) before the scan —
unit-test thinking.

**Solution outline:** `int collatzSteps(long long n)` counts until 1;
main scans 1..100, keeps max.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-024 — Collatz scan with helper
#include <iostream>

int collatzSteps(long long n)
{
    int steps{0};
    while (n != 1)
    {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        ++steps;
    }
    return steps;
}

int main()
{
    int bestN{1}, bestSteps{0};
    for (int n{1}; n <= 100; ++n)
    {
        int s{collatzSteps(n)};
        if (s > bestSteps)
        {
            bestSteps = s;
            bestN = n;
        }
    }
    std::cout << "n=" << bestN << " steps=" << bestSteps << '\n';
    return 0;
}
```

**Test cases (verified):** collatzSteps(6)=8; collatzSteps(27)=111;
scan output: **n=97 steps=118** (verified by execution).

**Extension:** print the *sequence* for the winner (needs a second
function or a mode flag — design trade-off).

---

## PF-CS-025 · Invoice Splitter (design-level)

**Expected concepts:** money as integer cents, explicit remainder policy,
caller-error contracts (PF-7.2, PF-2.4).

**Common incorrect approaches:** double money (0.1+0.2 folklore);
rounding *each* share independently and losing paisa; no policy for
people ≤ 0.

**Discussion points:** 1000.05 among 3: 33335 each (cents), 0 leftover;
1000.01 among 3: 33333.67 → 33333 each, 2 leftover — who gets them?
(first payer / last payer / house). The point is *deciding*, not the
choice. people ≤ 0: reject (caller bug), document.

**Solution outline:** totalCents = llround(total*100); share =
totalCents/people; leftover = totalCents − share*people → assigned by
policy.

**Test cases:** 100.05/3 → 33.35 each, 0 left; 100.00/3 → 33.33, 1 left;
0/5 → 0; total 10.00, people 0 → rejected.

**Extension:** uneven split by agreed ratios (weights) — validation that
weights are positive.

---

## PF-CS-026 · The Recursive-Looking Password

**Expected concepts:** adjacency loops, off-by-one at size−2, empty/1-char
cases (PF-7.3, PF-5.3).

**Common incorrect approaches:** loop to `i < s.size()` then reading
`s[i+1]` out of bounds on the last char; forgetting `""` and `"a"` return
false.

**Discussion points:** Valid neighbor pairs: i from 0 to size−2 — the
fence-post again. unsigned char cast for cctype. Where does this helper
plug into CS-007's meter?

**Solution outline:** for i in 0..size−2: if s[i]==s[i+1] return true;
return false.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-026 — adjacent duplicate detection
#include <iostream>
#include <string>

bool hasDoubleChar(const std::string& s)
{
    if (s.size() < 2)
        return false;
    for (std::size_t i{0}; i + 1 < s.size(); ++i)
        if (s[i] == s[i + 1])
            return true;
    return false;
}

int main()
{
    for (std::string w : {"book", "bok", "", "a", "ll", "abcabca"})
        std::cout << '"' << w << "\": "
                  << (hasDoubleChar(w) ? "yes" : "no") << '\n';
    return 0;
}
```

**Test cases:** book yes, bok no, "" no, a no, ll yes, abcabca no.

**Extension:** triple-repeat detection — same loop, deeper lookahead.

---

## PF-CS-027 · Overload Tournament (design-level)

**Expected concepts:** overload resolution by signature, ambiguity
hazards (PF-8.2).

**Common incorrect approaches:** area(int) vs area(double) with int call
sites (int picks int overload — surprising); identical parameter lists
differing only by return type (illegal overload).

**Discussion points:** Resolution: exact match → promotion. area(3)
(square side 3? or circle radius 3?) — the danger case. Safe design:
distinct names (squareArea, circleArea) vs overload purity. Course
position: overloads when *same operation, different arity/types that can't
collide*.

**Solution outline:** area(int side); area(int w, int h); area(double r);
area(double b, double h, char tag='t')... better: triangle via
triangleArea(b,h). Discuss the tagged-variant as the trap.

**Test cases (call matrix):** area(4)→16; area(3,5)→15; area(2.0)→12.566…;
area(3.0,4.0)→6.0.

**Extension:** add right-triangle area with legs — does it collide?

---

## PF-CS-028 · The Swap Handoff (design-level)

**Expected concepts:** value/pointer/reference semantics, call-site
visibility (PF-8.1).

**Common incorrect approaches:** believing references "copy too";
missing the & at the call site for pointer version (passing value);
thinking reference version is "the same as value but faster".

**Discussion points:** The three signatures side by side; the call sites
`swap(a,b)` vs `swap(&a,&b)` vs `swap(a,b)` — value and reference calls
look identical, behave oppositely: readability cost of references.
Sorting routine adopts references (or full-array pass).

**Solution outline:** three swaps; demonstrate only ref/ptr mutate
caller; value is a no-op.

**Test cases (behavioral):** value: a,b unchanged. pointer: swapped.
reference: swapped.

**Extension:** swapTwo via pointers *returning* the old values — multiple
outputs design.

---

## PF-CS-029 · Statistics on Demand (design-level)

**Expected concepts:** reference out-parameters, guard clauses, interface
comparison (PF-8.1, PF-7.2).

**Common incorrect approaches:** reading a[0] before the n==0 guard;
three separate functions returning min/max/mean (three passes, stale-mix
risk if data changes between calls).

**Discussion points:** One function = one pass = consistent snapshot.
Out-params: who initializes? Convention: function writes, caller declares.
The n==0 contract: return false / leave outs untouched.

**Solution outline:**
`bool computeStats(const double* a, int n, double& lo, double& hi, double& mean)`.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-029 — one-pass stats via out-parameters
#include <iostream>

bool computeStats(const double* a, int n,
                  double& lo, double& hi, double& mean)
{
    if (n <= 0)
        return false;
    lo = a[0];
    hi = a[0];
    double sum{0.0};
    for (int i{0}; i < n; ++i)
    {
        if (a[i] < lo) lo = a[i];
        if (a[i] > hi) hi = a[i];
        sum += a[i];
    }
    mean = sum / n;
    return true;
}

int main()
{
    double data[]{3.5, 1.0, 9.5, 2.0};
    double lo{}, hi{}, mean{};
    if (computeStats(data, 4, lo, hi, mean))
        std::cout << "min " << lo << " max " << hi
                  << " mean " << mean << '\n';
    double none[1]{};
    std::cout << (computeStats(none, 0, lo, hi, mean)
                  ? "ok" : "empty rejected") << '\n';
    return 0;
}
```

**Test cases (verified):** {3.5,1.0,9.5,2.0} → min 1, max 9.5, mean 4;
n=0 → rejected, outs untouched.

**Extension:** add median out-param — forces a sorted copy inside
(foreshadows CS-072).

---

## PF-CS-030 · Default Grading Modes (design-level)

**Expected concepts:** default arguments, policy-of-defaults reasoning
(PF-8.2).

**Common incorrect approaches:** default in *definition* only (linker
error in multi-file; single-file it's just style) — teach: declaration
carries the default once; changing the default later silently regrades
history.

**Discussion points:** Dangerous default = the one that inflates grades
(lenient). Safe default principle: the choice that cannot cause silent
harm. Transcript argument: an old call `curve(89.5)` changes output when
the default flips — every call site re-audited.

**Solution outline:** `double curve(double s, char mode = 'S')` — strict
truncates: `static_cast<int>(s*10)/10.0`; lenient rounds up at .5.

**Test cases:** 89.5 S→89.5? (define: strict = truncate fraction of a
point: 89.5→89.5 → careful: truncate to *integer* 89); 89.5 L→90;
89.4 L→89 (only .5 rounds up — policy!).

**Extension:** third mode 'C' (curved +5 capped 100) — default stays safe.

---

## PF-CS-031 · The Recursive Countdown

**Expected concepts:** base/recursive cases, termination, stack depth
(PF-8.3).

**Common incorrect approaches:** base case n<0 (skips 0's print); no
shrinking argument → infinite recursion; believing recursion is "always
worse".

**Discussion points:** Termination proof = "argument strictly decreases
to base". Stack depth = n here; limits are implementation-defined
(course flag). Loop version: no depth limit, same output — engineering
choice.

**Solution outline:** void rCount(int n){ if(n==0){print;return;} print;
rCount(n−1); }.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-031 — loop vs recursion countdown
#include <iostream>

void rCount(int n)
{
    if (n < 0)                            // base: nothing to print
        return;
    std::cout << n << ' ';
    rCount(n - 1);
}

int main()
{
    rCount(5);
    std::cout << '\n';
    for (int i{5}; i >= 0; --i)
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}
```

**Test cases (verified):** both print `5 4 3 2 1 0`. rCount(0) prints
just `0`. (Depth test at 10000 noted as implementation-dependent in the
discussion, not asserted in class.)

**Extension:** countUp via *post*-recursion print — order reversal
revelation.

---

## PF-CS-032 · Recursive Sum of Digits

**Expected concepts:** recursive decomposition n%10 + f(n/10), base n<10
(PF-8.3).

**Common incorrect approaches:** base case n==0 with negative inputs
(hangs); forgetting 2×10⁹ overflows int → long long contract.

**Discussion points:** Why n/10 is the shrinking half; termination
argument mirrors CS-031. digitSum(0)=0 — does the base n<10 cover it?
(n=0 < 10 → returns 0 ✓).

**Solution outline:** `long long digitSum(long long n){ return n<10 ? n :
n%10 + digitSum(n/10); }`

**Worked solution (compiled ✓):**

```cpp
// PF-CS-032 — recursive digit sum
#include <iostream>

long long digitSum(long long n)
{
    if (n < 10)
        return n;
    return n % 10 + digitSum(n / 10);
}

int main()
{
    for (long long v : {0LL, 7LL, 907LL, 12345LL, 2000000001LL})
        std::cout << v << " -> " << digitSum(v) << '\n';
    return 0;
}
```

**Test cases (verified):** 0→0, 7→7, 907→16, 12345→15, 2000000001→3.

**Extension:** digital root (repeat until one digit) — digitSum until
<10 loop outside, or recursion on the result.

---

## PF-CS-033 · Tower of Hanoi — Move Counter (design-level)

**Expected concepts:** recurrence relations, recursive printing, 2ⁿ−1
(PF-8.3, PF-6.3).

**Common incorrect approaches:** counting moves inside the wrong level
(off-by-one at the big-disk move); printing "from/to" poles swapped in
the recursion.

**Discussion points:** hanoi(n, from, to, via): print-move sandwiched by
two recursive calls with poles rotated. Count recurrence: 1 + 2·h(n−1).
Trace n=3: 7 lines — count them live.

**Solution outline:** standard three-pole recursion; moves(n)=2ⁿ−1.

**Test cases:** n=1→1 move; n=2→3; n=3→7 (A→C, A→B, C→B, A→C, B→A, B→C,
A→C for standard labeling).

**Extension:** four poles (Frame–Stewart teaser — no proof required;
"fewer than 2ⁿ−1, conjectured formula" as a discussion gem).

---

## PF-CS-034 · Function Table Refactor (design-level)

**Expected concepts:** parameter extraction, compute-vs-print functions
(PF-7.3).

**Common incorrect approaches:** passing 5 parameters when 2 vary;
functions that print (untestable) chosen "because easier".

**Discussion points:** The only-varies rule: name and multiplier become
parameters; everything else is local. Return-then-print wins for testability
— the course standard (per TEACHING_GUIDE).

**Solution outline:** `double report(const std::string& city, double mult)`
returns the computed figure; main calls it 3× and prints.

**Test cases:** identical outputs pre/post refactor (regression check —
the *definition* of a correct refactor).

**Extension:** the three blocks share a *loop* too — extract loop
function, main shrinks to 3 lines.

---

## PF-CS-035 · The Pass-by-Value Budget (design-level)

**Expected concepts:** copy semantics, two repair idioms (PF-8.1).

**Common incorrect approaches:** "const double& fixes it" (no — const
forbids the mutation; the copy was never the issue for *behavior*, only
cost); returning void with reference (works but hides data flow at call
site).

**Discussion points:** Copy dies at brace. Fix A (double&) mutates
invisibly; Fix B (return double) makes `total = addTax(total)` explicit.
Course preference: B for scalar math; A for big records or dual outputs.

**Solution outline:** both fixes; call sites compared.

**Test cases:** 100 → 117.0 both fixes; 0 → 0; −50 → −58.5 (garbage in,
garbage out — precondition discussion).

**Extension:** applyTax to an *array* of prices — now which fix and why?

---

## PF-CS-036 · Primes in a Range — Function Anatomy (design-level)

**Expected concepts:** √n divisor bound, function layering, I/O placement
(PF-7.3, PF-6.2).

**Common incorrect approaches:** testing divisors to n (wasteful but
correct — the discussion is *why wasteful*); isPrime printing primes'
found-status (mixing jobs).

**Discussion points:** If d·e=n with d≤e then d≤√n: the bound proof by
contradiction. printPrimes owns I/O; isPrime is pure — unit tests possible.

**Solution outline:** isPrime: n<2 false; 2 true; even false; odd d to
d*d≤n. printPrimes loops lo..hi calling isPrime.

**Test cases:** isPrime: 2 T, 3 T, 4 F, 9 F, 25 F (catches missing
d*d bound... no — 25 caught by d=5; 49 by 7 ✓), 97 T. Range 10..30 →
11,13,17,19,23,29.

**Extension:** count primes ≤ x for x=100 (25) — density intuition.

---

## PF-CS-037 · The Bilingual Menu (design-level)

**Expected concepts:** default args vs overloads — maintenance view
(PF-8.2).

**Common incorrect approaches:** overloads where one calls the other with
a magic string (fine, but then a default would do); switching language
*inside* greet via if(lang=="ur") — that's design (a) anyway.

**Discussion points:** Call matrix: greet("Ali") / greet("Ali","ur") /
greet("Ali","fr") — (a) compiles all three (fr silently treated how?),
(b) rejects the third *at compile time*. Scale-to-three analysis: (a)
adds a branch; (b) adds an overload; centralize vs enumerate.

**Solution outline:** both designs written; the verdict argued, not
imposed.

**Test cases:** each design × 3 calls.

**Extension:** enum Language instead of strings — type safety enters.

---

## PF-CS-038 · Scope Detective (design-level)

**Expected concepts:** shadowing, name lookup, :: scope resolution
(PF-8.4).

**Common incorrect approaches:** predicting the *global* prints inside
the function; assuming the function's write affects the global.

**Discussion points:** Innermost-wins rule. The two remedies and their
politics: rename (cure) vs :: (band-aid, but *documents intent* in
constructors' initializer lists — preview of L31). Compile with -Wshadow
as a tool-based remedy.

**Solution outline:** global int total; function declares local total,
mutates; predict: local wins inside, global untouched.

**Test cases:** program prints local 5 inside, global 0 after — verify
by running.

**Extension:** block-nested shadow (inner { } inside a function) —
three-layer lookup.

---

## PF-CS-039 · Menu Loop with Function Dispatch (design-level)

**Expected concepts:** while-menu pattern, switch default, input
robustness (PF-8.2, PF-4.3).

**Common incorrect approaches:** do-while that runs an operation before
showing the menu; break-happy switch falling through; invalid input
crashing on a later `cin >> int` failure (stream state — mention clear()).

**Discussion points:** Menu prints *inside* the loop. default: prints
help. The exit choice is a case like any other — control lives in the
condition. Full stream-error handling is L30 material; here, note it.

**Solution outline:** while(choice != 5){ showMenu; read; switch(1..4
dispatch, default help); }.

**Test cases:** 1,2,3,4 each once then 5; garbage input `x` → help, menu
re-shows (with the clear/ignore fix previewed).

**Extension:** submenu under option 2 — nested dispatch discipline.

---

## PF-CS-040 · Recursive Binary Strings (design-level)

**Expected concepts:** recursive enumeration, choice trees, 2ⁿ growth
(PF-8.3, PF-6.3).

**Common incorrect approaches:** forgetting to "undo" the appended bit
(string building without backtracking structure); base case printing at
n<0 (double-counts).

**Discussion points:** Each level appends '0' or '1' then recurses —
the tree of choices. Depth n, leaves 2ⁿ: the *shape* is the answer to
"how many". n=20 analysis: ~10⁶ lines — feasibility is an arithmetic
question, not a coding one.

**Solution outline:** void gen(std::string acc, int n){ if(n==0){
print acc; return;} gen(acc+'0', n−1); gen(acc+'1', n−1); }

**Test cases:** n=2 → 00,01,10,11 (in order — verify); n=3 → 8 lines,
first 000, last 111.

**Extension:** print in Gray-code order (adjacent lines differ by one
bit) — recursion with parity flag.
