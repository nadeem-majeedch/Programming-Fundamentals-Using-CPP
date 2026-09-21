# L27 · Dynamic Memory: `new`, `delete`, Leaks, Dangling Pointers, `std::vector` as Managed Memory

**Module 14 — Dynamic Memory and Structures · Week 14 · Lecture 27 of 32 · 120 minutes**
**Outcomes:** CLO-7 · PF-14.1, PF-14.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Allocate and release heap memory with `new`/`delete` (scalar) and
   `new[]`/`delete[]` (arrays), matching forms exactly and explaining why
   mismatching forms is undefined behavior (PF-14.1).
2. Identify memory leaks, dangling pointers, and double-deletes in code,
   and repair each with the correct fix (PF-14.1).
3. Explain RAII and why `std::vector`/`std::string` are the course default,
   converting a leak-prone raw-memory program to a leak-free vector version
   (PF-14.2).

## Prerequisites

L25 (pointers, addresses, state diagrams); L17 (array memory model); L03
(lifetime — stack objects die at scope end).

## Concept sequence

1. The stack vs heap: two memory regions with different rules
2. `new`/`delete`: explicit heap lifetime
3. `new[]`/`delete[]` for dynamic arrays; runtime-sized allocation
4. The three failure modes: leak, dangling, double-delete
5. RAII: tying lifetime to scope (vector as the safe owner)
6. Conversion lab: raw → vector

## Teaching topics (detailed)

- **Stack vs heap table:** stack = automatic, scope-bound, fast, limited;
  heap = explicit, flexible lifetime, manual release; diagram of a pointer
  *on the stack* pointing to a block *on the heap*.
- **`new`/`delete`:** `int* p{new int{42}}; ... delete p; p = nullptr;`
  — allocate-construct, use, release, null-out as the four-step discipline;
  why set `p = nullptr` after delete (turns dangling into checkable).
- **`new[]`:** `int* data{new int[n]};` with runtime `n` (finally: size not
  known at compile time — the thing stack arrays cannot do);
  `delete[] data;` — bracket matching rule and the UB of mixing.
- **Failure modes (each shown in code):** *leak* — reassign `p` before
  delete: the block becomes unreachable; *dangling* — use after delete;
  *double-delete* — two `delete`s on one pointer; each labeled with the
  symptom (or silent lack thereof) and the one-line fix.
- **RAII:** the owner-object pattern — constructor acquires, destructor
  releases (mechanism named, not implemented); `std::vector<int> v(n);`
  replaces `new[]` + manual delete; "you never write delete for vector" —
  the course rule and its justification; `v.push_back` growth shown as the
  runtime-sizing win without leak risk.
- **Conversion lab (live):** the leak-prone `raw_stats.cpp` rewritten to
  `vector` in 5 edits; line-count and failure-mode count both drop.

## C++ examples required

| File | Role |
|---|---|
| `dynamic_memory_caution.cpp` ✅ | three labeled failure modes (each reproducible-safe: leak via counter, dangling via re-set check, double-delete commented) + the corrected versions |
| (live) `raw_to_vector.cpp` | side-by-side raw vs vector implementations of the same stats task |

## Common student misconceptions

- "`delete` erases the pointer." (It releases the *pointed-to* block; the
  pointer variable survives — now dangling.)
- "Leaks crash the program." (They don't — they silently consume memory;
  that's what makes them insidious.)
- "`delete p;` needs repeating per element." (One `delete`/`delete[]` per
  allocation; matching the allocation form is the rule.)
- "`new` is just C++ for `malloc`." (It constructs typed objects; the
  type-safe pairing is the point.)
- "`std::vector` uses no heap." (It *manages* heap for you — RAII; students
  should understand what's being automated.)

## Conceptual explanation (beginner-first)

Until now, every variable's size was fixed in the source code —
`int scores[30];` is 30 forever. But programs often need memory whose
size they only know *at run time* ("allocate room for n students").
The **heap** (or *free store*) is memory you request explicitly with
`new` and release explicitly with `delete` — and that pair of
responsibilities is the whole lesson: every `new` must be matched by
exactly one `delete` (or `delete[]` for arrays), and failing to do so
*leaks* memory silently.

Three failure modes dominate, and all three are *silent or delayed*:
the **leak** (allocated, never freed — the program slowly eats RAM),
the **dangling pointer** (freed, but the pointer still points there —
using it is undefined behavior), and **double delete** (freeing twice —
corrupts the allocator). The disciplines that prevent them: null-check
before use, null-out after delete, never dereference a freed pointer,
and match allocation forms exactly.

Then the professional punchline: modern C++ makes `new[]`/`delete[]`
rare. **`std::vector<int>`** (a library array that grows and manages
its own heap memory) handles allocation and release *automatically* —
when the vector goes out of scope, its memory is freed. That pattern —
resource release tied to object lifetime — is called **RAII**, and it
is why the course default is vector, with raw `new` taught so the
mechanism is understood, not feared.

## Terminology and definitions

| Term | Definition |
|---|---|
| Stack | Automatic storage: locals and parameters; freed at scope exit |
| Heap / free store | Explicit memory: requested with `new`, released with `delete` |
| `new` / `delete` | Allocate one object / release it |
| `new[]` / `delete[]` | Allocate an array / release it — forms must match |
| Memory leak | Allocated but never freed; invisible, cumulative |
| Dangling pointer | Points to freed memory; any use is undefined behavior |
| Double delete | Freeing the same block twice — allocator corruption |
| `nullptr` reset | `p = nullptr;` after delete; deleting null is a safe no-op |
| `std::vector<T>` | Library dynamic array; manages its own heap memory (RAII) |
| RAII | Resource acquisition tied to object lifetime — release happens automatically |
| Runtime sizing | `int* data = new int[n];` where n is known only at run time |

## Syntax and C++ examples

```cpp
// runtime-sized single value and array
int n{};
std::cin >> n;
int* data{new int[n]{}};          // n zeros; size fixed AT RUN TIME

for (int i{0}; i < n; ++i)
    data[i] = i * i;              // same indexing as a normal array

long long total{0};
for (int i{0}; i < n; ++i)
    total += data[i];

delete[] data;                    // match the [] form — exactly once
std::cout << total << '\n';

// single object
int* p{new int{42}};
std::cout << *p << '\n';
delete p;
p = nullptr;                      // null-out: dangling becomes testable

// the modern default: std::vector does all of this management itself
#include <vector>
std::vector<int> v(static_cast<std::size_t>(n));
for (std::size_t i{0}; i < v.size(); ++i)
    v[i] = static_cast<int>(i) * static_cast<int>(i);
// no delete — freed automatically when v leaves scope (RAII)
```

## Line-by-line code explanation

`examples/dynamic_memory_caution.cpp` (three labeled failure modes,
each followed by its corrected version):

1. **Leak mode:** a loop allocates a fresh block each iteration and
   drops the only pointer into it — the old block becomes unreachable
   but is never freed. The corrected version frees (or reuses) before
   reallocating. Teaching point: the leak is *silent*; only a memory
   monitor would see it.
2. **Dangling mode:** a pointer is deleted, then *read* — the program
   may print the old value, zeros, or crash: undefined behavior. The
   fix nulls the pointer after delete, making "is it valid?" answerable
   with `if (p != nullptr)`.
3. **Double-delete mode:** `delete p;` twice — allocator corruption
   (presented as a commented demo; running it is not safe). The safe
   idiom: null-out after delete, because `delete nullptr` is defined
   as a no-op.
4. The corrected file finishes with the same task done by
   `std::vector<int>` — same results, zero management code: the RAII
   contrast is the closer.

## Output prediction questions (with answers)

1. `new int[10]` must be freed by — ? — `delete[]` (form must match).
2. Memory usage climbs every iteration — which failure mode? — Leak;
   suspect every allocation line not paired with a delete.
3. `delete p; p = nullptr; delete p;` — ? — Safe: deleting null is a
   no-op.
4. Reading through a freed pointer — ? — Undefined behavior: possibly
   old value, possibly garbage, possibly a crash.
5. Why does the vector version have no `delete`? — RAII: the vector's
   destructor frees its heap block at scope exit.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| `delete` on `new[]` memory | UB — wrong pairing | `delete[]` matches `new[]` |
| Leak in a loop | Slow RAM growth, no crash | Free before reallocating; or vector |
| Use after delete | Random garbage / crash | Null-out after delete; check before use |
| Double delete | Allocator corruption | Delete exactly once; null-out pattern |
| Losing the pointer (overwriting it) | Orphaned block — leak | Keep the pointer until deleted |
| Raw `new[]` where a vector fits | All of the above risks | Default to `std::vector` (course rule) |

## Classroom demonstrations

1. **The leak that "works":** run the leaky loop — nothing crashes;
   show Task Manager/`top` climbing. Silence is the danger.
2. **Dangling roulette:** print through a freed pointer a few times —
   differing outputs across runs demonstrate UB honestly.
3. **RAII relief:** run the vector version of the same task — then
   delete the vector's cleanup line conceptually: there is none. That
   *is* the lesson.

## Guided student activities
**Failure-mode clinic (20 min):** six short programs on cards (one leak, one
dangling read, one double-delete, one mismatched delete form, one missing
null-out, one correct); teams diagnose severity (crash now / crash later /
silent), fix, and rank by real-world danger; debrief ranks silent leaks
highest.

## Practice problems
- Trace-and-label the three failure modes in given snippets; write the fix.
- Implement `int* make_range(int lo, int hi)` with correct `new[]` +
  documented caller responsibility; then the vector version.
- Convert a fixed 100-element stack program to runtime-size `n` (raw), then
  to vector — count failure modes removed.
- (🟡 stretch) Explain why `delete p;` twice is UB but
  `p = nullptr; delete p;` twice is safe (delete on nullptr is a no-op).

## Summary

The heap buys runtime sizing at the price of manual pairing: every
`new[]` needs exactly one `delete[]`, and the three silent failure
modes (leak, dangling, double delete) have three disciplines (match
forms, null-out, never reuse freed memory). `std::vector` wraps the
whole contract into RAII — which is why the course default is vector,
and raw `new` is taught for understanding. Next (L28): structures —
user-defined types that bundle data.

## Exit ticket / formative assessment

1. Which `delete` frees `new int[10]`?
2. A program's memory usage climbs every loop iteration. Which failure mode,
   and which line type is the suspect?
3. Why does the course default to `std::vector` over `new[]`? (One
   sentence, one keyword: RAII.)

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (passing quiz) + stack vs heap | 10 |
| new/delete + dynamic arrays + disciplines | 40 |
| Break | 10 |
| Failure modes + RAII + vector conversion | 35 |
| Failure-mode clinic | 20 |
| Exit ticket + L28 preview | 5 |
