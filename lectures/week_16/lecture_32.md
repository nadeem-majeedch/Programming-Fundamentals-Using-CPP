# L32 · From Structs to Classes, Course Synthesis · **FINAL EXAM**

**Module 16 — Introduction to Object-Oriented Programming · Week 16 · Lecture 32 of 32 · 120 minutes**
**Outcomes:** CLO-1–CLO-8 · PF-16.3, PF-16.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **FINAL EXAM (120 min) · Capstone demo week**

## Learning objectives

1. Evolve a struct-based records program into a class-based design,
   defending the interface (what becomes private, which functions become
   members, where validation lives) — the capstone's final refinement
   (PF-16.3).
2. Synthesize Modules 1–16 outcomes in an integrated exam: trace, predict,
   write, debug, and design across the full semester map (PF-16.4).
3. Present the capstone project with a code walk-through answering
   line-by-line viva questions (PF-16.4, PF-G3).

## Prerequisites

All Modules 1–15; L31 (classes); capstone milestone (week 14) complete.

## Concept sequence (hour 1 — synthesis teaching)

1. The struct→class refactor checklist (worked on the roster program)
2. Semester map: 16 modules → 8 CLOs, one slide of truth
3. Exam strategy per question family
4. Capstone demo protocol & viva rubric
5. Where to go next: OOP course, data structures, DS pipeline courses

## Teaching topics (detailed)

- **Refactor checklist (applied live to L28's roster):** (1) state the
  invariant; (2) privatize the data; (3) promote the record functions to
  members (`print`, `promote` → member functions; free `find_by_id` stays
  free or becomes static-ish — discuss); (4) constructor validates at
  birth; (5) `const`-mark the readers; result diff shown — *same
  algorithms (M9–M12), new guard rails (L30–L31)*; the semester's arc in
  one refactor.
- **Semester synthesis map:** pipeline (M1) → types (M2–3) → control
  (M4–5) → design (M6) → abstraction (M7–8) → collections (M9–12) →
  machine (M13–14) → robustness (M15) → objects (M16) — each node named
  with its CLO and its exam question family.
- **Exam strategy:** predict-output → trace, don't run; trace-table → fill
  every variable column; write-a-function → signature first, edge cases
  second; find-the-bug → hypotheses ranked by L16 loop; design → IPO +
  invariants.
- **Capstone viva protocol:** 5-minute demo, 5-minute code walk, PF-G3
  line-by-line explanation; rubric per
  [projects/README.md](../../projects/README.md); demos scheduled this week
  (separate session per [COURSE_SCHEDULE.md](../../COURSE_SCHEDULE.md)).
- **Forward map:** OOP course (inheritance/polymorphism from L31's bridge
  slide), data structures (vector→STL containers), DS pipeline (M15's
  skip-and-report → real data cleaning).

## C++ examples required

| File | Role |
|---|---|
| `struct_to_class.cpp` ✅ | L28 roster as struct version vs L31-style class version, refactor checklist annotated inline |
| (live) final review set | 12 integrated questions covering all 8 CLOs (mirrors [exams/final/review_guide.md](../../exams/final/review_guide.md)) |

## Common student misconceptions

- "The final is about Module 16 only." (Cumulative with weeks 9–16 emphasis
  per [exams/README.md](../../exams/README.md); the synthesis map exists to
  prevent cramming-on-the-last-module.)
- "Refactoring to a class means rewriting the algorithms." (The algorithms
  survive; only the *ownership of data* changes — the demo shows 80% code
  reuse.)
- "The viva is a formality." (PF-G3: students must explain their own code —
  authored-understanding is the integrity check.)

## Conceptual explanation (beginner-first)

Hour 1 is the whole course as one map. Sixteen modules in one arc:
**values and control** (M1–M5: data, decisions, repetition),
**design** (M6–M8: problem-solving, functions, passing modes),
**data structures and algorithms** (M9–M12: arrays, strings, search,
sort), **the machine** (M13–M14: pointers, heap, structs), and
**integration** (M15–M16: files, robustness, classes). Every module
supplied a *pattern* (accumulate, find-first, two-pointer, invariant,
RAII, encapsulation) — the synthesis quiz is a rapid-fire tour of
exactly those patterns.

The struct→class refactor shows the arc's payoff concretely: the L28
roster (records + free functions) becomes a class whose data protects
itself — same algorithms, changed *ownership of data*, and a compile
error where corruption used to live. That single transformation is
the difference the course has been building toward since week 1: you
no longer only write correct programs; you design types that make
incorrect programs refuse to exist.

Hour 2 is the final exam (cumulative, weeks 9–16 emphasis per the
blueprint) — or, in the separate-exam-period variant, the full
synthesis lecture plus capstone demonstrations and vivas.

## Terminology and definitions

| Term | Definition |
|---|---|
| Synthesis map | The five-stage arc (values→control→design→data→machine→integration) |
| Pattern inventory | The named skeletons: ACCUMULATE, COUNT-IF, FIND-FIRST, two-pointer, state machine, invariant, RAII, encapsulation |
| Refactor checklist | The ordered struct→class steps (define private data → constructors → validated setters → const getters → move free functions) |
| Ownership of data | Who guards the invariant: free functions (struct) vs the type itself (class) |
| Viva | The oral defense of one's own capstone code — authored-understanding check |
| Demo script | The 5-minute capstone walkthrough: run, explain, answer |
| Cumulative emphasis | Weeks 9–16 weighted per the final blueprint |
| Course-end reflection | Self-assessment against chosen CLOs with submission evidence |

## Syntax and C++ examples

The refactor checklist, applied live (per `examples/struct_to_class.cpp`):

```cpp
// STEP 0 — the struct version (M28): data public, free functions guard
struct StudentR { std::string name; double gpa; };   // anyone can corrupt

// STEP 1 — privatize the data
class StudentC { public: /* interface next */ private: std::string name_; double gpa_; };

// STEP 2 — constructor establishes the invariant at birth
StudentC(const std::string& name, double gpa) { set_gpa(gpa); /* name_ init */ }

// STEP 3 — validated setters are the only write paths
void set_gpa(double g) { gpa_ = (g >= 0.0 && g <= 4.0) ? g : gpa_; }

// STEP 4 — const getters report safely
double get_gpa() const { return gpa_; }

// STEP 5 — free functions become members (or stay free, taking const&)
void print() const { /* was: print_student(const StudentR&) */ }
```

Each step compiles and runs — the checklist is incremental by design,
so no step leaves the program broken.

## Line-by-line code explanation

`examples/struct_to_class.cpp`:

1. Both versions exist side by side with the *same* `main` logic
   body — the diff is ownership, not algorithms: roughly 80% of the
   code survives untouched (the demo prints the identical analytics
   from both).
2. The corruption line works on the struct (silently) and fails to
   compile on the class — the two outcomes are printed as labeled
   evidence in the file's comments.
3. The checklist is annotated inline at each step, matching the
   terminology table — the file doubles as the review handout.
4. The final review set (12 integrated questions, live) mirrors
   `exams/final/review_guide.md` — one drill block per module plus integrative
   ones, each tagged with its CLO.

## Output prediction questions (with answers)

1. Same corruption write, struct vs class — ? — Struct: accepted,
   invariant broken. Class: compile error — corruption can't exist.
2. Refactoring to a class rewrites what fraction of the algorithms?
   — None: only data ownership and access paths change.
3. Which modules own each pattern: two-pointer (M11), invariant
   (M16), RAII (M14/15), FIND-FIRST (M9/12)? — Rapid-fire map.
4. Why does the class version need no validation at call sites? —
   Validation lives in the setter/constructor: the *only* write paths.
5. Which weeks does the final emphasize? — Cumulative with weeks 9–16
   emphasis, per the blueprint.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Cramming module 16 only | Cumulative items collapse | Synthesis map + review set coverage |
| Refactoring all at once | Half-class, half-struct chaos | The five-step checklist, compiling each step |
| Setters that skip validation "temporarily" | The invariant hole reappears | Every write path validates, always |
| Demo scripts that only run | Viva exposes unexplained code | Script = run + explain + answer |
| Free functions left taking public data | Bypass path around encapsulation | Move in or take `const&` of the *interface* |

## Classroom demonstrations

1. **The 80% refactor:** delete lines from the struct version as they
   are replaced; the surviving-code counter tells the reuse story
   better than claims.
2. **Pattern rapid-fire:** 16 one-line snippets — the class names the
   pattern and module in under a minute each; the CLO map builds
   itself on the board.
3. **The corruption crossfade:** run struct-corruption (silent),
   class-corruption (compile error) back to back — the course's thesis
   in two compile runs.

## Guided student activities
**Hour 1:** struct→class live refactor + rapid-fire synthesis quiz (16
questions, one per module, teams shout the CLO). **Hour 2: FINAL EXAM**
(120 min — institutions using a separate exam period run the full synthesis
lecture in this slot; both variants in
[COURSE_SCHEDULE.md](../../COURSE_SCHEDULE.md) § Scheduling notes).

## Practice problems
- Complete the refactor checklist on your own capstone (if time-scope
  allows) or on the provided roster.
- Final review set in [exams/final/review_guide.md](../../exams/final/review_guide.md) —
  24 questions mapped to CLOs.
- Prepare the demo script (5 min) + anticipate 5 viva questions on your own
  code.

## Practice problems

- Complete the refactor checklist on your own capstone (if time-scope
  allows) or on the provided roster.
- Final review set in [exams/final/review_guide.md](../../exams/final/review_guide.md) —
  24 questions mapped to CLOs.
- Prepare the demo script (5 min) + anticipate 5 viva questions on your own
  code.

## Summary

Sixteen modules, one arc: values → control → design → data → machine
→ integration; each contributed named patterns that the synthesis
review strings together. The struct→class checklist compresses the
course's destination into five compiling steps — the type now guards
its own invariant. Next: the exam (and after it, the next course).

## Exit ticket / formative assessment

*(Course-end reflection, submitted with the exam:)*
1. Name the one module that changed how you think about programs, and why.
2. Self-assess against two CLOs of your choice — evidence from your own
   submissions.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Struct→class refactor + synthesis map | 40 |
| Exam strategy + viva protocol | 15 |
| **FINAL EXAM** | 120* |

*When the exam runs in this slot the total exceeds 2 hours; institutions
therefore either (a) shorten hour 1 to 60 min and run the exam in a separate
period, or (b) run the synthesis lecture earlier in week 16's first slot —
both supported by [COURSE_SCHEDULE.md](../../COURSE_SCHEDULE.md).
