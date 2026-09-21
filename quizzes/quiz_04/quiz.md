# Quiz 4 · Decision-Making Statements

**Week 4 · lectures L07–L08 · 15 minutes · 10 marks**
**Outcomes:** CLO-3 (PF-4.1, PF-4.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

In an if/else-if ladder testing `score >= 60`, `>= 70`, `>= 90` for grades, the correct order is:

- A. 60, 70, 90
- B. 90, 70, 60
- C. any order works
- D. 70, 90, 60

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`switch` does NOT accept which controlling type?

- A. int
- B. char
- C. std::string
- D. enum values

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`(b != 0 && a / b > 2)` is safe because:

- A. && always evaluates both sides
- B. short-circuit evaluation skips the division when b == 0
- C. division by zero returns 0
- D. the compiler reorders the test

**Q4. [2 marks] Output tracing**

Input 95 — what prints?

```cpp
int s{};
std::cin >> s;
if (s >= 90) std::cout << "A";
else if (s >= 80) std::cout << "B";
else std::cout << "F";
```

**Q5. [2 marks] Debugging**

This switch never prints B. Why?

```cpp
int x{2};
switch (x) {
    case 1: std::cout << "A";
    case 2: std::cout << "B";
}
// note: output shows "B" for x==1 too
```

**Q6. [2 marks] Short conceptual answer**

Write a decision TABLE (4 rows) for an elevator at floors 1–2: current, requested, verdict.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The conditional operator in `fee = hours > 5 ? 20 : 10;` assigns:

- A. 20 always
- B. 10 always
- C. 20 if hours > 5 else 10
- D. 10 if hours > 5 else 20
