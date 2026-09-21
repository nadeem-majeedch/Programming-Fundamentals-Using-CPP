# case-studies/ — Projector Case Studies

**108 case studies** for the course's signature teaching activity: the case
method for programming. The instructor projects one case, students think for
~5 minutes, the class discusses approaches, and only then is the worked
solution revealed.

**108 cases · 5 difficulty tiers · every case tied to a lecture (L01–L32) ·
projector files contain NO solutions.**

Worked solutions, discussion points, and grading notes live in the
instructor-only area — see
[instructor/case_studies/README.md](../instructor/case_studies/README.md)
(restricted content; students should not open it).

## How a case runs in class (≈15 minutes)

| Phase | Time | What happens |
|---|---|---|
| Project | 0:00 | Instructor shows the case from the projector file |
| Think | 5 min | Students work **on paper** — no keyboards, no compiler |
| Discuss | 5–7 min | Students propose approaches; instructor routes, does not correct |
| Reveal | 2–3 min | Worked solution + discussion points from the instructor file |
| Extend | homework | The extension challenge becomes an optional task |

The paper-only rule is the point: it forces *planning before typing* —
the single most valuable habit this activity trains.

## Case anatomy

Every projector case contains exactly these fields:

- **Case ID** (`PF-CS-NNN`) and **title**
- **Difficulty tier** (1–5, see below)
- **Related lecture / module** (`L07` · Module 4)
- **Context** — a real-world or computational scenario
- **Problem statement** — unambiguous, no hidden requirements
- **Input / Output** — exact formats
- **Constraints** — explicit ranges so edge cases are fair game
- **Thinking questions** — 3–4 prompts that scaffold the discussion
- **Hints (progressive)** — three escalating nudges, shown on request

The instructor's parallel file adds: expected concepts, common incorrect
approaches, instructor discussion points, solution outline, worked C++
solution, test cases, and the extension challenge. The **extension
challenge** is *public* (it appears on the projector after the reveal);
worked extensions stay in the instructor area.

## Tiers

| Tier | Name | Cases | Lectures | Character |
|---|---|---|---|---|
| 1 | Beginner | CS-001–020 | L01–L12 | Trace, predict, read I/O, first decisions/loops |
| 2 | Foundational | CS-021–040 | L13–L16 | Number algorithms, function design, decomposition |
| 3 | Intermediate | CS-041–060 | L17–L24 | Arrays, strings, searching, sorting, counting |
| 4 | Advanced | CS-061–080 | L23–L30 | Complexity, pointers, dynamic memory, records |
| 5 | Expert introductory | CS-081–108 | L29–L32 | Files, validation pipelines, classes, synthesis |

Tiers are difficulty *bands*, not a strict lecture gate — Tier 2 cases may
appear in week 9 for revision. Within each file, cases ascend in difficulty.

## Files

```
case-studies/
├── README.md            ← this file
├── by_tier/             ← PROJECTOR files (questions + hints only)
│   ├── tier1_beginner.md
│   ├── tier2_foundational.md
│   ├── tier3_intermediate.md
│   ├── tier4_advanced.md
│   └── tier5_expert_introductory.md
└── index.md             ← ID → lecture → tier → concept map
```

| Instructor copy | Content |
|---|---|
| `instructor/case_studies/solutions_tier1.md` … `solutions_tier5.md` | Solution outline, worked code, test cases, discussion points, misconceptions |
| `instructor/case_studies/README.md` | How to run the activity, pacing, rubric |

## Policies

- **No solutions in projector files.** Hints stop at nudge level; nothing
  that reveals an algorithm.
- **Compilation status:** worked solutions in the instructor area were
  compiled and executed with the case's test cases (see
  [../docs/CASE_STUDY_AUDIT.md](../docs/CASE_STUDY_AUDIT.md) for evidence).
  Projector files contain no code to compile.
- **Standards:** C++17 per [../docs/CPP_STANDARD.md](../docs/CPP_STANDARD.md);
  code style per [../docs/CODE_STYLE.md](../docs/CODE_STYLE.md).
- Case IDs are permanent: retired cases are marked *retired*, never renumbered.
