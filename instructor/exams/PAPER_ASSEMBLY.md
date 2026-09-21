# Paper Assembly Guide — Midterm & Final
**INSTRUCTOR-ONLY** per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).

## 1. Midterm blueprint (100 minutes · 50 marks)

Weighting mirrors the course plan: 40 % conceptual, 60 % applied.

| Q | Pool section | Items | Marks | Notes |
|---|---|---|---|---|
| 1 | A (MCQ) | 6 of 8 | 6 | one per module M1–M5, one extra |
| 2 | B (Trace) | 4 of 10 | 8 | include one recursion trace (B8) |
| 3 | C (Debug) | 3 of 8 | 6 | one per skill band M2/M5/M7 |
| 4 | D (Short) | 3 of 6 | 6 | include one IPO/trace-table item |
| 5 | E (Design) | 2 of 4 | 6 | one decision-table + one decomposition |
| 6 | F (Coding) | 3 of 4 | 12 | include one function-based (F4) |
| 7 | G (Complete) | 2 of 2 | 6 | both completion items |
| | | **23 items** | **50** | |

Form variance rules (A–D): swap items within the same tag; keep section marks
identical across forms; never reuse an item that appeared on a quiz in the same
term unless it is the remediation variant (mark `remediation: true` when so).

## 2. Final blueprint (180 minutes · 100 marks)

Modules 9–16 carry ≥ 60 % of the paper.

| Q | Pool section | Items | Marks | Notes |
|---|---|---|---|---|
| 1 | A (MCQ) | 8 of 8 | 8 | one per module M9–M16 |
| 2 | B (Trace) | 5 of 10 | 10 | ≥ 3 from M13–M16 |
| 3 | C (Debug) | 4 of 8 | 8 | one per skill band M9–M16 |
| 4 | D (Short) | 4 of 6 | 8 | ≥ 2 from M13–M16 |
| 5 | E (Complexity) | 3 of 4 | 6 | include measured-counter item E4 |
| 6 | F (Design) | 3 of 4 | 9 | include the CSV loader (F4) |
| 7 | G (Coding) | 4 of 4 | 24 | array + string + sort + class |
| 8 | H (Complete) | 3 of 4 | 9 | include the class invariant item H4 |
| 9 | Section review | — | 18 | 3 more G-pool items, or a scaled practical variant |
| | | **34+ items** | **100** | |

Total marks check: 8+10+8+8+6+9+24+9+18 = **100** ✓

## 3. Printing and security checklist

- [ ] Strip `**Answer:**` lines and grading notes from the student copy (grep for `Answer:` must return zero lines).
- [ ] Page-count and marks-total check on the assembled paper before printing.
- [ ] Forms A–D differ in ≥ 30 % of items but identical section marks.
- [ ] Bluebook/answer-sheet mapping matches item numbering.
- [ ] Calculator/compiler policy line matches the practical assessment policy.

## 4. Answer-key integrity protocol

1. Every assembled paper ships with its key generated from the same pool subset.
2. Trace items: key output must match a compiled execution (see ASSESSMENT_AUDIT §5).
3. Two-person check: setter and moderator sign the key sheet (name/date lines included
   in the bank header when printed).
4. Post-exam: log any accepted alternative answers on the key sheet for grading consistency.
