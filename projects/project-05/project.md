# Project 05 · Integrated C++ Management Application

**Capstone · all 16 modules · the graded course project (10 %, Weeks 14–16)**
Outcomes: CLO-1…CLO-8. Difficulty: ★★★★★ · Subsumes P1–P4 bands.

## 1. Problem description

A small institute runs three desks that currently use three separate paper
registers: **course grades** (per-student weighted averages and letters, the
P1 domain), **petty cash** (expenses and category totals, the P2 domain), and
the **reading-room shelf** (a mini catalog with lend/return, the P3 domain).
You will build ONE console application that integrates these three desks into
a single coherent program with persistent state — the P4 class-design
discipline applied across all three domains — and demonstrate it live.

Integration is the point: one shared main menu, one consistent validation
vocabulary, one save/load discipline, reports that span desks (e.g., a
"session summary" quoting all three).

## 2. Learning objectives

1. Integrate three sub-systems behind one menu without entangling their data.
2. Apply class design with invariants to a domain that needs it (records)
   and honestly choose structs where they suffice (expenses).
3. Manage multi-file persistence with one uniform loader discipline.
4. Search and sort across a collection for a ranked report.
5. Produce a test table, a design narrative, and a live demonstration that
   together evidence understanding.

## 3. Functional requirements

- FR1 — Three sub-systems, one menu:
  - `grades`: add student name + lab/midterm/final (P1 weights & letter
    ladder); list all; summary (count, best, mean).
  - `cash`: add expense category+amount; category totals with shares; largest.
  - `shelf`: add book title/author; lend/return by id; report out-list.
  - `summary`: one line per desk (`grades: <n> students`, `cash: <total>`,
    `shelf: <k> out`) plus the session's total entries handled.
  - `quit` (also EOF): saves everything, prints `saved`.
- FR2 — Persistence: `grades.txt`, `cash.txt`, `shelf.txt` — loaded on start
  (with skip-and-report counts per file), saved on quit. A corrupted line in
  one file must not prevent the other two from loading.
- FR3 — `grades` and `shelf` domains use a class with stated invariants
  (grade components 0..100, weighted average recomputed-not-stored; shelf
  book ids unique, lend/return state machine). `cash` uses a struct +
  vector — and your report must defend that choice in one sentence.
- FR4 — One ranked report anywhere in the program: top-3 students by average
  (ties: alphabetical by name) using your own sort — not `std::sort`.
- FR5 — Validation vocabulary is consistent program-wide: `bad input` (read
  failure) · `bad value` (out of range) · `no such id` · `not available` /
  `nothing to undo`-style state messages per domain. Rejected entries change
  no state, in any desk.

## 4. Non-functional requirements

- NFR1 — Architecture: each sub-system is a translation unit's worth of
  functions/classes with contracts; the menu dispatches, it does not compute.
- NFR2 — The weighted average is never stored — always recomputed from
  components (stored derived state is banned; the report explains why).
- NFR3 — Compiles with the course contract, zero warnings; no raw
  new/delete; vector ownership everywhere.
- NFR4 — Capacity is effectively unbounded (vectors); no magic numbers
  without named constants.
- NFR5 — The program survives a poisoned file: skips it, counts it, runs the
  other desks, and says so in the startup line.

## 5. Suggested data structures

- `class GradeRecord { ... };` — private components + observers;
  `average()` recomputes; letter mapping stays a free function (pure).
- `struct Expense { std::string category; double amount; };` +
  `std::vector<Expense>` — money has no invariant beyond range checks at the
  door; say why a class would be ceremony here.
- `class ShelfBook { ... };` mirroring P3's Book with lend/return guards.
- `class Desk` per domain OR plain namespaces with vectors + functions —
  either is acceptable; the report defends the choice with the coupling
  argument.

## 6. User interaction design

```text
grades: loaded 2 skipped 0 | cash: loaded 5 skipped 1 | shelf: loaded 3 skipped 0
main (grades|cash|shelf|summary|quit): grades
grades (add|list|top|back): add
name lab midterm final: Zara 88 79 91
Zara: 86.05 -> C+
grades (add|list|top|back): back
main (grades|cash|shelf|summary|quit): summary
grades: 3 students | cash: 214.50 | shelf: 2 out
session entries: 4
main (grades|cash|shelf|summary|quit): quit
saved.
```

## 7. Input validation requirements

- VR1 — Domain range rules enforced at each desk's door (marks 0..100,
  amounts 0.01..5000, shelf ids unknown/absent) with the FR5 vocabulary.
- VR2 — Load-time skip-and-report per file, classified (bad field count vs
  bad value vs bad flag); a skipped line never enters a desk's state.
- VR3 — Cross-desk contamination impossible: a `cash` command inside the
  `grades` submenu is a `bad input`, and no desk's function mutates another's
  state.
- VR4 — `summary` works identically on empty desks (`grades: 0 students`).
- VR5 — Save failure on any file → `cannot save <file>`, exit 2, after an
  attempt to save the other two (partial-persistence honesty).

## 8. Testing plan

| # | Class | Scenario | Expected |
|---|---|---|---|
| T1 | integration | all three desks populated, summary | three correct lines + entry count |
| T2 | round-trip | populate all, quit, restart | per-file `loaded N skipped 0` |
| T3 | poisoned file | corrupt line in cash.txt only | cash `skipped 1`; other desks load clean |
| T4 | invariant | grade mark 101; shelf lend of out book | `bad value` / `not available`; state unchanged |
| T5 | derived state | student's average after gpa-style edit of a component | recomputed value in list/top — never a stale stored one |
| T6 | ranking | averages 86.05, 92.5, 86.05 | top-3 order: 92.5, then the two 86.05 alphabetical by name |
| T7 | cross-desk | `cash` typed at grades submenu | `bad input`, desks unaffected |
| T8 | empty desks | fresh files, `summary` then `quit` | zeros; `saved.`; restart loads zeros |
| T9 | save failure | read-only directory | `cannot save <file>` per file, exit 2 |
| T10 | vocabulary | one rejected entry per desk | same message grammar, no state change anywhere |

Plus a demonstration script: a printed 8–10 command sequence you will run
live at the demo (submit it; the demonstrator follows it).

## 9. Milestones (map to Weeks 14–16)

| Week | Milestone | Evidence at checkpoint |
|---|---|---|
| 14 | Proposal + skeletons | one-pager: data model per desk, file grammar, test-table plan |
| 15 | Checkpoint: desks work standalone | compiling program: all three menus function in-memory; debug log |
| 15 | Integration + persistence | one menu, three desks, round-trip (T2) |
| 16 | Polish + demo + report | T1–T10 tables, top-3 ranking, demonstration script |

## 10. Extension ideas ⚙ (optional; graded only as scope-calibration evidence)

- ⚙ `audit` command: per-desk counters of rejected entries this session.
- ⚙ A fourth desk (inventory) reusing the ShelfBook pattern — reuse as
  evidence, not novelty.
- ⚙ Export `summary` to a text report file with the audit footer.

## 11. Assessment rubric

Graded out of **100 points** with the shared project rubric
([../../instructor/assessment-rubrics/project.md](../../instructor/assessment-rubrics/project.md)):
correctness 30 · design & quality 25 · testing 15 · explanation 15 ·
process 10 · scope 5. The demonstration maps to correctness + explanation;
the debug logs and milestones map to process. NFR2 (no stored derived state)
and FR4 (own sort) are named quality lines — violating either caps quality at
15/25.

## 12. Student instructions

Individual by default; pairs allowed with a written split and both partners
answering live questions at the demonstration. Sequence: proposal → desk
skeletons → integration → persistence → ranking → polish. Keep every desk
working at each milestone (compile after every change; the debug log is
process evidence). Deliverables at Week 16: source file(s), the three sample
data files, `test_table.md` (T1–T10 + your own), `postmortem.md` (design
narration + ≥ 2 defect narratives + honest limits), demonstration script,
and a 5-minute live demo. Zip as `p05_<yourid>.zip`. Late policy per
syllabus; the demonstration is scheduled in Week 16's lab slot.
