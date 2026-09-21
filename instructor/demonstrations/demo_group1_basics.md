# Demonstrations · Group 1 — Toolchain, Translation, Variables, Types, I/O (L01–L04)

**Instructor-only scripts.** Each demo: preparation, delivery sequence, questions,
expected observations, common mistakes, debugging variation, extension, and
**verified output** (compiled under the course contract; compiler/standard on
file in [BUILD_REPORT.md](../../BUILD_REPORT.md)). Planned errors are
**edit-in-place** — never open a pre-broken file. Full rules:
[../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) § 1.6,
[../DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) § 2.

---

## DEMO-01 · First C++ Program, Compile, Run (L01)

- **Objective:** show the full edit→compile→run cycle and the first compile error, narrated.
- **Preparation:** empty editor buffer; terminal sized for the room; `g++ --version` pre-run to display the toolchain.
- **Source:** [examples/hello_world.cpp](../../examples/hello_world.cpp) — built live from scratch, then compared against the repository file.
- **Delivery sequence:**
  1. Type the program line by line, *narrating intent before each line* ("a program needs exactly one starting point — `main`").
  2. Compile with the contract: `g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello` — before running, ask: "what did the compiler *give* me?" (an executable, not output).
  3. Run `./hello`; observe output.
  4. **Planned error:** delete the semicolon on line 8. Predict *before* compiling: error class? Compile → read the diagnostic with the 3-step ritual → fix → re-run.
- **Questions:** "Which stage failed just now — and how do you know?" · "Why doesn't the compiler fix it for you?" · "What would `return 0;` change if we removed it?" (Answer honestly: defined behavior — `main` is special; `return 0` is implied; removing it compiles clean — a nice "the standard is precise" moment.)
- **Expected observations:** clean compile → `Hello, C++!` / `Compiled with the course contract.`; after the error, a `expected ';'` diagnostic pointing at/near the edited line.
- **Common student mistakes:** typing the error *back in* when copying from the board; thinking the executable is "the compiler's output" (it is the *input* to the OS).
- **Debugging variation:** rename `main` to `mian` → **linker** error (`undefined reference to 'main'` or equivalent) — the L02 three-classes lesson delivered physically.
- **Extension:** add a second statement; predict output before compiling.
- **Verified output:**
  ```
  Hello, C++!
  Compiled with the course contract.
  ```
- **Instructor notes:** this is many students' first-ever compile; celebrate the *error* as the second-most-important output. Do not rush the diagnostic reading — the ritual (first error → anchor word → restate) starts here and never stops.

---

## DEMO-02 · From Source to Executable: the Translation Pipeline Live (L02)

- **Objective:** make the four stages (preprocess → compile → assemble → link) *observable* by classifying three planted errors, one per failure class.
- **Preparation:** compile `examples/hello_world.cpp` once so the baseline is fast; have `examples/io_age_check.cpp` open for the anatomy read; rehearse all three error runs (they take 20 s each).
- **Sources:** [examples/hello_world.cpp](../../examples/hello_world.cpp) (error vehicle), [examples/io_age_check.cpp](../../examples/io_age_check.cpp) (code-reading anatomy).
- **Delivery sequence:**
  1. Anatomy read of `io_age_check.cpp` top to bottom: `#include` (preprocessor's food), declarations (compiler's), `main` (the linker's anchor), statements (runtime's). Attach each region to the stage that owns it — the pipeline has *owners*.
  2. **Planned error 1 (compile):** delete a `;`. Diagnostic names a line → "compile stage: the compiler read your file and objected."
  3. **Planned error 2 (link):** rename `main` → `mian`. Compile *succeeds*; the linker then fails with `undefined reference to 'main'` (wording is toolchain-specific — say so). The lesson: errors can come from a stage you never see.
  4. **Planned error 3 (runtime/logic):** swap two `cout` lines so the prompt prints *after* the read. Clean compile, clean link, wrong behavior — the third class has no diagnostic; only tracing finds it.
  5. Board table: stage → error class → who names it → what evidence it leaves.
- **Questions:** "Why did the linker error not appear when the compiler ran?" · "Which class of error can the tools *never* catch for us?" · "In `#include <iostream>`, who acts on that line?"
- **Expected observations:** three failures, three different signatures; the table filled from evidence, not slides.
- **Common student mistakes:** calling every error "syntax error"; believing `#include` copies "the whole library" (it copies declarations — say it simply: "the menu, not the kitchen").
- **Debugging variation:** hand out a mystery diagnostic (one per pair, drawn from the semester's common three) — classify stage *before* reading the fix.
- **Extension:** `-E` flag tease: "the preprocessor's output is a file too" — show one line, do not drown in it.
- **Verified output:** baseline `Hello, C++!` / `Compiled with the course contract.`; link error text per toolchain (verify wording on the teaching machine before class); runtime variant prints the read's behavior without a visible prompt.
- **Instructor notes:** the three-runs rhythm is deliberately repetitive — classification, not diagnosis, is today's skill. The table comes back in every debug lecture; keep it visible all week.

---

## DEMO-03 · Variables and Built-in Types (L03)

- **Objective:** make types visible (sizes, values, `const`) through prediction and observation.
- **Preparation:** compile `examples/types_and_sizes.cpp`; rehearse the `sizeof` table on the teaching machine (sizes are compiler-documented, not "the truth" — say so).
- **Source:** [examples/types_and_sizes.cpp](../../examples/types_and_sizes.cpp).
- **Delivery sequence:**
  1. Predict-then-run the size table (`sizeof(int)` etc. — votes before each).
  2. Declare one variable per type with a value; print each; ask "why this type for this datum?" per line.
  3. **Planned error:** use a declared-but-uninitialized `int` in a print — observe the garbage *once*, silently; then explain uninitialized storage (bank [MC-10](../misconception-bank/misconception_bank.md), home lecture L03/L04) and show the contract's warning.
  4. Add `const int seats = 30; seats = 40;` → compile error; read it; "the promise was enforced."
- **Questions:** "Why is `bool` a whole byte, not a bit?" · "When would `char` be the right type for a *number*?" · "What does `const` buy *you* (not the compiler)?"
- **Expected observations:** sizeof values per platform (document on the board as "this machine's truth"); garbage value for the uninitialized read; the const-assignment compile error.
- **Common student mistakes:** "int is always 4 bytes" (it's *typically*; the standard guarantees minimums); initializing with a wrong-type literal and not noticing the narrowing warning.
- **Debugging variation:** swap two initializers (`int age = "Ali";`) → type-mismatch diagnostic; classify and read.
- **Extension:** print `sizeof(long long)` vs `sizeof(int)` and discuss when counting would overflow int (leads to MC-03's neighbor: limits).
- **Verified output:** deterministic modulo the uninitialized garbage — instructor verifies locally before class (contract flags); the deterministic lines (sizes, typed values, const error) are stable.
- **Instructor notes:** the garbage-value moment is *theater with a point* — resist explaining before the class reacts. The "sizeof is this platform's documented truth" line prevents a semester of "but the book said 2!"

---

## DEMO-04 · Console I/O with Validation (incl. the getline Interplay) (L04)

- **Objective:** make the stream model observable: valid read, failed read, range rejection, and the `>>`→`getline` newline bite.
- **Preparation:** compile `examples/io_age_check.cpp` and the companion program below (`instructor/demonstrations/demo04_mixed_read.cpp`); rehearse typing `abc` at the prompt live.
- **Sources:** [examples/io_age_check.cpp](../../examples/io_age_check.cpp) (age validation); `demo04_mixed_read.cpp` (below — the MC-13 interplay, fixed variant); bank entry [MC-13](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. `io_age_check`: valid age → accept. Type `abc` → detect-and-refuse (stream state guard). Type `130` → range-reject. Three behaviors, three failures handled.
  2. **Planned error:** delete the `if (!cin)` guard → the program *accepts garbage silently* (or spins) — the students' future lab nights, on stage.
  3. `demo04_mixed_read`: run the fixed variant (int then full-name line reads correctly).
  4. **Planned error (act 2):** remove the `std::cin.ignore(...)` line live → the name read comes back **empty** — the newline left by `cin >> age` is consumed by `getline`. Re-add, re-run, fixed. Trace the pipe picture both times.
- **Questions:** "Where exactly is the newline character *right now*?" · "Why doesn't `>>` eat it?" · "Which of the three failure behaviors does your lab program implement today?"
- **Expected observations:** exactly the three tier-0 behaviors; then the empty-name artifact and its fix.
- **Common student mistakes:** believing the empty string means "getline is broken"; re-prompting without clearing state (the L30 lesson is born here as a question, answered there).
- **Debugging variation:** feed `25 Maria` on one line (space-separated) → works differently again; perfect segue to "know your input's shape."
- **Extension:** make the age prompt re-ask once (bounded retry) — a 5-line taste of L30's tier 1.
- **Verified output (demo04_mixed_read.cpp, input `25` + `Maria Chen`):**
  ```
  Age: 25
  Name: Maria Chen
  Hello Maria Chen, age 25
  ```
- **Instructor notes:** run the broken-name act *twice* (broken → fixed) — the before/after contrast is what sticks. This program is compiled and verified before every class; it is the semester's most-reused demo.

**Companion source — `instructor/demonstrations/demo04_mixed_read.cpp`:**

```cpp
// DEMO-04 companion · cin >> then getline interplay (MC-13, fixed variant).
// build: g++ -std=c++17 -Wall -Wextra -pedantic demo04_mixed_read.cpp -o demo04
// input: 25<Enter>Maria Chen<Enter>
//
// Live act: delete the cin.ignore(...) line, rebuild, rerun -> the name read
// is EMPTY (getline consumes the newline `>>` left behind). Re-add the line,
// rebuild, rerun -> fixed. Trace the pipe picture each time.

#include <iostream>
#include <limits>
#include <string>

int main()
{
    int age{};
    std::string name;

    std::cout << "Age: ";
    std::cin >> age;

    // Remove this line during the demo to reproduce the empty-name bug:
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << ", age " << age << '\n';
    return 0;
}
```
