# Demonstrations · Group 6 — Dynamic Memory, Structures, Files, Robust Programs, Classes (L27–L31)

**Instructor-only scripts.** Conventions as in
[demo_group1_basics.md](demo_group1_basics.md): edit-in-place planned errors,
contract build, verified output, 3-step diagnostic ritual.

---

## DEMO-28 · Dynamic Memory: Leak, Dangle, Double-Delete — and the Vector (L27)

- **Objective:** show the three canonical ownership failures *live*, then make them impossible with `std::vector`.
- **Preparation:** compile `examples/dynamic_memory_caution.cpp` in a scratch dir; rehearse the leak loop's counter visibility and the dangling-use crash (verify its actual symptom on your toolchain first — garbage or crash).
- **Source:** [examples/dynamic_memory_caution.cpp](../../examples/dynamic_memory_caution.cpp); bank entries [MC-18](../misconception-bank/misconception_bank.md), [MC-24](../misconception-bank/misconception_bank.md), [MC-25](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. `new`/`delete` anatomy: the arrow to heap memory drawn; the two-step ownership (create → release) named.
  2. **Failure 1 (leak):** loop `new` without `delete` — the counter climbs; "that memory is yours forever." Fix: delete in the loop.
  3. **Failure 2 (dangling):** use the pointer after delete — crash or garbage (classify honestly: UB, symptom toolchain-specific). Fix: null-out discipline.
  4. **Failure 3 (double-delete):** delete twice — crash. The ownership rule stated: *exactly one owner, exactly one delete*.
  5. The same program with `std::vector` — none of the failures *possible*. "The container is the grown-up."
- **Questions:** "What did the leak cost — and who pays, and when?" · "Why is the dangling read not an *error* to the compiler?" · "What did vector delete from the syllabus of things you can get wrong?"
- **Expected observations:** climbing counter; the dangling symptom; the double-delete crash; the vector version clean.
- **Common student mistakes:** `new[]`/`delete` mismatches (named out of scope); assuming the OS "cleans up at exit anyway" (true sometimes, wrong as a design).
- **Debugging variation:** symptom-only: "my program's memory grows every loop pass" — find the allocation without a matching release.
- **Extension:** add a counter of live allocations; predict the count at exit in both versions.
- **Verified output:** deterministic except UB symptoms — verify locally; keep the leak loop bounded (10 iterations) and the crash runs *sandboxed* (never on the projector's host machine unbounded).
- **Instructor notes:** this demo sanctions `vector` for labs/projects — say so explicitly so students hear the permission. The ownership rule (*one owner, one delete*) is the Module 14 takeaway sentence.

---

## DEMO-29 · Structures: Aggregate, Initialize, Pass, Nest (L28)

- **Objective:** make structs feel like "a box with labeled compartments" — then pass one to a function and watch the copy semantics.
- **Preparation:** compile `examples/struct_records.cpp`; board compartments plan for the record type; rehearse the missing-semicolon diagnostic.
- **Source:** [examples/struct_records.cpp](../../examples/struct_records.cpp); bank entry [MC-19](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Define the record struct live on the board (compartments drawn); initialize with brace syntax; print one field.
  2. Copy-assign one struct to another → two independent boxes (predict, run, confirm).
  3. **Planned error:** forget the `};` semicolon → read the diagnostic *together*; the "the error is often the line *after*" ritual in its natural habitat.
  4. Pass a struct to a function by value → modify inside → caller's copy unchanged; then pass by reference → changed. (L26's vote, re-run with a record.)
  5. Arrays of records: traverse, sort-by-member (index-sort from L24 keeping records whole); **planned error 2:** return a *local* struct by... nothing wrong! (structs return by value safely — deliberately *not* an error: the class predicts doom and learns when copying is safe.)
- **Questions:** "After `Weather b = a;`, how many compartments exist?" · "Which function call changed the caller's data — and what single character made the difference?" · "Why do functions that only *read* a struct deserve `const &`?" (L26 preview.)
- **Expected observations:** independent copies; the cascading diagnostic; the by-ref change landing in `main`.
- **Common student mistakes:** the missing semicolon (bank MC-19's 1-in-3 claim); assuming struct copy is a reference (it isn't); field access with `.` vs `->` confusion deferred to L25.
- **Debugging variation:** symptom-only: "my function 'updated' the record but main disagrees" — pass-by-value diagnosis via the frame picture.
- **Extension:** nest a struct inside a struct (date inside record); predict and run the access chain `r.date.year`.
- **Verified output:** deterministic; e.g. `a.temp=31.5 / b.temp=31.5 (after copy) / after by-value: a unchanged / after by-ref: a updated` — verify exact values locally.
- **Instructor notes:** the semicolon-after-struct is the course's most reliable Module 14 diagnostic-reading opportunity — spend real time on the "look one line *before* the reported line" rule; it generalizes to every brace type in C++. The return-local-struct non-error is the course's honest-cope lesson: not every scary-looking thing is UB.

---

## DEMO-30 · File Handling: Write, Read, and the Failure Case (L29)

- **Objective:** make the open-check reflex non-negotiable by *showing the silent empty-read* before showing the guard.
- **Preparation:** compile `examples/file_read_write.cpp` and `examples/robust_pipeline.cpp` in a scratch directory (they create/read files in the CWD); rehearse the missing-file run; check the lab machines can write to the demo directory.
- **Sources:** [examples/file_read_write.cpp](../../examples/file_read_write.cpp), [examples/robust_pipeline.cpp](../../examples/robust_pipeline.cpp); bank entry [MC-23](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Write phase: program writes 5 records to `scores.txt`; open the file in an editor — the artifact is *real*, on disk, outside the program. Let that land.
  2. Read phase: read it back, echo to screen. Deterministic; run twice, same output.
  3. **Planned error:** delete `scores.txt` (or point at `no_such.txt`) and run the unguarded read → the loop body *never executes* (silent zero). "Did it crash? No. That's the danger."
  4. Add the guard (`if (!in) { ... }`) live; rerun; the failure is now *announced*. Point at `robust_pipeline.cpp` as the full production shape.
  5. **Planned error 2:** the `while (!in.eof())` read loop → the last record processed *twice* (the eof extra-record artifact); fix with the read-in-condition idiom.
- **Questions:** "What did the unguarded program do with a missing file — crash, hang, or something worse?" · "Where else in this course have we seen 'silence' as the failure mode?" (L07's assignment-in-condition; L23's unsorted binary search — the *pattern* of silent failure.) · "What should a program do after announcing a failure — exit? default? retry?"
- **Expected observations:** the real file on disk; the silent zero; the announced failure after the guard; the doubled last record and its fix.
- **Common student mistakes:** `ifstream in("x.txt");` then reading without `if (!in)`; assuming the file path is relative to the *source file* (it is relative to the CWD — demonstrate by running from a different directory); forgetting the close (automatic on scope exit — reassure).
- **Debugging variation:** symptom-only: "my program prints nothing and exits 0" — the empty-read family; check the open state first.
- **Extension:** append mode (`ios::app`) vs truncation (`ios::trunc` default) — run the write program twice and observe the difference.
- **Verified output:** deterministic for a fixed input file; e.g. `wrote 5 records / read back: 88 92 79 85 91 / [missing-file run] ERROR: cannot open no_such.txt` — verify exact wording locally; the *unguarded* variant's behavior (silent) should be staged as a separate pre-built binary if you prefer not to edit live.
- **Instructor notes:** the "silence as failure" through-line (L07 → L23 → L29) is the course's quiet theme — name it explicitly here; students who see the *pattern* debug faster in every module. The CWD lesson prevents the classic "it works in my IDE" lab ticket.

---

## DEMO-31 · Robust Input: Stream-State Repair and the Exception Contract (L30)

- **Objective:** run the full state-repair loop (`clear` + `ignore` + re-ask), produce the spinning-loop bug *in public*, and make the throw-catch contract concrete.
- **Preparation:** compile `examples/robust_pipeline.cpp`; rehearse the messy-input transcript (letters at every prompt) and the uncaught-exception terminate (bounded; verify the toolchain's exact terminate wording); board plan: the pipe picture with the stream state as a *flag*.
- **Source:** [examples/robust_pipeline.cpp](../../examples/robust_pipeline.cpp); bank entries [MC-06](../misconception-bank/misconception_bank.md), [MC-26](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Tier-0 recap in one run: a letter typed at an `int` prompt — failed state, the read refused.
  2. The full repair loop predict-then-run: `clear()` (unstick the flag) + `ignore()` (drain the junk line) + re-ask (bounded retries) — run it with adversarial input and it survives.
  3. **Planned error:** `clear()` *without* `ignore()` — the junk stays, the loop spins forever (bounded run). The pipe picture explains it instantly: the flag is clean but the junk is still queued.
  4. Throw-catch shape: `throw runtime_error("...")`, `try` block, `catch (const runtime_error& e)` — predict-then-run on the negative-input path. **Planned error 2:** remove the matching `catch` → terminate message, non-zero exit; draw the propagation arrow climbing the L16 frame stack.
  5. The course division stated: *guards for expected input problems; exceptions for rule violations* — one example of each from `robust_pipeline`.
- **Questions:** "What exactly does `clear()` clear — and what does it *not* clear?" · "Why does the bounded-retry limit matter beyond politeness?" · "Who is responsible for recovery — the thrower or the catcher?" · "Why is the catch clause `const runtime_error&` — what does the `&` save?" (L26's alias lesson, reused.)
- **Expected observations:** the surviving transcript; the spinning loop; the caught message; the terminate path.
- **Common student mistakes:** `clear()` without `ignore()` (the spin); unbounded re-ask loops (no cap); catching by value (flag the `const &` convention; slicing named out of scope); throwing for *expected* input problems (the guard is the right tool there).
- **Debugging variation:** symptom-only: "my re-prompt loop never stops no matter what I type" — locate the missing half of the repair. Second symptom: "terminate called after throwing..." — trace the propagation path; who should have caught it?
- **Extension:** make the retry cap configurable and test all three exits (success, cap reached, EOF); add a second exception type (`invalid_argument`) and a second catch clause; discuss ordering.
- **Verified output:** deterministic per transcript; e.g. adversarial transcript ends with valid values and a summary line; `caught: temperature below -50 / [uncaught variant] terminate called after throwing an instance of 'std::runtime_error'` — verify exact wording locally (terminate text is compiler-flavored; say so), keep the spin bounded.
- **Instructor notes:** the spinning-loop act is the payoff of the L04 pipe picture from Module 2 — students recognize it instantly now. Honest scope note: smart pointers, RAII, and custom exception hierarchies are CS2; today is the *contract*, not the machinery. This is the lecture that powers Lab 15; flag it in the lab briefing.

---

## DEMO-32 · Classes: the Struct Refactored Live (L31)

- **Objective:** the L28 struct refactored into a class live — members go private, behavior moves in, the constructor enforces the invariant.
- **Preparation:** compile `examples/first_class.cpp` and `examples/struct_to_class.cpp`; rehearse the access-control diagnostic and the rejected-construction path; board plan: the wall drawing.
- **Sources:** [examples/first_class.cpp](../../examples/first_class.cpp), [examples/struct_to_class.cpp](../../examples/struct_to_class.cpp); bank entries [MC-20](../misconception-bank/misconception_bank.md), [MC-21](../misconception-bank/misconception_bank.md), [MC-22](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. The L28 struct on the board; the class question posed: "what *should* be illegal?"
  2. Refactor live: members go private; methods move in; the setter gains the validation the struct never had. Compile at each semantic step.
  3. **Planned error:** direct member access from `main` after privatising — the *access-control diagnostic* teaches the wall's location (compile stage).
  4. The constructor refuses a negative opening balance — "the object *cannot exist* in an invalid state; the invariant is enforced at birth." Run the rejected-construction path.
  5. Connect the ladder: L28 structs (no rules) → methods (behaviors) → classes (rules). The OOP arc in one board line.
- **Questions:** "Where does the wall live — which stage catches a breach?" · "What can a constructor never have?" (return type) · "Why is enforcement at construction stronger than checks before every use?"
- **Expected observations:** the refactor steps; the access diagnostic; the rejected construction with the object never existing.
- **Common student mistakes:** flipping everything public to silence the diagnostic (design failure — fix by *design*); writing a return type on the constructor; calling the constructor explicitly on an existing object.
- **Debugging variation:** symptom-only: "my class compiles but main can't reach anything" — everything accidentally private; the diagnostic tour names each block's access.
- **Extension:** deposit/withdraw with the invariant maintained across both ("after every method call, balance >= 0 must still hold") — the invariant sentence written per method.
- **Verified output:** deterministic; e.g. deposit(50) → balance updated; deposit(-50) → rejected with message; the access diagnostic text — verify exact wording locally before class.
- **Instructor notes:** "invariant enforced at birth" is the single most valuable OOP line in the course — deliver it slowly, twice if needed. Keep inheritance/polymorphism firmly out of scope; the course's promise is a *grounded start*, not a tour.
