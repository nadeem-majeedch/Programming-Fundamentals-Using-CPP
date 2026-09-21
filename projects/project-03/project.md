# Project 03 · Library Management System

**Modules 13–15 (Weeks 13–15) · structs, vector, references, file persistence — the first stateful project**
Outcomes: CLO-6…CLO-8 (PF-13…PF-15). Difficulty: ★★★☆☆ · Builds on P2.

## 1. Problem description

A campus reading room lends books to members. The desk currently uses a
paper register that is lost weekly. Write a console program that keeps a
catalog of books and a register of which are out, **saves state to a file
between runs**, and produces the desk's three daily reports. This is your
first project whose data outlives the program: persistence changes design.

## 2. Learning objectives

1. Model records with a `struct` and manage a collection in `std::vector`.
2. Use references for in/out parameters where copies would lie.
3. Implement file round-tripping: load on start, save on change.
4. Apply the skip-and-report loader: malformed lines are data, not crashes.
5. Search by title (case-sensitive substring) and report by status.

## 3. Functional requirements

- FR1 — Book record: `struct Book { std::string title; std::string author;
  std::string id; bool out; std::string borrower; };` `id` is unique
  (B-1001 style); `borrower` is `-` when not out.
- FR2 — On start, load `catalog.txt` (lines: `id;title;author;out;borrower`,
  `out` is `0`/`1`). Print `loaded: <n> skipped: <k>` — skip reasons counted,
  never fatal. Missing file = empty catalog (not an error).
- FR3 — Menu loop:
  `add / lend / return / find / report / quit` (exact words).
  - `add`: reads title, author; generates the next id (`B-1001` + 1 per
    catalog length ever added — keep the counter in the file via a new max).
  - `lend <id> <borrower>`: marks out, records borrower; fails with
    `not available` if already out; `no such id` if absent.
  - `return <id>`: marks in, borrower back to `-`; `no such id` if absent.
  - `find <text>`: prints every title containing <text> (case-sensitive
    substring), `id title out?` lines; `none` if no hits.
  - `report`: counts line `books: <n> out: <k> available: <m>` then the
    out-list `id -> borrower`.
- FR4 — Save the full catalog on `quit` (rewrite `catalog.txt`), and on
  every successful lend/return (crash tolerance — desk may lose power).
- FR5 — `quit` is the only exit; EOF on stdin acts as `quit` (desk closes
  the terminal).

## 4. Non-functional requirements

- NFR1 — Vector capacity grows by need; no fixed-size arrays anywhere.
- NFR2 — All mutation flows through functions taking
  `std::vector<Book>&`; report functions take `const std::vector<Book>&`.
- NFR3 — The save format and the load format are the same line grammar —
  a file your program wrote must load with `skipped: 0`.
- NFR4 — Semicolons or commas only in the file; titles containing the
  separator are rejected at add time with `title may not contain ';'`
  (documented limitation, not silent corruption).
- NFR5 — Compiles with the course contract, zero warnings; no raw
  `new`/`delete` anywhere.

## 5. Suggested data structures

- `std::vector<Book> catalog;` — the single source of truth.
- Next-id policy: scan for the current maximum numeric id on load; new id =
  max + 1 (survives deletions-in-file; state the rule in a comment).
- Deliberately **no classes yet**: P4 introduces the invariant-carrying
  class; here the struct is honest data and the functions are the behavior.

## 6. User interaction design

```text
loaded: 2 skipped: 1
menu (add|lend|return|find|report|quit): lend B-1001 Ali
ok
menu (add|lend|return|find|report|quit): report
books: 2 out: 1 available: 1
B-1001 -> Ali
menu (add|lend|return|find|report|quit): add
title: Dune
author: Herbert
added B-1003
menu (add|lend|return|find|report|quit): quit
saved: 3
```

## 7. Input validation requirements

- VR1 — Load-time classes per line: wrong field count, bad `out` flag, or
  empty id → skipped (counted by class in a comment-documented tally).
- VR2 — `lend`/`return` with unknown id: `no such id`, state unchanged.
- VR3 — `lend` on an out book: `not available`, state unchanged.
- VR4 — Empty title or author at add: `bad text`, book not added.
- VR5 — File cannot be *written* on save: `cannot save`, exit 2 (data
  environment failure) — after printing the report of what would be lost.

## 8. Testing plan

| # | Class | Scenario | Expected |
|---|---|---|---|
| T1 | round-trip | add 2, quit, restart | `loaded: 2 skipped: 0` |
| T2 | corrupt line | catalog with 1 bad line | `skipped: 1`, others load |
| T3 | state machine | lend → lend same | second: `not available` |
| T4 | state machine | return → return | second: `no such id` only if id absent; else ok→ok |
| T5 | search | find `du` against Dune | hit; `find zz` → `none` |
| T6 | id policy | add after max id B-1007 | next is B-1008 |
| T7 | persistence | lend, kill program (EOF), restart | lend survived (saved on change) |
| T8 | write-protect | read-only file/dir | `cannot save`, exit 2 |
| T9 | separator | title `A;B` | rejected, nothing added |
| T10 | empty catalog | fresh file absent | `loaded: 0 skipped: 0`, reports all zero |

## 9. Milestones

1. **M1:** struct + vector + load with skip-and-report + report + T2/T10.
2. **M2:** menu + add (id policy) + lend/return state machine + T3/T4/T6.
3. **M3:** save-on-quit + save-on-change + T1/T7/T8.
4. **M4:** find + hardening pass (VR4/VR5, T5/T9) + full test table.

## 10. Extension ideas ⚙

- ⚙ Due dates as day-numbers with an overdue report (arithmetic only).
- ⚙ `find` case-insensitive mode (tolower mapping — Module 11).
- ⚙ Two catalogs (books + members) with borrower ids resolved to names at
  report time — the join idea, two vectors.

## 11. Assessment rubric (10 points when graded as homework)

| Points | Line |
|---|---|
| 0–2 | Load with skip-and-report; missing file handled (T2, T10) |
| 0–2 | State machine: lend/return invariants hold (T3, T4) |
| 0–3 | Persistence: round-trip, save-on-change, cannot-save path (T1, T7, T8) |
| 0–2 | Search + reports exact (T5, FR3 report line) |
| 0–2 | NFR1/NFR2/NFR5: vector+references, no raw pointers, contracts |

Course-gate: does not compile with the contract → 0.

## 12. Student instructions

Work individually. Start from the file format — write a 3-line `catalog.txt`
by hand and load it before writing any menu code. The skipped-counter and the
round-trip test (T1) are the project's soul: a file you wrote must load clean.
Deliverables: `library.cpp`, `test_table.md` (T1–T10), `postmortem.md`, and
the sample `catalog.txt` you tested with. Zip as `p03_<yourid>.zip`. Use of
`new`/`delete` or fixed-size arrays = scope violation under the
scope-calibration line.
