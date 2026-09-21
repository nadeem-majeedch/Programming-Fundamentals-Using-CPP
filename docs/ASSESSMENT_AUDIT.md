# Assessment Package Validation Report

**Scope:** the complete assessment package — `quizzes/`, `assignments/`,
`exams/`, `projects/`, `instructor/exams/`, `instructor/assessment-rubrics/`.
**Method:** automated checks (Python scripts over the repository; GCC 16.2
compile-and-execute harness for every code-based answer) plus manual
cross-reading against `LEARNING_OUTCOMES.md` and `COURSE_SCHEDULE.md`.
Evidence is quoted per check. Date: 2026-09-18.

---

## 1. Deliverable inventory — **PASS**

| Required | Delivered | Evidence |
|---|---|---|
| ≥ 16 quizzes / quiz sets | **16 module quizzes** | `find quizzes -name quiz.md \| wc -l` → 16; 16 restricted keys |
| ≥ 8 programming assignments | **8** | `assignment_01` … `assignment_08`, each spec + key |
| Complete midterm bank | **42 items / 94 pool marks** | tag-parser count: 42 unique ids, marks sum 94 |
| Complete final bank | **48 items / 112 pool marks** | tag-parser count: 48 unique ids, marks sum 112 |
| Practical coding assessment | **2-hour / 80-mark format + 4 variants** | `exams/practical/README.md`, `instructor/exams/practical/variants.md` |
| Project evaluation rubric | **100-point rubric** | `instructor/assessment-rubrics/project.md` |
| Rubrics: quality/correctness/testing/explanation | **all four + project** | five files in `instructor/assessment-rubrics/` |

## 2. Question types & balance — **PASS**

Census (automated, per item tag):

| Type | Midterm pool | Final pool | Quizzes |
|---|---|---|---|
| MCQ | 8 | 8 | 64 (4 × 16) |
| Output tracing | 10 | 10 | 16 |
| Debugging | 8 | 8 | 16 |
| Short conceptual | 6 | 6 | 16 |
| Algorithm design | 4 | 4 | — |
| Coding problems | 4 | 4 | — |
| Complexity intuition | — | 4 (CPLX) | — |
| Code completion | 2 | 4 | — |

Conceptual ≈ 40 % / applied ≈ 60 % holds across both papers (MCQ+SHORT+part of
DEBUG vs TRACE+CODE+DESIGN+CCOMP), matching the plan's weighting line.

Difficulty (bank tags): midterm E16/M21/H5; final E17/M27/H4 — mixed ladders
with hard items concentrated in recursion, bounds, and invariant items.

## 3. CLO mapping — **PASS**

Automated extraction of CLO references per artifact:

- Quizzes: 01→CLO-1 · 02→CLO-2 · 03→CLO-2/3 · 04→CLO-3 · 05→CLO-3/4 ·
  06→CLO-4 · 07/08→CLO-5 · 09–12→CLO-6 · 13→CLO-7 · 14→CLO-7/8 · 15/16→CLO-8.
- Assignments: A1→CLO-1/2 · A2→CLO-2/3 · A3→CLO-3/4/5 · A4→CLO-5 ·
  A5–A7→CLO-6 · A8→CLO-7/8.
- Exam banks: midterm tags cover CLO-1(4), CLO-2(14), CLO-3(12), CLO-4(7),
  CLO-5(12); final tags cover CLO-6(30), CLO-7(9), CLO-8(9) — every CLO 1–8
  appears in at least one graded artifact; final-form weighting measured at
  **76 % of marks on Modules 9–16** (≥ 60 % required) for all four forms.

## 4. Marks & totals are mathematically correct — **PASS**

- Quizzes: generator-asserted 10 marks per quiz × 16 (sum of item marks
  checked at generation; re-verified per file: 7 items each, totals `10`).
- Midterm forms A–D: parsed section totals = **50 each** ✓.
- Final forms A–D: parsed section totals = **100 each** ✓ (incl. Q9 synthesis).
- Assignment marks: correctness 30 + postmortem 10 = **40** ✓ stated and used
  consistently in all 8 specs and keys.
- Bank pool totals: per-type sums equal headline totals (94 / 112) after
  fixing the header counts (initially mis-stated as 40/44 items — corrected).

## 5. Code-based answers validated — **PASS (after 6 fixes)**

Harness: GCC 16.2, `g++ -std=c++17 -Wall -Wextra -pedantic`, zero warnings
required; each program executed with its documented input and the key's
expected output had to appear verbatim.

| Program | Result | Note |
|---|---|---|
| A1 record_card | PASS | sample 86.05 reproduced |
| A2 tuition | PASS | 7500.00 (sample corrected) |
| A3 collatz | PASS | steps 8 / max 16 / path |
| A4 intervals | PASS | full demo output exact |
| A5 sensors | PASS | 5/2/19/22/20.8/3 |
| A6 campus | PASS | diagonal 2 (spec-trap honored) |
| A7 textkit | PASS | `swaps 2`; whole-word `no` |
| A8 ledger | PASS | loaded 3 / skipped 3 / mean 85.00 |
| Exam bank CODE ×8 (midterm F1–F4, final G1–G4) | PASS | incl. isPerfect 6 28 496 8128; insertion-sort per-pass rows |

**Defects found by execution and fixed:**

1. A2 sample: cap-then-scholarship order made `out 20 500` → 7500.00, not
   8400.00 (my arithmetic in the first draft ignored that the cap *precedes*
   the scholarship). Spec sample + key aligned; solution unchanged.
2. A4 solution: `clamp` defaults declared in definition (compile fix).
3. A7 solution: unused-parameter warning (signature fix); zero warnings now.
4. Midterm F3 key: quoted run `4 5 6 0 → 2 9 4.50` was wrong for that input
   (it is the output for `4 5 0`); both runs now quoted correctly.
5. Final G2 key: `Hello, World 42!` → `3 7 2`, not `3 8 2` (miscount of
   consonants); key corrected with the arithmetic shown.
6. Bank headers: item counts corrected to 42/48.

## 6. Duplicate detection — **PASS**

- Bank item ids: 42/42 and 48/48 unique (`collections.Counter`).
- Cross-file duplicate stems (normalized, quizzes + banks): only 4 matches,
  all boilerplate lines ("Answer all items…", tag legends, `cin >> a >> b`
  extraction line re-used in a *different* question context), zero duplicated
  question stems.
- Case-study/exercise IDs from earlier phases were not reused; assessment
  items use their own numbering (A/B/… per section, quiz Q1–Q7, PF-E untouched).

## 7. Answer-key consistency — **PASS**

- Every quiz item has exactly one key entry (7/7 per quiz, automated count).
- Form→bank mapping checked in `answer_keys.md`; form-specific completions
  keyed inline (e.g., Form B Q7 `(a) 0 (b) a (c) true`).
- Keys quote the executed outputs from §5 (post-fix values).
- Two-person protocol and post-exam alternative-answer log specified in
  `PAPER_ASSEMBLY.md` §4.

## 8. Student/instructor separation — **PASS**

- No `**Answer:**` lines in any student-facing file (grep: only instruction
  sentences like "Answer all items…" match, verified manually).
- All 32 keys (16 quiz + 8 assignment + banks/forms/rubrics) carry the
  INSTRUCTOR-ONLY banner (folder-level notice added for rubrics; form files
  bannered in-header since they are question-only by design).
- Exam papers contain questions only; the printing checklist in
  `PAPER_ASSEMBLY.md` mandates stripping Answer lines for exam-day copies.

## 9. No untaught features / scope discipline — **PASS**

Manual sweep: no templates, lambdas, STL algorithms (`std::sort` explicitly
banned in A7), ranges, smart pointers, or exceptions-as-validation before
Module 15; `std::vector` appears only from A8/M14 onward; `std::min`/`std::max`
(A2/A4) were introduced in M4; `std::istringstream` (A7/A8) follows L22/M15.
`std::string`-switch (illegal in C++) appears only as a *distractor*, keyed as
a compile error.

## 10. Repository integrity — **PASS**

- Link checker: **OK — 565 relative links resolve** (after repointing six
  stale `exams/review/` references in pre-existing docs to the delivered
  guides, and fixing the link depth in the midterm guide).
- Retired placeholder skeletons (`assignments/assignment_1..8` plan-era dirs,
  `quizzes/instructor/`, `exams/instructor/`, `exams/review/`,
  `projects/capstone/`) removed only after grep confirmed no content beyond
  empty folders/PLACEHOLDER text; all references repointed (README,
  CONTRIBUTING, instructor/, student/, lectures 16/32).
- Changes confined to: `quizzes/`, `assignments/`, `exams/`, `projects/`,
  `instructor/exams/`, `instructor/assessment-rubrics/`, `instructor/`
  (pointer lines only), `docs/CHANGELOG.md`, this report, and the six stale-
  reference fixes above. No build artifacts left (`rm -rf .audit_build*`).
- Nothing committed or pushed.

---

## Overall: **PASS**

| Area | Verdict |
|---|---|
| Inventory (counts) | PASS |
| Types & difficulty balance | PASS |
| CLO mapping & form weighting | PASS |
| Marks arithmetic | PASS |
| Code validation (compile + execute) | PASS (6 defects found & fixed) |
| Duplicates | PASS |
| Key consistency | PASS |
| Separation of solutions | PASS |
| Scope discipline | PASS |
| Links & integrity | PASS |
