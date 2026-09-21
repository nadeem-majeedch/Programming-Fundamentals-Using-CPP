# Quiz 11 · Strings and Character Processing

**Week 11 · lectures L21–L22 · 15 minutes · 10 marks**
**Outcomes:** CLO-6 (PF-11.1, PF-11.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`s.size()` for an empty std::string returns:

- A. -1
- B. 0
- C. 1
- D. undefined

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

Reading a full line with spaces uses:

- A. cin >> s
- B. getline(cin, s)
- C. scanf
- D. s.read()

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`std::string::npos` means:

- A. zero
- B. not found
- C. the last index
- D. string length

**Q4. [2 marks] Output tracing**

What prints?

```cpp
std::string s{"hello"};
std::cout << s.find("ll") << ' ' << (s.find('z') == std::string::npos);
```

**Q5. [2 marks] Debugging**

After `cin >> age;` the next `getline` reads an empty line. Explain and give the standard fix (stream-state form taught in class).

**Q6. [2 marks] Short conceptual answer**

Give the boundary rule for whole-word matching of "cat" so it does not match "category". One sentence.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`isalpha('3')` returns:

- A. true
- B. false
- C. 3
- D. '3'
