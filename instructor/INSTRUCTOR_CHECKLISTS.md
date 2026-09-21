# INSTRUCTOR_CHECKLISTS — Print and Use

**Instructor-only.** Thirteen checklists covering the semester cycle. Each is
designed to fit one printed page per cycle. Items marked **[C]** are
**[CONFIGURABLE]** (institutional policy, not defined in this repository).

---

## 1 · Semester preparation (once, before Week 1)

- [ ] Course contract posted: C++17, flags, style guide ([../../docs/CPP_STANDARD.md](../../docs/CPP_STANDARD.md), [../../docs/TOOLCHAIN.md](../../docs/TOOLCHAIN.md))
- [ ] Teaching machines verified: `g++ --version` matches BUILD_REPORT's documented toolchain
- [ ] All 32 lecture files skimmed; quiz-day and exam-day lectures marked in your planner (quizzes per cadence; midterm L16; final L32)
- [ ] Lab machines write-access verified (Lab 15's file labs depend on it)
- [ ] `python tools/build_site.py` runs clean; website current
- [ ] Instructor-area access control reviewed ([ACCESS_CONTROL.md](ACCESS_CONTROL.md)); student-facing tree contains no answer keys
- [ ] Grading weights published from the authoritative table ([ASSESSMENT_GUIDE.md](ASSESSMENT_GUIDE.md)); institutional scale attached **[C]**
- [ ] Demo companions compiled fresh: `demo04_mixed_read.cpp`, `demo05_ds_conversions.cpp` (groups 1–2 folder)
- [ ] Case-study projector pack verified against the anchor map ([discussion-prompts/CASE_DISCUSSION_GUIDE.md](discussion-prompts/CASE_DISCUSSION_GUIDE.md) § 4)
- [ ] TA briefing scheduled; triage table and no-keyboard rule on the agenda

## 2 · Before each lecture (the evening before, 20 min)

- [ ] Delivery guide read ([lecture-delivery/](lecture-delivery/) module file); time table summed (must be 120)
- [ ] Demo rehearsed *on the teaching machine*; verified output matches the script
- [ ] Planned errors staged as edits-to-type, never pre-broken files
- [ ] Anchor case loaded; worked solution tab ready but closed
- [ ] Exit-ticket harvest from last time read; opening question built from it
- [ ] Quiz staged if quiz day (key separated before circulation)
- [ ] Board plan: which pictures (box-row, frames, pipe, wall) appear where

## 3 · During each lecture

- [ ] Three-step diagnostic ritual used on the *first* error, verbatim
- [ ] Votes taken before every predict-then-run (the reveal waits for the vote)
- [ ] Hangs/crashes bounded (timeout or piped EOF)
- [ ] Case protocol: silent read → think → pair → vote → discuss → reveal → record
- [ ] MC-IDs named aloud as misconceptions surface
- [ ] Exit ticket administered; papers collected
- [ ] Time table roughly held (±10 min); the cut order agreed with yourself in advance (cut practice, never the exit ticket)

## 4 · After each lecture (10 min, same day)

- [ ] Vote split and ticket misses logged (next lecture's opening question depends on it)
- [ ] Group-A candidates noted ([DIFFERENTIATED_INSTRUCTION.md](DIFFERENTIATED_INSTRUCTION.md) monitoring hooks)
- [ ] Anything that flopped annotated in the delivery guide margin for next cohort
- [ ] Website rebuilt if content changed (`python tools/build_site.py`)

## 5 · Before each lab

- [ ] Manual's rubric in hand; starter code compiles clean on a lab machine
- [ ] Facilitation guide read ([lab-facilitation/](lab-facilitation/)); top-5 error table memorized
- [ ] Pre-lab quiz results read; "watch for" list built
- [ ] Checkered checkpoints marked on your copy
- [ ] Differentiation ladder assigned (who gets the template, who TAs)
- [ ] Scratch directory prepared for file labs (Lab 15) — CWD lesson ready

## 6 · During lab delivery

- [ ] Briefing ≤ 10 min; demo errors edit-in-place
- [ ] TAs circulating with the triage table, *not touching keyboards*
- [ ] Checkpoint sync at 0:50 held — everyone stops
- [ ] Rubric-row feedback verbal and in-session
- [ ] Debug-log discipline enforced (hypothesis row precedes fix row)
- [ ] Bounds/guard/const non-negotiables spot-checked before students leave

## 7 · After each lab

- [ ] Submissions graded on the 4-row rubric; debug-log row honest
- [ ] Guard presence checked in every file-handling submission (MC-23 row)
- [ ] Open tickets triaged: which become next lab's briefing items
- [ ] Session flops annotated in the facilitation guide margin

## 8 · Before each quiz

- [ ] Paper assembled from the bank; key separated *before* printing student copies
- [ ] Coverage matches the cadence's modules; no item from an untaught module
- [ ] Traces only from programs traced in lecture (demos' verified outputs)
- [ ] Marks total verified by hand (per-item × count)
- [ ] Seating/paper-distribution logistics **[C]**

## 9 · Before each assignment

- [ ] Spec's requirements re-checked: each one *testable* as written
- [ ] Starter skeleton (if any) compiles; no solutions in the student tree
- [ ] Grading sheet mirrors the requirements 1:1
- [ ] Release + due dates posted **[C]**; collaboration boundary stated **[C]**

## 10 · Before projects (P1–P5 ladder)

- [ ] Project spec's scope checked against course scope (no untaught features required)
- [ ] Interface-first presentation scheduled *before* the build window
- [ ] Rubric's design row prepared (the method-list artifact)
- [ ] Milestones dated; feedback protocol (one row per milestone) ready

## 11 · Before the midterm (L16)

- [ ] Forms assembled per `instructor/exams/PAPER_ASSEMBLY.md`; blueprint satisfied
- [ ] Bank's 40 % conceptual / 60 % applied split verified on the assembled form
- [ ] Review session built on DEMO-17 (method practice), not slide re-walks
- [ ] Review guide linked for students; keys inaccessible ([ACCESS_CONTROL.md](ACCESS_CONTROL.md))
- [ ] Take-up plan: the two hardest TRACE items re-traced on pictures within a week

## 12 · Before the final (L32)

- [ ] Final forms from the Modules 9–16 pool (coverage note corrected in the audit); cumulative through-lines present
- [ ] Weighting vs `PAPER_ASSEMBLY.md` verified; marks math checked by hand
- [ ] Synthesis one-pager ready to project post-exam
- [ ] Exit-ticket question ("3-hour workshop?") printed for the next cohort's calendar
- [ ] Grades timeline and access arrangements **[C]**

## 13 · End-of-semester review

- [ ] Item analysis vs blueprint per exam (which three items would you replace?)
- [ ] Misconception-bank hit rates reviewed: which MC-IDs dominated this cohort's DEBUG items
- [ ] Case-study alternates rotated for next term (no satiation repeats)
- [ ] Delivery-guide margin annotations consolidated into the revision notes
- [ ] Exit-ticket "workshop" answers → next cohort's lab calendar
- [ ] Repository state: CHANGELOG entry written; audit reports updated if content changed
- [ ] Archived cohort data (scores, anonymized tickets) stored per institutional policy **[C]**
