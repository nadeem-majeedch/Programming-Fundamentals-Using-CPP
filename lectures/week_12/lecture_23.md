# L23 · Linear Search vs Binary Search: Correctness and Comparisons

**Module 12 — Searching and Sorting · Week 12 · Lecture 23 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-12.1, PF-12.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Implement linear search and iterative binary search (with
   `low`/`high`/`mid`, `long long`-safe mid formula) returning index or −1,
   and trace both on given inputs (PF-12.1).
2. State and *use* binary search's precondition — the array must be sorted —
   and demonstrate the wrong-answer consequence of violating it (PF-12.1).
3. Count and compare comparisons for both algorithms (best/average/worst),
   and derive the O(log n) halving intuition (PF-12.2).

## Prerequisites

M9 (arrays, linear-search pattern from L18 — now formalized); M5 (loop
patterns: FIND-FIRST); L12 (trace discipline); L10 (iteration counting).

## Concept sequence

1. The search problem; return index vs bool vs −1 conventions
2. Linear search: the FIND-FIRST pattern formalized
3. Best/average/worst comparison counts for linear search
4. The sorted-data idea: halving the candidate range
5. Binary search: low/high/mid loop with all four exit conditions
6. Midpoint arithmetic and the overflow note; precondition violation demo

## Teaching topics (detailed)

- **Linear search (formal):** `int linear_search(const int a[], int n,
  int key)` → index or −1; best 1, worst n, average n/2 comparisons;
  Falsifiable claim: "nothing beats checking every element when data is
  unsorted."
- **Binary search loop (canonical):**
  `low = 0, high = n - 1; while (low <= high) { mid = low + (high - low) / 2;
  if (a[mid] == key) return mid; else if (a[mid] < key) low = mid + 1; else
  high = mid - 1; } return -1;` — the four places it can exit; `mid`
  recomputed *inside* the loop (the classic bug: computing once); the
  `(low + high) / 2` overflow remark (why `low + (high - low) / 2`).
- **Trace protocol:** three-column trace (low, high, mid) for a 16-element
  array; maximum comparisons = ⌊log₂ 16⌋ + 1 = 5 vs 16 — the felt
  difference; 1,000,000 elements → 20 vs 1,000,000.
- **Precondition:** binary search on unsorted data *silently returns wrong
  answers* (not a crash) — live demo on a 6-element unsorted array; hence
  the contract comment and the sort-then-search tradeoff (L24 connects).
- **Complexity vocabulary (intuition only):** O(n) vs O(log n) as growth
  curves, not formal definition; comparison-count tables as evidence.

## C++ examples required

| File | Role |
|---|---|
| `search_compare.cpp` ✅ | both searches; comparison counters printed; unsorted-precondition violation demo |
| (live) `binary_trace.cpp` | prints (low, high, mid) per iteration for two keys: present and absent |

## Common student misconceptions

- "Binary search is always faster." (Needs sorted data; sorting costs O(n²)
  with our tools — the tradeoff is L24's content.)
- "`mid = (low + high) / 2` is always fine." (Fine at our sizes; the
  overflow-safe form is the professional habit — shown, required.)
- "Binary search returns the *first* match." (It returns *a* match;
  duplicates need a variant — noted, not elaborated.)
- "`while (low < high)` is equivalent." (Off-by-one: misses the single-
  element range — traced.)

## Conceptual explanation (beginner-first)

You already own linear search: walk the array, compare each element,
stop at a match. Its cost grows **linearly** — twice the data, twice
the comparisons. Binary search is the payoff of L10's complexity work:
on a **sorted** array, every comparison against the middle element
throws away *half* of what remains. Twenty comparisons cover a
million elements; thirty cover a billion. That growth — cutting the
problem in half each step — is **logarithmic**, and it's the first
genuinely fast algorithm of the course.

The price is a strict precondition: **the data must be sorted**.
Binary search on unsorted data doesn't crash — it silently returns
wrong answers, which is far worse. So the algorithm's contract has two
parts: sorted input, and (when the key is absent) a well-defined
not-found result (`-1`, like linear search).

The loop maintains an invariant worth saying out loud: **if the key is
in the array, it lies between `low` and `high`**. Initialization
(`low = 0`, `high = n-1`) makes it true; each iteration preserves it by
discarding the half that cannot contain the key; when the range
empties (`low > high`), the invariant certifies the key is absent.
This is exactly the loop-invariant discipline from L09, now proving
something nontrivial.

## Terminology and definitions

| Term | Definition |
|---|---|
| Linear search | Scan every element; O(n) comparisons |
| Binary search | Halve the search space each comparison; O(log n) |
| Precondition | Sorted (ascending) input — violated = wrong answers, not errors |
| Search interval | `[low, high]` — the region that may still hold the key |
| Loop invariant | "The key, if present, is inside `[low, high]`" — maintained every pass |
| Midpoint | `mid = low + (high - low) / 2` — the overflow-safe form (required) |
| Logarithmic growth | Doubling the data adds ~1 comparison; the log₂ curve |
| Comparison count | The measured cost — printed by the example harness |
| Not-found result | `-1`, the same sentinel as linear search |

## Syntax and C++ examples

```cpp
// linear search — the baseline (L18 revisited, now with a counter)
int linearSearch(const int a[], int n, int key, long long& comparisons)
{
    for (int i{0}; i < n; ++i)
    {
        ++comparisons;
        if (a[i] == key)
            return i;
    }
    return -1;
}

// binary search — sorted input only
int binarySearch(const int a[], int n, int key, long long& comparisons)
{
    int low{0};
    int high{n - 1};
    while (low <= high)                      // inclusive interval non-empty
    {
        int mid{low + (high - low) / 2};     // overflow-safe midpoint
        ++comparisons;
        if (a[mid] == key)
            return mid;                      // found: return a position
        else if (a[mid] < key)
            low = mid + 1;                   // key can only be right of mid
        else
            high = mid - 1;                  // key can only be left of mid
    }
    return -1;                               // interval empty: absent
}
```

## Line-by-line code explanation

`examples/search_compare.cpp`:

1. Both functions take `long long& comparisons` — a *reference*
   parameter (Module 8) so the harness can read the cost; the sorted
   precondition is stated in a comment and *violated on purpose* once:
   searching unsorted data returns wrong `-1`s — no crash, no warning.
2. `while (low <= high)` — the inclusive interval `[low, high]` is
   non-empty; when `low > high` the interval is empty and the key is
   certified absent. Using `low < high` misses the one-element range —
   the off-by-one traced live.
3. `mid = low + (high - low) / 2` — mathematically identical to
   `(low+high)/2` for our sizes but immune to the overflow that hits
   huge indices; the professional habit, required by the course.
4. The three-way branch does double duty: equality returns, and both
   inequality arms *shrink the interval past `mid`* (`mid+1`/`mid−1`,
   not `mid`) — forgetting that is the infinite-loop bug.
5. The harness runs both searches over n = 10, 100, 1000 sorted
   arrays and prints comparison counts: linear grows ~n, binary grows
   ~log₂ n — the theory table, measured.

## Output prediction questions (with answers)

1. Linear search, 1,000 elements, worst case — ? — 1,000 comparisons;
   best case — 1.
2. Binary search, 1,000 elements, worst case — ? — ⌈log₂ 1001⌉ ≈ 10.
3. Binary search on `{5, 9, 2}` for key 9 — ? — wrong result or −1:
   unsorted input violates the precondition (silently).
4. `low = 3, high = 4`: what is `mid`, and after a failed compare the
   new interval? — `mid = 3`; new range is `[4,4]` or `[3,2]` — either
   way, progress toward termination.
5. Key absent: how does the loop end? — `high` drops below `low`; the
   interval empties; return −1.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Searching unsorted data | Silent wrong answers — no error | Precondition: sort first, or use linear |
| `(low + high) / 2` | Fine at course sizes; overflow at huge scales | `low + (high - low) / 2` (required) |
| `low = mid` / `high = mid` | Infinite loop on 2-element ranges | `mid + 1` / `mid − 1` — shrink past mid |
| `while (low < high)` | Misses the single-element interval | `low <= high` with inclusive bounds |
| `mid` computed outside the loop | Stale midpoint — wrong halving | Recompute every iteration |
| Returning the first match with duplicates | Returns *a* match, not the first | Variant algorithm (stretch exercise) |

## Classroom demonstrations

1. **Guess-my-number tournament (15 min):** one student thinks of 1–1024; class
   finds it by halving (binary search — 10 guesses guaranteed) then by
   linear scanning; comparison counts tallied on the board, ending in the
   log₂ plot.
2. **The silent wrong answer:** run binary search on an unsorted array
   — a confident `-1` for a key that is present: preconditions protect
   correctness, not memory.
3. **The trace film:** `binary_trace.cpp` prints (low, high, mid) per
   iteration for a present and an absent key; the class predicts each
   row before revealing it.

## Guided student activities
**Guess-my-number tournament (15 min):** one student thinks of 1–1024; class
finds it by halving (binary search — 10 guesses guaranteed) then by
linear scanning; comparison counts tallied on the board, ending in the
log₂ plot.

## Practice problems

- Trace binary search (low/high/mid table) for a key present and one absent
  on a 12-element sorted array.
- Implement both searches + a comparison-counting harness; verify counts
  match theory for n = 10, 100, 1000 (sorted input).
- Break a deliberately buggy binary search (mid outside loop, `<` vs `<=`)
  — diagnose by trace.
- (🟡 stretch) First-occurrence binary search variant for duplicates.

## Summary

Linear search is O(n) and unsorted-proof; binary search is O(log n)
and sorted-only — its invariant ("the key, if present, lies in
[low, high]") makes the halving logic provable, and the overflow-safe
midpoint makes it professional. Measured comparison counts turn the
log₂ curve from a formula into an observation. Next (L24): the sorting
algorithms that *produce* the precondition binary search needs.

## Exit ticket / formative assessment

1. Max comparisons for binary search on 1,000 sorted elements?
2. Which precondition makes binary search correct?
3. Why recompute `mid` inside the loop?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (string algorithms quiz) + search problem | 10 |
| Linear search formalized + counts | 20 |
| Break | 10 |
| Binary search build + traces + precondition | 40 |
| Guess-my-number tournament | 15 |
| Exit ticket + L24 preview | 15 |
