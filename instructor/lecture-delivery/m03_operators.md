# Delivery Guide — Module 3 · Operators and Expressions (Week 3)

**Guides:** L05, L06 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L05 · Arithmetic Operators, Precedence, and Integer vs Floating-Point Division

1. **Lecture/title:** L05 — Arithmetic Operators, Precedence, and Integer vs Floating-Point Division
2. **Module/week:** Module 3 · Week 3 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_03/lecture_05.md)): apply arithmetic operators with correct precedence/associativity; explain and predict integer vs floating-point division; predict negative-operand modulo; combine operators into correct expressions.
4. **Prerequisite knowledge:** L03 types; L05 needs only L03's `int`/`double`.
5. **Prep checklist:** compile `examples/precedence_demo.cpp` this morning; rehearse negative-modulo output on *your* compiler and mark it as the documented behavior it is; load PF-CS-005; board space for the precedence ladder.
6. **Materials & files:** `examples/precedence_demo.cpp`; case PF-CS-005 The Grading Curve Debate; [MC-03](../misconception-bank/misconception_bank.md) minimal snippet.
7. **Opening question (10):** predict `17 / 5` and `17 % 5` — votes first, no explanation. The split *is* the lesson's engine.
8. **Concept sequence (30):** (a) the arithmetic set + precedence ladder (as *agreement rules* the compiler follows, not arbitrary tables) (10); (b) **integer division** — the quotient/remainder picture: `17 = 5*3 + 2` so `/` gives 3 and `%` gives 2 (12); (c) negative operands & the documented truncation-toward-zero rule (8).
9. **Explanation guidance:** never say "C++ rounds down" — say "integer division *discards the remainder*"; the distinction matters the moment negatives appear. Use money/change contexts (they justify `%` naturally). Keep the DS angle ready: "means and rates are why `/` between ints is a trap" (DS track link).
10. **Demonstration (15):** [DEMO-05](../demonstrations/demo_group2_operators.md) — `precedence_demo.cpp` predict-then-run in blocks; planned error: `(a + b) / 2` average bug → runs silently, wrong answer → first *silent* defect of the course; connect to the contract flags.
11. **Output prediction:** three-stage: `2 + 3 * 4`; `17 / 5 * 5`; `-7 / 2` — escalating; the third is where the documented-behavior note lands.
12. **Case study (15):** **PF-CS-005 The Grading Curve Debate** — which quantities are counts (int) and which are averages (double); the division happens *once*, and its types decide the answer.
13. **Guided coding (20):** pairs write expressions for: average of three ints; last digit of n; minutes→h:mm converter; each pair *predicts* before running — prediction slips collected as the formative record.
14. **Common misconceptions:** formalize [MC-03](../misconception-bank/misconception_bank.md) (integer division) and seed [MC-02](../misconception-bank/misconception_bank.md) (precedence-as-multiplication-first); both get their full treatment here — this is their home lecture.
15. **Debugging activity:** symptom only: "my average prints as a whole number" — pairs diagnose from three candidate lines; the trap: the cast must happen *before* division (bank's corrected version).
16. **Independent practice (20):** T01 arithmetic/precedence items + the division-flavored T04 openers; TAs ask "int or double, and why?" at every declaration.
17. **Exit ticket (5):** (1) `9 / 2` and `9 % 2` — exact outputs. (2) One sentence: why does `(a+b)/2` lie to you when a,b are ints?
18. **Summary (5):** derive the quotient-remainder relationship on the board from the class's own answers.
19. **Support:** concrete-anchors first — coins on the desk for `17/5` before symbols; the bank's practice task is the re-teach.
20. **Extension:** derive why `x % 10` extracts digits (pipeline to L09's digit problems); predict `x % 2` for negative x on paper, verify.
21. **Reflection:** did votes on `-7/2` converge after the documented-rule note? Which pair explanations used the remainder picture vs memorized rules? (The former survive exams.)

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

## L06 · Type Conversions, Compound Assignment, and Mixed-Type Expressions

1. **Lecture/title:** L06 — Type Conversions, Compound Assignment, and Mixed-Type Expressions
2. **Module/week:** Module 3 · Week 3 · Lecture 2 of 2 (quiz-adjacent: announce first quiz for next lecture slot if your calendar puts quiz 1 in week 3's second lecture — see quizzes/README)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_03/lecture_06.md): [lecture_06.md](../../lectures/week_03/lecture_06.md)): predict implicit conversions in mixed expressions and assignments; use `static_cast` deliberately; use compound assignment operators; trace expressions with the state table.
4. **Prerequisite knowledge:** L05 division behavior; L03 types.
5. **Prep checklist:** compile `examples/conversion_demo.cpp` this morning; prepare trace-table handout or template; load PF-CS-021 (Leap Year Interrogation — its bool logic feeds compound/boolean reasoning).
6. **Materials & files:** `examples/conversion_demo.cpp`; case PF-CS-021; trace-table template (METHOD § 5 of DEBUG guide — pointer to it).
7. **Opening question (10):** resolve L03's parked mystery: `char c = 'A'; cout << c;` vs `cout << (int)c;` — the class re-meets conversion as *the answer* to their own week-2 question.
8. **Concept sequence (30):** (a) implicit conversion rules: promoting vs narrowing, where the silent loss happens (12); (b) `static_cast` as the *deliberate* conversion — documentation value (8); (c) compound assignment `+=`, `-=`, `*=`, `/=`, `%=` as the idiom loops will live on (10).
9. **Explanation guidance:** frame narrowing as "the compiler will not stop you from losing data — it assumes you meant it." `static_cast<double>(total)/count` is taught as *self-documenting intent*, with the alternative `(double)total/count` acknowledged but discouraged (easy to misread scope).
10. **Demonstration (15):** [DEMO-06](../demonstrations/demo_group2_operators.md) — `conversion_demo.cpp`; planned error: assign a double to an int *silently* (show the warning under contract flags), then the `int total; total / n;` average bug again — now fixed with the cast, full circle from L05.
11. **Output prediction:** `int x = 7.9;` ; `double d = 3;` ; `x += 0.5;` — three votes, one theme: which direction loses what.
12. **Case study (20 — case-heavy variant):** **PF-CS-021 Leap Year Interrogation** — the classic compound-condition problem; boolean operators + the leap-year rule as an exercise in *stating the rule precisely before coding*.
13. **Guided coding (15):** whole-class trace table of `x += y *= 2` style sequences on paper first — compound ops in traces are the exam skill.
14. **Common misconceptions:** bank: [MC-03](../misconception-bank/misconception_bank.md) deepened (cast-before-divide); new seed: "conversion happens at the assignment, not inside the expression" — demonstrated via `double d = 3 / 4;` vs `3.0 / 4`.
15. **Debugging activity:** symptom: "my loop counter doubles but my total is wrong" — a `total /= count;` inside a loop vs `total = total / count` intended once; trace-table it (first full DEBUG § 5 treatment).
16. **Independent practice (20):** T01 conversion items; DS-track students pointed at `exercises/data-science/` DS-01 (count & proportion — cast placement).
17. **Exit ticket (5):** (1) `double avg = 9 / 4;` — exact value, and the minimal fix. (2) `x *= 2 + 1` — what is it short for, exactly?
18. **Summary (5):** derive: "every expression has a type, computed by the rules; conversions are where intent gets lost."
19. **Support:** the two-line average fix (`static_cast`) as a sticky-note fix pattern; practice task MC-03's in pairs.
20. **Extension:** predict then verify `unsigned` wrapping (demo only, no drills) — deepens "types are promises" from L03; strictly optional.
21. **Reflection:** are compound assignments being traced correctly? (Quiz 1 next slot samples exactly this.) Which students still cast *after* dividing?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 20 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
