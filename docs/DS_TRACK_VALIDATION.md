# Data-Science Track Validation Report

**Scope:** `examples/data-science/` (9 programs + README + extensions),
`exercises/data-science/` (18 exercises, PF-DS-01…18 + 7 datasets),
`case-studies/data-science.md` (8 projector cases),
`instructor/examples_data_science/`, `instructor/exercises_data_science/`,
`instructor/case_studies/ds_solutions.md`.
**Method:** GCC 16.2 compile-and-execute harness for every program and the
consolidated solutions file; independent Python cross-computation of every
dataset's statistics; automated ID/structure/field checks; link checker.
Date: 2026-09-18.

---

## 1. Mathematical correctness — **PASS**

Every statistic's expected value was computed independently (Python) and then
matched against the C++ execution:

| Statistic | Dataset | Independent value | C++ result |
|---|---|---|---|
| mean (18 values) | temperatures.txt | 374.4/18 = 20.7944… → 20.8 | 20.8 ✓ |
| count strictly above mean | temperatures.txt | 6 | 6 ✓ |
| frequency table + relatives | survey_ratings.txt | 35 valid: 3/4/6/14/8; rel(4)=0.40 | matched ✓ |
| class identity | readings_na.txt | 11 loaded + 2 missing + 2 invalid = 15 lines | ✓ |
| mean of loaded | readings_na.txt | 231.5/11 = 21.0455 → 21.0 | 21.0 ✓ |
| mean/max/owner | scores.csv | 585/7 = 83.5714 → 83.57; max 100 Jade | ✓ |
| group means | students.txt | Ana (3.4+3.9+3.6)/3 = 3.6333 → 3.63 | 3.63 ✓ |
| mean/median/usable % | messy_grades.txt | 74.92 / 79.00 / 65.0 % | ✓ |
| population variance | `2 4 4 4 9 4` | Σ(x−4.5)²/6 = 4.5833 → 4.58, std 2.14 | 4.58 / 2.14 ✓ |
| weighted mean | `90·2+80+70` / 4 | 82.50 | 82.50 ✓ |
| empirical proportions | seed 42, n = 60 000 | all six faces within 0.1653–0.1683 of 1/6 | ✓ |

Two draft arithmetic errors in exercise *specs* were caught by this cross-check
and fixed before delivery: DS-08's variance (4.92 → **4.58**) and DS-10's
weighted mean (82.00 → **82.50**; 240/4, not /3).

## 2. Numerical outputs tested — **PASS**

- All **9 example programs** compile zero-warning and were executed; verified
  runs include: mean/median odd+even, `no data` on empty, sentinel-first
  `no data`, frequency with invalid exclusion (relative sums to 1.00), mode
  tie disclosure, sort with swap-cost line and top-k, pipeline class counts
  with a blank line ignored, simulation convergence (0.2333 @ n=60 →
  0.1663–0.1683 @ n=60 000).
- Consolidated instructor solutions file compiles zero-warning and executes:
  DS-01 0.60 · DS-02 4/22/18 · DS-03 404/80.80 · DS-05 88.0 & 25.0 ·
  DS-07 compact + dropped 2 · DS-08 4.58/2.14 · DS-10 82.50 ·
  DS-11 ranks `2 3 3 1 5` · DS-12 `tied: 4 7` · DS-16 4.00/6.00/8.00 ·
  DS-17 peak sum2 = 7.
- Exit codes: pipeline `readings_na.txt` → 0; missing file → 2; usage → 1.

## 3. Input assumptions verified — **PASS**

- Every exercise states its input contract (n-first, sentinel, or file format)
  and every dataset matches it (formats hand-checked against the parsers).
- The pipeline ignores blank lines explicitly; a blank line present in
  `readings_na.txt` proves the rule (15 counted, 16 physical lines).
- istringstream + leftover-char check rejects `abc` *and* `21.5x`; NA is
  classified before numeric parsing in DS-09/DS-15 and the pipeline.
- Missing-file behavior verified by execution (`cannot open`, exit 2); the
  example was hardened from `if (!in)` to `if (!in.is_open())` after the
  first run showed a platform quirk — the reliable form is taught.

## 4. Alignment with beginner C++ concepts — **PASS**

Feature sweep across all DS code and exercise requirements: only `iostream`,
`fstream`, `sstream`, `string`, `iomanip`, `cmath` (`sqrt` — taught with the
√n prime bound), `cctype`-free, `<random>` (`mt19937` +
`uniform_int_distribution`, DS-17/examples only), arrays, `struct`,
`std::vector` (DS-14/18, from M14), functions with contract comments, and the
L24 sorts. **Absent:** templates, lambdas, STL algorithms (`std::sort`
explicitly banned in the items that sort), smart pointers, classes beyond
none (structs only), exceptions, auto, range-for beyond taught forms,
parallelism, and any third-party or ML library.

## 5. No exercise exceeds course knowledge — **PASS**

Prerequisite chains checked programmatically: every item cites
`Prerequisites` (18/18) referencing only earlier DS items or course
lectures; difficulty ladder measured: Beginner 3 → Foundational 4 →
Intermediate 6 → Advanced 5 (DS-18 labeled Advanced Introductory). Items
needing M14+ material (vectors/structs/files) sit at Advanced level only.

## 6. IDs, duplication, separation — **PASS**

- `PF-DS-01…18`: 18 unique, contiguous, **zero overlap** with the 152 `PF-E`
  ids; case studies use `PF-DS-CS-1…8`, disjoint from `PF-CS-001…108`.
- Deliberate non-duplication is documented in both READMEs: main bank owns
  mechanics-once items (PF-E-067 mean, PF-E-075 histogram, PF-CS-056 CSV);
  DS items go further (median parity rules, weighted mean, variance, NA
  policy, group-by, simulation, capstone).
- All three instructor files carry INSTRUCTOR-ONLY banners; no solutions in
  student-facing files; datasets are student-visible with *expected values*
  (not solutions) documented.
- Link checker: **OK — 601 relative links resolve** (two depth fixes applied
  in instructor READMEs).

## 7. Deliverable completeness — **PASS**

| Required | Delivered |
|---|---|
| Instructor examples | 9 verified programs + restricted notes |
| Student exercises | 18 items with formulas-first, edge cases, hints |
| Case studies | 8 projector cases + restricted discussion guide |
| Suggested extensions | `examples/data-science/extensions.md` (11 + named bridges) |
| Testing datasets | 7 files with documented defects + expected values |

## 8. Repository integrity — **PASS**

Changes confined to: `examples/data-science/`, `exercises/data-science/`,
`case-studies/data-science.md`, `instructor/{examples_data_science,
exercises_data_science,case_studies/ds_solutions.md}`, pointer lines in
`examples/README.md` + `exercises/README.md`, `docs/CHANGELOG.md`, this
report. Build scratch removed; nothing committed or pushed.

---

## Overall: **PASS**

| Check | Verdict |
|---|---|
| Mathematical correctness (independent cross-check) | PASS (2 spec errors fixed) |
| Numerical outputs executed & matched | PASS |
| Input assumptions verified (incl. exit codes, NA, blanks) | PASS |
| Beginner-C++ alignment (feature sweep) | PASS |
| No beyond-course knowledge (prereq graph) | PASS |
| IDs / duplication / separation | PASS |
| Deliverables complete | PASS |
| Links & integrity | PASS (601/601) |
