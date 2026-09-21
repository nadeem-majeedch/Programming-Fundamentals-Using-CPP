# Delivery Guide — Module 2 · Variables, Data Types, and Input/Output (Week 2)

**Guides:** L03, L04 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L03 · Variables, Built-in Types, and Initialization

1. **Lecture/title:** L03 — Variables, Built-in Types, and Initialization (`int`, `double`, `char`, `bool`, `const`)
2. **Module/week:** Module 2 · Week 2 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_02/lecture_03.md)): declare and initialize variables of the five built-in types; choose a type for a given datum; explain initialization vs assignment; use `const` for fixed values.
4. **Prerequisite knowledge:** L02 program anatomy; toolchain working (Lab 1).
5. **Prep checklist:** compile `examples/types_and_sizes.cpp` this morning; board ready for the box notation (METHOD § 4); load PF-CS-003; check `sizeof` outputs on the teaching machine for the sizes table.
6. **Materials & files:** `examples/types_and_sizes.cpp`; case PF-CS-003 The Receipt Printer; exercise set T01 opening items.
7. **Opening question (10):** recall from tickets + "a program must remember a student's marks as they arrive — where do remembered values *live*?" → introduce the box picture before any syntax.
8. **Concept sequence (30):** (a) variables as labelled boxes; declaration = creating the box, initialization = putting the first value in (10); (b) the five types with *why five*: size, precision, and honesty of intent (12); (c) `const` as a promise the compiler enforces (8).
9. **Explanation guidance:** teach `int` vs `double` through *what the data is* (heads counted vs average computed), never through byte sizes first. Box-and-value diagram for every declaration you write — start the notation habit now.
10. **Demonstration (15):** [DEMO-03](../demonstrations/demo_group1_basics.md) — `types_and_sizes.cpp` live; planned error: use of an uninitialized variable, shown *once* without comment ("what number is that? where did it come from?") → seeds MC-10 properly next lecture.
11. **Output prediction:** sizeof table + a `char c = 'A'; cout << c;` vs `cout << (int)c` tease — votes split; park the "(int)c" mystery for L06 ("conversion"), do not resolve today.
12. **Case study (15):** **PF-CS-003 The Receipt Printer** — choosing types for real receipt fields (prices, counts, names); discuss why a price-as-`double` is the honest beginner choice here and where the tension lies (DS note: precision — full treatment in the DS track).
13. **Guided coding (20):** pairs declare a variable set for a student record (name, age, GPA, enrolled?) with correct types and `const` where fixed; TAs check *choices*, not just syntax — "why double for GPA?" must have an answer.
14. **Common misconceptions:** introduce [MC-10](../misconception-bank/misconception_bank.md) informally if the demo's garbage value landed; formal treatment L04. Watch for "declaration and initialization are the same thing" — correct with the two-step box picture.
15. **Debugging activity:** 3-line snippet using an uninitialized `int` — class predicts, runs, observes the garbage; connect to the compiler warning they'd have seen under the contract flags.
16. **Independent practice (20):** T01 beginner items (declaration, types, `const`); TAs verify type *choices* by spot questioning.
17. **Exit ticket (5):** (1) Which type for: number of siblings / the average of siblings across the class / a letter grade? (2) Why does `const int seats = 30;` beat `int seats = 30;` for a fixed room?
18. **Summary (5):** derive: "a variable is a typed, named box; the type is a promise about what fits."
19. **Support:** students conflating types get the concrete-anchor task: list five real data items from their life and assign types (pair with a confident peer).
20. **Extension:** `sizeof` exploratory — predict int vs double vs bool sizes *before* running; discuss why bool is not "one bit".
21. **Reflection:** did the box notation land? Count students who could justify a type *choice* unaided — that number is next lecture's starting point.

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L04 · Console I/O with `cin`/`cout`: Streams, Formatting, and Input Validation Basics

1. **Lecture/title:** L04 — Console I/O with `cin`/`cout`: Streams, Formatting, and Input Validation Basics
2. **Module/week:** Module 2 · Week 2 · Lecture 2 of 2 (quiz-adjacent: first quiz is week 3 — announce)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_02/lecture_04.md)): read values with `cin` and print with `cout`; explain the stream model; format output (`fixed`, `setprecision`); perform first input validation (stream state + range check).
4. **Prerequisite knowledge:** L03 types; L02 statements.
5. **Prep checklist:** compile `examples/io_age_check.cpp`; rehearse the failed-input live moment (type `abc` at an int prompt) — know exactly what your compiler/stdlib prints; load PF-CS-004; queue `<iomanip>` snippet.
6. **Materials & files:** `examples/io_age_check.cpp`; case PF-CS-004 Elevator Logic; [MC-13](../misconception-bank/misconception_bank.md) minimal snippet.
7. **Opening question (10):** "So far every value lived *inside* the program text. What has to happen for the *user* to put a value in?" — elicit the conversation model before the stream vocabulary.
8. **Concept sequence (30):** (a) streams as pipes: `cout` pours, `cin` drains; chaining and the role of whitespace (12); (b) reading into variables & what `>>` does to the box (8); (c) formatting with `fixed`/`setprecision` (5) + first validation guard (5).
9. **Explanation guidance:** the failed-read demo is the emotional center — run it *slowly*: type letters at an int prompt, show the silent garbage/skip, then introduce the `if (!cin)` guard as "checking the pipe isn't blocked". Do not show `clear()`/`ignore()` yet (that machinery belongs to L30); today is *detect*, not *recover*.
10. **Demonstration (15):** [DEMO-04](../demonstrations/demo_group1_basics.md) — `io_age_check.cpp` with live failed input; planned error: `cin >> age;` with the check forgotten → same hang/skip students will hit in labs tonight.
11. **Output prediction:** the getline-vs-`>>` whitespace bite via [MC-13](../misconception-bank/misconception_bank.md) minimal snippet (read int, then getline name — name comes up empty). Votes will split hard; trace the pipe picture: `>>` leaves the newline *in the pipe*.
12. **Case study (15):** **PF-CS-004 Elevator Logic** — validating capacity inputs; constraints as executable checks.
13. **Guided coding (20):** pairs build an "ask name + birth year, print age band" program *with* the two guards (stream state, range); TAs test each pair's program by feeding it garbage — validation is tested by *attack*, not by happy path.
14. **Common misconceptions:** formalize [MC-13](../misconception-bank/misconception_bank.md) (mixed `>>`/getline); note the MC-10 echo: reading into a variable after a failed read is uninitialized-adjacent territory.
15. **Debugging activity:** given the "name prints empty" symptom only, pairs locate where the pipe state diverges (trace the newline). First symptom-first exercise (DEBUG § 6).
16. **Independent practice (20):** in-class I/O + validation set; early finishers: make the program re-prompt once (bounded retry) — a taste of L30.
17. **Exit ticket (5):** (1) After `cin >> x;` fails on letters, what is true about the stream? (2) Why does `getline` after `cin >> n` need help — one sentence using "pipe" or "newline".
18. **Summary (5):** derive: "I/O is a conversation; every read is a question that can fail — check the answer."
19. **Support:** pairs who cannot reproduce the getline bite get the paper pipe diagram and physically trace the characters of `"25\nAda"` — kinetic, effective.
20. **Extension:** `setprecision` exploration: fixed vs default on `1.0/3.0`; predict-then-run each.
21. **Reflection:** how many pairs survived the garbage attack? (That count = validation understanding.) Ticket (2) answers decide whether L05 opens on pipes or moves straight to arithmetic.

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
