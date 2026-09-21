# Assignment 7 · Text Toolkit — Strings & Sorting
**Modules 11–12 (L21–L24) · 40 marks · due end of Week 13**
Outcomes: CLO-6 (PF-11.x, PF-12.x)

A text utility with three modes, driven by one command word.

## Modes

1. `wc` — read one line; print `words W chars C longest L`
   (whitespace-separated words; L = longest word's length; empty line → `0 0 0`).
2. `word` — read one word W then one line T; print `yes` if W occurs in T as a
   *whole word* (boundary = non-letter or line edge), else `no`.
   Case-sensitive.
3. `sortn` — read n (1 ≤ n ≤ 100) then n integers; print them sorted ascending
   on one line, then `swaps S` where S = the number of swaps your
   **selection sort** performed (count swaps only, not comparisons).

## Sample runs

| Input | Output |
|---|---|
| `wc / the   cat sat` | `words 3 chars 11 longest 3` |
| `word / cat / the category cat` | `yes` (two whole-word hits; category rejected) |
| `word / cat / concatenate` | `no` |
| `sortn / 4 / 5 2 9 1` | `1 2 5 9` then `swaps 2` |
| `sortn / 3 / 1 2 3` | `1 2 3` then `swaps 0` |

(Verify the swap count for `5 2 9 1` by hand: pass 0 swaps 5↔1; pass 1 swaps
9↔2; pass 2 is 5 already in place → 2 swaps. Your test table must show this.)

## Constraints

- `sortn` must implement selection sort yourself — no `std::sort`.
- `wc` must use `getline`; mode dispatch reads the command word first.
- Whole-word match uses index boundaries only — no `std::istringstream` for mode 2.
- Strings: `std::string` only; no C-strings.

## Deliverables

`textkit.cpp` (contract, zero warnings) · `test_table.md` — multi-space lines,
tab-separated words, whole-word at line start/end, word longer than any target
token, sorted input, reverse-sorted input, n = 1 and n = 100 · `postmortem.md`
(10 marks).

## Notes

- `chars` counts every character of the line including spaces.
- For `sortn`, after sorting you must print the sorted line *then* the swaps line — two lines total.
