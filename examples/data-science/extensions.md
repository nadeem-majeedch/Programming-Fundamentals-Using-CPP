# Suggested Extensions — Data-Science Track

Optional enrichment after the DS examples and exercises. Each extension stays
inside course-taught C++ or names exactly which *future course* supplies the
missing tool — that boundary is the lesson.

## From the examples

1. **Streaming statistics (ds_min_max_range.cpp).** Extend the one-pass
   trackers to also carry count and sum (they already do), then derive the
   mean — and discuss why the *median* refuses to stream. Future tool promised
   in data structures: order-statistics structures.
2. **Cost reporting (ds_sort_observations.cpp).** Add comparison and swap
   counters for insertion sort alongside selection sort on the same data;
   reproduce the O(n) vs O(n²) gap from L24 on sorted vs reverse inputs.
3. **Rolling window (ds_simulation.cpp).** Track the running proportion of
   face 6 every 100 trials and print it 20 times — a picture of convergence
   without a plotting library.
4. **Repair policy (ds_validate_dataset.cpp).** Implement the sketched
   repair-with-mean rule *with its own `repaired` counter*, and compare the
   mean of skip-policy vs repair-policy output on the same file — the two
   numbers differ; that difference is why policies are disclosed.
5. **Column types (ds_tabular_records.cpp).** Add a `passed` boolean column
   and print pass-rate per group — proportions from a struct column, zero new
   syntax.

## From the exercise bank

6. **DS-04 → one pass?** Prove experimentally that counting-above-the-mean
   needs two passes (store or re-read), then measure memory of both.
7. **DS-08 → sample variance.** Change the divisor to `n − 1` (Bessel), state
   when each is correct, and verify n = 2, {0, 10}: population 25.00, sample
   50.00.
8. **DS-11 → dense ranking.** Competition ranks `1 2 2 4` vs dense `1 2 2 3`;
   implement both from the same sorted array.
9. **DS-13 → header-aware CSV.** Detect and skip the header *by content*
   (`name,score`) instead of classifying it bad-score; state the rule in the
   contract comment.
10. **DS-16 → running-sum windows.** Replace the O(n·w) re-sum with
    add-entering/drop-leaving (O(n)) and verify identical outputs to 2 dp on
    1000 values — your first performance refactor with a correctness check.
11. **DS-18 → unit-style self-test.** Add a `--selftest` flag that runs the
    three station files and asserts the expected means before printing the
    report; the dataset README's numbers become the test oracle.

## Bridge to future courses (named, not taught)

- **Data structures:** replace `counts[100]` (DS-12) with a key→count map;
  replace the two-pass group-by (DS-14) with a hash map; a priority queue
  gives top-K without full sorting (DS-11).
- **Algorithms:** prove the two-pass mean is 2n reads and the running-sum
  window is n + w; compare quicksort vs your L24 sorts at n = 100,000.
- **Statistics:** sample vs population variance (extension 7), correlation of
  two columns from `students.txt`, and why `NA` needs its own class before any
  estimator runs.
- **Databases:** the DS-14 group-by *is* `SELECT name, AVG(gpa) GROUP BY name`;
  the DS-15 audit is a data-quality gate; the footer is a query result's
  row-count line.

## Not in scope (boundary statement)

Plotting, CSV/JSON libraries, pandas-style frames, floating-point control
(rounding modes), parallelism, randomness beyond `<random>`, and any machine
learning. The track ends where a **data structures** course begins — with
students who can already load, validate, summarize, and honestly report a
dataset in plain C++.
