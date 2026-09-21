# Delivery Guide — Module 4 · Decision-Making Statements (Week 4)

**Guides:** L07, L08 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L07 · `if`, `if/else`, and Nested Selection

1. **Lecture/title:** L07 — `if`, `if/else`, and Nested Selection
2. **Module/week:** Module 4 · Week 4 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_04/lecture_07.md)): write conditions with relational and logical operators; use if/else and nested selection; trace branching programs with the state table; guard invalid input inside decisions.
4. **Prerequisite knowledge:** L05–L06 expressions; L04 stream state (guards return here).
5. **Prep checklist:** compile `examples/decisions_grade.cpp` this morning; prepare the `=`-vs-`==` snippet in edit-in-place form; load PF-CS-022; note today's break placement (after guided practice).
6. **Materials & files:** `examples/decisions_grade.cpp`; case PF-CS-022 The Safe Division Service; [MC-01](../misconception-bank/misconception_bank.md) + [MC-02](../misconception-bank/misconception_bank.md) snippets.
7. **Opening question (10):** "You must print PASS only for marks ≥ 60 — write the *question* the computer must ask, in English, then in symbols." Elicit `>=` vs the two-condition form; both accepted, precision noted.
8. **Concept sequence (30):** (a) conditions as questions with boolean answers; relational + logical operators (10); (b) `if` / `else` / `else if` chains — order matters, first-match wins (12); (c) nested selection + guard clauses for validation (8).
9. **Explanation guidance:** teach the *chain* as a decision ladder where each rung is only reached if earlier rungs said no — students who see ladders stop writing overlapping conditions. Keep the guard pattern concrete: "validate, then compute" appears in every lab from now on.
10. **Demonstration (15):** [DEMO-07](../demonstrations/demo_group2_operators.md) — `decisions_grade.cpp` grade ladder; planned error: `if (mark = 60)` — the silent bug the whole course has waited for: compiles (with warning under contract flags), then always-true. Run it, observe, THEN explain assignment-in-condition ([MC-01](../misconception-bank/misconception_bank.md)).
11. **Output prediction:** three-condition ladder with a boundary value (exactly 60); then `if (x = 5)` vs `if (x == 5)` — the second vote should be near-unanimous *wrong* the first time; that is the lesson.
12. **Case study (15):** **PF-CS-022 The Safe Division Service** — guard the denominator before dividing; validation meets decisions; connect back to L05's division trap.
13. **Guided coding (20):** pairs extend `decisions_grade.cpp` with a validation guard (reject <0 or >100) and a nested band for "+/- grades"; TAs attack-test with boundary values (59, 60, 100, 101, letters).
14. **Common misconceptions:** [MC-01](../misconception-bank/misconception_bank.md) formal treatment today (home lecture); precedence-in-conditions ([MC-02](../misconception-bank/misconception_bank.md) §) shown via `if (x > 0 && x < 10)` needing no parentheses vs `if (x & 1) == 0`-style traps avoided.
15. **Debugging activity:** symptom: "my program always says Distinction" — three candidate lines, one has `=`; classify *before* fixing (silent-warning class under contract flags).
16. **Independent practice (20):** in-class decision set (bands, max-of-three, leap-year band check); boundary-value discipline: every condition tested at both edges.
17. **Exit ticket (5):** (1) Trace: `int x=5; if (x=0) ... else cout << x;` — what prints? (2) Why do we test exactly 59/60 on a ≥60 band?
18. **Summary (5):** derive: "a program becomes interesting when it answers different questions differently — conditions are the questions."
19. **Support:** decision-ladder worksheet (paper ladder, conditions on rungs) before code; the MC-01 practice task in pairs.
20. **Extension:** De Morgan translation drills (negating compound conditions) — paper exercise, feeds L09 boolean loops.
21. **Reflection:** did the `=` demo produce the intended shock? (If votes were already correct, use the follow-up: `while (x = 10)`.) Are guards appearing unprompted in guided work?

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

## L08 · `switch`, Multi-Way Selection, and the Conditional Operator

1. **Lecture/title:** L08 — `switch`, Multi-Way Selection, and the Conditional Operator
2. **Module/week:** Module 4 · Week 4 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 1 · Modules 1–4 content sample; timing per hub § 3)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_04/lecture_08.md): [lecture_08.md](../../lectures/week_04/lecture_08.md)): use `switch` with `case`/`break`/`default`; explain fall-through and when switch beats a chain; read the conditional operator.
4. **Prerequisite knowledge:** L07 conditions; L05 operators.
5. **Prep checklist:** quiz 1 printed/uploaded per calendar; compile `examples/switch_menu.cpp`; prepare the missing-break edit-in-place; load PF-CS-006.
6. **Materials & files:** `examples/switch_menu.cpp`; case PF-CS-006 Parking Fee; quiz 1 (from `quizzes/quiz_01/`) + key (instructor area).
7. **Opening question (10):** ticket-built recall + "a menu with 5 options: what does the if-chain look like? Is it *pleasant*?" — the dissatisfaction is the motivation for switch.
8. **Concept sequence (30):** (a) switch anatomy: integral selector, case labels, `break`, `default` (15); (b) fall-through demonstrated *visibly* — then the deliberate fall-through idiom (grouped cases) (10); (c) conditional operator as a one-line choose (5).
9. **Explanation guidance:** fall-through is the star: "cases are labels on a jump board; without `break`, execution *keeps walking*." The grouped-case idiom (`case 1: case 2:`) converts the hazard into a tool. Switch's limits (no strings, no ranges) stated plainly.
10. **Demonstration (15):** [DEMO-08](../demonstrations/demo_group2_operators.md) — `switch_menu.cpp`; planned error: remove one `break` → observe the walk-off live, then fix and re-run to contrast.
11. **Output prediction:** switch with a removed break (predict the spill-over); conditional-operator one-liner vs equivalent if/else — equivalence vote.
12. **Case study (15):** **PF-CS-006 Parking Fee** — tiered fees; class debates chain vs switch fit; ranges force the chain — a *fit* lesson, not a syntax lesson.
13. **Guided coding (15 → trimmed):** pairs convert an if-chain menu to switch with grouped cases; TAs check `default` presence.
14. **Common misconceptions:** missing-break as the week's bank candidate (documented in the demo; full bank entry lives with MC-02's family — no dedicated ID this week); "switch works on strings" corrected in passing.
15. **Debugging activity:** symptom: "my menu runs two actions" — locate the missing break from behavior alone; name the mechanism in one sentence.
16. **Independent practice (10 → trimmed):** menu conversion item; quiz takes the remaining time.
17. **Quiz 1 (15):** per `quizzes/README.md` cadence — 15 min, announced last week; invigilate per [../ASSESSMENT_GUIDE.md](../ASSESSMENT_GUIDE.md) § 3.
18. **Exit ticket (5):** (1) When is switch the *wrong* tool? (2) `grade == 'A' ? "pass-high" : "keep-going"` — what is this, in plain words?
19. **Summary (5):** derive the switch-fit rule (integral selector, equality cases) from the parking-fee debate.
20. **Support:** students who scored poorly on the quiz get the ladder worksheet re-run as homework alongside next week's reading — link quizzes to repair, not just records (ASSESSMENT § 4).
21. **Reflection:** quiz item-level results → which misconception needs next lecture's opening? (This is the recall-question generator.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 1 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

*Quiz-day note: this variant splits the hub's practice minutes to insert the quiz; every other lecture in this guide uses the canonical table.*
