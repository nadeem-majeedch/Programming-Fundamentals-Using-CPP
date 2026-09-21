# Lab 4 · Decision-Making

**Module 4 · Lectures L07–L08 · Week 4 · 120 minutes · guided/independent 70/30**

Prerequisites: completion of Labs 1–3 (Lab 1: none). Bring your laptop
with the course toolchain verified (see § 3) and your exercise notebook.

## 2. Learning objectives

By the end of this lab you can:

- Write decision tables before if-statements
- Order ladder branches so the most specific test runs first
- Translate if/else chains to switch and back
- Guard division and input ranges with early exits

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

decision tables, ladder order, switch-if translation, short-circuit guards — full treatment in the
[lecture notes](../../../lectures/README.md); the lab applies it, the lecture
explains it.

## 5. Pre-lab questions

Answer in your notebook BEFORE the session; the TA checks them at entry:

1. In a >= ladder, which threshold must be tested first, and why?
2. For which types does switch NOT work?
3. What does short-circuit evaluation protect in (b != 0 && a/b > 2)?

## 6. Instructor demonstration (15 min)

The instructor or TA demonstrates: **if/else, ladders, switch, boolean operators**. Watch for the *workflow*
(how errors are read and fixed), not just the final code. The demo ends
with the checkpoints you must hit in § 7.

## 7. Guided coding tasks

1. guided: elevator decision table to code
2. guided: grade ladder (correct order, then deliberately reversed)
3. independent: electricity tariff with slabs and a daily cap
4. independent: menu-driven shape calculator with switch

**Checkpoint rule:** show each guided result to the TA before moving on.
TAs give *guidance, not solutions*
([../../TEACHING_GUIDE.md](../../../TEACHING_GUIDE.md) § 5).

## 8. Independent programming exercises

Complete the tasks labeled *independent* in § 7 **without** step-by-step
help. You may consult lecture notes and this manual — not a neighbor's
screen. The TA records who completes what.

## 9. Debugging task

**A tariff program with a reversed ladder — trace the wrong branch, fix**

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
reliably write decision tables before if-statements; order ladder branches so the most specific test runs first; translate if/else chains to switch and back; guard division and input ranges with early exits. This maps to the module's PF outcomes and feeds
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
