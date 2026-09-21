# L01 · What Is a Program? Computers, Algorithms, and the C++ Toolchain

**Module 1 — Introduction to Programming and C++ · Week 1 · Lecture 1 of 32 · 120 minutes**
**Outcomes:** CLO-1 · PF-1.1, PF-1.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

By the end of this lecture, students can:

1. Define *algorithm* and *program*, and give one everyday algorithm in
   precise numbered steps (PF-1.1).
2. Order the stages source code → preprocessor → compiler → assembler →
   linker → executable, and state what each stage consumes/produces (PF-1.1).
3. Describe the stored-program idea: memory holds both instructions and data,
   and the CPU fetches–decodes–executes (PF-1.2).
4. Name the two families of translation (compilation vs interpretation) and
   place C++ correctly as compiled (PF-1.2).

## Prerequisites

None. Assumes secondary-school algebra only; no computing background.

## Concept sequence

1. Why program? (automating repetition, data processing at scale)
2. Algorithms vs programs: recipe metaphor, precision requirement
3. The stored-program computer in 4 boxes (CPU, RAM, storage, I/O)
4. From source code to running program: the toolchain pipeline
5. Compilers vs interpreters; why C++ compiles to machine code
6. The course toolchain: g++, editor, command line (verified live)

## Teaching topics (detailed)

- **Algorithms:** finiteness, unambiguity, effectiveness; everyday examples
  (tea-making fails the unambiguity test — a teachable failure).
- **CPU/RAM model:** instruction + data in one memory; fetch-decode-execute
  with a 3-instruction toy program.
- **Toolchain stages:** `hello_world.cpp` → preprocessor (`#include` pasting)
  → compiler (object file) → linker (standard library + your code → `.exe`);
  emphasize *linker errors* get their own name later (L02).
- **Compiled vs interpreted:** C++ vs Python one-slide contrast; portability
  via recompilation.
- **C++17 standard and the compile contract** (g++ 17 flags) — connect to
  [docs/CPP_STANDARD.md](../../docs/CPP_STANDARD.md).

## C++ examples required

| File | Role in lecture |
|---|---|
| `hello_world.cpp` ✅ | first build; walk the pipeline on it |
| (live-typed) `greet.cpp` | instructor types a 6-line variant live, then deliberately introduces a typo |

## Conceptual explanation (beginner-first)

Before any formal words: a **recipe**. A recipe is a list of steps that turns
ingredients into a cake. An algorithm is the same idea, but the steps must be
so precise that *no judgment calls* remain — "add salt to taste" is forbidden;
"add 2 grams of salt" is allowed. A **program** is an algorithm written in a
language a computer can translate, because a computer has no judgment at all:
it does *exactly* what the text says, which is why imprecise steps break.

Why do we care? Because a computer can repeat the steps *billions of times a
second without tiring or improvising*. That is the whole value proposition:
humans design the steps once; the machine executes them endlessly.

The last intuition before terminology: the computer does not understand the
text you write. A **translator** (the compiler) converts your text into the
computer's native language (machine code) *once*, and the result (the
executable) is what actually runs. This is why C++ is fast: translation
happens before execution, not during.

## Terminology and definitions

| Term | Beginner definition | Precise note |
|---|---|---|
| Algorithm | A finite list of unambiguous steps that solves a problem | Finiteness + definiteness + effectiveness |
| Program | An algorithm expressed in a programming language | The thing a compiler consumes |
| Source code | The human-readable text of a program (`.cpp` files) | What you edit |
| Compiler | Translates source code into machine code | Reports syntax errors; cannot run code |
| Linker | Joins your compiled code with library code into one executable | "Undefined reference" errors come from here |
| Executable | The runnable file produced by the linker | The OS loads and runs it — not the compiler |
| Machine code | The CPU's native instructions (binary) | Generated, never hand-written in this course |
| Preprocessor | Stage that performs text-level edits like `#include` | Runs *before* compilation proper |
| RAM | Working memory: fast, forgets when power is lost | Where a running program lives |
| CPU | The component that executes instructions, one after another | Fetch–decode–execute cycle |

## Syntax and C++ examples

The full minimal program is introduced formally in L02; today we only *build
and run* one so the pipeline is concrete:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello
./hello
```

| Piece | Meaning |
|---|---|
| `g++` | The compiler program we invoke |
| `-std=c++17` | Which dialect of C++ to accept (course standard) |
| `-Wall -Wextra -pedantic` | Turn on helpful warnings (course contract) |
| `hello_world.cpp` | The source file to translate |
| `-o hello` | Name the produced executable `hello` |
| `./hello` | Ask the OS to load and run it |

## Line-by-line code explanation

`examples/hello_world.cpp`, in pipeline order:

1. `#include <iostream>` — the preprocessor pastes in declarations for
   input/output (`cout` lives here). Runs *before* compiling.
2. `int main()` — the entry point; the OS calls this function to start your
   program. Every program has exactly one.
3. `std::cout << "Hello, world!\n";` — send text to the standard output
   stream. `\n` ends the line.
4. `return 0;` — report success to the OS (0 = success by convention).

When you run `g++ ... hello_world.cpp -o hello`:
1. the **preprocessor** produces the pasted source,
2. the **compiler** translates it into an object file,
3. the **linker** stitches the object file to the standard library and
   writes the executable `hello`,
4. `./hello` asks the **OS** to load it into RAM and hand it to the **CPU**.

## Output prediction questions (with answers)

1. *You rename `hello` to `hello_v2` with `-o hello_v2`. Does the program's
   output change?* — No; the executable's name has no effect on behavior.
2. *You re-run `g++` on the same file twice. Does it run the program?* — No;
   the compiler only translates. A separate `./hello` step runs it.
3. *Your program contains `int main() { return 0; }` with no output at all.
   Is it a valid program?* — Yes; it compiles, runs, and exits successfully
   while printing nothing.

## Common errors and debugging examples

| Error | Diagnostic / symptom | Fix |
|---|---|---|
| Compile step skipped | `./hello: No such file or directory` | Run the `g++` command first, then `./hello` |
| Wrong file compiled | `undefined reference to 'main'` (linker) | Compile the file that contains `main()` |
| Typo in filename | `fatal error: hello_wrold.cpp: No such file...` | Check spelling; the file must exist |
| Expecting the compiler to run code | "I compiled but nothing printed" | Compilation ≠ execution; run the executable |

Standard-C++ note: everything above is standard; where the *printed form* of
an error message differs between compilers, the meaning (missing file,
missing `main`) is the same — only the wording varies.

## Classroom demonstrations

1. **The pipeline, live:** build `hello_world.cpp`, run it; then delete the
   executable and run again to prove the compiler is not what executes.
2. **The preprocessor's work:** temporarily break the include line
   (`#include <iostreamm>`) and read the diagnostic: the *compiler* now
   fails on unknown names — showing which stage complained.
3. **Cross-check terminology:** point at each pipeline stage on the board
   diagram while performing it live, so the vocabulary lands on concrete
   actions.


## Guided student activities
**"Be the CPU" (20 min):** pairs; one student is the CPU, one is the RAM.
The RAM holds written instruction cards; the CPU executes literally —
demonstrating why imprecise steps break. Debrief connects to the precision
requirement of algorithms.

## Practice problems
- Write the "largest of three numbers" as numbered English steps (then find a
  classmate's ambiguity).
- Order 6 shuffled toolchain-stage cards; state each stage's input/output.
- Classify 6 short scenarios as compilation vs interpretation.
- (🟡 stretch) Find the real ambiguity in "sort the list quickly".

## Common student misconceptions

- "The compiler runs the program." (It only *translates*; the OS loads and
  runs the executable.)
- "C++ is interpreted because IDEs feel instant."
- "RAM and disk are the same kind of memory." (Address the speed/volatility
  difference explicitly; it returns in M14.)
- "An algorithm must be written in a programming language."

## Summary

A program is a precisely written algorithm; the computer executes it
literally, without judgment. Your text (source code) is translated —
preprocessed, compiled, linked — into an executable, and the OS runs *that*.
C++ is compiled, which is where its speed comes from and where its error
reports come from. Next lecture (L02) dissects the program text itself and
introduces the three error classes you will meet all semester.

## Exit ticket / formative assessment

1. In one sentence: what does the linker do that the compiler does not?
2. Put in order: *link · compile · preprocess · execute*.
3. T/F: An algorithm becomes a program when written in a language a computer
   can translate. (Explain your T/F choice in one clause.)

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Hook: "programs are everywhere" + course logistics | 10 |
| Algorithms & precision + "Be the CPU" activity | 35 |
| Break | 10 |
| Stored-program model & toolchain pipeline (with live build) | 40 |
| Compiled vs interpreted; C++17 contract | 10 |
| Exit ticket + preview of L02 | 15 |
