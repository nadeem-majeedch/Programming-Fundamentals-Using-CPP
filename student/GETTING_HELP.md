# Getting Help (Without Losing Time)

**The 30-minute rule:** if one error resists you for 30 minutes, get help.
Struggling is how you learn; *silent* struggling is how you fall behind.

## 1. Before you ask — the 5-minute self-check

1. **Read the error top-down.** The first diagnostic is usually the real one;
   later lines are often echoes. Find the file and line number.
2. **Reproduce it.** Run the exact command from
   [../docs/TOOLCHAIN.md](../docs/TOOLCHAIN.md) § 5. Does it still fail?
3. **Check the last change.** Undo the last edit mentally — did the error move?
4. **Explain it aloud** (rubber-duck style): "This loop should sum 1..10, but
   `total` prints 555." Saying the expectation out loud finds logic bugs fast.
5. **Shrink the program.** Comment out half; does the error remain? Binary
   search your own code.

## 2. Ask a good question (in office hours, lab, or the forum)

Include, in this order:

1. What you expected to happen.
2. What actually happened (paste the **first** error and the code near its
   line number).
3. What you already tried (from § 1).

Asking this way is itself course outcome PF-A4
([../LEARNING_OUTCOMES.md](../LEARNING_OUTCOMES.md)).

## 3. Where to get help

| Channel | Best for |
|---|---|
| Lectures — ask immediately | concept confusion |
| Labs — raise your hand | build/run errors, task checkpoints |
| Office hours | assignments, debugging strategy, grading questions |
| Class forum/mailing list (as set up by your instructor) | quick environment questions |

## 4. Integrity guardrails when asking online

Discussing *ideas* publicly is fine; posting assignment code or pasting
submissions into external services is not
([../COURSE_OVERVIEW.md](../COURSE_OVERVIEW.md) § 4.2). The suggested
classroom AI policy: assistants may *explain* errors; they may not *write*
code you submit.
