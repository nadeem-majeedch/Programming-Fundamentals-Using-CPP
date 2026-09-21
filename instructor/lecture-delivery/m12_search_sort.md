# Delivery Guide — Module 12 · Searching and Sorting (Week 12)

**Guides:** L23, L24 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L23 · Linear Search vs Binary Search: Correctness and Comparisons

1. **Lecture/title:** L23 — Linear Search vs Binary Search: Correctness and Comparisons
2. **Module/week:** Module 12 · Week 12 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_12/lecture_23.md): [lecture_23.md](../../lectures/week_12/lecture_23.md)): implement linear search with early exit; explain the binary-search precondition (sorted) and implement the half-interval loop; trace both on the same data; articulate *why* binary wins asymptotically (complexity intuition: halving vs scanning).
4. **Prerequisite knowledge:** L18 linear search; L10 loop patterns.
5. **Prep checklist:** compile `examples/search_compare.cpp` this morning; prepare the sorted-array prop (or the number-guessing game script); load PF-CS-071 + PF-CS-060; count `mid = (lo+hi)/2` overflow-irrelevance at course data sizes (state honestly, don't drill).
6. **Materials & files:** `examples/search_compare.cpp`; cases PF-CS-071 Binary Search Contract Test, PF-CS-060 Search Benchmark Disclosure; [MC-14](../misconception-bank/misconception_bank.md) snippet.
7. **Opening question (10):** the number-guessing game: "I'm thinking of 1–100. You get yes/no questions. What's the best strategy?" — elicit halving *before* the word "binary" is said; the game IS binary search.
8. **Concept sequence (30):** (a) linear search recap + early exit; count comparisons on 8 elements (8); (b) binary search: the invariant picture — *the answer, if it exists, is always between lo and hi*; the three-way shrink (12); (c) complexity intuition: 8→3 comparisons, 1000→10, 1,000,000→20 — halving is exponential *savings*; linear is proportional (10).
9. **Explanation guidance:** the invariant sentence is the lecture's keystone — write it on the board and *test every loop version against it*. Teach the loop as `lo..hi` inclusive with `while (lo <= hi)` — then show the `lo < hi` variant's missing-final-element bug (bank [MC-14](../misconception-bank/misconception_bank.md) adjacent; the demo's planned error). Complexity intuition stays *counting comparisons*, never big-O notation — the course's promise.
10. **Demonstration (15):** [DEMO-24](../demonstrations/demo_group5_search_pointers_structs.md) — `search_compare.cpp`: both searches on the same sorted array, comparison counters live; planned error: the `lo < hi` variant loses the final candidate — silent wrong answer, trace-table exposes the dropped boundary.
11. **Output prediction:** comparison counts for target-at-start/middle/end/absent (both searches); the absent-target binary walk (lo/hi/mid table on the board, class chants the shrink).
12. **Case study (15):** **PF-CS-071 Binary Search Contract Test** — the precondition as a *contract*: what breaks (silently!) if the array isn't sorted; ties directly to MC-14's teaching note.
13. **Guided coding (20):** pairs implement both searches as functions (contract: return index or −1) and *count comparisons* with a counter variable; TAs attack-test: unsorted input to binary search (observe the lie), single-element arrays, target at both ends.
14. **Common misconceptions:** "binary search works on anything" (precondition blindness — case-study debunked); off-by-one in `lo <= hi` vs `lo < hi` (demo); "compare once per element is fine" — answered by the counting exercise, not by preaching.
15. **Debugging activity:** symptom: "binary search says not-found but the element is there" — three candidates: unsorted input, `lo < hi`, wrong mid-update; the invariant-check locates which assumption broke.
16. **Independent practice (20):** T08 search items (both searches + comparison counting); DS students: DS-09's search variant.
17. **Exit ticket (5):** (1) The invariant, in your own words. (2) Comparisons to find 1,000,000th-element-worst-case: linear vs binary — two numbers.
18. **Summary (5):** derive the halving table from the class's counts; name the trade: *sorted-ness is bought once, halving pays forever* (foreshadows L24's sort cost).
19. **Support:** the guessing-game replay for students who lost the invariant; pre-drawn lo/hi/mid trace tables with first row filled.
20. **Extension:** interpolation-search tease ("what if data is *uniform* — can we guess better than mid?") — discussion only; complexity taste beyond the course.
21. **Reflection:** can the class state the precondition unprompted? (L24 will need it: sorting *enables* binary search.) Who counted comparisons by formula instead of trace?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L24 · Selection Sort and Bubble Sort: Tracing, Swapping, Complexity Intuition

1. **Lecture/title:** L24 — Selection Sort and Bubble Sort: Tracing, Swapping, Complexity Intuition
2. **Module/week:** Module 12 · Week 12 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 8)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_12/lecture_24.md): [lecture_24.md](../../lectures/week_12/lecture_24.md)): trace and implement selection sort; trace bubble sort with early exit; write a correct swap (references from L15); count comparisons/swaps for complexity intuition (quadratic feel); sort parallel arrays safely.
4. **Prerequisite knowledge:** L23 search + comparison counting; L15 references (swap needs them); L17 arrays.
5. **Prep checklist:** quiz 8 staged; compile `examples/sorting_traced.cpp`; prepare physical sort props (index cards with numbers); load PF-CS-058 + PF-CS-059.
6. **Materials & files:** `examples/sorting_traced.cpp`; cases PF-CS-058 Insertion Sort on Playing Cards, PF-CS-059 Stable Ranking with Ties; quiz 8 + key; [MC-15](../misconception-bank/misconception_bank.md) snippet.
7. **Opening question (10):** eight volunteers hold shuffled number cards; class directs a sort *by shouting instructions* ("swap positions 2 and 5...") — the instructor follows instructions *literally*, including bad ones. The pain of imprecise instructions is the algorithm-design setup.
8. **Concept sequence (30):** (a) selection sort: find-min-of-rest, swap-to-front — the growing-sorted-region picture (12); (b) bubble sort: adjacent compares, early exit on no-swap pass (9); (c) comparison/swap counting: n−1 + n−2 + ... — the *quadratic feel* (why 10× data ≈ 100× work) (9).
9. **Explanation guidance:** both sorts are taught *by physical trace first* (cards on the desk, instructor as the loop). Selection = "choose then place"; bubble = "compare neighbours, push extremes". The swap is L15's `swap_r` — references paying rent. Stability (ties keep order) is demonstrated, not defined: two same-mark students' name order survives selection? (No — show it.) That's PF-CS-059's seed.
10. **Demonstration (15):** [DEMO-25](../demonstrations/demo_group5_search_pointers_structs.md) — `sorting_traced.cpp`: both sorts traced pass-by-pass with counters; planned error: swap-by-value (calls L13's `swap_v` — silently does nothing); the frame picture *proves* why, full circle to L15.
11. **Output prediction:** pass-by-pass array states (the exam's TRACE face); comparison counts for sorted vs reverse inputs (bubble's early exit shines — votes); the no-op swap prediction.
12. **Case study (15):** **PF-CS-059 Stable Ranking with Ties** — stability as a *design requirement*; class designs the tie-breaking rule; PF-CS-058 (insertion via cards) as the named extension.
13. **Guided coding (15 — quiz-day trim):** pairs implement selection sort + swap-as-function; stretch: sort parallel arrays (names+marks) *by marks* — the index-sort variant that keeps alignment (PF-CS-046's lesson, reused).
14. **Common misconceptions:** swap-by-value ([MC-15](../misconception-bank/misconception_bank.md) adjacent — actually MC-09's array face; the demo owns it); "sorted output means sorted input was required" (selection doesn't care — contrast with binary search's precondition, L23's lesson inverted); comparison-count confusion (comparisons ≠ swaps).
15. **Debugging activity:** symptom: "my sort produces... the same array" — the by-value swap; frame-picture diagnosis in 60 seconds once you see it — make a student *be* the frame.
16. **Independent practice (10 — quiz-day trim):** one trace table + one implementation from T08.
17. **Quiz 8 (15):** per cadence.
18. **Exit ticket (5):** (1) Pass count for selection sort on 6 elements — and total comparisons, shown by addition. (2) Why must `swap` take references?
19. **Summary (5):** the quadratic feel derived from the class's own counts (10× data → ~100× work); sort-cost note: "L23's halving needs this price paid first."
20. **Support:** physical cards remain available during guided work; skeleton sort with the find-min step pre-written.
21. **Reflection:** did the counting exercise build *intuition* (no formulas demanded)? Who's ready for PF-CS-033 (Hanoi, exponential growth contrast)? Names for the DS track's sorting-taste discussion.

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 8 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
