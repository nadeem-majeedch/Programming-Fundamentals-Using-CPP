# Lab 12 · Searching and Sorting

**Module 12 · Lectures L23–L24 · Week 12 · 120 minutes · guided/independent 40/60**

Prerequisites: completion of Labs 1–11 (Lab 1: none). Bring your laptop
with the course toolchain verified (see § 3) and your exercise notebook.

## 2. Learning objectives

By the end of this lab you can:

- Implement linear and binary search with counters
- State binary search's precondition and invariant
- Trace selection and bubble sort with snapshots
- Compare costs with counted comparisons

These deliver the module's outcomes (PF codes in
[../../LEARNING_OUTCOMES.md](../../../LEARNING_OUTCOMES.md)).

## 3. Required software and compiler

- **Compiler contract:** `g++ -std=c++17 -Wall -Wextra -pedantic` (GCC 13+
  via MSYS2/MinGW-w64 on Windows; GCC or clang++ on macOS/Linux — see
  [../../docs/TOOLCHAIN.md](../../../docs/TOOLCHAIN.md)).
- **Editor:** any (VS Code + C/C++ extension recommended; debugger optional
  until Lab 4).
- **Verify before starting:**

  ```bash
  g++ --version
  ```

- Starter files for this lab live in `starter_code/` next to this manual;
  they compile warning-free under the contract (see
  [../../../docs/LAB_AUDIT.md](../../../docs/LAB_AUDIT.md)).

## 4. Relevant theory

invariants, traced sorts, counted comparisons — full treatment in the
[lecture notes](../../../lectures/README.md); the lab applies it, the lecture
explains it.

## 5. Pre-lab questions

Answer in your notebook BEFORE the session; the TA checks them at entry:

1. What breaks if binary search receives unsorted data?
2. Which sort does NO work on sorted input?
3. Roughly how many comparisons does binary search make for n = 1000?

## 6. Instructor demonstration (15 min)

The instructor or TA demonstrates: **Search correctness, sort tracing, complexity intuition**. Watch for the *workflow*
(how errors are read and fixed), not just the final code. The demo ends
with the checkpoints you must hit in § 7.

## 7. Guided coding tasks

1. guided: linear search with comparison counter
2. guided: selection sort snapshot trace on 6 elements
3. independent: binary search with counters + absent keys
4. independent: sort-then-search benchmark comparing counted costs

**Checkpoint rule:** show each guided result to the TA before moving on.
TAs give *guidance, not solutions*
([../../TEACHING_GUIDE.md](../../../TEACHING_GUIDE.md) § 5).

## 8. Independent programming exercises

Complete the tasks labeled *independent* in § 7 **without** step-by-step
help. You may consult lecture notes and this manual — not a neighbor's
screen. The TA records who completes what.

## 9. Debugging task

**Binary search boundary bug (low < high vs <=) — diagnose and fix**

Use the five-step debug loop (reproduce, isolate, hypothesize, test,
fix-and-verify) and record it in your debug log
([../../labs/resources/debug_log_template.md](../../resources/debug_log_template.md))
from Lab 4 onward. Identify the *stage* of each defect (compile, link,
runtime, logic).

## 10. Test cases

Your program must pass at minimum:

- Boundary values (0, 1, maximum legal input).
- Normal cases from the task descriptions.
- At least one invalid input handled gracefully (from Lab 4 onward).

Record results in the test-evidence table
([../../labs/resources/submission_template.md](../../resources/submission_template.md)):
input, expected, actual, verdict.

## 11. Expected learning outcomes

After this lab, verified by the checkpoints and your submission, you can
reliably implement linear and binary search with counters; state binary search's precondition and invariant; trace selection and bubble sort with snapshots; compare costs with counted comparisons. This maps to the module's PF outcomes and feeds
the next lab's prerequisites.

## 12. Submission requirements

Submit via the course LMS before **the start of next week's lab**:

1. Source file(s) named per the task list (snake_case).
2. Test-evidence table (completed template).
3. Debug log for the § 9 task (Lab 4 onward).
4. Pre-lab answers (photo or scan is fine).

Code must compile **warning-free** under the course contract — a warning
costs the compile check (§ 13).

## 13. Assessment rubric (10 points)

| Criterion | Points | Evidence |
|---|---|---|
| Pre-lab completed | 1 | notebook check at entry |
| Guided checkpoints | 3 | TA sign-offs during session |
| Independent tasks correct | 3 | code + test evidence |
| Debug task diagnosed (not just fixed) | 2 | debug log with stage + cause |
| Compiles warning-free + naming/format | 1 | build log, file names |

Total 10, scaled to the 10 % course component. Labs 1–15 count the best
12 of 15 (drop-lowest); Lab 16 is graded as the project milestone with the
same rubric plus the demo (see the instructor notes).
