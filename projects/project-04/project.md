# Project 04 · Student Record Management System

**Modules 14–16 (Weeks 14–16) · the first class with a stated invariant — private state, guarded mutators, file round-trip**
Outcomes: CLO-7, CLO-8 (PF-14…PF-16). Difficulty: ★★★★☆ · Builds on P3.

## 1. Problem description

A department office keeps student records: id, name, program, and a GPA that
must always lie in 0.00..4.00, plus a status that only moves in one direction
(active → graduated) — never backward. P3 kept *books*, which can be anything;
a student *record* carries rules. Those rules must be enforced by the type
itself, not by hoping every caller remembers them. Build a small system whose
core is **one class with real invariants** and a menu that cannot break them.

## 2. Learning objectives

1. Design a class: private data, public interface, stated invariants.
2. Write guarded mutators that make invalid states unreachable.
3. Use `const` member functions for observers; keep I/O out of the class.
4. Round-trip a class-managed collection through a text file.
5. Report from an invariant-safe collection without re-validating.

## 3. Functional requirements

- FR1 — `class Student`: private `id` (string, `S-` + digits), `name`,
  `program` (one of `cs`, `ds`, `se` — lower-case), `gpa` (0.00..4.00),
  `graduated` (bool). Public: constructor-ish `load`/make function, `id()`,
  `name()`, `gpa()`, `isGraduated()` observers (const), `setGpa(double)`
  and `graduate()` mutators.
- FR2 — Invariants (stated in a class comment, enforced by the mutators):
  - `0.00 ≤ gpa ≤ 4.00` — `setGpa` rejects out-of-range (returns bool);
  - `graduated` never reverts; `graduate()` on a graduated student fails;
  - `program` is fixed at construction; no mutator exists for it
    (absence of a setter *is* the design — say so in your report).
- FR3 — `class Roster`: owns `std::vector<Student>`; `add`, `findById`,
  `count`, `report` — the only door to the records.
- FR4 — Menu: `add / gpa / graduate / find / report / quit` (exact words).
  - `add <id> <name> <program>`: adds with gpa 0.00; duplicate id →
    `duplicate id`, state unchanged.
  - `gpa <id> <value>`: calls setGpa; `ok` or `rejected` (invariant), never
    a crash, never a partial write.
  - `graduate <id>`: `ok` or `already graduated`.
  - `report`: `students: <n> graduated: <k> gpa-mean: <x.xx>` over ACTIVE
    students only, then per-program counts `cs: <n> ds: <n> se: <n>`.
- FR5 — File round-trip on start/quit (`roster.txt`, line grammar of your
  design — document it). Round-trip must lose nothing.

## 4. Non-functional requirements

- NFR1 — The menu can print but can never write a field directly: all
  writes go through mutators that enforce the invariants. A `gpa` of 9.0
  must be *impossible* to store, not merely discouraged.
- NFR2 — `Student` has no cin/cout; `Roster` has no cin/cout; the menu
  function does I/O and nothing else.
- NFR3 — Compiles with the course contract, zero warnings.
- NFR4 — No raw `new`/`delete`; vector ownership only (RAII default).
- NFR5 — Every mutator returns a success bool; every caller checks it.

## 5. Suggested data structures

- `class Roster { std::vector<Student> students; ... };` — composition
  (has-a), the M16 pattern. The roster's own invariant: ids unique — enforced
  by `add` checking `findById` first.
- File line grammar suggestion: `id;name;program;gpa;graduated` — same
  trade-offs as P3 (reject titles/fields containing `;` at the door).
- The mean over active students: double sum, single-cast division, graduated
  excluded — a policy, documented.

## 6. User interaction design

```text
loaded: 3 skipped: 0
menu (add|gpa|graduate|find|report|quit): gpa S-1001 9.0
rejected
menu (add|gpa|graduate|find|report|quit): gpa S-1001 3.4
ok
menu (add|gpa|graduate|find|report|quit): graduate S-1001
ok
menu (add|gpa|graduate|find|report|quit): graduate S-1001
already graduated
menu (add|gpa|graduate|find|report|quit): report
students: 3 graduated: 1 gpa-mean: 2.93
cs: 1 ds: 1 se: 1
menu (add|gpa|graduate|find|report|quit): quit
saved: 3
```

## 7. Input validation requirements

- VR1 — `add` with unknown program word → `bad program`, nothing added.
- VR2 — `add` with duplicate id → `duplicate id`, nothing added (roster
  invariant).
- VR3 — `gpa` value 9.0, −0.5, `abc` → `rejected` / `bad input` respectively;
  state unchanged; the rejected value appears nowhere on disk after quit.
- VR4 — Load-time: bad gpa, bad program, or bad flag lines are skipped and
  counted — an invariant-breaking line must never enter the roster.
- VR5 — File write failure → `cannot save`, exit 2.

## 8. Testing plan

| # | Class | Scenario | Expected |
|---|---|---|---|
| T1 | invariant | gpa 4.00 then 4.01 | first `ok`, second `rejected` |
| T2 | invariant | gpa 0.00 accepted | `ok` (boundary is inclusive) |
| T3 | invariant | graduate twice | `ok` then `already graduated` |
| T4 | invariant | duplicate id | `duplicate id`, count unchanged |
| T5 | round-trip | 3 records, quit, restart | `loaded: 3 skipped: 0` |
| T6 | poisoned file | file with gpa 9.0 line | `skipped: 1` — invariant holds from birth |
| T7 | report policy | 1 graduated (gpa 4.0) + 2 active (3.0, 3.5) | mean 3.25 over ACTIVE only; graduated count 1 |
| T8 | bad program | `add S-1010 Xx math` | `bad program` |
| T9 | observer-only | attempt: does any public path write name/gpa directly? | code review: none exists |
| T10 | write-protect | read-only dir on quit | `cannot save`, exit 2 |

## 9. Milestones

1. **M1:** `Student` class + invariants + unit-style demo main (no menu,
   no file) exercising T1–T3.
2. **M2:** `Roster` + menu add/gpa/graduate + T4, T8.
3. **M3:** file round-trip + poisoned-file rejection + T5, T6, T10.
4. **M4:** report (per-program counts, active-only mean) + T7 + rubric pass.

## 10. Extension ideas ⚙

- ⚙ Dean's-list report (active, gpa ≥ 3.5, sorted by gpa desc — your own sort).
- ⚙ Probation flag as a *derived* property (gpa < 2.0 && !graduated) — an
  observer, never stored (stored derived state is the classic corruption).
- ⚙ `remove` for records — and the design argument about whether records
  should ever disappear (audit trails).

## 11. Assessment rubric (10 points when graded as homework)

| Points | Line |
|---|---|
| 0–3 | Class design: private state, guarded mutators, const observers, invariants stated (T1–T3, T9) |
| 0–2 | Roster invariants: unique ids, program whitelist (T4, T8) |
| 0–2 | File round-trip + poisoned-line rejection (T5, T6) |
| 0–2 | Report policies exact (active-only mean, counts) (T7) |
| 0–1 | I/O out of the classes (NFR2) + test table |

Course-gate: does not compile with the contract → 0.

## 12. Student instructions

Work individually (pair by arrangement). Write the invariant comment FIRST —
the rubric grades whether the code makes the invariant unbreakable, not
whether the menu "mostly works". Deliberate attack pass: try to break your own
invariant through every public path; document each attempt in `postmortem.md`
(successful defenses count as your defect narrative). Deliverables:
`records.cpp`, `test_table.md` (T1–T10), `postmortem.md` (≥ 1 defect narrative
+ the attack log), sample `roster.txt`. Zip as `p04_<yourid>.zip`.
