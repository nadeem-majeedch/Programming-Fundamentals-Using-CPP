# Delivery Guide — Module 1 · Introduction to Programming and C++ (Week 1)

**Guides:** L01, L02 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats referenced:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L01 · What Is a Program? Computers, Algorithms, and the C++ Toolchain

1. **Lecture/title:** L01 — What Is a Program? Computers, Algorithms, and the C++ Toolchain
2. **Module/week:** Module 1 · Week 1 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_01/lecture_01.md)): define algorithm vs program; name the translation stages source → executable; run a first program; state the course compile contract.
4. **Prerequisite knowledge:** none — this is the course entry point.
5. **Prep checklist:** compile `examples/hello_world.cpp` on the teaching machine **this morning**; project tier-1 case; test projector + terminal font size; print/load exit-ticket slips (or open the form); stage the toolchain slide for the students' OS mix.
6. **Materials & files:** `examples/hello_world.cpp`; case `case-studies/by_tier/tier1_beginner.md` (PF-CS-001); student kit `student/README.md` (install path).
7. **Opening question (10 min):** "Write down, in numbered steps, exactly how you make a cup of tea — then swap with a neighbour and *execute* their steps literally." Debrief: ambiguity is a *specification* problem; computers execute literally.
8. **Concept sequence (30):** (a) algorithm → program → machine (10); (b) the four translation stages with the toolchain picture (12); (c) the course contract + what "compiles" will mean all semester (8).
9. **Explanation guidance:** avoid CPU architecture depth; the machine model is "a very fast, very literal instruction-follower." Say *why* C++ is compiled (speed + control) vs interpreted, one sentence, no language war.
10. **Demonstration (15):** [DEMO-01](../demonstrations/demo_group1_basics.md) — type `hello_world.cpp` live from an empty file; compile with the contract flags; run. Planned error: delete the `;` → first compile error the class has ever seen; classify it together (compile-stage).
11. **Output prediction:** before the first run: "exact output of this 3-line program?" (trivial by design — the *win* is the ritual; predict-then-run starts today).
12. **Case study (15):** **PF-CS-001 The Vending Machine** — first exposure to encoding everyday rules as precise steps; run the full 5-minute protocol (METHOD § 3).
13. **Guided coding (20):** whole class edits `hello_world.cpp` together: change the text (predict first), add a second line, break it on purpose (remove `#include`) → meet the "unknown type" error family.
14. **Common misconceptions:** none banked yet — plant the vocabulary: "the compiler is picky on purpose"; errors are information, not failure (method: [../DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) § 4).
15. **Debugging activity:** the demo's missing-`;` error, walked with the 3-step diagnostic ritual (first error only → anchor word → restate as sentence).
16. **Independent practice (20):** `exercises/in_class/` opening set; every student must achieve one successful edit-compile-run cycle before leaving. TAs circulate with the "hello world 30-minute guarantee" path from the student kit.
17. **Exit ticket (5):** (1) List the four stages from source to running program, in order. (2) One question you still have about getting C++ running on *your* laptop.
18. **Summary (5):** derive by questioning: "program = algorithm + a language strict enough that a machine can execute it."
19. **Support:** toolchain triage is the real risk — TAs run the student-kit checklist per OS; nobody leaves with a broken toolchain (office-hours announcement repeats here).
20. **Extension:** students who finish early compile the same file with `-std=c++17` vs without flags and note any diagnostic difference; first taste of the contract.
21. **Reflection:** How many students left with a working toolchain? Which step of the toolchain picture drew blank faces? (Feeds L02's opening.)

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

## L02 · Anatomy of a C++ Program: `main`, Statements, Compilation, and the Three Error Classes

1. **Lecture/title:** L02 — Anatomy of a C++ Program
2. **Module/week:** Module 1 · Week 1 · Lecture 2 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_01/lecture_02.md)): identify every line's role in a minimal program (`#include`, `main`, statements, `return 0`); classify errors as compile / link / runtime; write and run a first original program.
4. **Prerequisite knowledge:** L01 toolchain picture; a working compiler (Lab 1 completed).
5. **Prep checklist:** compile `examples/hello_world.cpp` + `examples/io_age_check.cpp` this morning; prepare the three-error-class demo snippets as *edit-in-place* changes (never pre-broken files); load PF-CS-002.
6. **Materials & files:** `examples/hello_world.cpp`, `examples/io_age_check.cpp`; case PF-CS-002; lab-1 bug-hunt file `labs/lab_manuals/lab_01/starter_code/three_stages.cpp` (only if revisiting Lab 1).
7. **Opening question (10):** built from L01 tickets — typically "what was your install question?" + recall: "which stage turns `cout << 2+2` into `4` — and when?"
8. **Concept sequence (30):** (a) line-by-line anatomy of a minimal program — every token earns its place (12); (b) the **three error classes** with one physical example each (12); (c) statements vs expressions vs the semicolon (6).
9. **Explanation guidance:** anatomy first as *shape* (`main` is where the story starts; one statement per line; braces are the paragraph marks). The three classes get symptom-first framing: "what does each failure *look like*?"
10. **Demonstration (15):** [DEMO-02](../demonstrations/demo_group1_basics.md) — the translation pipeline live: one program, three planted failures (compile, link, runtime), one classification table on the board; planned errors are edit-in-place — the class meets every error class they will meet all semester, in one hour.
11. **Output prediction:** the `cout << "2+2 = " << 2+2` line — votes will split on `4` vs `2+2`; resolve by tracing what the compiler does to each `<<` operand. (Plants MC-03's neighbourhood early, without naming it.)
12. **Case study (15):** **PF-CS-002 Three-Cup Order** — sequencing precision; students encode a physical rearrangement as ordered steps.
13. **Guided coding (20):** pairs produce a 5-line program printing their name and an arithmetic result; TAs enforce contract flags; each pair introduces one error *for another pair* to classify — first bug-swap.
14. **Common misconceptions:** introduce [MC-00](../misconception-bank/misconception_bank.md) context (semicolon = statement terminator, not line end) — light touch; the bank proper starts next week.
15. **Debugging activity:** classify-then-fix relay: three snippets projected in turn (compile, link, runtime), teams name the class *before* any fix is shown. Symptom-first discipline begins (DEBUG § 6).
16. **Independent practice (20):** `exercises/in_class/` anatomy + error-classification set; early finishers attempt the Lab-1 bug hunt `three_stages.cpp` preview.
17. **Exit ticket (5):** (1) Classify: "`undeclared identifier: cout` — which error class, and what's the first thing to check?" (2) What does `return 0` hand back to whom?
18. **Summary (5):** re-derive the three error classes by asking for each one's *symptom* first.
19. **Support:** students still without a working toolchain get routed to office hours *today* — week-1 attrition is toolchain attrition (TEACHING_GUIDE § 2).
20. **Extension:** read the Lab-1 `three_stages.cpp` and predict (not fix) which line triggers which stage's failure.
21. **Reflection:** can every student name the three classes by symptom? Who has not yet typed at all? (Names → TA watchlist for Lab 1.)

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
