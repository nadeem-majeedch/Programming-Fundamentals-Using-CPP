# Delivery Guide — Module 6 · Problem-Solving and Algorithm Design (Week 6)

**Guides:** L11, L12 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L11 · From Problem to Algorithm: IPO Charts, Decomposition, Pseudocode, Flowcharts

1. **Lecture/title:** L11 — From Problem to Algorithm: IPO Charts, Decomposition, Pseudocode, Flowcharts
2. **Module/week:** Module 6 · Week 6 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_06/lecture_11.md): [lecture_11.md](../../lectures/week_06/lecture_11.md)): build an IPO chart for a stated problem; decompose a problem into ordered subproblems; express the design in pseudocode and as a flowchart; choose a loop pattern before coding.
4. **Prerequisite knowledge:** L07–L10: the decision/loop vocabulary that designs are *made of*.
5. **Prep checklist:** compile nothing new — today is design-first, but stage `examples/functions_refactor.cpp` for a design-to-code tease; load PF-CS-009 + PF-CS-013; print IPO templates (or project the grid).
6. **Materials & files:** IPO chart template (board); case PF-CS-009 Coin Split for Pocket Money + PF-CS-013 The Cashier's Change Maker; `exercises/in_class/` design set.
7. **Opening question (10):** "You already know loops, decisions, input, output. What is *left* before you can build anything real?" — elicit: a *plan*. Today's contract: no compiler until the plan exists.
8. **Concept sequence (30):** (a) IPO charts: Input → Process → Output as the first question set ("what comes in? what goes out? what transforms?") (10); (b) decomposition: big problem → ordered subproblems; top-down sketching (10); (c) pseudocode conventions + flowchart shapes, and when each earns its ink (10).
9. **Explanation guidance:** enforce the order *IPO → decomposition → pseudocode → code* on every worked example — the deliverable today is the *discipline*, not any artifact. Keep pseudocode at three verbs-per-line max; flowcharts only for branch-heavy logic. Anti-pattern to name: "code first, design never" — show its cost via the buggy refactor tease.
10. **Demonstration (15):** [DEMO-11](../demonstrations/demo_group3_loops_functions.md) — design-first walkthrough of the change-maker: IPO on the board → decomposition → pseudocode → *then* 10 lines of C++ (the functions-refactor program, built in its planned order); the demo's lesson is the sequence, with the planned error being a *design* flaw (skipped validation step) caught at desk-check, not compile.
11. **Output prediction:** skip (design day) — replaced by *design prediction*: "given this IPO, which loop pattern implements the Process?" — pattern-name fluency from L10 is the check.
12. **Case study (20 — case-heavy variant):** **PF-CS-013 The Cashier's Change Maker** — greedy change as a decomposition exercise; the 5-minute protocol runs long because the approach debate *is* the curriculum (largest-first vs all-denominations; iteration vs repetition of steps).
13. **Guided coding (15):** pairs take PF-CS-009 (Coin Split) from problem → IPO → pseudocode → *then* code it; TAs inspect pseudocode *before* compiler use and ask "which subproblem is this function going to be?" (foreshadows L13).
14. **Common misconceptions:** the course's first *process* misconception: conflating "I can't write the code" with "I don't have the plan" — addressed by making pseudocode a deliverable. No bank ID; documented here.
15. **Debugging activity:** desk-check the demo's flawed design: trace the missing-validation path with a zero/negative input and *watch the design fail on paper* — cheapest debugging there is (DEBUG § 5 applied to designs).
16. **Independent practice (20):** design-only items from `exercises/in_class/` (IPO + pseudocode for 2 of 3 problems); early finishers code one.
17. **Exit ticket (5):** (1) Produce the IPO chart for "compute a bill's average line cost." (2) What is the first subproblem of the change maker?
18. **Summary (5):** derive: "the compiler only checks syntax; the plan is where correctness is decided."
19. **Support:** fill-in-the-blanks IPO template; sentence-starter pseudocode ("READ …", "WHILE … ", "IF … THEN …"); pair designers with coders.
20. **Extension:** express the same design as a flowchart *and* pseudocode, then argue which communicated better to a partner.
21. **Reflection:** did students reach for the compiler before the plan? Count. That habit is Module 7's target (functions as planned decomposition, not afterthought).

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

---

## L12 · Desk-Checking, Trace Tables, and Test-Case Design

1. **Lecture/title:** L12 — Desk-Checking, Trace Tables, and Test-Case Design
2. **Module/week:** Module 6 · Week 6 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 3)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_06/lecture_12.md): [lecture_12.md](../../lectures/week_06/lecture_12.md)): construct a trace table for a program segment; design boundary and representative test cases from a specification; execute a desk-check to locate a logic error; connect test design to the exam's TRACE/DEBUG items.
4. **Prerequisite knowledge:** L09–L10 loop tracing; L11 process discipline.
5. **Prep checklist:** quiz 3 staged; prepare the buggy snippet (uninitialized accumulator + off-by-one combo) in edit-in-place form; print trace-table templates; load PF-CS-005 (revisit as a *test-design* problem).
6. **Materials & files:** trace-table templates; buggy snippet (bank: [MC-07](../misconception-bank/misconception_bank.md) + [MC-10](../misconception-bank/misconception_bank.md) combined); case PF-CS-005; quiz 3 + key.
7. **Opening question (10):** project Monday's change-maker *code* (not the design) with one planted defect: "the code matches the pseudocode — so why is the total wrong?" The answer (a typo the pseudocode review would have caught) opens the lecture's claim: tracing is how code gets audited.
8. **Concept sequence (30):** (a) trace-table mechanics: columns, one-row-per-execution, boundary-iterations-first (10); (b) test-case design: boundary analysis + representative cases from the spec (10); (c) connecting to exams: how TRACE items are marked (10).
9. **Explanation guidance:** trace tables must be *slow* today — narrate one full table yourself, one row per statement execution, no skipping. Boundary analysis taught as: for every range in the spec, test the two edges and one representative; for every condition, test both sides. The spec-first framing ("tests come from the *specification*, not the code") is the transferable idea.
10. **Demonstration (15):** [misconception-bank MC-07+MC-10 combined snippet](../misconception-bank/misconception_bank.md) — the buggy snippet desk-checked live: table fills, the off-by-one row exposes the bug *before any compile*; planned error is the entire demo. Then test-design application: class proposes cases for the grade ladder from L07 (59/60/100/101 reappear by design).
11. **Output prediction:** replaced by *bug prediction*: after 6 trace rows, class votes on the defective line before the table confirms — the reveal is the method's proof.
12. **Case study (15):** **PF-CS-005 The Grading Curve Debate** revisited as a test-design problem: what inputs would make two competing solutions disagree? (Type choices + boundaries — synthesizes Modules 3–5.)
13. **Guided coding (15 — quiz-day trim):** pairs desk-check each other's PF-CS-009 pseudocode from L11 (swap artifacts) — cross-checking designs is the practice; then 3 test cases for the sentinel mean.
14. **Common misconceptions:** tracing-as-overskipping ("I did the obvious rows in my head") — named as the failure mode; boundary-blindness ([MC-07](../misconception-bank/misconception_bank.md)'s exam face).
15. **Debugging activity:** the demo IS it; early finishers desk-check the [MC-07](../misconception-bank/misconception_bank.md) snippet and predict the wrong index before running.
16. **Independent practice (10 — quiz-day trim):** one full trace table + one test-case set from `exercises/in_class/`.
17. **Quiz 3 (15):** per cadence.
18. **Exit ticket (5):** (1) A loop `for (i=0; i<n; ++i)` — which iterations does your table *never* skip? (2) Spec: "valid mark: 0–100 inclusive" — write the boundary test set.
19. **Summary (5):** derive: "tests come from the spec; traces come from the code; meetings between the two are where bugs die."
20. **Support:** pre-filled first row of the trace table for students who stall at setup; pair roles: narrator/scribe (swap halfway).
21. **Reflection:** quiz 3 + the trace tables → who still traces by pattern-matching? (Names to TA watchlist before midterm — L16's review targets them.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 3 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
