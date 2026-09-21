# Case-Study Discussion Guides — How to Run the 5-Minute Protocol

**Instructor-only.** Companion to the projector files in
[../../case-studies/](../../case-studies/index.md) (student-facing, no
solutions) and the worked solutions in
[../case_studies/](../case_studies/README.md) (instructor-only).

**This file is the method** (protocol, questioning moves, formative capture).
Per-lecture anchor cases and module-specific discussion angles live in
[../lecture-delivery/](../LESSON_DELIVERY_GUIDE.md) — each lecture plan's
"Case study" row names its anchor case; the 16 module guides detail the
discussion. All case IDs below were verified against the case index.

---

## 1. The 5-minute protocol (run it the same way every time)

| Clock | Phase | What the instructor does |
|---|---|---|
| 0:00–0:30 | **Silent read** | Project the case; read nothing aloud yet; students read twice. |
| 0:30–2:00 | **Individual think** | No talking. Students write their *approach in one sentence* (not code — an approach). |
| 2:00–4:00 | **Pair compare** | Pairs exchange approaches; goal is *one shared approach*, disagreements logged. |
| 4:00–5:00 | **Vote** | Hands up per approach family (e.g. "one loop / two loops / array + pass"). Record the split on the board. |

Then the discussion: **always start from a wrong-but-popular answer**, never
from the correct one. Reveal the worked solution only after the class has
committed to an approach (the vote is the commitment device).

**Formative capture (2 min):** the vote split *is* the data — if >30 % voted
for an approach that ignores the case's key constraint, that constraint (not
the syntax) is what the next 5 minutes must teach. Log per-section in your term
notes; the misconception bank's practice tasks are the re-teach.

## 2. Questioning moves (use in order, resist skipping)

1. **Restate:** "Say the requirement back in your own words — what does *done* mean here?"
2. **Constraint probe:** "Which line of the case breaks your approach?"
3. **State-trace:** "Walk me through your approach with the sample input — where does the state live?"
4. **Counterexample request:** "Give me an input where my proposed fix still fails."
5. **Bridge:** "Which lecture pattern is this? Name it." (Retrieval practice — the pattern vocabulary pays here.)
6. **Commit:** "OK — the class now owns one approach. Show of hands *again* before I reveal."

## 3. Reading the room: three standard adjustments

- **Silent room:** switch from "any approach?" to a forced binary ("does the sentinel value get *processed* — yes or no?"). Binaries restart talk.
- **One voice:** make the loud student write while a quiet student speaks their written approach — swap roles next case.
- **Early solvers:** hand them the case's *extension challenge* (bottom of every projector file) to present in the last 2 minutes — they teach, you probe.

## 4. Anchor-case map (verified against `case-studies/index.md`)

Lecture → anchor case, per the delivery guides' case-study rows:

| Lecture | Anchor | Tier-1/L02 alternates | Tier-2 alternates | Tier-3 alternates |
|---|---|---|---|---|
| L01 | CS-001 The Vending Machine | CS-009 | — | — |
| L02 | — (toolchain lecture; no case slot) | CS-009 | — | — |
| L03 | CS-002 Three-Cup Order | — | — | — |
| L04 | CS-003 The Receipt Printer | — | — | — |
| L05 | CS-014 Class Attendance Percentages | — | — | — |
| L06 | CS-005 The Grading Curve Debate | — | — | — |
| L07 | CS-004 Elevator Logic | CS-006 Parking Fee | — | — |
| L08 | CS-007 Password Strength Meter | — | — | — |
| L09 | CS-016 Sum Until the Sentinel | CS-008, CS-010, CS-011 | — | — |
| L10 | CS-013 The Cashier's Change Maker | CS-012, CS-015, CS-017 | — | — |
| L11 | CS-013 (design-first re-run) | CS-018 Bus Fare Zoner | — | — |
| L12 | CS-020 Exam Averages with an Absence Rule | CS-019 | — | — |
| L13 | CS-021 Leap Year Interrogation | — | CS-022, CS-023 | — |
| L14 | CS-024 The Collatz Witness | — | CS-025, CS-026, CS-036 | — |
| L15 | CS-028 The Swap Handoff | — | CS-027, CS-029, CS-030, CS-035, CS-037, CS-038 | — |
| L16 | CS-031 The Recursive Countdown | — | CS-032, CS-033, CS-034, CS-039, CS-040 | — |
| L17 | CS-041 The Missing Temperature | — | — | CS-042, CS-043, CS-047, CS-048 |
| L18 | CS-047 Frequency Table from Scratch | — | — | CS-044, CS-045, CS-046 |
| L19 | CS-049 Seat Map Query Engine | — | — | CS-050, CS-051, CS-052 |
| L20 | CS-052 Matrix Border Sum | — | — | (grid act; cases optional) |
| L21 | CS-056 CSV Column Statistics | — | — | CS-053, CS-057 |
| L22 | CS-055 Palindrome Judge with Punctuation | — | — | CS-054 |
| L23 | CS-060 Search Benchmark Disclosure | — | — | CS-061, CS-071, CS-072, CS-075, CS-076, CS-077 |
| L24 | CS-058 Insertion Sort on Playing Cards | — | — | CS-059, CS-070 |
| L25 | CS-065 The Dangling Return | — | — | CS-062, CS-073 |
| L26 | CS-064 Out-Parameter vs Return | — | — | CS-063 |
| L27 | CS-066 Leak Hunter | — | — | CS-067 |
| L28 | CS-068 Struct Record Migration | — | — | CS-069, CS-074 |
| L29 | CS-078 The Nightly Settlement File | — | — | CS-081, CS-082, CS-083, CS-084 |
| L30 | CS-080 The Self-Validating Form | — | — | CS-079, CS-085, CS-086, CS-087, CS-088, CS-104 |
| L31 | CS-090 Bank Account Invariants | — | — | CS-089, CS-091, CS-092, CS-096, CS-101 |
| L32 | CS-108 The Capstone Mini-System | — | — | CS-093…CS-099, CS-100, CS-102, CS-103, CS-105…CS-107 (post-exam path) |

**Counting check (validated):** every L01–L32 has an anchor except L02 (toolchain
lecture — the protocol needs a problem, and L02's hour is the pipeline itself;
CS-009 runs as the L01 alternate if the calendar slips). 113 of 116 cases appear
in the map; the three DS-standalone cases (PF-DS-CS series in
`case-studies/data-science.md`) map to the DS track lectures L05/L10/L17 and run
as alternates there.

## 5. Module discussion angles (what makes each module's case *different*)

- **M1–M2 (L01–L06):** the discussion is about *precision*, not code — "can you state the stopping condition exactly?" Wrong answers are language answers.
- **M3–M5 (L07–L10):** the vote is between *approach families* (ladder vs table; one loop vs two). The reveal compares families, not correctness alone.
- **M6 (L11–L12):** the case is run *twice* — design-first (no code, IPO + pseudocode) then test-design (case set before the reveal). Both times the class commits on paper.
- **M7–M8 (L13–L16):** every case now has a *contract*: "write the function signature you'd defend." The discussion grades signatures before solutions.
- **M9–M10 (L17–L20):** draw the memory picture first, discuss second — no approach is heard until its box-row/grid drawing is on the board.
- **M11–M12 (L21–L24):** complexity intuition enters: "which approach reads the data twice? can you prove it's twice?" Counting comparisons is the discussion.
- **M13–M14 (L25–L28):** ownership language all discussion long — "whose box? whose lease? who deletes?" Approaches that can't answer "who owns this?" are rejected on that ground alone.
- **M15 (L29–L30):** every approach must state its *failure behavior* ("what does your program do when the file is missing?") before its success behavior.
- **M16 (L31–L32):** approaches are *interfaces*: "write the public method list a stranger could use safely." The class votes on interfaces, not implementations.

## 6. Common facilitation mistakes (from the method, not folklore)

1. Revealing the solution before the vote — the case becomes a lecture, the formative signal is lost.
2. Accepting "I'd use a loop" as an approach (no decisions made — same bar as pseudocode in DEMO-11).
3. Rescuing a struggling pair after 40 seconds — the protocol budgets 5 minutes; struggle is the content.
4. Running the same anchor case two modules running (satiation) — use the alternates column.
5. Skipping the *vote record* — two minutes of bookkeeping that powers the next lecture's opening question.
