# case_studies/ — INSTRUCTOR-ONLY

**Restricted content** per
[../ACCESS_CONTROL.md](../ACCESS_CONTROL.md). Do **not** publish or mirror
this directory to students.

This is the companion to [../../case-studies/](../../case-studies/README.md)
(the projector bank). The projector files deliberately contain **no
solutions**; everything that reveals an answer lives here.

## Files

| File | Content | Covers |
|---|---|---|
| `solutions_tier1.md` | Full instructor companion for CS-001–020 | Tier 1 |
| `solutions_tier2.md` | Full instructor companion for CS-021–040 | Tier 2 |
| `solutions_tier3.md` | Full instructor companion for CS-041–060 | Tier 3 |
| `solutions_tier4.md` | Full instructor companion for CS-061–080 | Tier 4 |
| `solutions_tier5.md` | Full instructor companion for CS-081–108 | Tier 5 |

## Session playbook (15 minutes per case)

1. **Project** the case (from `case-studies/by_tier/`). Do not open this
   directory on the projector.
2. **Think (5 min):** students answer the thinking questions on paper.
   Walk the room; note who proposes what — you will need names for the
   discussion.
3. **Discuss (5–7 min):** collect 2–3 approaches before judging any.
   Route with the *discussion points*, not corrections. If the room is
   stuck, reveal **hint 1 only**, then hint 2 on request. Hint 3 is the
   last resort before the reveal.
4. **Reveal (2–3 min):** show the solution outline first, then the code.
   Compare against the *common incorrect approaches* — students learn most
   from seeing their own idea diagnosed.
5. **Assign:** the extension challenge is public; optionally convert it
   into a homework entry citing the case ID.

## Pacing guidance

- 2 cases per lecture hour is comfortable; 1 case + 1 exercise is better
  when the case is Tier 4–5.
- Tier matches the *week's* lecture in the course schedule; earlier-tier
  cases work as revision warm-ups.
- If fewer than half the class answers thinking question 1 correctly,
  skip the reveal — reteach the concept and reuse the case next week.

## Grading rubric (if cases are assessed)

| Dimension | Weight | Excellent looks like |
|---|---|---|
| Problem decomposition | 30% | Inputs/outputs/steps identified before any code |
| Edge-case awareness | 30% | Names boundary inputs unprompted (0, 1, max, empty) |
| Concept accuracy | 25% | Correct construct choice and complexity intuition |
| Communication | 15% | Explains *why*, uses course terminology |

## Compilation status

Worked solutions were compiled with the course contract
(`g++ -std=c++17 -Wall -Wextra -pedantic`) and executed against the case's
test cases; the audit trail with results is
[../../docs/CASE_STUDY_AUDIT.md](../../docs/CASE_STUDY_AUDIT.md).
Representative — not exhaustive — solutions are compiled per tier; each
solution file states which cases were machine-verified.
