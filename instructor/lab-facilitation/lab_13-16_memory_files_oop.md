# Lab Facilitation · Labs 13–16 — Pointers, Memory, Files, OOP

**Manuals:** [../../labs/lab_manuals/lab_13/](../../labs/lab_manuals/lab_13/) …
[lab_16/](../../labs/lab_manuals/lab_16/) · Hub:
[../LAB_FACILITATION_GUIDE.md](../LAB_FACILITATION_GUIDE.md).

---

## Lab 13 · Pointers

- **Briefing:** "Two new operators, one new picture: `&` reads an address, `*` follows one. Everything today is the arrow — draw it before you type it."
- **Demo sequence:** the two-box board picture (DEMO-26 acts 1–2); the controlled null-deref and its guard; passing-modes with addresses printed (DEMO-27) to tie pointers to last module's aliases.
- **Top-5 errors:** (1) `int* a, b;` two-pointers reading (MC-17); (2) dereference before the guard (MC-18); (3) `*p = 5` where `p = &y` was meant; (4) printing `p` where `*p` was meant ("prints an address"); (5) pointer left dangling after delete (preview MC-25 — full treatment Lab 14).
- **Checkpoint questions:** "What is *in* `p` — walk me through `*p` on the drawing." · "Which question do we ask *before* every dereference?"
- **Differentiation:** strugglers — box-and-arrow templates with the address pre-labeled; guard-writing drills (three sites, three guards); advanced — `swap` via pointers vs references side by side, then defend when each is the honest tool.
- **Wrap-up questions:** "What does `*` mean on the left of `=` vs the right?" · "Why did the guarded version not crash?"
- **Watch for:** students afraid of the scheduled crash — frame it once more: "today the crash is the demonstration; in your code it is the bug." The `if (p)` reflex is the exit-ticket deliverable.

## Lab 14 · Structures and Dynamic Memory

- **Briefing:** "Structs give boxes *labeled compartments*; `new` gives you memory you must *return*. Both are ownership stories: one is automatic, one is yours."
- **Demo sequence:** struct define/copy/pass (DEMO-29 acts 1–4); then the leak/dangle/double-delete triad *sandboxed* (DEMO-28, bounded runs) and the vector version's clean run.
- **Top-5 errors:** (1) missing `};` after the struct (MC-19); (2) assuming struct copy is a reference; (3) leak — `new` in a loop, no delete (MC-24); (4) use-after-delete (MC-25); (5) double-delete (UB — never demo unbounded).
- **Checkpoint questions:** "After `Weather b = a;` how many compartments exist?" · "State the ownership rule: one ___, one ___."
- **Differentiation:** strugglers — the lease-ledger worksheet (action / ledger / arrows alive); struct→function signature drills; advanced — grow-on-demand array design (CS-067's protocol), then compare with `vector`'s growth behavior.
- **Wrap-up questions:** "Leak vs dangling — one sentence each, lease words." · "Why does vector make double-delete impossible *in its own code*?"
- **Watch for:** the course rule said plainly: raw `new`/`delete` is read-and-recognize; submissions use `vector`. Enforce the rule *as a rule*, not a preference — the rubric's memory-safety row does.

## Lab 15 · File Handling and Exceptions

- **Briefing:** "Files outlive your program; exceptions outlive your function. Both fail *silently* if you let them — today you learn to make every failure announce itself."
- **Demo sequence:** write→read→verify roundtrip (DEMO-30 acts 1–2); the silent empty-read then the guard (act 3); the `clear()`-without-`ignore()` spin (DEMO-31 act 3); throw/catch with the terminate variant (act 4).
- **Top-5 errors:** (1) no open-check guard (MC-23 — rubric row, zero tolerance); (2) CWD confusion ("it works in my IDE"); (3) the `while (!in.eof())` extra-record artifact; (4) `clear()` without `ignore()` (the spin, MC-06's stream edition); (5) exceptions used for expected input problems (wrong tool — the L30 division).
- **Checkpoint questions:** "What does your program *do* when the file is missing — exactly?" · "What does `clear()` clear, and what does it not?"
- **Differentiation:** strugglers — the guard as a *literal first line* after every open (stencil provided); transcript-based testing (feed the adversarial transcript, observe survival); advanced — skip-and-report over a messy dataset, then a two-file merge with cross-checks (CS-088's shape).
- **Wrap-up questions:** "Why is 'silent success' worse than a crash?" · "Where does recovery live — thrower or catcher — and why?"
- **Watch for:** students running from different directories comparing "broken" vs "works" — the CWD lesson is the wrap-up's first act if it appears. The guard's presence is graded in *every* file-handling submission from today forward.

## Lab 16 · OOP Mini-Project

- **Briefing:** "Everything converges: classes are structs with rules; files are persistence; functions are the behaviors. Your mini-project proves you can design — not just type — a small system."
- **Demo sequence:** the struct→class refactor live (DEMO-32 acts 1–3); the constructor-refuses-invalid act (act 4); the invariant sentence written per method; then the project rubric walk (instructor-only rubric: [../../instructor/assessment-rubrics/](../../assessment-rubrics/)).
- **Top-5 errors:** (1) everything-public fallback when the access diagnostic appears (design failure — fix by design); (2) constructor with a return type (MC-20); (3) invariant only checked in one method ("after every method call, ___ must hold" — all of them); (4) class-level state assumed shared (MC-22); (5) file persistence without the open-guard (MC-23's last stand).
- **Checkpoint questions:** "What *should* be illegal in your class — and which method enforces it?" · "How many `count` boxes do two objects own?"
- **Differentiation:** strugglers — the struct→class conversion checklist (which members go where, in order); invariant-sentence starters; advanced — the extension challenge (undo/history or a second collaborating class — the project's § Extension ideas), then *TA-for-a-day* triage during the independent block.
- **Wrap-up questions:** "What can a constructor never have?" · "One sentence: why is private data + validating methods safer *in a program you'll extend*?"
- **Watch for:** the project is the 10 % course component — the rubric's design row is *earned in the interface discussion first*: have students present their public method list before the independent block; the class questions it; then they build. Also: MC-22 resurfaces as "shared state" bugs — ask *how many boxes* questions while circulating.
