# Quiz 14 · Dynamic Memory and Structures

**Week 14 · lectures L27–L28 · 15 minutes · 10 marks**
**Outcomes:** CLO-7, CLO-8 (PF-14.1, PF-14.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`new int[10]` must be released with:

- A. delete
- B. delete[]
- C. free()
- D. nothing

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Forgetting delete on a heap allocation causes:

- A. compile error
- B. a leak (silent)
- C. immediate crash
- D. a warning

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

struct copies via assignment copy:

- A. nothing
- B. the address
- C. all members (a record copy)
- D. only the first member

**Q4. [2 marks] Output tracing**

What prints?

```cpp
struct P { int x; };
P a{3}; P b{a}; b.x = 9;
std::cout << a.x;
```

**Q5. [2 marks] Debugging**

This loop allocates each iteration without freeing on every path. Classify and give the two course-approved fixes.

```cpp
for (...) {
    int* p{new int[1000]};
    if (cond) return;   // line A
    delete[] p;
}
```

**Q6. [2 marks] Short conceptual answer**

One sentence: why is std::vector the course default over manual new/delete?

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Half-migrating parallel arrays to structs leaves:

- A. faster code
- B. the record-misalignment bug class alive
- C. cleaner headers
- D. no change
