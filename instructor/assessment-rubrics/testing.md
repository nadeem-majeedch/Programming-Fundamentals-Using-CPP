# Rubric — Testing (0–10 per artifact)

Students submit a test table with their code: each row = input, expected output,
observed output, verdict. Graders score the *discipline*, not the count.

| Points | Criterion |
|---|---|
| 0–3 | **Coverage of classes** — at least: typical, boundary (0/1/n−1/n), invalid, and (where relevant) empty/EOF |
| 0–3 | **Expected values are pre-computed and correct** — not copied from the program's own output |
| 0–2 | **Honesty** — observed ≠ expected rows kept and explained, not deleted |
| 0–2 | **Traceability** — each row names the defect found or the class it guards (maps to the debug-log habit from labs) |

## Score anchors

- Table with 3 identical-shaped happy-path rows: coverage ≤ 1.
- Boundary row for an off-by-one that *caught a real defect* before submission: honesty + traceability 4/4.
- A student who deletes failing rows (observed == expected everywhere, but grader
  reproduces a failure): honesty 0, artifact referred per academic-integrity line
  of the syllabus.

## Relationship to other components

- Practical task 3's separate 5-mark test-table line uses this rubric at 0–5
  (coverage + honesty only).
- The project uses the same table format per module, aggregated in `project.md`.
