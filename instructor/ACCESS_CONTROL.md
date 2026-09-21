# Access Control — Restricted Content Map

**Audience:** instructors and repository maintainers.

## 1. Restricted paths (never student-published)

| Path | Content |
|---|---|
| `instructor/` | keys index, pacing guide, slide sources, proctoring notes |
| `quizzes/quiz_NN/instructor_key.md` | quiz answer keys |
| `instructor/exams/` | exam banks, papers, keys, practical variants |
| `exercises/in_class/solutions/` | in-class drill solutions (publish after class) |
| `exercises/homework/solutions/` | homework solutions (publish after due date) |
| `assignments/assignment_N/instructor/` | assignment solutions & grading notes |
| `labs/lab_manuals/lab_0N/instructor_notes/` | TA checklists |

## 2. Publishing workflow (semester mirror)

1. Before week 1, create the student mirror as a **copy** of this repository
   with the paths in § 1 **excluded** (a simple `rsync`/`robocopy` exclude
   list works; no special tooling is required).
2. Publish exercise/quiz keys to the mirror **only after** their deadlines.
3. Exam papers are never mirrored in any form; students receive the printed
   paper in the exam room.
4. After the semester, archive the mirror under a term tag (e.g.
   `2026-fall`) so future-term papers stay unpublished.

## 3. Repository hygiene rules

- Never commit keys to student-facing paths; there is no "hidden" in a
  repository — only unshared.
- The split is by **content**, not by folder tricks: a public folder may not
  contain restricted material "temporarily".
- Contributions that mix student and instructor content in one commit are
  rejected ([../CONTRIBUTING.md](../CONTRIBUTING.md) § 6).

## 4. Review checklist (per semester start)

- [ ] Mirror exclude list matches § 1 exactly.
- [ ] No restricted path present in the published mirror (spot-check).
- [ ] Quiz/exam release calendar entered in the instructor calendar.
- [ ] Last term's exam papers removed from the current mirror.
