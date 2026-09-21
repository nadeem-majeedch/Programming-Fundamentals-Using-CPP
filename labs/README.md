# labs/ — Supervised Laboratory Series

**16 graded 2-hour laboratory sessions**, one per week, aligned module-for-
module with the 16 modules and 32 lectures (Lab *n* ↔ Module *n* ↔ lectures
2n−1, 2n; see [../COURSE_SCHEDULE.md](../COURSE_SCHEDULE.md)). Labs are the
graded practice layer between case studies and assignments: every session
moves from **guided work → independent programming → debugging**, ending
with check-points and a submission.

Labs are worth **10 % of the course grade** (checkpoint-based; see
[COURSE_OVERVIEW.md](../COURSE_OVERVIEW.md) § 4). TAs follow the "guidance,
not solutions" rules in [TEACHING_GUIDE.md](../TEACHING_GUIDE.md) § 5.

## Lab plan

| # | Lab | Module / Lectures | Week | Guided focus → Independent focus |
|---|---|---|---|---|
| 1 | First C++ Program | M1 · L01–L02 | 1 | Toolchain → edit-compile-run cycle |
| 2 | Variables and Calculations | M2 · L03–L04 | 2 | Types & formatted I/O → a unit-price calculator |
| 3 | Operators | M3 · L05–L06 | 3 | Precedence & conversion → expression workbench |
| 4 | Decision-Making | M4 · L07–L08 | 4 | if/else & switch → a validated tariff program |
| 5 | Loops | M5 · L09–L10 | 5 | Loop patterns → accumulation & validation loops |
| 6 | Algorithm Design | M6 · L11–L12 | 6 | IPO + trace tables → test-case design sprint |
| 7 | Functions | M7 · L13–L14 | 7 | Decomposition → tested function library |
| 8 | Recursion and References | M8 · L15–L16 | 8 | Passing modes → recursive function set |
| 9 | One-Dimensional Arrays | M9 · L17–L18 | 9 | Array loops → statistics toolkit |
| 10 | Two-Dimensional Arrays | M10 · L19–L20 | 10 | Grid traversal → matrix operations program |
| 11 | Strings | M11 · L21–L22 | 11 | char/string processing → text-analysis tool |
| 12 | Searching and Sorting | M12 · L23–L24 | 12 | Traced sorts → benchmarking search cost |
| 13 | Pointers | M13 · L25–L26 | 13 | Pointer mechanics → safe-pointer toolkit |
| 14 | Structures and Dynamic Memory | M14 · L27–L28 | 14 | new/delete & structs → records program |
| 15 | File Handling and Exceptions | M15 · L29–L30 | 15 | Streams → robust file pipeline |
| 16 | OOP Mini-Project | M16 · L31–L32 | 16 | Class design → graded mini-project demo |

Outcomes for each lab cite the module's `PF-m.n` codes — see
[LEARNING_OUTCOMES.md](../LEARNING_OUTCOMES.md).

## Layout

```
labs/
├── README.md                     ← this file
├── lab_manuals/
│   ├── lab_01/                   ← manual (student-facing)
│   │   ├── manual.md             ← the 13-section lab document
│   │   ├── starter_code/         ← compilable skeletons (contract applies)
│   │   └── instructor_notes/     ← TA checklist (restricted)
│   ├── … lab_16
│   └── README.md                 ← folder guide
└── resources/                    ← shared lab resources
    ├── submission_template.md    ← report skeleton for every lab
    └── debug_log_template.md     ← five-step debug log (Lab 4 onward)
```

## Manual template (13-section authoring contract)

Every `manual.md` contains, in order:

1. Header (number, title, week, duration, lecture links)
2. Learning objectives
3. Required software and compiler (per-OS contract)
4. Relevant theory (condensed, linked to lecture notes)
5. Pre-lab questions
6. Instructor demonstration
7. Guided coding tasks (with check-points)
8. Independent programming exercises
9. Debugging task
10. Test cases
11. Expected learning outcomes
12. Submission requirements
13. Assessment rubric

## Progression model

- **Labs 1–4:** ~70 % guided / 30 % independent — mechanics first.
- **Labs 5–8:** ~50/50 — design decisions start.
- **Labs 9–12:** ~30/70 — independent work with guided debugging.
- **Labs 13–16:** guided warm-up only; Lab 16 is a full mini-project.

## Safety notes (memory management)

Labs 13–14 teach pointers and `new`/`delete` **with explicit hazard
explanations**: every manual that touches dynamic memory names the hazards
(leak, use-after-delete, double-delete), demonstrates the guard pattern
(null-out after delete), and shows the course-preferred RAII alternative
(`std::vector`) side-by-side. No unexplained unsafe practice appears in any
manual or starter file.

## Status

✅ All 16 manuals, starter code, and TA notes authored; starter programs
compile warning-free and were executed (evidence:
[../docs/LAB_AUDIT.md](../docs/LAB_AUDIT.md)).
