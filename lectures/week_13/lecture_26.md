# L26 · References, Pass-by-Value vs Pass-by-Reference, and Arrays as Pointers

**Module 13 — Pointers and References · Week 13 · Lecture 26 of 32 · 120 minutes**
**Outcomes:** CLO-7 · PF-13.3, PF-13.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Assignment 4 due**

## Learning objectives

1. Distinguish reference semantics (bind once, no null, no arithmetic, no
   re-seating) from pointer semantics (re-seatable, nullable, arithmetic),
   and implement `swap`-class functions through both (PF-13.3).
2. Choose correct parameter passing — value, reference `T&`,
   const-reference `const T&`, array (`int a[]` ≡ `int* a`) — for each
   parameter of a designed function set, with one-line justifications
   (PF-13.3, PF-13.4).
3. Explain why a called function can modify an *array* argument but not a
   *scalar* argument passed by value (decay + copy semantics), and predict
   the resulting behavior in both directions (PF-13.4).

## Prerequisites

L25 (addresses, dereference, decay); L13 (copy semantics — the failed swap
comes home); L15 (`T&`/`const T&` patterns).

## Concept sequence

1. The three passing modes on one table (copy / alias / address)
2. References vs pointers: the full contrast table
3. Why arrays "pass by reference" without syntax: decay in parameters
4. `const` correctness across modes (protecting caller data)
5. The parameter-choice checklist (course standard)
6. A designed function set applying the checklist

## Teaching topics (detailed)

- **Contrast table:** re-bindable? null possible? arithmetic? must-
  initialize? syntax at use? — references (no/no/no/yes/transparent) vs
  pointers (yes/yes/yes/no/`*`-ful); when the course uses each: references
  by default (M8 rule), pointers where the *textbook model* of memory is
  the point (arrays, M14 dynamic memory).
- **Arrays in parameters:** `void fill(int a[], int n)` ≡
  `void fill(int* a, int n)` — the parameter *decays*; no copy is made;
  callee writes reach the caller's array (demonstrated: fill in callee,
  print in caller); size always travels separately (the L17 discipline
  formalized); `const int a[]` for read-only traversals (L18–L24 signatures
  retroactively explained).
- **Scalar vs array asymmetry:** `void bump(int x)` never reaches the
  caller's int; `void bump(int a[])` modifies the caller's array — same
  call syntax, opposite effect; the mechanism (copy vs decay) explained
  with both diagrams side by side.
- **`const` discipline:** `const T&` for large read-only inputs (strings,
  future structs), `const int a[]` for read-only arrays, `T&` only for
  write-back outputs — the full decision checklist students apply in the
  capstone (Module 14–16).
- **Designed function set (worked):** string statistics bundle —
  `int count_vowels(const std::string&)`, `void min_max(const int a[], int
  n, int& mn, int& mx)`, `void normalize(double a[], int n)` — each
  parameter's mode justified aloud.

## C++ examples required

| File | Role |
|---|---|
| `passing_modes.cpp` ✅ | scalar bump (fails), array bump (works), reference vs pointer swap, `const` variants — labeled sections with printed evidence |
| (live) `param_checklist_demo.cpp` | the string-statistics function set written signatures-first |

## Common student misconceptions

- "References are syntactic sugar for pointers, so they're the same thing."
  (Same *mechanism* at the machine level, different *rules*; the table's
  rows differ.)
- "Arrays are copied into functions like ints." (They decay; no copy — this
  is why OOB writes inside callees damage caller data.)
- "`int a[]` parameters know their length." (They don't; `n` travels
  separately — always.)
- "`const int a[]` prevents all modification." (It prevents writes *through
  that parameter*; const-correctness is per-access-path — honest scope
  note.)

## Conceptual explanation (beginner-first)

Every function parameter arrives by one of three modes, and picking
the right one is a design skill. **By value** (the default): the
argument is *copied* — safe for the caller, but expensive for big data
and useless for sending results back. **By pointer**: you pass an
*address* — the function can follow it and touch the original; the
possible `nullptr` makes every use a guard-rail exercise. **By
reference**: an alias — the function's name *is* the caller's variable;
no copy, no `nullptr`, no `*` punctuation. `swap(int& a, int& b)` is
the fix for L13's broken by-value swap.

Last module's honest secret is settled here: when an array is passed,
what travels is the **address of element 0** ("decay"). No copy is
made — which is why `const int a[]` matters so much: the callee writes
*through* to the caller's data unless you promise otherwise. And
because an array parameter forgets its length, the size always travels
as a second parameter.

The design habit is **const-correctness**: every parameter is either
`const` (I promise to read only) or deliberately mutable (I'm an
output). Reading that decision off a function's signature — inputs
first and `const`, outputs last — is how professionals read code.

## Terminology and definitions

| Term | Definition |
|---|---|
| Pass by value | A copy arrives; the caller's original is untouchable |
| Pass by pointer | The address arrives; callee dereferences; `nullptr` possible |
| Pass by reference | An alias arrives; the callee's name *is* the caller's variable |
| Out parameter | A reference/pointer parameter used to deliver results back |
| Array decay | An array argument converts to a pointer to element 0 |
| `const` correctness | Every access path marked read-only unless deliberately writable |
| Read-only parameter | `const T&` or `const T[]` — the input promise |
| Signature-first design | Write all prototypes before any body — the L26 workflow |
| Overloading | Same name, different parameter lists (Module 8) — mode changes can overload |
| Rule of three modes | Value for small inputs; `const&` for big inputs; `&`/`*` for outputs |

## Syntax and C++ examples

```cpp
// VALUE: copy arrives; caller's x is safe (and unchanged)
void bump(int x) { x = x + 1; }                  // useless for output!

// POINTER: address arrives; guard then dereference
void bumpByPtr(int* p)
{
    if (p != nullptr)
        *p = *p + 1;
}

// REFERENCE: alias arrives; no copy, no nullptr, no *
void swap(int& a, int& b)
{
    int tmp{a};  a = b;  b = tmp;                // the real swap, at last
}

// ARRAYS decay: these two headers are IDENTICAL to the compiler
void sumAll(const int a[], int n);               // course style
void sumAll(const int* a, int n);                // same function, spelled differently

// BIG OBJECTS: string/vector by const reference — no copy, no mutation
int countUpper(const std::string& s);

// OUT PARAMETERS: references deliver multiple results
void minMax(const int a[], int n, int& minOut, int& maxOut);
```

## Line-by-line code explanation

`examples/passing_modes.cpp` (labeled sections, printed evidence):

1. **Scalar bump:** `bump(x)` runs; the printout proves `x` unchanged —
   the copy semantics made visible. Then `bumpByPtr(&x)` — now the
   caller sees the change (address followed) — and `bumpRef(x)` —
   identical effect, cleaner syntax.
2. **Array bump:** a function writes `a[0] = 99;` — the caller's array
   *did* change: arrays decay, no copy, `const` is the only shield.
3. **Reference vs pointer swap:** both `swap(int&, int&)` and
   `pswap(int*, int*)` swap correctly; the call sites (`swap(a, b)` vs
   `pswap(&a, &b)`) show the ergonomic difference; the guard in the
   pointer version shows the nullability cost.
4. **`const` variants:** calling a `const`-parameter function with a
   normal array compiles; trying to pass a `const` array to a
   non-const-parameter function does not — the promise flows one way.

## Output prediction questions (with answers)

1. `void f(int x)` called as `f(a[3])` — can it modify `a[3]`? — No:
   the element was *copied*.
2. `bump(x)` then `bumpByPtr(&x)` starting from 5 — final `x`? — 5
   then 6: mode decides fate.
3. `swap(a, b)` with a=1, b=2 — ? — a=2, b=1: references reach the
   originals.
4. `sumAll(data, 4)` where data has 6 elements — ? — compiles; sums
   only the first 4: the size parameter is the truth, not the array.
5. `countUpper(name)` vs `countUpper(std::string copy = name)` — which
   copies? — only the by-value version; `const&` borrows.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| By-value "output" parameter | Function "works" but caller sees nothing | Reference/pointer for outputs |
| Missing `&` on big-object parameter | Slow copies (silent perf bug) | `const std::string&` / `const std::vector<T>&` |
| Missing `const` on array parameter | Accidental writes to caller data | `const int a[]` for every read-only array |
| Size parameter forgotten | Function reads garbage beyond the data | `int n` always travels with `a[]` |
| Unchecked pointer dereference | Crash on `nullptr` | Guard or take a reference instead |
| Returning a reference to a local | Dangling alias — UB | Return by value (copy-out is safe) |

## Classroom demonstrations

1. **The three bump calls:** same variable, three modes, three
   printouts — the mode table built from evidence, not slides.
2. **Decay address probe:** print `a` and `&a[0]` inside the callee and
   the caller — identical addresses: nothing was copied.
3. **Tribunal preview:** project one buggy signature; the class picks
   the mode fix in 30 seconds — the skill is signature-reading.

## Guided student activities
**Passing-modes tribunal (20 min):** six buggy functions presented as
"defendants" (scalar update that doesn't, array read missing `const`,
string passed by value, array size omitted, swap via wrong mode, pointer
not checked for nullptr); student prosecutors argue the defect, defense
proposes the minimal signature fix; class verdicts.

## Practice problems
- Complete the passing-mode choice table for 10 function designs (justify
  each cell).
- Fix six tribunal-style signatures + bodies.
- Write `reverse(int a[], int n)` (in place) and `reversed(const int a[],
  int n, int out[])` — contrast the two contracts.
- (🟡 stretch) Explain, with one diagram each, why `swap(int& , int&)` and
  `pswap(int*, int*)` produce identical memory effects.

## Summary

Three modes, three jobs: value for small inputs, `const`-marked for
read-only access (mandatory for arrays and big objects, which decay
and borrow), references/pointers for outputs. Signature-first design
plus const-correctness makes every function's contract readable from
its header. Next (L27): dynamic memory — where pointers earn their
keep and their dangers.

## Exit ticket / formative assessment

1. `void f(int x)` called with an array element `f(a[3])` — can it modify
   `a[3]`?
2. Two reference properties that pointers lack.
3. Choose modes: (a) 5000-element vector, read-only; (b) min/max outputs;
   (c) single `char`.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (pointer quiz) + the three modes | 10 |
| References vs pointers + decay in parameters | 40 |
| Break | 10 |
| `const` discipline + designed function set | 30 |
| Tribunal activity | 20 |
| Assignment 4 hand-in + exit ticket | 10 |
