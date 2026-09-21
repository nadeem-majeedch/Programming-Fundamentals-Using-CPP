# Lab Facilitation · Labs 09–12 — Arrays, Strings, Search & Sort

**Manuals:** [../../labs/lab_manuals/lab_09/](../../labs/lab_manuals/lab_09/) …
[lab_12/](../../labs/lab_manuals/lab_12/) · Hub:
[../LAB_FACILITATION_GUIDE.md](../LAB_FACILITATION_GUIDE.md).

---

## Lab 09 · One-Dimensional Arrays

- **Briefing:** "New shape today: many boxes, one name, numbered from zero — and C++ trusts you with the edges. Everything from loops forward now runs *over* this shape."
- **Demo sequence:** box-row traversal with indices above boxes (DEMO-18 acts 1–2); the silent bounds write; the six algorithms' names only (patterns pay off next week's labs — today is the shape).
- **Top-5 errors:** (1) `i <= N` traversal (MC-07 — the lab's planned trap); (2) `a[N]` "last element" (MC-11); (3) size retyped in loops instead of `const int N`; (4) 1-based reads (`a[1]` as first, MC-08); (5) sum accumulator uninitialized in the array loop (MC-10 back again).
- **Checkpoint questions:** "Point to `a[0]` on the board drawing — how far from the start?" · "Who polices your loop's bound?"
- **Differentiation:** strugglers — paper box-rows with movable index arrows; trace-template with the bound *pre-circled*; advanced — initializer-list semantics ({7} vs {} vs none), then min/max on an all-negative array as next week's preview.
- **Wrap-up questions:** "What is dangerous about `a[N]` even though it compiles?" · "Why `const int N` rather than the literal 5?"
- **Watch for:** the `{7}` surprise (rest zero-init) — most students predict garbage; it makes a memorable exit-ticket discussion. Bounds discipline is rubric from today: `< N` with a shared const.

## Lab 10 · Two-Dimensional Arrays

- **Briefing:** "A grid is rows of rows. Two indices, two bounds, one rule: the outer loop owns the slow hand."
- **Demo sequence:** row-major vs column-major print of one dataset (DEMO-20 act 1); swapped-bounds planned error; the colour-the-cells border act (act 4).
- **Top-5 errors:** (1) `[c][r]` reflex (MC-12); (2) inner bound `c < ROWS` (silent overrun); (3) in-place transpose on a non-square grid (DEMO-21's breakage); (4) column totals with the axis rule inverted ("prints row totals"); (5) corner double-count in border walks.
- **Checkpoint questions:** "For column totals, which axis holds the *result*?" · "Which cells got counted twice — colour them."
- **Differentiation:** strugglers — paper grids *before* any code, index rulers drawn; advanced — transpose on paper for 3×4, then implement with the swap loop *and* its correctness argument (why in-place fails for rectangles).
- **Wrap-up questions:** "State the axis rule in one sentence." · "Why is the paper grid worth two minutes before the code?"
- **Watch for:** students who "fixed" a wrong-shape bug by changing the *data* instead of the bounds — the debug-log row must say what the bounds *meant*.

## Lab 11 · Strings

- **Briefing:** "Strings are arrays you already understand — plus a length that knows itself. Today: characters as numbers, text as data, and the newline that bites."
- **Demo sequence:** classifier sweep (DEMO-22 act 1); the `'A' == "A"` diagnostic read aloud; the two-index palindrome walk traced on the board.
- **Top-5 errors:** (1) `cin >> name` for full names (MC-13); (2) missing `cin.ignore` between `>>` and `getline`; (3) `'A'` vs `"A"` in comparisons; (4) index-based char access off-by-one (`s[s.size()]`); (5) comparing with `==` then skipping normalization (case-sensitive "bugs" that are correct behavior).
- **Checkpoint questions:** "Where is the newline *right now*?" · "What does `tolower` change about your comparison — and where must it happen?"
- **Differentiation:** strugglers — the char-arithmetic table ('a'→97) printed; advanced — `myToupper` via arithmetic, then word-count with multi-space tolerance.
- **Wrap-up questions:** "Why did the two-word name break the `>>` read?" · "How many comparisons does the palindrome walk make for odd length — and why?"
- **Watch for:** the getline/`>>` interplay is *the* lab-11 ticket generator — demo the failure *again* at the checkpoint if one ticket appears (it will).

## Lab 12 · Searching and Sorting

- **Briefing:** "Two algorithms today, one precondition each: binary search needs *sorted*; sorts need *comparison direction*. Both fail silently when their contract is broken — you are the contract enforcers."
- **Demo sequence:** the physical bookshelf (DEMO-24 act 1) with probe counting; both sorts traced pass-by-pass (DEMO-25) on 6 cards.
- **Top-5 errors:** (1) binary search on unsorted data (MC-14 — the silent wrong answer); (2) flipped comparison → descending output (MC-15); (3) `lo < hi` vs `lo <= hi` mismatched with the updates; (4) selection's inner loop from `1` instead of `i+1`; (5) not-found returned as `0` (a valid index!).
- **Checkpoint questions:** "What does binary search *assume* — and what happens when we break it?" · "Trace pass 1 only: which element landed first, and what single character decided?"
- **Differentiation:** strugglers — card-sorting physically before coding; the four-case battery (present/absent/first/last) as a checklist; advanced — the early-exit `swapped` flag, then swap-count comparison selection-vs-bubble on the same data.
- **Wrap-up questions:** "Why is −1 the safe not-found value?" · "Which sort wins on nearly-sorted data — and *how much*, measured?"
- **Watch for:** search "always says not-found" — return-inside-loop placement (MC-14's cousin); sort students who test only on already-sorted input (the flag makes it look instant — make them shuffle).
