# DS Exercises · Part 1 — Descriptive Statistics from Scratch (DS-01…DS-06)

Formulas go in comments *before* the code that implements them; integer vs
floating-point choices are graded. Edge cases listed per item are part of the
task, not decoration.

---

### PF-DS-01 · Count and Proportion
**Level:** Beginner · **Lectures:** L05–L06 · **Prerequisites:** none
**Problem:** Read integers until EOF. Print `n: <count>`, then `even: <p>`
where `<p>` is the proportion of even values, 2 decimals.
**Formula first:** `p = (number of even values) / n` — division is the only
floating step; cast exactly once.
**Input:** any integers. **Output:** two lines as above; `n: 0` and `even: 0.00`
on empty input.
**Edge cases:** empty input; all odd; negative values (−4 is even!).
**Sample:** `1 2 2 7 8` → `n: 5` / `even: 0.60`
**Hints:** `v % 2 == 0` works for negatives on all course compilers; the count
is an `int`, the cast happens at the division.
**Avoid duplicating:** PF-E-067 (sum/mean) — this one is a proportion, no mean.

---

### PF-DS-02 · Min, Max, Range (sentinel)
**Level:** Beginner · **Lectures:** L09–L10 · **Prerequisites:** DS-01
**Problem:** Read integers until sentinel `-999`. Print `min`, `max`, `range`
(max − min) on separate lines. Sentinel never enters the data.
**Formula first:** `range = max − min`; trackers initialize from the FIRST data
value, never 0.
**Edge cases:** sentinel first → `no data`; single value → range 0; all-equal.
**Sample:** `4 17 9 22 -999` → `min: 4` / `max: 22` / `range: 18`
**Hints:** one pass; no arrays needed.

---

### PF-DS-03 · Mean of Whole Marks
**Level:** Beginner · **Lecture:** L09 · **Prerequisites:** DS-01
**Problem:** Read n, then n integer marks 0..100. Print `sum` and `mean` (2 dp).
Reject the whole run if any mark is outside 0..100: print `bad mark` and exit 1.
**Formula first:** `mean = (x1 + … + xn) / n` with the sum in `long long`.
**Edge cases:** n = 0 → `no data` (exit 0); n = 100 marks (capacity check with
a fixed array of 1000).
**Sample:** `5 82 91 75 68 88` → `sum: 404` / `mean: 80.80`
**Hints:** this is the *strict* sibling of PF-E-067: here validation rejects,
there input was trusted.

---

### PF-DS-04 · Count Above the Mean (file)
**Level:** Foundational · **Lectures:** L17 · **Prerequisites:** DS-03
**Problem:** Read doubles from file `temperatures.txt` (one per line) until
EOF. Compute the mean, then print `mean` (1 dp) and `above: <k>` — how many
values are STRICTLY greater than the mean.
**Formula first:** two passes: `mean = Σx/n`, then count `xi > mean`.
Discuss (in a comment): why one pass cannot count-above-the-mean.
**Edge cases:** empty file → `no data` (exit 0); file absent → exit 2 with a
message; a single value counts 0 above itself.
**Dataset:** [datasets/temperatures.txt](datasets/temperatures.txt)
(18 readings, mean 20.8 — six values above it).
**Sample check with the dataset:** `mean: 20.8` / `above: 6`
**Hints:** array capacity 1000; the count is int, values are double.

---

### PF-DS-05 · Median, Both Parities
**Level:** Foundational · **Lecture:** L17 · **Prerequisites:** DS-02
**Problem:** Read n then n integers. Print the median (1 dp): middle value for
odd n, average of the two middles for even n.
**Formula first:** sort ascending; odd n → `x((n+1)/2)`; even n →
`(x(n/2) + x(n/2+1)) / 2` (1-based). Implement your own insertion or selection
sort from L24 — do not re-derive a new sort here.
**Edge cases:** n = 0 → `no data`; n = 1; duplicates around the median.
**Sample:** `7 88 92 79 85 91 72 95` → `median: 88.0`; even case `4 10 20 30 40`
→ `median: 25.0`
**Hints:** the even case can produce .5 — that is why the return is double
while the data stays int.

---

### PF-DS-06 · Frequency Table with Invalids (file)
**Level:** Foundational · **Lecture:** L18 · **Prerequisites:** DS-05
**Problem:** Read integers from file `survey_ratings.txt` (one per line),
values expected 1..5. Print a table `rating count relative` for ratings 1..5
(relative = count/valid, 2 dp), then `invalid: <k>`. Out-of-range and
non-numeric lines both count as invalid but are reported separately
(`invalid-range`, `invalid-token` totals after the table).
**Formula first:** `f(c) = |{x : x = c}|`, `rel(c) = f(c)/n_valid`; index shift
`counts[r − 1]`.
**Edge cases:** all-invalid file (table of zeros, relative 0.00, no division
by zero!); missing file → exit 2.
**Dataset:** [datasets/survey_ratings.txt](datasets/survey_ratings.txt)
(40 lines: 35 valid, 3 out-of-range, 2 non-numeric).
**Sample check:** rating 4 → count 14, relative 0.40; `mode: 4` is NOT required
here (that is DS-12's job).
**Hints:** getline + istringstream per line (L29 pattern); guard the division
by the valid count.
