# exercises/ — The Exercise Bank

**152 unique programming exercises** spanning the full course, from first
variables to classes. Every exercise has a unique ID (`PF-E-NNN`), a labeled
difficulty, prerequisites, full I/O specification, hints, and the lecture it
supports. Exercises train the outcomes in
[../LEARNING_OUTCOMES.md](../LEARNING_OUTCOMES.md); each exercise cites its
outcome codes.

## Organization

```
exercises/
├── README.md                      ← this file: bank index + policies
├── by_topic/                      ← the bank itself, 12 topic files
│   ├── T01_variables_calculations.md
│   ├── T02_conditions.md
│   ├── T03_loops.md
│   ├── T04_number_problems.md
│   ├── T05_functions.md
│   ├── T06_arrays.md
│   ├── T07_strings.md
│   ├── T08_searching_sorting.md
│   ├── T09_pointers_references.md
│   ├── T10_structures.md
│   ├── T11_file_handling.md
│   └── T12_classes_objects.md
├── data-science/                  ← BS Data Science track: PF-DS-01…18 + datasets
├── in_class/                      ← short lecture-slot drills (authored per week)
│   └── solutions/                 ← instructor-side until published after class
└── homework/                      ← weekly practice sets (authored per week)
    └── solutions/                 ← published after the related due date
```

The `by_topic/` bank is the **master collection**: it is how an instructor
finds practice for a specific skill. The `in_class/` and `homework/`
directories are the **delivery layer**: per-week selections drawn from the
bank, authored with the week batches
([../docs/CONTENT_ROADMAP.md](../docs/CONTENT_ROADMAP.md) § 3).

## Difficulty ladder

| Level | Meaning | Expectation |
|---|---|---|
| 🟢 Beginner | One new concept, direct application | Finish in ~5 min |
| 🔵 Foundational | Concept + one twist (a second input, a boundary) | ~10 min |
| 🟠 Intermediate | Combine 2 concepts or require design judgment | ~20 min |
| 🔴 Advanced Introductory | Small program with structure + edge cases | ~30–45 min |

Every topic file runs the ladder in order — difficulty progression is
inside each topic *and* across the course (topics map to the 16-module
calendar, so later topics inherently carry higher floors).

## Exercise record format

Every exercise is a complete record:

```markdown
### PF-E-013 · Title
**Difficulty:** Intermediate · **Lecture:** L09 · **Outcomes:** PF-5.2, PF-5.3
**Prerequisites:** E-007, L05
**Problem:** …full statement…
**Input:** … / **Output:** … / **Constraints:** …
**Sample:** input → output
**Hints:** nudge 1 · nudge 2
```

## Solution policy — IMPORTANT

Complete C++ solutions live **only** under
[`instructor/exercise_solutions/`](../instructor/exercise_solutions/README.md)
(instructor-only per [../instructor/ACCESS_CONTROL.md](../instructor/ACCESS_CONTROL.md)).
Student-facing files (`by_topic/`, `in_class/`, `homework/`) contain the
exercise records **without solution code** — at most graduated hints.
Solutions are numbered to match exercise IDs (`PF-E-013.cpp` + a README
explaining the reasoning).

## Authoring rules

- IDs are unique across the bank and never reused
  (`tools/check_exercises.py` validates).
- No trick questions; no unexplained advanced features beyond the
  lecture that introduces them (the *Lecture* field is a hard gate).
- Genuine distinctness: two exercises may share a topic but must differ
  in task, algorithm, or edge-case focus — near-duplicates fail
  validation ([../docs/TEACHING_VALIDATION.md](../docs/TEACHING_VALIDATION.md)).
- Every problem states inputs, outputs, constraints, and at least one
  sample I/O pair (where meaningful).
- [../docs/CODE_STYLE.md](../docs/CODE_STYLE.md) governs all solution code.
