# Lab Facilitation Guide — How to Run the 2-Hour Lab

**Instructor-only.** Complements the student-facing manuals in
[../../labs/](../../labs/README.md) — the manual holds the tasks, rubric, and
starter code; *this* file holds the facilitation: briefing scripts, pacing,
error triage, differentiation, and wrap-ups. Per-lab guides:
[lab-facilitation/](lab-facilitation/) (four files, 16 labs covered, 4 labs each).

## 1. Standard 2-hour lab shape

| Clock | Phase | Notes |
|---|---|---|
| 0:00–0:10 | **Briefing** | Today's goal, one board picture, the two checkered checkpoints. Read the pre-lab quiz results aloud (anonymized): "three of you thought X — watch for it." |
| 0:10–0:20 | **Instructor demo** | The lab's demonstration sequence (per-lab guide below), errors edit-in-place. |
| 0:20–0:50 | **Guided block** | Everyone does tasks 1–2; TAs circulate with the *error triage table*, not answers. |
| 0:50–0:55 | **Checkpoint sync** | Class stops; one student screen shared; predict-the-next-line together. |
| 0:55–1:40 | **Independent block** | Tasks 3–4; differentiation ladder active (§ 3); debug-log discipline enforced. |
| 1:40–1:50 | **Debug-log review** | Pairs exchange logs; each finds one *diagnosis gap* (a symptom logged without a hypothesis). |
| 1:50–2:00 | **Wrap-up** | Exit questions (per-lab), preview next lab, submission reminder (manual § 12). |

## 2. Error triage table (teach TAs this, not answers)

| Student says... | First question | Then |
|---|---|---|
| "It doesn't compile" | "Read me the FIRST diagnostic — anchor word?" | Fix one error; recompile before reading on. |
| "It crashes when I run it" | "What exactly did you type? Reproduce it for me." | Classify stage; print the index/pointer at the crash site. |
| "It prints the wrong number" | "Trace the loop's last iteration on paper." | State table; check boundary iteration first (MC-07). |
| "It prints nothing" | "What does the open-check guard say?" (files) / "Is the prompt before or after the read?" | The silent families: MC-23, MC-06. |
| "It hangs" | "What moves toward false every pass?" | Bounded kill first (`Ctrl+C`), then MC-04/05/06 triage. |
| "It works on my machine" | "Show me, here." | Then check CWD (files), toolchain version, saved file. |

**The rule TAs must keep:** never touch the keyboard. Questions only; the
student's hands stay on their own defect. This is also how the rubric's
"debugging" row earns its marks honestly.

## 3. Differentiation ladder (every lab)

- **Struggling:** tasks 1–2 only, with the manual's trace-template pre-filled for the first loop; pairing rules from [../DIFFERENTIATED_INSTRUCTION.md](../DIFFERENTIATED_INSTRUCTION.md) § group A. Success = checkpoint 1 + honest debug log.
- **On pace:** tasks 1–4 + the rubric's standard rows. Success = all checkpoints + one self-designed test case beyond the manual's.
- **Advanced:** tasks 1–4 + the lab's extension task, then *TA-for-a-day*: they triage one classmate's defect using § 2's table (teaching = deepest encoding). Success additionally = their extension documented in the debug log.

## 4. The non-negotiables (every lab, every section)

1. **Open-check guards** in any file lab (rubric row — zero tolerance, MC-23).
2. **`const` on read-only parameters** once Module 7 begins (rubric style row).
3. **Bounds discipline** (`< N`, no magic numbers) from Lab 9 on (MC-07/11).
4. **Bounded hangs:** any demo of a hang uses a timeout/piped EOF (projector freeze = lost 5 minutes).
5. **Debug-log before fix:** the log's hypothesis row must predate the fix row (spot-check timestamps; grading pays diagnosis, per the manual's rubric).
6. **No solutions on screens:** the lab manuals ship tasks and starter code only; full solutions live in the instructor area ([../../instructor/answer_keys/](../answer_keys/) where present).

## 5. Reading the manual's rubric while circulating

The manual's 4-row rubric (correctness / debugging / style / testing) maps to
what TAs should *watch for live*: style violations caught during the guided
block cost students nothing (verbal fix); caught in submission they cost marks.
Circulate with the rubric in hand and say which row you're looking at — the
transparency is the feedback.

## 6. Per-lab guides

[lab_01-04_foundations.md](lab-facilitation/lab_01-04_foundations.md) ·
[lab_05-08_control_functions.md](lab-facilitation/lab_05-08_control_functions.md) ·
[lab_09-12_arrays_strings_search.md](lab-facilitation/lab_09-12_arrays_strings_search.md) ·
[lab_13-16_memory_files_oop.md](lab-facilitation/lab_13-16_memory_files_oop.md)

Each guide: per-lab briefing script, demo sequence, top-5 error table,
checkpoint questions, differentiation notes, wrap-up questions — complementing
the manual, never duplicating its tasks.
