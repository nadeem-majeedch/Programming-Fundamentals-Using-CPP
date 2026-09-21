# Quiz 13 · Pointers and References

**Week 13 · lectures L25–L26 · 15 minutes · 10 marks**
**Outcomes:** CLO-7 (PF-13.1, PF-13.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`&x` yields:

- A. the value of x
- B. the address of x
- C. a copy of x
- D. the dereference of x

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`int* p = nullptr; *p = 5;` is:

- A. fine
- B. undefined behavior (null dereference)
- C. a compile error
- D. sets p to 5

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

For an `int*`, `p++` advances by:

- A. one bit
- B. one byte
- C. sizeof(int) — one element
- D. 8 bytes always

**Q4. [2 marks] Output tracing**

What prints?

```cpp
int x{4};
int* p{&x};
*p = 9;
std::cout << x;
```

**Q5. [2 marks] Debugging**

State the two guards that prevent use-after-delete symptoms.

**Q6. [2 marks] Short conceptual answer**

One sentence: when is a reference parameter preferable to a pointer parameter?

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A reference, once bound:

- A. can be reseated
- B. cannot be reseated
- C. can be null
- D. must be const
