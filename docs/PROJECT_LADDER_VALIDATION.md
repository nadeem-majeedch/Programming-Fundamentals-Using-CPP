# Project Ladder Validation Report

**Scope:** `projects/README.md` + `projects/project-01..05/project.md` and the
restricted reference implementations under
`instructor/projects/reference/` (P1–P4).
**Method:** automated section/requirement parsing; GCC 16.2 compile-and-execute
of P1–P4 references against each spec's test table; scope-band sweep; link
checker. Date: 2026-09-18.

---

## 1. All five projects exist with the 12 required sections — **PASS**

Automated heading check per file: every `project.md` carries **12/12**
sections (problem, objectives, FR, NFR, data structures, UI design,
validation, testing plan, milestones, extensions, rubric, instructions).
Counts: P1 FR6/NFR5/VR4/tests 8 · P2–P5 FR5/NFR5/VR5/tests 10 each.

## 2. Course-scope implementability — **PASS**

Progressive bands, enforced in the requirements text itself:

| Project | Modules | Uses | Explicitly out of scope |
|---|---|---|---|
| P1 | 1–8 | functions, decisions, loops, references | arrays, files, structs, classes (NFR4) |
| P2 | 9–12 | arrays, parallel arrays, own sort, string categories | files, structs, vectors, classes, `std::sort` (NFR4, FR4) |
| P3 | 13–15 | structs, `std::vector`, references, file round-trip | classes/inheritance (deliberate — P4's step), raw new/delete (NFR5) |
| P4 | 14–16 | class + invariants, guarded mutators, const observers, files | raw new/delete (NFR4), stored derived state |
| P5 | 1–16 | everything at small scale, integrated | external deps, frameworks, beyond-scope libraries |

No FR in any project requires a feature outside its band (automated FR-level
sweep: no banned-feature mentions in requirement lines).

## 3. Requirements clear and testable — **PASS**

- Every FR is phrased with exact prompts/labels/output grammar (UI-design
  samples byte-specify the report lines; e.g., P2's sample session reproduces
  the report verbatim from the reference implementation).
- Every project has a numbered validation section (VR lines) and a test table
  covering: typical, boundary (T2/T3 in P1; 0.01/5000 in P2), invalid,
  state-machine (P3 T3/T4, P4 T3), persistence (P3/P4/P5 round-trips), and
  error-environment (write-protect) classes.
- Milestones are per-half-session (P1–P4) or mapped to the Week 14–16
  checkpoints (P5), each with named evidence.

## 4. Reference implementations compile and pass — **PASS**

GCC 16.2, `-std=c++17 -Wall -Wextra -pedantic`, zero warnings required.

| Project | Result | Verified behaviors (from the spec's tables) |
|---|---|---|
| P1 | PASS | T1 `86.05 -> B+` · T2 `90.00 -> A` · T5 `bad mark for lab` + exclusion · T7 `no students` · T6 exit 1 · T8 best-tracking |
| P2 | PASS | T1 exact sample report (shares 31.30/68.70 %) · T7 undo bookkeeping · T8 `nothing to undo` · T10 `no expenses` |
| P3 | PASS | T2 `skipped: 1` with clean lines loading · T3 `not available` · T1 round-trip `loaded: 3 skipped: 0` · id policy B-1003 |
| P4 | PASS | T1/T2 gpa bounds incl. 0.00 inclusive · T3 `already graduated` · T4 duplicate id · T6 poisoned line skipped, invariant holds · active-mean 2.17 cross-checked in Python · 2-dp save format |
| P5 | PASS (by construction) | No full reference shipped (leak policy — `instructor/projects/README.md`); desks are the P1–P4 domains, so their verified behaviors compose; T-table grading guidance provided |

**Defects found and fixed during verification:** P1's readMark conflated EOF
with out-of-range (one rejected mark aborted the session; spec FR6/VR2 require
continue) — restructured to a three-status reader, re-verified; P4's save
format printed gpas with default precision (`3` vs `3.00`) — fixed to
2 dp for a lossless round-trip; P4's factory needed an explicit placeholder
record (documented why it is safe); P3 add confirmed token-read (single-word
titles) with the `;`-rejection as the grammar guard.

## 5. Rubric completeness — **PASS**

Each P1–P4 rubric totals exactly 10 points with named lines tied to FR/VR/T
items and the compile gate. P5 uses the shared 100-point project rubric
(correctness 30 · quality 25 · testing 15 · explanation 15 · process 10 ·
scope 5) with two named quality caps (stored derived state, `std::sort`).
Course-gate language present in all five (contract compile → 0).

## 6. Projects sufficiently distinct — **PASS**

Domain, skill band, and persistence requirements differ per project:

| | Domain | Core new skill | Persistence |
|---|---|---|---|
| P1 | grades (single-student math) | function decomposition | none (forbidden) |
| P2 | money (event day) | collections + own sort | none (forbidden) |
| P3 | library | records + file round-trip | required |
| P4 | people-records | class invariants | required |
| P5 | integration | synthesis + multi-file state | required ×3 files |

A submission for one project cannot satisfy another's FR set (P2 forbids
files; P3/P4 require them; P1 forbids arrays; P2+ require collections) —
cross-submission is structurally detectable.

## 7. Separation of instructor material — **PASS**

Student specs contain no reference code; references live under
`instructor/projects/reference/` with INSTRUCTOR-ONLY banners
(`instructor/projects/README.md`). P5 deliberately ships **no** full
reference (leak policy documented).

## 8. Repository integrity — **PASS**

- Link checker: **OK — 612 relative links resolve** (one depth fix in P5's
  rubric link).
- Grading plan preserved: P5 = the 10 % component, Weeks 14–16, shared
  100-point rubric — stated in `projects/README.md` verbatim against
  `instructor/assessment-rubrics/project.md`; P1–P4 framed as ungraded
  ladders (optionally graded via the assignment weights).
- Build scratch removed; nothing committed or pushed.

---

## Overall: **PASS**

| Check | Verdict |
|---|---|
| Five projects, 12/12 sections each | PASS |
| Course-scope implementability (band-enforced) | PASS |
| Requirements clear + testable (FR/VR/T numbering) | PASS |
| References compile & execute (P1–P4) | PASS (4 defects found & fixed) |
| Rubric completeness (10-pt × 4 + 100-pt capstone) | PASS |
| Distinctness (domain × skill × persistence matrix) | PASS |
| Instructor separation | PASS |
| Links & integrity | PASS (612/612) |
