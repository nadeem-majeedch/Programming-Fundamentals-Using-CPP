# L12 · Desk-Checking, Trace Tables, and Test-Case Design

**Module 6 — Problem-Solving and Algorithm Design · Week 6 · Lecture 12 of 32 · 120 minutes**
**Outcomes:** CLO-4 · PF-6.3, PF-6.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 3 week**

## Learning objectives

1. Desk-check any straight-line, selection, or loop construct into a complete
   variable-state trace table, showing every variable's value before/after
   each step or iteration (PF-6.3).
2. Design a test plan with named classes — normal, boundary, invalid — and
   justify why each case can reveal a distinct failure (PF-6.4).
3. Report test evidence as expected-vs-actual with a one-line verdict, the
   format required in every lab and assignment for the rest of the semester
   (PF-6.4).

## Prerequisites

L11 (IPO/design artifacts); L09–L10 (trace basics, loop patterns).

## Concept sequence

1. Why tracing beats re-reading (attention lies; tables don't)
2. Trace-table mechanics: rows = steps/iterations, columns = variables
3. Tracing selection and nested structures
4. Test-case classes: normal, boundary, invalid (+ stress)
5. Boundary analysis: where do bugs actually live
6. Evidence reporting format (course standard)

## Teaching topics (detailed)

- **Trace-table protocol:** number every statement; one column per variable
  (+ output column); fill row-by-row *without running*; annotate the row
  where the bug manifests — the bug is usually *above* that row.
- **Worked traces:** the L09 digit-sum loop; an `if/else if` grade chain
  (trace across *branches*, marking the taken path); a nested pair loop
  (iteration-count column).
- **Test classes (course vocabulary):**
  - *normal:* typical valid values (2–3 cases),
  - *boundary:* edges of validity — min, max, min−1, max+1, empty/zero,
  - *invalid:* wrong type, out-of-range, sentinel-as-data.
  - Rule: **every boundary in the IPO chart must appear in the test plan.**
- **Expected-vs-actual tables:** `input | expected | actual | pass/fail`
  — the exact format labs/assignments require; a bug fix needs a
  before/after row pair.
- **Trace-then-test workflow:** desk-check finds *logic* bugs before
  running; tests find them after; both are cheaper than debugging blind —
  the module's closing argument.

## C++ examples required

| File | Role |
|---|---|
| `buggy_off_by_one.cpp` ✅ | 3 seeded bugs (off-by-one, wrong boundary, inverted condition); students must find them by trace table first, then by test plan |
| (live) `test_evidence.md` template filled for the buggy program | expected-vs-actual table modeled live |

## Common student misconceptions

- "Testing means trying it once with a normal value." (Normal cases are the
  *least* likely to reveal bugs — boundaries are.)
- "Desk-checking is only for when the program doesn't compile." (It's for
  logic bugs, which *do* compile.)
- "A passed test proves correctness." (It proves *this input* works;
  evidence accumulates, certainty doesn't.)
- "Trace tables are busywork." (They are the exam format for control-flow
  questions — show the midterm blueprint connection.)

## Conceptual explanation (beginner-first)

Last lecture planned programs on paper. Today: the two paper skills
that catch bugs *before* and *after* running — the trace table and the
test plan.

A **trace table** is you, playing computer. One column per variable
(plus an output column), one row per step or loop pass. You fill rows
*without running anything*, and — the crucial habit — you mark the row
where the output first goes wrong, because the bug almost always lives
*above* that row: the wrong value was computed earlier and merely
*showed up* here. Tracing beats re-reading because attention lies (you
skim past the wrong bound; the table doesn't) — this is why exams use
trace questions: they measure whether you actually simulate code.

A **test plan** is the record of what you'll try *after* running: not
random values, but named **classes** — normal (typical valid input),
boundary (the edges: min, max, min−1, max+1, empty, zero), invalid
(wrong type, out of range). The rule this course enforces: *every*
boundary in your IPO chart must appear in your test plan. And the
reporting format — input, expected, actual, verdict — becomes the
evidence table in every lab and assignment from here to the final.

## Terminology and definitions

| Term | Definition |
|---|---|
| Desk checking / trace table | Paper execution: rows = steps/passes, columns = variables |
| Manifestation row | Where the wrong output first appears — the bug is usually above it |
| Path marking | Annotating the trace with the branch taken at each decision |
| Test case | One input + its expected output, chosen in advance |
| Normal class | Typical valid inputs (2–3 cases) |
| Boundary class | Edges of validity: min, max, min−1, max+1, empty, zero |
| Invalid class | Wrong type, out of range, sentinel-as-data |
| Expected vs actual | The evidence table: input, expected, actual, pass/fail |
| Regression | A previously passing case broken by a change |
| Limits of testing | Passing tests ≠ correct; they prove behavior on those inputs only |

## Syntax and C++ examples

The worked trace (digit-sum loop, from L09):

| pass | work | digit | digitSum | note |
|---|---|---|---|---|
| enter | 907 | — | 0 | invariant holds |
| 1 | 90 | 7 | 7 | `work % 10`, then `work /= 10` |
| 2 | 9 | 0 | 7 | zero digit — pass still runs |
| 3 | 0 | 9 | 16 | loop condition now false → exit |

And a test plan for an "age 3–120" validator:

| input | class | expected |
|---|---|---|
| 25 | normal | accepted |
| 3 / 120 | boundary | accepted |
| 2 / 121 | boundary | rejected |
| -1 / 1000 | boundary | rejected |
| `"abc"` / empty | invalid | rejected |

```cpp
// the seeded-bug program students trace and test:
for (int i{1}; i <= n; ++i)   // bug: should be i < n (off-by-one)
{
    sum += a[i];
}
```

## Line-by-line code explanation

`examples/buggy_off_by_one.cpp` (three seeded bugs, found on paper
first):

1. **Off-by-one:** `i <= n` — the trace table shows the extra pass
   reading `a[n]` (one past the end): garbage in, garbage summed.
2. **Wrong boundary:** a parking-fee tier whose `else if (hours > 3)`
   should be `>= 3` — the boundary test case (exactly 3) exposes it;
   no normal case ever would.
3. **Inverted condition:** `if (!(score >= 60))` intended as "pass" —
   the path marking in the trace shows both branches firing in the
   wrong columns.
4. The lesson ordering: trace → diagnosis sentence → *then* run; the
   expected-vs-actual table documents what the fix changes.

## Output prediction questions (with answers)

1. Trace `s += i * 2` for `i = 2..4` (s starts 0) — ? — rows (2, 4),
   (3, 10), (4, 18); final s = 18.
2. Age validator: which class catches `120` vs `121`? — Boundary
   class — normal cases never touch the edge.
3. Expected 8.5, actual 8 — what do you ask first? — "Is this integer
   division truncation?" (L05's lesson re-appearing as a debugging
   question).
4. Why mark the manifestation row? — The bug's *cause* computed an
   earlier wrong value; the symptom only shows it.
5. A program passes all six planned tests. Is it correct? — Unknown:
   tests prove behavior on those inputs only.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Tracing from the symptom row | Wrong fix downstream of the cause | Start at row 1; mark the manifestation |
| One column for several variables | The table hides its own bug | One column per variable, always |
| Skipping the output column | Wrong answers go unnoticed mid-table | Add the output column and use it |
| Tests only normal cases | Boundaries silently broken | Every IPO boundary in the plan |
| "Fix first, diagnose later" | Shotgun editing (banned in L16) | Diagnosis sentence before any edit |
| Evidence without expected values | "It looked right" isn't evidence | Expected column filled *before* running |

## Classroom demonstrations

1. **The manifestation-row hunt:** hand out a traced-wrong table; the
   class marks where output goes wrong, then walks *upward* to the
   causing line — the habit made physical.
2. **Boundary theatre:** a fee program passes every normal case;
   input `3` (the boundary) breaks it — normal cases are the least
   informative, demonstrated live.
3. **Evidence formatting:** fill the expected-vs-actual table on the
   board for the buggy program, before/after the one-line fix.

## Guided student activities
**Lab 3 (2 h, this lecture slot):** [labs/lab_manuals/lab_03](../../labs/README.md)
— trace-table drills on loops and branches, then bug-hunt in
`buggy_off_by_one.cpp` with mandatory test-evidence tables. Lecture hour 2 =
lab launch + demonstration of the evidence format on the board.

## Practice problems
- Full trace tables for 3 programs (loop, branch-chain, nested pairs).
- Write test plans (≥ 6 cases with class labels) for: leap-year checker,
  parking-fee tiers, sentinel averager.
- Find the seeded bugs in `buggy_off_by_one.cpp` — trace table first, run
  only after committing to a diagnosis.
- (🟡 stretch) Construct an input that passes all *given* tests but is wrong
  — the limits-of-testing lesson.

## Summary

Trace tables simulate code row by row; the manifestation row points
*upward* to the cause. Test plans cover normal, boundary, and invalid
classes — with every IPO boundary present — and report evidence as
expected-vs-actual with a verdict. Both skills are exam formats *and*
daily habits; L16 turns them into a debugging method. Next (L13):
functions — the shape programs take when they grow.

## Exit ticket / formative assessment

1. Trace two iterations: `int s{0}; for (int i{2}; i <= 4; ++i) s += i * 2;`
2. Name the boundary cases for "valid age 3–120".
3. A test shows expected 8.5, actual 8. What single question do you ask
   first?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (IPO quiz) + why tracing | 10 |
| Trace-table mechanics with 2 worked examples | 35 |
| Break | 10 |
| Test-case classes + evidence format | 25 |
| **Lab 3 launch** (trace + bug-hunt drills) | 30 |
| Exit ticket + Module 7 preview | 10 |
