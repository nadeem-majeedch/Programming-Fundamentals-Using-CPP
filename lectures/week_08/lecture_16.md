# L16 · Debugging Methodology and Midterm Review · **MIDTERM EXAM**

**Module 8 — Advanced Function Concepts · Week 8 · Lecture 16 of 32 · 120 minutes**
**Outcomes:** CLO-1–CLO-5 · PF-8.3, PF-8.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 4 week · MIDTERM (90 min)**

## Learning objectives

1. Execute the five-step debugging loop — reproduce, isolate, hypothesize,
   test, fix — on a seeded-bug program, and document each step (PF-8.3).
2. Choose the right first tool per error class: diagnostics (syntax),
   trace tables + prints (logic), systematics (runtime) (PF-8.3).
3. Synthesize Module 1–8 outcomes under exam conditions (PF-8.4).

## Prerequisites

Modules 1–8 (all prior outcomes; the exam is cumulative to this point);
L12 (trace tables and evidence format).

## Concept sequence (hour 1 — teaching)

1. Debugging as a discipline, not an art
2. The five-step loop with a full worked example
3. Tool selection by error class
4. Print-debugging done right (labeled, scoped, removable)
5. Debug log format (course standard for labs/assignments)
6. Exam technique briefing (hour 2 = the exam)

## Teaching topics (detailed)

- **The five steps, demonstrated on one program:** *reproduce* (exact
  command + input), *isolate* (shrink inputs / comment-out halves — binary
  search the code), *hypothesize* (one sentence, falsifiable: "total is
  stale because update is after print"), *test* (trace table or prints that
  confirm/refute), *fix* (smallest change + regression test row).
- **Tool-by-error-class table:** syntax → read the *first* diagnostic;
  logic → trace table, print-debug; runtime/crash → last print that
  appeared; linker → missing/renamed definition.
- **Print-debugging rules:** label every print (`[dbg] i=3 total=15`),
  print *before* and *after* suspicious regions, delete before submission
  (style guide: no debug output in deliverables).
- **Debug log:** steps taken, hypothesis, evidence, fix — the PF-8.3
  documentation requirement; graded in labs from week 8 onward.
- **Midterm briefing:** blueprint per
  [exams/README.md](../../exams/README.md) — predict-output, trace-table,
  find-the-bug, write-a-function question forms; closed book; 90 min.

## C++ examples required

| File | Role |
|---|---|
| `buggy_off_by_one.cpp` ✅ | re-used from L12 — now debugged with the *full documented loop* (log template filled live) |
| (live) `debug_log_template.md` | worked log for one seeded bug |

## Common student misconceptions

- "Debugging = changing random things until it works." (Shotgun debugging
  creates new bugs; the loop exists to prevent it.)
- "If it compiles and runs once, it works." (Evidence vs anecdote — L12
  payoff.)
- "Removing debug prints is optional." (Style-guide violation; graders
  deduct.)

## Conceptual explanation (beginner-first)

Modules 1–8 taught you to *write* programs. Today's hour 1 is about
*repairing* them — the skill you'll actually use most — and hour 2 is
the midterm, which measures all of it.

Debugging is not luck; it's a loop with five steps. **1. Reproduce** —
find the smallest input that makes the bug show up reliably. **2.
Locate** — narrow where the bug lives (trace table, or prints between
stages). **3. Diagnose** — state the cause in one sentence *before*
touching code ("the loop runs one pass too many because the bound is
`<=`"). **4. Fix** — the smallest change that addresses that sentence.
**5. Test** — the failing case *plus* the cases that used to pass
(regression). Shotgun debugging — changing things until it happens to
work — is banned because it creates new bugs while hiding the old one.

The tool menu, in order of cost: your trace table (free, finds logic
bugs before running), print debugging (`std::cout` of state at stage
boundaries), the compiler's warnings (`-Wall` — read them *all*), then
the debugger (breakpoints, stepping — for state inspection the prints
can't reach). And the course's documentation habit: a **debug log** —
symptom, smallest reproduction, diagnosis sentence, fix, test evidence.
The exam and the labs grade the log, because the log *is* the skill.

## Terminology and definitions

| Term | Definition |
|---|---|
| Reproduce | Make the failure happen on demand, smallest input first |
| Locate | Narrow the region of code that misbehaves |
| Diagnose | The one-sentence cause statement, written before fixing |
| Fix | The minimal change addressing the diagnosis |
| Regression test | Re-running previously passing cases after any fix |
| Shotgun debugging | Random edits without diagnosis — banned practice |
| Print debugging | Temporary `std::cout` of variables/state at stage boundaries |
| Breakpoint / step | Debugger controls for pausing and single-stepping execution |
| Debug log | Symptom → reproduction → diagnosis → fix → evidence (course template) |
| Compiler warning | Suspicious-but-legal code flagged by `-Wall`; treat all as errors |

## Syntax and C++ examples

```cpp
// Stage-boundary print debugging (removed after diagnosis — style rule)
int sum{0};
for (int i{0}; i < n; ++i)
{
    sum += a[i];
    std::cout << "[dbg] i=" << i << " a[i]=" << a[i]
              << " sum=" << sum << '\n';     // the trace, live
}

// A wrong-looking average: which stage lied?
std::cout << "[dbg] sum=" << sum << " n=" << n << '\n';
double avg{sum / n};        // suspect line — diagnose BEFORE editing
```

The worked example re-uses `buggy_off_by_one.cpp` from L12: this time
the full debug log is filled in live — symptom, smallest repro, the
diagnosis sentence, the one-line fix, and the before/after evidence
rows — demonstrating the loop end to end.

## Line-by-line code explanation

The debug-log walkthrough (on `buggy_off_by_one.cpp`):

1. **Symptom:** "program prints one extra element" — quoted verbatim,
   no theories yet.
2. **Smallest reproduction:** n = 1 already misbehaves → the bug is not
   about size; it's structural.
3. **Diagnosis (the sentence):** "The final print executes because the
   loop bound is `i <= n` instead of `i < n`."
4. **Fix:** change the bound — one line, matched to the sentence.
5. **Evidence:** before/after rows for n = 1, 3, 5 plus the regression
   checks — the format required in every lab from now on.

## Output prediction questions (with answers)

1. A bug shows only for n = 1000. Which step is failing to do its job
   before this point? — Reproduction: shrink the input first.
2. You changed three things and it now works. What's missing? — The
   diagnosis + evidence: which change fixed it? (Shotgun debugging's
   bill comes due.)
3. Which tool first: trace table, print debugging, or debugger? —
   Trace table: free, and logic bugs surface on paper.
4. After a fix, the old tests fail. Name the concept. — Regression;
   step 5 exists precisely for this.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Shotgun debugging | "Works" but nobody knows why | Full five-step loop, every time |
| Fixing symptoms | The bug moves elsewhere | Diagnosis sentence before edits |
| No regression testing | Old features break quietly | Step 5 is not optional |
| Debug prints left in | Style-guide violation; noisy output | Remove at the end (or log cleanly) |
| Reading only the failing line | The cause is usually *above* the symptom | Trace upward from the manifestation |
| Treating warnings as noise | The real bugs hide behind them | `-Wall -Wextra` clean, always |

## Classroom demonstrations

1. **The loop, live:** run all five steps on the seeded bug —
   narrating each step aloud; the class sees diagnosis *precede* the
   edit.
2. **Shotgun vs. loop:** a volunteer shotguns for 2 minutes; the class
   counts the new breakages introduced — then the loop fixes it in one
   pass.
3. **Log gallery:** two filled debug logs projected; students grade
   them against the rubric before the midterm sees similar questions.

## Guided student activities
**Hour 1 lab segment (Lab 4):** [labs/README.md](../../labs/README.md)
— debug-clinic: teams run the full documented loop on two seeded programs;
graded on log quality, not just the fix. **Hour 2: MIDTERM EXAM** (90 min,
Modules 1–8, see [exams/README.md](../../exams/README.md) blueprint).

## Practice problems

- Complete a debug log for one seeded bug (submission artifact).
- Write the 5 steps you *would* take for a described non-reproducible bug.
- Midterm review set: 15 mixed questions from the four exam forms
  (posted in [exams/midterm/review_guide.md](../../exams/midterm/review_guide.md)).

## Summary

Debugging is the five-step loop — reproduce, locate, diagnose, fix,
test — with a tool ladder (trace table → prints → warnings → debugger)
and a documentation habit (the debug log) that makes the skill
assessable. Then: midterm. Next (L17): arrays — the first data
structure — begins the second half.

## Exit ticket / formative assessment

*(Post-exam reflection, submitted with the exam:)*
1. Which question type cost you the most time, and what will you practice?
2. Name the five steps of the debugging loop from memory.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Debugging loop lecture + worked example | 40 |
| Tool-selection table + debug log standard | 15 |
| **Lab 4 debug clinic (compressed, log-graded)** | 5 (extended in lab slot) |
| **MIDTERM EXAM** | 90* |

*Institutions running the exam in a separate period deliver hour 1 as a full
2-hour lecture with the complete Lab 4 in the lab slot — both variants are
supported by [COURSE_SCHEDULE.md](../../COURSE_SCHEDULE.md) § Scheduling notes.
