# L02 · Anatomy of a C++ Program: `main`, Statements, Compilation, and the Three Error Classes

**Module 1 — Introduction to Programming and C++ · Week 1 · Lecture 2 of 32 · 120 minutes**
**Outcomes:** CLO-1 · PF-1.3, PF-1.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Identify the structural parts of a minimal C++ program — preprocessor
   directive, `main` function, statements, return statement, comments — and
   predict the compile failure caused by removing each (PF-1.3).
2. Distinguish `'\n'` from `std::endl` and explain why output operators chain
   (PF-1.3).
3. Classify an error as **syntax**, **runtime**, or **logic** from either its
   compiler diagnostic or its symptom, and name the tool that catches each
   class (PF-1.4).

## Prerequisites

L01 (toolchain pipeline; can build and run `hello_world.cpp`).

## Concept sequence

1. Read `hello_world.cpp` line-by-line as a dissection
2. Statements, sequenced execution, and blocks
3. Comments (why-write vs what-happens)
4. Output details: chained `<<`, `'\n'` vs `endl`
5. The three error classes, with one live demo of each
6. Reading a diagnostic top-down (file, line, message, caret)

## Teaching topics (detailed)

- **`#include <iostream>`** — a preprocessor paste, not a Python-style import;
  why the `;` after include would be wrong.
- **`int main()`** — the mandated entry point; exactly one per program;
  returns `int` (0 = success).
- **Statements & sequencing:** each `;` ends a statement; execution is
  strictly top-to-bottom — no control flow yet (deliberately: decisions come
  in Module 4).
- **Output chaining:** `std::cout << "a" << 'b' << 42 << '\n';` — evaluate
  left to right, mix string literals, chars, numbers.
- **`'\n'` vs `std::endl`:** newline vs newline+flush; habit: `\n` unless
  debugging timing.
- **Error taxonomy with demos:** missing `;` (syntax), divide-in-progress
  hang or `vector` OOB later (runtime), wrong-but-compiling average formula
  (logic — *the compiler's silence is the danger*).
- **Diagnostic reading protocol:** first error first, read message, go to the
  line, recompile after each fix.

## C++ examples required

| File | Role |
|---|---|
| `hello_world.cpp` ✅ | dissection target |
| (live) `anatomy_break.cpp` | instructor breaks it 4 ways: no `;`, missing `}`, wrong include, `main` renamed |

## Conceptual explanation (beginner-first)

Think of a program as a list of instructions for a very obedient but very
literal worker. Every instruction is one **statement** — one complete command
ending in a semicolon, like a sentence ending in a period. The worker reads
them top to bottom and does exactly what each says, in order. If you want a
different order, you write the lines in a different order; there is no magic.

Three kinds of text live in a program: instructions (do things), comments
(notes for humans — the worker skips them), and **directives** (instructions
for the *translator*, not the worker, like `#include`, which pastes in a
helper file before translation even starts).

Why care about the three error classes now? Because each class has a
different *fixing tool*, and beginners waste hours using the wrong tool:
- **Syntax errors**: your text breaks the grammar. The translator catches
  them and prints a diagnostic — you literally cannot run the program.
- **Runtime errors**: the text is grammatical, but an instruction fails
  *while running* (crash, hang).
- **Logic errors**: everything runs, and the answer is wrong. The translator
  is silent — this is why we trace and test (Modules 6, 8).

## Terminology and definitions

| Term | Definition |
|---|---|
| Statement | One complete instruction, ending with `;` |
| Expression | A piece of code that produces a value (`2 + 3`) |
| Directive | An instruction for the preprocessor (`#include <iostream>`) |
| Comment | Text ignored by the compiler: `//` to end of line, `/* ... */` ranges |
| Stream | A channel data flows through (`cout` = out to screen, `cin` = in from keyboard) |
| Operator | A symbol performing an action (`<<` inserts into a stream) |
| Syntax error | Grammar violation, caught at compile time |
| Runtime error | Failure while the program runs (crash, hang) |
| Logic error | Program runs to completion but produces wrong results |
| Diagnostic | The compiler's error message: file, line, explanation |
| `std::endl` | Newline **plus** a flush (forces pending output out now) |

## Syntax and C++ examples

```cpp
#include <iostream>                 // directive for the preprocessor

int main()                          // entry point: OS calls this
{
    std::cout << "Hello!\n";        // statement 1: print a line
    std::cout << 2 + 3 << '\n';     // statement 2: print an expression
    std::cout << 'A' << "\n";       // statement 3: a char, in single quotes
    return 0;                       // statement 4: success code to the OS
}
```

| Piece | Meaning |
|---|---|
| `std::cout` | The standard output stream (from `<iostream>`) |
| `<<` | "insert into the stream"; chains left to right |
| `"..."` | A string literal (any text, double quotes) |
| `'A'` | A char literal — ONE character, single quotes |
| `\n` | Newline character (no flush) vs `std::endl` (newline + flush) |
| `// text` | Comment: for humans, skipped by the compiler |

## Line-by-line code explanation

Walking `examples/hello_world.cpp` and the program above:

1. `#include <iostream>` — not a Python-style import: the preprocessor
   *literally pastes* the declarations of `std::cout` here. No semicolon
   follows (it is not a statement).
2. `int main() {` — every C++ program starts at `main`; the `{` opens its
   body; the matching `}` closes it. Exactly one `main` per program.
3. `std::cout << "Hello, world!\n";` — the `<<` evaluates left to right;
   first the stream, then the text. The `;` ends the statement.
4. Chaining: `std::cout << "a" << 'b' << 42 << '\n';` prints `ab42` then a
   newline — three inserts, one statement.
5. `return 0;` — hand the value 0 back to the OS: "all good".
6. `}` — end of `main`'s body; reaching it ends the program.

## Output prediction questions (with answers)

1. `std::cout << "2+3";` — what prints? — The text `2+3` (inside quotes,
   nothing is computed).
2. `std::cout << 2 + 3 << '\n';` — and now? — `5` (no quotes: an expression
   is evaluated first).
3. `std::cout << "A" << 'A' << '\n';` — ? — `AA` (a string of one letter and
   a char literal print identically, but they are different types).
4. *Remove the `;` from line 3. Error class?* — Syntax; the diagnostic names
   the line, and no executable is produced.
5. *Replace `'\n'` with `"\n"`. Behavior?* — Identical here (one-character
   string prints the same); the types differ, which matters from Module 11.

## Common errors and debugging examples

| Error | Diagnostic / symptom | Fix |
|---|---|---|
| Missing `;` | `error: expected ';' before '}' token` | Read the FIRST diagnostic; add it |
| Missing `}` | `error: expected '}' at end of input` | Match braces pairwise while writing |
| `'A'` typed as `"A"` in a char slot | Usually compiles; wrong type bites later | Single quotes = char, double = string |
| `std::count` instead of `std::cout` | `'count' is not a member of 'std'` | Typo; re-read the diagnostic's name |
| Quotes: straight vs smart (from slides/chat) | `stray '\\342' in program` | Retype quotes as plain ASCII `"` |
| Logic error: printing `2+3` as text | Compiles, prints `2+3` | Quotes off when you want math |

Debugging protocol (used every week): read the **first** diagnostic, go to
that file:line, fix exactly that, recompile. One fix per compile.

## Classroom demonstrations

1. **Anatomy dissection:** project `hello_world.cpp`; delete one part at a
   time (include, semicolon, closing brace), recompile each time, and read
   the diagnostic aloud — students see the compiler's precision.
2. **The silent error:** change a correct formula to a plausible-but-wrong
   one; show it compiles and runs — logic errors give no warnings.
3. **Chain vs separate statements:** print the same three items with one
   chained statement, then three statements — identical output.

## Guided student activities
**Diagnostic triage relay (20 min):** teams rotate through 6 broken 5-line
programs; each team classifies the error class, underlines the culprit token,
and writes the one-character (or one-word) fix. Fastest correct team explains
their reasoning.

## Practice problems
- Annotate a printout of `hello_world.cpp` with the role of every token group.
- Predict output of 3 chained-`<<` statements (including one with an
  arithmetic expression `2+3` — deliberate foreshadowing of Module 3).
- Match 6 diagnostics (as printed text) to error classes and name the fix.
- (🟡 stretch) Explain why `int Main()` fails but `int main()` works.

## Common student misconceptions

- "Errors are bad." → Reframe: diagnostics are the compiler *helping*; the
  dangerous error is the one it cannot see (logic).
- "The last error message is the important one." (First one is.)
- "Comments change program speed/behavior."
- "`main` is a keyword." (It's a function *you* define; the OS calls it.)

## Summary

A C++ program is statements (`;`-terminated) executed strictly top to
bottom, inside the one required `main` function, with `#include` pasting in
library declarations before compilation. Output flows through `std::cout`
with chained `<<`; `\n` ends lines. Errors come in three classes — syntax
(compiler catches), runtime (crash while running), logic (silent wrong
answers) — and each class needs a different tool. Reading the first
diagnostic carefully is the semester's first habit. Next (L03): giving
names to values with variables and types.

## Exit ticket / formative assessment

1. Classify: *"Program compiles, runs, prints the average of 2 and 5 as 3."*
   (logic — integer division foreshadowing!)
2. What are the two jobs of `std::endl` that `'\n'` does not do?
3. Write the minimal legal C++ program from memory.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (L01 exit ticket) + pipeline warm-up | 10 |
| Anatomy dissection of `hello_world.cpp` | 30 |
| Output details (chaining, `'\n'` vs `endl`) | 20 |
| Break | 10 |
| Three error classes — live break-and-fix demos | 25 |
| Diagnostic triage relay activity | 15 |
| Exit ticket + Module 2 preview | 10 |
