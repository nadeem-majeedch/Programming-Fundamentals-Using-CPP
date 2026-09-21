# Demonstrations · Group 3 — Loops, Design, Desk-Checks, Functions (L09–L16)

**Instructor-only scripts.** Conventions as in
[demo_group1_basics.md](demo_group1_basics.md): edit-in-place planned errors,
contract build, verified output, 3-step diagnostic ritual.

---

## DEMO-09 · Loops: Sentinel Anatomy and the Infinite-Loop Family (L09)

- **Objective:** show the three-part loop contract failing in its three canonical ways — and the guard that fixes the read.
- **Preparation:** compile `examples/loops_sum_digits.cpp` and `examples/loop_patterns.cpp`; rehearse the piped-EOF run so the hang is *bounded* (`./demo < empty.txt` with a timeout).
- **Sources:** [examples/loops_sum_digits.cpp](../../examples/loops_sum_digits.cpp) (sentinel + guard), [examples/loop_patterns.cpp](../../examples/loop_patterns.cpp) (patterns); bank entries [MC-04](../misconception-bank/misconception_bank.md), [MC-05](../misconception-bank/misconception_bank.md), [MC-06](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Trace the sentinel sum with a state table (4 rows: read → check → add → read).
  2. **Planned error 1 (MC-05):** delete the update/second read → hang on first input; classify; fix.
  3. **Planned error 2 (MC-06):** move the read inside so the sentinel is summed → wrong total; trace where the check was bypassed.
  4. **Act 3 (EOF):** pipe an empty input → with the guard (as shipped): clean exit; without it: hang (bounded). The guard's two exits (`sentinel`, `stream failure`) named.
- **Questions:** "What *must* move toward false every pass?" · "Which read does the *checking* — and where is it?" · "What are the two ways this loop legally exits?"
- **Expected observations:** hang → wrong total → clean-EOF-exit; the state table diverging from the code at exactly the misplaced read.
- **Common student mistakes:** "fixing" a hang by adding `break` (treating symptoms); sentinel summed because the check happens on the *previous* value.
- **Debugging variation:** hand out the three broken variants (one MC-ID each); teams diagnose from behavior + one line, then verify by run.
- **Extension:** do-while edition: why the validation prompt wants at-least-once semantics.
- **Verified output:** input `3 8 5 0` → `Sum of digits: 16` (verify exact wording against the file header before class; the fixed program exits cleanly at EOF with the partial sum).
- **Instructor notes:** keep every hang *bounded* (timeout/piped EOF) — a frozen projector is a lost 5 minutes. The guard was added to this example precisely because its own lecture teaches the idiom; mention that lineage.

---

## DEMO-10 · Nested Loops, `break`/`continue`, and Loop Patterns (L10)

- **Objective:** make nested iteration *audible* (the clock model) and `break`/`continue` visually distinct.
- **Preparation:** compile `examples/loop_patterns.cpp`; chalk plan for the 3×3 grid.
- **Source:** [examples/loop_patterns.cpp](../../examples/loop_patterns.cpp).
- **Delivery sequence:**
  1. Class chants a 3×3 grid traversal ("row 0: col 0, col 1, col 2...") — total-iteration arithmetic derived from the chant.
  2. Predict-then-run the pattern suite (sum/count/filter) with pattern names attached.
  3. **Planned error:** swap `continue` for `break` in the filter → observe the *set* difference (one skipped item vs all remaining items dropped).
  4. Triangular variant (`j <= i`) — shape prediction before run.
- **Questions:** "In `i<j`, which loop is the slow hand?" · "After `break`, where exactly does control resume?" · "How many total prints — prove it by trace, not formula."
- **Expected observations:** grid shapes; the filter-vs-stop difference; iteration counts matching the chant.
- **Common student mistakes:** swapped bounds (`c < ROWS` — Module 10's MC-12 preview); counting iterations from the *body* instead of the loop product.
- **Debugging variation:** "triangle prints a square" — one-character bug hunt from output shape alone.
- **Extension:** predict-then-run `for` with the counter modified *inside* the body (legal, horrifying; brief — taste only).
- **Verified output:** deterministic (fixed loops, no input); verify locally (shape lines) before class.
- **Instructor notes:** the chant is slow the first time and never needed again — the auditory pattern is durable. Keep the break/continue difference physical: stand at the inner loop; `continue` = "next repetition", `break` = "leave this loop".

---

## DEMO-11 · Design-First Walkthrough and Desk-Check Live (L11)

- **Objective:** make the design sequence itself the demonstration — code appears only after its plan is board-approved; then the trace table finds a bug *before any compile*.
- **Preparation:** board space for IPO chart + pseudocode column; `examples/functions_refactor.cpp` staged as the *final* artifact (built live, not revealed); buggy snippet composed from bank [MC-07](../misconception-bank/misconception_bank.md) off-by-one + [MC-10](../misconception-bank/misconception_bank.md) uninitialized accumulator; trace-table template projected.
- **Sources:** [examples/functions_refactor.cpp](../../examples/functions_refactor.cpp) (endpoint); case PF-CS-013 as the worked problem; [../DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) § 5 rules.
- **Delivery sequence:**
  1. IPO chart for the change-maker, built by questioning (Input? Process? Output?).
  2. Decomposition into ordered subproblems; each gets a *name* (foreshadowing functions). Pseudocode, three verbs per line, projected beside the chart.
  3. **Planned "error" (design-level):** the desk-check reveals the missing validation subproblem (negative payment) — *caught on paper*; the fix is one pseudocode line, before any C++ exists.
  4. Translate to C++ live (10 lines); run against the desk-checked cases.
  5. **Act 2 — desk-check as debugger:** fill the trace table on the buggy snippet one row per statement execution, narrating every cell; boundary iterations first. The divergent row is found by re-checking a "skipped" line; bug named; fix minimally; re-trace only the affected rows.
- **Questions:** "Which subproblem is the loop pattern from L10?" · "What did the desk-check catch that the compiler never would?" · "Which row did we almost skip — and why was it suspicious?"
- **Expected observations:** the plan catching the defect; code matching pseudocode line-for-line; the table's divergent row with zero compiler involvement.
- **Common student mistakes:** skipping to code; pseudocode that is C++ with fewer semicolons (no *decisions* made); filling trace rows from memory instead of statement order.
- **Debugging variation:** hand out a *code-first* solution with a planted design flaw; teams re-derive the IPO and find what design would have prevented. Swap roles on the trace: students fill, instructor plays skeptic ("convince me").
- **Extension:** design the two test cases that would have caught the traced bug from the spec alone (boundary + representative) — L12's method, delivered.
- **Verified output:** endpoint program compiles clean (contract); buggy snippet → its wrong total (e.g. 24 vs 30 per your constants) — verify both locally before class and put the *symptom*, not the answer, on the board.
- **Instructor notes:** resist the room's itch to code — the demo's *point* is that the itch is wrong. This is the exam's TRACE section made flesh; say so. The "skip nothing" rule is the one students resist; enforce it by making *them* justify each skip request.

---

## DEMO-12 · Test Design: Boundary + Representative Cases (L12)

- **Objective:** turn test design from instinct into a procedure — and show tests *finding* a bug the eye misses.
- **Preparation:** a 15-line program with a planted boundary bug (grade ladder with `> 60`, or a range check `a < x < b` written as two joined comparisons); test-case template on the board.
- **Sources:** buggy program composed live from the L12 notes' examples; [../DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) § 3 tables.
- **Delivery sequence:**
  1. Class designs the case set *from the spec* (no code visible): every boundary (59/60, 100/101), one representative per region, one invalid input.
  2. Reveal the code; vote: does it pass the class's own case set? Run each case predict-then-run.
  3. **The reveal:** the boundary case fails (`60` misclassified). Locate by trace; fix; the case set re-runs green.
  4. Generalize: boundaries, representatives, invalid — three families, always all three.
- **Questions:** "Which family did the bug hide in?" · "Why is testing the *spec* before seeing code stronger?" · "What does a green run actually prove?" (Only what the cases cover.)
- **Expected observations:** a case set that includes the failing boundary *before* the code is shown; the failed run; the fix verified.
- **Common student mistakes:** only happy-path cases; "it worked on my three tests" as proof; testing the code's behavior instead of the spec's.
- **Debugging variation:** give two programs (one correct, one with a boundary flip) and *only* the spec — teams must design a case set that separates them.
- **Extension:** write the case set as comments above `main` for a lab program — the habit the lab rubric's "testing" row rewards.
- **Verified output:** per the planted bug; e.g. input `60` → `FAIL` (buggy) vs `PASS` (fixed) — verify locally and stage both runs.
- **Instructor notes:** the strongest moment is the class *catching its own future bug before writing code* — narrate that explicitly ("this case set just saved you a lab night"). Keep the three families on the wall for the semester.

---

## DEMO-13 · Functions: Monolith → Decomposition, Return-in-Loop (L13)

- **Objective:** refactor a working monolith into functions live, then break the return semantics on purpose.
- **Preparation:** compile `examples/functions_refactor.cpp`; board columns ready for call frames.
- **Source:** [examples/functions_refactor.cpp](../../examples/functions_refactor.cpp); bank entry [MC-16](../misconception-bank/misconception_bank.md) family (print vs return).
- **Delivery sequence:**
  1. Run the monolith; identify its three IPO subproblems on the board (L11 continuity).
  2. Extract function 1 live: signature from the IPO chart; body moves; caller updated. Compile at this semantic checkpoint.
  3. Repeat for functions 2–3; run — identical output, now three named units.
  4. **Planned error:** move a `return total;` inside the accumulation loop → truncated result; trace the frame picture (return = frame exit); fix; re-run.
- **Questions:** "What did the function promise — and where is that promise written?" (signature) · "Why did the early return truncate?" · "Which frame column changed when we passed by value?"
- **Expected observations:** identical output pre/post refactor; the truncated sum after the planned error; frame columns appearing/disappearing on the board.
- **Common student mistakes:** extracting functions that *print* (MC-16's shape); signatures that don't match the IPO chart's inputs/outputs.
- **Debugging variation:** the print-instead-of-return variant: "function prints the right answer, program can't use it" — refactor to return under guidance.
- **Extension:** parameterize one extracted function over `n` (generalization); predict `n = 0` behavior before running.
- **Verified output:** deterministic (fixed data); e.g. totals identical pre/post refactor — verify locally; put the *expected* table on the board and check the refactor against it live.
- **Instructor notes:** compile at semantic checkpoints, not per line — the rhythm teaches students what a *unit of meaning* is. The early-return bug previews L15's guard-style returns (by design).

---

## DEMO-14 · Scope & Lifetime: Shadowing and the Global Corruptor (L14)

- **Objective:** make scope *visible* (nested boxes) and lifetime *timed* (birth/death lines), then demonstrate why globals fail.
- **Preparation:** compile `examples/scope_lifetime_demo.cpp`; rehearse the two-call corruption sequence.
- **Source:** [examples/scope_lifetime_demo.cpp](../../examples/scope_lifetime_demo.cpp); case PF-CS-038 as follow-up.
- **Delivery sequence:**
  1. Nested-scope boxes on the board: outer `count`, inner `count` — predict, run, explain shadowing (the inner box *hides*, not merges).
  2. Lifetime timeline for one local: born at declaration, dies at `}` — draw it.
  3. **Planned error:** the global-reliant function called twice — second call starts from the first call's leftover; silent logic bug; trace across two frames.
  4. Fix by parameterization; re-run; the bug is now *impossible* (no shared air).
- **Questions:** "Which `count` did line 12 mean — how do you know?" · "What state survived between the two calls, and where did it live?" · "Why can't the parameter version fail this way?"
- **Expected observations:** shadowed values; the corrupted second call; identical correct output after de-globalization.
- **Common student mistakes:** reading shadowed names as one variable; "globals are convenient" surviving the evidence (address it head-on).
- **Debugging variation:** symptom-only handout: "works once, wrong twice" — teams locate the global before seeing code.
- **Extension:** `static` local teased as the *legal* cross-call memory — one slide, explicitly "you will meet this in CS2; today you know it exists."
- **Verified output:** deterministic; e.g. call-1 correct, call-2 corrupted value X (verify locally; the exact X depends on the demo constants — put *behavior*, not value, on the board if you prefer).
- **Instructor notes:** the corruption demo is Module 7's moral moment — let the silence after "wrong twice" do the teaching. Connect to L09's stream-state lesson: *state that outlives a call is state you must design on purpose.*

---

## DEMO-15 · Overloading, Defaults, and Reference Parameters (L15)

- **Objective:** make overload resolution and reference binding *predictable* — the two compile-time/runtime selection stories side by side.
- **Preparation:** compile `examples/overload_ref_demo.cpp` and `examples/passing_modes.cpp`; rehearse the ambiguous-overload diagnostic.
- **Sources:** [examples/overload_ref_demo.cpp](../../examples/overload_ref_demo.cpp), [examples/passing_modes.cpp](../../examples/passing_modes.cpp); bank entry [MC-09](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. Overload set predict-then-run: which `print` binds for `int`, `double`, `char` arguments — *state the rule* after each (exact match → promotion → ambiguity is an error).
  2. Default arguments: partial-argument calls; predict each bind.
  3. **Planned error:** `f(3.5)` with `f(int)` and `f(double)` both present... resolves fine — so make it *ambiguous* (`f(long)` added, or two-way conversion) → read the diagnostic; the rule "ambiguity is an error, not a choice" lands.
  4. Reference parameters: `increment_v(x)` vs `increment_r(x)` — the L13 vote *reversed*; frame picture: alias-label vs copy-box.
- **Questions:** "Which overload — and *why*, in one rule-sentence?" · "After `increment_r(x)`, whose box changed?" · "When would you *refuse* a reference parameter?" (read-only → const-ref; L26 preview.)
- **Expected observations:** correct binds; the ambiguity diagnostic; the caller's variable changed only by the reference version.
- **Common student mistakes:** believing overloads are chosen at runtime; out-params declared without `&`; adding overloads until "one of them will fit" (ambiguity risk).
- **Debugging variation:** symptom: "my function computes the average but main still shows 0" — missing `&` on the out-param; frame-picture diagnosis.
- **Extension:** predict binds for `f(3.0f)` / `f('a')` against a three-overload set; verify.
- **Verified output:** deterministic; e.g. `x before: 5 / after value-call: 5 / after ref-call: 6` — verify exact wording locally before class.
- **Instructor notes:** the vote-reversal is the pedagogical heart — spend the full 15 minutes; nothing else in Module 8 pays like watching the class *change its collective answer on evidence*.

---

## DEMO-16 · Recursion: the Call Stack Made Physical (L16)

- **Objective:** make recursion's self-call *mechanical* — each call gets its own frame, the base case stops the pile, returns unwind in reverse.
- **Preparation:** compile `examples/functions_refactor.cpp` plus your chosen recursive program (factorial/sum from the L16 notes); board frame-stack plan with empty slots ready.
- **Sources:** recursive snippet from the L16 lecture notes; case PF-CS-031/032 follow-ups.
- **Delivery sequence:**
  1. One call traced in the frame picture (nothing new). Then `fact(3)` calls `fact(2)` — *stack a second frame on the board*, physically offset.
  2. Third frame; base case reached: no further call. Now unwind: each frame's return value written as the frame is crossed out, bottom-up.
  3. **Planned error:** remove the base case → the stack grows frame by frame on the board until the crash; run the real program (bounded, `Ctrl+C` or timeout) and show the toolchain's stack-overflow message (wording toolchain-specific — verify first).
  4. Loop-vs-recursion on the same task: same result, different bookkeeping — which picture would you rather debug?
- **Questions:** "What must shrink every self-call — or what crash do we earn?" · "In what order do the frames *return* compared to the order they were created?" · "Where does the 'memory' of where to resume live?"
- **Expected observations:** the stacked frames; the unwinding order (reverse); the overflow after base-case removal.
- **Common student mistakes:** believing recursion "loops" inside one frame (each call is a *new* frame — the board stack proves it); base case unreachable (progress never shrinks).
- **Debugging variation:** symptom: "stack overflow on input 0" — the base case placed after the recursive call; the frame stack shows why the exit is never reached.
- **Extension:** trace `sumDigits(450)` recursively (L32's final-exam favorite) on the frame stack; count frames for input 1000000 — the depth insight.
- **Verified output:** deterministic per input; e.g. `fact(3) = 6` with three frames stacked/unwound; overflow message per toolchain — verify locally and keep the run bounded.
- **Instructor notes:** the physical stack is the course's payoff picture — every later "why did it return that?" recursion question gets answered on it. Keep the overflow run *bounded* (timeout) exactly like the loop hangs; a frozen projector is a lost 5 minutes.

---

## DEMO-17 · Debugging Methodology Applied (Midterm Review Vehicle) (L16/Review)

- **Objective:** run the six-step method end-to-end on an unseen defect — the exact skill the midterm's DEBUG items assess.
- **Preparation:** an unseen buggy program (compose from two bank entries the class has *not* seen diagnosed live — e.g. MC-06 + MC-03 combined); symptom printed, code projected.
- **Sources:** bank entries per your selection; [../DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) § 1 as the on-screen method card.
- **Delivery sequence:**
  1. Steps 1–2 aloud: reproduce (given input), state the symptom precisely.
  2. Step 3: isolate — comment out halves *live* until the smallest failing snippet remains.
  3. Step 4: classify the stage (compile? no. link? no. runtime? logic?).
  4. Step 5: one-sentence hypothesis from the class, *recorded verbatim*.
  5. Step 6: one change; predict; rebuild; compare. Iterate until the hypothesis survives.
- **Questions at each step:** "What do we *know* now that we didn't 30 seconds ago?" · "Is this hypothesis testable — what outcome would *refute* it?"
- **Expected observations:** the bug located by process, not luck; the prediction-compare discipline visible.
- **Common student mistakes:** changing three things at once; abandoning a hypothesis without a test.
- **Debugging variation:** run the same protocol *student-driven* — instructor only asks "which step?" and enforces the one-change rule.
- **Extension:** two defects planted; watch the class discover the first fix doesn't finish the job — the honest texture of real debugging.
- **Verified output:** verify both the buggy and fixed outputs locally before class; the symptom line on the board must match the buggy build exactly.
- **Instructor notes:** this demo replaces the usual pre-midterm slide-review — the method *is* the review. Every step is a midterm skill; name the bank IDs after the reveal so students can re-practice them.
