# Lab 9 · One-Dimensional Arrays

**Module 9 · Lectures L17–L18 · Week 9 · 120 minutes · guided/independent 50/50**

Prerequisites: completion of Labs 1–8 (Lab 1: none). Bring your laptop
with the course toolchain verified (see § 3) and your exercise notebook.

## 2. Learning objectives

By the end of this lab you can:

- Declare, fill, and traverse arrays within bounds
- Implement sum/average/min/max/count patterns
- Reverse an array in place
- Explain why C++ does not bounds-check []

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

bounds discipline, one-pass statistics, in-place reverse — full treatment in the
[lecture notes](../../../lectures/README.md); the lab applies it, the lecture
explains it.

## 5. Pre-lab questions

Answer in your notebook BEFORE the session; the TA checks them at entry:

1. Valid indices for int a[10] are which values?
2. Why initialize max from a[0] (or handle n==0 first)?
3. What happens off the end? (undefined behavior — not a friendly error)

## 6. Instructor demonstration (15 min)

The instructor or TA demonstrates: **Array loops, bounds, statistics patterns**. Watch for the *workflow*
(how errors are read and fixed), not just the final code. The demo ends
with the checkpoints you must hit in § 7.

## 7. Guided coding tasks

1. guided: fill/print/sum on an 8-element array
2. guided: in-place reverse with the swap trace
3. independent: statistics toolkit (min, max, avg, above-avg count)
4. independent: frequency table for ratings 1..5 with histogram

**Checkpoint rule:** show each guided result to the TA before moving on.
TAs give *guidance, not solutions*
([../../TEACHING_GUIDE.md](../../../TEACHING_GUIDE.md) § 5).

## 8. Independent programming exercises

Complete the tasks labeled *independent* in § 7 **without** step-by-step
help. You may consult lecture notes and this manual — not a neighbor's
screen. The TA records who completes what.

## 9. Debugging task

**Off-by-one hunt: two supplied array bugs (read past end; skip last)**

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
reliably declare, fill, and traverse arrays within bounds; implement sum/average/min/max/count patterns; reverse an array in place; explain why C++ does not bounds-check []. This maps to the module's PF outcomes and feeds
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
