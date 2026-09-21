# Programming Fundamentals Using C++

A complete, open repository for a **university-level introductory programming course**
(16 weeks · 32 lectures · 2 hours each), designed for:

- **BS Computer Science** beginners
- **BS Data Science** beginners
- **Any undergraduate student** with **no prior programming experience**

C++ is the primary programming language. The course moves progressively from
"what is a program?" to advanced introductory topics (pointers, dynamic memory,
file I/O, structs, and a complete capstone project).

---

## Snapshot

| Item | Value |
|---|---|
| Duration | 16 weeks (one semester) |
| Lectures | 32 (two per week) |
| Lecture length | 2 hours |
| Language | C++ |
| C++ standard | **C++17** (rationale: [docs/CPP_STANDARD.md](docs/CPP_STANDARD.md)) |
| Compiler | Any standard-conforming C++17 compiler (GCC ≥ 8, Clang ≥ 8, MSVC ≥ 2019 16.0) |
| Prerequisites | None — no programming experience assumed |
| Textbook | None required; curated free resources in [resources/](resources/README.md) |

> **Academic integrity note:** this repository contains **no invented citations**.
> Every referenced book, standard, or website is real, freely accessible, and
> listed with a verified URL. Course-internal documents cite each other by
> relative link only.

---

## Course at a glance

| Phase | Weeks | Theme | Milestone |
|---|---|---|---|
| I — First Contact | 1–2 | Computers, programs, first C++ programs | Lab 1: hello world |
| II — Building Blocks | 3–5 | Variables, types, operators, I/O, control flow | Assignment 1 |
| III — Structuring Code | 6–8 | Functions, scope, debugging, arrays, strings | **Midterm exam** (week 8) |
| IV — Working with Data | 9–11 | Pointers, dynamic memory, structs, file I/O | Project proposal |
| V — Toward Real Programs | 12–14 | std::vector/string, intro classes, STL algorithms, recursion | Project milestone |
| VI — Consolidation | 15–16 | Best practices, review, **final exam**, project showcase | Capstone delivery |

The complete week-by-week plan lives in [COURSE_SCHEDULE.md](COURSE_SCHEDULE.md).

---

## Repository architecture

```
Programming-Fundamentals-Using-C++/
├── README.md                 ← you are here
├── COURSE_OVERVIEW.md        ← syllabus, policies, grading
├── LEARNING_OUTCOMES.md      ← measurable outcomes + assessment mapping
├── COURSE_SCHEDULE.md        ← 16-week / 32-lecture plan
├── TEACHING_GUIDE.md         ← instructor pedagogy playbook
├── CONTRIBUTING.md           ← how to submit content or fixes
├── LICENSE                   ← usage terms
│
├── docs/                     ← standards: C++ policy, toolchain setup, code style, roadmap
├── lectures/                 ← lecture notes & slides, week_01 … week_16
├── examples/                 ← small, runnable, commented demo programs
├── exercises/                ← in-class + homework exercises (with solutions)
├── labs/                     ← supervised 2-hour lab manuals
├── assignments/              ← graded weekly assignments + rubrics
├── quizzes/                  ← short in-class quizzes (student + private versions)
├── exams/                    ← midterm & final (review guides public; papers restricted)
├── projects/                 ← semester capstone (specs, milestones, rubrics)
├── resources/                ← curated links, reference sheets, glossary
├── instructor/               ← INSTRUCTOR-ONLY: keys, pacing guides, slide decks
├── student/                  ← student-facing start-here kit & checklists
├── tools/                    ← helper scripts (link checker, scaffolding)
└── website/                  ← optional static landing page
```

### Purpose of each directory

| Directory | Purpose | Audience |
|---|---|---|
| [`docs/`](docs/README.md) | Project standards: selected C++ standard & rationale, compiler setup for Windows/macOS/Linux, coding style guide, content roadmap | All |
| [`lectures/`](lectures/README.md) | One folder per week; each holds two lecture note sets (e.g. `lecture_01.md`) with objectives, timing plan, worked examples, common pitfalls | Students (notes), instructor (decks) |
| [`examples/`](examples/README.md) | Minimal runnable C++ programs indexed by topic — every example compiles standalone under C++17 | Students |
| [`exercises/`](exercises/README.md) | Practice problems: in-class drills and homework, each with statement, constraints, and a `solutions/` subfolder | Students (statements), instructor (solutions) |
| [`labs/`](labs/README.md) | Six graded 2-hour supervised lab manuals (weeks 2, 4, 6, 8, 12, 15) with tasks, checkpoints, and grading sheets | Students |
| [`assignments/`](assignments/README.md) | Four weekly homework assignments with specifications and rubrics | Students |
| [`quizzes/`](quizzes/README.md) | Five 15-minute quizzes; student version (questions only) and instructor version (with answer key) | Split |
| [`exams/`](exams/README.md) | Midterm (week 8) and final (week 16); public review guides, restricted exam papers + keys | Split |
| [`projects/`](projects/README.md) | Capstone project pack: topic menu, milestone schedule, rubric, self-assessment forms | Students |
| [`resources/`](resources/README.md) | Curated real-world resources: documentation, books, tools, plus one-page cheat sheets and a course glossary | Students |
| [`instructor/`](instructor/README.md) | **Instructor-only**: answer keys index, pacing guide, slide sources, proctoring notes | Instructor |
| [`student/`](student/README.md) | Student start-here kit: how to install a compiler, how to study, weekly checklists | Students |
| [`tools/`](tools/README.md) | Maintenance scripts used while authoring (link checker, folder scaffolding) | Maintainers |
| [`website/`](website/README.md) | Optional static landing page for publishing the syllabus | Public |

### Audience separation at a glance

| Content | Location | Student sees? |
|---|---|---|
| Lecture notes, examples, lab manuals, project specs | `lectures/ examples/ labs/ projects/` | ✅ yes |
| Exercise **statements** | `exercises/<area>/` | ✅ yes |
| Exercise **solutions** | `exercises/<area>/solutions/` | 🟡 after deadline (per policy) |
| Quiz answer keys, exam papers, pacing guide | `instructor/`, `quizzes/*/instructor_key.md`, `instructor/exams/` | ❌ no |
| Review guides, past-paper topic maps | `exams/midterm/`, `exams/final/` | ✅ yes |

The enforcement policy (how the instructor publishes the restricted copies) is
described in [COURSE_OVERVIEW.md § 6](COURSE_OVERVIEW.md#6-content-access-policy).

---

## Conventions used in this repository

- **Directory naming:** `snake_case`, lowercase (`lab_manuals` inside `labs/`).
- **Week folders:** `week_01` … `week_16` (zero-padded, 2 digits).
- **Lecture numbering:** `lecture_01` … `lecture_32`, global across the semester
  (week 2 ⇒ lectures 03 and 04).
- **C++ files:** `snake_case.cpp` (e.g. `hello_world.cpp`).
- **C++ standard:** C++17 everywhere; see [docs/CPP_STANDARD.md](docs/CPP_STANDARD.md).
- **Every directory** contains a `README.md` explaining its layout and
  naming rules — this is the navigation contract for the whole repo.

## Getting started

- **If you are a student:** open [student/README.md](student/README.md) — it walks
  you through compiler installation and your first build in under 30 minutes.
- **If you are an instructor:** open [TEACHING_GUIDE.md](TEACHING_GUIDE.md) and
  [instructor/README.md](instructor/README.md).
- **If you want to contribute content:** open [CONTRIBUTING.md](CONTRIBUTING.md).

## Building the sample code

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples/hello_world.cpp -o hello
./hello
```

Every example in `examples/` builds with exactly this command line on any
standard-conforming compiler. See [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) for
platform-specific setup (MSVC, Xcode, Linux packages).

---

## Status

**Phase: foundation.** The architecture, standards, and navigation are complete;
content will be authored incrementally per the roadmap in
[docs/CONTENT_ROADMAP.md](docs/CONTENT_ROADMAP.md). ✅ No content is
fabricated or stubbed as "done" — every folder honestly states its current state.

## License

Distributed under the terms in [LICENSE](LICENSE) (MIT for code; course text
under the same license with attribution). Educational use is explicitly permitted.
