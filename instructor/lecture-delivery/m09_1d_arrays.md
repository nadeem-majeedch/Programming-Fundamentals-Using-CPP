# Delivery Guide — Module 9 · One-Dimensional Arrays (Week 9)

**Guides:** L17, L18 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L17 · 1-D Arrays: Declaration, Indexing, Bounds, and the Array–Memory Model

1. **Lecture/title:** L17 — 1-D Arrays: Declaration, Indexing, Bounds, and the Array–Memory Model
2. **Module/week:** Module 9 · Week 9 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_09/lecture_17.md): [lecture_17.md](../../lectures/week_09/lecture_17.md)): declare and initialize 1-D arrays; explain the contiguous-memory model; index with in-bounds guarantees; connect arrays to `size_t`-style index reasoning; explain why bounds violations are silent.
4. **Prerequisite knowledge:** L03 types; L10 loops (arrays are loop-shaped data).
5. **Prep checklist:** compile `examples/array_basics.cpp` this morning; board plan for the box-row picture (indices *above* boxes — METHOD § 4); load PF-CS-041; note today's recall seed: L16's worst-performing exam item.
6. **Materials & files:** `examples/array_basics.cpp`; case PF-CS-041 The Missing Temperature; [MC-11](../misconception-bank/misconception_bank.md) snippet.
7. **Opening question (10):** from the exit-ticket harvest: "the exam's hardest question involved N separate variables — what breaks when the count is 100? 1000?" Elicit the variable-explosion pain; arrays answer it.
8. **Concept sequence (30):** (a) arrays as indexed box-rows: declaration, zero-based indexing, the memory picture (contiguity) (10); (b) initialization lists, traversal with the counter loop, `arr[i]` as *a variable itself* (12); (c) bounds: C++ does not police them — why, and what "silent corruption" means (8).
9. **Explanation guidance:** the zero-start is motivated *geometrically*: index = distance from the start (first box is zero steps away). The DS angle lands today: "a column of observations" — arrays are what data science *is*, at this level. Do not soften the bounds message: out-of-bounds is not an error message, it is *lying memory* — which is why the contract's warnings exist and why L30's discipline matters.
10. **Demonstration (15):** [DEMO-18](../demonstrations/demo_group4_arrays_strings.md) — `array_basics.cpp`: declaration → init-list → traversal → element-assignment; planned error: `arr[5] = 99` on a 5-element array — runs *silently*, then (on your compiler, verify first) show what the neighbor memory caught; contrast with the contract's warning if emitted.
11. **Output prediction:** three-vote ladder: `a[0]` after init-list; the loop that prints indices vs values (classic mix-up); the out-of-bounds write — third vote is "anything could happen", and that answer is *correct* (undefined behavior, first formal naming).
12. **Case study (15):** **PF-CS-041 The Missing Temperature** — sentinel/absent-value handling inside an array context; DS-relevant (missing data) — run the 5-minute protocol.
13. **Guided coding (20):** pairs fill/print/modify a 5-element array; TAs enforce: `const int N = 5;` (no magic numbers), zero-start discipline, and a prediction comment before each element write.
14. **Common misconceptions:** [MC-11](../misconception-bank/misconception_bank.md) (bounds) — home lecture; the 1-vs-0 start (MC-07 family, now on arrays); "array size is knowable inside the function" — *parked* for L18's pass-with-size discussion, noted in pacing.
15. **Debugging activity:** symptom: "last element prints garbage" — off-by-one read `arr[N]`; pairs locate it by trace *before* running; the fix is `<` not `<=` (the exam's favorite).
16. **Independent practice (20):** T06 opening items (declare/init/traverse); DS students: DS-04 (min/max — next lecture's preview) as stretch.
17. **Exit ticket (5):** (1) `int a[4] = {7};` — what are `a[0]`…`a[3]`? (2) Why is `a[4]` dangerous even though it *compiles*?
18. **Summary (5):** derive: "an array is many boxes, one name, distance-numbered — and C++ trusts you with the edges."
19. **Support:** paper box-rows with movable index arrows; pairing confident typists with confident tracers; the `<` vs `<=` sticky-note.
20. **Extension:** predict then verify what `{7}` does vs `{}` vs no initializer — initializer-list semantics; tie to L03 initialization discipline.
21. **Reflection:** did the silent-corruption demo produce the intended wariness? Count students who wrote a bounds-check unprompted — that is the Module 9 outcome signal.

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

## L18 · Array Algorithms: Fill, Print, Sum/Average, Min/Max, Count, Linear Search

1. **Lecture/title:** L18 — Array Algorithms: Fill, Print, Sum/Average, Min/Max, Count, Linear Search
2. **Module/week:** Module 9 · Week 9 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 5)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_09/lecture_18.md): [lecture_18.md](../../lectures/week_09/lecture_18.md)): implement the six canonical array algorithms; trace them on the state table; pass arrays to functions *with* their size; select the right pattern for a stated task.
4. **Prerequisite knowledge:** L17 arrays; L10 loop patterns (accumulate/count/filter/search — the vocabulary pays off today).
5. **Prep checklist:** quiz 5 staged; compile `examples/array_algorithms.cpp`; prepare the parallel-arrays edit-in-place; load PF-CS-047 + PF-CS-014.
6. **Materials & files:** `examples/array_algorithms.cpp`; cases PF-CS-047 Frequency Table from Scratch, PF-CS-014 Class Attendance Percentages; quiz 5 + key.
7. **Opening question (10):** "Write `max` for 5 numbers *without arrays* using your L10 patterns — now imagine 500 numbers. What survives? What breaks?" — the accumulator survives; the variable-count breaks; arrays + the same pattern = today.
8. **Concept sequence (30):** (a) the six algorithms as *pattern applications*: fill (mapper), sum/avg (accumulator), min/max (accumulator-with-logic), count-if (counter), linear search (search) (18); (b) passing arrays to functions — what actually travels, why size travels separately, `const` for read-only (12).
9. **Explanation guidance:** every algorithm is *named, then traced on a 4-element array* — the pattern names from L10 are the retrieval structure. Min/max: initialize the running candidate from `a[0]` (not 0 — grades can be negative-adjacent discussions show why); search: teach found-index-vs-found-bool outputs and early-exit via `break`.
10. **Demonstration (15):** [DEMO-19](../demonstrations/demo_group4_arrays_strings.md) — `array_algorithms.cpp`: the six in sequence, each predict-then-run on a small dataset; planned error: min/max initialized to 0 on an all-negative dataset — silent wrong answer, trace-table resolved.
11. **Output prediction:** the all-negative min/max (votes will say 0 — the demo proves otherwise); linear search on absent target (what should the function return? — design vote, not syntax vote).
12. **Case study (15):** **PF-CS-047 Frequency Table from Scratch** — count-if generalized to counting *all* values; the class designs the frequency approach (parallel arrays or index-as-key) — foreshadows L20's 2-D thinking.
13. **Guided coding (15 — quiz-day trim):** pairs implement sum→avg (cast discipline from L06!) and count-if with a predicate chosen by dice/prompt; TAs check the `const` on read-only params.
14. **Common misconceptions:** min/max init-to-zero; avg computed as int (MC-03 returns with arrays — connect the threads aloud); array-size-inside-function (resolved today via pass-with-size).
15. **Debugging activity:** symptom: "average prints an integer" — three candidate lines; cast-before-divide located by trace; symptom 2: "search always says not-found" — return-inside-loop vs after-loop placement.
16. **Independent practice (10 — quiz-day trim):** T06 algorithm items (one accumulator + one search minimum).
17. **Quiz 5 (15):** per cadence.
18. **Exit ticket (5):** (1) Why does `find()` return −1 (convention) rather than 0? (2) Signature: a function that *reverses* an array in place — write it (name, params, const-ness).
19. **Summary (5):** the six algorithms → the four patterns map, derived by the class; DS students explicitly pointed at the DS track for statistics versions.
20. **Support:** algorithm skeleton cards (fill/sum/min/max/count/search outlines to complete); trace-template with the candidate variable pre-named.
21. **Reflection:** quiz 5 + exit tickets → who confuses search-found vs search-index? (Binary search in L23 will compound it.) Module 10 needs 2-D fluency in traversal — note who traced rows/columns mixed.

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 5 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
