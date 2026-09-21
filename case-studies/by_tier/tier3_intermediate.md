# Tier 3 · Intermediate — Projector Cases (CS-041–CS-060)

**Lectures L17–L24 · Modules 9–12** · think ~5 minutes · paper only.
Cases ascend in difficulty within the tier. Worked solutions: instructor
area only.

---

### PF-CS-041 · The Missing Temperature

- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** A sensor array logs hourly readings; one slot is corrupt.
- **Problem:** An array holds 24 readings; exactly one index holds a value outside −50…60. Design the scan that reports the suspect index and its value, *and* decide what the report should say if the array is actually clean (nothing?) — specify the none-found behavior.
- **Input:** 24 integers. **Output:** suspect index+value, or `all valid`.
- **Constraints:** exactly 0 or 1 bad values; others in −50…60.
- **Thinking questions:** What flag survives the loop? When is the flag set vs checked?

<details><summary>Hints (progressive)</summary>

1. A bool starts false and flips on the first violation.
2. Report *at the first* violation and stop, or collect all — decide the contract.
3. After the loop, the flag's value answers the none-found question.
</details>

---

### PF-CS-042 · Reverse Without a Second Array

- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** Memory is tight; a buffer must be reversed in place.
- **Problem:** Design the in-place reversal of n elements using one temporary variable. Trace the swap sequence for n = 5 (which pairs, how many swaps), and prove no element is touched twice.
- **Input:** n, then n integers. **Output:** the reversed array.
- **Constraints:** 1 ≤ n ≤ 100.
- **Thinking questions:** Which pairs exchange? Where do the two indices meet — and what happens at the meet point?

<details><summary>Hints (progressive)</summary>

1. Swap a[i] with a[n−1−i].
2. i runs to n/2 exclusive — the middle never swaps itself.
3. ⌊n/2⌋ swaps total; for odd n the center stays.
</details>

---

### PF-CS-043 · The Two-Pass Versus One-Pass Average Gap

- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** An analytics job reports how far each value sits from the mean.
- **Problem:** Design the computation of deviations |a[i] − mean| for n values. First as two passes (compute mean, then deviations), then ask: can one pass do it? Identify what a single pass *cannot* know and what that implies about storing the data.
- **Input:** n, then n doubles. **Output:** mean, then deviations.
- **Constraints:** 1 ≤ n ≤ 1000.
- **Thinking questions:** What does the second pass need that the first didn't have? If the data streamed and vanished, what would be lost?

<details><summary>Hints (progressive)</summary>

1. The mean is unknown until all values are seen.
2. Deviations need the final mean plus every original value.
3. One pass requires keeping the values — the array is the memory.
</details>

---

### PF-CS-044 · Rotating the Rota

- **Tier:** 3 Intermediate · **Lecture:** L18 · Module 9
- **Context:** A hospital rotates duty shifts left by k each week.
- **Problem:** Design the left-rotation of an array by k (with wraparound) *without* a second array. Trace for [A,B,C,D,E], k = 2. What goes wrong with the naive "move everything one slot, k times" for large n and k — and what is the fix?
- **Input:** n, k, then n values. **Output:** rotated array.
- **Constraints:** 1 ≤ n ≤ 100; 0 ≤ k ≤ n.
- **Thinking questions:** Where does element i land? What does k mod n buy you?

<details><summary>Hints (progressive)</summary>

1. New position of a[i] is (i − k + n) mod n... or a second index walk.
2. k mod n first: rotating by n is a no-op.
3. One-buffer copy with the modular index is simplest; triple-reversal is the expert trick.
</details>

---

### PF-CS-045 · The Balanced Seating Chart

- **Tier:** 3 Intermediate · **Lecture:** L18 · Module 9
- **Context:** An exam hall seats students to balance section sizes.
- **Problem:** Given counts per section (n values), design the assignment that seats sections alternately (A,B,C,A,B,C…) until each is exhausted, then continues with the sections that remain. Specify the loop that skips exhausted sections and terminates exactly when all are empty.
- **Input:** n sections with counts. **Output:** seating order as section letters.
- **Constraints:** 1 ≤ sections ≤ 8; counts ≤ 40.
- **Thinking questions:** How do you detect "this section is done"? Does the loop terminate if *all* counts are zero?

<details><summary>Hints (progressive)</summary>

1. A "remaining" counter plus per-section counters.
2. One pass = one round; skip empties; stop when remaining == 0.
3. All-zero input must print nothing and stop — verify that first.
</details>

---

### PF-CS-046 · Parallel Arrays Break a Report

- **Tier:** 3 Intermediate · **Lecture:** L18 · Module 9
- **Context:** A report sorts scores but names no longer match.
- **Problem:** Presented with parallel arrays names[] and scores[] where only scores[] was sorted, diagnose the exact data corruption, then design the fix that keeps records aligned while sorting (swap both, or restructure). Decide which fix you would mandate and why.
- **Input:** 5 name/score pairs, already corrupted on display. **Output:** diagnosis + corrected sort design.
- **Constraints:** names are unique; scores may tie.
- **Thinking questions:** What invariant did the sort violate? When does swapping both arrays still mislead?

<details><summary>Hints (progressive)</summary>

1. The invariant: names[i] and scores[i] describe the same student.
2. Any swap in scores must mirror in names.
3. Ties make "sorted by score" ambiguous — state the tie order policy.
</details>

---

### PF-CS-047 · Frequency Table from Scratch

- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** A survey records ratings 1–5; the report needs a histogram.
- **Problem:** Design the counting structure and loop for n ratings: counts per rating, then a star histogram. Decide the array size *before* seeing n, and specify what the histogram prints for a rating that never occurred.
- **Input:** n, then n ratings. **Output:** counts + histogram.
- **Constraints:** 1 ≤ n ≤ 500; ratings always 1…5 (validated).
- **Thinking questions:** Why is an index-shifted array (1→0) needed? What does counts[2] mean after your shift?

<details><summary>Hints (progressive)</summary>

1. int counts[6] = {} wastes slot 0 — or does it buy clarity?
2. counts[r]++ after validating 1 ≤ r ≤ 5.
3. A zero count still prints its label with no stars.
</details>

---

### PF-CS-048 · The Flood Warning Diff

- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** A river gauge reports hourly levels; alarms fire on rises.
- **Problem:** Design the pass that flags every index where level[i] > level[i−1] + 10 (a sharp rise). What is the correct starting index, and what does the report do with the *first* element (which has no predecessor)?
- **Input:** 24 levels. **Output:** flagged indices (or `none`).
- **Constraints:** levels 0…500.
- **Thinking questions:** Why does the loop start at 1? What fence-post error is lurking?

<details><summary>Hints (progressive)</summary>

1. Element 0 has no predecessor: start comparing at 1.
2. The loop runs n−1 comparisons for n elements.
3. An empty flag list must still print something — `none`.
</details>

---

### PF-CS-049 · Seat Map Query Engine

- **Tier:** 3 Intermediate · **Lecture:** L19 · Module 10
- **Context:** A cinema's 5×8 seat map stores 0 (free) / 1 (taken).
- **Problem:** Design the 2-D scan that answers three queries: seats free in row r, seats free in column c, and the first free seat in row-major order (as row, col or `full`). Specify behavior for a fully-booked map.
- **Input:** 5×8 grid, then queries. **Output:** counts or coordinates.
- **Constraints:** indices validated; grid fixed size.
- **Thinking questions:** Which queries need one loop, which need two? What is "row-major" doing for the third query?

<details><summary>Hints (progressive)</summary>

1. Row count = one loop over columns; column count mirrors it.
2. First-free = nested loops with an early exit flag.
3. `full` after both loops complete without finding — the fence-post of the search.
</details>

---

### PF-CS-050 · The Sudoku Row Check

- **Tier:** 3 Intermediate · **Lecture:** L19 · Module 10
- **Context:** A puzzle app validates one Sudoku row at a time.
- **Problem:** Design the check that a 9-element row contains each digit 1–9 exactly once, using a seen[] boolean array — *without* sorting. Then contrast with a sort-based approach: what does each cost, and which is clearer?
- **Input:** one row of 9 integers. **Output:** `valid` or the first offending digit.
- **Constraints:** entries 1…9 (out-of-range entries are "offending" too).
- **Thinking questions:** What does seen[d] mean? When do you know the answer early?

<details><summary>Hints (progressive)</summary>

1. seen[d] flips true when d appears; a repeat is an instant fail.
2. Out-of-range check first: 1–9 or report immediately.
3. Counting true values at the end proves all nine appeared.
</details>

---

### PF-CS-051 · Heat Grid Hotspots

- **Tier:** 3 Intermediate · **Lecture:** L19 · Module 10
- **Context:** A thermal camera yields a 4×6 grid of temperatures.
- **Problem:** Design the pass that finds the hottest cell and lists every cell within 2.0° of it (ties allowed). Decide the traversal for "list all": one pass or two — and what each pass stores.
- **Input:** 4×6 doubles. **Output:** hottest cell + neighbor list.
- **Constraints:** temps −20…120.
- **Thinking questions:** Can you list neighbors before knowing the max? What does the second pass compare against?

<details><summary>Hints (progressive)</summary>

1. Pass 1 finds max and its cell; pass 2 filters.
2. One pass cannot list (it doesn't know the threshold yet).
3. |t − max| ≤ 2.0 with ≤ — ties included by design.
</details>

---

### PF-CS-052 · Matrix Border Sum

- **Tier:** 3 Intermediate · **Lecture:** L19 · Module 10
- **Context:** A framing tool sums the "picture frame" of a matrix.
- **Problem:** Design the border sum of an n×m matrix (first/last rows and columns) *without* double-counting corners. Trace on 3×3 with distinct values. What does your formula give for n == 1 (a single row)?
- **Input:** n, m, then the matrix. **Output:** border sum.
- **Constraints:** 1 ≤ n, m ≤ 10.
- **Thinking questions:** Which cells are border cells as a predicate? Which traversal avoids corner double-count?

<details><summary>Hints (progressive)</summary>

1. Predicate: r==0 || r==n−1 || c==0 || c==m−1.
2. One loop over all cells with the predicate is safe; row/column walks need corner care.
3. n==1: every cell is border — the predicate handles it naturally.
</details>

---

### PF-CS-053 · The Name Formatter

- **Tier:** 3 Intermediate · **Lecture:** L21 · Module 11
- **Context:** A form imports names in any capitalization.
- **Problem:** Design the normalization: trim surrounding spaces, collapse internal runs of spaces to one, and capitalize the first letter of each word. Trace on `"   aLI   rAZA   "`. Which of the three sub-tasks changes the string's length?
- **Input:** one line (may have messy spacing). **Output:** normalized name.
- **Constraints:** letters and spaces only; line ≤ 80 chars.
- **Thinking questions:** Can you build the result in a second string instead of editing in place? Which is easier to reason about?

<details><summary>Hints (progressive)</summary>

1. Out-of-range/collapsing edits shrink the string — indices shift.
2. A result string with append-only logic avoids index chaos.
3. Word starts = position 0 or right after a space.
</details>

---

### PF-CS-054 · Word Hunt with Word Boundaries

- **Tier:** 3 Intermediate · **Lecture:** L22 · Module 11
- **Context:** A text tool counts whole-word matches of a keyword.
- **Problem:** Design countWord(text, word) that matches whole words only ("cat" must not match "category" or "scatter"). Specify the boundary rule (start-of-text, end-of-text, non-letter) and trace on a two-sentence example.
- **Input:** text line, then keyword. **Output:** match count.
- **Constraints:** text ≤ 200 chars; word ≤ 20.
- **Thinking questions:** What makes a position a word *start*? Does case matter — and who decides?

<details><summary>Hints (progressive)</summary>

1. A match is valid iff the chars before and after are non-letter boundaries.
2. Find a candidate, check both boundaries, continue past it.
3. Case policy must be explicit: exact match here (state it in the doc).
</details>

---

### PF-CS-055 · Palindrome Judge with Punctuation

- **Tier:** 3 Intermediate · **Lecture:** L22 · Module 11
- **Context:** A quiz app judges phrase palindromes like "A man, a plan...".
- **Problem:** Design the judge that ignores case and non-alphanumerics. Specify the two-pointer method over the *cleaned* view and what it returns for strings that become empty after cleaning (e.g., "!!!" ). Trace on "No 'x' in Nixon".
- **Input:** one line. **Output:** `palindrome` / `not palindrome` / the empty-case verdict.
- **Constraints:** line ≤ 100 chars.
- **Thinking questions:** Where do the pointers start and stop? What does left ≥ right mean?

<details><summary>Hints (progressive)</summary>

1. Two pointers walk inward, skipping junk characters.
2. Cleaning first simplifies the walk — decide build-then-scan vs scan-with-skips.
3. Empty-after-cleaning: define it as a palindrome or reject — document the choice.
</details>

---

### PF-CS-056 · CSV Column Statistics

- **Tier:** 3 Intermediate · **Lecture:** L21 · Module 11
- **Context:** A marks file has lines `name,score` and some corrupt lines.
- **Problem:** Design the processing loop: parse each line, compute the class mean of valid scores, list invalid line numbers. Decide the two failure categories (missing comma vs non-numeric score) and their distinct messages.
- **Input:** lines until EOF. **Output:** mean (2 dp) + invalid line list.
- **Constraints:** ≤ 100 lines; scores 0…100.
- **Thinking questions:** Which stream state tells you the score parse failed? Why is getline-then-istringstream the robust shape?

<details><summary>Hints (progressive)</summary>

1. istringstream >> score fails on "abc" — the stream's bool tells you.
2. Two error buckets need two counters (or one list with reasons).
3. Mean over *valid* lines only; report the excluded ones.
</details>

---

### PF-CS-057 · The Acronym Builder

- **Tier:** 3 Intermediate · **Lecture:** L21 · Module 11
- **Context:** A department tool turns course titles into acronyms.
- **Problem:** Design acronym(line) that uppercases the first letter of each word and skips small words (of, and, the). Trace on "theory of computation and data". Specify the word-detection rule you rely on.
- **Input:** one title line. **Output:** the acronym.
- **Constraints:** line ≤ 80; small-word list fixed.
- **Thinking questions:** What counts as a word here? Where do you test membership in the small list?

<details><summary>Hints (progressive)</summary>

1. Words are maximal letter runs.
2. Test the whole word (not its letters) against the stop list.
3. toupper only on accepted words' first letters.
</details>

---

### PF-CS-058 · Insertion Sort on Playing Cards

- **Tier:** 3 Intermediate · **Lecture:** L24 · Module 12
- **Context:** A player sorts cards as they arrive, one at a time.
- **Problem:** Explain insertion sort with a hand of cards: each new card slides left into place. Design the in-place version with the inner while-loop, trace fully on [7, 3, 9, 3], and state why it does *no work* on already-sorted input.
- **Input:** n, then n integers. **Output:** sorted array + comparison count.
- **Constraints:** 1 ≤ n ≤ 50.
- **Thinking questions:** What is the sorted prefix at pass i? What makes the inner loop stop early?

<details><summary>Hints (progressive)</summary>

1. After pass i, a[0..i] is sorted.
2. Inner while shifts larger elements right until the hole is found.
3. Sorted input: the while fails immediately every pass — O(n) total.
</details>

---

### PF-CS-059 · Stable Ranking with Ties

- **Tier:** 3 Intermediate · **Lecture:** L24 · Module 12
- **Context:** A leaderboard must keep earlier entrants ahead on ties.
- **Problem:** Design the sort of (name, score) pairs by score descending, preserving input order for equal scores (stability). Trace on three pairs with two tied scores. Which of the class algorithms (selection, bubble, insertion) is stable if written carefully — and what does "carefully" mean?
- **Input:** n pairs. **Output:** ranked list.
- **Constraints:** 1 ≤ n ≤ 40; names unique.
- **Thinking questions:** What does stability require of swaps? Which algorithm never swaps equal elements?

<details><summary>Hints (progressive)</summary>

1. Stability: equal keys keep their relative order.
2. Selection sort's long-range swaps can jump over equal keys.
3. Insertion sort with strict > comparison never reorders equals — stable by construction.
</details>

---

### PF-CS-060 · Search Benchmark Disclosure

- **Tier:** 3 Intermediate · **Lecture:** L23 · Module 12
- **Context:** A vendor claims their "search" is instant; you must evaluate.
- **Problem:** Design the comparison: linear search vs binary search on the same sorted array, counting comparisons for (a) a present key, (b) an absent key. Produce the argument that answers "is binary always better?" — including the cost of *keeping* the array sorted.
- **Input:** sorted n values, then keys. **Output:** comparison counts per search.
- **Constraints:** 1 ≤ n ≤ 1000; keys may be absent.
- **Thinking questions:** What does binary search *require* as precondition? When is linear the right tool anyway?

<details><summary>Hints (progressive)</summary>

1. Binary pays a sorting price up front; linear pays per query.
2. Absent keys show the gap best: log₂ n vs n.
3. For tiny n or unsorted one-off queries, linear wins on simplicity and total cost.
</details>
