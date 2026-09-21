# instructor/ — INSTRUCTOR-ONLY

**⛔ This directory must never be published to students.** It holds answer
keys, grading anchors, delivery guides, misconception banks, and every other
instructor-facing resource in the course.

## Layout

```
instructor/
├── README.md                     ← this file — the package hub
├── ACCESS_CONTROL.md             ← what is restricted where, and the publish workflow
│
│ Core methodology
├── TEACHING_GUIDE.md             ← pointer to the root guide (single source, no duplicate)
├── CLASSROOM_METHODOLOGY.md      ← teaching formats, question techniques, planned-error rules
├── LESSON_DELIVERY_GUIDE.md      ← the 2-hour session frame + per-module index
├── DEBUGGING_GUIDE.md            ← the six-step method, symptom tables, how debugging is taught
│
│ Teaching banks
├── COMMON_MISCONCEPTIONS.md      ← one-page quick reference to the bank
├── misconception-bank/           ← 27 full entries (MC-00…MC-26), verified examples
├── lecture-delivery/             ← 16 module files: complete 21-field plan for all 32 lectures
├── demonstrations/               ← DEMO-01…DEMO-32 in 6 group files + 2 companion sources
├── discussion-prompts/           ← the 5-minute case protocol + per-lecture anchor map
├── lab-facilitation/             ← 4 files covering all 16 labs (briefing, triage, wrap-up)
│
│ Assessment & differentiation
├── LAB_FACILITATION_GUIDE.md     ← the standard 2-hour lab shape + error triage
├── DIFFERENTIATED_INSTRUCTION.md ← three learner groups × ten topics, same rubric
├── ASSESSMENT_GUIDE.md           ← how to run every component; authoritative weights table
├── INSTRUCTOR_CHECKLISTS.md      ← 13 printable checklists for the semester cycle
│
│ Restricted assessment material (authored with the assessment package)
├── ACCESS_CONTROL.md             ← rules for everything below
├── answer_keys/                  ← consolidated key index
├── assessment-rubrics/           ← programming-quality / correctness / testing / explanation rubrics
├── exams/                        ← question banks, paper forms, assembly guide, quiz-usage notes
├── case_studies/                 ← worked solutions for the projector case bank
├── exercise_solutions/           ← per-topic compilable solution files
├── projects/                     ← reference implementations for P1–P5
├── exercises_data_science/       ← DS-track solution notes
├── examples_data_science/        ← DS-track example keys
└── revision/                     ← enhancement/audit reports (package history)
```

## Start here (first-time instructor path)

1. [../TEACHING_GUIDE.md](../TEACHING_GUIDE.md) — the course's pedagogy in one file (root-level, student-safe).
2. [CLASSROOM_METHODOLOGY.md](CLASSROOM_METHODOLOGY.md) — formats, questioning, planned errors.
3. [LESSON_DELIVERY_GUIDE.md](LESSON_DELIVERY_GUIDE.md) — the session frame, then your module's file in [lecture-delivery/](lecture-delivery/).
4. [INSTRUCTOR_CHECKLISTS.md](INSTRUCTOR_CHECKLISTS.md) § 1–2 — semester and pre-lecture checklists.
5. Before your first lab: [LAB_FACILITATION_GUIDE.md](LAB_FACILITATION_GUIDE.md) and the lab's facilitation file.

## Conventions

- **Student/instructor separation:** anything a student may legally see belongs
  outside this directory; when in doubt, follow
  [ACCESS_CONTROL.md](ACCESS_CONTROL.md). The website build never mirrors this
  tree — verified in every site QA run.
- **MC-IDs and DEMO-IDs are shared vocabulary:** the bank, the demo scripts,
  the delivery guides, and the exams cite the same IDs. If you add an entry,
  keep the numbering stable.
- **Time tables sum to 120:** every lecture plan's segment table totals exactly
  120 minutes (quiz/exam variants documented inside the plan).
- **Buggy code is never shipped:** planned errors are typed live; the
  misconception bank shows buggy lines as comments or described edits.
- **[CONFIGURABLE] marks policy gaps:** absence handling, late policy, AI
  stance, and sanctions are institutional decisions, not this repository's.

## Status

🟢 Complete teaching package: 32/32 lecture delivery plans · 32/32 demonstrations
· 27 misconception entries · 16/16 lab facilitation guides · case-discussion
protocol with verified anchor map · differentiation, assessment guidance, and
checklists. See [revision/INSTRUCTOR-MATERIALS-ENHANCEMENT-REPORT.md](revision/INSTRUCTOR-MATERIALS-ENHANCEMENT-REPORT.md).

Related restricted material lives **inside** its own area (never here):
`quizzes/quiz_NN/instructor_key.md`, `../exercises/*/solutions/`,
`../assignments/assignment_N/instructor/`, `../labs/lab_manuals/lab_0N/instructor_notes/`.
