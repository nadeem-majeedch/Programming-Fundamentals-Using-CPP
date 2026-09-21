# Delivery Guide — Module 13 · Pointers and References (Week 13)

**Guides:** L25, L26 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L25 · Pointers: Addresses, `&`, `*`, `nullptr`, and Pointer Arithmetic

1. **Lecture/title:** L25 — Pointers: Addresses, `&`, `*`, `nullptr`, and Pointer Arithmetic
2. **Module/week:** Module 13 · Week 13 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_13/lecture_25.md): [lecture_25.md](../../lectures/week_13/lecture_25.md)): read `&` (address-of) and `*` (dereference) in context; declare and use pointers; use `nullptr` and test for it; explain array-name decay; walk arrays with pointer arithmetic.
4. **Prerequisite knowledge:** L15 references (alias vs address); L17 memory model (contiguity pays off now).
5. **Prep checklist:** compile `examples/pointer_basics.cpp` this morning; rehearse the dereference-null *crash* (know your compiler's exit code/behavior); load PF-CS-062 + PF-CS-065; board plan for the arrow notation.
6. **Materials & files:** `examples/pointer_basics.cpp`; cases PF-CS-062 Pointer Cipher Walk, PF-CS-065 The Dangling Return; [MC-14](../misconception-bank/misconception_bank.md), [MC-15](../misconception-bank/misconception_bank.md) snippets.
7. **Opening question (10):** "L15 gave you *aliases* (second labels). Addresses are one level further: a box that stores *where another box lives*. Why would a language want that?" — collect guesses (sharing, arrays, dynamic memory — all coming); park them on the board to tick off during the lecture.
8. **Concept sequence (30):** (a) addresses as box locations; `&x` asks for one; a pointer *stores* one — the arrow picture formalized (10); (b) `*` in declaration vs in expression: `int* p` (type) vs `*p` (the box it points to) — read aloud differently (10); (c) `nullptr` as "points at nothing, on purpose"; array decay: `arr` ≈ `&arr[0]`; `p+1` walks one *element* (10).
9. **Explanation guidance:** the declaration-vs-expression `*` is the week's pronunciation drill: "`int* p` — p is a pointer-to-int" vs "`*p = 5` — star-p *means* the box p points at." Never let students say "star p" for both. Null-dereference is demonstrated *crash-first* (see demo) so the check becomes self-evident. The parked guesses from the opening get ticked off as each motivation arrives.
10. **Demonstration (15):** [DEMO-26](../demonstrations/demo_group5_search_pointers_structs.md) — `pointer_basics.cpp`: address printing, dereference read/write, null-check guard; planned error: `*p = 5` with `p = nullptr` — the crash; classify it (runtime), then add the `if (p)` guard and re-run; second act: `p+1` on an array vs `&arr[1]` — identical addresses, decay made visible.
11. **Output prediction:** address-of values (unpredictable digits, but *relationship* predictions: two runs differ?); `*p` after `*p = 7` on the original variable (alias-adjacent vote); pointer-walk output vs index-walk output (identical — the point).
12. **Case study (15):** **PF-CS-062 Pointer Cipher Walk** — pointer arithmetic as traversal; the class walks a string with a moving pointer on the board picture first, code second.
13. **Guided coding (20):** pairs write `max_in_range(const int* begin, const int* end)` and a null-safe `safe_get(const int* p, size_t i, size_t n)`; TAs check: null-guards present, `const` on read-only, no arithmetic past `end`.
14. **Common misconceptions:** [MC-14](../misconception-bank/misconception_bank.md) (dereference hazards) — home lecture; "pointers are integers you can math freely" — tempered (element semantics); decay-as-loss ("the array forgot its size" — resolves L17's parked question!).
15. **Debugging activity:** symptom: "my function walks the array but crashes at the end" — one-past-the-end arithmetic; the board picture shows where the arrow left the boxes.
16. **Independent practice (20):** T09 items (address printing, dereference, null-guards); every pointer use preceded by a commented prediction of the arrow's target.
17. **Exit ticket (5):** (1) `int x=3; int* p=&x; *p=9;` — value of `x`? (2) Why does `p+1` on `int*` move 4 bytes, but "one element" is the honest answer?
18. **Summary (5):** tick off the opening's parked motivations; derive: "a pointer is a box holding an arrow; the arrow must point somewhere real before `*` reads or writes."
19. **Support:** arrow-stamp worksheets (draw the arrow before writing `*p`); the crash-replay in slow motion with the guard added as the *lesson*, not punishment.
20. **Extension:** pointer-walk string reversal (PF-CS-062) — indices banned; discover the two-pointer palindrome from L22 in pointer dress.
21. **Reflection:** did the crash-first demo make null-guards habitual? (Watch guided work — count unprompted `if (p)` checks.) Who still reads `*` as multiplication? (Pronunciation drill repeat next lecture.)

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L26 · References, Pass-by-Value vs Pass-by-Reference, and Arrays as Pointers

1. **Lecture/title:** L26 — References, Pass-by-Value vs Pass-by-Reference, and Arrays as Pointers
2. **Module/week:** Module 13 · Week 13 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 9)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_13/lecture_26.md): [lecture_26.md](../../lectures/week_13/lecture_26.md)): unify L15's references with L25's addresses; choose passing modes deliberately (value / const-ref / ref); explain array-parameter decay and the pass-with-size convention; defend mode choices in code review.
4. **Prerequisite knowledge:** L25 pointers; L15 references/overloads; L18 pass-with-size.
5. **Prep checklist:** quiz 9 staged; compile `examples/passing_modes.cpp` + `examples/overload_ref_demo.cpp`; load PF-CS-064; prepare the mode-choice debate cards.
6. **Materials & files:** `examples/passing_modes.cpp`, `examples/overload_ref_demo.cpp`; case PF-CS-064 Out-Parameter vs Return; quiz 9 + key.
7. **Opening question (10):** "Two tools that both 'point': L15's `int&` alias, L25's `int*` arrow. Same thing?" — structured debate (2 min pair, vote, park); the unification is today's arc.
8. **Concept sequence (30):** (a) reference vs pointer: alias (bound once, no re-pointing, no null) vs address-box (re-pointable, nullable, arithmetic-capable) — the honest comparison table (12); (b) passing-mode selection rules: small/copyable → value; read-only big → const-ref; write-back → ref (9); (c) arrays-as-parameters: decay recap; why `size` rides along; the `const T* begin, size_t n` idiom (9).
9. **Explanation guidance:** the selection rules are *checklist-taught* and applied to every signature written today — mode choice becomes a review reflex (the rubric's style row from L15 finally has teeth). Keep "references are pointers-lite" *out* of vocabulary: they are distinct tools with distinct rules; the table is the record.
10. **Demonstration (15):** [DEMO-27](../demonstrations/demo_group5_search_pointers_structs.md) — `passing_modes.cpp` revisited *with addresses printed*: value (different address inside), const-ref/ref (same address) — the mode table made empirical; planned error: by-value array "modification" that works *silently*... until the caller reads its array (it doesn't — decay means the callee modified the caller's memory all along: predict, run, reconcile).
11. **Output prediction:** the decay paradox above (votes will split — it *looks* like value semantics, behaves like reference); address-equality checks per mode.
12. **Case study (15):** **PF-CS-064 Out-Parameter vs Return** — design debate: return struct vs out-params; class argues both, chooses per criteria (readability, multiple outputs); the mode-choice checklist applied live.
13. **Guided coding (15 — quiz-day trim):** pairs re-signature three provided functions choosing modes deliberately with a one-line justification comment each; TAs challenge justifications, not syntax.
14. **Common misconceptions:** reference≡pointer conflation (the table owns it); "const-ref is just slower value" (inverted — show big-struct copy cost *by count of copies printed*); decay-as-value-semantics (demo).
15. **Debugging activity:** symptom: "my function fills the array but main's array is unchanged" — students now know this *can't* be decay... the bug is a re-declared local array inside the callee; the board picture catches it (arrow pointed at a new row of boxes).
16. **Independent practice (10 — quiz-day trim):** T09 mode-choice items.
17. **Quiz 9 (15):** per cadence.
18. **Exit ticket (5):** (1) Choose modes: (a) `print(const BigStruct&)`? (b) `bool get_next(Token& out)`? (c) `int sum(int a, int b)`? — one-word answers + why. (2) Why does an array parameter need its size as a separate parameter?
19. **Summary (5):** the unified table derived from the class's debate; Module 14 tease: "pointers that must be *born* and *killed* by hand — and the class that does it for you."
20. **Support:** mode-choice flowchart card (three questions → three modes); the decay paradox re-traced in pairs.
21. **Reflection:** are mode justifications appearing in code now? (The rubric row's effectiveness check.) Quiz 9 decay items → who needs the board picture again before Module 14?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 9 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
