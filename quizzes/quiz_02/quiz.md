# Quiz 2 · Variables, Data Types, and Input/Output

**Week 2 · lectures L03–L04 · 15 minutes · 10 marks**
**Outcomes:** CLO-2 (PF-2.1, PF-2.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`int x{2.5};` is:

- A. legal, stores 2
- B. legal, stores 2.5 rounded
- C. a compile error (narrowing in brace init)
- D. undefined behavior

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The type that stores exactly one character is:

- A. string
- B. char
- C. bool
- D. int8_t

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`std::fixed << std::setprecision(2)` makes 3.14159 print as:

- A. 3.14
- B. 3.1
- C. 3.142
- D. 3

**Q4. [2 marks] Output tracing**

User types `7` then `2`. What prints?

```cpp
int a{}; int b{};
std::cin >> a >> b;
std::cout << a / b << ' ' << a % b << '\n';
```

**Q5. [2 marks] Debugging**

This code should read a price like 12.50 but always prints 0 decimals of detail (prints 12). Identify and fix.

```cpp
double price{};
std::cin >> price;
int p{price};               // line A
std::cout << p << '\n';
```

**Q6. [2 marks] Short conceptual answer**

Why is `double` the wrong type for exact money in this course's later design discussions? Answer in one sentence.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`sizeof(int)` on the course's target platforms is:

- A. guaranteed 2 by the standard
- B. typically 4, but implementation-defined
- C. always 8
- D. defined as the same as char
