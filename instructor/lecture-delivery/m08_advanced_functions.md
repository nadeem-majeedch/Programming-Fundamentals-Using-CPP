# Delivery Guide — Module 8 · Advanced Function Concepts (Week 8)

**Guides:** L15, L16 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L15 · Function Overloading, Default Arguments, and Reference Parameters

1. **Lecture/title:** L15 — Function Overloading, Default Arguments, and Reference Parameters
2. **Module/week:** Module 8 · Week 8 · Lecture 1 of 2 (midterm Thursday/Friday this week — see L16)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_08/lecture_15.md): [lecture_15.md](../../lectures/week_08/lecture_15.md)): overload functions on parameter lists; use default arguments; *predict the binding* (which overload, which defaults); explain and use pass-by-reference, including out-parameters.
4. **Prerequisite knowledge:** L13–L14 frames and scope; L06 conversions (overload resolution uses them).
5. **Prep checklist:** compile `examples/overload_ref_demo.cpp` and `examples/passing_modes.cpp`; rehearse the ambiguous-overload diagnostic; load PF-CS-027 + PF-CS-028; prepare the caller's-variable-changes prediction vote.
6. **Materials & files:** `examples/overload_ref_demo.cpp`, `examples/passing_modes.cpp`; cases PF-CS-027 Overload Tournament, PF-CS-028 The Swap Handoff; [MC-09](../misconception-bank/misconception_bank.md) snippet.
7. **Opening question (10):** deliver L13's parked reveal: "last week you believed parameters are copies-that-talk-back. Vote: after `f(x)`, can `x` in main be different?" — collect votes, defer: today the vote gets *evidence*.
8. **Concept sequence (30):** (a) pass-by-value vs pass-by-reference on the frame picture (alias-label vs copy-box) (12); (b) out-parameters: `void split_time(int total, int& h, int& m, int& s)` — the return-plus-extras idiom (8); (c) overloading + defaults as compile-time selection; *predicting the bind* (10).
9. **Explanation guidance:** the alias-label is the visual keystone: `int& r` draws a *second label on the same box* — no copying, no new box. Then the reveal lands: value parameters copy, reference parameters alias, so *now* `f(x)` can change `x`. Keep overload resolution honest: exact match first, conversions next, ambiguity is an error — show one ambiguous diagnostic on purpose (planned error, see demo).
10. **Demonstration (15):** [DEMO-15](../demonstrations/demo_group3_loops_functions.md) — `passing_modes.cpp` three-way (value/const-ref/ref) on the same function; planned error: overload ambiguity (`f(3.5)` with int and double versions) → read the diagnostic, name the rule it violates.
11. **Output prediction:** the big one: caller's variable after `increment_v(x)` vs `increment_r(x)` — this vote *reverses L13's near-unanimous 'no'*; make the moment explicit ("evidence changed our answer — that is how CS works"). Then a default-argument bind prediction (partial args).
12. **Case study (15):** **PF-CS-028 The Swap Handoff** — why `swap_v(a,b)` cannot work; the class proves it on the frame picture before seeing `swap_r`. PF-CS-027 named as self-study.
13. **Guided coding (20):** pairs build `split_time` (3 out-params) and an overloaded `print_stats` (int-set / double-set); TAs check the `const` discipline: anything not written gets `const` — this is the rubric's style row from now on.
14. **Common misconceptions:** [MC-09](../misconception-bank/misconception_bank.md) (value-vs-reference) formal treatment — home lecture; "references are pointers-lite" — *not yet* said (L25 owns pointers); alias-vs-copy confusion addressed purely on the picture.
15. **Debugging activity:** symptom: "my function computes the average but main still shows 0" — out-parameter written but caller passed by value / or forgot `&`; two candidate lines, frame-picture diagnosis.
16. **Independent practice (20):** T05 reference/overload items; every student writes one in+out function and *predicts* the caller's state in a comment before running.
17. **Exit ticket (5):** (1) Draw (describe) what `int& r = n;` adds to the box picture. (2) `f(3)` with `f(int)` and `f(double)` present — which binds, and why?
18. **Summary (5):** derive the three passing modes' table from the demo; announce the midterm blueprint next lecture.
19. **Support:** alias-sticker exercise — name two labels on one paper box; re-run the swap proof with physical cards.
20. **Extension:** predict overload binding for `f(3.0f)`/`f('a')` with three overloads — resolution-order reasoning; verify.
21. **Reflection:** did the vote-reversal land? (Ask two students to narrate *why* they changed their vote — metacognition check.) Who still writes out-params without `&`?

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

## L16 · Debugging Methodology and Midterm Review · **MIDTERM EXAM**

1. **Lecture/title:** L16 — Debugging Methodology and Midterm Review · MIDTERM EXAM
2. **Module/week:** Module 8 · Week 8 · Lecture 2 of 2 — **EXAM DAY** (variant per hub § 3)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_08/lecture_16.md): [lecture_16.md](../../lectures/week_08/lecture_16.md)): apply the six-step debugging method to unseen defects; consolidate Modules 1–8 for the exam; sit the midterm (90 min, closed book).
4. **Prerequisite knowledge:** Modules 1–8; the DEBUG § 1 method.
5. **Prep checklist:** midterm papers printed from `instructor/exams/` (blueprint: `PAPER_ASSEMBLY.md`); room/seating plan; review deck = the course's own TRACE/DEBUG bank items; review-guide link posted (`exams/midterm/review_guide.md`).
6. **Materials & files:** midterm paper (forms A–D), answer keys (instructor area); review guide; [DEBUG_GUIDE § 3 tables](../DEBUGGING_GUIDE.md) as the review spine.
7. **Opening question (5 — exam-day variant):** none — logistics + calm. Papers distributed per your institution's process **[CONFIGURABLE]**.
8. **Exam (100):** sit the midterm per `instructor/exams/PAPER_ASSEMBLY.md` blueprint (100 minutes · 50 marks; 40 % conceptual / 60 % applied).
9. **Post-exam take-up (10):** the *hottest* DEBUG items re-derived on the board using the six-step method — students vote on the defective line, then the trace confirms. This take-up is where "exam as formative" happens; do not skip it.
10. **Demonstration:** none (exam day).
11. **Output prediction:** embedded in the paper (TRACE section) — not run live.
12. **Case study:** none (exam day).
13. **Guided coding:** none.
14. **Common misconceptions:** harvested *from the exam*: the items with worst class performance become the next four lectures' recall-question seeds — record them now.
15. **Debugging activity:** the take-up (9 above) IS the debugging activity, applied to exam-real defects.
16. **Independent practice:** none.
17. **Exit ticket (5, merged with summary):** one question only: "which topic felt least solid *today*?" — the honest list feeds L17's opening and your lab-9 TA briefing. Post-exam close: summary and ticket share the final 5 minutes (ticket collected as students leave).
18. **Summary (within item 17's close):** preview Module 9: "arrays — the first data *structure*"; name the week's lab connection.
19. **Support:** exam-access arrangements per institutional policy **[CONFIGURABLE]**; post-exam office-hours surge slot announced.
20. **Extension:** n/a.
21. **Reflection:** after marking: item-analysis the paper — which outcome code underperformed? (Feeds both L17's recall and any Module-9 emphasis shifts.)

| Segment | Min |
|---|---|
| Opening and logistics | 5 |
| Midterm examination | 100 |
| Post-exam take-up (debugging method on real items) | 10 |
| Exit ticket + summary/preview (post-exam close) | 5 |
| **Total** | **120** |
