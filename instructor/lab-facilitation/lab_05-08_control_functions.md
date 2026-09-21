# Lab Facilitation · Labs 05–08 — Control Flow and Functions

**Manuals:** [../../labs/lab_manuals/lab_05/](../../labs/lab_manuals/lab_05/) …
[lab_08/](../../labs/lab_manuals/lab_08/) · Hub:
[../LAB_FACILITATION_GUIDE.md](../LAB_FACILITATION_GUIDE.md).

---

## Lab 05 · Loops

- **Briefing:** "One idea today: a loop is a promise that *something moves toward false*. Every hang you meet this afternoon is a broken promise — find the thing that isn't moving."
- **Demo sequence:** sentinel anatomy with the state table (DEMO-09's acts 1–2); the bounded hang (piped EOF, timeout); loop patterns suite (DEMO-10) with names.
- **Top-5 errors:** (1) missing update → hang (MC-04); (2) sentinel loop without re-read (MC-05); (3) read positioned after the work (MC-06 — sentinel processed); (4) `<=` on an N-count bound (MC-07 preview — full treatment Lab 9); (5) "fixing" hangs with `break`.
- **Checkpoint questions:** "What are the two legal exits of your loop?" · "How many reads happen per pass — and where?"
- **Differentiation:** strugglers — the four-column state table (read/check/add/read) pre-drawn for two iterations; advanced — do-while input validation, then the digit-extraction loop from Lab 3 extended to *all* digits.
- **Wrap-up questions:** "What made the broken loop hang — in one sentence using the word 'false'?" · "Why is the read-inside-the-condition idiom safer?"
- **Watch for:** the `break`-fix reflex — reject it in review ("which *condition* will now fail?"); unbounded prompt loops (add a retry cap as a style requirement from today).

## Lab 06 · Algorithm Design

- **Briefing:** "No new syntax today. New *discipline*: plan on paper, desk-check, then type. The compiler is not your designer."
- **Demo sequence:** the design-first walkthrough (DEMO-11 act 1: IPO → pseudocode → desk-check catches the flaw → C++), then the trace-table debug (act 2).
- **Top-5 errors (all design-level):** (1) skipping validation in the plan (the desk-check's catch); (2) pseudocode that is C++ (no decisions made); (3) IPO outputs that don't match the program's; (4) trace rows filled from memory, not statement order; (5) testing only happy paths (test families from DEMO-12: boundary/representative/invalid).
- **Checkpoint questions:** "Which subproblem was your desk-check's flaw in?" · "Which of the three test families is your weakest?"
- **Differentiation:** strugglers — IPO chart template with the validation row *pre-printed but empty*; advanced — design the case set for a classmate's spec before seeing their code, then reconcile.
- **Wrap-up questions:** "What did the desk-check catch that the compiler never would?" · "Why design tests from the spec, not the code?"
- **Watch for:** students who finish tasks 1–2 fast and *start typing task 3* — intervene; this lab's content is the planning, and the fast finishers need it most.

## Lab 07 · Functions

- **Briefing:** "Today your programs grow up: named, testable parts. The signature is a *promise* — parameters are what it needs, return is what it delivers. Print is not deliver."
- **Demo sequence:** monolith → three functions (DEMO-13 acts 1–3), compile at each semantic checkpoint; the return-in-loop planned error; print-vs-return refactor (MC-16's practice).
- **Top-5 errors:** (1) void-function-that-prints called "for its value" (MC-16); (2) missing prototype / definition-after-use; (3) parameter/argument order mismatch (silent wrong values); (4) `return` inside a loop (truncation); (5) forgetting `const` on read-only params (style row).
- **Checkpoint questions:** "Read your signature aloud as a sentence: 'this function ___ given ___.'" · "Which function is *testable* and why?"
- **Differentiation:** strugglers — signature-first worksheets (write all signatures, bodies second); advanced — decompose a 5-part task, then write a two-line `main` that reads like the IPO chart.
- **Wrap-up questions:** "What travels into your function — a copy or the original? How do you know?" · "Why do we print in `main`, not in the calculator function?"
- **Watch for:** signatures that don't match the IPO chart (design drift); the print-instead-of-return reflex — assign MC-16's practice task the same afternoon, not as homework later.

## Lab 08 · Recursion and References

- **Briefing:** "Two superpowers, one lab: functions that call themselves, and functions that change their caller's data. Both are about *frames* — the stack you draw and the boxes you alias."
- **Demo sequence:** the frame-stack recursion trace (DEMO-16) with the bounded base-case-removal overflow; then the reference-parameter vote machine (DEMO-15's act 4) — vote, measure, re-vote.
- **Top-5 errors:** (1) base case unreachable (progress never shrinks → overflow); (2) base case placed *after* the recursive call; (3) missing `&` on the out-param (MC-09); (4) returning a reference to a local (named as *the* danger, never shipped); (5) off-by-one in recursive range splits (MC-07 in new clothes).
- **Checkpoint questions:** "What shrinks every call? What stops the pile?" · "After `f(x)` with `&`, whose box changed — prove it with a printout."
- **Differentiation:** strugglers — frame-stack template with two pre-drawn frames for `fact(3)`; advanced — trace `sumDigits(450)` on the stack, then write the recursive binary search *signature* only (L23 preview).
- **Wrap-up questions:** "In what order do frames return — and why?" · "What single character decides whether a function can change its argument?"
- **Watch for:** recursion students who "got it" without the stack (they recite, can't trace) — the exam's recursion item is a *trace*; make them draw once more. Reference-parameter confusion is expected to *invert* the class vote — that inversion is the lesson, record it.
