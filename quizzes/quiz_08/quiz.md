# Quiz 8 · Advanced Function Concepts

**Week 8 · lectures L15–L16 · 15 minutes · 10 marks**
**Outcomes:** CLO-5 (PF-8.1, PF-8.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Pass-by-reference means the function:

- A. gets a copy
- B. can access the caller's object directly
- C. gets a pointer value it must dereference
- D. cannot modify anything

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Recursion terminates when:

- A. the function calls itself
- B. the base case is reached and the argument shrinks each call
- C. a loop inside finishes
- D. the stack overflows

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

digitSum(907) via `n%10 + digitSum(n/10)` returns:

- A. 907
- B. 16
- C. 97
- D. 7

**Q4. [2 marks] Output tracing**

What prints?

```cpp
void bump(int& v) { ++v; }
int n{9}; bump(n); std::cout << n;
```

**Q5. [2 marks] Debugging**

This recursion never ends for n=5. State the missing piece.

```cpp
int fact(int n)
{
    return n * fact(n - 1);
}
```

**Q6. [2 marks] Short conceptual answer**

One sentence: what does a default argument promise existing call sites?

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Scope resolution `::total` refers to:

- A. the local total
- B. the global total
- C. a member of a class named total
- D. a macro
