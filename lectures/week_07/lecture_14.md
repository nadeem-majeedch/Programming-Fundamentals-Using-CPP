# L14 · Scope, Lifetime, and Program Decomposition with Functions

**Module 7 — Functions Fundamentals · Week 7 · Lecture 14 of 32 · 120 minutes**
**Outcomes:** CLO-5 · PF-7.3, PF-7.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Assignment 2 due**

## Learning objectives

1. Predict program output involving local, block, global, and shadowed
   variables, and state each variable's scope and lifetime (PF-7.3).
2. Explain why global mutable variables are banned in course code, citing
   the two failure modes (hidden coupling, re-entrancy surprise) (PF-7.3).
3. Decompose a fresh 60–100 line problem into a function structure using
   stepwise refinement, then implement it to specification (PF-7.4).

## Prerequisites

L13 (functions, call stack, copy semantics); L09–L10 (loops for the
decomposed program).

## Concept sequence

1. Scope = where a name is visible; lifetime = when it exists
2. Local scope and block scope; fresh frames per call
3. Global variables and constants — allowed vs banned
4. Shadowing: legal, confusing, avoidable
5. Static locals (mentioned, not encouraged)
6. Full decomposition workflow: spec → hierarchy → functions → main

## Teaching topics (detailed)

- **Scope/lifetime table:** local (`{}` block, per-call), parameter (per-call),
  global (whole file, whole run), `const` global (allowed — named constants
  from L03), static local (exists across calls; shown for completeness with
  a "you won't need it this semester" note).
- **Shadowing demo:** inner `int total` hiding outer `total` — compiles,
  runs, wrong; `-Wshadow`-style awareness via careful reading; course rule:
  never shadow.
- **Global mutables banned:** two failure modes demonstrated — (1) a bug in
  one function silently corrupts state used by another; (2) the same call
  returns different results depending on history. `const` globals (`kMaxStudents`)
  remain encouraged.
- **Decomposition workflow (the capstone of M6+M7):** exam-statistics program
  — spec → IPO (L11) → hierarchy chart (4 functions) → signatures designed
  first (paper exercise) → bodies filled → `main` as 6 readable lines.
- **Signature-first design:** write all prototypes before any body — forces
  contract thinking; catching signature mismatches at compile time.

## C++ examples required

| File | Role |
|---|---|
| `scope_lifetime_demo.cpp` ✅ | 4 labeled mini-sections: block scope, shadowing, global mutable bug, static local — printed traces students predict first |
| (live) `exam_stats_decomposed.cpp` | built live from hierarchy chart in ≤ 8 minutes, signatures first |

## Conceptual explanation (beginner-first)

Last lecture a function received *one* number at a time. But real data
comes in sets: 30 quiz scores, a week of temperatures. Copying values
into a function one by one would be absurd — instead, we hand the
function the **array** itself. In C++, what actually travels is the
address of the first element (a low-level idea we'll name honestly in
Module 13), plus a separate count parameter. Because the function holds
the address, it can *see and change* the caller's elements: unlike a
single `int`, an array parameter behaves like an open notebook, not a
photocopy.

That power needs discipline. The function cannot ask an array how long
it is — C++ does not carry that information inside the parameter — so
**the caller passes the size** and the function trusts it. And to
promise "I will look but not touch," we mark the element type `const`:
`const int a[]`. The compiler then rejects any attempt to write
`a[i] = ...`, turning a class of silent bugs into compile errors.

## Terminology and definitions

| Term | Definition |
|---|---|
| Array parameter | Declared as `int a[]` or `int* ` — receives the address of element 0 |
| Decay | An array expression converts to a pointer to its first element when passed |
| Size parameter | The companion `int n` (or `std::size_t n`) a function needs to know the length |
| `const` array parameter | `const int a[]` — the function promises not to modify elements |
| In-place update | Modifying the caller's array through the parameter |
| Search space | The range of positions a searching algorithm still examines |
| Sentinel search | Stop at the target *or* at the end-of-data marker |

## Syntax and C++ examples

```cpp
// const: read-only access to the caller's elements
void printAll(const int a[], int n)
{
    for (int i{0}; i < n; ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

// write access: fill with a value
void fill(int a[], int n, int value)
{
    for (int i{0}; i < n; ++i)
        a[i] = value;                    // changes the CALLER's array
}

// returning a computed result from an array
int sumAll(const int a[], int n)
{
    int total{0};
    for (int i{0}; i < n; ++i)
        total += a[i];
    return total;
}

// count matches — the pattern most homework is built from
int countBelow(const int a[], int n, int limit)
{
    int count{0};
    for (int i{0}; i < n; ++i)
        if (a[i] < limit) ++count;
    return count;
}
```

## Line-by-line code explanation

`examples/array_algorithms.cpp` (search functions):

1. `linearSearch(const int a[], int n, int key)` — walks 0..n-1, returns
   the index of the first match or the sentinel `-1` if none. The caller
   must check for `-1` before using the result.
2. `findMax(const int a[], int n)` — seeds with `a[0]`, scans 1..n-1.
   For an empty array the caller must guarantee `n >= 1` (documented as a
   precondition) — otherwise the seed itself is undefined behavior.
3. Every traversal uses `i < n` (not `<=`): exactly n elements, 0-based.
4. The `const` on read-only functions is the contract in action —
   remove it and re-add a stray write; the compiler flags the line.

## Output prediction questions (with answers)

1. `int x[3]{5,5,5}; fill(x, 3, 9); printAll(x, 3);` — ? — `9 9 9` —
   the change is visible to the caller (in-place).
2. `sumAll({2, 3, 4}, 3)` — ? — 9.
3. `linearSearch` on `{8, 1, 8}` for key 8 — ? — index 0 (first match).
4. `linearSearch` for 42 in `{8, 1}` — ? — `-1`; the caller must test it.
5. `countBelow({4, 9, 1}, 3, 5)` — ? — 2.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Forgetting the size parameter | Function can't know where to stop | Always pair `int a[], int n` |
| Passing `n` but looping `i <= n` | Reads one past the end (garbage or crash) | `i < n` |
| Missing `const` on read-only function | Accidental writes compile silently | `const` every read-only array parameter |
| Using the returned index without checking | `-1` used as a real index → out-of-bounds | `int pos = linearSearch(...); if (pos != -1) ...` |
| Assuming the function receives a copy | Caller surprised by changed elements | Arrays pass the address — document in-place functions |
| `sizeof(a) / sizeof(a[0])` inside the function | Gives pointer size, not element count — classic trap | Pass `n` explicitly |

## Common student misconceptions

- **"A variable declared in a block survives after the block."**
  Automatic objects die at scope exit; the name and the object share a
  lifetime — dangling use of a stale name is a compile error, which is
  *protective* here.
- **"Passing by value copies nothing for big types."** Every parameter
  is initialized from the argument; show a class-type copy being made
  (a copy constructor print) to make the cost concrete.
- **"A reference parameter is a pointer the compiler hides."**
  Conceptually a reference is an alias; the *observable* difference from
  pass-by-value (mutation visible in the caller) is what matters now.
- **"Shadowing is a warning about names, not values."** An inner `x`
  makes the outer `x` unreachable by name — code reading the wrong `x`
  produces plausible-looking wrong answers.
- **"Global variables are convenient, so use them."** They break the
  function-contract habit the module builds; local parameters keep
  functions testable and reusable.

## Classroom demonstrations

1. **The notebook metaphor:** print the same array twice — hand one
   "photocopy" (a by-value int) into a pretend function, hand the
   original (the array) into another — which comes back changed?
2. **Compiler as contract-enforcer:** remove `const` from `sumAll`, add
   `a[0] = 0;`, compile — the error names the line; restore.
3. **Off-by-one autopsy:** change one loop to `<= n`, run — the garbage
   value printed is the memory lesson.

## Guided student activities
**Signature auction (20 min):** teams bid (with points) on proposing the best
function set for a "text-menu currency converter" spec; each bid must state
name, params, return, and the single responsibility; class votes on winning
architectures; instructor reveals their version for comparison.


1. **Pattern cards:** each pair gets one operation (sum, count, max,
   search, fill) and writes its function; groups compare skeletons —
   they differ in one or two lines only.
2. **Contract writing:** for `countBelow`, write the one-sentence
   contract (what it needs, what it returns, what it does NOT change).
3. **Bug hunt:** a five-line `findMin` with a `<=` bound and no `const`
   — find both defects, one by reading, one by compiling.

## Practice problems
- Predict output of 5 scope/shadowing programs (with explanations).
- Convert a global-mutating program to parameter-passing form.
- Full decomposition (IPO + signatures + implementation) for a "delivery
  cost estimator" (weight tiers + distance zones).
- (🟡 stretch) Explain why two calls to a function using a static local
  counter return different values — and why that violates testability.

## Summary

Functions + arrays = collections made reusable: the array parameter
delivers the address (changes are visible to the caller), the size
parameter delivers the length, and `const` separates readers from
writers at compile time. The search/count/max skeletons from this
lecture are the raw material of nearly every homework problem ahead.
Next (L15): two-dimensional arrays — tables, grids, and rows that are
arrays themselves.

## Exit ticket / formative assessment

1. A variable declared inside `main`'s `for` loop — scope? lifetime?
2. Why is `const int kMaxStudents{120};` at file scope acceptable while
   `int total{0};` is not?
3. Name the first artifact you produce when decomposing (not code).

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (call-stack quiz) + scope vs lifetime | 10 |
| Scope rules + shadowing + global policy | 35 |
| Break | 10 |
| Decomposition workflow (signature-first build) | 35 |
| Signature auction activity | 20 |
| Assignment 2 hand-in + exit ticket | 10 |
