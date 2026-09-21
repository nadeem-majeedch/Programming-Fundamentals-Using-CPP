# Teaching Guide — Programming Fundamentals Using C++

**Audience:** instructors, teaching assistants, and content authors.
**Student-facing counterpart:** [student/README.md](student/README.md).

---

## 1. Pedagogical stance

1. **Concepts before syntax, syntax before shortcuts.** Every feature is
   introduced with the *problem it solves* before its grammar. Example: loops
   appear as "how do we avoid copy-pasting 100 lines?" before any `for` is shown.
2. **Live coding is the default mode.** Students must watch programs being
   built, broken, and fixed in real time — including failures and compiler
   errors. A lecture without live coding is a reading session; use the notes.
3. **Tracing is the core skill.** From week 4 onward, every lecture includes at
   least one desk-check (state table) exercise; this is what exams assess.
4. **Errors are curriculum.** Common beginner errors (missing `;`, `=` vs `==`,
   integer division, off-by-one, uninitialized variables) are deliberately
   demonstrated, named, and collected in the lecture notes' "Common pitfalls"
   section.
5. **Typed memory pictures from day one.** Variables are introduced with a
   box-and-value diagram; pointers in week 12 extend the same notation rather
   than introducing a new mental model.
6. **Two audiences, one course.** CS students need the machine model (week 12
   pointers, arrays-as-memory); DS students need data pipelines (week 13 files,
   week 14 STL). The schedule keeps both tracks honest without splitting.

## 2. Course-load calibration

This is a **first course for students who have never programmed**. Plan for:

- 4–6 h/week of out-of-class practice (assignments + reading).
- The first three weeks are the danger zone for attrition: toolchain problems
  and "imposter syndrome" dominate. Mitigations:
  - Lab 1 is graded generously (participation-weighted).
  - The [student/](student/README.md) kit has a 30-minute "hello world"
    guarantee path for each OS.
  - Announce office hours *in lecture 01* and again in week 3.

## 3. Lecture delivery pattern (2-hour slot)

| Minutes | Segment |
|---|---|
| 0–10 | Recall: one trace-table or predict-the-output question from last lecture |
| 10–60 | New concept A: motivation → live coding → pitfalls |
| 60–65 | Break (non-negotiable; retention collapses after ~60 min) |
| 65–105 | New concept B (or the applied second half of concept A) |
| 105–120 | In-class exercise (from `exercises/in_class/`) + exit question |

Exit questions feed the next lecture's recall segment — a two-minute loop that
surfaces misconceptions early.

## 4. Using the repository materials

- **lectures/** — one folder per week; notes are written to be projected
  (headings are slide-sized). Convert to decks as you prefer; sources for the
  canonical decks live in `instructor/slide_sources.md` (authored with the
  lecture batches).
- **examples/** — every program compiles standalone with
  `g++ -std=c++17 -Wall -Wextra -pedantic`. Prefer running them live over
  showing pre-pasted output.
- **exercises/** — statements are public; `solutions/` subfolders are
  instructor-side until after the due date (see
  [instructor/ACCESS_CONTROL.md](instructor/ACCESS_CONTROL.md)).
- **quizzes/, exams/** — student copies contain questions only; keys are in
  the matching `instructor/` folders.
- **labs/** — manuals include instructor checklists (what to watch for while
  circulating) under `instructor_notes/` inside each lab folder.

## 5. TA guidelines (do/don't)

| Do | Don't |
|---|---|
| Ask "what have you tried? what did you expect?" | Take the keyboard and type the fix |
| Point to the diagnostic line and teach reading it | Translate errors into silent rewrites |
| Sketch the memory/state diagram | Give the assignment's final code |
| Encourage a debugging log | Say "this is easy" — ever |

## 6. Assessment construction

- Every graded item must cite the outcomes it evidences
  ([LEARNING_OUTCOMES.md](LEARNING_OUTCOMES.md) codes) in its header.
- Exam blueprints: [exams/README.md](exams/README.md) (midterm/final maps to
  outcomes with point allocations).
- Rubric pattern for code (0/1/2 per row): works correctly · style guide
  ([docs/CODE_STYLE.md](docs/CODE_STYLE.md)) · testing evidence · explanation
  in viva.
- Quiz cadence: one 15-minute module quiz per week in week *n*'s second
  lecture (16 total, 10 marks each; lowest two dropped — 15 % of the grade),
  announced a week ahead; predict-the-output and short code writing.

## 7. Calendar variants

- **14-week calendar:** merge week 05 into 04 (drop nested-loop drills to lab
  homework) and week 15 into 14 (recursion becomes a lecture-length demo +
  optional exercise set).
- **3-credit, no-lab variant:** convert the six labs into assignment sections
  and keep only Lab 1 (toolchain) in class.
- **Quarter (10-week) variant:** cut week 14 (classes) and week 15 recursion
  stays; pointers become one lecture instead of two. Document your variant in
  your fork's `docs/CHANGELOG.md`.

## 8. Adapting the course

If you fork/adopt this course:

1. Keep the outcome codes (`PF-…`) so assessment mapping remains traceable.
2. Record local policy changes (grading, integrity, late policy) in
   [COURSE_OVERVIEW.md](COURSE_OVERVIEW.md) § 4 rather than editing
   assessments silently.
3. Maintain the audience split: never move instructor-only material into
   student-facing folders; see [instructor/ACCESS_CONTROL.md](instructor/ACCESS_CONTROL.md).
4. Log changes in [docs/CHANGELOG.md](docs/CHANGELOG.md).

## 9. First-time instructor checklist

- [ ] Read [COURSE_OVERVIEW.md](COURSE_OVERVIEW.md) and this guide end-to-end.
- [ ] Build every `examples/` file on the machine you will teach from.
- [ ] Walk through the [student/](student/README.md) install guide on each OS
      your students use; fix anything stale.
- [ ] Review `instructor/PACING_GUIDE.md` and mark your own cut/extend
      decisions per lecture.
- [ ] Stage the private instructor mirror before week 1
      (see [instructor/ACCESS_CONTROL.md](instructor/ACCESS_CONTROL.md)).
- [ ] Schedule labs, quizzes, and the midterm on the institutional calendar
      per [COURSE_SCHEDULE.md](COURSE_SCHEDULE.md) § Scheduling notes.
