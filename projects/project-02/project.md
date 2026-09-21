# Project 02 · Expense Tracking System

**Modules 9–12 (Weeks 9–12) · arrays as collections, parallel arrays, sorting, reports — no files, no structs yet**
Outcomes: CLO-6 (PF-9…PF-12). Difficulty: ★★☆☆☆ · Builds directly on P1.

## 1. Problem description

A student club treasurer tracks small cash expenses (canteen, transport,
printing, supplies, other) during an event day. Write a console program that
accepts a day's expenses, stores them in memory, and produces the reports the
treasurer reads aloud at the evening meeting: totals per category, the largest
expense, a sorted listing, and a category-share line.

## 2. Learning objectives

1. Use arrays as collections with exact bounds discipline (n, cap).
2. Manage parallel arrays safely — or explain why you avoided them.
3. Implement and apply your own selection or insertion sort (L24).
4. Produce aggregate reports (category totals, shares) from stored data.
5. Keep validation at the input boundary so reports never see bad rows.

## 3. Functional requirements

- FR1 — Categories are fixed: `food transport printing supplies other`
  (single words, lower-case). Amounts are doubles 0.01..5000.
- FR2 — Add phase: read expenses until sentinel `done`: each entry is
  `category amount`. Capacity 200; a 201st entry prints `full` and stops
  accepting.
- FR3 — Reports (in this order, exact labels):
  - `total: <sum>` (2 dp) — all valid expenses.
  - `by category:` then one line per category
    `<name> <sum> <share%>` (2 dp; share of total; zero-count categories print `0.00 0.00%`).
  - `largest: <amount> (<category>)` — first wins ties.
  - `sorted:` all expenses ascending on one line (2 dp each).
  - `over 100: <k>` — count strictly greater than 100.
- FR4 — Sorting must be your own insertion or selection sort on the amounts
  array; `std::sort` is banned.
- FR5 — An `undo` entry removes the most recent still-present expense
  (multiple `undo` allowed; `undo` on empty log prints `nothing to undo`).

## 4. Non-functional requirements

- NFR1 — Capacity is a named constant; every array access is provably in
  bounds (report treats this as the correctness gate it is).
- NFR2 — Reports are produced by functions that take the arrays and counts —
  no report function reads input.
- NFR3 — Compiles with the course contract, zero warnings.
- NFR4 — No files, no structs, no vectors (Module 13+ skills; parallel arrays
  or an amount+index design is the intended struggle).
- NFR5 — Money math: amounts are double but the *sum* uses a stated rounding
  policy (round-half-up at display only — never mutate stored values).

## 5. Suggested data structures

- `double amounts[200];` + `int categoryIndex[200];` (parallel arrays) —
  the classic form; every swap during sorting must move BOTH arrays or you
  corrupt the category report (the L20-era misalignment bug, now yours to
  avoid).
- `double catTotal[5]; int catCount[5];` — category aggregates.
- Alternative (accepted, defend in a comment): sort an array of *indices*
  by amount, leaving the data arrays untouched — this is the cleaner design
  and is graded favorably under quality.

## 6. User interaction design

```text
expense (cat amount | undo | done): food 12.50
expense (cat amount | undo | done): transport 45
expense (cat amount | undo | done): food 8
expense (cat amount | undo | done): done
total: 65.50
by category:
food 20.50 31.30%
transport 45.00 68.70%
printing 0.00 0.00%
supplies 0.00 0.00%
other 0.00 0.00%
largest: 45.00 (transport)
sorted: 8.00 12.50 45.00
over 100: 0
```

## 7. Input validation requirements

- VR1 — Unknown category word: `bad category`, entry rejected, continue.
- VR2 — Amount outside 0.01..5000 or non-numeric: `bad amount`, rejected.
- VR3 — Rejected entries never partially enter the arrays (category without
  amount or vice versa).
- VR4 — Zero valid expenses at `done`: print `no expenses` instead of reports,
  exit 0.
- VR5 — Undo interacts correctly with capacity (undo then add works; undo
  never decrements below 0).

## 8. Testing plan

| # | Class | Input | Expected |
|---|---|---|---|
| T1 | typical | the session above | the report above (shares sum ≈ 100 %) |
| T2 | tie | two 45.00 in different categories | largest names the FIRST |
| T3 | sort | 5 unsorted amounts incl. equal | ascending line, equal values adjacent |
| T4 | boundary | amount 0.01 and 5000 accepted | both appear; 5000.01 rejected |
| T5 | invalid | `snacks 10` | `bad category`, count unchanged |
| T6 | invalid | `food 0` | `bad amount` |
| T7 | undo | add 3, undo 1, report | total has 2 entries; undo again removes next |
| T8 | undo-empty | `undo` first | `nothing to undo` |
| T9 | capacity | 201 adds | 201st → `full` |
| T10 | empty | `done` first | `no expenses` |

## 9. Milestones

1. **M1:** add-phase with validation into parallel arrays + T5/T6.
2. **M2:** total + by-category report + T1 (first three lines).
3. **M3:** your own sort + sorted line + largest + T2/T3.
4. **M4:** undo + capacity + empty cases + T7–T10.

## 10. Extension ideas ⚙

- ⚙ `max <category>` sub-report (max within one category).
- ⚙ Percent-share bars using `#` characters (fixed-width, Module 11).
- ⚙ Second event day: run the report twice in one session and diff the
  totals (Module 9 discipline, still no files).

## 11. Assessment rubric (10 points when graded as homework)

| Points | Line |
|---|---|
| 0–3 | Storage + validation correct (VR1–VR3, T4–T6) |
| 0–2 | Reports exact (labels, 2 dp, shares, T1) |
| 0–2 | Own sort + largest + over-100 (FR3/FR4, T2/T3) |
| 0–2 | Undo + capacity + empty (FR5, VR4–VR5, T7–T10) |
| 0–1 | Bounds discipline visible (NFR1) + test table |

Course-gate: does not compile with the contract → 0.

## 12. Student instructions

Work individually. The parallel-array alignment bug is the famous one — your
test table MUST include a case where sorting happens before the category
report (T1's order does this) to prove categories still match amounts.
Deliverables: `expenses.cpp`, `test_table.md` (T1–T10), `postmortem.md` (one
real defect narrated). Zip as `p02_<yourid>.zip`. `std::sort` or `vector`
here = scope violation: correctness capped at 3/10 under the scope-calibration
line.
