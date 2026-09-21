# C++ Standard Policy — C++17

**Audience:** everyone authoring content; quoted in every rubric.

## 1. Decision

This course teaches **C++17** (ISO/IEC TS 21541:2017 era; formally ISO/IEC
14882:2017). All examples, solutions, and assessments target C++17 and must
compile with:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic
```

(equivalent flags for clang++/MSVC in [TOOLCHAIN.md](TOOLCHAIN.md)).

## 2. Why C++17 and not older or newer

| Considered | Verdict | Reason |
|---|---|---|
| C++98/03 | rejected | Pre-dates beginners' laptops; idioms (e.g. `std::auto_ptr`) are obsolete and actively harmful |
| **C++11** | strong candidate | The "modern baseline": `auto`, range-`for`, lambdas, `nullptr`, uniform initialization |
| **C++14/17** | **selected (C++17)** | Strict improvements over C++11 with no new beginner burden: structured bindings, `if`-with-initializer, `std::string_view` (deferred in teaching), fold expressions (not needed) — and it is the default on the toolchains students will install in 2026 |
| C++20/23 | rejected for v1 | Concepts, modules, ranges are excellent but add cognitive load; a documented migration path is kept (§ 5) |

C++17 is also the intersection point of the course's two goals: *portable
standard C++* (compiles everywhere with a modern default toolchain) and
*minimal beginner confusion* (no legacy idioms, no pre-standard quirks).

## 3. The compile contract

1. Every `.cpp` file compiles **warning-free** with the flags above.
2. `int main()` returns `int`; no platform-specific entry points.
3. No compiler extensions (`-pedantic` is part of the contract).
4. Undefined behavior is banned, full stop; implementation-defined behavior
   (e.g. `int` size) must be flagged in a comment when relevant.
5. The teaching subset below is authoritative: if a lecture uses a feature,
   the feature appears in § 4; if not, it must not appear.

## 4. Feature policy — what we teach, what we defer

### 4.1 Taught (in schedule order)

`main`, statements, comments · `int`, `double`, `char`, `bool`, `const`,
brace initialization `{}` · operators & precedence · `cin`/`cout` and stream
state · `if/else`, `switch` · `while`, `do-while`, `for`, range-`for` ·
functions, overloading, default arguments, references (`T&`, `const T&`) ·
scope/lifetime · C-style arrays (as memory model + "why vector exists"),
`std::vector`, `std::string` · `struct` · pointers, `new`/`delete` (briefly,
conceptually) · `ifstream`/`ofstream` · selected `<algorithm>` functions ·
`enum class` · introduction to classes (constructor, members) · recursion.

### 4.2 Explicitly deferred (with the week we *mention* them)

| Feature | Deferred to | Why |
|---|---|---|
| `auto` for locals | mentioned week 3, taught week 9 | Safe only after types are understood |
| Lambdas | week 14 (demo only) | Needs algorithm context |
| `std::string_view` | not taught | Ownership subtleties exceed beginner scope |
| Move semantics / rvalue refs | not taught | OOP course material |
| Templates (writing) | not taught | Using `std::vector<T>` is; writing isn't |
| Exceptions | week 13 mention only | Stream checks cover error handling needs |
| Concurrency | not taught | Far beyond scope |
| Modules | not taught | C++20; build complexity |

### 4.3 Banned in course code (correctness/pedagogy)

`using namespace std;` in headers · `system("pause")` · `conio.h` ·
magic numbers without named constants · uninitialized variables ·
C-style casts · macros-as-constants.

## 5. Migration path (C++20/23)

The course is written so that a C++20 adopter can upgrade with:

1. Replace flag `-std=c++17` with `-std=c++20` (no course code should break).
2. Introduce designated initializers and `std::span` in weeks 9–12 (optional
   enrichment boxes in lecture notes).
3. Adopt `import std;` only when institutional toolchains uniformly support it.

The roadmap tracks this as a non-goal for v1 — see
[CONTENT_ROADMAP.md](CONTENT_ROADMAP.md) § 5.

## 6. References (verified, no invented citations)

- ISO C++ standard status and history: <https://isocpp.org/std/status>
- C++17 feature summary (cppreference): <https://en.cppreference.com/w/cpp/17>
- Compiler support tables (cppreference): <https://en.cppreference.com/w/cpp/compiler_support>
- Core Guidelines (Bjarne Stroustrup & Herb Sutter, isocpp.org):
  <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines>
