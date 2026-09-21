# Project 01 · Student Grade Calculator

**Modules 1–8 (Weeks 1–8) · no arrays, no files, no structs — functions are the architecture**
Outcomes: CLO-1…CLO-5 (PF-1…PF-8). Difficulty: ★☆☆☆☆

## 1. Problem description

A tutoring center computes end-of-term grades from three components: **lab
25 %, midterm 35 %, final 40 %**. Their volunteer desk does this by hand and
makes arithmetic errors. Write a console program that processes students one
at a time (an interactive session, not a data file), computes each weighted
average, maps it to a letter grade, and ends the session with a summary of
everyone processed in this run.

## 2. Learning objectives

1. Decompose a small problem into single-purpose functions with contracts.
2. Use reference parameters where a function must return more than one value.
3. Apply decision ladders correctly (descending thresholds).
4. Validate every read at the boundary; distinguish bad data from end-of-run.
5. Distinguish integer counts (int) from weighted measures (double).

## 3. Functional requirements

- FR1 — One student = name (one word), lab, midterm, final (0..100 doubles).
- FR2 — Weighted average printed with exactly 2 decimals:
  `Ayesha 88 79 91 -> 86.05 C+` (see mapping below).
- FR3 — Letter mapping: ≥ 90 A · ≥ 87 A− · ≥ 83 B+ · ≥ 80 B · ≥ 77 B− ·
  ≥ 73 C+ · ≥ 70 C · ≥ 67 C− · ≥ 60 D · else F.
- FR4 — Session loop: process students until the name `DONE` (case-sensitive).
- FR5 — Session summary: students processed, highest average with owner,
  class average, count below 60. Print `no students` if the first entry is DONE.
- FR6 — A grade below 0 or above 100 terminates that student's record with
  message `bad mark for <component>` and does NOT count them in the summary.

## 4. Non-functional requirements

- NFR1 — `main` is an outline: every computation lives in a function.
- NFR2 — Every function has a contract comment (precondition/postcondition).
- NFR3 — Compiles with the course contract, zero warnings.
- NFR4 — No global variables; no arrays (they are Module 9 — a single student
  at a time is the whole point).
- NFR5 — Session summary values come from accumulators updated per student,
  not from re-reading anything.

## 5. Suggested data structures

Per student: five locals in `main` (name + three marks + average). Per
session: four accumulators (count, sum of averages, best average, best name).
The maximum-tracking pattern (init from first value, L17 discipline) is
expected even though arrays are not — accumulate as you go.

## 6. User interaction design

```text
Student (or DONE): Ayesha
lab midterm final: 88 79 91
Ayesha: 86.05 -> C+
Student (or DONE): Bilal
lab midterm final: 105 80 80
bad mark for lab
Student (or DONE): DONE
students: 1  best: Ayesha 86.05  class avg: 86.05  below 60: 0
```

Prompts exactly as shown; no other output lines. One space between fields in
the summary; averages always 2 decimals.

## 7. Input validation requirements

- VR1 — Failed read of any mark (EOF or non-numeric): print `bad input`,
  exit code 1.
- VR2 — Mark out of 0..100: `bad mark for <component>` (lab|midterm|final),
  record rejected, continue the session loop.
- VR3 — Name `DONE` ends the session even mid-line (rest of the line ignored).
- VR4 — No cin/cout inside the letter-mapping function — it takes an average,
  returns a letter; testability is the point.

## 8. Testing plan

| # | Class | Input | Expected |
|---|---|---|---|
| T1 | typical | `Ayesha 88 79 91` | `86.05 -> C+` |
| T2 | boundary | all three marks 90 exactly | `90.00 -> A` |
| T3 | boundary | all three marks 89.999… (use 89.99) | `B+` (>= 90 fails) |
| T4 | even weights | lab 0 midterm 0 final 0 | `0.00 -> F`, counts below 60 |
| T5 | invalid | lab 105 | `bad mark for lab`, not in summary |
| T6 | EOF mid-record | name then EOF | `bad input`, exit 1 |
| T7 | immediate DONE | `DONE` | `no students` |
| T8 | best tracking | Ayesha 86.05 then Bilal 92.50 | best Bilal 92.50 |

Pre-compute expected values before running (testing.md discipline); keep
observed ≠ expected rows in the table with a one-line diagnosis.

## 9. Milestones

1. **M1 (½ session):** single student, FR1–FR2, no letters — get the weighted
   math exact.
2. **M2:** letter ladder (FR3) with its own function + T1–T3.
3. **M3:** session loop + rejection path (FR4, FR6, VR2) + T5–T7.
4. **M4:** summary (FR5) + T4, T8 + full rubric self-check.

## 10. Extension ideas ⚙

- ⚙ Marks entered as `A+`..`F` strings mapped to midpoints (Module 11).
- ⚙ Round-half-up policy function vs banker's rounding — which does the
  center want? (Documented choice; no language feature beyond Module 6.)
- ⚙ Percentile-free "class standing" line using only comparisons.

## 11. Assessment rubric (10 points when graded as homework)

| Points | Line |
|---|---|
| 0–3 | FR1–FR3 correct (weights exact, ladder thresholds, 2 dp) |
| 0–2 | Session loop + rejection path (FR4, FR6, VR1–VR3) |
| 0–2 | Summary accumulators correct (FR5, T4/T8) |
| 0–2 | NFR1/NFR2/NFR4: function decomposition with contracts, no globals |
| 0–1 | Test table with pre-computed expectations |

Course-gate: does not compile with the contract → 0 (rubrics cap).

## 12. Student instructions

Work individually. Read the whole spec before coding; implement milestones in
order and compile after each. The deliverable is `grade_calc.cpp` plus
`test_table.md` (T1–T8 minimum) plus `postmortem.md` (one real defect:
symptom → hypothesis → test → fix). Submit as a zip named
`p01_<yourid>.zip`. Late policy per syllabus. Ask clarifying questions early —
"the spec was ambiguous" is only a valid defense if you asked by Week 7.
