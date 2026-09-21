# Lab 9 TA Notes — INSTRUCTOR-ONLY

**Restricted** per
[../../../instructor/ACCESS_CONTROL.md](../../../../instructor/ACCESS_CONTROL.md).
Do not publish or mirror this file to students.

## Entry check (first 5 min)

- Toolchain spot-verification: one student runs the § 3 verify command.
- Pre-lab answers checked (rubric item 1); initial the notebook.

## Session pacing (120 min)

| Segment | Time | What |
|---|---|---|
| Demo | 0:00–0:15 | Array loops, bounds, statistics patterns |
| Guided tasks + checkpoints | 0:15–1:00 | sign off § 7 guided items |
| Independent work | 1:00–1:45 | record completion only |
| Debug task | 1:45–2:00 | Off-by-one hunt: two supplied array bugs (read past end; skip last) |

## Guidance rules

- NEVER type the answer for a student. Ask: "what did the compiler say,
  and which line?"
- Route students to the manual's theory section before re-explaining.
- A missed checkpoint is homework, not a zero: one week to demo it at
  office hours.

## Common sticking points

- Wrong build flags (missing `-std=c++17` or `-Wall`).
- Running the executable from the wrong directory (file-not-found).
- Lab 9 specific: watch for the § 9 bug being "fixed" without diagnosis —
  the rubric pays for the *log*, not the fix.

## After the lab

- Collect submissions from the LMS; apply the § 13 rubric.
- Feed recurring errors back to the instructor for the next lecture's
  warm-up.
