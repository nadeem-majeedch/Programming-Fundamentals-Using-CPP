# Assessment and Feedback Guidance

**Instructor-only.** How to *run* each assessment component and what feedback
to give. **The distribution below is the authoritative as-built package**
(verified against [../../instructor/assessment-rubrics/README.md](assessment-rubrics/README.md)
and the repository changelog during the final audit):

| Component | Weight | This file's section |
|---|---|---|
| 16 quizzes | 15 % | § 2 |
| 8 programming assignments | 20 % | § 3 |
| 16 labs | 10 % | § 4 |
| Midterm (L16) | 15 % | § 5 |
| Final (L32) | 25 % | § 6 |
| Practical coding assessment | 5 % | § 7 |
| Course project (P5) | 10 % | § 8 |

Formative assessment (not graded) is § 1 — it is where most of the teaching
power lives. Academic integrity is § 9. Institutional absences, make-ups, and
grade scales are **[CONFIGURABLE]** — this repository documents no institutional
policy; the audit's grading-contradiction fix aligned the *component weights*
only.

---

## 1. Formative assessment (ungraded, constant)

Four instruments, all already scheduled by the delivery guides:

1. **Exit tickets** (every lecture, 5 min): two targeted questions — the answers *are* next lecture's opening question. Harvest rule: any concept missed by >30 % of tickets becomes the next lecture's first 10 minutes.
2. **Case-study votes** (every lecture with a case): the vote split is the constraint-level signal — see [discussion-prompts/CASE_DISCUSSION_GUIDE.md](discussion-prompts/CASE_DISCUSSION_GUIDE.md) § 1.
3. **Checkpoint syncs** (every lab, 0:50): one student screen, class predicts the next line — the cheapest misconception detector in the course.
4. **MC-ID tagging:** when a misconception surfaces, name it aloud with its bank ID ([misconception-bank/](misconception-bank/misconception_bank.md)); students learn the taxonomy, and the exam's DEBUG items reuse the same IDs.

## 2. Quizzes (16 · 15 %)

- **Format:** 15 minutes, in-lecture (quiz-day lectures are marked in the delivery guides), 6–10 items, answer key in [answer_keys/](answer_keys/) — never circulated before the sitting.
- **Item mix:** 2 MCQ, 2 trace, 1 debug-identify, 1–2 short code. Traces only from programs students have *seen traced* (the demos' verified outputs).
- **Feedback protocol (48 hours):** item-level histogram on the board (no names); the two worst-missed items re-derived live using the bank's corrected versions; students annotate their own paper in a different colour — the annotation is the learning act.
- **Roster duty:** quiz < 50 % twice = Group-A entry per [DIFFERENTIATED_INSTRUCTION.md](DIFFERENTIATED_INSTRUCTION.md) § monitoring hooks.

## 3. Programming assignments (8 · 20 %)

- **Specs:** [../../assignments/](../../assignments/) — requirements are testable statements; grading is per-requirement, never vibes.
- **Feedback protocol:** the three-column comment — *what* (requirement ID), *why* (the failure it causes), *how* (the bank's MC-ID or a corrected pattern). Sample: "R3 · runs forever on empty input · sentinel loop needs the read-in-condition form · MC-05."
- **The 10-minute rule:** if more than 10 minutes of feedback would repeat one sentence to many students, that sentence becomes a full-class announcement instead.
- **Late policy, collaboration boundaries:** **[CONFIGURABLE]** — not defined in this repository.

## 4. Labs (16 · 10 %)

- **Rubric:** correctness / debugging / style / testing (4 rows, in each manual) — § 4–5 of [LAB_FACILITATION_GUIDE.md](LAB_FACILITATION_GUIDE.md) for how to earn marks honestly while circulating.
- **Debug-log grading principle:** marks pay for *diagnosis quality* (symptom → hypothesis → test → result), not for prose. A correct fix with an empty log caps the debugging row; a wrong first fix with a rigorous log can earn full marks.
- **Feedback in-session:** verbal, rubric-row-labeled ("style row: this magic number"), so nothing at submission time is a surprise.

## 5. Midterm (L16 · 15 %)

- **Construction:** pull from [exams/](../../exams/) blueprint + `instructor/exams/midterm_bank.md`; forms and assembly in `instructor/exams/PAPER_ASSEMBLY.md` (instructor-only).
- **Review teaching:** the review is DEMO-17 (the six-step method applied to unseen defects) plus the student-facing review guide — not slide re-walks.
- **Take-up discipline:** the two worst-missed TRACE items re-traced *on the frame/state pictures* within one week; every DEBUG item mapped to its MC-ID aloud.
- **Format facts** (per the as-built package): 90 minutes + 20-minute take-up split inside the 2-hour slot; 50 marks; 40 % conceptual / 60 % applied.

## 6. Final (L32 · 25 %)

- **Construction:** `instructor/exams/final_bank.md` (Modules 9–16 pool — the coverage note was corrected during the final audit), forms A–D, blueprint weighting in `PAPER_ASSEMBLY.md`.
- **Cumulative design:** emphasis 9–16 *with* cumulative coverage of the through-lines (silent failure, ownership, contracts) — the exam's CPLX items test the *connections*, which is why the case-study program matters for grading.
- **Post-exam:** the synthesis one-pager take-up per the L32 delivery guide; item analysis logged for the next cohort (the reflection loop).

## 7. Practical coding assessment (5 %)

- **What it is:** a timed, small, *live* task at a lab machine (the as-built package's designated slot in the second half of term) — one IPO problem with two checkpoints and one planted twist (e.g. an invalid input case).
- **Grading:** checkpoints passed + the debugging row of the lab rubric applied to their session. IDE + compiler only; no internet.
- **Feedback:** same-day verbal per student (2 minutes: "your guard saved you here; your bound did not there") — the highest feedback-per-minute in the course.

## 8. Course project (P5 · 10 %)

- **Rubric:** the project evaluation rubric in [assessment-rubrics/](assessment-rubrics/) (design / correctness / invariant discipline / persistence / report). The L31 interface-first presentation (Lab 16 briefing) is a graded *design-row* artifact — collect it before the build.
- **Feedback protocol:** milestone-based (the project's § Milestones), one rubric row per milestone — never a single end-loaded pile; the final report gets the design-row commentary students can carry to CS2.

## 9. Academic integrity

- **What this course treats as dishonest:** submitting code you cannot explain line-by-line in a 3-minute viva; copying trace answers without the trace; submitting work whose debug log describes someone else's session.
- **What this course treats as legitimate:** discussing *approaches* (the case-study protocol institutionalizes it); using lecture examples as patterns; TA triage under the no-touching-the-keyboard rule; the bank's practice tasks completed jointly then written individually.
- **The viva is the detector:** every graded artifact is viva-able for 3 minutes. "Why this `&` here?" — inability to answer re-flags the artifact, not the person, first time.
- **AI-assistance stance:** **[CONFIGURABLE]** — the repository documents no institutional AI policy. Whatever your institution decides, the viva rule above already operationalizes it: students must explain what they submit.
- **Sanctions ladder:** **[CONFIGURABLE]** per institutional policy.

## 10. Rubric-based feedback, summarized

Every graded row in this course maps to a *specific, teachable* behavior —
that is the package's design: correctness (requirements), debugging (the
six-step method + MC taxonomy), style (the course contract's flags and
conventions), testing (the three case families), memory safety (the ownership
rule), design (interfaces before implementations). Feedback that names the row,
the artifact, and the next concrete action is the standard; feedback that
states a feeling ("messy") is out of policy.
