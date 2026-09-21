# L25 · Pointers: Addresses, `&`, `*`, `nullptr`, and Pointer Arithmetic

**Module 13 — Pointers and References · Week 13 · Lecture 25 of 32 · 120 minutes**
**Outcomes:** CLO-7 · PF-13.1, PF-13.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Explain the address-of/dereference pair — `&x` yields the address, `*p`
   accesses the pointed-to object — and draw state diagrams (box-and-arrow)
   for pointer declarations, assignments, and updates (PF-13.1).
2. Declare pointers, assign addresses, dereference for read/write, use
   `nullptr`, and distinguish the pointer variable from the pointed-to value
   in code and diagrams (PF-13.1).
3. Trace pointer arithmetic on arrays (`*(a + i)` ≡ `a[i]`), including the
   step-size-by-type rule (PF-13.2).

## Prerequisites

L17 (array memory model — the box-address diagram pays off now); L15
(references as aliases — the contrast is pedagogically load-bearing); L06
(casts, type discipline).

## Concept sequence

1. Motivation: functions couldn't modify caller variables — what *really*
   happens inside memory
2. Every variable has an address; `&` reveals it
3. Pointer declaration/assignment; dereference `*` for read and write
4. `nullptr` — the pointer that points nowhere (on purpose)
5. State diagrams: the course notation for all pointer reasoning
6. Pointers and arrays: decay + `*(a + i)` ≡ `a[i]` arithmetic

## Teaching topics (detailed)

- **Addresses:** `&x` printed with `%p`-style via `static_cast<const void*>`
  (mention only); the *variable vs value vs address* triple; box-and-arrow
  notation established as the exclusive diagram language (M14, M16 reuse it).
- **Pointer basics:** `int* p{&x};` — read as "p is a pointer to int";
  `*p` as lvalue (write) and rvalue (read); `p` vs `*p` vs `&x` spoken
  aloud until fluent; uninitialized pointers vs `nullptr` (initialize to
  `nullptr` always); dereferencing `nullptr` = crash demo (safe, deterministic).
- **Write-through:** `*p = 99;` changes `x` — the mechanism *under* L15's
  references; `sizeof(p) == 8` regardless of pointee type (address size),
  vs pointee size.
- **Decay & arithmetic:** array name decays to `&a[0]` in expressions;
  `*(a + i)` ≡ `a[i]` ≡ `p[i]` with `int* p{a};`; arithmetic scales by
  `sizeof(element)` — printed address walk over an int array (4-byte steps)
  vs double array (8-byte steps); one-past-the-end pointer legality note.
- **Style/limits ([docs/CPP_STANDARD.md](../../docs/CPP_STANDARD.md) § 4):**
  no pointer arithmetic beyond array walks; `const int* p` (pointer-to-const)
  vs `int* const p` (const pointer) — named, one slide, not drilled.

## C++ examples required

| File | Role |
|---|---|
| `pointer_basics.cpp` ✅ | addresses printed; read/write through `p`; `nullptr` guard; decay + arithmetic walk with printed addresses |
| (live) `pointer_swap.cpp` | swap via pointer parameters (contrast with L15 reference swap — same result, different syntax) |

## Common student misconceptions

- "`&x` is the reference operator from L15." (Same symbol, different context:
  in a *declaration* it's a reference type; in an *expression* it's
  address-of — the table that resolves every confusion.)
- "`*p` declares a dereference at declaration." (`int* p, q;` — only `p` is
  a pointer; course style: one declarator per line.)
- "Pointers store values." (They store *addresses*; the value lives at the
  address.)
- "Pointer arithmetic adds bytes." (It adds *elements*; type scales the
  step.)

## Conceptual explanation (beginner-first)

Every variable lives somewhere: `int x{42}` occupies a real box in
memory, and that box has an **address** — a number, usually written in
hexadecimal, that names the box's location. A **pointer** is simply a
variable whose value is such an address. If `x` is a house, `p` is a
sticky note with the house's street address written on it.

Two operators run the whole lecture. **Address-of** (`&x`) reads the
address out of a variable: "where does x live?" **Dereference**
(`*p`) travels to the address a pointer holds: "go to the address
written on p, and use what's there." Through `*p` you can read the
distant box — `cout << *p` — or *write* it — `*p = 99` changes `x`.
This is the mechanism that made pass-by-reference work in Module 8
(`int& r` is a safe, automatic cousin) and that makes arrays and
strings possible (an array name *is* an address in most contexts).

With that power comes the rule that governs the module: **a pointer
must point at something before it is dereferenced**. A pointer with no
target gets the dedicated value `nullptr`, and every dereference in
course code is guarded by `if (p != nullptr)` first. Dereferencing
nullptr (or garbage) is undefined behavior — the crash-generating,
silently-corrupting territory this lecture teaches you to never enter.

## Terminology and definitions

| Term | Definition |
|---|---|
| Address | The memory location of a variable (printed in hex) |
| Pointer | A variable that stores an address; type: `int*`, `double*`, `char*` |
| Address-of operator | `&x` — yields the address of `x` |
| Dereference operator | `*p` — accesses the object at the address `p` holds |
| `nullptr` | The pointer value meaning "points at nothing" |
| Dangling pointer | A pointer to memory no longer owned (use-after-scope) |
| Pointer arithmetic | `p + 1` moves one *element* (not byte) — type-scaled |
| Array–pointer decay | An array expression converts to a pointer to element 0 |
| Memory safety | The discipline: initialize, guard, never outlive |
| State diagram | Box-and-arrow picture of pointers and their targets |

## Syntax and C++ examples

```cpp
int x{42};
int* p{nullptr};                 // every pointer starts as nullptr

p = &x;                          // p now holds x's address

std::cout << x << '\n';          // 42
std::cout << &x << '\n';         // e.g. 0x7ffd... (machine-specific!)
std::cout << p << '\n';          // same address
std::cout << *p << '\n';         // 42 — dereference: the thing pointed at

*p = 99;                         // write through the pointer
std::cout << x << '\n';          // 99 — x changed

// guard before dereferencing
if (p != nullptr)
    std::cout << *p << '\n';
p = nullptr;                     // now it points at nothing again

// pointer arithmetic walks ELEMENTS
int a[5]{10, 20, 30, 40, 50};
int* q{a};                       // decay: points at a[0]
for (int i{0}; i < 5; ++i)
    std::cout << *(q + i) << ' ';            // 10 20 30 40 50 — *(q+i) == a[i]
```

## Line-by-line code explanation

`examples/pointer_basics.cpp`:

1. Every declaration initializes: `int* p{nullptr};` — the uninitialized-
   pointer bug never gets a foothold in course code.
2. The address block prints `&x` and `p`: same value. The instructor
   note printed by the program says it too: **exact addresses are
   machine- and run-specific** (standard C++ doesn't fix them) — only
   the *relationships* are meaningful.
3. `*p = 99;` — the write-through: `x` reads 99 afterwards. The program
   prints both names for the same box: "x is 99; *p is 99."
4. The `nullptr` guard demonstrates the pattern around every
   dereference; then `p = nullptr;` shows the repointable nature — the
   pointer is the sticky note; you can rewrite the address on it.
5. The array walk prints `q + i` (addresses stepping 4 bytes on this
   build) and `*(q + i)` (values) — decay and element-scaled
   arithmetic made visible; `*(q+i)` and `a[i]` are the same thing.

## Output prediction questions (with answers)

1. `int y{7}; int* q{&y}; *q = *q + 1;` — value of `y`? — **8** (the
   addition went through the pointer).
2. `q = nullptr; cout << *q;` — ? — undefined behavior: crash or worse;
   the guarded version prints nothing and continues.
3. `int a[3]{1,2,3}; cout << *(a + 2);` — ? — **3**; equivalent to
   `a[2]`.
4. `int* p{nullptr}; if (p) cout << "yes"; else cout << "no";` — ? —
   `no` — a pointer converts to bool: non-null is true.
5. Two runs of the program print different addresses for `&x` — a
   bug? — no: addresses are machine/run-specific; relationships
   (p == &x) are the invariant.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Dereferencing uninitialized pointer | Crash or random corruption | Initialize to `nullptr` (or a target) at declaration |
| Dereferencing `nullptr` | Crash on access | Guard: `if (p != nullptr)` |
| Dangling pointer (target went out of scope) | Use-after-scope UB | Never return/keep addresses of locals |
| `int* p, q;` | `q` is a plain int — the declaration trap | One pointer per line |
| Confusing `&` in declaration vs expression | Type errors, wrong mental model | Declaration = reference type; expression = address-of |
| Byte-vs-element arithmetic | Off-target reads | `p + 1` moves one element; the step is `sizeof(type)` |

## Classroom demonstrations

1. **The sticky note:** a named box (label `x`, value 42) and a second
   box holding "→ x's address"; every operator is a physical action on
   the two boxes.
2. **Address printing:** run the example twice — different addresses,
   same relationships; the standard-vs-implementation distinction is
   made explicit (standard C++ doesn't pin addresses; *any* conforming
   compiler may differ).
3. **The guarded crash:** dereference nullptr with and without the
   guard; the class sees UB's arbitrariness (one build crashes, another
   prints garbage).

## Guided student activities
**Box-and-arrow speed rounds (20 min):** 8 code snippets projected; teams
race to draw the state diagram (boxes, arrows, labels) then predict output;
round 8 deliberately reassigns `p` mid-program (repointing, not overwriting)
— the most-missed distinction.

## Practice problems
- Draw state diagrams for 6 pointer sequences (incl. repointing, write-
  through, nullptr).
- Predict printed output of 5 address/arithmetic programs.
- Implement `array_sum(const int* a, int n)` using only `*(a + i)`.
- (🟡 stretch) Explain what `p++` moves past on an int array vs a double
  array, with printed addresses as evidence.

## Summary

A pointer stores an address; `&` takes an address, `*` follows one,
and the box-and-arrow diagram is the ground truth for every question.
`nullptr` is the pointed-at-nothing state — check before following.
Arrays and pointers share arithmetic (`*(a+i)` is `a[i]`), which is
both the origin of array/pointer interchangeability and the source of
module 13's discipline. Next (L26): the honest, deeper story of what
arrays pass to functions and how references differ.

## Exit ticket / formative assessment

1. `int x{5}; int* p{&x}; *p = 12;` — value of `x`? of `p`?
2. In `int* p{nullptr};` what does dereferencing do — and when is
   `nullptr` useful?
3. `double d[4]; double* q{d};` — address step from `q` to `q + 1`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (sorting quiz) + the caller-modification problem | 10 |
| Addresses, `&`, `*`, nullptr + state diagrams | 40 |
| Break | 10 |
| Decay + pointer arithmetic + address walk | 30 |
| Speed-round activity | 20 |
| Exit ticket + L26 preview | 10 |
