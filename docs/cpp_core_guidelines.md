# Applying the C++ Core Guidelines in a First Course

**Audience:** content authors.

The course does **not** teach the Core Guidelines themselves; it borrows a
small, beginner-safe subset as the rationale behind
[CODE_STYLE.md](CODE_STYLE.md) rules. When a student asks "why?", the author
notes below supply the answer in beginner terms.

## Selected guidelines and how we translate them

| Guideline (paraphrased) | Course translation | Where taught |
|---|---|---|
| Express ideas directly in code | Name things for what they mean; one responsibility per function | Weeks 6–7 (functions) |
| Initialize variables | Brace-initialize everything; never read an uninitialized variable | Week 3 (variables) |
| Keep scopes small | Declare at first use; no global mutable state | Week 7 (scope) |
| Const by default | `const`/`constexpr` unless mutation is intended | Week 3 onward |
| Prefer `vector` and `string` over raw arrays/pointers | Motivates week 9 vectors; week 12 pointers exist to explain what vector automates | Weeks 9, 12 |
| Check inputs and return values | Stream-state checks; file open checks | Weeks 3, 13 |

## Author rules

1. When a lecture note cites a rule, link to
   [CODE_STYLE.md](CODE_STYLE.md), not to the external guideline number —
   students meet one authoritative document.
2. Do not quote guideline numbering in student-facing text; numbering changes
   upstream and means nothing to beginners.
3. If a guideline conflicts with beginner clarity, clarity wins, and the
   deviation is documented here with the reason.

## Reference (verified)

- C++ Core Guidelines — Bjarne Stroustrup & Herb Sutter (isocpp.org):
  <https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines>
