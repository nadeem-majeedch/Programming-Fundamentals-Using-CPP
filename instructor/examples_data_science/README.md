# DS Examples — Instructor Notes · INSTRUCTOR-ONLY

Restricted per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).
Companion to [../examples/data-science/](../../examples/data-science/README.md)
(the programs themselves are student-visible; these notes are not).

## Verification status (GCC 16.2, `g++ -std=c++17 -Wall -Wextra -pedantic`)

All nine programs compile **zero-warning** and were **executed**; outputs below
are machine-verified. Re-verify after any edit:

```bash
cd examples/data-science
for f in ds_*.cpp; do g++ -std=c++17 -Wall -Wextra -pedantic "$f" -o /tmp/dstest; done
```

## Per-program teaching targets & verified outputs

### ds_types_precision.cpp
Demonstrates: counts vs measures; 0.1 drift (prints
`0.1 added ten times: 0.99999999999999989` with setprecision(17)); the
single-cast mean; the int-truncation trap (`404/5 → 80`, loses .8);
tolerance comparison `|x − 1| < 1e-9` prints the tolerance line, not the
naive `==` verdict.
**Debate to run:** why is `total` `long long` here? (n × 100-scale marks; the
exactness argument, not the size argument, matters at this scale.)

### ds_mean_median.cpp
Input `7 88 92 79 85 91 72 95` →
`count: 7 · mean: 86.0 · sorted: 72 79 85 88 91 92 95 · median: 88.0`.
Even case `4 10 20 30 40` → `median: 25.0` (average of middles). `0` →
`no data`, exit 0. Median math: odd → a[n/2]; even → (a[n/2−1]+a[n/2])/2.0.
**Point out:** mean loop and median need different preconditions (n ≥ 1 vs
sorted) — the contract comments carry this.

### ds_min_max_range.cpp
`4 17 9 22 -999` → count 4, min 4, max 22, range 18, mean 13.0.
Sentinel-first → `no data`. Init-from-first-value rule demonstrated against
the all-negative trap (ask the class to break a 0-initialized tracker).

### ds_frequency_counts.cpp
`10 1 3 3 5 2 3 4 5 3 2` → table 1:1(0.10) 2:2(0.20) 3:4(0.40) 4:1(0.10)
5:2(0.20), `mode : 3`. Tie case `6 3 3 9 3 1 1` → mode 3 with the
`(bimodal/multimodal: 2 categories tie)` line and the invalid excluded
(relative uses valid count only — check row sums: 0.40 + 0.60 = 1.00).
**Point out:** index shift `counts[r − MIN_RATING]` on write AND read.

### ds_validate_dataset.cpp
`8 21 19 missing 24 999 abc 20 22` → valid 5, missing 1, out-of-rng 1,
corrupt 1, mean 21.2. All-invalid (`3 missing x NA`) → valid 0 +
`no usable data — statistics skipped`, exit 0. Token `abc` caught by the
istringstream parse + leftover-char check (`abc` fails extraction; `12x`
fails on leftover).
**Point out:** three policies named in comments; the repair rule is *sketched,
not executed* so the skip policy stays honest.

### ds_sort_observations.cpp
`8 72 91 85 85 68 79 95 88` → sorted `68 72 79 85 85 88 91 95`,
min 68, median 85.0, max 95, `swaps: 6`, top-3 `95 91 88`.
Single `1 42` → all statistics 42, swaps 0 (and the formatting branch that
keeps the sorted line's newline correct).
**Point out:** swap count is *cost* reporting — the data-science habit of
publishing what the computation cost.

### ds_stats_pipeline.cpp
With the sample file (mixed classes incl. a blank line and a name-only line):
`loaded 4 · missing 1 · invalid 3 · mean 20.8 · median 20.8`, exit 0.
Missing file → `cannot open …`, exit 2 (uses `is_open()` — the reliable open
check on all course platforms). Usage error → exit 1.
**Point out:** three-tier exit codes live here exactly as in L29–L30.

### ds_simulation.cpp
Seed 42. n=60: face-1 proportion 0.2333, mean 3.2167 (noise dominates).
n=10000: proportions 0.1616–0.1725, mean 3.4959. Same seed → identical output:
reproducibility is a feature. Expected column is 1/6 = 0.1667 and mean 3.5.
**Point out:** `<random>` (mt19937 + uniform_int_distribution) is the
standard-blessed toolkit; `rand()%6` is neither reproducible across libraries
nor uniform-safe.

### ds_tabular_records.cpp
`4 Ana 20 3.4 Ben 22 2.8 Ana 21 3.9 Cy 20 3.1` → rows 4, rejected 0,
mean age 20.75, mean gpa 3.30; groups: Ana 3.65 (2 rows), Ben 2.80 (1), Cy
3.10 (1). Validation case `3 S1 19 3.0 S2 300 3.5 S3 21 9.9` → rows 1,
rejected 2.
**Point out:** integer age-sum vs double gpa-sum — the two column *types*
demand different accumulators; grouping is two passes, no maps (maps are a
data-structures-course promise).

## Common student questions

1. *"Why not just use Python?"* — the point is owning the arithmetic (and the
   overflow, and the drift) before a library hides it.
2. *"Is the sample mean exact?"* — the sum of doubles is not; 1-dp display is
   the contract, tolerance comparison is the test.
3. *"When do I need long long?"* — when the *total* (not the mean) could
   exceed ~2.1 × 10⁹, or the count of iterations itself is large.

## If you extend the set

Follow the header contract: `// purpose:` (formula-first), `// build:`,
`// input:`. One teaching point per file, edge cases executed not described,
and re-run the zero-warning build before committing.
