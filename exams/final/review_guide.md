# Final Review Guide — All 16 Modules (emphasis 9–16)

**Exam format:** 180 minutes · 100 marks. Modules 9–16 carry ≥ 60 %.
Shapes: MCQ, tracing, debugging, short conceptual, complexity intuition,
algorithm design, coding, code completion, one extended synthesis choice.
Closed book — hand-write your practice.

## Emphasis map (Modules 9–16)

| Module | Must-have skills | Practice from |
|---|---|---|
| M9 · 1-D arrays | bounds discipline, max/min from a[0], reversal, frequency tables | Quiz 09, exercises T06 |
| M10 · 2-D arrays | row-major order, diagonals, border predicate, transpose | Quiz 10, `examples/grid_basics.cpp` |
| M11 · Strings | getline vs `>>`, npos, char classes, whole-word rules | Quiz 11, exercises T07 |
| M12 · Search & sort | binary search invariants, insertion/selection traces, stability | Quiz 12, exercises T08 |
| M13 · Pointers | address-of/dereference, element arithmetic, use-after-delete guards | Quiz 13, `examples/pointer_basics.cpp` |
| M14 · Dynamic memory & structs | new[]/delete[] pairing, leak paths, record copies, vector default | Quiz 14, exercises T10 |
| M15 · Files & errors | open-check, getline+istringstream, skip-and-report, exit codes | Quiz 15, exercises T11 |
| M16 · OOP | private state, invariants, guarded mutators, const methods, has-a | Quiz 16, `examples/first_class.cpp` |

## Complexity facts to memorize

- Linear search absent key: n comparisons. Binary: ⌈log2 n⌉ (1000 → ~10; 10⁶ → ~20).
- Insertion sort: O(n) on sorted input, O(n²) worst; selection: always n²/2 compares.
- Measured counters from L23–L24: binary ≈ 10 vs linear ≈ 1000 at n = 1000.

## Trace drills

1. `a[5]{}` filled `a[i] = i*i` — `a[1] + a[4]`?
2. Selection sort pass 0 on {5,2,9,1} — the row?
3. `*p = *p + 5; p = nullptr; cout << x;` — prints?
4. `P a{3}; P b{a}; b.x = 9;` — `a.x`?

## Debugging gallery (name defect + fix)

`i <= n` on an array · corner double-count in borders · getline after `>>` ·
binary-search bound mixing · use-after-delete · early return past `delete[]` ·
unsanitized member write breaking an invariant.

## Coding practice set

1. Second-largest distinct or `N/A` (n ≤ 100).
2. Vowel/consonant/digit counts of a full line.
3. Insertion sort with per-pass printing.
4. `Counter` class with guarded `dec()` returning bool.

## The synthesis question

Expect a choose-one extended item: extra coding items, or a scaled practical
variant (extend a class or loader, design + code + your own test table). Practice
*writing a test table with expected outputs* — it is graded work.

## Exam technique

- Class questions: write the invariant as a comment first; guards fall out of it.
- File questions: open-check → per-line classify → skip counter → exit codes.
- Budget: Q7 coding items ≈ 15 minutes each; leave 20 minutes for synthesis.

See [../midterm/review_guide.md](../midterm/review_guide.md) for Weeks 1–8 foundations.
