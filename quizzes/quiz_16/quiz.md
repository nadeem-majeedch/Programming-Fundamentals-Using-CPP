# Quiz 16 · Introduction to Object-Oriented Programming

**Week 16 · lectures L31–L32 · 15 minutes · 10 marks**
**Outcomes:** CLO-8 (PF-16.1, PF-16.3) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A private data member can be accessed:

- A. anywhere
- B. by member functions of the class (and friends)
- C. by derived classes only
- D. never

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

An invariant is:

- A. a loop condition
- B. a property that holds after every public method
- C. a comment
- D. a private member

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A const member function promises:

- A. speed
- B. it will not modify the object's state
- C. no parameters
- D. private access

**Q4. [2 marks] Output tracing**

What prints?

```cpp
class C { public: void set(int v) { x_ = v; } int get() const { return x_; } private: int x_{0}; };
C c; c.set(7); std::cout << c.get();
```

**Q5. [2 marks] Debugging**

Withdrawing more than the balance succeeds. Which invariant is broken, and where is the validation placed (the only legal door)?

**Q6. [2 marks] Short conceptual answer**

One sentence: what does has-a composition mean for a Garage containing Cars?

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Encapsulation's main benefit for invariants is:

- A. smaller binaries
- B. a small attack surface: all writes pass through guarded methods
- C. faster I/O
- D. automatic testing
