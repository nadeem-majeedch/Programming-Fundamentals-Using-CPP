# Course Overview — Programming Fundamentals Using C++

**Catalog-style description · module structure · policies · grading · support model**

---

## 1. Course identification

| Field | Value |
|---|---|
| Title | Programming Fundamentals Using C++ |
| Level | Undergraduate (year 1) |
| Duration | 16 weeks · **16 modules** (module *n* in week *n*) |
| Lectures | **32** (two per week) × 2 hours = 64 contact hours + labs |
| Credits | 3 + 1 (adjust to local credit rules) |
| Language of instruction | English (adjust locally) |
| Primary language taught | **C++ (C++17 standard)** — see [docs/CPP_STANDARD.md](docs/CPP_STANDARD.md) |

### 1.1 Description

A first course in structured programming using C++ for students with **no prior
programming experience**. The curriculum progresses through sixteen modules —
from *what is a program?* through types, operators, decisions, loops, algorithm
design, functions, arrays (1-D and 2-D), strings, searching and sorting,
pointers and references, dynamic memory and structures, file handling and error
management, to an introduction to object-oriented programming. Students learn
to design, implement, trace, test, and debug small programs, with the emphasis
on **correct reasoning about program behavior** rather than syntax
memorization. The module sequence deliberately prepares both target audiences:
the machine-model track (pointers, memory, arrays) for BS Computer Science
students, and the data track (files, records, string processing) for BS Data
Science students.

### 1.2 Intended audience

- BS Computer Science, first semester
- BS Data Science, first semester
- Any undergraduate student with no prior programming experience

### 1.3 Prerequisites

None. Basic secondary-school algebra is assumed. No prior exposure to
programming, the command line, or compiler tooling is assumed — these are
taught in Module 1.

### 1.4 What this course is *not*

- It is **not** a software engineering course (design patterns, Git workflows,
  and testing frameworks appear only as gentle previews).
- It is **not** a competitive-programming course; problem solving is in service
  of *understanding the machine*.
- It is **not** a full OOP course: Module 16 is a bridge (classes,
  encapsulation, constructors), not the destination.

---

## 2. Module structure (summary)

| Module | Theme | New "hard idea" |
|---|---|---|
| 1 | Introduction to Programming and C++ | the translation pipeline |
| 2 | Variables, Data Types, and Input/Output | named, typed memory |
| 3 | Operators and Expressions | expressions as computed values |
| 4 | Decision-Making Statements | conditional execution |
| 5 | Loops and Repetition | controlled repetition |
| 6 | Problem-Solving and Algorithm Design | design & verification as skills |
| 7 | Functions Fundamentals | abstraction & the call stack |
| 8 | Advanced Function Concepts | overload resolution, references |
| 9 | One-Dimensional Arrays | collections & indices |
| 10 | Two-Dimensional Arrays | grids & row-major layout |
| 11 | Strings and Character Processing | text as processable data |
| 12 | Searching and Sorting | algorithm comparison & cost |
| 13 | Pointers and References | addresses & indirection |
| 14 | Dynamic Memory and Structures | heap lifetime & records |
| 15 | File Handling and Error Management | persistence & robustness |
| 16 | Introduction to Object-Oriented Programming | data + behavior + access control |

The authoritative week-by-week plan with lecture titles, outcomes, and the
assessment calendar is [COURSE_SCHEDULE.md](COURSE_SCHEDULE.md). The outcome
system (`CLO-1…8`, `PF-m.n`) is [LEARNING_OUTCOMES.md](LEARNING_OUTCOMES.md).

---

## 3. Weekly rhythm

| Slot | Activity | Duration |
|---|---|---|
| Lecture A | Module concept part 1 + live coding | 2 h |
| Lecture B | Module concept part 2 + in-class exercises | 2 h |
| Labs (weeks 2, 4, 6, 8, 10, 12, 15) | Supervised practice per [labs/](labs/README.md) | 2 h |
| Homework | Released at second lecture, due before next module ends | ~4–6 h self-study |

## 4. Assessment & grading

| Component | Weight | Details |
|---|---|---|
| Quizzes (16 module quizzes, drop lowest 2) | 15 % | 15 min each, week *n*'s second lecture |
| Programming assignments (8, drop lowest 1) | 20 % | 40 marks each, ~every 2 weeks |
| Lab reports (16 labs) | 10 % | checkpoint-based, weeks 2–15 |
| Midterm (week 8, L16) | 15 % | 90 min, closed book, Modules 1–8 |
| Final (week 16, L32) | 25 % | 120 min, cumulative, emphasis Modules 9–16 |
| Practical coding assessment | 5 % | 2-hour supervised lab exam (variants A–D) |
| Capstone project (P5) | 10 % | proposal wk 12 · milestone wk 14 · demo wk 16 |

**Pass threshold:** ≥ 50 % overall **and** ≥ 40 % on the final exam (local
policy may adjust). The assessment calendar is
[COURSE_SCHEDULE.md](COURSE_SCHEDULE.md) § Assessment calendar; rubrics live
next to each assessment.

### 4.1 Late policy (suggested)

Assignments: −10 % per 24 h up to 3 days, then instructor discretion.
Documented illness/exception: equal-footing extension.

### 4.2 Academic integrity

Collaboration at the *idea level* only; every submitted line must be written
and understood by you. Similarity checks apply; first violation zeroes the
item, second fails the course. Suggested AI policy: assistants may *explain*
errors, not *write* submitted code (see [student/GETTING_HELP.md](student/GETTING_HELP.md) § 4).

## 5. Required tools

All free; setup in [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md): a C++17 compiler
(MinGW-w64 / MSVC / Xcode CLT / gcc), VS Code with the C/C++ extension.
Verification (Module 1, L01):

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples/hello_world.cpp -o hello
```

## 6. Content access policy

Student-visible: lecture planning files, examples, lab manuals, exercise
statements, project specs, review guides. Instructor-only: solution folders,
quiz keys, exam papers, pacing guide — the complete restricted-path map and
the semester-mirror workflow are in
[instructor/ACCESS_CONTROL.md](instructor/ACCESS_CONTROL.md).

## 7. Support model

- **Lectures:** new material + live coding; questions always welcome.
- **Labs:** guidance, not solutions — the TA rules are in
  [TEACHING_GUIDE.md](TEACHING_GUIDE.md) § 5.
- **Office hours:** ≥ 2 h/week per instructor and TA.
- **Stuck?** Start with [student/GETTING_HELP.md](student/GETTING_HELP.md)
  (the 30-minute rule).

## 8. Accessibility & inclusion

Text-first markdown materials (screen-reader friendly); live coding always
paired with spoken explanation and posted notes; culturally neutral problem
contexts across science, data, games, and text processing. Accommodation
requests in week 1 — no reason needs to be disclosed.

## 9. Versioning

Materials carry a semester tag (`2026-fall`). Changes are logged in
[docs/CHANGELOG.md](docs/CHANGELOG.md); adaptation guidance for adopting
instructors is in [TEACHING_GUIDE.md](TEACHING_GUIDE.md) § 8.
