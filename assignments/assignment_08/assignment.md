# Assignment 8 · Score Ledger — Structs, Files, Synthesis
**Modules 13–15 (L27–L30) · 40 marks · due end of Week 15**
Outcomes: CLO-7, CLO-8 (PF-13.x–PF-15.x)

The capstone assignment: read a ledger file of scores, compute a report,
and write a clean output file. Uses `struct`, `std::vector`, and file streams.

## Input file format (`ledger.txt`, redirected or default name)

Each line: `name score` — name is one word; score is an integer 0..100.
Lines may be: blank, malformed (wrong field count, non-numeric, out-of-range),
or valid. Example:

```
Ayesha 88
Ben 72

Cara 95
Dan abc
Eve 101
```

## Behavior

1. Open `ledger.txt`; on open failure print `cannot open ledger.txt` and exit 2.
2. Parse line by line (`getline` + `istringstream`). Valid records go into
   `std::vector<Score>` where `struct Score { std::string name; int value; };`
3. Print a summary to stdout:
```
loaded : 3
skipped: 2
mean   : 85.00
best   : Cara
```
(best = highest score; ties → first in file order; skipped = every non-valid line
including blanks; mean over loaded records with 2 decimals)
4. Append the same summary to `report.txt` (create if missing).
5. Exit 0 in all cases except the open failure (exit 2). A file of only bad
   lines is *not* an error: `loaded 0` with mean/best printed as `n/a`.

## Constraints

- No raw `new`/`delete` — `std::vector` only (the course default).
- `struct Score` must be defined at file scope; helper functions take
  `const std::vector<Score>&`.
- Bad-line detection: extraction failure OR out-of-range OR wrong field count —
  all are "skipped", no crash, no early exit.
- If `report.txt` cannot be opened for append, print `cannot write report.txt`
  and exit 2 (after the stdout summary).

## Deliverables

`ledger.cpp` (contract, zero warnings) · `ledger.txt` sample (your own, ≥ 6
lines covering all line classes) · `test_table.md` — missing file, empty file,
only-bad file, tie for best, 100-record file, malformed mid-file ·
`postmortem.md` (10 marks).

## Notes

- `loaded` counts records, not lines.
- `best` prints the *name*; `mean` prints before it in the exact order shown.
