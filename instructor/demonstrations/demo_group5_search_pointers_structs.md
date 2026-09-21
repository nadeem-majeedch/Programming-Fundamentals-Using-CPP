# Demonstrations · Group 5 — Search, Sort, Pointers, References, Structures (L23–L26)

**Instructor-only scripts.** Conventions as in
[demo_group1_basics.md](demo_group1_basics.md): edit-in-place planned errors,
contract build, verified output, 3-step diagnostic ritual.

---

## DEMO-24 · Linear vs Binary Search on a Physical Bookshelf (L23)

- **Objective:** make the halving insight *physical* before the code, then verify it in `search_compare.cpp`.
- **Preparation:** compile `examples/search_compare.cpp`; a sorted list of 8 numbers on the board (or actual index cards); rehearse the unsorted-input run.
- **Source:** [examples/search_compare.cpp](../../examples/search_compare.cpp); bank entry [MC-14](../misconception-bank/misconception_bank.md); case PF-CS-049 follow-up.
- **Delivery sequence:**
  1. Bookshelf act: 8 cards sorted; student volunteers; "find 43." Linear first (count the probes — say the number aloud). Then binary: fold the search space in half each probe, count again (3).
  2. Board table: n vs worst-case probes for both (8→8 vs 3; 1000→1000 vs 10; 1,000,000→1,000,000 vs 20). *This* is complexity intuition, delivered.
  3. Run `search_compare.cpp` predict-then-run: target present, target absent, first element, last element.
  4. **Planned error:** feed the binary search an *unsorted* array → silent wrong answer (or false absent). "What did the algorithm assume? What did we break?"
- **Questions:** "How many elements can binary eliminate per probe — and what does that do to the count?" · "Why did binary report 'absent' for a value that is present?" · "What is binary search's *price*?" (pre-sorting — next demo.)
- **Expected observations:** 8 probes vs 3; the silent wrong answer on unsorted input; the four boundary cases all correct.
- **Common student mistakes:** computing `mid` with integer overflow fears (note it, don't teach it — course scope); forgetting that "not found" is a *valid outcome*, not an error.
- **Debugging variation:** symptom: "binary search says 43 is absent but it's right there" — teams check the precondition (sorted?) first; the ritual's step 4 pays.
- **Extension:** count comparisons empirically: add a probe counter, run both searches on the same 1000-element array, tabulate.
- **Verified output:** deterministic; e.g. `linear: found at 5 (6 probes) / binary: found at 5 (3 probes) / absent: -1` — verify exact wording locally before class.
- **Instructor notes:** the physical act is not decoration — beginners who *fold the shelf* once remember the recurrence forever. Hold the O-notation vocabulary; the table *is* the lesson.

---

## DEMO-25 · Selection vs Bubble Sort, Traced at the Board (L24)

- **Objective:** make both quadratic sorts *visible* as pass-by-pass state changes, then bubble's early exit as a design lesson.
- **Preparation:** compile `examples/sorting_traced.cpp`; a 6-element dataset chalk plan; rehearse the swapped-comparison break.
- **Source:** [examples/sorting_traced.cpp](../../examples/sorting_traced.cpp); bank entry [MC-15](../misconception-bank/misconception_bank.md); case PF-CS-050 follow-up.
- **Delivery sequence:**
  1. Selection sort on 6 cards at the board: pass 1 fully traced (find min index, swap); students finish passes 2–3 aloud; run the traced program against the board.
  2. Bubble sort: adjacent-swap rhythm on the same data; "what bubbled? how far did pass 1 reach?"
  3. **Planned error:** flip one comparison (`<` ↔ `<=`) → *reversed* output; read the symptom aloud, locate by trace.
  4. Early exit: sorted input to bubble with a `swapped` flag → pass count 1; without the flag → full n² passes. *Design pays.*
- **Questions:** "How many swaps did selection make — how many *comparisons*?" · "Why does bubble's flag help on sorted input but not on random input?" · "Which sort would you pick for nearly-sorted data?"
- **Expected observations:** identical final array from both algorithms; the reversed-output symptom; pass-count 1 on sorted input with the flag.
- **Common student mistakes:** selection's inner loop starting at `i+1` written as `1`; bubble bounds (`n-1-i`) forgotten → redundant passes (silent, not wrong).
- **Debugging variation:** symptom-only: "my sort outputs descending instead of ascending" — single comparison flip; find it by tracing pass 1 only.
- **Extension:** swap-count comparison on the same dataset (selection ≤ bubble always? run it); stability discussed informally.
- **Verified output:** deterministic; e.g. sorted `{1 2 3 5 8 9}` from both; selection swap-count 3 vs bubble swap-count 9 on the demo data — verify exact values locally, put the *unsorted* row on the board and fill columns live.
- **Instructor notes:** keep both algorithms on one board half each — the *comparison* is the content, not either algorithm alone. The flag lesson is the first "engineering a constant-factor win" students meet; name it as such.

---

## DEMO-26 · Pointer Basics: Address-of, Dereference, Null (L25)

- **Objective:** make `&` and `*` two distinct operators with two distinct meanings, then dereference null *safely on purpose* (under a guard, with honest crash talk).
- **Preparation:** compile `examples/pointer_basics.cpp` and `examples/dynamic_memory_caution.cpp`; board boxes ready with *addresses* (invented hex values) labeled; rehearse the null-deref crash output.
- **Sources:** [examples/pointer_basics.cpp](../../examples/pointer_basics.cpp), [examples/dynamic_memory_caution.cpp](../../examples/dynamic_memory_caution.cpp); bank entries [MC-17](../misconception-bank/misconception_bank.md) (pointer declaration syntax) and [MC-18](../misconception-bank/misconception_bank.md) (null dereference).
- **Delivery sequence:**
  1. Board: `int x = 5;` box labeled 5 at "address 0x1000"; `int* p = &x;` — a second box *containing 0x1000*, labeled "points to x". Two boxes, two names, one arrow.
  2. Predict-then-run: `cout << x` → 5; `cout << p` → 0x1000 (compiler-dependent rendering — say so, honest about the standard vs the toolchain); `cout << *p` → 5 (walk the arrow aloud).
  3. **Planned error:** reassign `p = nullptr; cout << *p;` — *run it* and show the crash honestly (controlled, expected crash; name it undefined behavior whose *typical* symptom is exactly this). Then the guard: `if (p) { ... }` — the null-check reflex installed.
  4. Pointer arithmetic tease: `p + 1` shown once, explicitly labeled "the exact byte math is beyond today; what matters is the arrow moved."
- **Questions:** "What is stored *in* p — a 5 or an address?" · "What does `*` do on the left of `=` vs on the right?" · "Why did the guard version not crash?"
- **Expected observations:** the three-value output; the guarded branch skipping cleanly; students spontaneously using "arrow" vocabulary.
- **Common student mistakes:** reading `int* a, b;` as two pointers (bank MC-17 warning); dereferencing before the null-check habit forms; writing `*p = 5` when they meant `p = &y`.
- **Debugging variation:** symptom-only: "my program prints an address where I expected a number" — missing `*`; the fix is one character and the lesson is enormous.
- **Extension:** `swap(int*, int*)` call-site vs `swap(int&, int&)` call-site side by side — same effect, different syntax; neither style is "wrong", both are honest tools.
- **Verified output:** deterministic except the address rendering (say so); e.g. `x=5 / p=0x61ff08 / *p=5` — verify locally; put the *value triple* (5, address, 5) on the board without the hex.
- **Instructor notes:** the controlled null-deref is the one crash we *schedule* — frame it exactly that way ("today the crash is the demonstration; in your code it is the bug"). The `if (p)` reflex installed here is re-queried in L27 and MC-18's practice task.

---

## DEMO-27 · Passing Modes Revisited with Addresses (L26)

- **Objective:** make the mode table *empirical* — addresses printed at the caller and inside the callee for all three passing modes.
- **Preparation:** compile `examples/passing_modes.cpp` and `examples/struct_records.cpp`; board compartments plan for the record type; rehearse the missing-semicolon diagnostic.
- **Sources:** [examples/passing_modes.cpp](../../examples/passing_modes.cpp); bank entry [MC-09](../misconception-bank/misconception_bank.md).
- **Delivery sequence:**
  1. `passing_modes.cpp` *with addresses printed*: value (different address inside), const-ref/ref (same address) — the mode table made empirical; **planned error:** by-value "modification" that silently fails at the caller; the frame picture *proves* why.
  2. Reference-vs-alias vocabulary check: after `int& r = x;`, who is `r`? (Another name for the same box — predict, run, confirm with addresses.)
  3. **Planned error 2:** swap by value vs swap by reference on the same caller data — the one-character difference (`&` in the parameter list) decides whether anything happens at all.
  4. The design rule stated: outputs want `&`, read-only large data wants `const &`, small copies stay by value — each rule traced to today's measurements.
- **Questions:** "Whose address did the function see — how do you *know*?" · "After `int& r = x;`, how many names does the box have?" · "What single character decides whether a function can change its argument — and where must it be written?" · "When would you *refuse* a reference parameter?" (read-only → const-ref.)
- **Expected observations:** the address table matching the mode theory; the alias test confirming one box/two names; the by-ref change landing in `main`.
- **Common student mistakes:** out-params without `&`; assuming a reference parameter "copies on exit"; declaring `int& r;` without initialization (compile error — read it).
- **Debugging variation:** symptom-only: "my function 'updated' the record but main disagrees" — pass-by-value diagnosis via the frame picture.
- **Extension:** apply the three-rule design test to a function with two outputs and one read-only input — write the signature first, defend it aloud.
- **Verified output:** deterministic; e.g. value-call address differs, ref-call address matches caller; `x before: 5 / after value-call: 5 / after ref-call: 6` — verify exact values locally.
- **Instructor notes:** printing addresses turns the mode table from a memorized chart into a *measured fact* — students check the caller/callee addresses themselves. This demo is L26's vote machine: the class predicts, measures, and re-votes on evidence.
