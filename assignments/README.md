# assignments/ — Programming Assignments

Eight graded programming assignments (one every ~2 weeks), 40 marks each,
drop-lowest-1. Every folder: `assignment.md` (student spec) +
`instructor_key.md` (restricted; contains reference solutions — compiled &
executed under the course contract — hidden-case classes, and common defects).

| # | Folder | Topic | Modules | Due |
|---|---|---|---|---|
| 1 | `assignment_01` | Course Record Card — variables, I/O, arithmetic | M1–M2 | Week 3 |
| 2 | `assignment_02` | Tuition Estimator — decisions & validation | M3–M4 | Week 5 |
| 3 | `assignment_03` | Collatz Explorer — loops + first functions | M5–M7 | Week 7 |
| 4 | `assignment_04` | Interval Math Library — overloading, defaults, recursion, references | M8 | Week 9 |
| 5 | `assignment_05` | Sensor Array Analytics — 1-D arrays | M9 | Week 10 |
| 6 | `assignment_06` | Campus Grid — 2-D arrays | M10 | Week 11 |
| 7 | `assignment_07` | Text Toolkit — strings & sorting | M11–M12 | Week 13 |
| 8 | `assignment_08` | Score Ledger — structs, files, synthesis | M13–M15 | Week 15 |

Difficulty ascends from guided (A1–A2) through decomposition (A3–A5) to
synthesis (A6–A8). A8 doubles as practical-exam preparation: its skill band
(structs, vectors, robust file parsing) is the same as the practical's task 3.

## Grading

Per-assignment: correctness 30 (`instructor/assessment-rubrics/correctness.md`),
postmortem 10 (`explanation.md`); the test table feeds correctness lines
(`testing.md`). Code quality is graded on the shared `programming_quality.md`
scale via the correctness gate: artifacts that fail the compile gate score 0.

## CLO mapping

A1 → CLO-1/2 · A2 → CLO-2/3 · A3 → CLO-3/4/5 · A4 → CLO-5 · A5/A6/A7 → CLO-6 ·
A8 → CLO-7/8. Full map: `../../docs/ASSESSMENT_AUDIT.md` §3.

## Integrity

Assignments are individual. Reference solutions live only under `instructor/`;
never publish keys with the specs. See `../../instructor/ACCESS_CONTROL.md`.
