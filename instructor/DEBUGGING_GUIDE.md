# Debugging Teaching Guide — Programming Fundamentals Using C++

**Instructor-only.** How to *teach* debugging: the course-wide method, the
planned-error technique for demos, per-class diagnosis tables (symptom → likely
cause → first move), and how debugging is assessed. The misconception bank
([misconception-bank/](misconception-bank/)) holds the 22 specific defects; this
file holds the method.

---

## 1. The course debugging method (teach from L02, expect by L16)

Six steps, in this order. Teach the *order*: beginners change code before they
read the message. Every lab from Lab 4 on asks for the log
([labs/resources/debug_log_template.md](../labs/resources/debug_log_template.md)),
which mirrors these steps.

1. **Reproduce** — find the exact input/command that triggers it. Unreproducible
   bugs cannot be fixed or graded.
2. **Symptom** — say precisely what happens: error text, wrong value, hang, crash.
3. **Isolate** — shrink it: comment out halves, hardcode the input, find the
   smallest snippet that still misbehaves.
4. **Classify the stage** — compile / link / runtime / logic. (L02 teaches the
   three error classes; logic bugs join in L06 with trace tables.)
5. **Hypothesis** — one sentence: "I believe X because Y."
6. **Test the hypothesis** — change *one* thing; predict the outcome before
   rebuilding; compare. Repeat until the hypothesis survives.

Teaching moves that make the method stick:
- Model it live on every unplanned failure (see
  [CLASSROOM_METHODOLOGY.md](CLASSROOM_METHODOLOGY.md) § 6) — narrate which step
  you are on, visibly.
- Enforce the one-change rule: students who change three things and "fix" the bug
  have learned nothing. In labs, ask "what did you change, and what did you
  predict would happen?"
- Praise diagnosis quality over fix speed. The lab rubric already does this.

## 2. Planned-error technique for demos

Each demonstration in [demonstrations/](demonstrations/) includes a **debugging
variation**: a deliberately broken state of the demo. Delivery discipline:

1. Break the code *visibly* (delete/edit a line while students watch — never
   swap in a secret pre-broken file).
2. **Predict first:** "Before I compile — will this be a compile error, a
   warning, or a silent wrong answer?" The classification *is* the lesson.
3. Compile/run; read the diagnostic together; ask which word points to the fix.
4. Fix minimally; re-run; compare output with the verified expected output.

Why some defects are warnings and some are silence (a recurring lecture point):
the course contract `-Wall -Wextra -pedantic` exists because the silent ones
(uninitialized use, `=` in a condition, signed/unsigned mixes) are the ones that
cost marks. Demonstrate at least one silent-wrong-answer bug per module —
the bank tags every entry with **Detection** (compiler / runtime / silent).

## 3. Stage-1 diagnosis tables (symptom → likely cause → first move)

### 3.1 Compile-time

| Symptom | Likely cause (bank ID) | First move |
|---|---|---|
| `expected ';'` at line N | Missing terminator on the *previous* statement (MC-00 none — basic) | Look one line up, not at N |
| `undeclared identifier` | Typo, or use-before-declaration, or wrong scope | Check spelling against declaration; ask "does this name exist in *this* scope?" |
| `lvalue required as left operand of assignment` | `x = 0` written inside a condition (`=` vs `==`, MC-01) | Read the condition aloud as a question |
| `invalid conversion ... const char*` etc. | Type mismatch in init/argument (MC-03 adjacent) | Compare declared type vs provided type |
| `expected primary-expression` | Missing `()` on a zero-arg call, or stray comma | Check the call syntax |

### 3.2 Link-time

| Symptom | Likely cause | First move |
|---|---|---|
| `undefined reference to 'main'` | No `main` in any translation unit (Lab-1 file does this *deliberately*) | Is there a `main`? |
| `undefined reference to 'foo()'` | Declared but never defined; or definition signature differs | Match parameter lists exactly |
| `multiple definition of ...` | Function defined in a header included twice (rare this term; mention, don't drill) | Definitions live in one .cpp |

### 3.3 Runtime / logic (the exam-relevant tier)

| Symptom | Likely cause (bank ID) | First move |
|---|---|---|
| Program hangs, prints nothing new | Sentinel loop without stream-state guard (MC-06); missing update (MC-05); `while` condition never falsified (MC-04) | Trace the loop variable: "what makes this false?" |
| Output "off by one" (one extra/fewer iteration, first/last item wrong) | `<=` vs `<` on bounds (MC-07); index starts at 0 vs 1 (MC-08); post/pre-increment confusion | Desk-check the *boundary iterations only* |
| Garbage number in output | Uninitialized variable (MC-10) | Search every declaration for `{}`/`= 0` |
| Every value equals the last read | Loop reads outside condition (MC-06 variant) | Check where the read happens relative to the check |
| Crash after "input" prompt | Bounds violation (MC-11, MC-12), bad dereference (MC-14/15) | Print the index/pointer *before* use — at the crash site |
| Wrong value only in some paths | Precedence (MC-02), integer division (MC-03), copy-vs-alias (MC-09), reference mix-up (MC-09) | Trace with the state table; watch types at each hop |
| Sum grows absurdly fast | Infinite loop adding (MC-04/05) | Print the variable each iteration, 3 iterations only |
| File: empty/garbage/no file | Open failure unchecked (MC-23) | `if (!in) { ... }` before any read |

## 4. Reading compiler diagnostics with beginners

Three-step ritual, every time (starts L02, automatic by week 4):

1. **First error only.** Later errors are usually downstream noise from the
   first; fix one, recompile. ("Errors cascade — fix the head of the snake.")
2. **Find the anchor**: the line number and the *one word* in the message that
   names the problem kind (`undeclared`, `expected`, `invalid conversion`).
3. **Restate as a sentence**: "The compiler says it does not know the name
   `conut` at line 7 — so I check spelling and declaration."

GCC's note-style diagnostics (`note: declared here`) are teaching gold — show
that the *second* block often contains the answer. Set `LANG=C`-style plain
output is unnecessary; do tell students their editor's red squiggle is *also*
the compiler and may lag — the terminal is the truth.

## 5. Desk-check / trace tables as the debugging weapon

From L06 on, the trace table is the primary logic-bug tool (exams assess it —
see the exam banks' TRACE items). Classroom rules:

- Columns: **line · statement · variables (all live ones) · output · comment**.
- Fill it *one row per statement execution*, no skipping "obvious" rows — the
  bug hides in the skipped row.
- For loops: trace the boundary iterations (first, second, last, first-failing)
  before the middle ones.
- Pair activity format: one student narrates rows, the other writes; switch at
  the halfway point; disagreements are the lesson (that is exactly the moment
  two mental models diverged).

## 6. Assessment of debugging

- **Lab debugging tasks** (every lab, § 9 of each manual): grade the *log* —
  each defect scores for reproduce/isolate/stage/hypothesis/test-of-hypothesis;
  the fix itself is worth little without the trail
  ([labs/resources/debug_log_template.md](../labs/resources/debug_log_template.md)).
- **Exam DEBUG items** (midterm/final banks): a snippet + symptom; students name
  the defect class, the line, and the minimal fix. Marking keys live in
  `instructor/exams/`.
- **Quiz DEBUG items**: one-minute defect identification (bank MC-IDs feed these).
- Design principle: never ask "find the bug" without giving the *symptom* —
  real debugging starts from observed behavior, and the answer keys are written
  on that premise.

## 7. TA conduct in labs (extended from TEACHING_GUIDE § 5)

| Do | Don't |
|---|---|
| Ask "which of the six steps are you on?" | Touch the keyboard |
| Ask "what did you expect this line to do?" | Say "you missed a semicolon" (say: "read line 12's message aloud") |
| Draw the box-arrow memory picture | Draw nothing and explain in words only |
| Require the log entry *before* helping | Fix it so they can move on |
| Point to the [misconception-bank/](misconception-bank/) entry when the defect matches | Hand out corrected code |
| Escalate after 15 stuck minutes to the "smallest reproducible step" script | Let a student silently restart from scratch |
