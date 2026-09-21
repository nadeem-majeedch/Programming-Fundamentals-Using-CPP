# Rubric — Correctness (0–40 per assignment; scaled per artifact)

| Points | Criterion |
|---|---|
| 0–10 | **Sample fidelity** — the paper's sample I/O reproduced exactly (formatting included) |
| 0–10 | **Hidden cases A (typical)** — 2–3 standard workloads beyond the sample |
| 0–10 | **Hidden cases B (boundaries & invalid)** — zero/one-element inputs, range edges, malformed data handled per spec (skip/reject, not crash) |
| 0–10 | **Robust behavior** — EOF-safe reads; no undefined behavior under stress inputs; deterministic output |

## Grade gates

- **Does not compile with the course contract → 0** regardless of intent.
- **Any hidden case crashes → that line scores 0**, other lines unaffected.
- **Silent wrong answer on invalid input** (accepts what spec says to reject) =
  half credit on B at most.

## Reading the spec strictly

Answers that *add* unrequested output lose nothing; answers that *omit* required
output lose the sample line. Where spec wording allows either `skip` or
`abort`, accept either if the choice is stated in a comment — ambiguity is the
student's to resolve visibly.
