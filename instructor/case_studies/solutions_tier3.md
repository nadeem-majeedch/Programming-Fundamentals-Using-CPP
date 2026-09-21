# Tier 3 Instructor Companion — CS-041–CS-060

Per case: expected concepts · common incorrect approaches · discussion
points · solution outline · worked solution · test cases · extension.
Worked solutions marked **compiled ✓** were built with the course
contract and executed.

---

## PF-CS-041 · The Missing Temperature

**Expected concepts:** flag scans, none-found contracts (PF-9.1).

**Common incorrect approaches:** returning −1 as "suspect index" without
documenting that −1 means clean (sentinel ambiguity); scanning with
`for(i... ) if(bad) { report; }` printing every pass (report-once
discipline).

**Discussion points:** The contract question: report-first-bad-and-stop,
or report-all? Both legal — pick, document. none-found must print
something (`all valid`).

**Solution outline:** loop; on out-of-range print index+value and either
break or continue; after loop, if flag still false print `all valid`.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-041 — out-of-range sensor scan
#include <iostream>

int main()
{
    const int N{24};
    int readings[N]{};
    bool found{false};
    for (int i{0}; i < N; ++i)
    {
        std::cin >> readings[i];
        if (readings[i] < -50 || readings[i] > 60)
        {
            std::cout << "suspect index " << i << " value "
                      << readings[i] << '\n';
            found = true;
        }
    }
    if (!found)
        std::cout << "all valid\n";
    return 0;
}
```

**Test cases:** clean 24 values → `all valid`; one 99 at index 7 →
`suspect index 7 value 99` (plus all-valid suppressed); two bad values →
two lines (contract: report-all).

**Extension:** replace the suspect value with the neighbor average —
repair pass.

---

## PF-CS-042 · Reverse Without a Second Array (design-level)

**Expected concepts:** symmetric swaps, ⌊n/2⌋ bound (PF-9.2).

**Common incorrect approaches:** full-n loop swapping twice (identity!);
i ≤ n/2 inclusive (middle self-swap — harmless but sloppy; for even n it
re-swaps a pair — *bug*).

**Discussion points:** Trace n=5: swaps (0,4),(1,3) — 2 swaps, center
fixed. n=4: (0,3),(1,2) — 2 swaps. The i<n/2 bound is the whole proof.

**Solution outline:** for i in 0..n/2−1: swap(a[i], a[n−1−i]).

**Test cases:** 5 elems → reversed; 4 elems; 1 elem (no swaps); 0 (no
crash).

**Extension:** rotate-by-k via three reversals — algebra of reversals.

---

## PF-CS-043 · The Two-Pass Versus One-Pass Average Gap (design-level)

**Expected concepts:** pass structure, data-dependency analysis (PF-9.3,
PF-6.2).

**Common incorrect approaches:** claiming one pass "if you're clever"
(mean is unknowable before the last value); recomputing mean inside the
deviation loop (O(n²)).

**Discussion points:** Deviation needs (final mean, all values). Streaming
without storage: Welford's online mean exists (name-drop only) — but
deviations-from-final-mean fundamentally need the data or a second
statistic. Storage is the price of hindsight.

**Solution outline:** pass 1 sum→mean; pass 2 |a[i]−mean| list.

**Test cases:** {1,2,3} mean 2, deviations 1,0,1; single value → 0.

**Extension:** variance in two passes — squared deviations.

---

## PF-CS-044 · Rotating the Rota (design-level)

**Expected concepts:** modular index math, rotation costs (PF-9.2).

**Common incorrect approaches:** rotating by k with k full passes
(O(nk)); off-by-sign on direction; forgetting k mod n.

**Discussion points:** Left by k: new[(i−k+n)%n] = a[i]. One temp array:
O(n) time, O(n) space; triple-reversal: O(n) time, O(1) space — the
expert trick named, derived in the extension. k mod n first is the
one-line optimization.

**Solution outline:** k%=n; out[(i−k+n)%n]=a[i] (or temp-buffer copy).

**Test cases:** [A,B,C,D,E] k=2 → [C,D,E,A,B]; k=0 → identity; k=5 →
identity; k>n → normalize first.

**Extension:** triple-reversal derivation: reverse(0,k−1),
reverse(k,n−1), reverse(0,n−1).

---

## PF-CS-045 · The Balanced Seating Chart (design-level)

**Expected concepts:** multi-source round-robin, exhaustion handling
(PF-9.3).

**Common incorrect approaches:** infinite loop when all counts hit zero
but the outer loop is `while(true)` without the remaining check; skipping
exhausted sections but also skipping the *stop* condition.

**Discussion points:** Two nested structures: rounds (outer) × sections
(inner) or a flat "next non-empty" walk — compare. Termination: every
pass seats ≥1 or stops. All-zero input → zero passes → print nothing.

**Solution outline:** remaining = Σcounts; while remaining>0: for each
section with count>0: seat one, --count, --remaining.

**Test cases:** A:2 B:1 → A B A; A:0 B:2 → B B; all zero → empty output.

**Extension:** maximize alternation when counts are lopsided (A:5 B:1 →
impossible to fully alternate — report the unavoidable adjacency).

---

## PF-CS-046 · Parallel Arrays Break a Report (design-level)

**Expected concepts:** record integrity invariant, mirrored swaps
(PF-9.2, PF-14-preview).

**Common incorrect approaches:** re-sorting *both* arrays independently
(same bug, twice); assuming the bug is in the sort, not the data model.

**Discussion points:** The invariant names[i]↔scores[i]; any swap must
mirror. Fix A: mirrored swaps (works, fragile); Fix B: struct + array of
records (kills the bug class) — forward reference to L26/CS-068. Tie
order: stable policy stated.

**Solution outline:** sort by score with a double-swap helper
swapRecord(i,j) touching both arrays.

**Test cases:** 5 records, two tied scores, verify name-score pairing
after sort.

**Extension:** add a third parallel array (section) — how many places
now need editing? (Motivates structs.)

---

## PF-CS-047 · Frequency Table from Scratch (design-level)

**Expected concepts:** counting arrays, index shifting, zero-count
display (PF-9.1).

**Common incorrect approaches:** counts[5] with ratings 1..5 (off-by-one
crash on rating 5); skipping zero-count rows in the histogram (report
must show them).

**Discussion points:** counts[6] with slot 0 unused vs counts[5] with
rating−1 shift: clarity vs memory (trivial here — clarity wins for
beginners). Validate-then-count: the rating contract is guaranteed by
constraints, but defensive check costs one line.

**Solution outline:** int counts[6]{}; counts[r]++ after validation;
print rows 1..5, label + stars.

**Test cases:** ratings {1,1,3,5} → counts 2,0,1,0,1 with empty rows
printed; all five ratings once → full histogram.

**Extension:** normalize to percentages of n — rounding row sums to 100±ε.

---

## PF-CS-048 · The Flood Warning Diff (design-level)

**Expected concepts:** adjacent-difference scans, fence-post start at 1
(PF-9.3).

**Common incorrect approaches:** starting at 0 (compares level[0] with
level[−1] — out of bounds); using >= 10 (boundary: the case says > 10 —
strict).

**Discussion points:** n elements → n−1 gaps. The first element has no
predecessor: definitionally unflaggable. Strict vs inclusive threshold:
read the spec twice, code once.

**Solution outline:** for i=1..n−1: if level[i] > level[i−1]+10 → flag i.

**Test cases:** rising flood {100,115} → flag 1; {100,110} → none
(=10 not >10); flat data → none.

**Extension:** flag *sustained* rises (two consecutive sharp rises) —
state machine seed.

---

## PF-CS-049 · Seat Map Query Engine (design-level)

**Expected concepts:** 2-D traversals, early exit, row-major order
(PF-10.1).

**Common incorrect approaches:** first-free search without a found flag
(printing every free seat); full-map detection by exception (negative
count) instead of explicit check.

**Discussion points:** Three queries, three traversals: row scan, column
scan, ordered scan with exit. `full` is the *termination* of the ordered
scan without success — the search loop's natural none-found.

**Solution outline:** freeInRow(r): one loop; freeInCol(c): mirrored;
firstFree: nested loops, break out via flag; if !found print `full`.

**Test cases:** empty map → row counts 8, first-free (0,0); full map →
0,0,`full`; first-free after booking (0,0),(0,1) → (0,2).

**Extension:** best-adjacent-pair query (two free seats side by side) —
2-D pattern scan.

---

## PF-CS-050 · The Sudoku Row Check (design-level)

**Expected concepts:** seen-boolean arrays, early rejection (PF-10.1).

**Common incorrect approaches:** sorting the row (destroys the data the
caller may need; also slower); forgetting the out-of-range check (index
9 crash on input 9 with seen[9]).

**Discussion points:** seen[d] semantics; count-true at the end vs
detect-miss-during. Sort-based: O(n log n) vs seen-array O(n) — at n=9
both instant; the *clarity* question is the real one.

**Solution outline:** bool seen[10]{}; for each v: if v<1||v>9 →
report v, done; if seen[v] → report v, done; seen[v]=true; after loop
check all true.

**Test cases:** {1..9} → valid; {1..8,9,1}? — 10 elems invalid spec;
{1..8,5} → duplicate 5 reported; {0,...} → offending 0.

**Extension:** full 9×9 board validation — three constraint types
(rows, columns, boxes) composed.

---

## PF-CS-051 · Heat Grid Hotspots (design-level)

**Expected concepts:** two-pass 2-D pattern, threshold lists (PF-10.2).

**Common incorrect approaches:** single pass attempting to list
neighbors before the max is known; tie handling `|t−max|<2` excluding
exact-2.0 cells (spec says within 2.0 — inclusive).

**Discussion points:** Pass 1: max + location. Pass 2: |t − max| ≤ 2.0
→ list. Why one pass cannot work (threshold depends on global max) —
the same dependency logic as CS-043, now in 2-D.

**Solution outline:** scan for (maxR, maxC, maxV); scan again printing
cells meeting the band.

**Test cases:** uniform grid → every cell listed (max everywhere);
one hotspot 50, rest 20 → hotspot + band 48.0+; ties: two 50s —
first-in-scan reported as hottest (state it).

**Extension:** Manhattan-distance neighborhoods (radius 1) — shape of
"near" becomes data.

---

## PF-CS-052 · Matrix Border Sum (design-level)

**Expected concepts:** border predicates, degenerate dimensions (PF-10.2).

**Common incorrect approaches:** adding top and bottom rows then left
and right columns (corners twice); n==1 handled by the predicate
naturally but by row-walks with disaster (double-count everything).

**Discussion points:** Predicate approach: one pass, `if(r==0||r==n−1||
c==0||c==m−1) sum+=a[r][c]` — no double-count by construction. Row-walk
approach must special-case n==1, n==2, m==1, m==2 — four fence-post
traps. The predicate is *why* it's the recommended pattern.

**Solution outline:** single pass with border predicate.

**Test cases:** 3×3 {1..9} → border = 1+2+3+4+6+7+8+9 = 40; 1×5 → all
5 cells; 2×2 → all 4 (every cell is corner).

**Extension:** inner sum = total − border — two traversals or one?

---

## PF-CS-053 · The Name Formatter (design-level)

**Expected concepts:** build-vs-edit strings, word boundaries, cctype
(PF-11.1).

**Common incorrect approaches:** editing in place while indices shift
(collapse changes length!); capitalizing after ANY space (multiple
spaces → multiple "first letters" of nothing).

**Discussion points:** Build a fresh result: single pass, states
(in-word / between-words). toupper only at word starts; tolower
elsewhere (normalization, not preservation!). Spec trace:
`"   aLI   rAZA   "` → `Ali Raza`.

**Solution outline:** result=""; inWord=false; for ch: space →
inWord=false (append one space only if result non-empty and inWord was
true); letter → if !inWord toupper, else tolower; inWord=true. Trim =
only append separator between words.

**Test cases:** the spec trace; "ALI" → "Ali"; "" → ""; "a b" → "A B".

**Extension:** hyphenated names (Ali-Raza) — second word-start
character class.

---

## PF-CS-054 · Word Hunt with Word Boundaries (design-level)

**Expected concepts:** whole-word matching, boundary predicate, find-loop
(PF-11.2).

**Common incorrect approaches:** s.find(word) counting "cat" inside
"category"; boundary = space only (misses start/end-of-string and
punctuation).

**Discussion points:** Boundary predicate: pos==0 || !isalpha(text[pos−1])
and symmetric at the end. Overlap policy: after a match, continue from
match-end (non-overlapping). Case: exact per spec — but say it aloud.

**Solution outline:** pos = text.find(word, from); check both
boundaries; count and advance from = pos + word.size(); else from =
pos + 1.

**Test cases:** text "the cat scattered", word "cat" → 1; "cat cat
cat" → 3; "concatenate" → 0; word at string start/end both count.

**Extension:** case-insensitive mode — normalize copies, keep the
boundary logic identical.

---

## PF-CS-055 · Palindrome Judge with Punctuation (design-level)

**Expected concepts:** cleaning pass + two-pointer scan, empty-after-clean
policy (PF-11.2).

**Common incorrect approaches:** skipping junk with two pointers over
the RAW string (correct but subtle — index bookkeeping); calling "!!!"
a palindrome silently (policy: define!).

**Discussion points:** Build cleaned (alnum, lowercased) then two-pointer
— two simple passes beat one clever pass for beginners. Empty cleaned:
define as palindrome (vacuous) or reject — either, documented. Trace
"No 'x' in Nixon" → noxinnixon → palindrome.

**Solution outline:** clean → for l=0,r=size−1: l<r compare, move
inward; verdict.

**Test cases:** the spec phrase → palindrome; "hello" → not; "!!!" →
policy verdict; "Aa" → palindrome (case-insensitive).

**Extension:** longest palindromic substring (brute force) —
complexity discussion seed.

---

## PF-CS-056 · CSV Column Statistics (design-level)

**Expected concepts:** getline+istringstream, two error categories,
mean-over-valid (PF-11.3).

**Common incorrect approaches:** cin >> name >> comma >> score with no
space tolerance (fails on `Ayesha,88`... wait — it fails differently:
`>>name` eats `Ayesha,88` whole); treating missing-comma and bad-number
as one bucket (spec wants distinct messages).

**Discussion points:** find(',') then istringstream on the tail: robust
against names-with-no-spaces. Stream bool as the parse verdict. Mean
over valid only; both counters reported.

**Solution outline:** per line: commaPos=find; if npos →
`line N: missing comma`; else parse tail via istringstream >> score;
fail → `line N: bad score`.

**Test cases:** `Ayesha,88` ok; `Ben` → missing comma; `Cara,abc` →
bad score; `Dan,95` ok; mean over the two valid = 91.50.

**Extension:** empty-name check (`,88`) — third category.

---

## PF-CS-057 · The Acronym Builder (design-level)

**Expected concepts:** tokenization, stop-list membership, toupper (PF-11.2).

**Common incorrect approaches:** taking first LETTER of the line only;
testing small words by first letters ("of" vs "orange").

**Discussion points:** Word = maximal letter run (spaces split).
Membership test on the whole lowered token against {of, and, the}.
Case handling: lower for comparison, upper for output.

**Solution outline:** split into words; for each: if not in stop-list →
result += toupper(w[0]).

**Test cases:** "theory of computation and data" → TOCD; "the best of
times" → BT; all-stop-words → empty acronym (define!).

**Extension:** roman-numeral suffix handling (II, III stay as-is) —
rule interaction.

---

## PF-CS-058 · Insertion Sort on Playing Cards

**Expected concepts:** insertion mechanics, sorted prefix, O(n²)/O(n)
best case (PF-12.1).

**Common incorrect approaches:** swapping instead of shifting (works but
2× writes; also obscures the "hole" idea); inner loop bound drifting
past the prefix.

**Discussion points:** Hand metaphor: new card slides left past larger
cards. Trace [7,3,9,3]: pass1: 3 slides past 7 → [3,7,9,3]; pass2: 9
stays (1 comparison); pass3: 3 slides past 9,7 → [3,3,7,9]. Comparisons:
2+1+2=5. Sorted input: every pass 1 comparison → n−1 total, O(n).

**Worked solution (compiled ✓):**

```cpp
// PF-CS-058 — insertion sort with comparison count
#include <iostream>

int main()
{
    int n{};
    std::cin >> n;
    int a[50]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];

    long long comparisons{0};
    for (int i{1}; i < n; ++i)
    {
        int key{a[i]};
        int j{i - 1};
        while (j >= 0)
        {
            ++comparisons;
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                --j;
            }
            else
                break;
        }
        a[j + 1] = key;
    }

    for (int i{0}; i < n; ++i)
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    std::cout << "comparisons: " << comparisons << '\n';
    return 0;
}
```

**Test cases (verified):** [7,3,9,3] → `3 3 7 9`, comparisons 5;
already-sorted 4 elems → 3 comparisons; reverse 4 → 6.

**Extension:** binary insertion (find slot via binary search) — fewer
comparisons, same shifts.

---

## PF-CS-059 · Stable Ranking with Ties (design-level)

**Expected concepts:** stability definition, algorithm properties (PF-12.2).

**Common incorrect approaches:** assuming all class sorts are stable;
selection sort claimed stable because "we only swap when strictly less"
(the long-range swap jumps over equals — the subtle part).

**Discussion points:** Stability = equal keys keep input order. Insertion
with strict `>` in the while: equal elements never slide past each other
→ stable by construction. Selection: swap distance k can leapfrog equal
keys → unstable (classic counterexample: (2a,2b,1) → (1,2b,2a)).
Bubble with strict comparison: stable too. The course trio: two of three.

**Solution outline:** insertion sort on (score desc) with strict
comparison; trace tied pair — order preserved.

**Test cases:** (Ali,80),(Ben,90),(Cara,80) → Ben, Ali, Cara (Ali
before Cara); reverse-input tied pair stays reversed-in? (No — strict
comparison never swaps equals: input order holds.)

**Extension:** two-key stable sort via *two passes* (sort by name,
then stable-sort by score) — the classic trick, relates to CS-075.

---

## PF-CS-060 · Search Benchmark Disclosure (design-level)

**Expected concepts:** comparison counting, preconditions of binary
search, total-cost reasoning (PF-12.3).

**Common incorrect approaches:** counting only successful searches
(absent keys show the real gap); ignoring the sort cost when arguing
"binary is better"; testing on n=10 (too small to see the gap).

**Discussion points:** Precondition: sorted. Cost table: linear ~n/2
avg present, n absent; binary ~log₂n both. Total cost with q queries:
sort (n log n) + q log n vs q·n — crossover analysis IS the case. When
linear wins: tiny n, unsorted one-offs, or when order must not change.

**Solution outline:** instrument both with counters; run on sorted n=1000,
keys present+absent; report counts; argue crossover.

**Test cases:** n=1000 sorted, absent key: linear 1000, binary 10
(±1) — the money shot; present-at-end: linear 1000, binary ~10.

**Extension:** measure *time* with chrono — counts vs nanoseconds
(chat: what does each measure?).
