# Lecture-Timing and MC-23 Verification Report

**Scope:** focused verification of (1) the misconception-bank MC-23 example (compile + failure path + happy path) and (2) the time-allocation totals of all 32 lecture delivery plans in `instructor/lecture-delivery/`.
**Method:** every timing total was **recalculated from its individual activity rows** (markdown table rows parsed with a `^| label | N |` pattern, `Total` rows excluded and compared separately); MC-23 was compiled and executed in a disposable temp sandbox. No result below is assumed from any displayed total.
**Date:** 2026-09-19.

---

## Part 1 · MC-23 verification

### 1.1 Source and documentation

| Item | Value |
|---|---|
| Bank entry | `instructor/misconception-bank/misconception_bank.md`, section `## MC-23 · File-open failure unchecked` |
| Quick-reference row | `instructor/COMMON_MISCONCEPTIONS.md` line 38 (MC-23, L29) — consistent |
| Cross-references | `DEBUGGING_GUIDE.md`, `INSTRUCTOR_CHECKLISTS.md`, `LAB_FACILITATION_GUIDE.md` all reference MC-23 for the open-check guard — consistent |
| Intended failure path | missing file → `if (!in)` guard → `std::cerr` message → `return 1` |
| Intended happy path | file present → `getline` loop echoes every line → `return 0` |
| Required input files | none for the failure path; any readable text file named `no_such_file.txt` for the happy path (created as a temp test file only) |

### 1.2 Compilation

- **Command:** `g++ -std=c++17 -Wall -Wextra -pedantic mc23_guarded.cpp -o mc23_guarded` (the repository's documented contract flags; GCC 16.2.0, Winlibs MinGW-w64)
- **Result:** **exit 0, zero warnings, zero errors.** The shipped example needed **no modification** — no defect was found.
- A second variant with the guard stripped (the entry's own questioning strategy: *"Run it without the guard"*) also compiled clean under the same flags.

### 1.3 Missing-file (failure-path) test

| Aspect | Observed |
|---|---|
| Method | run compiled binary in a directory containing no `no_such_file.txt` |
| Exit code | **1** (non-zero, as designed) |
| Output | `ERROR: cannot open no_such_file.txt` on **stderr** |
| Expected result | non-zero exit + visible error message — **matches** |
| Appropriate handling | yes: the guard detects the failed stream state before any read, reports to stderr (not stdout), and signals failure via the exit code |

### 1.4 Guard-stripped control test (the misconception, demonstrated)

| Aspect | Observed |
|---|---|
| Method | same binary with the guard removed (the entry's questioning demo) |
| Exit code | **0** |
| Output | **none** — silent success |
| Interpretation | exactly the misconception MC-23 teaches: a failed stream reads as no-ops, the loop never runs, and the program "succeeds" having done nothing. The control experiment confirms the entry's claim is technically accurate. |

### 1.5 Happy-path test

| Aspect | Observed |
|---|---|
| Test setup | temp file `no_such_file.txt` created with three lines (`alpha`, `beta`, `gamma`) — the only test file created |
| Method | run the same guarded binary with the file present |
| Exit code | **0** |
| Output | `alpha`, `beta`, `gamma` — each on its own line |
| Expected result | file echoed line-by-line, exit 0 — **matches** |

### 1.6 Cleanup

All temporary artifacts removed: both `.cpp` sources, both binaries, the test data file, and the `mktemp` working directory (verified removed). **No temporary files remain; no repository file outside this report was created or modified for the MC-23 tests.**

**MC-23 verdict: PASS — verified, no defect, example unchanged.**

---

## Part 2 · Lecture timing verification (all 32 plans)

### 2.1 Method and honesty notes

- Plans live in 16 files; each `## LNN` section holds one 21-field plan ending in a segment table. Every row was parsed and summed per lecture; printed totals were **not trusted** (in several files the printed total was wrong while the rows were right, and vice versa).
- Transparency: an early quick parse overstated the failure set (it reported L17/L21/L31 as failing and mis-summed L16/L32). The robust re-parse — full-table dumps eyeballed against the script output — proved those four were already correct. All findings and corrections below rest on the verified numbers only.
- Realism check: totals equal exactly 120; segment sizes stay in pedagogically reasonable bands (5–30 min); quiz-day rows carry the 15-minute quiz from `quizzes/README.md` ("Sixteen 15-minute module quizzes"); exam-day rows match the authoritative `instructor/exams/PAPER_ASSEMBLY.md` durations (midterm 100 min, final 180-min blueprint).

### 2.2 Verification table (final state, after corrections)

Total row count = timed activities (the `Total` line excluded). All 32 recalculated totals equal **exactly 120**.

| L | Lecture title | File | Timed rows | Total | Status | Note |
|---|---|---|---|---|---|---|
| 01 | What Is a Program? Computers, Algorithms, and the C++ Toolchain | lecture-delivery/m01_introduction.md | 8 | 120 | PASS | already correct |
| 02 | Anatomy of a C++ Program | lecture-delivery/m01_introduction.md | 8 | 120 | PASS | already correct |
| 03 | Variables, Built-in Types, and Initialization | lecture-delivery/m02_variables_io.md | 8 | 120 | PASS | already correct |
| 04 | Console I/O with `cin`/`cout`: Streams, Formatting, and Input Validation Basics | lecture-delivery/m02_variables_io.md | 8 | 120 | PASS | already correct |
| 05 | Arithmetic Operators, Precedence, and Integer vs Floating-Point Division | lecture-delivery/m03_operators.md | 8 | 120 | PASS | already correct |
| 06 | Type Conversions, Compound Assignment, and Mixed-Type Expressions | lecture-delivery/m03_operators.md | 8 | 120 | PASS | **corrected** (was 115) |
| 07 | `if`, `if/else`, and Nested Selection | lecture-delivery/m04_decisions.md | 8 | 120 | PASS | already correct |
| 08 | `switch`, Multi-Way Selection, and the Conditional Operator | lecture-delivery/m04_decisions.md | 9 | 120 | PASS | **corrected** (was 110) |
| 09 | `while` and `do-while`: Sentinel and Input-Controlled Loops | lecture-delivery/m05_loops.md | 8 | 120 | PASS | already correct |
| 10 | `for`, Nested Loops, `break`/`continue`, and Loop Patterns | lecture-delivery/m05_loops.md | 9 | 120 | PASS | **corrected** (was 110) |
| 11 | From Problem to Algorithm: IPO Charts, Decomposition, Pseudocode, Flowcharts | lecture-delivery/m06_algorithms.md | 8 | 120 | PASS | **corrected** (was 115) |
| 12 | Desk-Checking, Trace Tables, and Test-Case Design | lecture-delivery/m06_algorithms.md | 9 | 120 | PASS | **corrected** (was 110) |
| 13 | Defining and Calling Functions: Parameters, Return Values, `void` | lecture-delivery/m07_functions.md | 8 | 120 | PASS | already correct |
| 14 | Scope, Lifetime, and Program Decomposition with Functions | lecture-delivery/m07_functions.md | 9 | 120 | PASS | **corrected** (was 110) |
| 15 | Function Overloading, Default Arguments, and Reference Parameters | lecture-delivery/m08_advanced_functions.md | 8 | 120 | PASS | already correct |
| 16 | Debugging Methodology and Midterm Review · MIDTERM EXAM | lecture-delivery/m08_advanced_functions.md | 4 | 120 | PASS | **corrected** (was 125) |
| 17 | 1-D Arrays: Declaration, Indexing, Bounds, and the Array–Memory Model | lecture-delivery/m09_1d_arrays.md | 8 | 120 | PASS | already correct |
| 18 | Array Algorithms: Fill, Print, Sum/Average, Min/Max, Count, Linear Search | lecture-delivery/m09_1d_arrays.md | 9 | 120 | PASS | **corrected** (was 110) |
| 19 | 2-D Arrays: Declaration, Row/Column Indexing, Nested Traversal | lecture-delivery/m10_2d_arrays.md | 8 | 120 | PASS | already correct |
| 20 | 2-D Operations: Row/Column Totals, Matrix Addition, Transpose, Passing to Functions | lecture-delivery/m10_2d_arrays.md | 9 | 120 | PASS | **corrected** (was 110) |
| 21 | Characters and Strings: `char` Processing and the `std::string` Class | lecture-delivery/m11_strings.md | 8 | 120 | PASS | already correct |
| 22 | String Algorithms: Reverse, Palindrome, Counting, Word Processing | lecture-delivery/m11_strings.md | 9 | 120 | PASS | **corrected** (was 110) |
| 23 | Linear Search vs Binary Search: Correctness and Comparisons | lecture-delivery/m12_search_sort.md | 8 | 120 | PASS | already correct |
| 24 | Selection Sort and Bubble Sort: Tracing, Swapping, Complexity Intuition | lecture-delivery/m12_search_sort.md | 9 | 120 | PASS | **corrected** (was 110) |
| 25 | Pointers: Addresses, `&`, `*`, `nullptr`, and Pointer Arithmetic | lecture-delivery/m13_pointers.md | 8 | 120 | PASS | already correct |
| 26 | References, Pass-by-Value vs Pass-by-Reference, and Arrays as Pointers | lecture-delivery/m13_pointers.md | 9 | 120 | PASS | **corrected** (was 110) |
| 27 | Dynamic Memory: `new`, `delete`, Leaks, Dangling Pointers, `std::vector` as Managed Memory | lecture-delivery/m14_dynamic_structs.md | 8 | 120 | PASS | **corrected** (was 95) |
| 28 | Structures: `struct` Definition, Members, Nesting, Arrays/Files of Records | lecture-delivery/m14_dynamic_structs.md | 9 | 120 | PASS | **corrected** (was 110) |
| 29 | Text Files with `ifstream`/`ofstream`: Reading, Writing, Appending, EOF | lecture-delivery/m15_files.md | 8 | 120 | PASS | already correct |
| 30 | Robust Programs: Stream State, Error Checking, Recovery Strategies | lecture-delivery/m15_files.md | 9 | 120 | PASS | **corrected** (was 110) |
| 31 | Classes: Data + Behavior, Constructors, Encapsulation | lecture-delivery/m16_oop.md | 8 | 120 | PASS | already correct |
| 32 | From Structs to Classes, Course Synthesis · FINAL EXAM | lecture-delivery/m16_oop.md | 3 | 120 | PASS | **corrected** (was 135) |

**Result: 32/32 PASS.** No missing, duplicated, ambiguous, or non-numeric durations remain in any table.

### 2.3 Lectures requiring corrections — exact discrepancies and fixes

Root cause: the as-built tables deviated from the hub's own variant rules (`LESSON_DELIVERY_GUIDE.md` § 1/§ 3: quiz-day takes 10 from Independent + 5 from Guided with Concept 30 intact; case-heavy = Guided 15 · Case 20; exam days per `PAPER_ASSEMBLY.md`).

| Lecture | Was | Defect | Fix applied |
|---|---|---|---|
| L06, L11 | 115 | "case-heavy variant" trimmed Guided *and* Independent by 5 each instead of Guided only | restored true case-heavy split: Guided 15 · Case 20 · Independent 20; prose markers updated |
| L08, L10, L12, L14, L18, L20, L24, L26, L28, L30 | 110 | quiz-day trim wrongly cut Concept 30→20 (the hub rule trims practice only) | Concept restored to 30 (sub-topic splits rebalanced in prose); quiz 15 retained |
| L22 | 110 | quiz-day ∧ case-heavy hybrid under-allocated Concept | Concept 25 hybrid (Guided 15 · Case 20 · Independent 10 · Quiz 15 kept) |
| L16 | 125 | exam row 90 vs authoritative 100-min midterm blueprint; ticket+summary double-counted the close | Exam 100 · take-up 10 · merged 5-min close; prose aligned to `PAPER_ASSEMBLY.md` |
| L27 | 95 | a second, unrecorded "case-heavy trim" hit Concept, Guided, and Independent | canonical case-heavy restored: Concept 30 · Guided 15 · Case 20 · Independent 20 |
| L32 | 135 | exam row "120\*" vs 180-min blueprint vs 2-hour slot; ticket + summary separate | 110-min in-slot sitting (forms' minimum-per-section selection) · merged 5-min post-exam close; footnote rewritten: 180-min blueprint authoritative, in-slot split **[CONFIGURABLE]** |

Hub table updated to match: quiz-day now documented as "Concept 30 · Guided 15 · Independent 10 · Quiz 15", exam rows carry the corrected durations, case-heavy lists L06/L11/L27, and the L22 hybrid is listed explicitly.

---

## Part 3 · Files modified

Only timing-consistency files were touched; no validated course content, objectives, CLOs, assessment policy, or schedule was changed, and `instructor/misconception-bank/misconception_bank.md` was **not** modified (MC-23 passed as shipped).

1. `instructor/lecture-delivery/m03_operators.md` (L06)
2. `instructor/lecture-delivery/m04_decisions.md` (L08)
3. `instructor/lecture-delivery/m05_loops.md` (L10)
4. `instructor/lecture-delivery/m06_algorithms.md` (L11, L12)
5. `instructor/lecture-delivery/m07_functions.md` (L14)
6. `instructor/lecture-delivery/m08_advanced_functions.md` (L16)
7. `instructor/lecture-delivery/m09_1d_arrays.md` (L18)
8. `instructor/lecture-delivery/m10_2d_arrays.md` (L20)
9. `instructor/lecture-delivery/m11_strings.md` (L22)
10. `instructor/lecture-delivery/m12_search_sort.md` (L24)
11. `instructor/lecture-delivery/m13_pointers.md` (L26)
12. `instructor/lecture-delivery/m14_dynamic_structs.md` (L27, L28)
13. `instructor/lecture-delivery/m15_files.md` (L30)
14. `instructor/lecture-delivery/m16_oop.md` (L32)
15. `instructor/LESSON_DELIVERY_GUIDE.md` (variant table)
16. `instructor/revision/LECTURE-TIMING-AND-MC23-VERIFICATION-REPORT.md` (this report — new)

## Part 4 · Commands and scripts executed

1. **Timing recalculation** (final version): Python heredoc — split each `m*_*.md` on `^## (L\d+)`, regex `^\|\s*(.+?)\s*\|\s*(\d+)\s*\|\s*$` per row, exclude `Total` rows from the sum, compare to 120. Final output: `32 PASS / 0 FAIL / 32 total`.
2. **Full-table dumps** for all 32 lectures (parsed rows printed for manual cross-check against the script).
3. **Authority greps:** `instructor/exams/PAPER_ASSEMBLY.md` ("Midterm blueprint (100 minutes · 50 marks)", "Final blueprint (180 minutes · 100 marks)"), `quizzes/README.md` ("Sixteen 15-minute module quizzes"), `lectures/week_08/lecture_16.md` and `lectures/week_16/lecture_32.md` headers, `exams/final/review_guide.md` ("180 minutes · 100 marks"), `LESSON_DELIVERY_GUIDE.md` § 1/§ 3 variant rules.
4. **MC-23 verification chain:** temp-sandbox source extraction → `g++ -std=c++17 -Wall -Wextra -pedantic` (both variants, zero warnings) → missing-file run (exit 1, stderr message) → guard-stripped control run (exit 0, silent) → happy-path run with a 3-line temp file (exit 0, all lines echoed) → artifact and sandbox cleanup.
5. **Title extraction** for the table above (L25's title taken from `lectures/week_13/lecture_25.md`).

## Part 5 · Remaining warnings and limitations

1. **Pre-existing exam-duration conflict — documented, not silently changed.** The authoritative `PAPER_ASSEMBLY.md` blueprint states **midterm 100 min / final 180 min**, but the *validated lecture notes* still say "**MIDTERM (90 min)**" (`lectures/week_08/lecture_16.md`) and "**FINAL EXAM (120 min)**" (`lectures/week_16/lecture_32.md`). Under the operating rules (validated lecture content must not be changed), the delivery guides were aligned to the blueprint and this conflict is flagged for the next course-content revision.
2. **L32 structural tension (marked [CONFIGURABLE] in place):** a 180-minute blueprint cannot fit a 2-hour slot; the plan documents a 110-minute in-slot sitting plus an institution-scheduled post-exam session. Institutions running the full 180-minute session should absorb the slot.
3. Realism attestation: all totals equal 120 with segment sizes in reasonable bands; beyond the arithmetic and the authority cross-checks, no live classroom trial has been conducted (no claim of classroom validation is made).

## Part 6 · Final status

**PASS WITH WARNINGS**

- MC-23: compiled zero-warning under the course contract; failure path, misconception-control path, and happy path all executed and matched the documented behavior; no defect; example unchanged.
- Lecture timing: 32/32 plans recalculate to exactly 120 minutes after 16 documented, rule-based corrections; hub variant table reconciled.
- Warnings are limited to the documented (pre-existing) exam-duration conflict in the validated lecture notes and the L32 [CONFIGURABLE] scheduling note above.
