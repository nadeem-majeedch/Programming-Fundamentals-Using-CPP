# Changelog

All notable changes to course materials are logged here.
Format: date · scope · summary. Newest first.

## 2026-09-18 · GitHub Pages deployment

- **Workflow** (`.github/workflows/pages.yml`): on push to `main` (and
  manual dispatch) — checkout → Python 3.x → `python tools/build_site.py` →
  upload `website/site` as the Pages artifact → `actions/deploy-pages@v4`.
  Zero dependencies; correct permissions (`pages: write`, `id-token: write`)
  and a non-cancelling concurrency group. One-time repo setting: Pages
  source → "GitHub Actions".
- **Subpath-readiness of the site**: `.nojekyll` emitted (site.js serves
  unprocessed), `<link rel="canonical">` on every page pointing at the
  production URL (`SITE_BASE_URL` in `tools/build_site.py`).
- Validated: YAML parses and matches the official Pages pattern; site
  crawl 97/97 pages + assets with 0 broken links; **0 absolute-root paths**
  anywhere; full-site crawl under a simulated `/Programming-Fundamentals-Using-CPP/`
  subpath passed 100 %.

## 2026-09-18 · course website (97-page static site)

- **Generated site** (`website/site/`, built by `tools/build_site.py`):
  home + 11 sections + 84 sub-pages (32 lectures, 16 labs, 7 case-study
  pages, 17 exercise pages, 11 assignment pages, 6 project pages),
  responsive academic theme, dependency-free C++ syntax highlighting
  (`tools/site_src.js`), mirrored DS datasets (11 files).
- Link architecture: repo-relative markdown links normalized to root-anchored
  URIs and resolved site-wide — mapped targets → pages, mirrored files →
  copies, unmapped repo docs → honestly de-linked text; instructor-only
  folders never linked or mirrored.
- Defects found and fixed during QA: depth-relative chrome (1,415 broken
  links at first crawl), raw repo links (140), dead `#top` anchor,
  missing `#teaching-model` anchor target (section added), title
  truncation ("L01 · L01"), list-continuation splitting, literal `\1` in
  de-linked text, tablet breakpoint gap (46→64 rem), lede emphasis not
  rendered.
- QA: `docs/WEBSITE_QA.md` — all checks PASS (0 broken links/fragments,
  a11y 0 defects, 0 solution exposure, 0 restricted links).

## 2026-09-18 · progressive mini-project ladder (5 projects)

- **Five projects** (`projects/project-01..05`) replacing the single-project
  menu: Grade Calculator (M1–8, functions only) → Expense Tracker (M9–12,
  arrays + own sort, files forbidden) → Library System (M13–15, structs/
  vector/file round-trip) → Student Records (M14–16, first class with
  stated invariants) → Integrated Management Application (capstone,
  the graded 10 % component, Weeks 14–16).
- Every spec carries all 12 sections: problem, objectives, FR/NFR/VR
  numbering, data-structure guidance, byte-exact UI samples, testing plan
  (8–10 named cases), milestones, extensions, rubric, student instructions.
- **Reference implementations P1–P4** (`instructor/projects/reference/`):
  zero-warning compiles, executed against the spec tables. Defects fixed
  during verification: P1 EOF-vs-range conflation, P4 save precision and
  factory placeholder. P5 ships no full reference (leak policy).
- Grading plan preserved: P5 = 10 % via the shared 100-point rubric;
  P1–P4 optional homework grading at assignment weights.
- Audit: `docs/PROJECT_LADDER_VALIDATION.md` — all checks PASS.

## 2026-09-18 · data-science track (examples, exercises, case studies)

- **9 data-oriented example programs** (`examples/data-science/`): types &
  precision, mean/median, min-max-range, frequency counting, validation
  policies, sorting observations, a full text-file statistics pipeline,
  tabular records with group means, and a reproducible dice simulation —
  all zero-warning compiled and executed, formula-first headers, edge cases
  executed (empty input, NA, ties).
- **18 DS exercises** (`exercises/data-science/`, PF-DS-01…18) with a 7-file
  tested dataset set (documented defects + independently computed expected
  values) and a station-report mini capstone.
- **8 DS projector case studies** (`case-studies/data-science.md`) with a
  restricted instructor discussion guide.
- **Restricted instructor companions**: verified solutions
  (`instructor/exercises_data_science/`), per-program teaching notes
  (`instructor/examples_data_science/`), DS case solutions.
- Suggested extensions document with named bridges to data structures,
  algorithms, statistics, and databases — and an explicit out-of-scope
  boundary (no ML, no data libraries).
- Audit: `docs/DS_TRACK_VALIDATION.md` — all checks PASS (two spec arithmetic
  errors caught by independent cross-computation and fixed).

## 2026-09-18 · assessment package (quizzes, assignments, exams, rubrics)

- **16 module quizzes** (`quizzes/quiz_01..16`): student paper (7 items —
  4 MCQ, 1 trace, 1 debug, 1 short · 10 marks) + restricted instructor key
  per quiz with distractor analysis and remediation pointers; every trace
  answer machine-verified. Drop-lowest-2 per the preserved grading plan.
- **8 programming assignments** (`assignments/assignment_01..08`): 40 marks
  each (correctness 30 + postmortem 10), ascending difficulty M1→M15, each
  with a reference solution compiled **and executed** under the course
  contract, hidden-case classes, and common-defect lists.
- **Exam banks** (`instructor/exams/`): midterm pool 42 items / 94 marks,
  final pool 48 items / 112 marks — all tagged type·module·lecture·CLO·
  difficulty·marks; every CODE answer compiled & executed (two answer-key
  errors found and fixed during verification); blueprint assembly guide,
  4 midterm forms (50 marks each) + 4 final forms (100 marks each),
  consolidated answer keys, and per-quiz usage notes.
- **Practical coding assessment** (`exams/practical/` + restricted variants):
  2-hour lab exam, 80 marks, 4 variants with solutions and hidden-case
  classes.
- **Shared rubrics** (`instructor/assessment-rubrics/`): programming quality,
  correctness, testing, explanation, and a 100-point project rubric; the
  syllabus grading distribution is preserved verbatim (15/20/10/15/25/5/10).
- Student-facing review guides (`exams/midterm/`, `exams/final/`), projects
  menu, and retired the placeholder `assignment_N` skeletons and stale
  `quizzes/instructor/`, `exams/instructor/`, `exams/review/` paths.
- Audit: `docs/ASSESSMENT_AUDIT.md` — all checks PASS with evidence.

## 2026-09-18 · laboratory series (16 labs, manuals, starter code, TA notes)

- Rebuilt `labs/` from the 7-lab plan into a **16-lab series** (Lab *n* ↔
  Module *n* ↔ lectures 2n−1/2n): every `lab_manuals/lab_NN/manual.md`
  carries the 13-section contract (objectives, software contract, theory,
  pre-lab questions, demo, guided tasks with checkpoints, independent
  exercises, debugging task, test cases, outcomes, submission, rubric),
  progressing 70/30 guided→independent (Lab 1) to 20/80 (Lab 16).
- Starter programs for every lab compile **warning-free** (GCC 16.2,
  course contract) and were executed; bug-hunt files carry deterministic,
  documented defects — UB-bearing files (Lab 9 off-by-one write, Lab 12
  binary-search boundary) are compile-only, paper-trace exercises by
  design. One bug file that lacked its bug (Lab 10 border sum) was found
  and corrected during the audit.
- Memory-safety rule enforced: hazards always explained, guard pattern
  shown, `std::vector`/RAII alternative taught side-by-side (Lab 14).
- Shared resources added (`labs/resources/`): submission and five-step
  debug-log templates. TA notes restricted under `instructor_notes/`.
- Audit: [LAB_AUDIT.md](LAB_AUDIT.md) — **PASS**.

## 2026-09-18 · case-study bank (108 projector cases + instructor companions)

- Created `case-studies/` — **108 case studies** (`PF-CS-001`…`PF-CS-108`)
  in five progressive tiers (Beginner → Expert introductory) with projector
  files (`by_tier/`) containing problems, thinking questions, and
  progressive hints only — **no solutions** — plus `index.md` mapping every
  case to tier/lecture/module/concept.
- Created `instructor/case_studies/` — full companions: expected concepts,
  common incorrect approaches, discussion points, solution outlines, worked
  solutions, test cases, extensions, and a session playbook. 26 worked
  solutions machine-verified (GCC 16.2, `-std=c++17 -Wall -Wextra
  -pedantic`, zero warnings, executed with case inputs; 1 initializer-list
  defect found and fixed).
- All 108 lecture/module attributions cross-checked against
  `COURSE_SCHEDULE.md`; 22 initial mis-attributions corrected. Audit:
  [CASE_STUDY_AUDIT.md](CASE_STUDY_AUDIT.md) — **PASS**.

## 2026-09-18 · exercise bank (152 exercises + tested instructor solutions)

- Created `exercises/by_topic/` — the master exercise bank: **152 unique
  exercises** (`PF-E-001`…`PF-E-152`) across twelve topic files covering
  variables & calculations, conditions, loops, number problems, functions,
  arrays, strings, searching & sorting, pointers & references, structures,
  file handling, and classes & objects. Every record carries ID, title,
  problem statement, difficulty (Beginner → Foundational → Intermediate →
  Advanced Introductory), prerequisites, input/output requirements,
  constraints, samples, hints, and related lecture.
- Created `instructor/exercise_solutions/` — 13 compilable solution files
  (T12 split into two), one namespace per exercise. All compile
  **warning-free** under `g++ -std=c++17 -Wall -Wextra -pedantic` and every
  exercise was **executed** with its documented sample inputs; outputs
  verified (e.g., Collatz 871→178 steps, median/Q1/Q3, CSV skip-and-report
  4 loaded / 2 skipped, Fraction 1/6+1/3=1/2).
- Fixed during testing: e127 CSV parser (comma placement), e132→e133
  namespace reference, missing `<vector>` include, three unused-variable
  warnings. Student-facing files contain no solution code.
- Validation report: [EXERCISE_VALIDATION.md](EXERCISE_VALIDATION.md).

## 2026-09-18 · teaching material (complete lesson plans + verified examples)

- Extended all **32 lecture files** into full instructor-ready lesson
  plans: each now carries the twelve required sections — conceptual
  explanation (beginner-first), terminology & definitions, syntax with
  compilable examples, line-by-line code explanation, output prediction
  questions (with answers), common errors & debugging, classroom
  demonstrations, guided student activities, practice problems, summary,
  exit ticket, and estimated time allocation.
- All **29 example programs** in `examples/` authored, compiled
  **warning-free** under the course contract
  (`g++ -std=c++17 -Wall -Wextra -pedantic`), and **executed** — outputs
  verified against their documented expectations; interactive programs
  tested with piped inputs.
- Fixed during verification: stray `cin.ignore` in
  `string_processing.cpp`; `robust_pipeline.cpp` / `file_read_write.cpp`
  converted from exceptions to stream-state parsing (course standard
  policy); section order normalized in all 32 lectures (duplicate or
  misplaced headings removed); status markers flipped ⏳ → ✅ in
  `examples/README.md` and lecture tables.
- Validation: 32/32 section coverage · 29/29 compile-and-run · 353
  relative links resolve · 64/64 PF outcome codes consistent · no
  encoding artifacts. Details in
  [TEACHING_VALIDATION.md](TEACHING_VALIDATION.md).

## 2026-09-18 · curriculum (complete 16-module plan)

- Authored **32 detailed lecture planning files** (`lectures/week_01/lecture_01.md`
  … `lectures/week_16/lecture_32.md`), each with objectives, prerequisites,
  concept sequence, detailed teaching topics, required C++ examples,
  misconceptions, classroom activity, practice exercises, exit ticket, and
  time allocation.
- Restructured [../LEARNING_OUTCOMES.md](../LEARNING_OUTCOMES.md): 8 CLOs
  (CLO-1…8) + 64 fine-grained outcomes (PF-m.n, two per lecture), coverage
  matrices, prerequisite chain.
- Rewrote [../COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md) around the 16
  required modules (Module *n* = week *n*): module map, per-module lecture
  tables, assessment calendar, progression design.
- Updated [../COURSE_OVERVIEW.md](../COURSE_OVERVIEW.md),
  [../lectures/README.md](../lectures/README.md) (curriculum map),
  [../labs/README.md](../labs/README.md) (7-lab plan),
  [../examples/README.md](../examples/README.md) (28-file example index),
  assessment READMEs (assignments, quizzes, exams, projects), and 16 week
  folder READMEs.
- Validation report: `docs/CURRICULUM_VALIDATION.md` (32 lectures, 16
  modules, unique objectives, prerequisite ordering, CLO coverage — all PASS).

## 2026-09-18 · foundation

- Created repository architecture: 14 top-level directories with purpose
  READMEs; 16 week folders under `lectures/`; assessment subfolders.
- Authored root documents: README, COURSE_OVERVIEW, LEARNING_OUTCOMES,
  COURSE_SCHEDULE, TEACHING_GUIDE, CONTRIBUTING, LICENSE.
- Authored standards: C++17 policy ([CPP_STANDARD.md](CPP_STANDARD.md)),
  toolchain setup ([TOOLCHAIN.md](TOOLCHAIN.md)), code style
  ([CODE_STYLE.md](CODE_STYLE.md)), content roadmap
  ([CONTENT_ROADMAP.md](CONTENT_ROADMAP.md)).
- Added seed example `examples/hello_world.cpp` (compiles under the compile
  contract) and link checker `tools/check_links.sh`.
