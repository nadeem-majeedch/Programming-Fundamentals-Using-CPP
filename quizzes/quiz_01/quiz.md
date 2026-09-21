# Quiz 1 · Introduction to Programming and C++

**Week 1 · lectures L01–L02 · 15 minutes · 10 marks**
**Outcomes:** CLO-1 (PF-1.1, PF-1.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Which sequence correctly describes how a C++ source file becomes a running process?

- A. edit → run → compile
- B. preprocess → compile → assemble → link
- C. compile → preprocess → run → link
- D. link → compile → assemble → run

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

The compiler stage that handles `#include` directives is:

- A. the assembler
- B. the linker
- C. the preprocessor
- D. the optimizer

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

A program that compiles with no errors can still misbehave because of:

- A. logic errors only
- B. runtime or logic errors
- C. nothing — compiling proves correctness
- D. linker errors only

**Q4. [2 marks] Output tracing**

What does this program print?

```cpp
#include <iostream>
int main() {
    std::cout << "2+3=" << 2+3 << '\n';
    return 0;
}
```

**Q5. [2 marks] Debugging**

The program below should print Hi but prints nothing and exits. Name the most likely defect stage and the fix.

```cpp
#include <iostream>
int main() {
    int x{0};
    std::cin >> x;   // user types nothing, presses Ctrl+Z/Ctrl+D
    std::cout << "Hi\n";
}
```

**Q6. [2 marks] Short conceptual answer**

In one sentence: why is `std::cout << "Hi"` usable without writing class code yourself?

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Which is a compile error (not a warning)?

- A. unused variable
- B. missing semicolon
- C. comparing signed with unsigned
- D. unreferenced parameter
