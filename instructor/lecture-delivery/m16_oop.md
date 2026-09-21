# Delivery Guide — Module 16 · Introduction to Object-Oriented Programming (Week 16)

**Guides:** L31, L32 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L31 · Classes: Data + Behavior, Constructors, Encapsulation

1. **Lecture/title:** L31 — Classes: Data + Behavior, Constructors, Encapsulation
2. **Module/week:** Module 16 · Week 16 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_16/lecture_31.md): [lecture_31.md](../../lectures/week_16/lecture_31.md)): define a class with private data and public members; write constructors (default + parameterized); explain encapsulation as *invariant protection*; convert L28's struct to a class with behavior.
4. **Prerequisite knowledge:** L28 structs; L26 passing modes; L30 the three-tier input discipline (constructor validation uses it).
5. **Prep checklist:** compile `examples/first_class.cpp` + `examples/struct_to_class.cpp` this morning; prepare the struct→class refactor sequence (the demo's arc); load PF-CS-090; decide the private-data "what could go wrong" examples for your class (bank has two).
6. **Materials & files:** `examples/first_class.cpp`, `examples/struct_to_class.cpp`; case PF-CS-090 Bank Account Invariants; [MC-20](../misconception-bank/misconception_bank.md), [MC-21](../misconception-bank/misconception_bank.md), [MC-22](../misconception-bank/misconception_bank.md) snippets.
7. **Opening question (10):** "L28's `Student` struct: anyone can write `s.marks = 9999`. What *should* happen instead?" — elicit the invariant idea ("rules data must obey") before any class syntax; OOP arrives as *protection*, not ceremony.
8. **Concept sequence (30):** (a) class = struct + private wall + public interface; `private:`/`public:` and why (10); (b) constructors: default + parameterized; member-init lists as the initialization discipline from L03 finally formalized (10); (c) encapsulation as invariant protection: the only writers of the data are methods that *enforce the rules* (10).
9. **Explanation guidance:** teach `private` as *promise enforcement*: the invariant ("balance never negative") can only be guaranteed if only the class's methods touch the balance. Constructor validation = L30's tier-1 discipline applied at birth ("an object that isn't valid at construction is a bug you shipped"). Keep inheritance/polymorphism firmly out of scope — the course's promise is a *grounded start*, not a tour.
10. **Demonstration (15):** [DEMO-32](../demonstrations/demo_group6_memory_files_oop.md) — `struct_to_class.cpp`: the L28 struct refactored live into a class — members go private, behavior moves in, the setter gains the validation the struct never had; planned error: direct member access from `main` after privatising — the *access-control diagnostic* teaches the wall's location.
11. **Output prediction:** the access-violation diagnostic (compile-stage — classify it); the deposit(-50) rejection (invariant enforced at runtime — vote on what *should* happen before running); constructor-chaining behavior with/without a default ctor.
12. **Case study (15):** **PF-CS-090 Bank Account Invariants** — the design debate: which operations exist, what each asserts, what the constructor refuses; the class designs the public interface *before* seeing the solution — the course's design discipline applied to types.
13. **Guided coding (20):** pairs convert their L28 `Book` into a class (`mark_borrowed()`/`mark_returned()` with the available-invariant); TAs check: no public data, validation in ctor, invariant mentioned in a comment per method.
14. **Common misconceptions:** [MC-20](../misconception-bank/misconception_bank.md) (constructors: "just a function named like the class" — the no-return-type rule and the auto-call); [MC-21](../misconception-bank/misconception_bank.md) (access: "private = security" — it's *interface discipline*, not encryption); [MC-22](../misconception-bank/misconception_bank.md) (object creation: "the class is the object" — class = type/blueprint, object = the built thing; the L03 box picture scales: class = box *design*, object = box).
15. **Debugging activity:** symptom: "my class compiles but main can't reach anything" — everything accidentally private; the diagnostic tour names each block's access; fix by *design* (what's interface?), not by flipping everything public.
16. **Independent practice (20):** T12 items (class definition, ctor, invariant method); every method gets a one-line invariant comment.
17. **Exit ticket (5):** (1) What can a constructor *never* have? (2) One sentence: why is `private` data + methods safer than a public struct *in a program you'll extend*?
18. **Summary (5):** derive: "a class is a struct with walls and a doorman — the doorman enforces the rules you wrote in Module 6 designs."
19. **Support:** the struct→class conversion checklist (which members go where, in order); invariant-sentence starters ("after every method call, ___ must still hold").
20. **Extension:** add a *static-like* discussion tease (not syntax): "where would a *count of all accounts* live?" — parks a question for CS2; honest scope statement.
21. **Reflection:** did encapsulation land as *protection* or as *ritual*? (Exit ticket (2) answers tell.) Who wrote constructors without validation? (Lab 16's rubric cares — flag names for the TA briefing.)

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

## L32 · From Structs to Classes, Course Synthesis · **FINAL EXAM**

1. **Lecture/title:** L32 — From Structs to Classes, Course Synthesis · FINAL EXAM
2. **Module/week:** Module 16 · Week 16 · Lecture 2 of 2 — **EXAM DAY** (variant per hub § 3)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_16/lecture_32.md): [lecture_32.md](../../lectures/week_16/lecture_32.md)): consolidate the full arc (types → control → functions → arrays → memory → files → classes) in one synthesis view; sit the final (180-min blueprint; 110 min sat in-slot — see item 8, closed book).
4. **Prerequisite knowledge:** Modules 1–16.
5. **Prep checklist:** final papers staged from `instructor/exams/` (`final_bank.md`, forms A–D, blueprint in `PAPER_ASSEMBLY.md` — Modules 9–16 pool per the corrected coverage note); review guide link posted (`exams/final/review_guide.md`); room/seating; synthesis one-pager (the course's own concept map) ready to project post-exam.
6. **Materials & files:** final exam paper + keys (instructor area); review guide; [DEBUG_GUIDE § 3 tables](../DEBUGGING_GUIDE.md) for the take-up.
7. **Opening question (5 — exam-day variant):** logistics + calm; synthesis one-pager *available* but not reviewed pre-exam (post-exam material).
8. **Exam (110):** sit the final per the blueprint; emphasis Modules 9–16 with cumulative coverage — as documented in `PAPER_ASSEMBLY.md`. The 180-minute blueprint is delivered in-slot via the forms' minimum-per-section selection, with the take-up and synthesis (items 9/15) scheduled as the post-exam session; institutions preferring the full 180-minute sitting run it in a dedicated exam window **[CONFIGURABLE]**.
9. **Post-exam synthesis (if your calendar provides the slot — 0 min in this variant's 120; run as the take-up):** the exam's hardest TRACE/DEBUG items re-derived; the synthesis map built *by the class* ("which module gave us which tool?" — the arrows are drawn by their answers).
10. **Demonstration:** none (exam day).
11. **Output prediction:** embedded in the paper.
12. **Case study:** PF-CS-108 The Capstone Mini-System — *named* as the post-exam extension/summer-bridge path, not run today.
13. **Guided coding:** none.
14. **Common misconceptions:** harvested from the exam for the *next* cohort's instructor — record in your term notes (the package's reflection loop).
15. **Debugging activity:** the take-up (9).
16. **Independent practice:** none.
17. **Exit ticket (5, merged with summary):** one question: "the one topic you'd want a 3-hour workshop on" — feeds the next cohort's lab calendar. Post-exam close: summary and ticket share the final 5 minutes (ticket collected as students leave).
18. **Summary (within item 17's close):** close the arc publicly: Module 1's "cup of tea algorithm" → Module 16's invariant-protected classes — the same discipline, matured. Thank the class; announce feedback channel.
19. **Support:** exam-access arrangements per institutional policy **[CONFIGURABLE]**; grades timeline per institutional policy **[CONFIGURABLE]**.
20. **Extension:** PF-CS-108 + the DS track's full pipeline as the self-study bridge to Data Structures.
21. **Reflection (instructor, post-marking):** item analysis vs the blueprint's outcome mapping; which three items would you replace next term? (Feeds the bank's evolution — log in your fork's changelog per TEACHING_GUIDE § 8.)

| Segment | Min |
|---|---|
| Opening and logistics | 5 |
| Final examination (per blueprint, in-slot sitting) | 110 |
| Exit ticket + summary/preview (post-exam close) | 5 |
| **Total (in-slot teaching time)** | **120** |

*\*The final's authoritative blueprint is 180 minutes · 100 marks (`instructor/exams/PAPER_ASSEMBLY.md`, `exams/final/review_guide.md`); the teaching slot is 2 hours, so this plan seats a 110-minute in-slot sitting (the forms' minimum-per-section selection) and runs the take-up/synthesis as the institution's post-exam session. Where your institution runs the full 180-minute session, it absorbs this slot and the close **[CONFIGURABLE]**. The L16 midterm uses the blueprint's 100-minute paper with a 10-minute post-exam take-up.*
