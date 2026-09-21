# Quiz Usage Notes — Instructor

**Restricted** per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).

## Scheduling

Quiz *n* runs in week *n*'s second lecture (after both module lectures).
15 minutes, 10 marks, closed book. The schedule appears in the course plan;
drop-lowest per `quizzes/README.md`.

## Per-quiz watchpoints

| Quiz | Common wrong answers | Remediation pointer |
|---|---|---|
| 01 | linker vs preprocessor; "compiles = correct" | L01 notes §errors |
| 02 | silent truncation expectation from brace init | L03 narrowing demo |
| 03 | left-to-right precedence reading; "sign always positive" | L06 `%` identity |
| 04 | ladder ordering; fall-through | L07/L08 demos |
| 05 | "add a break" instead of missing update | L10 sentinel demo |
| 06 | answers without trace tables | require tables when graded |
| 07 | one-sided passing-mode fix | Lab 08 demo |
| 08 | pass-by-value confusion re-surfaces | reference quiz item with Lab 08 |
| 09 | best = 4 misread; sentinel 0 initializers | L17 max-tracker |
| 10 | diagonal relations swapped; column-major answers | L19 grid demo |
| 11 | npos arithmetic; −1/false expectations | L21 find demo |
| 12 | accepting wrong pass-0 row; "stable = fast" | L23/L24 sort traces |
| 13 | bytes vs elements; single guard | L25/L26 guards drill |
| 14 | shallow-copy answer 9 | L27 record copy demo |
| 15 | counting bad lines; reversed exit codes | L29 robust-read demo |
| 16 | re-deriving the class; validation placement | L31 private-state demo |

## Scaling

Scores are recorded raw out of 10; the drop-lowest policy already accounts for
quiz difficulty drift — do not rescale individual quizzes.

## Item reuse

Quiz items may reappear on the final only as remediation variants (reworded,
same skill). Log any reworded reuse in the key sheet for moderation.
