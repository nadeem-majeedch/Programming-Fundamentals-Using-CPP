# case-studies/data-science.md — DS Track Projector Cases (PF-DS-CS-1…8)

Eight supplementary case studies for BS Data Science sections, in the same
5-minute think → discuss → reveal format as the main bank
([by_tier/](by_tier/)). Numbering uses the `PF-DS-CS` prefix so the main
bank's `PF-CS-001…108` stays contiguous. Worked discussion guides live in the
instructor area only
([../instructor/case_studies/ds_solutions.md](../instructor/case_studies/ds_solutions.md)).

---

### PF-DS-CS-1 · The Billion-Row Mean
- **Tier:** 2 Foundational · **Lecture:** L17 · Module 9
- **Context:** A teammate computed a dataset's mean, then the data grew 100×.
- **Problem:** The sum was stored in `int`. At what dataset size (roughly, values ~1000) does the sum overflow a 32-bit int? What type changes fix it, and which statistic becomes impossible to compute in one pass regardless of types?
- **Input/Output:** no code required — a numeric estimate + a one-paragraph policy.
- **Constraints:** only types taught in Modules 2–8.
- **Thinking questions:** what is int's range? what is the honest failure mode — crash, wrap, or silent wrong answer? what would you print if asked "how big is too big?"
- **Expected concepts:** integer limits, `long long`, silent overflow, streaming vs stored data.
- **Hints:** int tops out near 2.1 × 10⁹ · think total, not mean · what happens to the *mean* if the *sum* wraps?

---

### PF-DS-CS-2 · One Missing Sensor Beat the Mean
- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** A weather report said "mean temperature 21.0 °C" but one faulty sensor had logged −999 °C for a day.
- **Problem:** Design the validation rule that would have caught it, the two statistics you can still report honestly with the bad value *excluded*, and what you must disclose to the report's readers.
- **Input/Output:** rule in pseudocode; disclosure as a fixed-format footer line.
- **Constraints:** data in a plain array; values plausible in −50..60.
- **Thinking questions:** is −999 more like "missing" or "wrong"? why is the median less embarrassed than the mean here? what number belongs next to "n ="?
- **Expected concepts:** range validation, skip-and-count, robust vs non-robust statistics, honest reporting.
- **Hints:** −999 was chosen as a sentinel by whoever wrote the logger · mean is a sum divided by *what* exactly? · disclosure = counts of what you excluded.

---

### PF-DS-CS-3 · The Two-Median Trick
- **Tier:** 3 Intermediate · **Lecture:** L17 · Module 9
- **Context:** A dataset of 7 values grew by 2 new values; someone claims the median is "the average of the two new values."
- **Problem:** Construct a 7-value dataset and 2 added values where that claim is true, then one where it is badly false. State the correct even-n median rule in your own words.
- **Input/Output:** two concrete datasets + the rule.
- **Constraints:** 9 values total; small enough to sort by hand.
- **Thinking questions:** what must the two new values do to land at the middle? what does the median actually measure — new data, or middle position?
- **Expected concepts:** median as an order statistic, sorting before medians, why n matters.
- **Hints:** make the old 7 all tiny · the middle of 9 sorted values is the 5th · "average of two values" needs *which* two?

---

### PF-DS-CS-4 · The Frequency Table That Lied
- **Tier:** 3 Intermediate · **Lecture:** L18 · Module 9
- **Context:** Ratings run 1..5. A student's table printed six rows — ratings 0..5 — and row 0 said "12 responses."
- **Problem:** Diagnose the indexing defect (which slot did rating 5 really go to?), state the two standard fixes (shift vs spare slot), and their trade-off for readability.
- **Input/Output:** defect diagnosis + corrected table sketch.
- **Constraints:** `int counts[6]` is the array; no vectors.
- **Thinking questions:** where did rating 5's vote land? why didn't the program crash? what would happen with rating 6?
- **Expected concepts:** off-by-one/index shifting, silent corruption vs out-of-bounds, defensive range checks before indexing.
- **Hints:** C++ indices start at 0 · `counts[r]` with r = 5 is the *sixth* slot · validate first, index second.

---

### PF-DS-CS-5 · Skip, Repair, or Abort?
- **Tier:** 4 Advanced · **Lectures:** L29–L30 · Module 15
- **Context:** A grading pipeline reads 5,000 rows; 30 have a missing score, 3 have scores above 100, 1 row is a duplicated header.
- **Problem:** For each of the three defect classes, choose skip / repair / abort and defend it in one sentence each. Then state the one summary line your pipeline must always print so consumers can judge the data.
- **Input/Output:** a 3-row decision table + the footer line format.
- **Constraints:** beginner C++ (streams + arrays); no libraries.
- **Thinking questions:** which defects are *per-row* and which poison the whole file? what does a repair need before it is honest? why is exit code 0 correct even when rows were skipped?
- **Expected concepts:** validation policies, skip-and-report, the audit footer, exit-code discipline.
- **Hints:** missing ≠ invalid ≠ structural · repaired values must be counted separately · the footer carries the denominators.

---

### PF-DS-CS-6 · Percentile by Hand
- **Tier:** 4 Advanced · **Lecture:** L24 · Module 12
- **Context:** A 12-value sorted dataset; a report asks for "the 75th percentile."
- **Problem:** Two textbook definitions exist (nearest-rank vs interpolation). Compute BOTH by hand for a dataset of your choosing, explain why they differ, and argue which to ship when the consumer is a school registrar.
- **Input/Output:** your 12 values + both percentile results + one-sentence justification.
- **Constraints:** sorted array arithmetic only; no code required.
- **Thinking questions:** which definition never invents a value that was not in the data? when does the difference vanish?
- **Expected concepts:** order statistics, definition-dependence of derived numbers, documentation as part of the answer.
- **Hints:** nearest-rank picks a real data point · interpolation may create a .5 that never existed · consistency across reports beats cleverness.

---

### PF-DS-CS-7 · The Simulation That Looked Rigged
- **Tier:** 4 Advanced · **Lecture:** L18 · Module 9
- **Context:** A student seeded their die simulator with the current time; their classmate's "unusual" results (four 6s in ten rolls) were dismissed as a bug.
- **Problem:** Is 4 sixes in 10 rolls suspicious for a fair die? Design the counting experiment that answers this over many 10-roll batches, and state what role the seed plays in reproducibility.
- **Input/Output:** experiment design + expected proportion of "4+ sixes" batches, roughly.
- **Constraints:** `<random>` with a fixed seed only; counting loops.
- **Thinking questions:** what is the expected *count* of 6s in 10 rolls? what counts as "unusual" — who decides, and from what? why does a fixed seed make the debate finishable?
- **Expected concepts:** empirical vs expected frequency, simulation as measurement, reproducibility via seeds.
- **Hints:** expected sixes per 10 rolls is 10/6 ≈ 1.7 · variance makes small batches wobbly · run 10,000 batches and count.

---

### PF-DS-CS-8 · The Report That Could Not Be Rebuilt
- **Tier:** 5 Expert introductory · **Lecture:** L30 · Module 15
- **Context:** Two students produced different means from the same file. One skipped blank lines and quoted lines as data; the other counted blanks as missing.
- **Problem:** Specify the line-classification contract (exact classes, exact counters, exact footer) that would make both students print identical reports, and identify which number in the report exposes a classification difference fastest.
- **Input/Output:** a written contract (6–8 lines) + the "fastest tell" number.
- **Constraints:** getline-based parsing; the footer from PF-DS-CS-5.
- **Thinking questions:** why did both means look plausible? which counter catches classification drift — loaded, missing, or invalid? what does the class-identity equation enforce?
- **Expected concepts:** classification contracts, counters as invariants (loaded + missing + invalid = non-blank lines), reproducible pipelines.
- **Hints:** both forgot the footer · the identity equation fails loudly when classes drift · contracts are documentation that tests can check.
