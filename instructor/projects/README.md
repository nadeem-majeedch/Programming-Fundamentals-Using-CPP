# instructor/projects/ — Project Keys & Reference Implementations
**INSTRUCTOR-ONLY** per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).

## Contents

| File | Purpose |
|---|---|
| [reference/p01_grade_calc.cpp](reference/p01_grade_calc.cpp) | P1 reference solution (functions-only architecture) |
| [reference/p02_expenses.cpp](reference/p02_expenses.cpp) | P2 reference solution (index-sort design variant) |
| [reference/p03_library.cpp](reference/p03_library.cpp) | P3 reference solution (struct + vector + persistence) |
| [reference/p04_records.cpp](reference/p04_records.cpp) | P4 reference solution (class with invariants) |
| P5 | **No full reference shipped** — see policy below |

## Verification status

P1–P4 reference implementations compile **zero-warning** with the course
contract (GCC 16.2, `g++ -std=c++17 -Wall -Wextra -pedantic`) and were
executed against the specs' test tables. Verified highlights:

- **P1** — T1 `86.05 -> B+`; T2 boundary `90.00 -> A`; T5 `bad mark for lab`
  with the record excluded from the summary; T7 immediate DONE →
  `no students`; T6 EOF mid-record → `bad input`, exit 1; T8 best-tracking
  correct.
- **P2** — T1 sample session reproduces the spec's exact report (shares
  31.30 %/68.70 %); T7 undo adjusts totals; T8 `nothing to undo`; T10 empty →
  `no expenses`. Sorted report uses the index-sort variant so category
  alignment cannot corrupt.
- **P3** — T2 corrupt line → `skipped: 1`, clean lines load; T3 lend/lend →
  `not available`; T4 return/return → `ok`/`ok` (idempotent return is
  harmless, documented); T1 round-trip `loaded: 3 skipped: 0`; id policy
  B-1003 after max B-1002. Save format uses `std::setprecision` discipline —
  note the file grammar uses token reads (single-word titles); the spec's
  "reject `;` in titles" rule is the defense that keeps the grammar safe.
- **P4** — T1 gpa 4.01 → `rejected`; T3 graduate twice →
  `already graduated`; T4 duplicate id rejected; T6 poisoned file (gpa 9.0
  line) → `skipped: 1` and the invariant holds from birth; report mean
  verified over ACTIVE students only (2.17 case cross-checked in Python);
  save format fixed at 2 dp so the round-trip is lossless.

## P5 policy — why no complete reference

P5 is the graded capstone; a distributed reference would leak. Graders
should assemble the expected behaviors from the P1–P4 references (the three
desks are deliberately the same domains) plus the spec's T1–T10. If a full
reference is needed for moderation, derive it by merging p02/p03/p04
patterns; do not circulate any merged file to students.

## Grading notes (P1–P4 when used as graded homework)

- Use each project's 10-point rubric; the shared `correctness.md` gates apply
  (contract compile = gate).
- P2 scope line: `std::sort`/`vector` caps correctness at 3/10.
- P3/P4: a program that crashes on its own poisoned-file test fails the
  persistence line entirely (state machines must reject, not throw).
- P4's attack log (postmortem) is evidence, not decoration: no attacks
  documented → explanation rubric ≤ half.

## Distribution discipline

Student specs live in `../../projects/project-0N/`; this folder never ships
with them. When publishing a solution *after* the term, strip instructor
headers and rotate the spec's data (ids, thresholds) next term.
