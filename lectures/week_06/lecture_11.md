# L11 · From Problem to Algorithm: IPO Charts, Decomposition, Pseudocode, Flowcharts

**Module 6 — Problem-Solving and Algorithm Design · Week 6 · Lecture 11 of 32 · 120 minutes**
**Outcomes:** CLO-4 · PF-6.1, PF-6.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Produce an IPO chart (Input–Processing–Output) with typed inputs, ordered
   processing steps, and precise output formats from a problem statement
   (PF-6.1).
2. Decompose a multi-step problem into a main task plus named subtasks,
   drawn as a structure/hierarchy chart (PF-6.2).
3. Express the refined algorithm in numbered pseudocode and as a flowchart
   using the four standard symbols, and argue the refinement steps from
   naive to final (PF-6.2).

## Prerequisites

M1–M5 (all control-flow constructs — now students can *read* any algorithm
they design; that's what makes this module the consolidation point).

## Concept sequence

1. Why design precedes code (bug-cost asymmetry; the "just start typing" trap)
2. IPO analysis: contract thinking
3. Decomposition: subtasks and hierarchy charts
4. Pseudocode: structured English with our control vocabulary
5. Flowcharts: the four symbols (process, decision, I/O, terminator)
6. Stepwise refinement: naive → correct → good

## Teaching topics (detailed)

- **IPO charts:** columns Input / Processing / Output; typed inputs
  (`n : int`), numbered processing steps referencing named variables, output
  *format* specified exactly (e.g. `Average = 87.50` — 2 decimals); worked on
  payroll and exam-statistics problems.
- **Decomposition:** hierarchy chart (main → read-data → compute → report);
  cohesion heuristic — each box = one sentence with no "and"; these boxes
  become functions in Module 7 (explicit forward reference).
- **Pseudocode conventions (course standard):** numbered steps; `READ`,
  `COMPUTE`, `DISPLAY`, `IF/ELSE`, `WHILE`, `FOR`; no language syntax; one
  step = one verifiable action.
- **Flowchart symbols:** oval terminators, parallelogram I/O, rectangle
  process, diamond decision (exactly two exits); loop drawn as backward
  arrow; common-shape misuse gallery.
- **Stepwise refinement on one running example:** "class average with
  drop-lowest": naive (average all) → correct (drop lowest) → good
  (validate inputs); each refinement justified by a requirement.
- **Cross-module echo:** digit extraction (M3), sentinels (M5) re-derived as
  designs, showing students they've been doing this implicitly.

## C++ examples required

| File | Role |
|---|---|
| (design-only, then built) `loop_patterns.cpp` ✅ | the ACCUMULATE pattern re-derived from its IPO chart — code shown as the *end* of the design pipeline |
| (live) `payroll_design.md` sketch on board → `payroll.cpp` skeleton | IPO → pseudocode → skeleton mapping demonstrated live |

## Common student misconceptions

- "Design documents are busywork for graders." (They are the debugging
  leverage point — a wrong IPO becomes a wrong program no compiler catches.)
- "Pseudocode is just bad C++." (It's language-independent; no `;`, no types
  except where the *contract* needs them.)
- "Decomposition means splitting into tiny steps." (It means splitting into
  *responsibilities*; a 30-step list isn't decomposition.)
- "Flowcharts must show every variable." (They show control flow, not state —
  trace tables show state, Module 6 L12.)

## Conceptual explanation (beginner-first)

Everything so far taught vocabulary: variables, branches, loops. This
lecture is about the *grammar of solving* — what experienced
programmers do between reading a problem and typing code. The process:
1. **Understand** — restate the problem in your own words; identify
inputs and outputs. 2. **Plan** — write the steps in plain language
(**pseudocode**) and trace them by hand. 3. **Code** — translate
pseudocode line by line. 4. **Test** — including the nasty cases. 5.
**Refine** — improve names, structure, and check edge cases. Most
beginner failures are step-1 or step-2 failures, not C++ failures.

Hand tracing is the core skill. Before running anything, we play
computer: a table with one column per variable, one row per step. If
the trace is wrong, the plan is wrong — fix it on paper, where it
costs seconds, not hours. And when the plan is right but the program
isn't, **incremental development** keeps you sane: write two lines,
compile, run; add a bit, compile, run. Never write 50 lines and then
compile for the first time.

## Terminology and definitions

| Term | Definition |
|---|---|
| Pseudocode | Plain-language steps describing an algorithm, no syntax |
| Algorithm | A finite sequence of unambiguous steps that solves a problem |
| Trace / dry run | Executing an algorithm on paper, recording every variable |
| Edge case | A boundary input: empty, one item, zero, maximum, negative |
| Incremental development | Build, compile, and run in tiny verified steps |
| Decomposition | Breaking a problem into smaller subproblems |
| Refinement (top-down) | Expanding a high-level step into more detailed steps |
| Desk checking | Verifying logic on paper before compiling |
| Regression | A previously-working behavior broken by a change |
| Minimum viable program | The smallest program that does one verifiable thing |

## Syntax and C++ examples

The example walks the full process on one classic problem: *read n
scores, print the highest and its position*.

Pseudocode plan (shown in the file, then coded):

```text
read n
read first score -> best, bestPos = 1
for pos from 2 to n:
    read score
    if score > best: best = score, bestPos = pos
print best, bestPos
```

Then the translation to C++ — one pseudocode line per statement — with
the trace table for input `5 42 87 87 13 60` filled in as a comment:
best moves 42 → 87 (pos 2), and the later 87 does **not** move it
(strict `>` keeps the first occurrence).

```cpp
int n{};
std::cin >> n;
int best{}, bestPos{1};
std::cin >> best;                        // first score seeds the max
for (int pos{2}; pos <= n; ++pos)
{
    int score{};
    std::cin >> score;
    if (score > best)
    {
        best = score;
        bestPos = pos;
    }
}
std::cout << best << ' ' << bestPos << '\n';   // 87 2
```

## Line-by-line code explanation

The best-so-far program (above, mirrored in `examples/loop_patterns.cpp`):

1. `std::cin >> best` seeds the maximum with the *first* value — not 0,
   which fails for all-negative scores. This is an edge case decision
   made in the planning stage.
2. The loop starts at `pos = 2` because position 1 is already consumed.
3. `if (score > best)` — strict inequality: ties keep the earliest
   position. Change to `>=` and the *last* tie wins; neither is wrong,
   but the choice must be deliberate.
4. Every pseudocode line maps to exactly one statement or small group —
   the code reads like the plan, which makes desk checking possible.

## Output prediction questions (with answers)

1. Input `5 42 87 87 13 60` — ? — `87 2` (first of the two 87s).
2. Same program with `>=` instead of `>` — ? — `87 3` (last tie wins).
3. Input `1` followed by `-5` — ? — `-5 1`; seeding with 0 would have
   printed `0 1` — a wrong answer for all-negative data.
4. Trace pseudocode `x=1; while x < 10: x = x * 2` — ? — x: 1, 2, 4, 8,
   16 — four passes, exits at 16.
5. A plan with no step to read n before the loop — what breaks? — the
   loop bound is garbage; the trace table exposes it immediately.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Coding before planning | 50 broken lines, no idea where it went wrong | Pseudocode + trace first |
| Compile-only-at-the-end | Dozens of errors at once, morale collapse | Incremental development |
| No edge cases tested | Works on samples, fails on 0 / 1 / empty | Test the boundary list every time |
| Seeding max/min with 0 | Wrong answer for all-negative (or all-positive min) input | Seed with the first real value |
| Off-by-one in "positions" | bestPos doesn't match the value | Keep position and value updated together |
| Silent scope creep | "Small change" breaks working code | Re-run the old test cases (regression) |

## Classroom demonstrations

1. **Live pseudocode → code:** solve "sum the even numbers from 1 to n"
   on the board: plan, trace with n = 10 (2+4+6+8+10 = 30), then code —
   the whole method in eight minutes.
2. **Seed-the-max trap:** run the best-so-far program on all-negative
   input with a 0 seed, then with first-value seeding — edge cases made
   visible.
3. **Break-it bingo:** hand out a working program; teams compete to list
   the most inputs that break it (empty, one, huge, negative, non-
   numeric) — testing as an active skill.

## Guided student activities

**Plan-before-code relay (25 min):** teams get a problem statement; station
1 writes the IPO chart, station 2 writes pseudocode, station 3 hand-traces
it on a given input, station 4 codes it; traces are exchanged between teams
for desk-checking before any code runs.

## Practice problems

- Write IPO charts + pseudocode for: even-number summer, digit counter,
  menu with input validation.
- Hand-trace the pseudocode from two of the above on specified inputs.
- Decompose the "highest score and its position" problem; identify the
  seeding decision and defend it.
- (🞡 stretch) Take a working program and construct three inputs that
  break it; classify each by test class.

## Summary

Programming is a process: understand, plan, trace, code, test, refine.
Pseudocode makes thinking cheap; tracing makes plans verifiable on
paper; incremental development keeps compile-run cycles short; edge
cases are checked by list, not by luck. The best-so-far pattern seeds
with the first value — an edge-case decision that belongs in the plan.
Next (L12): turning a plan into testable units — the `assert`-style
mindset and building blocks of algorithm design.

## Exit ticket / formative assessment

1. List the six steps of the problem-solving process in order.
2. Trace: `s = 0; for i in 1..4: s += i` — give the (i, s) table.
3. Why is seeding the maximum with 0 a bug for the input `-3 -7 -2`, and
   what is the fix?

1. What are the three columns of an IPO chart?
2. Convert one pseudocode step into a sentence a non-programmer could verify.
3. Which pseudocode step hides a subtask too big for one box? (Given sample.)

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (patterns quiz) + why design first | 10 |
| IPO + decomposition + hierarchy charts | 35 |
| Break | 10 |
| Pseudocode + flowcharts + stepwise refinement | 35 |
| Design-a-thon + peer review | 20 |
| Exit ticket + L12 preview | 10 |
