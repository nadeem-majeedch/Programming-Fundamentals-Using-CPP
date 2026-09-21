# Quiz 7 · Functions Fundamentals

**Week 7 · lectures L13–L14 · 15 minutes · 10 marks**
**Outcomes:** CLO-5 (PF-7.1, PF-7.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A function prototype declares:

- A. the body
- B. name, return type, parameter types
- C. local variables
- D. the call sites

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Why return values instead of printing inside functions?

- A. printing is illegal in functions
- B. returning makes functions testable and reusable
- C. returning is faster to type
- D. printing requires headers

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`double area(double r)` and `double area(double w, double h)` are:

- A. a redefinition error
- B. a valid overload set
- C. a recursion
- D. templates

**Q4. [2 marks] Output tracing**

What prints?

```cpp
int f(int x) { return x * 2; }
int main() { std::cout << f(3) + f(4); }
```

**Q5. [2 marks] Debugging**

This function computes but the caller sees no change. Name the mechanism and fix two ways.

```cpp
void addTax(double price)
{
    price *= 1.17;
}
```

**Q6. [2 marks] Short conceptual answer**

Write the contract comment (precondition/postcondition) for a `safeDivide(int a, int b, int& out)`.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The √n divisor bound in isPrime is valid because:

- A. primes are small
- B. any factor pair has one member ≤ √n
- C. division is expensive
- D. n/2 is unsafe
