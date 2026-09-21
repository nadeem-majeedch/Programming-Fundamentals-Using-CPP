# L24 · Selection Sort and Bubble Sort: Tracing, Swapping, Complexity Intuition

**Module 12 — Searching and Sorting · Week 12 · Lecture 24 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-12.3, PF-12.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 6 week · Project proposal due**

## Learning objectives

1. Implement selection sort and bubble sort (with the early-exit
   optimization) using a `swap` helper, and trace passes/iterations with
   array snapshots (PF-12.3).
2. State each algorithm's invariant ("first i positions final" vs "largest
   bubbles to the end each pass") and verify it on traces (PF-12.3).
3. Compare both algorithms by comparison/exchange counts (O(n²) growth),
   and decide sort-then-search vs linear search for a given scenario
   (PF-12.4).

## Prerequisites

L23 (search costs — sorting buys faster searches); L18 (min/min-index
pattern — selection sort *is* repeated min-selection); L15 (reference
parameters — the `swap` function).

## Concept sequence

1. Why sort: binary search's precondition, human-readable reports
2. Swap as a function (references from L15 at work)
3. Selection sort: select-min, place — repeated L18 pattern
4. Bubble sort: adjacent compares, early-exit flag
5. Invariants + pass-by-pass traces of both on one array
6. O(n²) intuition and the sort-then-search decision rule

## Teaching topics (detailed)

- **`swap` by references:** `void swap(int& a, int& b)` — the canonical
  first use of output parameters; temp-variable necessity re-proven (failed
  one-liner without temp).
- **Selection sort:** outer i from 0..n-2: find min index in `i..n-1`
  (inner j from i+1), swap into position i; invariant: prefix `[0, i)` is
  final and sorted; comparisons always n(n−1)/2 (data-independent), swaps ≤
  n−1 (few writes — its practical virtue).
- **Bubble sort:** adjacent pairs, swap if out of order; after pass k, last
  k elements final ("largest bubbles up"); optimized: shrink inner bound
  (`j < n-1-k`) + `swapped` flag for early exit → best case O(n) on
  already-sorted input; comparisons worst n(n−1)/2.
- **Side-by-side trace:** same 6-element array through both, snapshot after
  each pass; invariant check row; comparison/exchange counts totaled —
  evidence for the O(n²) claim (L12 evidence format).
- **Decision rule (PF-12.4):** search once on unsorted n → linear O(n);
  search k times → sort once (n²) + k binary searches (k·log n) — break-even
  reasoning with concrete n/k numbers; growth-curve table (n, n log n
  mentioned, n²).

## C++ examples required

| File | Role |
|---|---|
| `sorting_traced.cpp` ✅ | both sorts with per-pass snapshot printing and comparison/exchange counters |
| (live) `sort_then_search.cpp` | k-search cost model demo: linear vs sort+binary at k = 1, 10, 1000 |

## Common student misconceptions

- "Bubble sort's early exit changes worst-case complexity." (Worst case
  stays O(n²); only the *best* case improves.)
- "Selection and bubble sort produce different results." (Same sorted
  output; different work distribution.)
- "Sorted output means the algorithm is O(n)." (Output sortedness ≠ cost;
  counters prove the work.)
- "The invariant is optional commentary." (It's *the* correctness argument —
  exam trace questions require naming it.)

## Conceptual explanation (beginner-first)

Sorting means rearranging a collection so its elements run in order —
and it's the step that *earns* binary search's precondition. Two
classic algorithms teach opposite lessons about doing the same job.

**Selection sort** finds the smallest remaining element and moves it
to the front, then repeats on the rest. Its invariant is crisp: after
pass *k*, the first *k* positions hold the *k* smallest elements in
final order. It always does about n²/2 comparisons — it doesn't care
whether the input was already sorted.

**Bubble sort** walks the array comparing neighbors and swapping those
out of order; each pass "bubbles" the largest remaining element to
the end. Its invariant: after pass *k*, the last *k* positions are
correct. It also does ~n² comparisons — but with an early-exit flag
(pass with zero swaps = sorted) its *best* case on already-sorted data
drops to n−1 comparisons.

Neither is the fastest sort known — the course says so honestly
(O(n log n) sorts exist but need Module 13/16 machinery). Their value
is that every step is traceable by hand, their invariants are provable
with L09's discipline, and their counters make the O(n²) growth rate
*measurable* rather than quoted.

## Terminology and definitions

| Term | Definition |
|---|---|
| Selection sort | Repeatedly select the minimum of the unsorted part into place |
| Bubble sort | Repeatedly swap out-of-order neighbors; extremes float to the end |
| Pass | One full sweep of the algorithm's comparison structure |
| Invariant (selection) | First k positions hold the k smallest, in final order |
| Invariant (bubble) | Last k positions are the k largest, in final order |
| Early exit | A no-swap pass proves sortedness — best case becomes O(n) |
| Swap | Three-assignment exchange via a temporary (Module 9) |
| Comparison/exchange counter | Instrumentation measuring the cost claims |
| O(n²) vs O(n log n) | The growth-rate gap honest about what we're not teaching yet |

## Syntax and C++ examples

```cpp
// selection sort — smallest of the remainder to the front
void selectionSort(int a[], int n, long long& comparisons, long long& swaps)
{
    for (int i{0}; i < n - 1; ++i)           // last element self-places
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
        {
            ++comparisons;
            if (a[j] < a[minIdx])
                minIdx = j;                  // track, don't swap yet
        }
        if (minIdx != i)                     // swap only when needed
        {
            int tmp{a[i]};  a[i] = a[minIdx];  a[minIdx] = tmp;
            ++swaps;
        }
    }
}

// bubble sort with early exit — neighbors compared, swapped out of order
void bubbleSort(int a[], int n, long long& comparisons, long long& swaps)
{
    for (int pass{0}; pass < n - 1; ++pass)
    {
        bool swapped{false};
        for (int j{0}; j < n - 1 - pass; ++j)  // tail already correct
        {
            ++comparisons;
            if (a[j] > a[j + 1])
            {
                int tmp{a[j]};  a[j] = a[j + 1];  a[j + 1] = tmp;
                ++swaps;
                swapped = true;
            }
        }
        if (!swapped)
            break;                           // a clean pass: sorted, done
    }
}
```

## Line-by-line code explanation

`examples/sorting_traced.cpp`:

1. Both functions print a **snapshot after each pass** (labelled) plus
   final comparison/exchange counts — the trace table the exams use,
   produced by the program itself.
2. Selection sort: the inner loop *only tracks* `minIdx`; the single
   swap after the loop is the "one exchange per pass" property — the
   cheap-swaps/expensive-comparisons profile discussed in topics.
3. Bubble sort's inner bound `n - 1 - pass` encodes its invariant:
   after `pass` rounds, the last `pass` cells are final, so don't
   re-touch them.
4. The early-exit `break` fires when a pass makes no swaps — on
   already-sorted input the counters show n−1 comparisons instead of
   ~n²/2: best case measured, worst case unchanged.
5. `main` sorts the same array both ways, prints both traces, and
   compares counters — same output, different work distribution.

## Output prediction questions (with answers)

1. Selection sort on `[5, 2, 9, 1, 7]` — pass-1 result? — `[1, 2, 9,
   5, 7]` (1 swapped into position 0).
2. Bubble sort, same array, pass 1 — ? — `[2, 5, 1, 7, 9]` (9 bubbled
   to the end).
3. Comparisons for selection sort, n = 5 — ? — 4+3+2+1 = 10, always.
4. Bubble sort on already-sorted `[1,2,3,4,5]` — passes and
   comparisons? — 1 pass, 4 comparisons, 0 swaps, early exit.
5. Which does fewer swaps on reverse-sorted input, and why? —
   selection (n−1 or fewer) vs bubble (~n²/2) — the work-distribution
   lesson in numbers.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Inner loop to `j < n` (bubble) | Re-compares the sorted tail | `j < n - 1 - pass` |
| Selection inner from `j = i` | Compares element with itself | `j = i + 1` |
| Swapping inside the inner selection loop | n² swaps — the expensive-swap bug | Track `minIdx`, swap once per pass |
| Early-exit flag never reset per pass | Exits after pass 1 always | Reset `swapped = false` each pass |
| `pass < n` instead of `n - 1` | One wasted pass (harmless but off-spec) | Know why n − 1 suffices |
| Sorting a copy, expecting the original sorted | Caller sees no change | Arrays pass by address — this bug is rarer; but passing by value *copies* for objects (M16 preview) |

## Classroom demonstrations

1. **Human selection sort (Lab 6 opener):** students hold number cards;
   the class "runs" selection sort by pointing — the minimum-hunt is
   visible before any code.
2. **Counter showdown:** sort the same random array both ways; the
   printed comparison/exchange tallies make O(n²) concrete and show
   the swaps profile difference.
3. **Early exit on demand:** feed bubble sort sorted input — one pass,
   zero swaps, stop: the flag does what the slide claims.

## Guided student activities
**Lab 6 (2 h, this lecture slot):** [labs/README.md](../../labs/README.md)
— human selection sort (students as elements), traced implementations of
both sorts with counter verification, sort-then-search break-even worksheet.
Lecture hour 2 = lab launch; project proposals (due this week) reference
search/sort needs in the capstone menu.

## Practice problems

- Trace both sorts on `[5, 2, 9, 1, 7]` — snapshots + invariant rows.
- Implement both with counters; verify counts equal theory for n = 8.
- Add early-exit bubble sort; show best-case comparison count on sorted
  input.
- (🟡 stretch) Sort a parallel array of names by paired scores (stable-pair
  swap discipline) — Module 14 records foreshadowed.

## Summary

Selection sort locks the smallest remaining element into place (one
swap per pass, invariant at the front); bubble sort floats extremes
to the back (many swaps, early exit on clean passes). Both are O(n²)
in the worst case — verified by counters — and their invariants are
the exam's trace-table backbone. Sorting is the gate binary search
needs; next (L25) the course turns to memory itself: pointers.

## Exit ticket / formative assessment

1. State each sort's invariant in one sentence.
2. n = 100: how many comparisons does selection sort always make?
3. Scenario: 1,000 searches over 50,000 records — linear or sort+binary?
   Why (one number each)?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (search quiz) + why sort | 10 |
| Swap + selection sort + invariant | 30 |
| Break | 10 |
| Bubble sort + traces + O(n²) + decision rule | 35 |
| **Lab 6 launch** (human sort + traced implementations) | 25 |
| Exit ticket + project proposal reminder | 10 |
