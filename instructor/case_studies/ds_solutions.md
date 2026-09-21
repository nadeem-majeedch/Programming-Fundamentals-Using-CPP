# DS Case Studies — Instructor Discussion Guide · INSTRUCTOR-ONLY

Restricted per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).
Companion to [../../case-studies/data-science.md](../../case-studies/data-science.md)
(projector file — questions only). Pacing and grading notes follow the same
15-minute playbook as [README.md](README.md).

---

## PF-DS-CS-1 · The Billion-Row Mean

**Solution outline.** int: max ≈ 2,147,483,647 (2³¹−1). Sum of values ~1000
overflows near **~2.1 million rows** (2.1e9 / 1e3). Fix: accumulate in
`long long` (or double for *measures* — with the drift caveat from L03).
The statistic that stays impossible in one pass regardless of types: **the
median** (needs the data ordered/stored); a mean streams fine.

**Discussion points.**
- The dangerous part is *silence*: wrapping does not crash; it prints a wrong
  mean with confidence.
- Ask: "who in this room has seen a negative sum from positive data?" — that
  is what wraparound looks like.
- Policy sentence students should produce: "choose the accumulator by the
  dataset size you were *promised*, times two."

**Common wrong approaches.** "Use double for everything" (loses exactness for
counts; drift for big sums — link ds_types_precision.cpp); "the compiler warns"
(-Wextra does not know your dataset size).

**Test cases (mental).** n = 2,000,000 × 1000 → int sum wraps negative; long
long = 2,000,000,000, exact; mean 1000.00 both ways — the *sum line* is the tell.

**Extension.** Add a rolling-mean (running average) so no total is stored at
all; discuss when that is acceptable (it is — mean is streamable).

---

## PF-DS-CS-2 · One Missing Sensor Beat the Mean

**Solution outline.** Validation rule: `if (v < −50 || v > 60) → class: invalid
range` (never average it). With the bad value excluded, report honestly:
mean of valid values **and** the median of valid values, plus the footer
`n valid = k, excluded = 1 (range)`. Disclosure: every statistic carries its
denominator.

**Discussion points.**
- Median "less embarrassed": one wild value moves the median by at most one
  position, the mean by value/n — robustness is a *position* property.
- −999 is a sentinel someone chose at logging time: missing-data policy starts
  at the sensor, not at the report.
- The mean of a dataset *containing* −999 is not "wrong-ish", it is a number
  nobody can use.

**Common wrong approaches.** "Just delete bad rows silently" (undisclosed);
"clamp −999 to −50" (repair without a stated rule is fabrication);
"report both means" (no — one definition, disclosed exclusions).

**Test cases.** dataset {20, 21, −999}: mean-with = −319.3; mean-valid = 20.5;
median both ways = 20/20.5 — students verify the honest pair.

**Extension.** Repair rule "replace with the median of the 5 nearest days",
counted in a `repaired` class.

---

## PF-DS-CS-3 · The Two-Median Trick

**Solution outline.** True case: old 7 = {1,1,1,1,1,1,1}; add {9, 9} → sorted
middle is… position 5 of 9 = 1 — *not* the claim. Students discover the claim
is essentially never true: adding 2 values shifts the middle by one position.
A "true" construction: {1,1,1,2,2,2,2} + {2,2} → sorted {1,1,1,2,2,2,2,2,2},
5th = 2 = average of the two new values (2,2). Badly false: old 7 = {1..7},
add {8,9} → median 5, not 8.5.
**Correct rule:** for n = 9 sorted, median = x(5); even n = x(n/2), x(n/2+1)
averaged.

**Discussion points.**
- The median measures *middle position*, not "the latest additions".
- Why the even rule averages: no single middle element exists.
- Vocabulary audit: many students say "middle of the list" without "sorted".

**Common wrong approaches.** Forgetting to sort before taking x(5); averaging
first/last; claiming median = mean for symmetric data (fine here, wrong habit).

**Test cases.** The two constructions above, hand-sorted in a table.

**Extension.** What happens to median and mean if one extreme value doubles?
(Mean moves; median may not.)

---

## PF-DS-CS-4 · The Frequency Table That Lied

**Solution outline.** With `int counts[6]` and code `++counts[r]`: rating 5
landed in slot 5, which the printout labeled "5" — correct — but rating 0
(impossible data or an initialization artifact) filled slot 0. The real defect
is usually `++counts[r]` without a range check plus a loop printing 0..5:
row 0 shows whatever wrote slot 0. Fixes: (a) shift on write/read:
`++counts[r − 1]`, print r = slot + 1; (b) spare slot 0: indices 1..5, accept
one wasted int. Trade-off: (a) uses all memory and forces the author to state
the mapping; (b) reads like the data but silently depends on discipline.

**Discussion points.**
- Why no crash: slot 0 is *inside* the array — silent corruption class.
- What rating 6 would do (out of bounds — undefined behavior; the earlier
  lecture's warning returns).
- Defense: validate first, index second.

**Common wrong approaches.** Printing slots as 0..5 with data 1..5 (the
displayed lie); "fixing" by array size 7 without a rule.

**Test cases.** Ratings {1, 5, 5}: shifted table shows 1:1, 5:2; unshifted
buggy print shows a phantom row.

**Extension.** Make the table width a constant and the labels derived from it.

---

## PF-DS-CS-5 · Skip, Repair, or Abort?

**Solution outline.**

| Defect | Policy | One-sentence defense |
|---|---|---|
| Missing score (30) | **skip + count** (or documented repair) | known-unknown per row; the run's other 4,970 rows are still honest data |
| Score > 100 (3) | **skip + count as invalid** | out-of-range is a *quality* defect, not absence; repairing it would invent grades |
| Duplicated header (1) | **detect + skip + count structurally** | it poisons nothing if recognized; aborting 5,000 good rows for one line is disproportionate |

Mandatory footer: `loaded L · missing M · invalid I · structural S · total T`
with the identity `L + M + I + S = T`. Exit 0 when at least one row loaded
(a data job's product is the report); exit 2 only if the file cannot open.

**Discussion points.** Repair needs a *stated rule* and its own counter;
"abort" is for files, not rows; who reads the footer? (the next engineer —
write it for them).

**Common wrong approaches.** Abort on first defect (destroys the batch);
merge missing+invalid into one counter (destroys the audit); repair silently.

**Test cases.** The identity equation on the 5,000-row scenario; footer
format checked against a hand-built example.

**Extension.** Percentage columns and a threshold that flips exit to 3
("usable fraction below policy") — policy as code.

---

## PF-DS-CS-6 · Percentile by Hand

**Solution outline.** Example sorted 12 values: 40 45 50 52 55 58 60 62 65 70
75 90.
- Nearest-rank p75: rank = ⌈0.75 × 12⌉ = 9 → **65** (a real data point).
- Linear interpolation (the common textbook form): position = 0.75 × (12 − 1)
  + 1 = 9.25 → x(9) + 0.25 × (x(10) − x(9)) = 65 + 0.25 × 5 = **66.25**
  (invented value).
They differ because one picks a data point, the other interpolates between
neighbors. For a registrar: **nearest-rank** — never invent a score that no
student earned; consistency across reports beats sophistication.

**Discussion points.** The percentile is a *definition*, not a fact; document
which one shipped; difference vanishes when data is dense or p lands on an
integer position.

**Common wrong approaches.** Treating 66.25 as "more accurate" (more precise,
less real); mixing definitions across reports.

**Test cases.** Both formulas at p = 50 (they coincide at the median only for
even n interpolation vs nearest-rank — students verify when).

**Extension.** Quartiles Q1/Q3 both ways; compare with the median rule.

---

## PF-DS-CS-7 · The Simulation That Looked Rigged

**Solution outline.** Expected sixes in 10 rolls: 10/6 ≈ 1.67. 4 sixes is
high but far from impossible — the counting experiment: run 10,000
independent 10-roll batches (fixed seed per batch for reproducibility), count
batches with ≥ 4 sixes, report the proportion (≈ 0.20 by the binomial law —
roughly one batch in five!). Verdict: not suspicious. Seed's role: a fixed
seed makes a run *reproducible* — the debate can end by re-running; time
seeds make every debug session unreproducible.

**Discussion points.** Empirical vs expected: single batches wobble, large
counts converge; "unusual" needs a threshold agreed *before* looking;
`rand()` is banned in the course for exactly this discussion (quality of
randomness + no reproducibility contract).

**Common wrong approaches.** Judging from one batch; re-running until the
result "looks right" (that is p-hacking at week 10); using `% 6` on rand().

**Test cases.** With seed 42 and 10,000 batches: proportion ≥ 4 sixes lands
near 0.2 (±0.02); students record their exact value for reproducibility.

**Extension.** Two-dice triangle (DS-17) — expected counts 1..6..1 over
sums 2..12; peak at 7.

---

## PF-DS-CS-8 · The Report That Could Not Be Rebuilt

**Solution outline.** Contract (students produce something equivalent):
1. read lines; blank/whitespace-only lines are ignored (no counter);
2. class A `loaded`: exactly two fields, field 2 parses as a number in range;
3. class B `missing`: exactly two fields, field 2 == "NA";
4. class C `invalid`: two fields but bad/out-of-range value;
5. class D `structural`: field count ≠ 2 (including headers);
6. print footer `loaded L missing M invalid I structural S lines T` with
   **L + M + I + S = T** enforced before printing;
7. statistics quote L as their denominator.
Fastest tell: the **total-lines counter T** (or the identity failing) —
it exposes classification drift even when means agree. Both students "looked
plausible" because a mean hides its denominator; the footer publishes it.

**Discussion points.** A contract is documentation a program can violate
loudly; the identity is an *invariant* in the Module 16 sense; reproducibility
is a property of the pipeline, not of the person.

**Common wrong approaches.** "Use the same code" (not a contract — an
implementation); counters that skip blank lines *and* count them (both halves
of the disagreement preserved).

**Test cases.** A 6-line file where two classifications genuinely differ by
rule choice; students show the identity catching the drift.

**Extension.** Turn the contract into a function `classify(line) -> Class`
with a contract comment; report = fold over classes.
