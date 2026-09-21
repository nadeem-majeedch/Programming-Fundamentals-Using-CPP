# exercises/data-science/ — BS Data Science Exercise Bank

**18 exercises** (IDs `PF-DS-01` … `PF-DS-18`) that reframe course
fundamentals as data work — the same loops, arrays, structs, and files as the
main bank (`../by_topic/`), but aimed at the questions data-science students
will meet again in statistics and data-processing courses.

**No overlap by design:** the main bank teaches mechanics once (mean in
PF-E-067, one histogram in PF-E-075, one CSV study in PF-CS-056); DS items go
further — medians with even/odd rules, modes with ties, weighted means,
missing-data policies, grouped aggregates, reproducible simulation.

## Rules that apply to every exercise

1. Standard C++ only: arrays, `struct`, `std::vector`, `std::string`, streams.
   No statistics libraries, no `std::sort`/STL algorithms unless the item says
   otherwise, no machine-learning anything.
2. **Formula before code:** write the mathematical definition as a comment
   before the function that implements it.
3. **Integer vs floating-point, consciously:** counts stay `int`; measurements
   are `double`; the `static_cast<double>` appears exactly where division does.
4. **Edge cases are graded:** empty input, all-invalid input, single element,
   and ties must be handled (or reported as `n/a`), not ignored.
5. Programs read stdin unless the item specifies a file; broken reads exit
   with the course's codes (0 ok · 1 usage · 2 data/environment).

## Difficulty ladder & index

| ID | Title | Level | Lectures | Dataset |
|---|---|---|---|---|
| DS-01 | Count and Proportion | Beginner | L05–L06 | — (stdin) |
| DS-02 | Min, Max, Range (sentinel) | Beginner | L09–L10 | — |
| DS-03 | Mean of Whole Marks | Beginner | L09 | — |
| DS-04 | Count Above the Mean | Foundational | L17 | [temperatures.txt](datasets/temperatures.txt) |
| DS-05 | Median, Both Parities | Foundational | L17 | — |
| DS-06 | Frequency Table with Invalids | Foundational | L18 | [survey_ratings.txt](datasets/survey_ratings.txt) |
| DS-07 | Range-Check Filter | Foundational | L07/L09 | — |
| DS-08 | Variance and Std Dev | Intermediate | L17 | — |
| DS-09 | Missing-Data Report | Intermediate | L29 | [readings_na.txt](datasets/readings_na.txt) |
| DS-10 | Weighted Mean | Intermediate | L13–L17 | — |
| DS-11 | Sort and Rank | Intermediate | L24 | — |
| DS-12 | Mode with Honest Ties | Intermediate | L18 | — |
| DS-13 | Two-Column File Statistics | Intermediate | L29–L30 | [scores.csv](datasets/scores.csv) |
| DS-14 | Group Means by Key | Advanced | L28–L30 | [students.txt](datasets/students.txt) |
| DS-15 | Data Quality Audit | Advanced | L29–L30 | [messy_grades.txt](datasets/messy_grades.txt) |
| DS-16 | Moving Average | Advanced | L17–L18 | — |
| DS-17 | Reproducible Simulation | Advanced | L10/L18 | — |
| DS-18 | Mini Capstone: Station Report | Advanced Introductory | L24–L30 | [stations/](datasets/stations/) |

Paired worked solutions: instructor-only at
[../../instructor/exercises_data_science/](../../instructor/exercises_data_science/README.md)
(verified compiled + executed; not to be distributed).

Datasets: [datasets/](datasets/README.md) — plain-text, tiny, with a documented
defect in every file that claims one. Students may also generate their own
inputs; the listed files make grading comparable.
