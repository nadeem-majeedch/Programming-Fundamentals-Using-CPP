# L06 · Type Conversions, Compound Assignment, and Mixed-Type Expressions

**Module 3 — Operators and Expressions · Week 3 · Lecture 6 of 32 · 120 minutes**
**Outcomes:** CLO-2 · PF-3.3, PF-3.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Assignment 1 due**

## Learning objectives

1. Predict the value and type of mixed-type expressions: `int → double`
   promotion, assignment-driven conversion, and truncation on
   double→int narrowing (PF-3.3).
2. Convert deliberately with `static_cast<int>(...)` / `static_cast<double>(...)`
   and state where each is required in course code (PF-3.4).
3. Rewrite update expressions with `+=`, `-=`, `*=`, `/=`, and pre/post
   `++`/`--`, and predict expression values when increment placement matters
   (PF-3.4).

## Prerequisites

L05 (arithmetic, truncation); L03 (assignment semantics).

## Concept sequence

1. Implicit conversions: the compiler's silent rewrites
2. Promotion in mixed arithmetic (`int` op `double` → `double`)
3. Assignment conversion: widening vs narrowing (truncation, no rounding)
4. Explicit `static_cast` — course policy for narrowing
5. Compound assignment & increment operators
6. Pre- vs post-increment: value of the *expression* vs the *variable*

## Teaching topics (detailed)

- **Promotion ladder:** `bool → char → int → double`; demo:
  `3 + 0.5` → `3.5` (`int` promoted); `7 / 2` vs `7 / 2.0` vs
  `static_cast<double>(7) / 2` — three ways, one lesson.
- **Assignment conversion:** `double d{5};` fine (widening);
  `int i{5.7};` rejected by braces but `int i = 5.7;` compiles with
  truncation → course policy: braces + explicit casts for narrowing;
  `int i{static_cast<int>(5.7)};` → 5.
- **char↔int:** `static_cast<int>('A')` → 65 (peek at ASCII table; full use
  in Module 11); `char c{static_cast<char>(66)};` → 'B'.
- **Compound assignment:** `x += 5` as `x = x + 5`; readable only as
  update-in-place; loop-counter previews.
- **`++`/`--`:** prefix vs postfix — *variable* ends the same, *expression
  value* differs (`int y = x++;` vs `int y = ++x;` with a state table);
  course style: prefer standalone statements or prefix; never two `++` on one
  variable in one statement (undefined behavior).
- **Boolean pitfall preview:** `bool b = 3.9;` → `true` (any nonzero →
  true); revisited in Module 4.

## C++ examples required

| File | Role |
|---|---|
| `conversion_demo.cpp` ✅ | promotion, narrowing, casts, char codes — 12 printed lines students predict first |
| (live) `increment_trace.cpp` | pre/post-increment state-table walk |

## Conceptual explanation (beginner-first)

Types must agree for an operation to happen — but C++ quietly *converts*
values to make them agree. Mostly this is helpful: `3 + 0.5` becomes `3.5`
because the `3` is **promoted** to a double. But conversions can also lose
information: storing `5.7` into an `int` throws away the `.7` — **not** by
rounding, but by truncating toward zero. The danger is that the `=` form
performs this narrowing *silently*; that is why the course standardizes:
brace-init when you mean it, explicit `static_cast` when narrowing is truly
intended.

The increment family (`++`, `--`) adds/subtracts one. The subtlety is the
difference between *the variable's* new value and *the expression's* value:
`++x` increments first, then yields the new value; `x++` yields the old
value, then increments. In standalone statements there is no difference —
which is why the course style says: use them standalone, and the subtlety
stays out of your way.

## Terminology and definitions

| Term | Definition |
|---|---|
| Implicit conversion | Compiler-inserted conversion to make types agree |
| Promotion | Smaller type widened (`int` → `double`) — no data loss |
| Narrowing | Conversion that can lose data (`double` → `int`, truncation) |
| `static_cast<T>(x)` | Explicit, searchable conversion — course-required for narrowing |
| Compound assignment | `x += 5` ≡ `x = x + 5` (also `-= *= /= %=`) |
| Increment `++` / decrement `--` | Add/subtract 1 (prefix vs postfix forms) |
| Prefix vs postfix | `++x`: increment then yield; `x++`: yield then increment |
| Truncation toward zero | `-3.9` → `-3` (not −4); same rule as integer division |

## Syntax and C++ examples

```cpp
double d{5};                          // promotion: 5 -> 5.0 (safe)
int truncated = 5.7;                  // = form: silent truncation -> 5
int dollars{static_cast<int>(19.99)}; // explicit, searchable -> 19
int back{static_cast<int>(-3.9)};     // -> -3 (toward zero)

char c{'A'};
int code{static_cast<int>(c)};        // 65 — chars are small numbers

int x{5};
x += 3;         // x = 8
x *= 2;         // x = 16
++x;            // x = 17 (standalone: prefix/postfix identical)
int old{x++};   // old = 17, x = 18 (postfix yields OLD value)
int neu{++x};   // x = 19 first, neu = 19 (prefix yields NEW value)
```

## Line-by-line code explanation

`examples/conversion_demo.cpp` (predict each printed line first):

1. `3 + 0.5` → `3.5`: the `int` is promoted; the *whole expression* becomes
   double.
2. `double widened{5};` → prints `5` — widening never loses data, so braces
   allow it.
3. `int truncated = 5.7;` → `5` — the `=` form silently truncates. The
   commented line above it (`int narrowed{5.7};`) is what *would* produce
   `error: narrowing conversion` — the brace shield.
4. `static_cast<int>(19.99)` → 19 and `static_cast<int>(-3.9)` → **-3** —
   truncation toward zero, not flooring.
5. `nine / 2.0` → 4.5 (promotion mid-expression), then wrapped in
   `static_cast<int>` → 4 — the two-step pipeline students must trace.
6. `static_cast<int>('A')` → 65, `static_cast<char>(66)` → `B` — the
   char↔int dictionary that Module 11 builds on.
7. `bool flag = 3.9;` → prints `1` — any nonzero value becomes true; note
   the braces would reject this narrowing (as intended).

## Output prediction questions (with answers)

1. `int x = 9 / 2.0;` — x? — `4` (9/2.0 is 4.5, then truncation on store).
2. `static_cast<int>(-3.9)` — ? — `-3` (toward zero).
3. After `int a{5}; int b{a++};` — a and b? — `a=6, b=5` (postfix yields
   the old value).
4. After `int a{5}; int b{++a};` — ? — `a=6, b=6`.
5. `double half{7 / 2};` — half? — `3.0` — the division happened in ints
   FIRST; storing into a double is too late (the classic order-of-events
   question).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Rounding assumption | `static_cast<int>(2.9)` believed to be 3; it is 2 | Cast truncates; round explicitly if needed |
| Cast after the fact | `double d{7 / 2};` → 3.0 | Make ONE operand double: `7 / 2.0` |
| Silent narrowing via `=` | Data loss with no diagnostic | Brace-init; `static_cast` when intended |
| Two `++` on one variable in a statement | Undefined behavior | One modification per expression |
| `x++` where `++x` intended (in expressions) | Off-by-one using the yielded value | Standalone style avoids it entirely |

## Common student misconceptions

- **"`int + double` is an error because types differ."** C++ promotes
  via the usual arithmetic conversions; students expect a compile error
  like Python 3's `int + str`.
- **"Assignment in a condition is a typo the compiler catches."**
  `if (x = 5)` assigns; only some cases warn — the course habit is `if
  (5 == x)` in risky spots or compiling with warnings on.
- **"`x += 1` and `x = x + 1` can differ."** For built-in types they
  compute the same; the compound form also avoids repeating a possibly
  expensive side-effecting left side.
- **"Casting changes the stored value."** `static_cast<int>(7.9)`
  converts *the value produced by the expression*; it never edits the
  original object.
- **"Narrowing never bites if it compiles."** List initialization
  (`int x{3.9};`) is rejected, but plain assignment `int x = 3.9;`
  silently truncates — show both side by side.

## Classroom demonstrations

1. **The two-line proof:** compile `int a{5.7};` (error) beside
   `int b = 5.7;` (silent 5) — the brace shield made visible.
2. **Pre/post state tables:** trace `int old{x++};` and `int neu{++x};` on
   the board with columns `x`, `yielded` — the table IS the explanation.
3. **Character codes:** print `'A'` + 1 as char → `'B'`, seeding Module 11's
   letter arithmetic.

## Guided student activities
**Conversion carousel (20 min):** 6 stations around the room, each with a
3-line program and a prediction card; students rotate, commit predictions,
then the station answer is revealed; debrief the two most-missed stations.

## Practice problems
- Predict type+value of 8 mixed expressions (promotions, casts, char math).
- Rewrite 6 update statements with compound assignment; 2 with correct
  pre/post choice.
- Repair a money-split program that truncates the tip; use `static_cast`
  where required by the style guide.
- (🟡 stretch) Show with a program that `0.1 + 0.2 == 0.3` is `false`; print
  with `setprecision(17)`.

## Summary

Mixed-type expressions promote; assignment may narrow silently — which is
why the course requires braces (which reject narrowing) and explicit
`static_cast` (which documents it). Truncation is toward zero. Compound
assignment updates in place; pre/post increment differ only in the value
the *expression* yields — keep them standalone and the trap vanishes.
Next (Module 4): programs that choose — `if`, comparisons, and logical
operators.

- "The compiler warns about every bad conversion." (Narrowing via `=`
  compiles silently; braces are the seatbelt.)
- "`static_cast` is just fancy syntax for rounding." (It *truncates* toward
  zero and works for char↔int too.)
- "`x++` and `++x` are interchangeable everywhere." (Statement: yes;
  expression: no.)
- "`double` arithmetic is exact." (0.1 + 0.2 ≠ 0.3 demo here as a
  seed for Module 12 comparisons.)

## Exit ticket / formative assessment

1. `int x = 9 / 2.0;` — value? type of the right-hand side *before* the
   assignment conversion?
2. `static_cast<int>(-3.9)` = ?
3. After `int a{5}; int b{a++};` what are `a` and `b`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (division quiz) + silent conversions motivation | 10 |
| Promotion + assignment conversion + `static_cast` policy | 35 |
| Break | 10 |
| Compound assignment + pre/post increment with state tables | 30 |
| Conversion carousel activity | 20 |
| Assignment 1 hand-in reminder + exit ticket | 15 |
