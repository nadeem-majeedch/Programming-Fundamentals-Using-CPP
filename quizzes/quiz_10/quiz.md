# Quiz 10 · Two-Dimensional Arrays

**Week 10 · lectures L19–L20 · 15 minutes · 10 marks**
**Outcomes:** CLO-6 (PF-10.1, PF-10.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Row-major traversal of g[ROWS][COLS] means:

- A. outer loop over columns
- B. outer loop over rows, inner over columns
- C. diagonal order
- D. reverse order

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The main diagonal cells satisfy:

- A. r == c
- B. r + c == ROWS
- C. r > c
- D. c == 0

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

In-place transpose swaps only j > i to:

- A. save memory
- B. avoid swapping each pair twice
- C. keep it sorted
- D. satisfy the compiler

**Q4. [2 marks] Output tracing**

Grid {{1,2},{3,4}}: row totals print?

```cpp
for r: sum over c of g[r][c]
```

**Q5. [2 marks] Debugging**

A border sum double-counts corners. Describe the defect in one sentence and name the one-pass predicate fix.

**Q6. [2 marks] Short conceptual answer**

State the signature rule for passing 2-D arrays to functions (which dimension must appear?).

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Per-row accumulators must be reset:

- A. never
- B. before each row's inner loop
- C. after the whole grid
- D. inside the innermost iteration
