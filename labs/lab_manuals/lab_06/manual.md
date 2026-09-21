# Lab 6 · Algorithm Design

**Module 6 · Lectures L11–L12 · Week 6 · 120 minutes · guided/independent 60/40**

Prerequisites: completion of Labs 1–5 (Lab 1: none). Bring your laptop
with the course toolchain verified (see § 3) and your exercise notebook.

## 2. Learning objectives

By the end of this lab you can:

- Write an IPO chart before coding
- Decompose a problem into ordered sub-steps
- Hand-trace with a trace table including expected outputs
- Design boundary test cases (0, 1, max, empty, invalid)

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

IPO charts, decomposition, trace tables, boundary tests — full treatment in the
[lecture notes](../../../lectures/README.md); the lab applies it, the lecture
explains it.

## 5. Pre-lab questions

Answer in your notebook BEFORE the session; the TA checks them at entry:

1. What belongs in an IPO chart that pseudocode omits?
2. Why test 0, 1, and n separately for a loop?
3. Is a trace table made before or after the code — and why?

## 6. Instructor demonstration (15 min)

The instructor or TA demonstrates: **IPO, decomposition, trace tables, test design**. Watch for the *workflow*
(how errors are read and fixed), not just the final code. The demo ends
with the checkpoints you must hit in § 7.

## 7. Guided coding tasks

1. guided: IPO + pseudocode for a parking-fee problem
2. guided: trace-table on a supplied digit-reversal program
3. independent: design test sets for a supplied validator (5 cases minimum)
4. independent: implement your own IPO from case study CS-018

**Checkpoint rule:** show each guided result to the TA before moving on.
TAs give *guidance, not solutions*
([../../TEACHING_GUIDE.md](../../../TEACHING_GUIDE.md) § 5).

## 8. Independent programming exercises

Complete the tasks labeled *independent* in § 7 **without** step-by-step
help. You may consult lecture notes and this manual — not a neighbor's
screen. The TA records who completes what.

## 9. Debugging task

**Trace-table sprint: trace 2 supplied programs by hand, then verify**

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
reliably write an IPO chart before coding; decompose a problem into ordered sub-steps; hand-trace with a trace table including expected outputs; design boundary test cases (0, 1, max, empty, invalid). This maps to the module's PF outcomes and feeds
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
