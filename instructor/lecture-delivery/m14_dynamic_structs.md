# Delivery Guide — Module 14 · Dynamic Memory and Structures (Week 14)

**Guides:** L27, L28 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L27 · Dynamic Memory: `new`, `delete`, Leaks, Dangling Pointers, `std::vector` as Managed Memory

1. **Lecture/title:** L27 — Dynamic Memory: `new`, `delete`, Leaks, Dangling Pointers, `std::vector` as Managed Memory
2. **Module/week:** Module 14 · Week 14 · Lecture 1 of 2 — **case-heavy variant**
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_14/lecture_27.md): [lecture_27.md](../../lectures/week_14/lecture_27.md)): allocate and free heap memory with `new`/`delete`/`delete[]`; identify leaks and dangling pointers *by pattern*; explain why `std::vector` is the managed alternative; use `vector` with push_back/size/indexing as the course's default collection from now on.
4. **Prerequisite knowledge:** L25 pointers/arithmetic; L17 arrays; L13 functions.
5. **Prep checklist:** compile `examples/dynamic_memory_caution.cpp` this morning; decide leak-demonstration visibility (Task Manager/Activity Monitor or a counter — rehearse both); load PF-CS-066 + PF-CS-067; stage the vector reveal last.
6. **Materials & files:** `examples/dynamic_memory_caution.cpp`; cases PF-CS-066 Leak Hunter, PF-CS-067 Grow-on-Demand Array; [MC-24](../misconception-bank/misconception_bank.md), [MC-25](../misconception-bank/misconception_bank.md) snippets.
7. **Opening question (10):** "Arrays need their size at compile time. A music app doesn't know your playlist length when it's *compiled*. What must exist instead?" — elicit *runtime-sized* memory; heap introduced as the answer.
8. **Concept sequence (30 — case-heavy):** (a) stack vs heap: the two parking lots (short-term labelled spots vs long-term unnumbered); `new` = rent a box, `delete` = return it — the *lease* metaphor (16); (b) the three failure patterns by picture: leak (never returned), dangling (returned but arrow kept), double-delete (two returns, second poisons the ledger) (14).
9. **Explanation guidance:** every heap rule taught as *ledger discipline*: what `new` writes in the ledger, what `delete` erases, what remains true/false after each. Dangling shown *on the picture* (arrow to a struck-through box) before any crash. `std::vector` arrives as the **managed lease**: it holds the ledger for you — not as "a better array" magic. The course's honest framing: *you learn raw new/delete to read legacy code and to understand what vector does for you; you write vector.*
10. **Demonstration (15):** [DEMO-28](../demonstrations/demo_group6_memory_files_oop.md) — `dynamic_memory_caution.cpp`: leak (loop of `new` without delete — watch memory/counter climb), dangling (use-after-delete — crash or garbage, classify it), double-delete (crash), then the same program with `vector` — none of the failures *possible*; planned error: the leak, run long enough to be visible.
11. **Output prediction:** the memory-climb (leak) prediction; use-after-delete values (honest answer: *anything* — undefined behavior again); vector version's identical *correct* output with zero manual deletes.
12. **Case study (20 — case-heavy):** **PF-CS-067 Grow-on-Demand Array** — the design problem vector solves: grow-by-copy vs grow-by-double; class designs the growth strategy on the board (allocation-counting), then *compares with vector's actual behavior* — the reveal that the library encodes their own design.
13. **Guided coding (15):** pairs convert a leaky program to vector; then write one *deliberate* leak and one dangling pointer, and *document the pattern* in a comment (recognition practice — safer than encouraging raw use).
14. **Common misconceptions:** [MC-24](../misconception-bank/misconception_bank.md) (leaks: "the program ended, so it's fine" — addressed: long-running/OS consequences, and the *habit* argument); [MC-25](../misconception-bank/misconception_bank.md) (dangling: "delete destroys the pointer" — it destroys the *lease*, the arrow survives); [MC-18](../misconception-bank/misconception_bank.md) (null-deref habit: the guard must precede the deref); and the MC-25 ledger-audit follow-up (double-delete).
15. **Debugging activity:** symptom: "memory climbs until the machine complains" — the leak hunt (PF-CS-066 as the protocol): every `new` must have an erase-mate; ledger audit on the board.
16. **Independent practice (20):** T09/T10 memory items (pattern *identification*, one vector conversion).
17. **Exit ticket (5):** (1) Leak vs dangling — one sentence each, using the lease words. (2) Why does `vector` make double-delete impossible *in its own code*?
18. **Summary (5):** the ledger metaphor derived back from the class; the course rule stated plainly: "raw new/delete: read, recognize, explain — `vector`: write."
19. **Support:** the lease-ledger worksheet (columns: action / ledger / arrows alive); leak-hunt checklist card.
20. **Extension:** PF-CS-066's full hunt on a provided multi-function program; grow-by-double allocation counting vs vector's (measure with a counter class tease — optional).
21. **Reflection:** did the vector-as-managed-lease framing avoid the "raw pointers are evil" oversimplification? (Check exit ticket (2) answers — students who say "magic" need the L28→L31 bridge re-laid.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 20 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

*Quiz note: Module 14's quiz (Quiz 10) is delivered in L28's slot per the cadence — L27 runs the case-heavy variant above.*

---

## L28 · Structures: `struct` Definition, Members, Nesting, Arrays/Files of Records

1. **Lecture/title:** L28 — Structures: `struct` Definition, Members, Nesting, Arrays/Files of Records
2. **Module/week:** Module 14 · Week 14 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 10)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_14/lecture_28.md): [lecture_28.md](../../lectures/week_14/lecture_28.md)): define structs with appropriate member types; access members and nested members; build arrays/vectors of records; pass records by const-ref; connect structs to real datasets (the DS student's row-type).
4. **Prerequisite knowledge:** L26 passing modes; L17/L27 arrays & vector.
5. **Prep checklist:** quiz 10 staged; compile `examples/struct_records.cpp`; load PF-CS-068 + PF-CS-074; prepare the parallel-arrays-vs-struct comparison prop.
6. **Materials & files:** `examples/struct_records.cpp`; cases PF-CS-068 Struct Record Migration, PF-CS-074 Struct vs Parallel Arrays Benchmark; quiz 10 + key.
7. **Opening question (10):** "A student has a name (string), marks (double), ID (int). Five hundred students. Five *parallel arrays* — what breaks when you sort by marks?" (PF-CS-046's ghost returns) — the alignment problem is structs' birth certificate.
8. **Concept sequence (30):** (a) `struct` as *the type you define*: members, dot access, initialization (12); (b) nesting (Address inside Student) + records in arrays/vectors (10); (c) passing records: `const Student&` for read, `Student&` for edit — L26's checklist applied to user types (8).
9. **Explanation guidance:** the struct is sold as *alignment*: data that belongs together *travels* together — sorting, passing, returning, one unit. `const Student&` discipline enforced from the first signature. DS framing: a struct is a *row schema*; a vector of structs is a *table* — the CSV instinct, typed. Demo note: show the same dataset as parallel arrays vs vector<Student> and *feel* which code you'd rather debug.
10. **Demonstration (15):** [DEMO-29](../demonstrations/demo_group6_memory_files_oop.md) — `struct_records.cpp`: define, init, traverse, sort-by-member (index-sort from L24 keeping records whole); planned error: return a *local* struct by... nothing wrong! (structs return by value safely — deliberately *not* an error: contrast with L25's dangling-return, the class predicts doom and learns when copying is safe).
11. **Output prediction:** sort-by-marks with records (alignment held?); nested access votes (`s.home.city` paths); the safe-return prediction (the trap that isn't).
12. **Case study (15):** **PF-CS-068 Struct Record Migration** — refactor parallel arrays into records; the migration checklist (which array is the *identity*, how members map) is the protocol.
13. **Guided coding (15 — quiz-day trim):** pairs define a `Book` struct (title, author, year, available) + a vector of 3 + a find-available function (`const Book&` returns index or −1 — L18/L23 conventions paying off).
14. **Common misconceptions:** dot-vs-arrow confusion — *prevented* by staying with dot on objects/refs until L31 (note the deferral in pacing); "structs can't be returned" (the demo's safe-return act); member-order-as-identity ("swap two members, nothing changes" — the compiler disagrees; show the diagnostic).
15. **Debugging activity:** symptom: "my find function returns the right index but the caller's record looks wrong" — returned a *copy* into a discarded temporary vs by-ref into a named variable; board picture resolves.
16. **Independent practice (10 — quiz-day trim):** one struct + vector + predicate item from T10.
17. **Quiz 10 (15):** per cadence.
18. **Exit ticket (5):** (1) Why does sorting *records* not need the index-sort trick? (2) Signature: cheapest-book finder — write it (const-ness included).
19. **Summary (5):** derive: "a struct is a row schema — the type system finally models your data."
20. **Support:** the parallel-arrays→struct migration checklist card; nested-access path diagrams (`s.home.city` as a corridor).
21. **Reflection:** did the DS framing land? (Vector-of-structs = table — L29's file reading becomes "loading tables".) Who reached for arrow syntax unprompted? (Note: L31 will name it; premature `->` use is fine if grounded.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 10 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
