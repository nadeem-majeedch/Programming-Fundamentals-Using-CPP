# L17 · 1-D Arrays: Declaration, Indexing, Bounds, and the Array–Memory Model

**Module 9 — One-Dimensional Arrays · Week 9 · Lecture 17 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-9.1, PF-9.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Declare, initialize, and index 1-D arrays of any built-in type, and
   explain their contiguous memory layout with a box-address diagram
   (PF-9.1).
2. Predict the (dangerous) behavior of out-of-bounds indexing and
   off-by-one loops, and apply the course discipline
   (`const int N{...}; arr[N]`, valid indices `0..N-1`) (PF-9.2).
3. Choose between full initialization, partial initialization, and
   size-from-initializer forms, stating the consequences of each (PF-9.1).

## Prerequisites

M5 (loops — arrays are processed with them); L03 (types, `const`);
Module 6 (trace discipline for array algorithms).

## Concept sequence

1. The limitation motivating arrays: 30 scores = 30 variables?
2. Declaration + memory diagram (contiguous boxes with addresses)
3. Indexing: zero-based, `arr[i]` as a *variable you can read and write*
4. Initialization forms and their exact semantics
5. Traversal idioms with `for`; `const int N` size discipline
6. Out-of-bounds: why C++ doesn't check, and what discipline replaces it

## Teaching topics (detailed)

- **Memory model:** `int scores[5];` → 5 adjacent 4-byte boxes, address of
  first + index × size — the diagram reused for pointer arithmetic (M13);
  array name as address-of-first-element (mentioned here, formalized L26).
- **Zero-based indexing:** valid indices `0..N-1`; the fence-post argument;
  `arr[N]` is one past the end — legal-looking, undefined behavior.
- **Initialization forms:** `int a[3] = {10, 20, 30};` · `int b[3] = {10};`
  (rest zero!) · `int c[] = {1, 2, 3};` (size 3) · `int d[3]{};` all zero —
  semantics contrasted in one demo program.
- **Course discipline:** size as `const int N{5};`, loops
  `for (int i{0}; i < N; ++i)`; why `sizeof(a)/sizeof(a[0])` is *shown once,
  then replaced by the N-discipline* (works only in the declaring scope —
  decay surprise foreshadowed).
- **OOB reality check:** demo reading `arr[5]` — compiles, prints garbage or
  crashes *unreliably*; C++ trusts you; the checker is discipline + tests
  (M6 evidence format).

## C++ examples required

| File | Role |
|---|---|
| `array_basics.cpp` ✅ | all four init forms printed; traversal idioms; commented OOB demonstration |
| (live) `array_memory.cpp` | prints element addresses to *show* contiguity (4-byte steps) |

## Conceptual explanation (beginner-first)

So far, "text" was a `std::string` — a comfortable object that grows,
knows its length, and handles memory for us. But underneath, C++ (like
C) stores text the old way: as an **array of `char` ending with the
null character `'\0'`**. You will meet this style in textbooks, legacy
code, and APIs — so you must be able to read it. The rules: the
terminator occupies one slot, string literals like `"hi"` already carry
it (so they need two chars of room plus the terminator), and a `char`
array that fills completely has **no terminator** — printing it runs
off the end into whatever bytes sit next door.

This lecture is deliberately hands-off-`std::string`: we write the
loops ourselves, because the loops *are* the lesson. Walking a C-string
until `s[i] != '\0'` is the same scan pattern as searching an array —
with a terminator standing in for the size parameter. The terminator is
the string's own "size parameter," stored in the data itself.

## Terminology and definitions

| Term | Definition |
|---|---|
| C-string | A `char` array whose last character is `'\0'` |
| Null terminator | `'\0'` — the byte marking the end |
| String literal | `"text"` — has `strlen(text) + 1` bytes; already terminated |
| Buffer | A fixed-size `char` array a string is read into |
| Buffer overflow | Writing past the buffer's end — the classic security bug |
| `std::size_t` | The unsigned type of sizes and indices |
| `<cctype>` functions | `isalpha`, `isdigit`, `toupper`, `isspace` — per-character tests and maps |
| Per-character loop | The standard scan: `for (std::size_t i{0}; s[i] != '\0'; ++i)` |

## Syntax and C++ examples

```cpp
char word[]{"hi"};            // size 3: 'h', 'i', '\0' — literal adds it
char buf[8]{};                // all zeros: an empty C-string from the start

std::cin >> buf;              // reads ONE word into the buffer

// the canonical C-string walk — no size needed, terminator says stop
for (std::size_t i{0}; word[i] != '\0'; ++i)
    std::cout << word[i] << ' ';          // h i

// count digits using <cctype>
int digits{0};
for (std::size_t i{0}; buf[i] != '\0'; ++i)
    if (std::isdigit(static_cast<unsigned char>(buf[i])))
        ++digits;

// std::string still exists — .size() and [] are our friends
std::string s{"A1b2"};
for (char ch : s)             // range-for: no indices at all
    if (std::isdigit(static_cast<unsigned char>(ch))) ++digits;
```

- "Arrays start at 1." (Zero-based; fence-post error follows.)
- "`arr[5]` on a 5-element array is an error the compiler catches." (It
  isn't — undefined behavior, no diagnostic.)
- "The array knows its own size." (It doesn't; the *programmer's* discipline
  carries it — `std::vector` in L27 fixes this properly.)
## Line-by-line code explanation

The C-string mechanics program (per `examples/array_basics.cpp`'s char
section):

1. `char word[]{"hi"};` — the compiler counts: 'h', 'i', and the
   terminator the literal supplies → size 3. Writing `char word[2]`
   would *drop the terminator* — the bug demo below.
2. `char buf[8]{};` — brace-init zeroes all 8 bytes, so buf is an empty
   C-string before any input (a terminated empty string, never garbage).
3. `for (std::size_t i{0}; word[i] != '\0'; ++i)` — the walk: no size
   variable, the terminator is the stop sign. Compare with the array
   loop `i < n` from the previous lecture: same scan pattern, sentinel
   instead of bound.
4. `std::isdigit(static_cast<unsigned char>(buf[i]))` — the `<cctype>`
   functions are defined for the unsigned char range; the cast is the
   documented, portable way to pass a plain char safely. (Standard C++
   everywhere; no compiler-specific behavior.)
5. The `std::string` version with range-for is shown as the contrast:
   same logic, no terminator management — why we default to
   `std::string`.

## Output prediction questions (with answers)

1. `char w[]{"cat"}; std::cout << sizeof(w);` — ? — **3** bytes: 'c',
   'a', 't', `'\0'` (sizeof counts the terminator; `strlen` would say
   2).
2. `char b[4]{}; std::cin >> b;` with input `hello` — ? — undefined
   behavior: 5 chars + terminator exceed 4 — the overflow demo.
3. `char t[3]{"abc"};` — ? — compile error (needs 4 including
   `'\0'`); with `char t[3] = "abc";` (no braces) it is also rejected —
   the language protects literal-to-array sizing.
4. Walk output for `word = "A1"` in the digit-count loop — ? — prints
   `A 1 `, digits == 1.
5. `char e[4]{};` before any input, printed — ? — nothing: element 0 is
   `'\0'`, so the string is empty, not garbage.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Buffer exactly fits the text | No room for `'\0'` → runs past the end when printed | Size = longest text + 1 |
| Copying arrays with `=` | Arrays don't assign element-wise | Copy in a loop (or `std::strcpy` with care) |
| Comparing C-strings with `==` | Compares addresses, always false-ish | `std::strcmp == 0` (shown, flagged as legacy) |
| Reading with `cin >> buf` into a small buffer | Overflow on long input | Prefer `std::string` + `getline` |
| Forgetting the terminator when building by hand | Print runs into garbage bytes | Terminate manually: `s[n] = '\0';` |
| `char` vs `int` in `<cctype>` calls | Works usually, UB on negative chars | Cast to `unsigned char` first |

## Common student misconceptions

- **"Array bounds are checked at runtime."** C++ performs no bounds
  checking on `a[i]` — out-of-range access is undefined behavior, not a
  catchable exception; discipline (size constants, loop bounds) is the
  safety net.
- **"`int a[10]` contains ten useful values right away."** The ten ints
  are *uninitialized*; using them before assigning is undefined — show
  `int a[10]{};` as the zero-initialized habit.
- **"`a[10]` is the last element."** For size 10, valid indexes are
  `0..9`; `a[10]` is one past the last — the off-by-one that follows
  students for weeks.
- **"The array knows its own length."** `sizeof a / sizeof a[0]`
  works only where the *array type* is visible; once passed to a
  function the array decays and the size must travel separately.
- **"Assigning arrays copies them (`b = a;`)."** Arrays are not
  assignable; element-wise copying needs a loop (or `std::copy` later).

## Classroom demonstrations

1. **The overflow that "works":** print an unterminated buffer —
   garbage-or-nothing output differs between runs/machines: undefined
   behavior made visceral.
2. **Terminator surgery:** set `word[1] = '\0'` on `"hi"` → prints `h`
   only: the terminator *is* the string's end, data after it is ignored.
3. **sizeof vs strlen:** same array, two answers (3 vs 2) — memory size
   vs text length, permanently distinguished.

## Guided student activities

**Human array (15 min):** 8 students become elements (holding numbered
cards); commands like `a[3] = 99`, `for i in 0..7: a[i] *= 2` executed
physically; the student asked for `a[8]` dramatizes the OOB read.

## Practice problems

- Draw box-address diagrams for 3 array declarations (with addresses).
- Predict output of 5 traversal/initialization programs (incl. partial-init
  trick).
- Fix 3 programs with off-by-one and OOB bugs (trace-table first).
- (🟡 stretch) Show `sizeof(a)/sizeof(a[0])` succeeding in the declaring
  function and failing (decayed) in a function receiving the array.

## Practice problems
- Convert the three prediction programs above into runnable files under
  `exercises/in_class/` at authoring time; the stretch item becomes the
  lab extension.

## Summary

C-strings are `char` arrays with a `'\0'` terminator standing in for a
size; the walk-until-terminator loop is the scan pattern with the
terminator as its own sentinel. `std::string` remains the default tool
— but reading C-string style code is a required literacy, and buffer
sizes are the origin of the overflow bugs we will keep naming.
Next (L18): the array-algorithm workshop — fill, print, sum, min/max,
count, and linear search written as proper functions.

## Exit ticket / formative assessment

1. How many bytes does `char w[]{"cat"}` occupy, and what is in the
   last one?
2. Write the `for` header that walks a C-string `s` without a size
   variable.
3. Why is `char tiny[3]{"abc"}` a bug, and what symptom would you
   expect when printing `tiny`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (midterm debrief) + motivation | 10 |
| Memory model + indexing + init forms | 40 |
| Break | 10 |
| Traversal discipline + OOB reality | 30 |
| Human-array activity | 15 |
| Exit ticket + L18 preview | 15 |
