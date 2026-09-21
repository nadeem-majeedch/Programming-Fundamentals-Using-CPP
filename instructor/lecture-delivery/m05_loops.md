# Delivery Guide — Module 5 · Loops and Repetition (Week 5)

**Guides:** L09, L10 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L09 · `while` and `do-while`: Sentinel and Input-Controlled Loops

1. **Lecture/title:** L09 — `while` and `do-while`: Sentinel and Input-Controlled Loops
2. **Module/week:** Module 5 · Week 5 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_05/lecture_09.md)): write `while` loops with correct initialization/condition/update; use sentinel-controlled and input-validation loops; predict and prevent infinite loops; use `do-while` for at-least-once logic.
4. **Prerequisite knowledge:** L07 conditions; L04 stream state (validation loops build on it).
5. **Prep checklist:** compile `examples/loops_sum_digits.cpp` and `examples/loop_patterns.cpp` this morning; rehearse the hang-on-EOF behavior with piped input so you can *show* it safely; load PF-CS-016; board plan for the loop-anatomy annotation.
6. **Materials & files:** `examples/loops_sum_digits.cpp`, `examples/loop_patterns.cpp`; case PF-CS-016 Sum Until the Sentinel; [MC-04](../misconception-bank/misconception_bank.md), [MC-05](../misconception-bank/misconception_bank.md), [MC-06](../misconception-bank/misconception_bank.md) snippets.
7. **Opening question (10):** "Print `I will trace loops` 100 times — write the honest version of your program." The copy-paste version writes itself; its pain is the motivation.
8. **Concept sequence (30):** (a) loop anatomy: init / condition / update as the three-part contract — annotate one `while` on the board with all three labelled (10); (b) sentinel-controlled loops (12); (c) input-validation loops + `do-while` for prompts (8).
9. **Explanation guidance:** the loop contract framing ("something must *move toward false*") prevents more infinite loops than any rule-list. For sentinels, teach the read-then-check shape and *name* the trap: reading into the variable inside the body *after* the check is how the sentinel gets summed (MC-06 lives here — see its entry).
10. **Demonstration (15):** [DEMO-09](../demonstrations/demo_group3_loops_functions.md) — sentinel sum live; planned error: move the read inside so the sentinel is consumed — observe the wrong total; then the EOF variant with piped input (safe hang demo: run with a 3-second timeout).
11. **Output prediction:** two-stage: the sentinel-sum trace (state table, 4 rows); then the MC-06 variant — votes will defend both totals; resolve by tracing *where the read happens*.
12. **Case study (15):** **PF-CS-016 Sum Until the Sentinel** — the canonical sentinel design debate: which loop shape, where the read goes, why the guard matters.
13. **Guided coding (20):** pairs build a validation loop ("keep asking until 1–100") and a sentinel mean; TAs test with: empty input, sentinel-first, non-numeric garbage — the three behaviors that separate understanding from pattern-matching.
14. **Common misconceptions:** [MC-04](../misconception-bank/misconception_bank.md) (infinite-loop condition), [MC-05](../misconception-bank/misconception_bank.md) (missing update), [MC-06](../misconception-bank/misconception_bank.md) (read-in-loop structure) — all three live here; the demo hits MC-06, guided practice will surface MC-05 naturally.
15. **Debugging activity:** symptom: "my program never asks again / never stops" — pairs classify which of MC-04/05/06 from behavior + one line of code; three mini-cases projected.
16. **Independent practice (20):** T03 loop-mechanics items (count-up/down, validation); DS students: DS-05 opener (read-until-EOF counting — sentinel's data cousin).
17. **Exit ticket (5):** (1) In a sentinel loop, why must the *first* read happen before the loop? (2) What are the two ways `while (cin >> x)` exits?
18. **Summary (5):** derive the loop contract from the class's own trace rows; name the three failure modes one final time.
19. **Support:** physical tracing — students walk the loop: one is the condition, one is the body; the "update" student must announce movement toward false each pass.
20. **Extension:** digit-extraction pipeline (`n % 10`, `n /= 10`) — the L05 modulo payoff; predict the reversal of 3-digit numbers before coding.
21. **Reflection:** how many students' mean programs survived the three attack inputs? (That count is the week's true formative score.) Which misconception dominated tickets?

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

## L10 · `for`, Nested Loops, `break`/`continue`, and Loop Patterns

1. **Lecture/title:** L10 — `for`, Nested Loops, `break`/`continue`, and Loop Patterns
2. **Module/week:** Module 5 · Week 5 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 2 · Module 5 sample)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_05/lecture_10.md): [lecture_10.md](../../lectures/week_05/lecture_10.md)): write `for` loops and map them to while; trace nested loops (total iterations); use `break`/`continue` deliberately; recognize the accumulation/count/filter loop patterns.
4. **Prerequisite knowledge:** L09 while-loops; L07 conditions.
5. **Prep checklist:** quiz 2 staged; compile `examples/loop_patterns.cpp`; prepare the 3×3 nested-loop trace grid; load PF-CS-011.
6. **Materials & files:** `examples/loop_patterns.cpp`; case PF-CS-011 Traffic Light Cycle; quiz 2 + key.
7. **Opening question (10):** "Here is Monday's while-loop. Write its `for` translation — then vote: are they *the same* loop?" (Yes — `for` is packaging; the contract is identical.)
8. **Concept sequence (30):** (a) `for` anatomy as the loop contract folded into one line; scope of the counter (12); (b) nested loops: the *clock* model (outer = slow hand, inner = fast hand); total-iterations arithmetic (12); (c) `break`/`continue` with the traffic-light mental model (6).
9. **Explanation guidance:** nested-loop iteration counting is the exam skill: rows × columns, but *derived* by tracing the grid, not memorized. Have the class hand-simulate a 3×3 grid: 9 announcements, "row 0: col 0,1,2..." chanted — audible patterns stick.
10. **Demonstration (15):** [DEMO-10](../demonstrations/demo_group3_loops_functions.md) — loop patterns (sum/count/filter) with the pattern names attached; planned error: swap `continue` for `break` in the filter — observe the *set* difference live.
11. **Output prediction:** nested-loop output shape (grid of `i*j`); then total-iteration count for `i<j` triangular case — votes split; the trace grid resolves it.
12. **Case study (15):** **PF-CS-011 Traffic Light Cycle** — cycle design with nested time; loop-choice justification (which construct *fits* the timing, and why).
13. **Guided coding (15 — quiz-day trim):** pairs produce multiplication-table output, then the triangular variant; TAs ask "how many total prints — prove it by trace, not formula."
14. **Common misconceptions:** off-by-one in `for` bounds (the [MC-07](../misconception-bank/misconception_bank.md) family arrives formally with arrays in L17 — plant it now with `<` vs `<=` on the counter); continue/break scope confusion shown in the demo.
15. **Debugging activity:** symptom: "my triangle prints a square" — one-character bug; pairs find it by reading the inner condition against the desired shape.
16. **Independent practice (10 — quiz-day trim):** T03 nested-loop + pattern items.
17. **Quiz 2 (15):** per cadence; invigilation per [../ASSESSMENT_GUIDE.md](../ASSESSMENT_GUIDE.md) § 3.
18. **Exit ticket (5):** (1) Total iterations: `for i in 0..2 { for j in 0..3 }` — number + one-line proof. (2) One sentence: `break` vs `continue`.
19. **Summary (5):** derive the clock model from the class's chant; name the four patterns (accumulate/count/filter/search) — the course's loop vocabulary from here on.
20. **Support:** quiz repair loop per ASSESSMENT § 4; the grid-trace template for students lost in nested bounds.
21. **Reflection:** pattern-name fluency check — when Module 6 asks for algorithms, can this class *say* "that's a filter"? Ticket (1) proofs reveal formula-vs-trace thinkers.

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 2 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
