# Quiz 14 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 14 · lectures L27–L28 · Dynamic Memory and Structures · total 10 marks · CLO-7, CLO-8

**Q1 (1 mk) — B**



**Q2 (1 mk) — B**



**Q3 (1 mk) — C**



**Q4 (2 mk) — 3**

b is a copy; a is untouched.

**Q5 (2 mk) — Leak on the early-return path (line A skips delete[]). Fixes: free on every exit path with one owner, or replace with std::vector (RAII, the course default).**



**Q6 (2 mk) — The vector frees its memory automatically at scope exit, so leaks and use-after-delete cannot occur by construction.**



**Q7 (1 mk) — B**



## Common wrong answers to watch for

Q4: shallow-copy confusion — some answer 9.