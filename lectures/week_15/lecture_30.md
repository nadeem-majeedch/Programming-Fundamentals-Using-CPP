# L30 · Robust Programs: Stream State, Error Checking, Recovery Strategies

**Module 15 — File Handling and Error Management · Week 15 · Lecture 30 of 32 · 120 minutes**
**Outcomes:** CLO-8 · PF-15.3, PF-15.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 7 clinic week · project work**

## Learning objectives

1. Inspect and repair stream state with `fail()`, `bad()`, `eof()`,
   `clear()`, and `ignore()` — mapping each state bit to its cause and its
   recovery (PF-15.3).
2. Classify program errors into three response tiers — *user-fixable input
   errors* (re-prompt), *environment errors* (report + fallback), *program
   bugs* (assert/abort) — and implement the right tier for a given failure
   (PF-15.3).
3. Design and implement recovery strategies (re-prompt with bound, default
   value, skip-and-report) for a file-processing pipeline that must survive
   malformed input (PF-15.4).

## Prerequisites

L29 (file reading/writing, open checks); L04 (basic `clear`/`ignore`
recovery — now formalized); L12 (test-case classes — malformed input is the
invalid class at file scale).

## Concept sequence

1. From "works on my data" to robust software
2. Stream state bits: good/fail/bad/eof — what each means and who set it
3. State-repair toolkit: `clear()` + `ignore()` mechanics
4. The three error tiers and their responses
5. Recovery strategies for file pipelines (skip-and-report pattern)
6. Lab clinic + capstone robustness pass

## Teaching topics (detailed)

- **State-bit table:** `goodbit/failbit/badbit/eofbit` — failbit =
  recoverable (bad format), badbit = irrecoverable (disk), eofbit = normal
  end; `fail()` covers fail|bad — why course code tests `if (!stream)`;
  state persists across reads (a failed read taints *subsequent* reads —
  the reason clear-then-ignore is a pair, L04's question answered in full).
- **`clear()` + `ignore()`:** `cin.clear();` resets state;
  `cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` discards
  the poisoned buffer — `<limits>` include; the pair as a single named
  idiom; demo: 3-input form surviving mixed garbage input.
- **Three error tiers with examples:** user input (negative price →
  re-prompt with bounded attempts), environment (missing file → error
  message + default data / graceful exit code), program bugs (impossible
  state → `assert` mention, abort strategy); response matrix keyed to
  *who can fix it*.
- **Skip-and-report pipeline:** process `scores.txt` where some lines are
  malformed; per-line parse, on failure increment `bad_lines`, log line
  number, continue — the DS-track pattern (data cleaning); end-of-run
  report (processed / skipped counts) — robustness *measured*.
- **Capstone robustness pass:** every project topic adds: open-checks
  everywhere, input validation on the menu (M5 `do-while` + L30 idiom),
  skip-and-report on the data file; the milestone rubric references these
  three behaviors explicitly.

## C++ examples required

| File | Role |
|---|---|
| `robust_pipeline.cpp` ✅ | malformed-file skip-and-report; tiered error handling; clear/ignore idiom wrapped as a function |
| (live) `input_guard.cpp` | bounded re-prompt validator (3 attempts → default) built from the state toolkit |

## Common student misconceptions

- "After a failed read, the next read just works." (State persists; the
  stream stays poisoned until cleared — demonstrated with two consecutive
  reads.)
- "`clear()` also discards the bad text." (It resets *state* only; the
  buffer needs `ignore()` — the pair, never the singleton.)
- "Robust programs never fail." (They fail *informatively and recoverably*;
  exit codes and reports are success criteria.)
- "`assert` is error handling." (It's a bug detector for impossible states,
  not user-input handling — tier separation.)

## Conceptual explanation (beginner-first)

Every `cin` operation since week 2 had a hidden second job: recording
whether it succeeded. Streams carry **state bits** — `good` (all
well), `fail` (the last read couldn't produce the value, e.g. letters
into an int), `bad` (something broke at the system level), `eof`
(the end was reached). Once a stream *fails*, it stays broken: every
later read is skipped until you repair it — and repair is a two-step
kit: `clear()` resets the state bits, `ignore(...)` flushes the bad
characters still sitting in the buffer. The pair, never the singleton.

Robust programs organize their responses into three **tiers**. Tier 1,
*input problems* (user typed letters): recoverable — clear, ignore,
re-prompt with a bound. Tier 2, *data problems* (missing file, garbage
records inside a valid file): recoverable per-item — skip-and-report,
continue, then summarize ("47 records, 3 skipped: lines 12, 30, 41").
Tier 3, *environment problems* (`badbit`, unwritable disk): not
recoverable in this course — save nothing, print a clear message, exit
with a non-zero status code.

This lecture assembles the whole toolkit into functions —
`read_int_bounded`, `skip_and_report` — that the capstone reuses, and
that make "robust" a set of checkable behaviors rather than a mood.

## Terminology and definitions

| Term | Definition |
|---|---|
| Stream state bits | good / fail / bad / eof — the stream's health flags |
| Poisoned stream | A failed stream that skips all reads until cleared |
| `clear()` | Resets the state bits (not the buffer!) |
| `ignore(n, '\n')` | Discards characters — up to n or the newline |
| Clear-then-ignore | The repair pair, always in that order |
| Tier 1: recoverable input | Re-prompt after clear+ignore, bounded attempts |
| Tier 2: recoverable data | Skip-and-report per bad record; end-of-run summary |
| Tier 3: unrecoverable | Clear message + non-zero exit status |
| Exit status | `return 1;` signals failure to the environment |
| Bounded re-prompt | Attempts limit + default/fail — no infinite loops |

## Syntax and C++ examples

```cpp
// the state toolkit as a reusable function
int readIntBounded(const std::string& prompt, int lo, int hi, int attempts)
{
    for (int used{1}; used <= attempts; ++used)
    {
        std::cout << prompt;
        int value{};
        if (std::cin >> value)                 // read + check in one
        {
            if (value >= lo && value <= hi)
                return value;                  // tier 1 success
            std::cout << "must be " << lo << ".." << hi << '\n';
        }
        else
        {
            std::cout << "that is not a number\n";
            std::cin.clear();                  // 1) reset the state
            std::cin.ignore(1000, '\n');       // 2) flush the bad text
        }
    }
    return lo;                                 // bounded default
}

// tier 2: skip-and-report over file records
int lineNo{0};
int good{0}, bad{0};
std::string line;
while (std::getline(in, line))
{
    ++lineNo;
    std::istringstream row{line};
    int score{};
    if (row >> score) { total += score; ++good; }
    else
    {
        ++bad;
        std::cerr << "line " << lineNo << ": skipped (bad record)\n";
    }
}
std::cout << good << " ok, " << bad << " skipped\n";

// tier 3: unrecoverable
if (!out)
{
    std::cerr << "fatal: cannot open output file\n";
    return 1;                                  // non-zero = failure
}
```

## Line-by-line code explanation

`examples/robust_pipeline.cpp`:

1. The bounded validator loops **at most** `attempts` times — no
   infinite re-prompt loops; each failure path clears *and* ignores
   (the singleton `clear()` bug is the demo's first patient).
2. Range checking is separated from type checking: "not a number" and
   "out of range" get different messages — diagnostics that respect
   the user.
3. The pipeline reads records with `getline` + `istringstream`: the
   *line* is read successfully even when the *record* inside is
   garbage — that separation is what makes skip-and-report possible.
4. Bad records increment `bad` and report the line number on `cerr`
   (diagnostics stream, established in L29); processing continues —
   one poisoned record never stops the batch.
5. The end-of-run summary (good/bad counts) is the contract with the
   person who supplied the data: partial success is *measured*.

## Output prediction questions (with answers)

1. `cin` fails on `"abc"`; the program calls `clear()` only, then
   reads again — what happens? — The read skips: `abc` is still in the
   buffer; `ignore` was missing.
2. State bit for letters-into-int? — failbit — tier 1, recoverable.
3. Why clear *before* ignore? — A failed stream's `ignore` does
   nothing: the state must be reset first, or the pair is a no-op.
4. A file with 10 records, 2 malformed — output of the pipeline? — 8
   processed, 2 skipped with line numbers, summary printed — exit 0.
5. `badbit` set — what should the program do? — Tier 3: message,
   save nothing, exit non-zero.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| `clear()` without `ignore()` | Infinite re-prompt on the same bad text | The pair, always |
| `ignore()` without `clear()` | Ignore silently does nothing | Same answer, other order |
| Unbounded re-prompt | User can never escape the loop | Attempts bound + default (L04 discipline, formalized) |
| Treating bad records as fatal | One garbage line kills the batch | Tier 2: skip-and-report + summary |
| Using assert for user input | Crashes in production use | assert = impossible states; tiers for data |
| Zero exit on partial failure | Calling scripts can't detect the problem | Exit status policy: define and document |

## Classroom demonstrations

1. **The poisoned stream:** type `abc` into an int prompt twice in a
   row — the second read vanishes; then the repair pair — recovery.
2. **Singleton surgery:** run the validator missing `ignore` — the
   infinite loop; add `ignore` — fixed. Other order: still broken.
3. **Skip-and-report theatre:** feed a roster file with three broken
   lines — the pipeline reports all three by line number and finishes
   with counts: robustness you can grade.

## Guided student activities
**Lab 7-style clinic (2 h, this lecture slot):** robustness clinic — teams
harden a provided fragile pipeline (missing file, garbage lines, empty
file, duplicate records) against a fault-injection checklist; graded on the
skip-and-report output and the three-tier matrix completion. Remaining time:
capstone robustness pass with TA support
([labs/README.md](../../labs/README.md)).

## Practice problems

- Map 8 failure scenarios to (state bit, tier, response, idiom).
- Implement `read_int_bounded(prompt, lo, hi, attempts)` using the full
  state toolkit.
- Harden the L29 record loader with skip-and-report + end-of-run counts.
- (🟡 stretch) Explain why `badbit` has no user-side recovery, and what the
  program should do when it's set (save nothing, exit non-zero).

## Summary

Stream state bits make failure *observable*; the clear-ignore pair
makes it *repairable*; the three tiers make responses *policy* instead
of panic: bounded re-prompts for input, skip-and-report for data,
clear-message-plus-exit-code for the unrecoverable. Robustness is now
a checklist the capstone must satisfy. Next (L31): classes — behavior
joins data.

## Exit ticket / formative assessment

1. State bit for "user typed 'abc' into an int"? Response tier?
2. Why must `clear()` precede `ignore()`?
3. Name the three tiers and one example response each.

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (file I/O quiz) + robustness motivation | 10 |
| State bits + clear/ignore idiom | 35 |
| Break | 10 |
| Error tiers + skip-and-report pipeline | 35 |
| Robustness clinic + capstone pass | 25 |
| Exit ticket + Module 16 preview | 5 |
