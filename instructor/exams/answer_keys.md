# Consolidated Answer Keys — Exam Forms
**INSTRUCTOR-ONLY.** Keys reference bank items in `midterm_bank.md` / `final_bank.md`
(verified outputs there). Form-specific items not in the banks are keyed inline here.

## Midterm Form A
*Form files A–D are restricted papers; this key file and the bank files carry
their own banners. The banner line below covers every form.*

**ALL FORMS A–D INSTRUCTOR-ONLY.**

| Q | Answers |
|---|---|
| Q1 | 1-D, 2-C, 3-B, 4-B, 5-B, 6-A |
| Q2 | 1-`4` 2-`14` 3-`5` 4-`24` |
| Q3 | 1-integer division → `/2.0` 2-missing re-read 3-pass-by-value → `double&` or return |
| Q4 | 1-syntax: missing `;` / logic: wrong accumulation init 2-brace init rejects narrowing 3-input/process/output |
| Q5 | 1-rows 30/31/120/121/300/301/cap; cap = min(120, 50+10·⌈(t−300)/60⌉) 2-`readPrice`, `subtotal`, `taxOf`, `printLine` with contracts |
| Q6 | 1-bank F1 (36.6 → `36.6C = 97.9F`) 2-bank F3 3-bank F4 (`6 28 496 8128`) |
| Q7 | 1-(a)`3` (b)`+= 3` 2-(a)`<` (b)`hi` (c)`return v` |

## Midterm Form B
| Q | Answers |
|---|---|
| Q1 | 1-C, 2-B, 3-C, 4-C, 5-B, 6-B |
| Q2 | 1-`3 1` 2-`16` 3-`16` 4-`805` |
| Q3 | 1-shadowed accumulator 2-missing `break` 3-no base case |
| Q4 | 1-float drift vs integer cents 2-per-iteration table; exposes off-by-one/init defects 3-testability/reuse |
| Q5 | 1-bank E1 algorithm 2-`sos(n)= n<=0?0:n*n+sos(n-1)`, shrink n−1 |
| Q6 | 1-bank F2 2-bank F3 3-bank F4 |
| Q7 | 1-(a)`<` (b)`n-1-i` 2-(a)`0` (b)`a` (c)`true` (out = a / b) |

## Midterm Form C
| Q | Answers |
|---|---|
| Q1 | 1-B, 2-A, 3-B, 4-B, 5-B, 6-A |
| Q2 | 1-`3 1` 2-`4 5` 3-`1991` 4-`10` |
| Q3 | 1-missing decision row (req == cur) 2-boundary/limit test at 301 3-`>=` includes 0 → use `>` per spec |
| Q4 | 1-library reuse, tested code 2-identity `(a/b)*b + a%b == a` guaranteed; sign of negatives not portable (truncation → −1 for −7%2) 3-self-similar + base case (digitSum) |
| Q5 | 1-bank E2 2-bank E3 |
| Q6 | 1-bank F1 2-bank F2 3-bank F4 |
| Q7 | 1-(a)`!=` (b)`cin >> v` 2-(a)`2.0` |

## Midterm Form D
| Q | Answers |
|---|---|
| Q1 | 1-B, 2-A, 3-B, 4-C, 5-B, 6-B |
| Q2 | 1-`11` 2-`5` 3-`24` 4-`16` |
| Q3 | 1-integer division → `/2.0` 2-add `if (n <= 1) return 1;` style base 3-do-while tests after body |
| Q4 | 1-narrowing rejection 2-input/process/output with two running trackers 3-precondition, postcondition |
| Q5 | 1-bank E1 2-base `n == 0 → rev`, shrink `n /= 10`, accumulator rides the parameter chain |
| Q6 | 1-bank F3 2-bank F2 3-bank F4 |
| Q7 | 1-(a)`-= 3` 2-(a)`lo` (b)`hi` (c)`v` |

## Final Form A
| Q | Answers |
|---|---|
| Q1 | 1-C, 2-B, 3-C, 4-B, 5-C, 6-B, 7-B, 8-B |
| Q2 | 1-`7` 2-`5 ell` 3-`1 2 9 5` 4-`3` 5-`7` |
| Q3 | 1-OOB read (UB), `<=` → `<` 2-newline residue → consume rest of line 3-use-after-delete; null-at-birth + null-after-delete 4-balance ≥ 0 (or overdraft policy); validation in the public mutator |
| Q4 | 1-all-negative correctness 2-sorted precondition → O(log n) guarantee 3-must-exist, never-null, no reseat 4-0 success / 1 usage / 2 data-environment |
| Q5 | 1-≈1000 2-≈10 3-linear ~n, binary ~log n → ~20 vs ~10⁶ |
| Q6 | 1-bank F1 predicate 2-bank F3 3-bank F4 |
| Q7 | 1-bank G1 2-bank G2 3-bank G3 4-bank G4 |
| Q8 | 1-(a)`<` (b)`--j` 2-(a)`delete` (b)`nullptr` 3-(a)`||` (b)`-=` |
| Q9 | Option 1: pick G-pool items + bank keys. Option 2: reset() sets count_ = 0; test table must include reject-at-0 and reject-overdraft-free cases as applicable |

## Final Form B
| Q | Answers |
|---|---|
| Q1 | 1-C, 2-A, 3-B, 4-B, 5-B, 6-B, 7-B, 8-B |
| Q2 | 1-`17` 2-`15` 3-`2` 4-`9` 5-`2` |
| Q3 | 1-index 3 skipped → `i < 4` 2-corners twice; predicate `r==0||r==R-1||c==0||c==C-1` 3-fail-forever on absent keys; `high = n-1 && low <= high` 4-leak; owner-frees-every-path or vector |
| Q4 | 1-COLS must appear 2-boundary chars non-letter 3-RAII auto-free 4-owns Cars, public interface only |
| Q5 | 1-sorted → 1 compare/element 2-one 3-pays when n large (log vs n) |
| Q6 | 1-bank F2 2-birth: nullptr; release: delete[] then p = nullptr; use: check p != nullptr 3-bank F4 |
| Q7 | 1-bank G1 2-bank G2 3-bank G3 4-bank G4 |
| Q8 | 1-(a)`[r]` (b)`r` 2-`data = nullptr;` + check-before-use 3-(a)`||` (b)`-=` |
| Q9 | Option 1: bank keys. Option 2: mean/max accumulate during load; report only loaded; tests: all-bad file (no mean), missing-score line skipped |

## Final Form C
| Q | Answers |
|---|---|
| Q1 | 1-B, 2-B, 3-B, 4-B, 5-B, 6-C, 7-B, 8-B |
| Q2 | 1-`5 4 3 2 1` 2-`3 7` 3-`2 1` (index 2; npos → true) 4-`3` 5-`7` |
| Q3 | 1-init from a[0] 2-newline residue; consume-then-getline 3-null-at-birth + null-after-delete 4-batch data: count-and-continue; getline+istringstream |
| Q4 | 1-`<` visits all; `<=` reads one past (UB) 2-minimum lands at index 0; rest untouched 3-ownership tied to scope → automatic release 4-0/1/2 |
| Q5 | 1-≈10 2-≈1000 3-log vs n widening |
| Q6 | 1-only j > i to avoid double-swap 2-struct pairs name+score; misalignment dies 3-bank F4 |
| Q7 | 1-bank G1 2-bank G2 3-bank G3 4-bank G4 |
| Q8 | 1-(a)`<` (b)`--j` 2-canonical three lines (see bank H3 note) 3-(a)`||` (b)`-=` |
| Q9 | Option 1: bank keys. Option 2: track peak_ = max(peak_, count_) in inc(); allBelow scans peaks history or tracks bool flag; tests: exact-cap boundary true, cap+1 false |

## Final Form D
| Q | Answers |
|---|---|
| Q1 | 1-B, 2-B, 3-B, 4-C, 5-B, 6-B, 7-B, 8-B |
| Q2 | 1-`17` 2-`15` 3-`2` 4-`9` 5-`3` |
| Q3 | 1-corners twice; predicate fix 2-fail-forever; `high = n-1 && low <= high` 3-leak; owner-frees or vector 4-in the public mutator (only door) |
| Q4 | 1-all-negative correctness 2-must-exist/no-reseat 3-half-updated swaps; struct pairs make it atomic 4-property held after every public method; balance ≥ 0 |
| Q5 | 1-insertion — one compare per element on nearly-sorted 2-≈20 3-sortedness |
| Q6 | 1-bank F1 predicate 2-bank F2 3-bank F3 |
| Q7 | 1-bank G1 2-bank G2 3-bank G3 4-bank G4 |
| Q8 | 1-(a)`[r]` (b)`r` 2-`data = nullptr;` + check-before-use 3-(a)`||` (b)`-=` |
| Q9 | Option 1: bank keys. Option 2: frequency[26]; ties → first alphabetically (scan a→z for max); tests: tie case, all-same, non-letter ignored |

---
*Key verification: outputs quoted in bank items were executed (see ASSESSMENT_AUDIT §5).*
