# Shared Assessment Rubrics
**INSTRUCTOR-ONLY** per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).

**INSTRUCTOR-ONLY** — all five rubric files in this folder are restricted
(despite individual filenames not carrying the banner; this README is the
folder-level notice).

| File | Used by |
|---|---|
| [programming_quality.md](programming_quality.md) | assignments, practical, project — code-quality line |
| [correctness.md](correctness.md) | assignments, practical, exams' coding items |
| [testing.md](testing.md) | assignments (test tables), practical task 3, project |
| [explanation.md](explanation.md) | assignments (postmortem), project report, synthesis exam option 2 |
| [project.md](project.md) | course project evaluation (100 points) |

## Course-wide grading distribution

The syllabus-era plan already fixed the distribution; this package **preserves**
it (see `../../COURSE_OVERVIEW.md` §Assessment). For convenience, the same
numbers:

| Component | Weight | Delivered by this package |
|---|---|---|
| 16 module quizzes (drop lowest 2) | 15 % | `quizzes/quiz_01..16` |
| 8 programming assignments (drop lowest 1) | 20 % | `assignments/assignment_01..08` |
| Laboratory program (16 labs) | 10 % | `labs/` (delivered separately) |
| Midterm examination | 15 % | `instructor/exams/midterm_form_A..D` |
| Final examination | 25 % | `instructor/exams/final_form_A..D` |
| Practical coding assessment | 5 % | `exams/practical/` + variants |
| Course project | 10 % | `projects/` + rubric `project.md` |

Total = 100 %. No component was silently re-weighted; the quiz drop policy
(d lowest 2 of 16) and assignment drop (lowest 1 of 8) match the plan's
resilience language.

## Mark-integrity rules

1. Every artifact states its total; totals must equal the sum of line marks
   (verified in `../../docs/ASSESSMENT_AUDIT.md` §6).
2. Partial credit uses the rubric lines only — no ad-hoc deductions.
3. Borderline grades are decided by the explanation rubric evidence, not by
   rounding.
