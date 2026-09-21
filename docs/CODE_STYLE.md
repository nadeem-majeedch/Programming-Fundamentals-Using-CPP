# C++ Style Guide (Course Standard)

**Audience:** all authors; applied to every example, solution, and rubric row.

These rules optimize for **beginner readability and correctness**, in that
order. Where this guide is silent, follow the
[Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
(see [cpp_core_guidelines.md](cpp_core_guidelines.md)).

## 1. Layout

- Indentation: **4 spaces**, never tabs.
- Braces: Allman (brace on its own line) — chosen for beginner scanning of
  block boundaries:

  ```cpp
  if (score >= 60)
  {
      std::cout << "Pass\n";
  }
  ```

- One statement per line; one variable declaration per line.
- Line length target ≤ 100 characters.
- Blank line between logical steps inside a function; no multiple blank lines.

## 2. Naming

| Entity | Convention | Example |
|---|---|---|
| Variables, parameters | `snake_case` | `total_score` |
| Functions | `snake_case`, verb-first | `compute_average()` |
| Types (struct/class/enum) | `PascalCase` | `StudentRecord` |
| Constants | `constexpr` + `k` prefix | `kMaxStudents` |
| Enumerators | `PascalCase` | `Color::Red` |

Names are pronounceable and specific (`student_count`, not `n`); loop indices
may be short (`i`, `j`) when conventional.

## 3. Declarations & types

- Initialize **every** variable; prefer brace initialization (`int x{0};`).
- `const` or `constexpr` by default; mutable only with reason.
- No global mutable variables; constants may be global.
- Prefer `std::vector`/`std::string` over raw arrays/char pointers; C arrays
  appear only where the schedule teaches the memory model (weeks 9, 12).
- Narrowing conversions are written explicitly (`static_cast<int>(x)`) —
  implicit narrowing is a review failure.

## 4. Functions

- One responsibility per function; name says what, body shows how.
- Prefer returning values over output parameters; `T&` parameters are for
  genuinely produced results, `const T&` for non-trivial inputs.
- Early `return` over deep nesting; guard clauses first.

## 5. Comments

- Explain **why**, not what — the code already says what.
- Every file begins with a one-paragraph purpose comment.
- No commented-out code in submissions; no "author/date" banners.

## 6. Includes

- Include only what you use, in this order: own header, C++ standard headers,
  C headers (rare).
- Never `using namespace std;` (even in `.cpp` — students form habits).

## 7. Program shape (course template)

```cpp
// purpose: one-line description of the program
#include <iostream>

int main()
{
    // 1. read
    // 2. compute
    // 3. report
    return 0;
}
```

## 8. Error handling

- Input is validated via stream state (`if (!(std::cin >> value))`).
- File opens are always checked.
- `assert` is acceptable in exercises after week 6 (documented in notes).

## 9. Formatting automation (optional for students, required for authors)

- `clang-format` with a config providing: 4-space indent, Allman braces,
  100-col limit. Authors run it before submitting.

## 10. Review rubric tie-in

Every code rubric row "follows course style" refers to this document; graders
do not invent personal preferences. Style errors are deducted once per
category, not per occurrence.
