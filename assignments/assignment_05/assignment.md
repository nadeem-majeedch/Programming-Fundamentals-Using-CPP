# Assignment 5 · Sensor Array Analytics — 1-D Arrays
**Module 9 (L17–L18) · 40 marks · due end of Week 10**
Outcomes: CLO-6 (PF-9.x)

A weather station logs hourly readings. You will compute a small analytics
report with fixed-size arrays and clean function decomposition.

## Input

First an integer n (1 ≤ n ≤ 1000): the number of readings. Then n integers
−50..60 (°C). Any reading outside −50..60 is *skipped* (still consumes input)
and counted as invalid; n is the count of *all* readings, valid or not.

## Report (exact labels)

```
valid : V
invalid: I
min   : m
max   : M
mean  : x.x (1 decimal)
above : A        (strictly greater than mean, among valid readings)
```

If there are no valid readings, print the `min/max/mean/above` block as
`n/a` lines instead (four lines, each label followed by `n/a`).

## Required functions

- `int readReadings(int a[], int cap);` — fills a, returns valid count (invalid skipped but counted via reference or second channel).
- `int minOf(const int a[], int n);` / `int maxOf(const int a[], int n);` — preconditions n ≥ 1.
- `double meanOf(const int a[], int n);`
- `int countAbove(const int a[], int n, double threshold);`

## Sample run

Input `7 | 20 -99 22 19 999 22 21` →
`-99` and `999` invalid →
```
valid : 5
invalid: 2
min   : 19
max   : 22
mean  : 20.8
above : 3
```
(mean of 20,22,19,22,21 = 20.8; above = 22,22,21 → 3)

## Constraints

- Fixed array `int readings[1000];` — no vectors yet (vectors enter in M14).
- Every function takes the array with a `const` correctness where it does not modify.
- No repeated passes over the data beyond the four required analytics (one fill, then each function once).

## Deliverables

`sensors.cpp` (contract, zero warnings) · `test_table.md` — all-invalid input,
single valid, boundary values −50/60, mean exactly integer (e.g., 20 20 → 20.0),
n = 1000 (fill test) · `postmortem.md` (10 marks).
