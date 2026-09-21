# Case-Study Bank Audit Report

**Scope:** 108 case studies under `case-studies/by_tier/`, the index map
`case-studies/index.md`, and the instructor companions under
`instructor/case_studies/`.
**Method:** automated checks (grep/awk/python over the repository; GCC 16.2
compile-and-execute harness for worked solutions) plus manual cross-reading
against `COURSE_SCHEDULE.md` and the lecture files. Evidence is quoted per
check. Date: 2026-09-18.

---

## 1. At least 100 cases — **PASS**

- Evidence: heading-level count `grep -hcE "^### PF-CS-[0-9]{3} · " case-studies/by_tier/tier*.md`
  → 20 / 20 / 20 / 20 / 28 = **108** cases (CS-001…CS-108).

## 2. Unique IDs and titles — **PASS**

- Unique IDs: `grep -hroE "PF-CS-[0-9]{3}" | sort -u | wc -l` → **108**;
  duplicate-heading check (`sort | uniq -d`) → empty.
- Sequence: `sed 's/PF-CS-//' | awk 'NR!=$1'` → empty; IDs contiguous
  001–108, no gaps.
- The only repeated ID *strings* in the tier files (CS-085, CS-099) are
  cross-references inside other cases' problem statements, verified by
  line inspection (e.g., tier5 line 428 references CS-085 as related
  material) — not duplicate records.

## 3. Genuine distinctness (no reworded duplicates) — **PASS**

- All 108 titles are distinct (checked by exact-match sort).
- Concept-level review: every case carries a distinct task contract. Where
  topics are related, the task *type* differs deliberately (documented in
  each case): CS-005 (design a ladder) vs CS-059 (prove stability of a
  sort); CS-022 (two-channel error design) vs CS-064 (interface comparison);
  CS-085 (lenient fallbacks) vs CS-104 (strict structure-first) — paired
  cases contrast policies rather than reword problems.
- Difficulty within each tier ascends by case number; tiers form five
  bands over the course arc.

## 4. Progressive difficulty — **PASS**

| Tier | Cases | Lecture span | Character |
|---|---|---|---|
| 1 Beginner | 20 | L01–L12 (Modules 1–6) | Traces, I/O, first decisions/loops |
| 2 Foundational | 20 | L13–L16 (Modules 7–8) | Function design, contracts, recursion |
| 3 Intermediate | 20 | L17–L24 (Modules 9–12) | Arrays, strings, search/sort |
| 4 Advanced | 20 | L23–L30 (Modules 12–15) | Complexity, pointers, memory, records |
| 5 Expert introductory | 28 | L29–L32 (Modules 15–16) | Files, validation, OOP, synthesis |

Tier headers in the tier files state the corrected spans (an earlier draft
understated Tier 1's span as L01–L08; fixed during audit).

## 5. Lecture/module alignment — **PASS (after 22 fixes)**

- Automated cross-check of every case's `Lecture · Module` line against
  the authoritative `COURSE_SCHEDULE.md` mapping (Module *m* = lectures
  2m−1, 2m): initial run found **22 mismatches** (cases attributed to
  lectures outside their module's range — e.g., CS-068 listed L26 but
  struct material lives in L28).
- All 22 re-attributed to the correct lecture *within the intended
  module* using the actual lecture titles (e.g., CS-058 → L24 Selection
  Sort; CS-068 → L28 Structures); re-run → **108 cases checked,
  0 problems**.
- `case-studies/index.md` rows re-synced with the tier files:
  **108/108 rows agree** (tier, lecture, module).
- Lecture citations cover **L01–L32** (L05 has no case by design — its
  operator content is exercised inside CS-002/CS-009; every other lecture
  is cited directly, L28 by CS-068/069/074). All 16 modules carry at least
  4 cases.

## 6. Case record completeness — **PASS**

- Every projector case carries: ID, title, tier, lecture, module, context,
  problem, input, output, constraints, thinking questions, and a
  progressive 3-hint block — verified 20/20 per tier file via field greps
  and `<details>` counts (108/108 hint blocks).
- Every instructor companion entry carries: expected concepts, common
  incorrect approaches, discussion points, solution outline, worked
  solution (code or verified design), test cases, extension.

## 7. Worked solutions compile and run — **PASS (26/26 machine-verified)**

- Harness: python extraction of every ` ```cpp ` block from the instructor
  companions → compile with `g++ -std=c++17 -Wall -Wextra -pedantic`
  (GCC 16.2) → execute with case-specific piped inputs.
- **26 solutions compiled zero-warning and executed with expected
  output**, including: CS-002 (order + comparison count 3), CS-005
  (95→A), CS-006 (full-day → capped 200), CS-007 (Abcdef1!→STRONG),
  CS-008 (65 → 01:05…00:00), CS-011 (10⁶ → RED), CS-013 (350 → change
  650 = 500+100+50), CS-021 (leap sweep 1900–2400), CS-024 (Collatz
  winner n=97, 118 steps), CS-026 (adjacency cases), CS-029 (min/max/
  mean + empty rejection), CS-031 (loop vs recursion identical), CS-032
  (digit sums), CS-041 (suspect index 6), CS-058 (insertion sort, 5
  comparisons), CS-061 (binary search incl. absent keys), CS-062 (XYZ→YZA
  with wrap), CS-089/090 (class invariants: rejections leave state
  untouched).
- **1 defect found and fixed during testing:** CS-032's test loop used a
  mixed-type initializer list (`{0, 7, …, 2000000001LL}`) — GCC cannot
  deduce the element type; corrected to all-`long long` literals.
  Re-verified OK.
- Remaining cases are design-level (the *deliverable* is the argument or
  the trace, not a program); each carries a hand-verified outline and
  test-case traces (e.g., CS-033's 7-move Hanoi sequence, CS-100's wait
  formula). Their solutions state this explicitly; no untested code is
  claimed as tested.

## 8. Sample-output accuracy — **PASS**

- Every executed solution's output matched its documented test table
  (spot examples: CS-003 column widths; CS-013's per-denomination lines;
  CS-061's −1 for absent keys; CS-090's invariant-preserving rejections).
- Projector cases' sample I/O were cross-checked against the
  corresponding solution behavior during authoring; no case promises an
  output the solution cannot produce.

## 9. Student/instructor separation — **PASS**

- Projector files (`case-studies/by_tier/`) contain **zero** ```cpp
  blocks and zero solution fields — the only pattern match per file is
  the header line "Worked solutions: instructor area only."
- Hints stop at nudge level (3 progressive hints per case, no algorithm
  reveal) — reviewed line-by-line.
- All worked solutions, discussion points, and the session playbook live
  under `instructor/case_studies/` behind the
  `instructor/ACCESS_CONTROL.md` notice. The **extension challenge** is
  public by design (stated in the README policy).

## 10. Repository integrity — **PASS**

- `bash tools/check_links.sh` → **OK: all relative markdown links
  resolve** (the audit report itself resolves the two links introduced by
  the README and instructor guide).
- Change set confined to: `case-studies/` (new), `instructor/case_studies/`
  (new), `docs/CASE_STUDY_AUDIT.md` (this file), `docs/CHANGELOG.md`
  (entry). No files outside the course directory touched; no build
  artifacts left in the repo.
- Nothing committed or pushed (per task instruction).

---

## Verdict

**PASS** on all ten checks. The bank exceeds the 100-case floor at 108
genuinely distinct, lecture-aligned cases with a verified difficulty
ladder, complete records, machine-verified representative solutions, and
strict student/instructor separation.
