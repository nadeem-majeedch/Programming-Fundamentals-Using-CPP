# Quiz 15 · File Handling and Error Management

**Week 15 · lectures L29–L30 · 15 minutes · 10 marks**
**Outcomes:** CLO-8 (PF-15.1, PF-15.2) — see [../../LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

Answer all items on this sheet. No compilers, notes, or neighbors.
Marks per item are shown in brackets.

**Q1. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`!in` after opening an ifstream tests:

- A. empty file
- B. open failure
- C. read error only
- D. EOF

**Q2. [1 mark] Multiple choice (one mark; exactly one correct answer)**

getline + istringstream per line is preferred because:

- A. it is faster
- B. malformed lines become data to classify, not crashes
- C. it needs no headers
- D. files must be line-based

**Q3. [1 mark] Multiple choice (one mark; exactly one correct answer)**

`ios::app` mode:

- A. truncates
- B. creates-or-continues (appends)
- C. reads only
- D. deletes the file

**Q4. [2 marks] Output tracing**

File contains: 5\n7\n(x). What prints for a robust read loop counting valid ints?

**Q5. [2 marks] Debugging**

This loader exits on the first malformed line. Why is that wrong for batch data, and what pattern fixes it?

**Q6. [2 marks] Short conceptual answer**

Give the exit-code discipline from the course (0 / 1 / 2 meanings) in one sentence.

**Q7. [1 mark] Multiple choice (one mark; exactly one correct answer)**

In-class try/catch demos use exceptions for:

- A. every validation
- B. exceptional structural failures, with stream-state as the everyday tool
- C. loops
- D. file opening only
