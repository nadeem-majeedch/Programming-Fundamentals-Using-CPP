# L03 · Variables, Built-in Types, and Initialization (`int`, `double`, `char`, `bool`, `const`)

**Module 2 — Variables, Data Types, and Input/Output · Week 2 · Lecture 3 of 32 · 120 minutes**
**Outcomes:** CLO-2 · PF-2.1, PF-2.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Declare and initialize variables of types `int`, `double`, `char`, `bool`,
   and `const`-qualified variants, choosing the type appropriate to the
   modeled quantity (PF-2.1).
2. Predict a variable's value, type, and (approximate) memory footprint, and
   explain why reading an uninitialized variable is a defect (PF-2.2).
3. Use brace initialization `{}` and name the two reasons the course bans
   uninitialized variables (PF-2.1, PF-2.2).

## Prerequisites

L01–L02 (program anatomy; can write minimal `main` with `cout` output).

## Concept sequence

1. Why *variables*: naming values so programs can remember and recompute
2. The box-and-value diagram (typed memory cell)
3. The built-in types and what fits in each
4. Declaration vs initialization vs assignment
5. `const` — values that cannot change and why we default to them
6. Uninitialized variables: the undefined-behavior preview

## Teaching topics (detailed)

- **Types:** `int` (whole counts, ±~2.1 billion), `double` (measurements,
  ~15–16 significant digits), `char` (single character, `'A'` syntax), `bool`
  (`true`/`false`); `sizeof` demo showing 4/8/1/1 bytes.
- **Declarations:** `int score{95};` — brace init as course standard; explain
  why `{}` refuses narrowing (`int x{3.7};` won't compile — a *feature*).
- **Assignment vs initialization:** re-assignment allowed (not `const`);
  assignment is right-to-left (`total = total + 5;` — algebra lie, compute
  the right side first).
- **`const`:** `const double TaxRate{0.15};` — named constants vs magic
  numbers; renaming demo with one edit.
- **Uninitialized:** show `int x; std::cout << x;` — garbage value, no
  diagnostic; state the course rule and the reason (UB).
- **Naming:** `snake_case`, pronounceable, specific (`student_count` not `n`).

## C++ examples required

| File | Role |
|---|---|
| `types_and_sizes.cpp` ✅ | declares each type, prints values + `sizeof`; brace-init narrowing failures shown commented |
| (live) `const_demo.cpp` | magic-number version refactored to named constants in one pass |

## Conceptual explanation (beginner-first)

A program that cannot remember anything is useless — it could print, but not
compute. A **variable** is a named box in memory: it has a **name** (so you
can refer to it), a **type** (what kind of thing fits, and how many bytes it
takes), and a **value** (what is in the box right now).

Why must C++ know the type *before* the box is used? Because the type tells
the compiler how many bytes to reserve and which operations make sense:
adding two whole numbers is different, at the machine level, from adding two
decimal numbers. Declaring the type once means the compiler can check every
later use — that is the safety net beginners are actually buying.

Two habits pay for themselves all semester:
1. **Initialize immediately** (`int x{0};`): an uninitialized box contains
   garbage, and reading garbage is undefined behavior.
2. **Make values constant by default** (`const double TaxRate{0.15};`):
   anything that should not change becomes impossible to change.

## Terminology and definitions

| Term | Definition |
|---|---|
| Variable | A named, typed memory location whose value can change |
| Type | The kind of value a variable holds (`int`, `double`, `char`, `bool`) |
| Declaration | Telling the compiler a name and its type (reserving the box) |
| Initialization | Giving a variable its first value *at* declaration |
| Assignment | Replacing a variable's value later (right side computed first) |
| `const` | Promise (checked by the compiler) that a value never changes |
| Named constant | A `const` with a meaningful name, replacing a "magic number" |
| Brace initialization | `{...}` form; refuses narrowing conversions |
| Narrowing | A conversion that may lose information (`double` -> `int`) |
| Undefined behavior | Anything may happen; reading uninitialized memory is UB |
| `sizeof` | Operator: bytes a type occupies (platform-dependent, `char` is always 1) |

## Syntax and C++ examples

```cpp
int score{95};                  // whole number, initialized
double average{91.5};           // decimal number
char grade{'A'};                // ONE character, single quotes
bool enrolled{true};            // logical: true/false
const double Pi{3.14159};       // named constant

int total{};                    // zero-initialized ("empty braces")
score = 100;                    // assignment: value REPLACED
total = score + 10;             // right side computed first: 110
```

| Piece | Meaning |
|---|---|
| `int count{42};` | Declare `count` as int, initialize to 42 |
| `{}` vs `=` | Braces refuse narrowing; `=` silently truncates |
| `char c{'A'};` | Single quotes for one character (double quotes = string) |
| `const double r{0.15};` | Named constant replaces the magic number `0.15` |
| `int x{};` | Empty braces = zero — never read uninitialized |

## Line-by-line code explanation

`examples/types_and_sizes.cpp`:

1. `int count{42};` — reserve an int-sized box, name it `count`, store 42.
2. `bool enrolled{true};` — a bool prints as `1`/`0` (its integer values);
   the *words* true/false are for writing, not for printing.
3. `const double Pi{3.14159};` — a box that can never be reassigned; the
   compiler enforces the promise.
4. `std::cout << sizeof(int) ...` — `sizeof` answers in bytes: typically
   int 4, double 8, char 1, bool 1 — but the standard guarantees only
   *relative* sizes (`char` = 1, others at least that). Portability note:
   exact int size is platform-defined; 4 bytes is what most teaching
   machines use.
5. `// int bad{3.7};` — commented out *deliberately*: uncommenting produces
   `error: narrowing conversion of '3.7' from 'double' to 'int'` — the brace
   form refusing to lose data silently.
6. `int sloppy = 3.7;` — the `=` form compiles and truncates to 3 — the
   bug the brace form prevents.

## Output prediction questions (with answers)

1. `int x{7}; x = x + 3; std::cout << x;` — ? — `10` (right side first:
   7+3, then store).
2. `int a[partial]...` → simpler: `int b[3] = {10};` is Module 9; here:
   `double d{5}; std::cout << d;` — ? — `5` (int widened to double 5.0,
   printed as `5`).
3. `char c{'A'}; std::cout << c;` vs `std::cout << 'A';` — ? — both `A`.
4. `bool flag = 3.9; std::cout << flag;` — ? — `1` (nonzero converts to
   true; the fractional part does not survive).
5. *Why does `int x{3.7};` fail but `int x = 3.7;` compile?* — Braces refuse
   narrowing; `=` truncates silently (to 3).

## Common errors and debugging examples

| Error | Diagnostic / symptom | Fix |
|---|---|---|
| Uninitialized read | Garbage value, no diagnostic | Initialize with `{}` always |
| `int x{3.7};` | `error: narrowing conversion ...` | If truncation is intended, write `static_cast<int>(3.7)` |
| `'A'` vs `"A"` | `'A'` is char; `"A"` is a string of two chars (A + hidden end) | Single quotes for single characters |
| Assignment in a condition (`if (x = 5)`) | Compiles; always true | `==` for comparison; `-Wall` warns |
| Magic numbers (`if (s > 90)`) | Code works, meaning unclear | Named constants: `kGradeA` |
| Reassigning a `const` | `error: assignment of read-only variable` | If it must change, it must not be `const` |

## Classroom demonstrations

1. **Box-and-value, live:** draw the box for `int score{95};`; erase and
   rewrite for the assignment `score = 100;` — the *box* persists, the
   *value* is replaced.
2. **The brace shield:** compile `int x{3.7};` (error), then `int x = 3.7;`
   (silent truncation) — one design decision shown preventing a real bug.
3. **Magic-number refactor:** a 6-line program with `0.15` scattered
   thrice; change the rate once with a named constant vs three times
   without.
4. **`sizeof` tour:** run `types_and_sizes.cpp`; note that these sizes are
   typical-but-not-guaranteed (standard guarantees relative sizes only).

## Common student misconceptions

- "`int` can hold 3.5 if I only print the whole part." (Type fixes the
  *storage*, not the display.)
- "`double` is 'more accurate' than `int`." (Different *domain*; doubles have
  their own surprises — 0.1 + 0.2 ≠ 0.3, revisited in M3.)
- "`char` holds 'ABC'." (One character only; strings come in Module 11.)
- "Assignment means equality." (`x = x + 1;` is compute-then-store.)

## Guided student activities
**Type-choosing workshop (20 min):** 10 real-world quantities (age, temperature,
grade letter, is-enrolled, population, price, phone number, number of legs,
GPA, house number). Pairs choose a type each and defend one that is *wrong*
per typical intuition (phone number, house number → string/`int` identity vs
quantity discussion).

## Practice problems
- Box-and-value diagrams for 6 declaration/assignment sequences.
- Predict output: 5 programs reassigning `int`/`double`/`bool` (including
  `bool b = 42;`).
- Fix 4 programs that use magic numbers or uninitialized variables.
- (🟡 stretch) Explain why `char letter{65};` prints `A` with
  `(char)` casting — foreshadow Module 11.

## Summary

A variable is a labeled box with a type; the type fixes size, allowed
values, and operations. Initialize with `{}` braces, name things for
what they hold, prefer `const` for values that never change, and never
read a box before you put something in it. Next (L04): getting real
values in and out of programs — console I/O and formatted output.

## Exit ticket / formative assessment

1. Choose a type: *number of stars in a galaxy*; *a single reply y/n*;
   *average of 3 exam scores*. Justify in ≤ 1 clause each.
2. Why does `int x{3.7};` fail to compile, and why is that good?
3. Write one statement declaring a `const` named constant for π.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (anatomy quiz) + why variables | 10 |
| Box-and-value model + types with `sizeof` demo | 35 |
| Break | 10 |
| Declaration/init/assignment; `const`; uninitialized trap | 35 |
| Type-choosing workshop | 20 |
| Exit ticket + L04 preview | 10 |
