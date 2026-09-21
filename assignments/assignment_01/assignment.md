# Assignment 1 · Course Record Card — Variables, I/O, Arithmetic
**Modules 1–2 (L01–L04) · 40 marks · due end of Week 3**
Outcomes: CLO-1, CLO-2 (PF-1.x, PF-2.x)

A department office prints student record cards. You will produce one card from
keyboard input, with correctly typed and formatted numbers.

## Requirements

1. Read, in this order: student name (single word), age (int), lab grade, midterm
   grade, final grade (doubles, 0–100).
2. Print a card exactly in this shape (example values `Ayesha 20 88 79 91`):

```
=== COURSE RECORD ===
name   : Ayesha
age    : 20
lab    : 88.00
midterm: 79.00
final  : 91.00
average: 86.00 (weighted: lab 25% / midterm 35% / final 40%)
```

3. The weighted average must use the stated percentages and print with exactly
   2 decimals (`std::fixed`, `std::setprecision(2)`).
4. If any read fails (EOF or non-numeric), print `bad input` and exit with code 1.
5. Grades outside 0–100: print `bad input` and exit with code 1 (no card).

## Constraints

- Use `int` for age only; grades are `double`.
- The weighted average must be computed in one expression with a `static_cast<double>` somewhere it is needed.
- No functions beyond `main` are required yet (decomposition is graded from A3 onward).

## Sample runs

```text
input:  Ayesha 20 88 79 91
output: (card above; average: 86.00)
```
Check: 88·0.25 + 79·0.35 + 91·0.40 = 22 + 27.65 + 36.4 = 86.05 → the sample card
should print `86.05`; if your program prints `86.00` you have an integer-division
or precedence defect.

## Deliverables

1. `record_card.cpp` — compiles with the course contract, zero warnings.
2. `test_table.md` — at least: two typical runs, one boundary (grade 0 and 100),
   one invalid grade, one failed read (EOF). Pre-compute expected values *before*
   running (`testing.md` rubric).
3. `postmortem.md` — one real defect you hit: symptom → hypothesis → test → fix
   (`explanation.md` rubric, 10 of the 40 marks).

## Submission

Zip `record_card.cpp`, `test_table.md`, `postmortem.md`. Naming per
`../../labs/resources/submission_template.md`. Late policy per syllabus.
