# DS Exercises · Part 3 — Files, Groups, Simulation, Capstone (DS-13…DS-18)

The advanced-introductory band: everything runs over real (small) text
datasets, ends in a mini capstone, and stays inside course-taught C++.

---

### PF-DS-13 · Two-Column File Statistics (CSV)
**Level:** Intermediate · **Lectures:** L29–L30 · **Prerequisites:** DS-09
**Problem:** File `scores.csv` holds `name,score` lines (no spaces in names;
score 0..100). Print `loaded`, then the mean (2 dp), the max with its owner
(first owner wins ties), and the count of skipped lines with reasons split
into `no-comma` and `bad-score`.
**Formula first:** mean over loaded only; skip classification is a decision
tree: (no comma) → `no-comma`; (comma but non-numeric / out of range) →
`bad-score`.
**Edge cases:** empty file; file with header line `name,score` — treat it as
a data line and let it classify as `bad-score` (document the choice; a
header-aware version is an extension).
**Dataset:** [datasets/scores.csv](datasets/scores.csv)
(11 lines incl. the `name,score` header: 7 loaded, 1 no-comma, 3 bad-score —
the header counts as bad-score per the stated rule; mean of the 7 valid
88, 72, 95, 61, 79, 90, 100 is 83.57; max 100 owned by Jade).
**Hints:** find(',') on each line; substr both fields; istringstream the score.

---

### PF-DS-14 · Group Means by Key (file)
**Level:** Advanced · **Lectures:** L28–L30 · **Prerequisites:** DS-13
**Problem:** File `students.txt` holds `name age gpa` lines. Print mean age
and mean GPA overall, then for each distinct name (first-appearance order):
`<name>: <gpa-mean> (<k> rows)` 2 dp.
**Formula first:** `mean(c,k) = Σ gpa where name = k / rows(k)` — a two-pass
group-by without maps: pass 1 discovers keys (first appearance), pass 2
accumulates each group (the ds_tabular_records.cpp pattern).
**Edge cases:** a single-row group; all rows one group; out-of-range rows
(age 16..90, gpa 0..4) rejected and counted before grouping.
**Dataset:** [datasets/students.txt](datasets/students.txt)
(12 lines: 9 valid, 1 bad age, 1 bad gpa, 1 non-numeric gpa; Ana appears 3×
with gpa mean 3.63; overall mean age 20.89, mean gpa 3.37).
**Hints:** `struct Student { string name; int age; double gpa; };` +
`std::vector<Student>`; a parallel `bool grouped[]` marks joined rows.

---

### PF-DS-15 · Data Quality Audit (file)
**Level:** Advanced · **Lecture:** L30 · **Prerequisites:** DS-09, DS-13
**Problem:** File `messy_grades.txt` holds lines that are one of:
`name score` (valid), `name NA` (missing), `name <junk>` (corrupt),
or garbage with no name. Produce an audit: counts per class, then for valid
rows: min, max, mean, median (2 dp), and the percentage of the file that was
usable, `usable: <p>%` (1 dp).
**Formula first:** `usable% = 100 · loaded / total_lines` (blank lines
excluded from both); median by the sorted rule from DS-05.
**Edge cases:** zero valid rows (statistics n/a, audit still prints, exit 0);
a line that is only whitespace; duplicate names (fine — grades may repeat).
**Dataset:** [datasets/messy_grades.txt](datasets/messy_grades.txt)
(20 lines: 13 valid, 2 missing, 2 corrupt values, 3 no-name lines (bare scores
or lone `NA` — classify them as corrupt with a reason, your table must state
the rule); mean 74.92, median 79.00, usable 65.0 %, min 41, max 100).
**Hints:** build on DS-09's classifier, then add statistics; keep classes
separate in the report — merging them destroys the audit's value.

---

### PF-DS-16 · Moving Average
**Level:** Advanced · **Lectures:** L17–L18 · **Prerequisites:** DS-08
**Problem:** Read n, window w (1 ≤ w ≤ n), then n doubles. Print the w-day
moving averages, one per line, 2 dp — there are exactly `n − w + 1` of them.
**Formula first:** `MA(i) = (x(i) + x(i+1) + … + x(i+w−1)) / w` for
i = 1 .. n−w+1 (1-based). Naive version: re-sum each window (O(n·w)) —
fine at this scale; say so in a comment.
**Edge cases:** w = n (exactly one average = the overall mean); w = 1 (the
data echoed back, formatted).
**Sample:** `5 3  2 4 6 8 10` → `4.00` / `6.00` / `8.00`
**Hints:** one outer loop over window starts, one inner loop over the window;
a *running sum* version (add the entering value, drop the leaving one) is
the extension — implement naive first, then compare outputs.

---

### PF-DS-17 · Reproducible Simulation
**Level:** Advanced · **Lectures:** L10/L18 · **Prerequisites:** DS-06
**Problem:** Simulate n rolls of a fair six-sided die with a FIXED seed (42),
`std::mt19937`, and `uniform_int_distribution<int> die{1,6}`. Print per-face
counts and empirical proportions (4 dp) plus the mean of faces shown, then
the same table for n trials of TWO dice summed, `sum2` 2..12 (13 buckets,
index shift).
**Formula first:** expected p = 1/6 per face; for two dice, expected counts
follow the triangle 1,2,3,4,5,6,5,4,3,2,1 over sums 2..12 — print your
empirical proportions beside `k/36` computed from the triangle.
**Edge cases:** n = 0 (no trials, proportions printed as 0.0000 with a note);
large n (long long counts).
**Sample behavior:** with n = 60000, every face proportion lands within
±0.01 of 0.1667 and the two-dice peak sits at sum 7 — verify and state both
in the test table. Same seed → identical output every run: reproducibility
is the point; say why in a comment.
**Hints:** exactly the ds_simulation.cpp pattern extended; no other randomness
sources allowed (no `rand()`).

---

### PF-DS-18 · Mini Capstone: Station Report
**Level:** Advanced Introductory · **Lectures:** L24–L30 · **Prerequisites:** DS-14, DS-15
**Problem:** Files `stations/station_*.txt` (see datasets/stations/) each hold
`day temperature` lines. Build one report across ALL station files (argument:
directory-free version — filenames listed in `stations/index.txt`, one per
line): per station (loaded/missing/invalid + mean), then across all stations:
the hottest single reading with station and day, the coldest likewise, and
each station's mean as a ranked list (hottest mean first; stable ties by name).
**Formula first:** means per group (DS-14); ranking = sort an array of
`struct StationMean { string name; double mean; }` with your own sort
(descending by mean; equal means keep alphabetical name order — a stated,
implemented tie rule).
**Edge cases:** a station file entirely NA (mean n/a — still ranked? No:
excluded from the ranking, listed in an `excluded:` line); an index entry
whose file cannot open → warning line, exit code still 0 if at least one
station loaded, else 2.
**Dataset:** [datasets/stations/](datasets/stations/) — three stations,
~10 days each, seeded defects; expected headline values are in the datasets
README for self-checking.
**Hints:** this composes DS-09 + DS-11 + DS-14; keep each piece a function
with a contract comment — the report is the product, the functions are the
pipeline.
