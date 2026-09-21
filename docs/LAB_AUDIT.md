# Laboratory Series Audit Report

**Scope:** the 16-lab series under `labs/` — rewritten series README, 16
manuals (`lab_manuals/lab_NN/manual.md`), 16 TA checklists (restricted),
17 starter programs, and shared resources.
**Method:** automated checks (grep/python over the repository; GCC 16.2
build-and-execute harness with fresh binaries) plus manual cross-reading
against `COURSE_SCHEDULE.md`, `LEARNING_OUTCOMES.md`, and the lecture
planning files. Evidence per check. Date: 2026-09-18.

---

## 1. Exactly 16 labs — **PASS**

- Evidence: `find labs -name manual.md | wc -l` → **16**; folders
  `lab_01 … lab_16` each contain `manual.md`, `starter_code/`,
  `instructor_notes/ta_checklist.md`.
- Manual numbering matches the required topic list 1–16 verbatim
  (First C++ Program … OOP Mini-Project).

## 2. Learning objectives and topic alignment — **PASS**

- Each Lab *n* is bound to Module *n* and lectures 2n−1/2n, matching the
  authoritative `COURSE_SCHEDULE.md` table row-for-row (verified by
  cross-reading all 16 rows; the series README table states the same
  binding).
- The 16 required topics map 1:1 onto the 16 manuals; the 13 required
  manual sections appear in order in every manual (section-numbered
  headings § 2–§ 13; header block covers item 1).
- Objectives are lecture-anchored: each manual cites the module's PF
  outcomes via `LEARNING_OUTCOMES.md`; progression guided→independent
  follows the stated ratios (70/30 in Lab 1 → 20/80 in Lab 16).

## 3. Starter code compiles — **PASS (16 clean + 1 documented teaching failure)**

- Harness: fresh build directory, `g++ -std=c++17 -Wall -Wextra -pedantic`
  (GCC 16.2), every `.cpp` under `labs/lab_manuals/*/starter_code/`.
- Result: **16/17 compile with zero diagnostics**.
- `lab_01/three_stages.cpp` fails **by design** — its documented
  Defect A is the compile-stage error (`return 0` missing the
  semicolon); the file header labels it "bug-hunt file (DO NOT fix
  before class)". This is the Lab 1 teaching artifact, not a defect.
- During the first harness run a stale binary produced a false result
  (Lab 15's missing-file path appeared not to fire); the run was
  repeated with cleaned binaries and the program behaves as documented
  (`cannot open <file>`, exit 2). No source change was needed.

## 4. Sample outputs and test cases — **PASS**

Executed outputs matched every documented value, including the
*deliberately wrong* bug-hunt outputs (a bug-hunt file that printed the
correct answer would be misleading — one such file, Lab 10's border sum,
was found showing 40 instead of the promised double-count and was
corrected to actually contain the defect):

| Program | Documented | Executed |
|---|---|---|
| greeting.cpp | two fixed lines | match |
| workbench.cpp | 8 expression values (14, 20, 3, 2, 3.4, 6, 11, 4) | match |
| truncating_totals.cpp (bug-hunt) | wrong totals 3750 / 39 | match |
| reversed_ladder.cpp (bug-hunt) | 95 → D (wrong branch) | match |
| missing_update.cpp (bug-hunt) | infinite `0 0 0…` (run under timeout) | match |
| digit_reversal.cpp | 907 → 709 | match |
| monolith.cpp | rect 12.00, circle 12.57, tri 7.50 | match |
| failed_swap.cpp (bug-hunt) | 5 9 (swap fails) | match |
| off_by_one.cpp (bug-hunt) | not executed — contains an out-of-bounds write (UB); trace-only by design | n/a (stated in file header) |
| border_double_count.cpp (bug-hunt, fixed) | 60 double-count vs correct 40 | match (60) |
| word_count_naive.cpp (bug-hunt) | "the   cat" → 4 | match |
| hazards_guards.cpp | null-guard path, 42, 7, null-after-delete | match |
| raw_vs_vector.cpp | raw sum 55 = vector sum 55 | match |
| robust_read.cpp | good file → 3 loaded / 2 skipped / avg 85; missing → exit 2; no args → usage, exit 1 | match |
| account_skeleton.cpp | 1 500 / 0 500 / 1 300 (invariant holds) | match |

## 5. Memory-safety honesty — **PASS**

- No starter file exhibits undefined behavior **without labeling**:
  `off_by_one.cpp` (out-of-bounds write) and `binary_search_bug.cpp`
  (out-of-bounds read) carry "READ, DO NOT RUN YET" headers and are
  paper-trace exercises; they were compiled (both compile clean) but
  deliberately not executed.
- Labs 13–14 teach hazards (leak, use-after-delete, double-delete) with
  the guard pattern (null-out after delete) AND the course-preferred
  RAII alternative (`raw_vs_vector.cpp` shows both side by side; Lab 14's
  independent task rebuilds the same program with `std::vector` and
  compares).

## 6. Student/instructor separation — **PASS**

- TA checklists live in `instructor_notes/` and carry the restricted
  notice linking `instructor/ACCESS_CONTROL.md`; manuals and starter code
  contain no answers to the independent tasks or the bug files' fixes.
- `labs/resources/` holds only neutral templates (submission, debug log).

## 7. Links and repository integrity — **PASS**

- `bash tools/check_links.sh` → **OK: all relative markdown links
  resolve** (includes the new `docs/LAB_AUDIT.md` referenced by every
  starter README).
- Changes confined to `labs/` and `docs/` (this report + changelog
  entry); no files outside the course directory modified; no build
  artifacts left in the repository.
- Nothing committed or pushed (per task instruction).

## 8. Defects found and fixed during the audit

1. **Lab 10 bug file lacked its bug** — the border-sum starter computed
   the correct 40 (its loops already excluded corners), contradicting its
   own documentation. Rewritten to contain the actual corner double-count
   (verified output 60); documentation updated.
2. **Stale-binary false alarm** in the first build harness run (see § 3);
   re-run with fresh binaries; no source defect.
3. Series README typos (duplicated table fragment, "Lids") caught and
   fixed immediately after writing.

---

## Verdict

**PASS** on all eight checks. The series delivers exactly 16 lecture-
aligned labs with the full 13-section contract, compilable-and-verified
starter code, honest bug-hunt files (including one repaired during the
audit), explicit memory-safety explanations, and clean
student/instructor separation.
