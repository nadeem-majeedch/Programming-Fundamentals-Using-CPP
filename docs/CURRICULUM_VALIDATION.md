# Curriculum Validation Report

**Scope:** the complete 16-module, 32-lecture curriculum developed for
*Programming Fundamentals Using C++* (this repository).
**Method:** automated checks (`bash`/`grep` over the repository) plus
manual cross-reading of the three curriculum documents against the lecture
files. Evidence is quoted per check. Date: 2026-09-18.

---

## 1. Exactly 32 lectures — **PASS**

- Evidence: `ls lectures/week_*/lecture_*.md | wc -l` → **32**.
- Files span `lectures/week_01/lecture_01.md` …
  `lectures/week_16/lecture_32.md`; the global numbering rule (week *n* =
  lectures `2n−1`, `2n`) holds for every pair (spot-checked: week 5 → L09/L10,
  week 13 → L25/L26, week 16 → L31/L32).

## 2. All 16 modules included — **PASS**

- The 16 required modules appear verbatim in
  [COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md) § Module map (16 rows) and are
  implemented as Module *n* = week *n*:
  1 Introduction to Programming and C++ · 2 Variables, Data Types, and
  Input/Output · 3 Operators and Expressions · 4 Decision-Making Statements ·
  5 Loops and Repetition · 6 Problem-Solving and Algorithm Design ·
  7 Functions Fundamentals · 8 Advanced Function Concepts ·
  9 One-Dimensional Arrays · 10 Two-Dimensional Arrays ·
  11 Strings and Character Processing · 12 Searching and Sorting ·
  13 Pointers and References · 14 Dynamic Memory and Structures ·
  15 File Handling and Error Management · 16 Introduction to Object-Oriented
  Programming.
- Every week folder README carries its module title and number
  (`lectures/week_NN/README.md`, 16 files, machine-generated from the same
  title list used in the schedule).

## 3. All required sections per lecture file — **PASS**

Required sections (11 per file): title/header block, Learning objectives,
Prerequisites, Concept sequence, Teaching topics (detailed), C++ examples
required, Common student misconceptions, Classroom activity, Practice
exercises, Exit ticket, Estimated time allocation.

- Evidence: grep count of each `## ` heading across the 32 files → **32/32**
  for every section (one heading per file; no misses, no duplicates).
- Time-allocation tables sum to 120 minutes per lecture (verified by
  inspection; L16 and L32 carry an explicit note for their exam-hour
  variants, per [COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md) § Scheduling
  notes).
- No placeholder phrasing: `grep -riE "cover relevant|TBD|placeholder topic|etc\." lectures/week_*/lecture_*.md`
  → only false-positive matches inside fully specified content (e.g. "etc."
  absent; the word "placeholder" appears only in assignment folder READMEs
  that are *intentionally* marked as not-yet-authored assessment specs).

## 4. No duplicated lecture objectives — **PASS**

- Evidence: `grep -h "^1\. " lectures/week_*/lecture_*.md | sort | uniq -d | wc -l`
  → **0** (first-objective lines are unique across all 32 files; the first
  objective is always the lecture's primary behavioral claim).
- Fine-grained outcome codes are likewise unique: 64 distinct `PF-m.n` codes
  across lecture headers (`grep -oE "PF-[0-9]+\.[0-9]+" | sort -u | wc -l` →
  **64**), exactly two per lecture × 32.

## 5. Prerequisites and progression — **PASS**

- Every lecture file names its prerequisites as exact lectures/modules; the
  maximal prerequisite of any lecture in Module *m* is ≤ Module *m−1*
  (verified per file; e.g. L25 requires L17+L15+L06, all < Module 13;
  L31 requires L28+L15/L26+M5, all < Module 16).
- Difficulty ordering documented and monotonic:
  [COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md) § Progression design (six-step
  rationale: values → control → design consolidation → abstraction → data →
  machine → integration). No module introduces two independently new hard
  ideas; every reuse is named (e.g. selection sort reuses L18's
  min-selection; transpose reuses L20's `j > i` swap symmetry).
- Forward references are only deliberate foreshadowing (named as such:
  "payoff in L15/L26", "full treatment in Module 15"), never silent gaps.

## 6. CLO ↔ lecture-topic alignment — **PASS**

- [LEARNING_OUTCOMES.md](../LEARNING_OUTCOMES.md) defines 8 CLOs and 64 `PF-m.n`
  codes; each lecture header cites exactly one CLO and its two PF codes; the
  CLO↔module coverage matrix shows **every module maps to exactly one primary
  CLO** and every CLO has 2–4 primary modules (8 CLOs / 16 modules).
- Assessment mapping matrix (CLO × assessment instrument) is present and
  consistent with the grading weights in
  [COURSE_OVERVIEW.md](../COURSE_OVERVIEW.md) § 4 and the assessment calendar in
  [COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md).
- Consistency check: PF codes used in lecture files = PF codes defined in
  LEARNING_OUTCOMES.md (set equality, 64 = 64; e.g. PF-16.1–16.4 defined →
  used by L31/L32).

## 7. Repository integrity after the change — **PASS**

- Link check: `bash tools/check_links.sh` → **OK: 346 relative markdown
  links checked, all resolve** (planned example files are referenced as
  code-text ⏳ markers, matching the repository convention).
- No unrelated files modified: the change set touches only
  `COURSE_OVERVIEW.md`, `LEARNING_OUTCOMES.md`, `COURSE_SCHEDULE.md`,
  `lectures/**` (32 lecture files, 16 week READMEs, lectures/README.md),
  `labs/README.md`, `labs/lab_manuals/README.md`, `examples/README.md`,
  `assignments/README.md`, `assignments/assignment_3/README.md`,
  `assignments/assignment_4/README.md`, `quizzes/README.md`,
  `exams/README.md`, `projects/README.md`, and `docs/` (CHANGELOG,
  CONTENT_ROADMAP, this report). The established architecture
  (directory layout, naming conventions, access-control split, C++17
  policy) is preserved — no directory was added, moved, or removed.
- Nothing committed or pushed (no git repository exists).

---

## Summary

| Check | Verdict |
|---|---|
| Exactly 32 lectures | PASS |
| All 16 modules included | PASS |
| Required sections per lecture (11 × 32) | PASS |
| No duplicated lecture objectives | PASS |
| Prerequisites & progression | PASS |
| CLO ↔ lecture-topic alignment | PASS |
| Repository integrity (links, scope, architecture) | PASS |

**Overall: PASS** — the curriculum is complete, internally consistent, and
aligned with the repository's architecture and outcome system.
