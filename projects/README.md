# projects/ — Progressive Mini-Project Ladder

Five programming mini-projects of increasing complexity, each mapped to the
course's module progression. Projects **P1–P4 are ungraded skills ladders**
(recommended as the matching modules complete; instructors may grade them as
homework via the assignment rubrics); **P5 is the graded course project** —
the syllabus's 10 % component across Weeks 14–16, unchanged. Each project
folder contains one complete student specification: `project.md` with all
twelve required sections (problem, objectives, functional & non-functional
requirements, data structures, UI design, validation, testing plan,
milestones, extensions, rubric, instructions).

## The ladder

| # | Folder | Title | Modules | New skills vs previous |
|---|---|---|---|---|
| 1 | [project-01/](project-01/project.md) | Student Grade Calculator | M1–M8 | functions, decisions, loops — no arrays yet; weights & letter mapping |
| 2 | [project-02/](project-02/project.md) | Expense Tracking System | M9–M12 | arrays as collections, parallel arrays → sorting, string categories, reports |
| 3 | [project-03/](project-03/project.md) | Library Management System | M13–M15 | structs, `std::vector`, references, file load/save with skip-and-report |
| 4 | [project-04/](project-04/project.md) | Student Record Management System | M14–M16 | a class with a stated invariant, guarded mutators, file round-trip |
| 5 | [project-05/](project-05/project.md) | Integrated C++ Management Application | M1–M16 | synthesis: menus + records + search + files + class in one coherent program |

**Progression discipline.** Each project is implementable *using only the
modules listed* — P1 needs no arrays; P2 uses no files; P3 introduces structs
and file I/O; P4 is where the first class with an invariant appears; P5 asks
for everything at small scale. Extensions marked ⚙ in each spec go one step
beyond the listed modules and are optional.

## Scope, distinctness, and overlap policy

- P1–P4 are **deliberately distinct domains** (grades / money / library /
  people-records) and **distinct skill bands** — a student cannot submit P2
  work for P3: P3 requires persistence P2 forbids.
- P5 is the capstone synthesis and subsumes earlier bands; the graded
  demonstration rubric applies to it alone.
- The DS track's station-report capstone (PF-DS-18) and the old single-project
  menu are superseded for the main track: DS sections may still submit
  PF-DS-18 as their P5 equivalent with instructor approval.

## Grading (preserved from the course plan)

P5 is worth **10 %** of the course grade (proposal Week 14 → checkpoint
Week 15 → final + demonstration Week 16), evaluated out of 100 points with
the shared rubric
[instructor/assessment-rubrics/project.md](../instructor/assessment-rubrics/project.md)
(correctness 30 · quality 25 · testing 15 · explanation 15 · process 10 ·
scope 5). P1–P4, when graded, use the assignment weights (correctness 30 +
postmortem 10). **Reference implementations and per-project grading keys are
instructor-only** at `../instructor/projects/` — never distributed with the
specs.

## Integrity

P1–P3 individual; P4–P5 individual by default, pair work with a stated split
and a live "explain any line" demonstration allowed. Tooling/AI use follows
the syllabus policy — understanding is evidenced through the explanation
rubric and the demonstration.
