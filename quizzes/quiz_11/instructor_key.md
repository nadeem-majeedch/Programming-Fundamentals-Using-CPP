# Quiz 11 Answer Key — INSTRUCTOR-ONLY

**Restricted** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Week 11 · lectures L21–L22 · Strings and Character Processing · total 10 marks · CLO-6

**Q1 (1 mk) — B**



**Q2 (1 mk) — B**



**Q3 (1 mk) — B**



**Q4 (2 mk) — 2 1**

find("ll") is index 2; find('z') == npos so the comparison is true.

**Q5 (2 mk) — `cin >> age` leaves the newline in the stream; the next getline consumes it as an empty line. Fix: consume the rest of the line before getline (course stream-state form).**

Accept 'use cin.ignore / flush the newline' in course wording.

**Q6 (2 mk) — A match is valid only if the character before and after are word boundaries (start/end of text or a non-letter).**



**Q7 (1 mk) — B**



## Common wrong answers to watch for

Q4: npos arithmetic (index 2, true) trips students who expect -1 and false.