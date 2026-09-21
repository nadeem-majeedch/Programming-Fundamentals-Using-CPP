# L18 · Array Algorithms: Fill, Print, Sum/Average, Min/Max, Count, Linear Search

**Module 9 — One-Dimensional Arrays · Week 9 · Lecture 18 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-9.3, PF-9.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Quiz 2 (Modules 5–8)**

## Learning objectives

1. Implement from a blank editor — no notes — the core array algorithms:
   fill, print, sum/average, min/max (value *and* index), count-if, and
   reverse-in-place (PF-9.3).
2. Implement linear search with the FIND-FIRST pattern (early exit), state
   its best/worst comparison counts, and write its test plan including the
   not-found boundary (PF-9.4).
3. Map each algorithm to its Module 5 pattern name (ACCUMULATE, COUNT-IF,
   FIND-FIRST) — showing pattern vocabulary carrying new data structures
   (PF-9.3, PF-9.4).

## Prerequisites

L17 (array mechanics); L09–L10 (patterns); L13 (writing functions —
algorithms are written as functions from here on).

## Concept sequence

1. Algorithms as functions over arrays (signature design first)
2. Fill + print (the development pair)
3. ACCUMULATE: sum, average (with the L05 truncation lesson!)
4. EXTREMES: min/max with index tracking (two-output via references — L15)
5. COUNT-IF: predicate counting
6. FIND-FIRST: linear search with early exit + complexity count

## Teaching topics (detailed)

- **Signature design (L14 discipline):**
  `void fill(int a[], int n);` `double average(const int a[], int n);`
  `int index_of_max(const int a[], int n);` `bool contains(const int a[],
  int n, int key);` — size travels with the array (decy question deferred to
  L26, honest note); `const` correctness on read-only arrays.
- **Fill/print:** fill from `cin` (with validation echo) and from
  deterministic pattern (i*2) for testing; print with `setw` columns (L04
  formatting reuse).
- **Average bug-in-context:** `sum / n` truncates → `static_cast<double>(sum)
  / n` — L05's lesson now in its real habitat.
- **Min/max:** initialize with `a[0]`, loop from 1; track index alongside
  value; common wrong version: initializing min/max to 0 breaks on
  all-negative arrays — live fix.
- **Count-if:** e.g. count scores ≥ 60; predicate as explicit condition;
  COUNT-IF skeleton.
- **Linear search:** return index or -1; early `break` on first hit;
  comparisons: best 1, worst N, average N/2 — the baseline that binary
  search (L23) will beat *only on sorted data*.

## C++ examples required

| File | Role |
|---|---|
| `array_algorithms.cpp` ✅ | all six algorithms as functions + a `main` that exercises them on a fixed test array with printed results |
| (live) `linear_search_trace.cpp` | search traced with comparison counter printed per iteration |

## Conceptual explanation (beginner-first)

Real text is messy: `"  Ada  LOVELACE "` needs to become
`"Ada Lovelace"`; a CSV line `"12,7,9"` needs to become three numbers;
a report line needs a number glued into the middle of a sentence.
This lecture is a workshop of the small algorithms that do that work —
all built from the scanning patterns we already own.

Two standard library helpers earn their keep this week. `getline(cin,
s)` reads a *whole line* including spaces (whereas `cin >> s` stops at
the first space) — essential for names. And string concatenation with
`+` builds results character by character or piece by piece: `s = s +
ch` grows a string one character at a time. Neither is exotic; both are
daily tools.

## Terminology and definitions

| Term | Definition |
|---|---|
| `getline` | Reads one full line (spaces included) into a `std::string` |
| Concatenation | `+` or `+=` joining strings; `s += ch` appends one char |
| Trim | Removing leading/trailing spaces |
| Word boundary | A position where a word starts/ends (space or string edge) |
| Case mapping | `toupper`/`tolower` per character via `<cctype>` |
| Token | One whitespace-separated piece of a line |
| Title case | First letter of each word upper, rest lower |

## Syntax and C++ examples

```cpp
std::string line;
std::getline(std::cin, line);        // whole line, spaces kept

// count words: a new word starts at a non-space after a space/edge
int words{0};
bool inWord{false};
for (char ch : line)
{
    if (std::isspace(static_cast<unsigned char>(ch)))
        inWord = false;
    else if (!inWord) { ++words; inWord = true; }
}

// build a string piece by piece
std::string cleaned;
for (char ch : line)
    if (!std::isspace(static_cast<unsigned char>(ch)))
        cleaned += ch;               // append one character
```

- "Initialize min to 0." (Breaks on negatives; initialize to `a[0]`.)
- "Search must always scan the whole array." (FIND-FIRST exits early —
  correctness *and* speed.)
- "Passing the array copies it." (What's copied is handled in L26 —
  for now: the *size must travel separately*, and that's a hint.)
- "`average` should return int because scores are int." (Type serves the
  *answer*, not the input — L06 tie-in.)

## Line-by-line code explanation

`examples/string_algorithms.cpp` (clean/split/build sections):

1. `trimLeading(line)` — the classic index-skip: find the first
   non-space position `start`, then build the result from `substr(start)`
   (or erase in place). Edge case: all-spaces input must yield `""`, so
   the not-found case is checked before using `start`.
2. Word counter — the `inWord` flag is a tiny state machine: false
   means "between words." Entering a non-space while `inWord == false`
   is a boundary crossing: count it and flip the flag. Double spaces
   never double-count because the flag only flips on the
   space→letter transition, not on every letter.
3. CSV split — walk the line; on `','` push the token accumulated so
   far and reset it; after the loop push the final token (the one with
   no comma after it). Forgetting the post-loop push is *the* bug.
4. `cleaned += ch` builds the space-free version — appending one char
   per accepted character; contrast with building a new `std::string`
   via index arithmetic for the trim.

## Output prediction questions (with answers)

1. `"  Ada  LOVELACE "` through the word counter — ? — 2 words (double
   space handled by the flag).
2. Trim of `"   hi   "` — ? — `"hi"`; trim of `"     "` — `""`.
3. Split of `"12,7,9"` — ? — {"12", "7", "9"}; of `"12,,9"` — ? —
   {"12", "", "9"} — an empty middle token is *data*, not a bug.
4. `s = "val: "; s += 42;` — ? — appends the *character* with code 42
   (`'*'`), not the digits — the char-vs-int conversion trap.
5. Title-case of `"ada l."` — ? — `"Ada L."`; the first-letter rule
   fires on the boundary, not on every letter.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Mixing `cin >> s` and `getline` | The getline gets an empty leftover line | Drain with `cin.ignore` after `>>` (L04 rule) |
| Word counter without the flag | Double spaces count twice | State machine: flag flips on transitions only |
| Missing final token in split | Last CSV field vanishes | Push the accumulator after the loop |
| `s += 42` expecting digits | Asterisk appears | `s += std::to_string(42)` |
| Off-by-one in trim | One space survives / a letter dies | Trace a 2-char string by hand |
| Assuming `length()` counts words | Length counts characters | Words need boundaries, not counts |

## Common student misconceptions

- **"Initialize the running max to 0."** For values that may be
  negative, initializing max to `0` returns 0 for all-negative input;
  the correct pattern seeds from the first element.
- **"The average of ints is an int."** `sum / n` truncates — the mean
  of `1 2` is 1.5; converting after the loop with a
  `static_cast<double>` on the *division* is the fix to practice.
- **"Linear search needs sorted data."** It works on any order —
  students conflate it with binary search; that's exactly why it's the
  baseline before L23.
- **"The search returns the value, not the position."** Decide and
  document the "not found" contract (−1 as a sentinel index is the
  course convention).
- **"Counting patterns need nested loops."** Most counting/frequency
  patterns in this lecture are single-pass — the nested-loop habit
  arrives with L23 and should not be imported early.

## Classroom demonstrations

1. **Double-space stress test:** run the counter on `"a  b   c"` live —
   the flag makes it boring, which is the point.
2. **The vanishing token:** run a split missing the post-loop push —
   `"12,7,9"` prints only two numbers; students spot the missing push.
3. **Char arithmetic surprise:** `s += 42` vs `s += "42"` side by side —
   the type of the right operand is the whole story.

## Guided student activities

1. **Design-your-own trim:** pairs write `trimTrailing` (mirror of the
   leading version) and exchange with a neighbor to trace.
2. **CSV dialect:** modify the splitter to accept `';'` — one character
   changes; discuss what a real CSV parser must additionally handle.
3. **Counting vowels:** implement with `<cctype>` (`tolower` first),
   then predict its behavior on `"XYZ"` vs `"xyz"` before running.

## Practice problems

- Write `trimLeading` and `trimTrailing`; test on `""`, `"   "`, `"a "`.
- Split `"12,7,9"` into three `int`s (with a string→int conversion —
  stream-state style, per the course standard).
- Reverse a `std::string` in place; predict `"abc"` → `"cba"` first.
- (🟡 stretch) Title-case a line using the word-boundary flag.

## Practice problems
- The four problems above are the in-class set; the stretch item becomes
  the homework extension when `exercises/homework/` is authored.

## Summary

String work is scanning plus building: `getline` for full lines,
`isspace`-gated state machines for words, `+=` to grow results, and
index arithmetic to mirror or trim. The word counter's `inWord` flag is
the reusable idea — transitions between "in" and "out" are where events
happen. Next (L21): searching arrays — linear and binary — and the
first real complexity comparison.

## Exit ticket / formative assessment

1. Write the loop that counts commas in a line — then states why it is
   COUNT-IF in disguise.
2. Given `line = "ada  l."` (two spaces), what does the word counter
   print, and which variable prevents a miscount?
3. What does the split routine owe to the loop boundary — i.e., why is
   there a push *after* the loop?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| **Quiz 2** | 15 |
| Signature design + fill/print + accumulate | 25 |
| Break | 10 |
| Extremes + count-if + linear search (+complexity count) | 40 |
| Algorithm relay activity | 20 |
| Exit ticket + Module 10 preview | 10 |
