# Quiz 3 · Operators and Expressions

**Week 3 · lectures L05–L06 · 15 minutes · 10 marks**
**Outcomes:** CLO-2, CLO-3 (PF-3.1, PF-3.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`2 + 3 * 4 % 5` evaluates to:

- A. 20
- B. 14
- C. 4
- D. 0

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Which expression computes the average of int scores a and b correctly?

- A. (a + b) / 2
- B. (a + b) / 2.0
- C. a + b / 2
- D. (a / 2 + b / 2)

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`x++` as a statement is equivalent to:

- A. ++x
- B. x + 1
- C. x =+ 1
- D. x += x

**Q4. [2 marks] Output tracing**

What prints?

```cpp
int x{5};
x += 3 * 2;
std::cout << x << '\n';
```

**Q5. [2 marks] Debugging**

This should print the fractional average 3.5 but prints 3. Fix minimally.

```cpp
int a{3}; int b{4};
double avg{(a + b) / 2};
std::cout << avg << '\n';
```

**Q6. [2 marks] Short conceptual answer**

State one thing the C++ standard guarantees about `%` and one thing the standard does NOT specify about its sign rules for negative operands as commonly misstated — answer in one sentence using course wording.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`static_cast<double>(n)` is preferred over C-style `(double)n` in this course because:

- A. it is faster
- B. it is more visible in search and states intent explicitly
- C. C-style casts are illegal
- D. it avoids rounding
