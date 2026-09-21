# Classroom Methodology — Programming Fundamentals Using C++

**Instructor-only.** Concrete teaching procedures for this course's active-learning
model. The per-lecture guides ([lecture-delivery/](lecture-delivery/)) reference the
formats and protocols defined here; this file defines *how*, they define *what/when*.

Items marked **[CONFIGURABLE]** are local-policy decisions, not course requirements.

---

## 1. The active-learning formats used in this course

### 1.1 Predict-then-run (every lecture)
1. Project a 5–12 line program (from the lecture's example files). **Do not run it.**
2. Students write the exact expected output (or the error class) — 90 seconds, individually.
3. Finger-check / mini-whiteboard vote **[CONFIGURABLE]**, then run it live.
4. If votes split, do not explain yet: ask one student from each camp to justify,
   then trace line-by-line on the board until the class finds the divergence point.

Why it works here: exams assess tracing; this format is tracing with stakes.

### 1.2 Think-pair-share (traces and design questions)
1. *Think:* 60–90 s solo on a trace table or IPO sketch.
2. *Pair:* 2 min — partners must reconcile to ONE answer (forces argument, not averaging).
3. *Share:* nominate pairs (rotate a name grid **[CONFIGURABLE]**), capture answers
   on the board in a two-column "we agree / we disagree" table before resolving.

### 1.3 Peer instruction (concept checks, from week 3)
1. Concept-check MCQ (build from the lecture's misconception, not trivia).
2. Vote 1 (individual). If 30–70 % correct: 2-minute peer discussion → revote.
   If > 70 %: confirm quickly and move. If < 30 %: re-teach with a different
   representation (never the same words).
3. Keep a per-lecture bank of 2–3 such MCQs; the lecture guides seed them.

### 1.4 Case-study discussion — the 5-minute protocol
Full protocol in § 3. Used every lecture from L01 with the case named in the
lecture guide; case statements live in `case-studies/by_tier/` (student-safe).

### 1.5 Bug hunt (at least one per week from L02)
Instructor ships a deliberately broken snippet (lecture notes' "Common pitfalls"
items, `examples/buggy_off_by_one.cpp`, or the bank's minimal examples).
Students must (a) name the error *class*, (b) quote the diagnostic or symptom,
(c) propose the minimal fix — in that order. Grade the diagnosis, not the fix.

### 1.6 Live coding with narration
Rules that keep live coding valuable (see also [LESSON_DELIVERY_GUIDE.md](LESSON_DELIVERY_GUIDE.md) § 3):
- **Narrate before you type.** Say the line's intent; students predict it.
- Compile at *semantic* checkpoints (after each complete idea), not each line.
- Insert one planned error per demo (the lecture guide says which) and let the
  compiler/diagnostic do the teaching — see [DEBUGGING_GUIDE.md](DEBUGGING_GUIDE.md) § 2.
- Never debug silently. If you fix without words, students learn that magic exists.

## 2. Questioning technique

**The question ladder.** For every new construct, climb four rungs in order:

| Rung | Form | Example (loops) |
|---|---|---|
| 1 Recall | "What does this line do?" | "What does `i++` change?" |
| 2 Predict | "What will the output be?" | "How many lines print?" |
| 3 Diagnose | "Why does it print that?" | "Why does the last line repeat?" |
| 4 Design | "How would you make it…?" | "Change one token to print in reverse." |

Rules of use:
- **Wait time ≥ 10 seconds** after any rung-2+ question. Count if you must; the
  silence is the learning.
- **Cold-calling from a rotating grid is recommended** so every student expects
  to answer; give a pass token per student per class **[CONFIGURABLE]**.
- Follow every correct answer with "convinced?" aimed at the class — make
  peer-scrutiny, not instructor approval, the authority.
- Normalize errors: replace "no" with "not yet — which rung are you sure of?"
  Students who fear being wrong stop predicting, and prediction is the engine.
- Sources: each lecture in [lecture-delivery/](lecture-delivery/) lists its
  opening question, prediction prompts, and misconception questions by ID from
  the [misconception-bank/](misconception-bank/).

## 3. The 5-minute case-study protocol (canonical)

Used with the case named in each lecture guide (statements: `case-studies/`;
worked solutions: `instructor/case_studies/` — keep solutions off the projector
until after discussion).

| Time | Instructor move | Student activity |
|---|---|---|
| 0:00–0:30 | Project the case; read the scenario aloud; confirm constraints ("what is *not* given?") | Listen; mark unknowns |
| 0:30–2:30 | Silent individual thinking. **Do not circulate or hint.** Capture suspects' names for later | Sketch IPO chart / steps / test cases on paper |
| 2:30–4:00 | Neighbours compare; reconcile to one approach | Argue, revise |
| 4:00–5:00 | Collect 2–3 distinct approaches on the board (no judging yet) | Nominate a spokesperson |

Then (5–12 min): walk the approaches toward a solution outline by questioning —
"What does your loop condition miss?", "Which test case kills approach 2?" —
and only then reveal the worked solution's *outline* (full code if time allows).
Close by naming the transferable idea ("this is the guard pattern — you will
reuse it in L30"). Formative record: note which approaches appeared; feed
recurring errors into next lecture's recall segment. Participation is assessed
by approach quality, not correctness **[CONFIGURABLE]**.

## 4. Memory-model board notation (use it consistently)

- A variable is a **labelled box**: `int n` draws a box labelled `n` (name outside,
  type on the tag) with the value inside.
- An array is a **row of boxes with index ticks 0..n−1** drawn *above* the boxes.
- A pointer is a **box holding an arrow** to another box; `nullptr` is an arrow to
  a struck-through ⌀ symbol. Never draw "magic clouds".
- A function call gets a **new frame column**: parameters boxed on entry, return
  value boxed on exit — pass-by-value copies the box, pass-by-reference draws a
  second *label* aliasing the same box.
- The stream is a **pipe**: `cout >>` writes to the right pipe, `cin <<` drains
  from the left; failed state = blocked pipe drawn with an ✗.

The same notation runs from L03 to L32 (classes = composite boxes). Consistency
across instructors is what makes it an exam-transferable skill — agree on it in
week 1 with your TAs.

## 5. Managing the two audiences (BSCS + BSDS)

- Every lecture guide marks a **data angle**: a one-line reframe of the main
  concept for data work (e.g., L17 arrays → "a column of observations"). Use it
  when the CS-flavored example loses the room.
- Pairing: mix confident typists with confident reasoners in guided practice;
  rotate weekly. Both programmes get the same assessments — differentiation is
  in *scaffolding*, not standards ([DIFFERENTIATED_INSTRUCTION.md](DIFFERENTIATED_INSTRUCTION.md)).
- The DS track material (`exercises/data-science/`, `examples/data-science/`)
  is the designated enrichment/homework lane for data-flavored practice —
  point students there rather than improvising.

## 6. When the live demo fails (it will)

Two-minute triage script, in order:
1. **Name the error class** aloud (compile/link/runtime/logic) — students classify.
2. Read the diagnostic together; ask "which word in this message points at the fix?"
3. If not resolved in 2 minutes: "This is a real debugging session — watch me
   apply the method" and switch to the [DEBUGGING_GUIDE.md](DEBUGGING_GUIDE.md)
   6-step procedure on the projector. A recovered failure teaches more than a
   clean demo; a hidden one teaches nothing.

Prevention: every lecture guide's prep checklist says *compile every file on the
teaching machine that morning* — the course contract
(`g++ -std=c++17 -Wall -Wextra -pedantic`) is the baseline.

## 7. Formative participation methods

Pick **one** primary method and stay consistent **[CONFIGURABLE]**:
exit tickets (the default — see [LESSON_DELIVERY_GUIDE.md](LESSON_DELIVERY_GUIDE.md) § 4),
finger-check voting, or mini-whiteboards. The lecture guides assume exit tickets;
each defines its two-question ticket. Review tickets *before* the next lecture —
the opening recall question is built from whatever the tickets show the class
got wrong.
