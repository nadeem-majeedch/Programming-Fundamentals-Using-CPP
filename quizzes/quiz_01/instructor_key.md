# Quiz 1 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 1 · lectures L01–L02 · Introduction to Programming and C++ · total 10 marks · CLO-1

**Q1 (1 mk) — B**

Preprocessor runs before compilation; linker combines object files last.

**Q2 (1 mk) — C**



**Q3 (1 mk) — B**



**Q4 (2 mk) — 2+3=5**

`<< 2+3` prints the evaluated sum.

**Q5 (2 mk) — runtime stage: the input stream failed (EOF), so `x`'s read failed and the stream is in a failed state; the course-style fix is to check `if (!(std::cin >> x))` before using the value.**

Accept: 'the read fails at EOF; guard the stream state.'

**Q6 (2 mk) — Because std::cout is provided by the standard library (<iostream>), so programs reuse tested library code instead of writing their own output machinery.**



**Q7 (1 mk) — B**



## Common wrong answers to watch for

Watch for students confusing the linker with the preprocessor (Q1/Q2), and 'compiles = correct' reasoning (Q3).