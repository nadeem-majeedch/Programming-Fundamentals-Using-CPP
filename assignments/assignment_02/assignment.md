# Assignment 2 · Tuition Estimator — Decisions & Validation
**Modules 3–4 (L05–L08) · 40 marks · due end of Week 5**
Outcomes: CLO-2, CLO-3 (PF-3.x, PF-4.x)

The bursary quotes a tuition estimate from credit hours and residence status.
Your program reproduces their published table — exactly.

## Fee table (authoritative)

| Residency | Base | Per credit hour | Cap rule |
|---|---|---|---|
| `in` | 1200 | 150 | total capped at 4500 |
| `out` | 2500 | 320 | total capped at 8000 |

`total = min(base + credits·rate, cap)`. Scholarships: input `scholarship`
amount (0 or more) is subtracted *after* the cap; the result never goes below 0.

## Requirements

1. Read: residency word (`in`/`out`), credits (int), scholarship (double).
2. Validate: residency must be exactly `in` or `out` (else `bad residency`,
   exit 1); credits 1–24 (else `bad credits`, exit 1); scholarship ≥ 0
   (else `bad scholarship`, exit 1). Check in that order, one message per run.
3. Print `estimate: <total>` with 2 decimals.

## Sample runs

| Input | Output |
|---|---|
| `in 12 0` | `estimate: 3000.00` |
| `out 20 500` | `estimate: 7500.00` (2500 + 20·320 = 8900 → cap 8000 → −500) |
| `in 30 0` | `bad credits` |
| `xx 10 0` | `bad residency` |

## Constraints

- One `switch` or if/else ladder for residency — choose one and justify in a comment.
- No loops yet; a single pass of decisions.
- Money math in `double` is accepted here (exactness discussion is A1's postmortem topic).

## Deliverables

`tuition.cpp` (course contract, zero warnings) · `test_table.md` covering both
residencies, cap hit, scholarship floor at 0, every validation message, boundary
credits 1/24/25 · `postmortem.md` (10 marks).

## Notes

- The cap applies before scholarship; the floor applies last.
- Credits are whole hours; do not accept 12.5.
