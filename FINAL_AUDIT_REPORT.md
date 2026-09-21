# FINAL_AUDIT_REPORT.md — Comprehensive Release Audit

**Course:** Programming Fundamentals Using C++
**Audit date:** 2026-09-18 / 2026-09-19 · **Auditor:** automated + manual cross-reading
**Method:** every numeric claim below is backed by a command run against this
repository (evidence quoted in the phase reports listed in §9). Environment and
reproduction steps: [BUILD_REPORT.md](BUILD_REPORT.md).

---

## Verdict

# ✅ PASS WITH WARNINGS

No critical or high-priority issues remain open. Two medium-priority warnings and
three low-priority notes are recorded below; none block release. **This verdict
could not have been claimed at the start of the audit** — six real defects were
found and fixed during it (§7).

---

## 1. Headline numbers

| Metric | Count |
|---|---|
| Files reviewed (excl. `.git`, generated `website/site/`) | **351** |
| Generated site files (reviewed via crawl + QA) | 100 (97 pages, styles.css, site.js, .nojekyll) |
| C++ files compiled | **72** (38 examples + 9 DS examples + 17 lab starters + 13 solution banks + 4 project references) |
| C++ files compiled clean (contract flags) | **71** (72 − 1 intentional Lab-1 defect) |
| Deterministic executions / test runs | **≈ 40** (examples, DS pipeline, quiz/exam/assignment key harness, project specs) |
| Tests passed | **all** (0 unexpected failures; 2 flagged runs verified as correct guard behavior, 1 hang fixed — §7.5) |
| Markdown links checked | **612/612** resolve (`tools/check_links.sh`) + **2,064** site links, 0 broken |
| Lectures / modules / weeks | **32 / 16 / 16** |
| Case studies | **108** (+ 8 data-science cases = 116 total) |
| Exercises | **170** (152 PF-E + 18 PF-DS) |
| Labs / quizzes / assignments / projects | **16 / 16 / 8 / 5** |

## 2. Structure — PASS

- All 14 required directories present (`docs lectures examples exercises labs
  assignments quizzes exams projects resources instructor student tools website`)
  plus `case-studies/`, `.github/workflows/`.
- All 7 required root files verified present: README, COURSE_OVERVIEW,
  LEARNING_OUTCOMES, COURSE_SCHEDULE, TEACHING_GUIDE, CONTRIBUTING, LICENSE —
  plus `.github/workflows/pages.yml` and `website/site/.nojekyll` (Pages deploy).
- Inventory scan: **0 orphaned files, 0 naming violations** (all content follows
  `lecture_NN.md`, `quiz_NN/`, `assignment_NN/`, `lab_NN/`, `tierN_*.md` etc.).
- No scratch/build artifacts in the repo (audit-run leftovers removed — §8).

## 3. Curriculum — PASS

- **32 lectures** in `lectures/week_01…week_16/`, numbered 01–32 with no gaps or
  duplicates; week *n* = module *n* = lectures 2n−1/2n; every module of the
  requested 16-module list maps to its week.
- Per-lecture completeness: all 12 mandated sections present in all 32 lectures —
  after this audit added the missing *Common student misconceptions* section to
  L04, L05, L06, L07, L14, L17, L18 (§7.4). Verified present: `L04–L07, L14,
  L17, L18: 1` section each.
- Outcome codes: **64/64 PF-codes in lecture headers are valid** against
  `LEARNING_OUTCOMES.md`; **0 duplicated objectives** across all 32 lectures.
- Progression: prerequisites chain correctly (no lecture cites an untaught
  construct; difficulty rises M1→M16; the CLO→module matrix in
  `docs/CURRICULUM_VALIDATION.md` shows full coverage with no gaps).

## 4. Content quality — PASS

- Grading-distribution contradiction **found and fixed** (§7.1): overview,
  schedule, teaching guide, and quizzes README now agree with the authoritative
  7-component assessment (Quizzes 15 % · Assignments 20 % · Labs 10 % ·
  Midterm 15 % · Final 25 % · Practical 5 % · Project 10 % = **100 %**).
- No invented academic references: repository-wide citation scan returns only
  the C++ standard, cppreference, and the ISO C++ Core Guidelines (all real,
  publicly verifiable). Formula/technique claims are self-contained.
- No placeholder text in course content (`grep -r` for TODO/placeholder/lorem/
  "TBD"/"cover relevant" = 0 hits outside audit reports; the single "TODO" is
  an intentional student task in a lab skeleton).
- Terminology follows the glossary (`resources/glossary.md`); standard vs
  compiler-specific behavior is distinguished in lectures and
  [docs/CPP_STANDARD.md](docs/CPP_STANDARD.md).

## 5. C++ code quality — PASS (71/72 clean + 1 intentional)

- Contract: `g++ -std=c++17 -Wall -Wextra -pedantic` (GCC 16.2.0).
- **71/72 files compile with zero warnings**; deterministic ones were executed
  and outputs matched expectations (examples, DS statistics pipeline vs hand
  computed values, quiz/exam tracing answers, assignment keys, project
  reference solutions vs their spec test tables).
- The single non-compiling file, `labs/lab_manuals/lab_01/starter_code/
  three_stages.cpp`, is the **Lab-1 bug hunt** with one planted defect per
  translation stage — intentional, documented in `manual.md` §9, and flagged
  in-file ("DO NOT fix before class").
- Input validation & edge cases: this audit **fixed** a real robustness defect —
  `examples/loops_sum_digits.cpp` hung on EOF-without-sentinel (§7.5). After the
  fix, the EOF case exits cleanly with the correct sum. `decisions_grade.cpp`'s
  rc=1 at EOF is its correct "Not a number" guard, verified.
- Memory safety: no unsafe patterns in course code (`gets`-era APIs, unchecked
  `new`, dangling references, `delete` misuse — none present; Lab 13 *teaches*
  hazard identification against guarded examples, Lab 14 contrasts raw arrays
  with `std::vector`).

## 6. Case studies — PASS

- **108 projector cases** (requirement: ≥ 100) in 5 progressive tiers
  (20/24/26/22/16) + 8 data-science cases = 116; **unique IDs, unique titles,
  116/116 mapped to lectures**; duplicate-concept scan clean.
- Every case carries the mandated fields (context, I/O, constraints, thinking
  questions, hints, extensions — the projector files carry **no solutions**;
  worked solutions + discussion points live in `instructor/case_studies/`).
- Solution outputs for deterministic cases verified during the phase audit
  (GCC-compiled harness; see `docs/CASE_STUDY_AUDIT.md`).

## 7. Issues found and fixed during this audit

| # | Severity | Defect (evidence) | Fix |
|---|---|---|---|
| 7.1 | Medium | **Grading-policy contradiction** — stale 6-component distribution (Quizzes 10 %, weeks 5/9/11) in `COURSE_OVERVIEW.md`, `COURSE_SCHEDULE.md`, `TEACHING_GUIDE.md`, `quizzes/README.md` vs the authoritative as-built 7-component package (rubrics README, changelog, prior audits) | All four files corrected to the 7-component 100 % table; re-grepped consistent |
| 7.2 | Medium | **False coverage claim in final-exam docs** — header claimed "28 marks of pool from Modules 1–8" while the bank/blueprint/audit draw the final entirely from the Modules 9–16 pool (0 M1–M8 items parsed) | `instructor/exams/final_bank.md` and `final_form_A.md` corrected to "Modules 9–16 pool only (76 % of paper marks, ≥ 60 % required)"; verified against `PAPER_ASSEMBLY.md` and the assessment audit |
| 7.3 | High (student-facing breakage) | **Malformed lab-page links** — 16 lab pages emitted `href="../resources.html"#fragment` (anchor outside the quotes) due to a fragment-emission bug in `tools/build_site.py::fix_links()` | Generator fixed; site rebuilt; scan for malformed hrefs = 0 |
| 7.4 | Medium | **7 lectures (L04, L05, L06, L07, L14, L17, L18) lacked the mandated *Common student misconceptions* section** | Topic-appropriate sections added to each (validation per-lecture count = 1 each, re-run) |
| 7.5 | High (runtime hang) | **`examples/loops_sum_digits.cpp` infinite-loops on EOF without sentinel** (failed read leaves stream stuck) — contradicted the very idiom its lecture teaches | Stream-state guard added per the lecture's own pattern; EOF case now terminates with correct sum; recompiled & re-executed clean |
| 7.6 | Low | Stale header text in `final_form_A.md` only (B/C/D clean) | Corrected |

## 8. Lab & assessment audit — PASS

- **16 labs** `lab_01…lab_16`, each with the 13 mandated components, starter
  code (compiles clean except the intentional Lab-1 defect), test cases, and
  rubric; guided→independent progression documented in `labs/README.md`.
- **16 quizzes** (quiz_01…quiz_16, each with student `quiz.md` + separate
  `instructor_key.md`); **8 assignments** (assignment_01…08, same split);
  midterm bank 42 items/94 marks (internally consistent, 0 duplicate IDs);
  final bank 48 items/112 marks (section sums 8+20+16+12+8+12+24+12 = 112 ✓);
  4 midterm + 4 final forms; practical exam README + variants; 5 rubric files
  (programming quality, correctness, testing, explanation, project).
- Marks math verified programmatically for quizzes, assignments, both banks,
  and forms. Answer-key placement: every key inside `instructor/`-controlled or
  `*_key.md` files; **student-facing files contain 0 complete solutions**
  (leak scan: 31 hits, all navigational policy text — verified manually).
- Audit trailing: `docs/ASSESSMENT_AUDIT.md` records the machine-verified
  answer harness (GCC 16.2).

## 9. Website — PASS

- Build re-run this audit: **97 pages + assets, deterministic** (two runs
  byte-identical), 0 build errors.
- Full crawl from `index.html`: **2,064 internal links / 0 broken**; cross-page
  fragments resolve; 0 malformed hrefs (after §7.3).
- 12-section navigation present on every page with section-aware
  `aria-current`; accessibility basics verified per page in the phase QA
  (`docs/WEBSITE_QA.md`); responsive breakpoints (tablet/phone/print) verified
  live in the phase audit with screenshots.
- Placeholder scan: 0. Exposure scan: 0 real leaks — 31 regex hits inspected
  one by one; all are navigation/policy sentences (e.g. "solutions live in the
  instructor area"), not answer content; `instructor/` and `*_key*` trees are
  never mirrored into `website/site/`.

## 10. Priority summary

| Priority | Open | Notes |
|---|---|---|
| Critical | **0** | — |
| High | **0** | §7.3/§7.5 were high and are fixed |
| Medium | **0 open** | §7.1/§7.2 fixed this audit; 2 *warnings* remain (below) |
| Low | **0 open** | §7.6 fixed; 3 *notes* remain (below) |

**Warnings (do not block release):**

1. **Instructor resource package is minimal.** A completed `instructor/` tree
   exists (access control, answer-key index, exam keys, rubrics, TA checklists),
   but a dedicated narrative *lesson-delivery / facilitation* guide was not
   authored (the interrupted turn that would have created it was superseded by
   this audit, per its "no major new content" constraint). TEACHING_GUIDE.md at
   root covers session structure and time allocation.
2. **Cross-compiler verification is documented, not executed.** The course
   contract claims MSVC/Clang portability ([docs/TOOLCHAIN.md](docs/TOOLCHAIN.md));
   all machine verification this audit ran used GCC 16.2 only. Code review found
   no non-standard constructs, but "compiles on MSVC" remains a documented claim.

**Low-priority notes:**

1. `labs/lab_manuals/` files share a bulk timestamp from their generation pass —
   cosmetic only; content verified individually.
2. "Labs 1–N" prerequisite phrasing in lab manuals is range notation with an
   explicit "(Lab 1: none)" clarification — semantically correct.
3. Website is served from the repo subpath by design (relative links +
   canonical URLs); anyone hosting at a domain root should regenerate with the
   documented base change (see `website/README.md`).

## 11. Reproducibility & cleanup

- Validation re-ran after the Freebuff restart from a fresh shell; website build
  determinism re-verified (byte-identical trees).
- Scratch artifacts from audit executions (`app_log.txt`, `mixed_scores.txt`,
  `scores.txt` written by file-I/O examples; the `/tmp` build tree) **removed**;
  repository contains no build leftovers.
- No directories outside the course repository were modified. Nothing was
  committed or pushed (per instruction).

## 12. Evidence index

| Claim | Source |
|---|---|
| Structure/naming inventory | this audit's inventory scan (§2) |
| Curriculum, lecture completeness, PF codes | `docs/CURRICULUM_VALIDATION.md` + re-runs (§3) |
| Teaching-material sections | `docs/TEACHING_VALIDATION.md` + this audit's section check (§3) |
| Exercises & IDs | `docs/EXERCISE_VALIDATION.md` + re-run: 170 exercises, 0 duplicate IDs (§1) |
| Case studies | `docs/CASE_STUDY_AUDIT.md` + re-run: 116 cases, unique IDs/titles (§6) |
| Labs | `docs/LAB_AUDIT.md` + compile sweep (§5, §8) |
| Assessments & marks | `docs/ASSESSMENT_AUDIT.md` + re-runs (§8) |
| Data-science track | `docs/DS_TRACK_VALIDATION.md` |
| Projects | `docs/PROJECT_LADDER_VALIDATION.md` |
| Website | `docs/WEBSITE_QA.md` + this audit's rebuild & crawl (§9) |
| Environment & reproduction | [BUILD_REPORT.md](BUILD_REPORT.md) |

---

## FINAL RESULT: **PASS WITH WARNINGS**

The repository is release-ready for a pilot semester. The two warnings above are
enhancement opportunities, not defects: no critical or high-priority issue
remains open, all machine checks pass, and the six defects discovered by this
audit are fixed and re-verified.

*Per instruction, nothing was committed or pushed.*
