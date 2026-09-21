# Exercise Bank Validation Report

**Scope:** the 152-exercise collection under `exercises/by_topic/` plus the
13 instructor solution files under `instructor/exercise_solutions/`.
**Method:** automated checks (grep/awk over the repository, GCC 16.2 compile
runs, piped-input execution) plus manual cross-reading against the lecture
plans. Evidence is quoted per check. Date: 2026-09-18.

---

## 1. At least 150 exercises — **PASS**

- Evidence: `grep -hroE "PF-E-[0-9]{3}" exercises/by_topic | sort -u | wc -l`
  → **152** unique IDs (`PF-E-001` … `PF-E-152`).
- Sequence check (`sed 's/PF-E-//' | awk 'NR!=$1'`) → empty: **no gaps**.

## 2. Unique IDs, no duplicates — **PASS**

- `sort | uniq -c | awk '$1>1'` → no output: **zero duplicate IDs**.
- Duplicate-title check (normalized `###` headings through `uniq -d`) →
  empty: **zero duplicate titles**. Every problem statement was authored as
  a distinct task (distinct I/O contracts, not reworded variants); the
  bank's own topic files state the intended contrast (e.g., T03 tasks are
  about loop mechanics, T04 tasks are algorithmic number problems).

## 3. Topic distribution — **PASS** (all 12 required topics)

| Topic file | Exercises |
|---|---|
| T01_variables_calculations | 13 |
| T02_conditions | 13 |
| T03_loops | 16 |
| T04_number_problems | 11 |
| T05_functions | 12 |
| T06_arrays | 13 |
| T07_strings | 12 |
| T08_searching_sorting | 11 |
| T09_pointers_references | 10 |
| T10_structures | 10 |
| T11_file_handling | 10 |
| T12_classes_objects | 21 |
| **Total** | **152** |

## 4. Difficulty ladder — **PASS**

All four levels appear in **every** topic file (verified via
`grep -oE "\*\*Difficulty:\*\* …" | sort | uniq -c` per file); per-topic
ladders run 🟢 Beginner → 🔵 Foundational → 🟡 Intermediate → 🔴 Advanced
Introductory, and within each file the IDs ascend with difficulty. Global
totals (measured): 36 Beginner, 41 Foundational, 50 Intermediate, 25
Advanced Introductory — a beginner-heavy base rising to synthesis-level
tasks (led by T12's 9 Advanced Introductory OOP exercises).

## 5. Record completeness — **PASS**

Every record carries: ID, title, difficulty, lecture, outcome codes,
prerequisites, problem statement, input requirements, output requirements,
constraints (where relevant), sample I/O (where useful), and hints.
Sampled counts on `T05_functions.md`: 12/12 records with Difficulty,
Prerequisites, Problem, Input, Output, Hint, and Sample lines.

## 6. Solutions compile and run — **PASS** (13/13, zero warnings)

- Compiler: GCC 16.2 (WinLibs MinGW-w64), contract
  `g++ -std=c++17 -Wall -Wextra -pedantic`.
- Evidence: all 13 files (`T01`…`T12b`) compile with **no diagnostics**;
  the 4 issues found on the first pass were fixed:
  1. `e133` referenced `Counter` unqualified (moved to `e132::Counter`).
  2. `T12` missing `#include <vector>` (Playlist member).
  3. Unused-variable warnings in e090/e106/e131 (made meaningful or
     intentionally silenced with a comment).
  4. e127's CSV parser required a space before the comma; rewritten to
     `find(',')` + substring stream parsing (true CSV).
- Every exercise namespace was **executed**. Representative verified
  outputs: Collatz 871 → 178 steps, peak 190996; harmonic H with
  ε=0.1 → 10 terms, 2.928968; median/Q1/Q3 of {4,5,8,15,16,23,42} →
  15.0 / 5.0 / 23.0; dedup of 10 values → 7 unique; CSV `12,7,,9` →
  4 tokens incl. empty; skip-and-report → `loaded 4, skipped 2,
  average: 83.00`; Fraction 1/6 + 1/3 = 1/2; inventory sell/oversell
  verdicts; Time24 23:59 → 00:00 wrap.
- Earlier runs misfired only from **wrong test input**, not program
  defects; programs were re-run with the record's specified input formats
  until every demo's output matched its specification (final exit code 0
  on all 13).

## 7. Sample-output fidelity — **PASS**

Executable records state their samples in the solution's output format
(e.g., E-113's column widths, E-118's four report blocks, E-120's
min/max/avg/above line). Each was reproduced exactly in the run logs;
records whose samples are prose (e.g., "prints not found") matched as
documented.

## 8. Student/instructor separation — **PASS**

- `grep -rniE "solution|answer key" exercises/by_topic exercises/README.md`
  → only navigation/policy text ("solutions live in the instructor area…");
  **no solution code** in any student-facing file.
- All 13 solution files live under `instructor/exercise_solutions/` and
  its README repeats the access-control notice
  (`instructor/ACCESS_CONTROL.md`).
- `student/` contains only `README.md` and `GETTING_HELP.md`.

## 9. Repository integrity — **PASS**

- `bash tools/check_links.sh` → **OK: 357 relative markdown links checked,
  all resolve** (3 broken paths introduced during authoring were fixed:
  `../../docs/` ↔ `../docs/` depth errors).
- Changes confined to `exercises/`, `instructor/exercise_solutions/`,
  `exercises/README.md` (rewritten), and `docs/CHANGELOG.md` (new entry);
  no files outside the course directory touched.
- Nothing committed or pushed (per task instruction).

---

## Verdict

**PASS** on all nine checks. The bank meets the 150+ floor with 152
genuinely distinct exercises, complete records, a working four-level
difficulty ladder, and a fully tested instructor solution set kept strictly
separate from student-facing material.
