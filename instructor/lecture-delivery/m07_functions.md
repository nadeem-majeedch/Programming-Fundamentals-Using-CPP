# Delivery Guide — Module 7 · Functions Fundamentals (Week 7)

**Guides:** L13, L14 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L13 · Defining and Calling Functions: Parameters, Return Values, `void`

1. **Lecture/title:** L13 — Defining and Calling Functions: Parameters, Return Values, `void`
2. **Module/week:** Module 7 · Week 7 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_07/lecture_13.md): [lecture_13.md](../../lectures/week_07/lecture_13.md)): define and call functions with parameters and return values; distinguish `void` from value-returning; trace calls with call frames; decompose a main into functions per the Module 6 design.
4. **Prerequisite knowledge:** L11 decomposition; L06 expressions.
5. **Prep checklist:** compile `examples/functions_refactor.cpp` this morning; board plan for call-frame columns; load PF-CS-023; decide the day's pairings (designer/coder mixes from L11).
6. **Materials & files:** `examples/functions_refactor.cpp`; case PF-CS-023 Unit Converter with Contracts; T05 opening items.
7. **Opening question (10):** revisit L11's guided work: "your pseudocode had a step 'convert temperature' — where did that live in your code? Inline? Copy-pasted? Today we give steps *names*."
8. **Concept sequence (30):** (a) functions as named subproblems: parameters as the *inputs from the IPO chart*, return as the *output* (10); (b) `void` vs value-returning; multiple returns as guard exits (10); (c) call frames: what exists when a function runs (10).
9. **Explanation guidance:** teach the frame picture *before* any pass-by-value talk — parameters as boxes created per call, destroyed at return. This picture is reused in L15 (references) and L25 (pointers); consistency is the investment. Anti-pattern to name: functions that print instead of return — "a calculator that only says its answer aloud can't be used in the next sum."
10. **Demonstration (15):** [DEMO-13](../demonstrations/demo_group3_loops_functions.md) — `functions_refactor.cpp`: main monolith → three functions, refactored live; planned error: return inside a loop exits early — observe the truncated result, connect to "every return is an exit."11. **Output prediction:** trace a two-call sequence with a local shadowing a global-free name (frame picture predicts it); votes on whether the caller's variable changes — unanimous *no*, which is precisely the setup for L15's pass-by-reference.
12. **Case study (15):** **PF-CS-023 Unit Converter with Contracts** — designing function signatures *before* bodies: name, parameter types, return type as the "contract"; the class debates contract choices, then implements.
13. **Guided coding (20):** pairs decompose their L11 change-maker into `read_amount()`, `compute_change()`, `print_breakdown()`; TAs check signatures against the IPO chart — the design document becomes the API.
14. **Common misconceptions:** printing-instead-of-returning (named in concept sequence; banked as [MC-16](../misconception-bank/misconception_bank.md) family — see entry); "parameters are just labels for the caller's variables" — *not yet corrected*: that is L15's reveal, leave it standing deliberately and note it in your pacing.
15. **Debugging activity:** symptom: "my function prints the right answer but the program can't use it" — refactor to return under guidance; the diagnosis (wrong verb: print vs return) is the lesson.
16. **Independent practice (20):** T05 beginner items (first functions, void vs return); every student writes at least two functions with pre-declared contracts.
17. **Exit ticket (5):** (1) `void` vs `double` function: when must you use which? (2) In the frame picture, what happens to the parameter boxes at `return`?
18. **Summary (5):** derive: "a function is a named IPO — the design chart, compiled."
19. **Support:** signature-first worksheets (bodies provided, contracts chosen); sentence frame: "I name it ___, it takes ___, it returns ___."
20. **Extension:** convert one loop from L10 into a function taking `n` — parameterization as generalization; predict behavior for `n = 0`.
21. **Reflection:** how many pairs' signatures matched their IPO charts exactly? (Design-to-code transfer is Module 7's true outcome.) Did anyone's "parameters are aliases" belief surface early? Note names — L15's demo will target them.

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

## L14 · Scope, Lifetime, and Program Decomposition with Functions

1. **Lecture/title:** L14 — Scope, Lifetime, and Program Decomposition with Functions
2. **Module/week:** Module 7 · Week 7 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 4)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_07/lecture_14.md): [lecture_14.md](../../lectures/week_07/lecture_14.md)): distinguish local vs global scope; explain variable lifetime vs scope; use scope rules to justify program structure; decompose a program with parameters instead of shared globals.
4. **Prerequisite knowledge:** L13 call frames; L06 compound assignment.
5. **Prep checklist:** quiz 4 staged; compile `examples/scope_lifetime_demo.cpp`; prepare the shadowing edit-in-place; load PF-CS-038 (Scope Detective).
6. **Materials & files:** `examples/scope_lifetime_demo.cpp`; case PF-CS-038 Scope Detective; quiz 4 + key; T05 intermediate items.
7. **Opening question (10):** "Monday's three functions each needed `amount`. Why did nobody just declare it once at the top and share?" — collect the instinct, defer judgment: that is today's debate.
8. **Concept sequence (30):** (a) scope: where a name is *visible* — block rules, shadowing (12); (b) lifetime: when a box *exists* — locals die at `}`, statics teased only as a footnote (10); (c) globals as last resort: the coupling argument with the refactor evidence (8).
9. **Explanation guidance:** scope = visibility, lifetime = existence — draw the two timelines side by side for one local. The global argument is *evidential*, not moral: show the demo's two-version failure (function relies on a global; caller changes it; silent corruption), then the parameter version that cannot fail that way. "Data should travel on signatures, not through the air."
10. **Demonstration (15):** [DEMO-14](../demonstrations/demo_group3_loops_functions.md) — `scope_lifetime_demo.cpp`: shadowing surprise (inner `count` hides outer — predict, run, explain); planned error: the global-reliant function corrupting state across calls (silent logic bug).
11. **Output prediction:** shadowing trace (frame columns per call); the corrupted-accumulator two-call sequence — votes on the second call's result expose who thinks globals are "shared nicely".
12. **Case study (15):** **PF-CS-038 Scope Detective** — predict-output cases across nested scopes; run as team rounds, scores on the board.
13. **Guided coding (15 — quiz-day trim):** pairs de-globalize a provided 30-line program: every global becomes a parameter/return; TAs check that *no* global survived.
14. **Common misconceptions:** shadowing-as-merging; "globals are convenient" (corrected *with evidence* today); lifetime-scope conflation (see concept sequence).
15. **Debugging activity:** symptom: "function works when called once, wrong when called twice" — state carried in a global; trace-table across two calls finds it; the fix is parameterization (today's theme).
16. **Independent practice (10 — quiz-day trim):** scope-prediction items from T05.
17. **Quiz 4 (15):** per cadence.
18. **Exit ticket (5):** (1) Scope vs lifetime — one sentence each. (2) Why is a parameter safer than a global for the same value?
19. **Summary (5):** derive the de-globalization rule from the demo's failure story.
20. **Support:** two-timeline handout (visibility vs existence); the shadowing re-trace in pairs before solo.
21. **Reflection:** quiz 4 items on scope → who still reads shadowed names as one variable? Flag for L15 (references are coming, and confusion compounds).

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 4 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
