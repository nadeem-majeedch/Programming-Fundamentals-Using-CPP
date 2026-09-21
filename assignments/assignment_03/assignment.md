# Assignment 3 · Collatz Explorer — Loops + First Functions
**Modules 5–7 (L09–L13) · 40 marks · due end of Week 7**
Outcomes: CLO-3, CLO-4, CLO-5 (PF-5.x, PF-7.x)

The Collatz rule: for n > 1, next is `n/2` if n is even, `3n+1` if odd; stop at 1.
You will build a small toolkit of functions and drive it from a menu-free main.

## Requirements

Implement and use these functions (signatures fixed):

1. `int collatzLength(long long n);` — steps from n down to 1 (n ≥ 1; return 0 for n == 1). Precondition comment required.
2. `long long collatzMax(long long n);` — the largest value seen on the path *including n itself*.
3. `void printPath(long long n);` — prints the path comma-separated, ending with 1 and a newline (e.g., `6, 3, 10, 5, 16, 8, 4, 2, 1`).

Main:

- Read one long long n (1 ≤ n ≤ 1,000,000; else `bad n`, exit 1 — validate the read itself too).
- Print `steps: L` and `max: M` on separate lines, then the path.

## Sample run

Input `6` →
```
steps: 8
max: 16
6, 3, 10, 5, 16, 8, 4, 2, 1
```

## Constraints

- All three functions take n *by value*; no globals.
- The path print must not recompute the sequence differently — reuse the rule once (single loop per function is fine; duplication of the *rule* across functions is the defect to avoid; factor a `next(n)` helper if that keeps it single-sourced).
- `3n+1` must not overflow: keep the running value in `long long` and state why in one comment.

## Deliverables

`collatz.cpp` (contract, zero warnings) · `test_table.md` — n = 1, 2, 6, 27
(steps 111, max 9232 — verify by hand for one of them), boundary 1000000, n = 0
rejected, non-numeric rejected · `postmortem.md` (10 marks).

## Notes

- n = 1 path is just `1` with 0 steps.
- The famous n = 27 case is a good stress test for your max tracker.
