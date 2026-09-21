# Demonstrations · Group 4 — Arrays, Grids, Strings (L17–L22)

**Instructor-only scripts.** Conventions as in
[demo_group1_basics.md](demo_group1_basics.md): edit-in-place planned errors,
contract build, verified output, 3-step diagnostic ritual.

---

## DEMO-18 · 1-D Arrays: Declaration, Traversal, the Silent Bounds Bug (L17)

- **Objective:** make the box-row memory model *visible*, then break the boundary and watch C++ stay silent.
- **Preparation:** compile `examples/array_basics.cpp`; board plan for the box-row picture (indices *above* boxes — METHOD § 4); rehearse the out-of-bounds run (verify your compiler's actual behavior first).
- **Source:** [examples/array_basics.cpp](../../examples/array_basics.cpp); bank entry [MC-11](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Declaration → init-list → traversal → element-assignment, predict-then-run per step; indices drawn *above* the boxes.
  2. **Planned error:** `arr[5] = 99` on a 5-element array — runs *silently*, then (on your compiler, verify first) show what the neighbor memory caught; contrast with the contract's warning if emitted.
  3. Rebuild with the loop bound `< N` vs `<= N` — the exam's favorite boundary, now embodied.
- **Questions:** "Why is the first index 0 — what does the number *measure*?" · "The write to `arr[5]` 'worked'. Did it? What does *worked* mean here?" · "Who polices the bounds in C++?"
- **Expected observations:** correct traversal; the silent corruption (or garbage read); the compiler's silence itself as the lesson.
- **Common student mistakes:** 1-based reflex; "the compiler will stop me" (it will not); `<=` in traversal loops.
- **Debugging variation:** symptom-only: "last element prints garbage" — pairs locate `arr[N]` by trace *before* running.
- **Extension:** predict then verify `{7}` vs `{}` vs no initializer — initializer-list semantics.
- **Verified output:** deterministic except the UB write (behavior compiler-dependent — say so and verify on the teaching machine); deterministic lines (init-list, traversal, assignment) stable.
- **Instructor notes:** the silence is the message: out-of-bounds is not an error, it is *lying memory*. The DS angle lands today — "a column of observations" is what data science *is* at this level.

---

## DEMO-19 · Array Algorithms Suite (with the Init-to-Zero Trap) (L18)

- **Objective:** run the six canonical algorithms predict-then-run, then break min/max with the classic initialization bug.
- **Preparation:** compile `examples/array_algorithms.cpp`; choose an all-negative dataset for the trap act.
- **Source:** [examples/array_algorithms.cpp](../../examples/array_algorithms.cpp); case PF-CS-047 as follow-up.
- **Delivery sequence:**
  1. Fill → print → sum/avg → min/max → count-if → linear search, each predict-then-run on a 5-element dataset; pattern name attached per algorithm (L10 vocabulary).
  2. **Planned error:** min/max initialized to `0` on the all-negative dataset → min prints 0; trace the running-candidate logic; fix (initialize from `a[0]`).
  3. Linear search: found (index) and not-found (−1) runs; early-exit visible with a counter.
- **Questions:** "Why is initializing max to 0 a *design* decision — and when is it wrong?" · "What should search return when absent — and why is −1 a safe convention?" · "Which of the six is a *filter*? A *search*?"
- **Expected observations:** six correct outputs; the 0-as-min artifact; the early exit count.
- **Common student mistakes:** avg computed in int (L06's cast — reconnect aloud); search returning 0 for "not found".
- **Debugging variation:** symptom-only: "average prints an integer" — three candidate lines, cast-before-divide located by trace.
- **Extension:** count-if with a *parameterized* predicate (threshold as an argument) — functions + arrays composing.
- **Verified output:** deterministic (fixed dataset); e.g. `sum=25 avg=5 min=2 max=9 count(>4)=3 found@2` — verify exact values locally and put the expected table on the board.
- **Instructor notes:** the min/max-init bug is *the* Module 9 exam face — run it slowly and let the wrong answer sit visible for a full beat before the trace. The cast-discipline callback (avg) should be *student*-voiced by now; prompt for it.

---

## DEMO-20 · 2-D Arrays: Grid Traversal, Axis Aggregates, Border Trap (L19)

- **Objective:** make row/column traversal and per-axis aggregation unambiguous, then double-count the border corners on purpose.
- **Preparation:** compile `examples/grid_basics.cpp` and `examples/matrix_ops.cpp`; grid chalk plan with both index rulers.
- **Sources:** [examples/grid_basics.cpp](../../examples/grid_basics.cpp), [examples/matrix_ops.cpp](../../examples/matrix_ops.cpp); bank entry [MC-12](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Row-major print → column-major print of the same grid: two shapes, one dataset; the visit-order lesson.
  2. **Planned error:** swapped inner bounds (`c < ROWS`) → garbage/silence; trace which index left the grid.
  3. Row totals (outer=rows) then column totals (outer=cols) — the axis rule stated and *applied both ways*.
  4. **Planned error 2:** border sum with double-counted corners → silent over-count; colour the counted cells on the board grid; the overlap is visible; fix the region walk.
- **Questions:** "Which loop is the slow hand in column-major?" · "For column totals, which axis does the *result* live on?" · "Which cells got counted twice — how would you prove it?"
- **Expected observations:** two print shapes; the bounds garbage; correct axis aggregates; the corner over-count.
- **Common student mistakes:** `[c][r]` reflex under time pressure; in-place transpose attempts (L20 corrects formally).
- **Debugging variation:** symptom-only: "my column totals print row totals" — paper-grid trace first, code second.
- **Extension:** transpose on paper for a non-square grid before coding (L20's assignment preview).
- **Verified output:** deterministic (fixed grids); e.g. 3×4 grid row sums `10 26 42`, col sums `12 18 24 24` (verify against your dataset locally; put the grid, not the answer, on the board).
- **Instructor notes:** the colour-the-cells move is the single highest-yield 2-D teaching act — it converts an abstract double-count into a picture a beginner can *see*. Budget the full 15; the second planned error is worth it.

---

## DEMO-21 · 2-D Processing: Transpose, Matrix Ops, Row/Column Aggregates (L20)

- **Objective:** run the matrix operations with the axis rule *applied*, then break the transpose in-place for a non-square grid.
- **Preparation:** compile `examples/matrix_ops.cpp`; paper grids pre-drawn for the transpose act.
- **Source:** [examples/matrix_ops.cpp](../../examples/matrix_ops.cpp); bank entry [MC-12](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Addition and scalar multiply predict-then-run — element-wise, no axis traps; name the shape rule (same dims).
  2. Transpose: paper act first (rows become columns on the grid), then code; non-square grid — predict the new shape *before* running.
  3. **Planned error:** in-place transpose on a non-square grid with `n×n` loop bounds → silent wrong shape/overwrites; the paper grid exposes what the code destroyed.
  4. Row totals vs column totals with the axis rule stated both ways (DEMO-20's rule, now applied under time pressure).
- **Questions:** "For a 3×4 grid, what shape is its transpose — and which loop bound guaranteed it?" · "Which cells must a diagonal walk visit?" · "Why is in-place transpose different for square vs rectangular grids?"
- **Expected observations:** correct ops; the wrong-shape artifact; the axis aggregates correct.
- **Common student mistakes:** writing the transposed result into the *same* array while still reading it; confusing `[r][c]` order in the swap.
- **Debugging variation:** symptom-only: "my 3×4 transpose prints a 4×3 full of half-wrong numbers" — the paper grid before the debugger.
- **Extension:** diagonal sum walk (`i == j`) — predict the count (n) then run; boundary walk revisited from L19.
- **Verified output:** deterministic (fixed grids); e.g. transpose of `{{1,2,3,4},{5,6,7,8},{9,10,11,12}}` printed correctly; the in-place attempt visibly wrong — verify locally.
- **Instructor notes:** the paper-grid-before-code rule pays for itself here — students who transpose on paper never write the in-place bug. This is the last pure-data lecture before strings; close by asking what a "row of characters" would be.

---

## DEMO-22 · Strings: Classifiers, Comparison, and the Two-Index Walk (L21)

- **Objective:** make character classification and string algorithms observable, then break the palindrome walk's middle.
- **Preparation:** compile `examples/string_processing.cpp` and `examples/string_algorithms.cpp`; rehearse the `'A' == "A"` diagnostic.
- **Sources:** [examples/string_processing.cpp](../../examples/string_processing.cpp), [examples/string_algorithms.cpp](../../examples/string_algorithms.cpp); bank entry [MC-13](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Classifier sweep over a mixed string (`isalpha/isdigit/isspace/toupper/tolower`) — predict-then-run per character class.
  2. Comparison: `"Apple" == "apple"` (false) → normalize with `tolower` → true; the content-compare lesson.
  3. **Planned error:** `if (ch == "A")` — char vs string literal; read the diagnostic; fix to `'A'`.
  4. Two-index palindrome walk on `"racecar"` — trace on the board (3 comparisons), then `string_algorithms` runs; **planned error 2:** condition `left < right` vs `left <= right` — observe (harmless overcheck here), then construct the case where it matters (empty/middle-edge) and discuss honestly.
- **Questions:** "What *is* `'A'` vs `"A"` — one is a character, one is...?" · "Why does normalization come *before* comparison?" · "How many comparisons does the walk make for n=7 — and why not 7?"
- **Expected observations:** classifier outputs; false→true after normalization; the type diagnostic; the traced walk.
- **Common student mistakes:** comparing with `==` expectations from other languages (works here — say so — but normalization is still on them); writing the walk with `<=` and never testing the middle case.
- **Debugging variation:** symptom: "my judge rejects 'A man, a plan...'" — the missing normalization layer; check layers one at a time.
- **Extension:** `myToupper` via char arithmetic (`c - 'a' + 'A'`) — L05 meets L21.
- **Verified output:** deterministic (fixed strings); e.g. classifier counts for `"Ci2Zn 9x"`; palindrome verdicts for the three test strings — verify locally, put the strings (not answers) on the board.
- **Instructor notes:** the `'A' == "A"` diagnostic is a gift — a compile error that *teaches type systems*. Read it aloud with the class; the anchor-word ritual applies to type errors too.

---

## DEMO-23 · C-Strings and `getline`: the Null Terminator, the Whitespace Bite (L22)

- **Objective:** make the null terminator *visible* and the `>>`/`getline` interplay concrete on legacy-style storage.
- **Preparation:** compile `examples/string_algorithms.cpp`; prepare a `char word[10]` snippet for the overflow act; rehearse the mixed-read run.
- **Sources:** [examples/string_algorithms.cpp](../../examples/string_algorithms.cpp); mixed-read companion `instructor/demonstrations/demo04_mixed_read.cpp` (reused); bank entry [MC-13](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. `char` array + terminator: print `strlen` vs the array size — the two "lengths" (content vs capacity) separated; the `'\0'` byte found by index.
  2. **Planned error:** `char word[10]` fed a 12-character word via unbounded read — discuss the overflow honestly (do not run the UB; *diagram* it: the terminator has nowhere to live). The safe forms shown (`std::string`, bounded reads).
  3. `cin >> word` vs `getline`: multi-word name — the whitespace bite returns in legacy dress; the `ignore` fix re-applied.
  4. String-view bridge: `std::string` *uses* this machinery underneath — the comfort object has an honest foundation.
- **Questions:** "Where exactly does the string end — how would you *prove* it?" · "Why must the array be one larger than the longest word?" · "Which read should take a full name — and why?"
- **Expected observations:** the two lengths; the diagrammed overflow; the whitespace artifact and fix.
- **Common student mistakes:** sizing arrays without terminator headroom; `cin >> ` for names; confusing `strlen` result with capacity.
- **Debugging variation:** symptom-only: "the last letter of my word prints as garbage" — the missing terminator; draw the bytes until the fix is obvious.
- **Extension:** write `myStrlen` by walking to `'\0'` — the library function, rebuilt, 6 lines.
- **Verified output:** deterministic for fixed inputs; e.g. `strlen("city")=4, capacity 10`; the mixed-read name printed whole after the fix — verify locally before class.
- **Instructor notes:** the diagrammed (not executed) overflow is deliberate — students must *see* the bytes without learning to fear UB as a game. Legacy C-string literacy is the stated goal; keep the `std::string`-first message intact.
