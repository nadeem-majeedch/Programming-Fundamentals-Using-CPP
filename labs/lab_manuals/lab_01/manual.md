# Lab 1 · First C++ Program

**Module 1 · Lectures L01–L02 · Week 1 · 120 minutes · guided/independent 70/30**

Prerequisites: completion of Labs 1–1 (Lab 1: none). Bring your laptop
with the course toolchain verified (see § 3) and your exercise notebook.

## 2. Learning objectives

By the end of this lab you can:

- Build and run a C++ program from the command line
- Identify the four translation stages
- Read a compiler error and locate its line
- Make a deliberate change and predict its effect

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

edit-compile-run cycle, error location, deliberate prediction — full treatment in the
[lecture notes](../../../lectures/README.md); the lab applies it, the lecture
explains it.

## 5. Pre-lab questions

Answer in your notebook BEFORE the session; the TA checks them at entry:

1. What four stages turn hello.cpp into a running process?
2. Which line does the compiler report FIRST in a program with two errors?
3. What is the difference between a compile error and a runtime error?

## 6. Instructor demonstration (15 min)

The instructor or TA demonstrates: **Toolchain & edit-compile-run cycle**. Watch for the *workflow*
(how errors are read and fixed), not just the final code. The demo ends
with the checkpoints you must hit in § 7.

## 7. Guided coding tasks

1. guided: modify the greeting program in 3 small steps
2. guided: break-and-fix cycle on an instructor-chosen line
3. independent: personal info card (name, id, program) formatted
4. independent: add an output line using an escape sequence you look up

**Checkpoint rule:** show each guided result to the TA before moving on.
TAs give *guidance, not solutions*
([../../TEACHING_GUIDE.md](../../../TEACHING_GUIDE.md) § 5).

## 8. Independent programming exercises

Complete the tasks labeled *independent* in § 7 **without** step-by-step
help. You may consult lecture notes and this manual — not a neighbor's
screen. The TA records who completes what.

## 9. Debugging task

**A program with 3 planted errors (one per stage) — classify each before fixing**

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
reliably build and run a C++ program from the command line; identify the four translation stages; read a compiler error and locate its line; make a deliberate change and predict its effect. This maps to the module's PF outcomes and feeds
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
