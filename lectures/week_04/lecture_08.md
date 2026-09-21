# L08 · `switch`, Multi-Way Selection, and the Conditional Operator

**Module 4 — Decision-Making Statements · Week 4 · Lecture 8 of 32 · 120 minutes**
**Outcomes:** CLO-3 · PF-4.3, PF-4.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 2 week**

## Learning objectives

1. Implement `switch` statements over integral and `char` selectors with
   correct `case`/`break`/`default` structure, and predict fall-through
   behavior when `break` is omitted (PF-4.3).
2. Use the conditional operator `?:` for value-level choices and state the
   readability limits the course style guide imposes on it (PF-4.4).
3. Choose between `if/else if` chain, `switch`, and `?:` for a given decision
   problem, with a one-sentence justification tied to selector type and
   branch count (PF-4.4).

## Prerequisites

L07 (boolean evaluation, branch coverage discipline).

## Concept sequence

1. When `if/else if` chains get long: the menu problem
2. `switch` anatomy: selector, cases, `break`, `default`
3. Fall-through: bug and (rare) feature
4. Grouped cases (`case 'a': case 'A':`)
5. `?:` — the expression that chooses values (not actions)
6. Decision-structure selection criteria

## Teaching topics (detailed)

- **`switch` mechanics:** selector must be integral/char/enum (strings
  rejected — demo of the error); cases are *labels* jumped to, hence the
  need for `break`; `default` need not be last but usually is; char menus
  (`'a'` add, `'d'` delete, `'q'` quit).
- **Fall-through demo:** missing `break` executes onward — show the bug,
  then the one legitimate use (grouped labels) with a loud comment.
- **`?:` semantics:** `x = (a > b) ? a : b;` — value selection; style rule:
  values only, never nested chains (banned by
  [docs/CODE_STYLE.md](../../docs/CODE_STYLE.md)); used for max/abs/idiom
  demos.
- **Selection rubric:** few discrete integral cases → `switch`; ranged or
  compound conditions → `if/else if`; single value pick → `?:`; selector on
  strings/doubles → `if/else if` only.
- **Menu loop preview:** menu programs need repetition → Module 5 teaser
  (explicit "next module completes this pattern").

## C++ examples required

| File | Role |
|---|---|
| `switch_menu.cpp` ✅ | char-menu with grouped cases, `default`, plus the same logic as `if/else if` for side-by-side comparison |
| (live) `fallthrough_bug.cpp` | deliberate missing-`break` bug fixed live |

## Common student misconceptions

- "`switch` works on any type I can compare." (Integral/char/enum only.)
- "`default` runs when no case matches *and* then the program exits the
  switch even without `break`." (It behaves like any case: falls through.)
- "`?:` is a compact `if/else` for statements." (It's an *expression* — it
  produces a value; statements don't fit.)
- "Cases must be in numeric order."

## Conceptual explanation (beginner-first)

`if/else if` chains answer "which *range* does this value fall in?"
But menus ask a different question: "which *exact option* was typed?"
When the choices are discrete — 'a' to add, 'd' to delete, 'q' to quit —
C++ offers a purpose-built construct: `switch`. Think of it as a
telephone switchboard: the selector value is plugged in, and control
jumps directly to the matching `case` label. That jump is why `break`
matters: without it, control *keeps going* into the next case — the
fall-through bug.

The conditional operator `?:` is the third decision tool, and it is
smaller in ambition: it doesn't choose which *statements* to run, it
chooses which *value* to produce. `m = (a > b) ? a : b;` reads "if a > b
then a else b" — one line, one value. It shines for exactly that shape
and nowhere else; the course style guide bans nesting these operators.

Choosing between the three is a design skill with a rubric: discrete
integral cases → `switch`; ranges or compound conditions →
`if/else if`; a single value pick → `?:`.

## Terminology and definitions

| Term | Definition |
|---|---|
| Selector | The integral/char expression `switch` jumps on (`switch (choice)`) |
| `case` label | A named jump target for one constant value |
| `break` | Ends the switch — control leaves the block |
| Fall-through | Execution continuing into the next case when `break` is missing |
| Grouped cases | Several labels stacked on one body (`case 'a': case 'A':`) |
| `default` | The no-match branch (like a chain's final `else`) |
| Conditional operator | `cond ? valueIfTrue : valueIfFalse` — an expression |
| Expression vs statement | Expressions *produce values*; `?:` is the decision-expression |
| Integral type | Whole-number types a switch can select on: int, char, enum |

## Syntax and C++ examples

```cpp
char choice{};
std::cin >> choice;

switch (choice)                        // selector: integral or char only
{
    case 'a':                          // exact-match labels
    case 'A':                          // grouped: both spellings share a body
        std::cout << "adding...\n";
        break;                         // jump out — or fall through
    case 'd':
        std::cout << "deleting...\n";
        break;
    case 'q':
        std::cout << "bye\n";
        break;
    default:                           // everything else lands here
        std::cout << "unknown option\n";
        break;
}

// the conditional operator: a value-level decision
int m{(a > b) ? a : b};                // m = larger of a, b
int absX{(x < 0) ? -x : x};            // absolute value in one expression

// the same menu as an if/else if chain — compare for yourself
if (choice == 'a' || choice == 'A')      { /* add */ }
else if (choice == 'd')                  { /* delete */ }
else if (choice == 'q')                  { /* quit */ }
else                                     { /* unknown */ }
```

## Line-by-line code explanation

`examples/switch_menu.cpp`:

1. The `switch (choice)` selector must be an integral type or `char` —
   the file shows the compile error a `std::string` selector produces
   (in a comment; the language rejects it outright).
2. Grouped `case 'a': case 'A':` — two labels, one body: the *one*
   legitimate form of fall-through, always with a comment saying so.
3. Every body ends in `break;` — the default too; the style rule is
   "falling through is never accidental in course code."
4. The `if/else if` twin implements identical logic; the comparison
   makes the selection rubric concrete (discrete chars → switch reads
   better; the body count is the same).
5. The `?:` section computes max and absolute value — value-shaped
   decisions only.

## Output prediction questions (with answers)

1. Input `'d'` to the menu — ? — prints `deleting...` only (the `break`
   stops the fall-through).
2. Delete the `break` after case `'d'` — input `'d'` — ? — prints
   `deleting...` *and* `bye` — execution falls into case `'q'`.
3. Which selectors compile? `int` — yes; `double` — no; `char` — yes;
   `std::string` — no (compile error).
4. `m = (a > b) ? a : b;` with a = 3, b = 7 — ? — m is 7.
5. `switch (grade)` where grade is `"A"` — ? — does not compile —
   strings can't be selectors.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Missing `break` | Later cases run too — the silent classic | Break every body; grouped cases only by design |
| Selector on `double`/`string` | Compile error | Use an `if/else if` chain instead |
| Case values not constants | Compile error — labels must be literal constants | Constants only; ranges need if/else if |
| Forgetting `default` | Silent nothing for bad input | Always handle the no-match case |
| Nested `?:` chains | Unreadable logic — style-guide violation | If/else if for anything with two conditions |
| Declaration in a case without braces | "jump over initialization" error | Braces around the case body when declaring |

## Classroom demonstrations

1. **Fall-through live bug:** remove one `break`, run with input 'd',
   watch two options fire; restore — the break's job is visceral now.
2. **The rejected selector:** attempt `switch (name)` with a string;
   read the compiler's complaint; translate to the rubric.
3. **Twin menus:** run switch and if/else-if versions side by side on
   the same inputs — students articulate which reads better and why.

## Guided student activities
**Lab 2 (2 h, this lecture slot):** [labs/README.md](../../labs/README.md)
— decision drills: grade classifier variants, menu programs, switch-to-if
and if-to-switch translations, fall-through bug hunt. Lecture hour 2 = lab
launch + supervised practice.

## Practice problems
- Convert 3 `if/else if` chains to `switch` (and 1 that *cannot* be —
  say why).
- Predict output of 4 fall-through programs.
- Write a vowel/consonant checker two ways (grouped `case`, `?:`).
- (🟡 stretch) Show why `switch (score / 10)` with cases `10: 9: 8: ...`
  classifies grades — and name its limitation (no ranges like 65–69).

## Summary

`switch` selects among discrete integral cases: enumerate every value,
`break` each one, treat falling through as a bug, and use `if/else if`
whenever logic involves ranges or compound conditions. The `?:` operator
is a value-producing decision — use it only for short, obviously-shaped
choices. Next (L09): the other way programs repeat work — loops — which
turn these decision tools into iteration and open up real algorithms.

## Exit ticket / formative assessment

1. Write the `if/else if/else` equivalent of a `switch` on integer `code`
   with cases 1 and 2 plus `default`.
2. Why is the missing-`break` bug dangerous rather than merely a compile
   error?
3. What is the single circumstance where the conditional operator is a
   good choice?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (branch coverage quiz) + menu motivation | 10 |
| `switch` anatomy + fall-through live demo | 35 |
| Break | 10 |
| `?:` + selection rubric + menu-loop teaser | 25 |
| **Lab 2 launch** + supervised practice | 30 |
| Exit ticket + Module 5 preview | 10 |
