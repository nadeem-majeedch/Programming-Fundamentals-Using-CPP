# Quiz 9 · One-Dimensional Arrays

**Week 9 · lectures L17–L18 · 15 minutes · 10 marks**
**Outcomes:** CLO-6 (PF-9.1, PF-9.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

For `int a[8]`, valid indices are:

- A. 1..8
- B. 0..8
- C. 0..7
- D. 1..7

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

C++ array indexing `a[i]` with i out of range is:

- A. a compile error
- B. a runtime exception
- C. undefined behavior
- D. returns 0

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

In-place reversal of n elements performs:

- A. n swaps
- B. n/2 swaps
- C. n-1 swaps
- D. n^2 swaps

**Q4. [2 marks] Output tracing**

Array {4, 1, 7}: what does max-tracking print?

```cpp
int best{a[0]};
for (int i{1}; i < n; ++i) if (a[i] > best) best = a[i];
std::cout << best;
```

**Q5. [2 marks] Debugging**

This sum skips one element. Which, and why?

```cpp
int a[4]{2, 4, 6, 8};
int sum{0};
for (int i{0}; i < 3; ++i) sum += a[i];
```

**Q6. [2 marks] Short conceptual answer**

Why initialize max from a[0] rather than 0? One sentence (consider all-negative input).

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A frequency table for ratings 1..5 conventionally uses:

- A. counts[5] indexed by rating directly
- B. counts[6] with slot 0 unused, or index shifting
- C. a string
- D. two arrays named x and y
