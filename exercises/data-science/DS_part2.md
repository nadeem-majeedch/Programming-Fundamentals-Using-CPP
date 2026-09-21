# DS Exercises · Part 2 — Messy Data and Derived Statistics (DS-07…DS-12)

The intermediate band: data with defects, statistics derived from other
statistics, and honest tie handling.

---

### PF-DS-07 · Range-Check Filter
**Level:** Foundational · **Lectures:** L07/L09 · **Prerequisites:** DS-02
**Problem:** Read n, then n integers (sensor values). Print the *kept* values
on one line (those in −50..60 inclusive), then `dropped: <k>`.
**Formula first:** predicate `keep(v) ⇔ −50 ≤ v ≤ 60`; kept values compact
left-to-right into the same array (no second array).
**Edge cases:** nothing kept (print an empty line, then `dropped: n`); all kept
(`dropped: 0`); n = 0.
**Sample:** `6 21 999 -7 60 61 0` → kept line `21 -7 60 0` / `dropped: 2`
**Hints:** this is the *filter-compact* half of PF-E-072's remove — here the
rule is physical plausibility, not an exact value.

---

### PF-DS-08 · Variance and Standard Deviation
**Level:** Intermediate · **Lecture:** L17 · **Prerequisites:** DS-05
**Problem:** Read n then n doubles. Print `mean` (2 dp), `variance` (2 dp,
population form), `stddev` (2 dp).
**Formula first:**
`var = Σ(xi − mean)² / n`, `std = √var`.
Use the two-pass form (compute mean first, then the squared deviations).
State in a comment why the one-pass "sum of squares" shortcut
(`Σx²/n − mean²`) is numerically riskier for large values.
**Edge cases:** n = 1 → variance 0.00, stddev 0.00 (define it, print it, do
not crash); constant data.
**Sample:** `6 2 4 4 4 9 4` → mean 4.50, variance **4.58**, stddev **2.14**
(population form; verify the mean by hand first: 27/6 = 4.5).
**Hints:** `<cmath>` `sqrt` is allowed (taught with `isPrime`'s √n bound);
sums of squares of doubles stay double; no integer casts here.

---

### PF-DS-09 · Missing-Data Report (file, NA field)
**Level:** Intermediate · **Lecture:** L29 · **Prerequisites:** DS-06
**Problem:** File `readings_na.txt` holds lines `station value`, where value
may be a number or the token `NA`. Print `loaded`, `missing`, `invalid`
(non-numeric or wrong field count), then mean of loaded values (1 dp).
NA is a *recorded gap* (its own class) — never mean it, never call it invalid.
**Formula first:** mean over loaded only; class counts must sum to line count
(`loaded + missing + invalid = lines`) — assert it in a comment and check by
hand in the test table.
**Edge cases:** empty file (`all zeros, mean n/a`, exit 0); missing file →
exit 2; blank lines ignored (not counted in any class).
**Dataset:** [datasets/readings_na.txt](datasets/readings_na.txt)
(15 non-blank lines: 11 loaded, 2 missing, 2 invalid; mean 21.05 — and the
class identity `11 + 2 + 2 = 15` holds, which your test table must confirm).
**Hints:** getline + istringstream; `token == "NA"` before numeric parse.

---

### PF-DS-10 · Weighted Mean
**Level:** Intermediate · **Lectures:** L13–L17 · **Prerequisites:** DS-03
**Problem:** Read n, then n pairs `score weight` (weights ≥ 0, at least one
positive). Print the weighted mean (2 dp).
**Formula first:** `weighted mean = Σ(xi·wi) / Σwi` — NOT `Σxi/n`.
The denominator is the *weight total*, not the count; getting this wrong is
the whole point of the exercise.
**Edge cases:** all weights zero → `no weights` (exit 0, no division!); a
weight of exactly 0 (legal: the score is ignored by the math — verify it is).
**Sample:** `3 90 2 80 1 70 1` → `82.50` (not 82.75, and not the unweighted
80!); with a zero weight `3 90 0 80 1 70 1` → `82.50` still (the zero-weight
pair contributes to neither numerator nor denominator).
**Hints:** accumulate `sumXW` and `sumW` in one loop; both double (scores may
be non-integer later).

---

### PF-DS-11 · Sort and Rank
**Level:** Intermediate · **Lecture:** L24 · **Prerequisites:** DS-05
**Problem:** Read n then n scores. After sorting ascending, print `rank of
<value>` queries? No — print, for the ORIGINAL order, each score's rank band
(1-based position in the sorted list, smallest rank on ties).
**Formula first:** `rank(x) = 1 + |{y : y < x}|` (competition ranking:
`2 2 4` → ranks `1 1 3`).
**Edge cases:** all equal (every rank 1); single element (rank 1).
**Input:** n, n values, then queries? Keep it programmatic: after sorting,
print two lines: sorted values and their rank bands, space-separated.
**Sample:** input `5 70 85 85 60 90` →
sorted `60 70 85 85 90` / ranks `1 2 3 3 5`
**Hints:** ranks come from *positions*; a value's rank can be found while
sorting or by counting smaller elements — either, stated in a comment.
**Avoid duplicating:** PF-CS-059 (stable ranking with ties) was a design
study; this is a concrete implementation with a precise rank formula.

---

### PF-DS-12 · Mode with Honest Ties
**Level:** Intermediate · **Lecture:** L18 · **Prerequisites:** DS-06
**Problem:** Read n then n integers in 1..100. Print `mode: <v>` and, if
several values share the maximum frequency, print ALL of them ascending on a
second line `tied: ...` (omit the line if unique). Also print `freq: <k>`.
**Formula first:** `mode = argmax_c f(c)`; ties are reported, not hidden —
an honest report lists every maximizer.
**Edge cases:** every value distinct (max frequency 1 — a weak claim; print
it anyway with `tied:` listing all n values? No: if all frequencies are 1,
print `mode: none` — say why in a comment); n = 0.
**Sample:** `9 4 6 4 7 6 4 7 7 9` → counts 4:3, 6:2, 7:3, 9:1 →
`mode: 4` / `tied: 4 7` / `freq: 3`
**Hints:** counts array of 100 slots with index shift; two scans: find max
frequency, then list maximizers ascending.
