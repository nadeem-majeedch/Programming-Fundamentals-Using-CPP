# Lab Facilitation · Labs 01–04 — Foundations

**Manuals:** [../../labs/lab_manuals/lab_01/](../../labs/lab_manuals/lab_01/) …
[lab_04/](../../labs/lab_manuals/lab_04/) · Hub:
[../LAB_FACILITATION_GUIDE.md](../LAB_FACILITATION_GUIDE.md) (standard shape,
triage table, ladder — used by all four guides here).

---

## Lab 01 · First C++ Program

- **Briefing (script):** "Today you join the two groups of people who can make a computer do something: those who know how, and those learning. By the hour's end you will have *compiled* — turned text into an executable — and run your own program. Errors today are not failures; they are the syllabus."
- **Demo sequence:** live type of `greeting.cpp` (DEMO-01's first 3 steps); compile; run. Then delete the semicolon, compile, read the diagnostic with the 3-step ritual, fix.
- **Top-5 errors:** (1) missing `;` (MC-00 — expect it in 20 % of screens); (2) `Main`/`mian` — link error; (3) running the *compiler* output name wrong (`./a.out` vs `-o` name); (4) editing the wrong file (two open tabs); (5) quotes from a word processor (smart quotes) — "no C++ compiler accepts curly quotes."
- **Checkpoint questions:** "What are the four stages? Which stage failed in the planned error?" · "What does `-o greeting` change?"
- **Differentiation:** strugglers — type-and-run only, prediction slip optional; advanced — add a third line whose output they predict in writing *before* compiling, then the mian link-error hunt.
- **Wrap-up questions:** "What is the difference between the compiler's output and the program's output?" · "Why will we always compile with the same flags?"
- **Watch for:** students photographing the screen instead of typing (typing is the learning today); the smart-quotes problem (project from a plain editor).

## Lab 02 · Variables and Calculations

- **Briefing:** "Last week you made the machine speak. Today it *remembers* and *computes*. The one rule: every variable has a type, and the type decides what the bits mean."
- **Demo sequence:** `types_and_sizes.cpp` predict-then-run (DEMO-03); then a 4-line receipt calculator built live: declare, read, compute, print — narrating the type choice per line.
- **Top-5 errors:** (1) uninitialized total (MC-10 — show the garbage once); (2) `int price = 3.99;` — narrowing warning, read it together; (3) reading into a literal (`cin >> 5`); (4) `=` in the reset (`count = 0` vs `==` inside a condition — preview MC-01); (5) forgetting `const` on the tax rate — style note, not error.
- **Checkpoint questions:** "Why is `double` right for the price but `int` for the count?" · "What does the compiler do when types mix in `price * count`?"
- **Differentiation:** strugglers — the receipt program skeleton with TODO comments; advanced — add quantity discounts (`if` preview, explicitly labeled as next-week's topic, *do not* explain the syntax yet).
- **Wrap-up questions:** "Name one quantity where choosing `int` would be a *bug*." · "What did the narrowing warning protect us from?"
- **Watch for:** magic numbers appearing in formulas after the const was declared (style row reminder); division appearing in a bill (MC-03 is *next* week — flag "hold that thought" when someone divides).

## Lab 03 · Operators

- **Briefing:** "Two surprises today: division that discards, and remainders that count. Everything else you already own." State the contract flags; today they earn their keep.
- **Demo sequence:** `precedence_demo.cpp` blocks (DEMO-05) including negatives; then the minutes→h:mm converter built live with `/` and `%`.
- **Top-5 errors:** (1) `(a+b)/2` average (MC-03 — the planned lab trap); (2) cast-after-divide; (3) `%` on a double (compile error — read it); (4) precedence in `x / 2 * y` assumptions; (5) negative modulo expectations — "documented behavior, we checked ours."
- **Checkpoint questions:** "`17 = 5·3 + 2` — which operator answers which part?" · "Where must the cast go for a correct mean?"
- **Differentiation:** strugglers — coins-on-desk for `17/5` before code; advanced — digit-extraction pipeline (`n % 10`, `n / 10`) as the warm-up for next week's digit problems, then predict `x % 2` for negative x and verify.
- **Wrap-up questions:** "When is integer division *exactly* what you want?" · "Why do the contract flags matter today more than ever?"
- **Watch for:** students memorizing "rounds down" — correct to "discards the remainder" aloud, every time; DS students computing a mean — route them to the DS track's mean exercise tonight.

## Lab 04 · Decision-Making

- **Briefing:** "Programs stop being calculators today — they start making *calls*. Your job: make the same call the same way every time. That means boundaries, and boundaries mean 59/60."
- **Demo sequence:** `decisions_grade.cpp` boundary sweep (59, 60, 90, 101) then the assignment-in-condition planned error (DEMO-07's act).
- **Top-5 errors:** (1) `if (mark = 60)` (MC-01); (2) ladder order bugs (`>= 90` after `>= 60` — unreachable arm); (3) `0 < x < 100` chained comparison (compiles, wrong — the classic); (4) missing `else` causing double-branches; (5) `switch` walk-off if Lab 4's extension uses switch.
- **Checkpoint questions:** "Which boundary does your ladder *not* test yet?" · "Walk the ladder for 60 — which arm fires, and why?"
- **Differentiation:** strugglers — decision-table worksheet before code (rows = regions, columns = outputs); advanced — convert the ladder to guard-style early returns and defend which is clearer; then the `0 < x < 100` bug hunt.
- **Wrap-up questions:** "Why did the ladder order matter?" · "Which two inputs must every boundary program be tested on, always?"
- **Watch for:** the chained-comparison bug — it is silent and *popular*; make one student's version the class-wide demo if it appears.
