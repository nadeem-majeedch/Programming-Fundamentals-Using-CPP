# Rubric — Explanation (0–10 per artifact)

Applied to assignment postmortems, the project report's reflection section, and
synthesis exam options that ask for justification.

| Points | Criterion |
|---|---|
| 0–2 | **Design narration** — why the chosen decomposition/data types; one rejected alternative named |
| 0–2 | **Defect narrative** — at least one real bug: symptom → hypothesis → test → fix (the lab debug-log shape) |
| 0–2 | **Correct vocabulary** — terms used per the course glossary (invariant, narrowing, sentinel, RAII…) without decoration |
| 0–2 | **Test justification** — why those test classes; what each guards against |
| 0–2 | **Honest limits** — what the program still does not handle; stated plainly |

## Calibration anchors

- "It works" with no narrative: 0–2 overall.
- A precise trace-table-based account of an off-by-one: defect narrative 2/2.
- Using "invariant" for a loop condition: vocabulary ≤ 1.
- Admitting "fails for empty input; not handled" when true: honesty 2/2 — and it
  protects the robustness line in `correctness.md` from double penalty only if
  the behavior matches the claim.

## Use in borderline decisions

When a grade sits between bands, the explanation rubric's evidence decides:
documented defects and honest limits move *up*; silent mismatch moves *down*.
