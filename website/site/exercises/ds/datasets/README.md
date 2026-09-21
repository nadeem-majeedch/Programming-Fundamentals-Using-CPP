# DS Exercise Datasets — plain text, tiny, self-checking

All datasets are student-visible and may be freely copied. Every dataset that
contains defects documents them here, together with the *expected values* a
correct program must produce — so students can self-check and graders compare.

Generated inputs are also welcome; when a task says "use the dataset", use
these files so outputs are comparable.

## Files

### temperatures.txt — 18 clean readings
No defects. For DS-04.
- mean = **20.8** (exact sum 374.4 / 18 = 20.7999…, prints 20.8 at 1 dp)
- values **strictly above** the true mean: **6** (the six ≥ 21.8)

### survey_ratings.txt — 40 non-blank lines
For DS-06. Defects on purpose:
- **35** valid ratings 1..5
- **3** out-of-range (`0`, `9`, `-2`)
- **2** non-numeric (`five`, `missing?`)
- counts: 1→3, 2→4, 3→6, 4→14, 5→8; relative for 4 = 14/35 = **0.40**

### readings_na.txt — 15 non-blank lines (+ 1 blank line to ignore)
For DS-09. Line classes:
- **11** loaded (all parse and lie in −50..60)
- **2** missing (`NA` on N-02 and N-03)
- **2** invalid (`twenty` non-numeric; `N-06` has no value field)
- class identity holds: 11 + 2 + 2 = 15
- mean of loaded = **21.0455… → 21.0 at 1 dp** (231.5 / 11)

### scores.csv — 11 lines
For DS-13. Defects on purpose:
- header `name,score` — per the task's stated rule, it classifies as
  **bad-score** (it is data-shaped, that is the lesson)
- `Farah 90` — no comma → **no-comma** (1)
- `Gus,101` (range) and `Ivan,abc` (non-numeric) → **bad-score** (2 more)
- **7 loaded**: 88, 72, 95, 61, 79, 90, 100
- mean = **83.57** (585/7); max **100** owned by **Jade** (unique owner)

### students.txt — 12 lines
For DS-14. Defects:
- `Eli 300 2.0` — age out of 16..90 → rejected
- `Gus 22 4.1` — gpa out of 0..4 → rejected
- `Ivy 21 three` — non-numeric gpa → rejected
- **9 valid rows**; overall mean age **20.89**, mean gpa **3.37**
- Ana appears **3×** (3.4, 3.9, 3.6) → Ana mean **3.63**; Joy and Cy are
  single-row groups; first-appearance order: Ana, Ben, Cy, Dee, Fay, Gus, Hal, Joy

### messy_grades.txt — 20 non-blank lines
For DS-15. Defect classes (your program must state its classification rule
for the 3 no-name lines; suggested rule: no name ⇒ corrupt):
- **13** valid (min 41, max 100)
- **2** missing (`Ben NA`, `Ned NA`)
- **2** corrupt values (`Dan abc`, `Qu 101` out of range)
- **3** no-name lines (`72`, `79`, the lone `NA`)
- expected: mean **74.92**, median **79.00**, usable **65.0 %** (13/20)

### stations/ — three station files + index.txt
For DS-18. Format `day temperature`; temperature plausible range −50..60.

| File | loaded | missing | invalid | mean |
|---|---|---|---|---|
| station_north.txt | 9 | 1 | 0 | 21.06 (21.0556) |
| station_south.txt | 7 | 1 | 2 (`twenty`, `700` out of range) | 26.07 |
| station_coast.txt | 8 | 1 | 1 (`foggy`) | 18.75 |

- hottest single reading: **27.5** at station_south day 7
- coldest single reading: **17.5** at station_coast day 4
- mean ranking (hottest first): south 26.07, north 21.06, coast 18.75
- no ties in this data; the tie rule (alphabetical) exists for robustness —
  test it by adding a temporary file with an equal mean.
