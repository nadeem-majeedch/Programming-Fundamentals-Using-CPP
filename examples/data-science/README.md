# examples/data-science/ — Data-Oriented Demo Programs (BS Data Science Track)

Standalone, heavily commented programs that reframe the course's fundamentals
around **data work**: loading observations, computing descriptive statistics,
counting frequencies, validating messy input, and simulating simple random
processes. Every program compiles with the course contract:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic <file>.cpp -o <prog>
./<prog>            # most read stdin; ds_stats_pipeline reads a data file
```

**Scope discipline:** standard C++ only — arrays, `struct`, `std::vector`,
`std::string`, streams. No libraries beyond the standard, no statistics
libraries, no machine learning. These programs exist so that later courses
(data structures, algorithms, statistics) meet students who already type
`long long` sums without being told.

## The set (8 programs, in teaching order)

| File | Data-science skill | Course link |
|---|---|---|
| [ds_types_precision.cpp](ds_types_precision.cpp) | integer vs floating-point data; exact counts vs approximate measurements | M2/M3 · L03–L06 |
| [ds_mean_median.cpp](ds_mean_median.cpp) | mean and median from scratch, formula-first, sorted-input rule | M9 · L17 |
| [ds_min_max_range.cpp](ds_min_max_range.cpp) | min/max/range with sentinel input and the empty-input case | M9 · L17 |
| [ds_frequency_counts.cpp](ds_frequency_counts.cpp) | frequency tables, index shifting, mode by counting | M9 · L18 |
| [ds_validate_dataset.cpp](ds_validate_dataset.cpp) | missing/invalid value handling: skip vs repair vs abort | M4/M5 · L07–L11 |
| [ds_sort_observations.cpp](ds_sort_observations.cpp) | sorting observations (selection sort on a data array), rank = position | M12 · L24 |
| [ds_stats_pipeline.cpp](ds_stats_pipeline.cpp) | a complete text-file pipeline: load → validate → summarize | M15 · L29–L30 |
| [ds_simulation.cpp](ds_simulation.cpp) | basic simulation: dice trials, counting outcomes, empirical vs expected | M5/M9 · L10, L18 |

## Pedagogical notes

- **Formula before code.** Each program's header comment states the mathematical
  definition it implements (mean, median, empirical probability) *before* the
  implementation, and the code follows the formula line by line.
- **Integer vs floating-point, deliberately.** Counts and frequencies stay in
  `int`; measurements use `double`; sums of measurements use `long long` or
  `double` with a stated reason. The cast to `double` happens exactly where the
  division happens.
- **Edge cases are content, not afterthoughts.** Empty input, all-invalid
  input, single-element data, and tied medians/modes are exercised in the
  programs themselves.
- **No duplication of the main bank.** The general bank teaches the *mechanics*
  (sum/mean once in PF-E-067, one histogram in PF-E-075, one CSV study in
  PF-CS-056); these programs go further — medians, modes, percentile-style
  ranks, simulation, and a full pipeline — and are framed as data work.

Worked solutions for the paired exercise bank live in the instructor area only
([../../instructor/examples_data_science/](../../instructor/examples_data_science/README.md)).
