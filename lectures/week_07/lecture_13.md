# L13 · Defining and Calling Functions: Parameters, Return Values, `void`

**Module 7 — Functions Fundamentals · Week 7 · Lecture 13 of 32 · 120 minutes**
**Outcomes:** CLO-5 · PF-7.1, PF-7.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Define and call functions with typed parameters, `return` values, and
   `void` returns; trace argument→parameter data flow and the return value's
   arrival at the call site (PF-7.1).
2. Draw and update the call stack (activation records: parameters, locals,
   return address) across a 3-function call sequence (PF-7.2).
3. State and apply the course design rules: one responsibility, verb-first
   name, no `cin`/`cout` inside computational functions (PF-7.1).

## Prerequisites

M6 (decomposition boxes → now they become functions); M2–M3 (types,
expressions).

## Concept sequence

1. The reuse-and-name problem (repeated code, unnameable logic)
2. Function anatomy: return type, name, parameter list, body, return
3. Arguments vs parameters; copy semantics on call
4. `void` functions; early `return`; multiple returns
5. Call stack: activation records, LIFO unwinding
6. Design rules + the I/O boundary principle

## Teaching topics (detailed)

- **Anatomy:** `double average(double a, double b) { return (a + b) / 2.0; }`
  — declaration-before-use rule; prototypes (declaration vs definition);
  why parameters have *their own* names.
- **Copy semantics:** arguments are copied into parameters (pass-by-value by
  default); changes to parameters never reach the caller — demonstrated with
  a failed `attempted_swap` (payoff in L15/L26).
- **`void` functions:** perform actions (printing helpers); early `return`
  for guard checks; multiple `return` paths allowed but one job per function.
- **Call stack:** draw activation records for
  `main → get_scores → compute_avg → print_report`; each record holds
  params + locals; return pops the frame — the diagram students will reuse
  for recursion-free explanations on the midterm.
- **I/O boundary principle:** computational functions take parameters and
  *return* values; only `main` (or dedicated I/O functions) touch
  `cin`/`cout` — testability rule for the rest of the course.
- **Refinement payoff:** the Module 6 hierarchy chart maps 1:1 onto function
  definitions (design → code bridge).

## C++ examples required

| File | Role |
|---|---|
| `functions_refactor.cpp` ✅ | flat gradebook program (before) refactored into 4 functions (after); both versions in one file, clearly separated |
| (live) `call_stack_demo.cpp` | 3-deep call chain with printed entry/exit lines matching the board diagram |

## Common student misconceptions

- "Calling a function jumps away permanently." (Returns to exactly the point
  after the call — return address.)
- "Parameters are just global-ish variables." (Each call creates *fresh*
  copies; two callers can't interfere.)
- "`void` means the function fails to return." (It means *no value*; the
  function still returns control.)
- "Functions must return exactly one value." (One *value*, yes — multiple
  outputs need references, Module 8 — the honest bridge.)

## Conceptual explanation (beginner-first)

A function is a named, reusable box of behavior: it takes inputs
(**parameters**), does its work, and hands back one answer (the **return
value**). Everything before this course was a thousand-line `main`
waiting to happen; functions are how programs stay readable — you name
an operation once, then *call* it by name wherever needed, the way you
say "multiply" instead of re-explaining multiplication every time.

The mental model that pays for itself all semester: calling a function
is hiring a contractor. You hand over **copies** of your materials
(arguments copied into parameters). The contractor works on their own
copies; whatever they do to them, your originals are untouched. The
finished product comes back as the return value. That's why the classic
`swap(int a, int b)` fails — the contractor swaps their own copies and
tosses them out. (Module 8 hands the contractor keys to your house:
references.)

C++ compiles top-to-bottom, so the compiler must know a function's name
and signature *before* the call site — that's the prototype: a promise
the definition later keeps. And the compiler's warnings (`-Wall`) are
already policing contracts for you: forget a `return` and it tells you.

## Terminology and definitions

| Term | Definition |
|---|---|
| Function | Named block of behavior with parameters and (usually) a return value |
| Parameter | The function's local input variable, declared in the header |
| Argument | The actual value copied into the parameter at the call site |
| Return value | The single output, delivered by `return` |
| `void` | Return type meaning "no value comes back" |
| Prototype / declaration | Name + return type + parameter types, promised before use |
| Definition | The full function body that delivers the promise |
| Pass-by-value | Arguments are copied; the caller's originals are safe |
| Local variable | Born inside the function, dies at its return |
| Global variable | Declared outside all functions; visible everywhere — course policy: avoid |
| Call stack | The runtime structure remembering "where to resume" after each return |
| Activation record | One call's frame: its parameters and locals |
| Contract | Precondition + postcondition — what the function needs and delivers |

## Syntax and C++ examples

```cpp
// prototype: the promise (note the semicolon)
int max2(int a, int b);
double toCelsius(double fahrenheit);
bool isEven(int n);
void printLine(char fill, int width);   // void: behavior, no answer

int main()
{
    std::cout << max2(3, 7) << '\n';    // call: arguments copied in
    std::cout << toCelsius(98.6) << '\n';
    printLine('*', 10);
    return 0;
}

// definition: the delivery
int max2(int a, int b)
{
    if (a > b)
        return a;                        // first exit point
    return b;                            // second exit point
}

double toCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

bool isEven(int n)
{
    return n % 2 == 0;                   // the comparison IS the answer
}

void printLine(char fill, int width)
{
    for (int i{0}; i < width; ++i)
        std::cout << fill;
    std::cout << '\n';                   // no return — void
}
```

## Line-by-line code explanation

`examples/functions_refactor.cpp` — the same gradebook twice:

1. **Before (flat):** `main` reads scores, computes sum/min/max/average
   inline — 60 lines, no name says what any part does; changes touch
   everything.
2. **After (refactored):** `double average(const int a[], int n)` etc.
   — `main` reads like the problem statement; each function is testable
   alone. (Array parameters appear here early; Module 9 formalizes
   them.)
3. `max2` shows *two* return points — legal and clear for a two-path
   answer; the compiler's `-Wall` catches any path that forgets one.
4. `isEven` returns the comparison directly — `n % 2 == 0` already
   *is* a bool; writing `if (...) return true; else return false;`
   is noise (style guide point).
5. The refactored `main` demonstrates the top-down story: the function
   names *are* the Module 6 plan.

## Output prediction questions (with answers)

1. `max2(3, 7)` — ? — 7.
2. `toCelsius(212.0)` — ? — 100.0.
3. `isEven(0)` — ? — true (0 % 2 == 0).
4. After `void f(int x) { x = 99; }` and `int a{5}; f(a);` — what is
   `a`? — 5: the parameter was a copy.
5. `printLine('-', 3)` — ? — prints `---` and a newline; returns
   nothing.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Using before declaring | "'max2' undeclared" at the call site | Prototype above, or define before `main` |
| Missing return on a value path | Warning; garbage returned on that path | Every path returns; `-Wall` finds them |
| `swap(a, b)` by value | Caller's values unchanged | Copies can't: references (M08) fix it |
| Parameter/local name shadows a global | Confusing dual behavior | No globals — course policy |
| Ignoring the return value | Computed then dropped silently | Capture it or make it `void` deliberately |
| Mismatched prototype/definition types | Overload surprise or error | Types must match exactly |

## Classroom demonstrations

1. **The contractor sketch:** run the pass-by-value swap live; the
   printouts prove the originals never moved — copies, not keys.
2. **Refactor theater:** flat `main` on the left; functions born one at
   a time on the right; `main` shrinks to a readable story.
3. **Warning hunt:** delete one return path, compile with `-Wall`, read
   the warning aloud — the compiler is a contract enforcer.

## Guided student activities
**Function archaeology (20 min):** teams receive the flat version of
`functions_refactor.cpp` and the Module 6 hierarchy chart; they draw the
function boundaries on the printout (name, params, return) *before* seeing
the solution; scoring rewards matching the I/O-boundary principle.

## Practice problems
- Write 6 small functions (`max2`, `max3` via `max2`, `to_celsius`,
  `is_even`, `last_digit`, `print_line`).
- Trace a 3-function call with an activation-record diagram.
- Spot the violations: 4 functions that mix I/O with computation.
- (🟡 stretch) Why can't `get_two_values()` return two ints? Sketch what you
  *wish* the syntax were (answered in L15).

## Summary

Good functions are born from two habits: naming the operation and
letting the compiler's warnings police the contract. Parameters are the
function's inputs (and `const` is how you promise not to change them);
the return value is its output; the declaration in a prototype is the
promise, the definition is the delivery. Global variables are read as
"hidden wiring" and avoided. Next (L13): arrays — the first data
structure — where functions will process whole collections.

## Exit ticket / formative assessment

1. Write the prototype for `double average3(int a, int b, int c)` and
   one sentence stating its contract.
2. What does `-Wall` catch about `int countNegatives(int a[], int n)`
   if you forget `return count;` at the end?
3. Rewrite the buggy `swap(int a, int b)` call site so the swap actually
   works, given only pass-by-value is available this week.

1. Write a prototype for a function that converts minutes to h:mm format as
   two outputs... or explain why one value suffices.
2. What is on top of the stack when `compute_avg` runs?
3. What does the caller receive from a `void` function call?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (trace quiz) + the naming/reuse problem | 10 |
| Anatomy + copy semantics + failed swap demo | 35 |
| Break | 10 |
| `void`, call stack, I/O boundary principle | 35 |
| Function archaeology activity | 20 |
| Exit ticket + L14 preview | 10 |
