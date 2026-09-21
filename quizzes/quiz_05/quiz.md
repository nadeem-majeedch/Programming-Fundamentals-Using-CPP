# Quiz 5 · Loops and Repetition

**Week 5 · lectures L09–L10 · 15 minutes · 10 marks**
**Outcomes:** CLO-3, CLO-4 (PF-5.1, PF-5.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`for (int i{0}; i < n; ++i)` executes its body:

- A. n+1 times
- B. n times
- C. n-1 times
- D. depends on n's parity

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The priming read pattern belongs to:

- A. for loops
- B. sentinel-controlled while loops
- C. do-while loops
- D. infinite loops

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`do { ... } while (cond);` guarantees:

- A. the body runs at least once
- B. the body never runs
- C. cond is true at entry
- D. termination

**Q4. [2 marks] Output tracing**

Complete the trace: final value of total?

```cpp
int total{0};
for (int i{1}; i <= 4; ++i)
    total += i;
std::cout << total;
```

**Q5. [2 marks] Debugging**

This loop should stop at sentinel -1 but never does. Identify the missing piece.

```cpp
int v{};
std::cin >> v;
while (v != -1)
{
    std::cout << v << '\n';
    // line X
}
```

**Q6. [2 marks] Short conceptual answer**

Give one situation where `continue` is clearer than restructuring with if/else — one sentence.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Accumulator variables must be initialized:

- A. inside the loop each pass
- B. before the loop
- C. after the loop
- D. never — defaults are 0
