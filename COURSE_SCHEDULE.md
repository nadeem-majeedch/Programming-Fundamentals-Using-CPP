# Course Schedule — 16 Modules · 16 Weeks · 32 Lectures

Weeks are numbered `01–16`; lectures are numbered **globally** `01–32`
(week *n* contains lectures `2n−1` and `2n`). Each lecture is 2 hours.
**Module *n* is taught in week *n*.**

Every lecture has a detailed planning file at
`lectures/week_NN/lecture_MM.md` containing: title, learning objectives,
prerequisites, concept sequence, teaching topics, required C++ examples,
common misconceptions, classroom activity, practice exercises, exit ticket,
and time allocation (see [lectures/README.md](lectures/README.md)).

Outcome codes (`CLO-x`, `PF-x.x`) are defined in
[LEARNING_OUTCOMES.md](LEARNING_OUTCOMES.md). Difficulty rises monotonically
across modules; see § Progression design at the end.

---

## Module map

| # | Module | Lectures | Week |
|---|---|---|---|
| 1 | Introduction to Programming and C++ | 01–02 | 1 |
| 2 | Variables, Data Types, and Input/Output | 03–04 | 2 |
| 3 | Operators and Expressions | 05–06 | 3 |
| 4 | Decision-Making Statements | 07–08 | 4 |
| 5 | Loops and Repetition | 09–10 | 5 |
| 6 | Problem-Solving and Algorithm Design | 11–12 | 6 |
| 7 | Functions Fundamentals | 13–14 | 7 |
| 8 | Advanced Function Concepts | 15–16 | 8 |
| 9 | One-Dimensional Arrays | 17–18 | 9 |
| 10 | Two-Dimensional Arrays | 19–20 | 10 |
| 11 | Strings and Character Processing | 21–22 | 11 |
| 12 | Searching and Sorting | 23–24 | 12 |
| 13 | Pointers and References | 25–26 | 13 |
| 14 | Dynamic Memory and Structures | 27–28 | 14 |
| 15 | File Handling and Error Management | 29–30 | 15 |
| 16 | Introduction to Object-Oriented Programming | 31–32 | 16 |

---

## Week-by-week schedule

### Module 1 — Introduction to Programming and C++ (Week 1)

| Lecture | Title | Outcomes |
|---|---|---|
| L01 | What Is a Program? Computers, Algorithms, and the C++ Toolchain | CLO-1, PF-1.1, PF-1.2 |
| L02 | Anatomy of a C++ Program: `main`, Statements, Compilation, and the Three Error Classes | CLO-1, PF-1.3, PF-1.4 |

Assessment due: none. First-week focus: every student leaves able to build and
run a program (`examples/hello_world.cpp`).

### Module 2 — Variables, Data Types, and Input/Output (Week 2)

| Lecture | Title | Outcomes |
|---|---|---|
| L03 | Variables, Built-in Types, and Initialization (`int`, `double`, `char`, `bool`, `const`) | CLO-2, PF-2.1, PF-2.2 |
| L04 | Console I/O with `cin`/`cout`: Streams, Formatting, and Input Validation Basics (**Lab 1**) | CLO-2, PF-2.3, PF-2.4 |

Assessment due: Lab 1 report.

### Module 3 — Operators and Expressions (Week 3)

| Lecture | Title | Outcomes |
|---|---|---|
| L05 | Arithmetic Operators, Precedence, and Integer vs Floating-Point Division | CLO-2, PF-3.1, PF-3.2 |
| L06 | Type Conversions, Compound Assignment, and Mixed-Type Expressions | CLO-2, PF-3.3, PF-3.4 |

Assessment due: **Assignment 1** (I/O, types, arithmetic).

### Module 4 — Decision-Making Statements (Week 4)

| Lecture | Title | Outcomes |
|---|---|---|
| L07 | `if`, `if/else`, and Nested Selection | CLO-3, PF-4.1, PF-4.2 |
| L08 | `switch`, Multi-Way Selection, and the Conditional Operator (**Lab 2**) | CLO-3, PF-4.3, PF-4.4 |

Assessment due: Lab 2 report.

### Module 5 — Loops and Repetition (Week 5)

| Lecture | Title | Outcomes |
|---|---|---|
| L09 | `while` and `do-while`: Sentinel and Input-Controlled Loops | CLO-3, PF-5.1, PF-5.2 |
| L10 | `for`, Nested Loops, `break`/`continue`, and Loop Patterns | CLO-3, PF-5.3, PF-5.4 |

Assessment due: **Quiz 1** (Modules 1–4).

### Module 6 — Problem-Solving and Algorithm Design (Week 6)

| Lecture | Title | Outcomes |
|---|---|---|
| L11 | From Problem to Algorithm: IPO Charts, Decomposition, Pseudocode, Flowcharts | CLO-4, PF-6.1, PF-6.2 |
| L12 | Desk-Checking, Trace Tables, and Test-Case Design (**Lab 3**) | CLO-4, PF-6.3, PF-6.4 |

Assessment due: Lab 3 report.

### Module 7 — Functions Fundamentals (Week 7)

| Lecture | Title | Outcomes |
|---|---|---|
| L13 | Defining and Calling Functions: Parameters, Return Values, `void` | CLO-5, PF-7.1, PF-7.2 |
| L14 | Scope, Lifetime, and Program Decomposition with Functions | CLO-5, PF-7.3, PF-7.4 |

Assessment due: **Assignment 2** (loops + functions).

### Module 8 — Advanced Function Concepts (Week 8)

| Lecture | Title | Outcomes |
|---|---|---|
| L15 | Function Overloading, Default Arguments, and Reference Parameters | CLO-5, PF-8.1, PF-8.2 |
| L16 | Debugging Methodology and Midterm Review · **MIDTERM EXAM** (**Lab 4**) | CLO-1–5, PF-8.3 |

Assessment due: **Midterm exam** (L01–L15, 90 min, closed book) · Lab 4 report.

### Module 9 — One-Dimensional Arrays (Week 9)

| Lecture | Title | Outcomes |
|---|---|---|
| L17 | 1-D Arrays: Declaration, Indexing, Bounds, and the Array–Memory Model | CLO-6, PF-9.1, PF-9.2 |
| L18 | Array Algorithms: Fill, Print, Sum/Average, Min/Max, Count, Linear Search | CLO-6, PF-9.3, PF-9.4 |

Assessment due: **Quiz 2** (Modules 5–8).

### Module 10 — Two-Dimensional Arrays (Week 10)

| Lecture | Title | Outcomes |
|---|---|---|
| L19 | 2-D Arrays: Declaration, Row/Column Indexing, Nested Traversal | CLO-6, PF-10.1, PF-10.2 |
| L20 | 2-D Operations: Row/Column Totals, Matrix Addition, Transpose, Passing to Functions (**Lab 5**) | CLO-6, PF-10.3, PF-10.4 |

Assessment due: **Assignment 3** (arrays) · Lab 5 report.

### Module 11 — Strings and Character Processing (Week 11)

| Lecture | Title | Outcomes |
|---|---|---|
| L21 | Characters and Strings: `char` Processing and the `std::string` Class | CLO-6, PF-11.1, PF-11.2 |
| L22 | String Algorithms: Reverse, Palindrome, Counting, Word Processing | CLO-6, PF-11.3, PF-11.4 |

Assessment due: **Quiz 3** (Modules 9–10).

### Module 12 — Searching and Sorting (Week 12)

| Lecture | Title | Outcomes |
|---|---|---|
| L23 | Linear Search vs Binary Search: Correctness and Comparisons | CLO-6, PF-12.1, PF-12.2 |
| L24 | Selection Sort and Bubble Sort: Tracing, Swapping, Complexity Intuition (**Lab 6**) | CLO-6, PF-12.3, PF-12.4 |

Assessment due: Lab 6 report · **Capstone project proposal**.

### Module 13 — Pointers and References (Week 13)

| Lecture | Title | Outcomes |
|---|---|---|
| L25 | Pointers: Addresses, `&`, `*`, `nullptr`, and Pointer Arithmetic | CLO-7, PF-13.1, PF-13.2 |
| L26 | References, Pass-by-Value vs Pass-by-Reference, and Arrays as Pointers | CLO-7, PF-13.3, PF-13.4 |

Assessment due: **Assignment 4** (2-D arrays + strings).

### Module 14 — Dynamic Memory and Structures (Week 14)

| Lecture | Title | Outcomes |
|---|---|---|
| L27 | Dynamic Memory: `new`, `delete`, Leaks, Dangling Pointers, `std::vector` as Managed Memory | CLO-7, PF-14.1, PF-14.2 |
| L28 | Structures: `struct` Definition, Members, Nesting, Arrays/Files of Records | CLO-7, PF-14.3, PF-14.4 |

Assessment due: none (project milestone week 14 Friday).

### Module 15 — File Handling and Error Management (Week 15)

| Lecture | Title | Outcomes |
|---|---|---|
| L29 | Text Files with `ifstream`/`ofstream`: Reading, Writing, Appending, EOF | CLO-8, PF-15.1, PF-15.2 |
| L30 | Robust Programs: Stream State, Error Checking, Recovery Strategies (**Lab 7-type clinic**, project work) | CLO-8, PF-15.3, PF-15.4 |

Assessment due: Lab 6 (project clinic) report.

### Module 16 — Introduction to Object-Oriented Programming (Week 16)

| Lecture | Title | Outcomes |
|---|---|---|
| L31 | Classes: Data + Behavior, Constructors, Encapsulation | CLO-8, PF-16.1, PF-16.2 |
| L32 | From Structs to Classes, Course Synthesis · **FINAL EXAM** | CLO-1–8, PF-16.3 |

Assessment due: **Final exam** (120 min, cumulative, emphasis Modules 9–16) ·
**Capstone demo & code review** (separate session).

---

## Assessment calendar (authoritative)

| Item | Week | Lecture slot | Weight (component overall) |
|---|---|---|---|
| Lab 1 | 2 | L04 week | 10 % (labs) |
| Assignment 1 | 3 | due L06 | 20 % (assignments, drop lowest 1 of 8) |
| Lab 2 | 4 | L08 week | — |
| Quiz 1 (M1–4) | 5 | L10 (15 min) | 15 % (quizzes, drop lowest 2 of 16) |
| Lab 3 | 6 | L12 week | — |
| Assignment 2 | 5 | due L14 (week 7) | — |
| Lab 4 · **Midterm** | 8 | L16 week | 15 % exam |
| Quiz 2 (M5–8) | 9 | L18 (15 min) | — |
| Assignment 3 | 9–10 | due L20 (week 10) | — |
| Lab 5 | 10 | L20 week | — |
| Quiz 3 (M9–10) | 11 | L22 (15 min) | — |
| Lab 6 · Project proposal | 12 | L24 week | 10 % project |
| Assignment 4 | 12–13 | due L26 (week 13) | — |
| Project milestone | 14 | L28 week | — |
| Lab 7 (robustness clinic + project pass) | 15 | L30 week | — |
| **Practical** (variants A–D) | 15–16 | lab session | 5 % practical |
| **Final** · Capstone demo | 16 | L32 week | 25 % exam · project demo |

## Progression design (why this order)

1. **M1–M3** build the vocabulary of *values* (programs → variables →
   expressions) with no control flow: every program is a straight line.
2. **M4–M5** add *control* (selection → repetition), each fully supported by
   the straight-line vocabulary already mastered.
3. **M6** consolidates before abstraction: students formalize the design and
   checking habits used informally since L01 — exactly before functions demand
   them.
4. **M7–M8** introduce *abstraction* (functions) on single-purpose problems,
   then scale to overloading/references — the reference idea here prepares
   pointers in M13.
5. **M9–M12** are *data* modules: 1-D arrays → 2-D arrays → strings (a
   vector-of-chars view) → algorithms over collections (search/sort). Each
   module reuses the previous collection type, so only one new concept lands
   at a time.
6. **M13–M14** reveal the *machine* (addresses, dynamic memory, records) —
   now meaningful because students have felt why vectors/strings exist.
7. **M15–M16** are *integration*: persistence and error handling, then the
   class as "a struct that protects its own data" — the bridge to OOP courses.

No module introduces two independently new hard ideas. Every module's
prerequisites are exactly the modules before it that it names.

## Scheduling notes for adopters

- The midterm occupies L16's second hour; L16's first hour is the debugging
  methodology lecture (delivered in week 8 before the exam).
- The final is written for L32's second hour; L31 remains a full teaching
  lecture either way.
- A 14-week calendar: merge M6 into M5 homework and M12 into M11 (search
  stays, bubble sort becomes lab-only). See [TEACHING_GUIDE.md](TEACHING_GUIDE.md) § 7.
- Minute-by-minute pacing per lecture lives in each `lecture_MM.md` and
  (for instructors) in `instructor/PACING_GUIDE.md`.
