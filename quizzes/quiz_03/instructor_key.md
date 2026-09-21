# Quiz 3 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 3 · lectures L05–L06 · Operators and Expressions · total 10 marks · CLO-2, CLO-3

**Q1 (1 mk) — C**

Precedence: 3*4=12, 12%5=2, 2+2=4. B (14) is the left-to-right reading ignoring precedence.

**Q2 (1 mk) — B**

One double operand forces floating division.

**Q3 (1 mk) — A**



**Q4 (2 mk) — 11**

3*2=6; x=5+6=11.

**Q5 (2 mk) — (a + b) / 2.0 (or cast a side), i.e., double avg{static_cast<double>(a + b) / 2};**



**Q6 (2 mk) — The standard fixes only the sign convention that (a/b)*b + a%b == a; the commonly claimed 'always non-negative' rule is false — GCC truncates toward zero, so (-7)%2 is -1.**

Accept any answer citing the identity requirement and truncation-toward-zero on the course compilers.

**Q7 (1 mk) — B**



## Common wrong answers to watch for

Q1: many pick 14 by reading left-to-right; Q6: expect vague 'sign is always positive' claims.