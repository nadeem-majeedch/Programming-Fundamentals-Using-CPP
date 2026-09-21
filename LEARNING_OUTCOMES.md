# Learning Outcomes — Programming Fundamentals Using C++

This document defines what a student will demonstrably be able to **do** at the
end of the course. It has two levels:

- **CLO-x — Course Learning Outcomes** (8): the programmatic outcomes cited in
  the course file and reported to accreditation.
- **PF-m.n — fine-grained outcomes** (2 per lecture, 64 total): keyed to
  *Module m, Lecture n's second digit* (e.g. `PF-13.1` = Module 13, Lecture 1
  of the module = global lecture L25). Every lecture file states its two
  `PF-` codes; every assessment cites the `CLO-`/`PF-` codes it evidences.

Bloom levels: R=Remember, U=Understand, Ap=Apply, An=Analyze, E=Evaluate, C=Create.

## Course Learning Outcomes (CLOs)

| CLO | Statement | Bloom | Assessed by |
|---|---|---|---|
| CLO-1 | Explain how a C++ program is translated and executed, and build, run, and diagnose programs with a standard C++17 toolchain. | U, Ap | Lab 1, Midterm, Final |
| CLO-2 | Write correct C++ expressions using built-in types, operators, conversions, and validated console I/O. | Ap | Assignment 1, Quiz 1, Midterm |
| CLO-3 | Construct selection and repetition logic from specifications, including nested structures, and trace their execution. | Ap, An | Assignments 1–2, Quizzes 1–2, Midterm |
| CLO-4 | Transform problem statements into algorithms using decomposition, pseudocode, flowcharts, trace tables, and systematic test-case design. | An, C | Assignments 2–3, Lab 3, Midterm |
| CLO-5 | Design, implement, and document modular programs using functions with correct scope, parameter passing, and overload resolution. | Ap, C, E | Assignments 2–3, Midterm, Final |
| CLO-6 | Implement, trace, and evaluate standard algorithms over 1-D arrays, 2-D arrays, and strings, including searching and sorting. | Ap, An, E | Assignments 3–4, Quizzes 2–3, Final |
| CLO-7 | Explain and correctly use pointers, references, dynamic memory, and structures, with state diagrams and leak-free programs. | U, Ap, An | Assignment 4, Final, Project |
| CLO-8 | Build persistent, robust programs with file I/O and error management, and model data with structs and introductory classes. | Ap, C | Assignments 4, Final, Capstone project |

## Fine-grained outcome map (by module)

### Module 1 — Introduction to Programming and C++
- **PF-1.1** Define *algorithm*, *program*, *compiler*, and *linker*, and order the stages of the translation pipeline. (R, U) — L01
- **PF-1.2** Distinguish hardware/software roles in executing a stored program. (U) — L01
- **PF-1.3** Identify the parts of a minimal C++ program (`#include`, `main`, statements, comments) and predict the effect of removing each. (U) — L02
- **PF-1.4** Classify an error as syntax, runtime, or logic from a diagnostic or symptom. (An) — L02

### Module 2 — Variables, Data Types, and Input/Output
- **PF-2.1** Declare and initialize variables of types `int`, `double`, `char`, `bool`, and `const`, choosing types appropriate to the data. (Ap) — L03
- **PF-2.2** Predict value, type, and memory footprint of declared variables, including uninitialized-variable risk. (An) — L03
- **PF-2.3** Read values with `std::cin` and write formatted output with `std::cout`, `'\n'` vs `std::endl`, and fixed/setprecision/setw manipulators. (Ap) — L04
- **PF-2.4** Validate numeric input using stream-state checks and recover from failed reads. (Ap) — L04

### Module 3 — Operators and Expressions
- **PF-3.1** Evaluate arithmetic expressions honoring precedence, associativity, and unary minus. (Ap) — L05
- **PF-3.2** Predict integer division, truncation, and modulo behavior including negative operands. (An) — L05
- **PF-3.3** Predict implicit conversions in mixed-type expressions (promotion, assignment narrowing) and their precision loss. (An) — L06
- **PF-3.4** Rewrite expressions using explicit `static_cast`, compound assignment (`+=`, `*=`, `++`, `--`), and increment placement correctly. (Ap) — L06

### Module 4 — Decision-Making Statements
- **PF-4.1** Evaluate relational/logical expressions including short-circuit evaluation and `!` of comparisons. (Ap) — L07
- **PF-4.2** Implement `if`/`else` chains and nested selection covering all branches of a specification. (Ap) — L07
- **PF-4.3** Implement `switch` with `case`, `break`, `default`, and falling-through semantics. (Ap) — L08
- **PF-4.4** Choose between `if/else` chain, `switch`, and `?:` for a multi-way decision and justify. (E) — L08

### Module 5 — Loops and Repetition
- **PF-5.1** Write `while` loops with correct initialization/test/update (three-part loop discipline). (Ap) — L09
- **PF-5.2** Write `do-while` input-validated menus and distinguish pre-test vs post-test control. (Ap) — L09
- **PF-5.3** Write `for` loops (counted, step ≠ 1, accumulators) and nested loops (tables, shapes, pairs). (Ap) — L10
- **PF-5.4** Predict `break`/`continue` effects; select and implement accumulate/search/validate patterns. (An, Ap) — L10

### Module 6 — Problem-Solving and Algorithm Design
- **PF-6.1** Produce an IPO chart and input/validation/output specification from a problem statement. (C) — L11
- **PF-6.2** Express an algorithm in pseudocode and flowchart, refined stepwise from a naive version. (C) — L11
- **PF-6.3** Desk-check a loop or nested structure into a full variable-state trace table. (An) — L12
- **PF-6.4** Design test cases: normal, boundary, and invalid classes; expected vs actual reporting. (C, E) — L12

### Module 7 — Functions Fundamentals
- **PF-7.1** Define and call functions with parameters, return values, and `void` returns; trace arguments→parameters data flow. (Ap) — L13
- **PF-7.2** Explain and demonstrate the call stack's activation records (parameters, locals, return address). (U, An) — L13
- **PF-7.3** Predict program behavior from scope/lifetime rules for local, global, block, and shadowed names. (An) — L14
- **PF-7.4** Decompose a specified flat program into cohesive functions and apply stepwise refinement. (C) — L14

### Module 8 — Advanced Function Concepts
- **PF-8.1** Create unambiguous overloaded function sets and default-argument functions. (Ap) — L15
- **PF-8.2** Implement output-parameter patterns with references and justify pass-by-value vs pass-by-reference vs `const T&`. (Ap, E) — L15
- **PF-8.3** Execute the debugging loop (reproduce→isolate→hypothesize→test→fix) and document it; diagnose from diagnostics and state tables. (An, E) — L16
- **PF-8.4** Synthesize Modules 1–8 material in an integrated exam setting. (Ap–E) — L16 (midterm)

### Module 9 — One-Dimensional Arrays
- **PF-9.1** Declare, initialize, and index 1-D arrays; explain bounds and contiguous memory layout. (Ap, U) — L17
- **PF-9.2** Predict out-of-bounds consequences and off-by-one index errors; state `size` vs `capacity` style discipline (`const int N`, `arr[N]`). (An) — L17
- **PF-9.3** Implement fill/print, sum/average, min/max (with index), count-if, and reverse-in-place algorithms. (Ap) — L18
- **PF-9.4** Implement and trace linear search; compute comparisons for best/worst cases. (Ap, An) — L18

### Module 10 — Two-Dimensional Arrays
- **PF-10.1** Declare, initialize, and index 2-D arrays with row/column addressing and memory layout (row-major). (Ap, U) — L19
- **PF-10.2** Implement nested traversal patterns (row-wise, column-wise, diagonal, boundary). (Ap) — L19
- **PF-10.3** Implement row/column totals, matrix addition, and transpose (and detect when the shape is not square). (Ap) — L20
- **PF-10.4** Pass 2-D arrays to functions (fixed-column form) and design small data applications. (Ap) — L20

### Module 11 — Strings and Character Processing
- **PF-11.1** Apply `char` classification (`isdigit`, `isalpha`, `toupper`, `tolower`) and char arithmetic in loops. (Ap) — L21
- **PF-11.2** Manipulate `std::string`: indexing, `length()`, `+`, `+=`, comparison, `substr`, `find`, `getline` vs `>>`. (Ap) — L21
- **PF-11.3** Implement reverse, palindrome, vowel/word counting, and per-character transformation algorithms. (Ap) — L22
- **PF-11.4** Implement word-level processing (splitting on spaces, longest word, search/replace, initials). (Ap, C) — L22

### Module 12 — Searching and Sorting
- **PF-12.1** Implement linear search and binary search; state and verify binary search's sorted precondition. (Ap) — L23
- **PF-12.2** Compare search algorithms by comparison counts (best/average/worst) and explain O(log n) intuition. (An, E) — L23
- **PF-12.3** Implement selection sort and bubble sort with swap; trace passes/iterations and invariants. (Ap, An) — L24
- **PF-12.4** Explain O(n²) growth intuition; choose between linear/binary search and sort-then-search by data size and sortedness. (E) — L24

### Module 13 — Pointers and References
- **PF-13.1** Explain the address-of/dereference pair (`&`, `*`), pointer declaration/assignment, and `nullptr`; draw state diagrams. (U, Ap) — L25
- **PF-13.2** Trace pointer arithmetic on arrays and simulate the array-decay behavior. (An) — L25
- **PF-13.3** Distinguish reference vs pointer semantics (bind-once, no null, no arithmetic) and implement swap via references. (Ap, An) — L26
- **PF-13.4** Explain array↔pointer relationship and choose correct parameter forms for array parameters. (E, Ap) — L26

### Module 14 — Dynamic Memory and Structures
- **PF-14.1** Allocate/deallocate with `new[]`/`delete[]`, and identify leaks, dangling pointers, double delete in code. (Ap, An) — L27
- **PF-14.2** Explain RAII and why `std::vector`/`std::string` are the default; convert a leaky demo to a leak-free version. (U, Ap) — L27
- **PF-14.3** Define structs, initialize, access/modify members (including nested structs), and pass/return by value/reference. (Ap) — L28
- **PF-14.4** Implement records-in-collection applications (arrays/vectors of structs) with aggregate computations. (Ap, C) — L28

### Module 15 — File Handling and Error Management
- **PF-15.1** Read text files with `ifstream` (word, line via `getline`, and token loops) and check open success. (Ap) — L29
- **PF-15.2** Write/append text with `ofstream` and std::ios modes; distinguish `'\n'`/EOF handling in reading loops. (Ap) — L29
- **PF-15.3** Implement robust input/file handling: stream state (`fail()`, `clear()`, `ignore()`), error categories, user feedback. (Ap, An) — L30
- **PF-15.4** Design recovery strategies (re-prompt, default value, skip-and-report) and a small CSV-lite analytics pipeline. (C) — L30

### Module 16 — Introduction to Object-Oriented Programming
- **PF-16.1** Define a class with private data, public interface, and constructor(s); instantiate and use objects. (Ap) — L31
- **PF-16.2** Justify encapsulation by contrasting a public-data struct with a guarded class; predict compile errors from access violations. (E, U) — L31
- **PF-16.3** Evolve a struct-based program into a class-based one and defend the interface design. (C) — L32
- **PF-16.4** Synthesize Modules 1–16 in an integrated exam and demonstrate a capstone with a viva. (Ap–C) — L32 (final)

---

## CLO ↔ module coverage matrix

| Module | CLO-1 | CLO-2 | CLO-3 | CLO-4 | CLO-5 | CLO-6 | CLO-7 | CLO-8 |
|---|---|---|---|---|---|---|---|---|
| M1 | ● | | | | | | | |
| M2 | | ● | | | | | | |
| M3 | | ● | | | | | | |
| M4 | | | ● | | | | | |
| M5 | | | ● | | | | | |
| M6 | | | | ● | | | | |
| M7 | | | | | ● | | | |
| M8 | | | | | ● | | | |
| M9 | | | | | | ● | | |
| M10 | | | | | | ● | | |
| M11 | | | | | | ● | | |
| M12 | | | | | | ● | | |
| M13 | | | | | | | ● | |
| M14 | | | | | | | ● | ○ |
| M15 | | | | | | | | ● |
| M16 | ○ | | | | | | | ● |

● = primary · ○ = supporting. Every CLO has 2+ primary modules; every module
maps to exactly one primary CLO.

## Assessment coverage matrix

| CLO | Assign. | Labs | Quizzes | Midterm | Final | Project |
|---|---|---|---|---|---|---|
| CLO-1 | A1 | L1 | Q1 | ● | ● | ○ |
| CLO-2 | A1 | L1 | Q1 | ● | ● | ○ |
| CLO-3 | A1–2 | L2 | Q1–2 | ● | ● | ● |
| CLO-4 | A2–3 | L3 | Q2 | ● | ● | ● |
| CLO-5 | A2–3 | ○ | Q2 | ● | ● | ● |
| CLO-6 | A3–4 | L5 | Q2–3 | ○ | ● | ● |
| CLO-7 | A4 | ○ | Q3 | – | ● | ● |
| CLO-8 | A4 | L6 | – | – | ● | ● |

## Prerequisite chain (teaching order)

```
M1 → M2 → M3 → M4 → M5 → M6 → M7 → M8 (midterm)
                                  ↘
M9 → M10 → M11 → M12 → M13 → M14 → M15 → M16 (final, capstone)
```

Each module lists its exact prerequisite modules in its week table of
[COURSE_SCHEDULE.md](COURSE_SCHEDULE.md) and in its lecture files. The week-by-week placement is
[COURSE_SCHEDULE.md](COURSE_SCHEDULE.md); how instructors assess outcomes is in
[TEACHING_GUIDE.md](TEACHING_GUIDE.md) § 6.
