# Differentiated Instruction — Three Learner Groups, Ten Topics

**Instructor-only.** Concrete, same-week interventions for the course's three
learner groups, organized by topic in course order. Each cell: the *task* to
give, the *hint* style that works, and the *signal* that says it worked.
Group definitions:

- **A · Struggling** — missed a checkpoint, quiz below 50 %, or two labs
  behind. Pattern: syntax anxiety + fragile loop tracing.
- **B · On pace** — meeting outcomes. Needs *depth*, not more volume.
- **C · Advanced** — early finishers, quiz ≥ 85 %. Needs *design* work and
  teaching roles, not harder syntax.

**Classroom management spine (applies everywhere):** pair A with B for guided
blocks (A types, B traces — swap next lab); C gets TA-for-a-day roles with the
[triage table](LAB_FACILITATION_GUIDE.md) § 2; never pair A with A or C with C
during guided work; all three groups get the same rubric — differentiation is
in the *path*, never the *standard*.

---

## 1. Variables and expressions (L03–L06)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Type-and-predict drills: 6 one-line declarations, write the type before running | "What is this quantity *physically*?" (coins, people, temperature) | Predicts type/size correctly 4 of 6 |
| B | Rewrite a working program replacing two magic numbers with `const`; justify each type in a comment | "Which type choice would survive a requirements change?" | Comments name the *reason*, not the rule |
| C | Build the minutes→h:mm converter, then a currency converter; write the IPO chart for each *first* | "Where could your design silently divide two ints?" | They *find* MC-03 in their own draft |

## 2. Decisions (L07–L08)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Decision-table worksheet (regions × outputs) *before* any code; then code the ladder from their own table | "Which row is 60 in?" | Boundary cases pass first try |
| B | Convert ladder → switch → guard-style returns; write one paragraph on which is clearest and why | "What makes an arm unreachable?" | The paragraph argues from *evidence*, not taste |
| C | The `0 < x < 100` chained-comparison bug hunt on three programs; then write the validation ladder for a grade *and* an age in one program | "What does `0 < x` evaluate *to*?" | They explain the bool-to-int conversion |

## 3. Loops (L09–L10)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | The four-column state table (read/check/work/next-read) for *every* loop, two iterations minimum | "What moves toward false?" | Hangs self-diagnosed with the table, no TA |
| B | Loop-pattern flashcards: given a task (sum/count/filter/search), name the pattern, then code | "Which pattern did L10 teach for this?" | Pattern named before code, correctly |
| C | Trace `j <= i` triangle shapes on paper for n=1..5, derive the shape rule, then implement FizzBuzz *as a table* (conditions × outputs grid) | "Prove the iteration count from the chant" | Derives counts, doesn't run-and-look |

## 4. Functions (L13–L16)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Signature-first worksheets: write all signatures for a 3-part task, bodies second; read each aloud as a sentence | "This function ___ given ___ returns ___" | Signatures correct before any body exists |
| B | Refactor their own Lab-6 monolith into functions; add one `const &` and defend the choice | "Who needs to *change* this data?" | The defense cites copy cost or intent |
| C | Write the recursive `sumDigits` *and* its loop version; trace both on 450; write one paragraph on which they'd ship and why | "Where does the 'memory' live in each?" | The paragraph mentions the frame stack |

## 5. Arrays (L17–L20)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Paper box-rows with movable index arrows; bound-circling drill (circle `< N` before running anything) | "Point to a[0] — how far from the start?" | Zero bounds violations in the lab session |
| B | The six algorithms from memory on a 4-element array; then count-if with a parameterized threshold | "Which pattern is min/max — accumulator or accumulator-with-logic?" | Names pattern, initializes from a[0] unprompted |
| C | Design the grow-on-demand array (CS-067 protocol); then explain vector's growth in one board pitch to group B | "What does doubling buy you? What does it cost?" | Amortization intuition appears (words, not O-notation) |

## 6. Strings (L21–L22)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Char-arithmetic table ('a'→97) beside the keyboard; classifier sweep on their own name; two-word-name getline drill | "Where is the newline *right now*?" | The ignore-line appears without prompting |
| B | Word-count with multi-space tolerance; palindrome with normalization; each with a 3-case test battery | "What does your program do with 'A man, a plan...?" | Normalization layer present |
| C | `myStrlen`/`myToupper` from scratch (library rebuilt); then CSV column statistics (CS-056 protocol) | "What does the terminator prove about the array's size?" | Sizing includes terminator headroom, explained |

## 7. Searching and sorting (L23–L24)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Card-sort physically; probe-count on 8 cards; then code selection with the comparison *pre-circled* | "Ascending ⇒ which element lands first?" | Pass-1 trace correct before any run |
| B | Implement both searches + both sorts; the four-case battery (present/absent/first/last) as a checklist | "What does binary assume — and who enforces it?" | Precondition check appears in code |
| C | Early-exit bubble with `swapped` flag; measure pass-counts sorted vs random; write the cost table linear-vs-binary for n = 8/1000/1M | "Design pays — where is the constant factor?" | The table matches the lecture's, self-derived |

## 8. Pointers (L25–L27)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Box-and-arrow templates; guard-writing drills at three dereference sites; "what's in p — value or address?" quiz each lab | "What question do we ask before `*p`?" | `if (p)` appears reflexively |
| B | Swap via pointers vs references side by side; address-printing to verify the mode table empirically | "Whose box changed — prove it with an address" | Mode table reproduced from measurement |
| C | Lease-ledger audit of a leaky program (every new → its delete); then rewrite with vector and argue which errors became impossible | "One owner, one delete — where does yours break?" | Names leak/dangle/double-delete in their argument |

## 9. File handling (L29–L30)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | The guard as a literal stencil: first line after every open, before anything else; transcript-testing their own program (feed garbage, observe survival) | "What does your program *do* when the file is missing — exactly?" | Guard present in every submission; can state the missing-file behavior |
| B | Skip-and-report over a messy dataset; append-vs-truncate experiment documented in the debug log | "When is skip better than stop?" | Chooses the mode per *context*, not habit |
| C | Two-file merge with cross-checks (CS-088's shape); design the error-message set for three failure classes | "Who reads this message at 2 a.m.?" | Messages name the file, the line, the reason |

## 10. Introductory OOP (L31–L32)

| Group | Task | Hint style | Signal |
|---|---|---|---|
| A | Struct→class conversion checklist (which member goes where, in order); invariant-sentence starters ("after every method call, ___ holds") | "What should be *illegal* in your class?" | Constructor validates; invariant stated per method |
| B | Their Lab-14 struct becomes a class; deposit/withdraw maintaining the invariant across both | "Who is the wall against?" (future-you) | Private data + validating methods, argued |
| C | The project's extension (undo/history or a second collaborating class); then TA-for-a-day triage with the § 2 table | "Where would a *count of all accounts* live?" (CS2 tease) | They teach the invariant idea to a peer, correctly |

---

## Progress monitoring hooks (per [ASSESSMENT_GUIDE.md](ASSESSMENT_GUIDE.md))

- **Group A roster source:** quiz scores + exit-ticket harvest + lab checkpoint misses (the delivery guides' reflection rows collect these).
- **Group C roster source:** early finishers *two labs running* — one lab is noise, two is a roster entry.
- **Movement rule:** groups are per-topic, not per-semester — a student can be A in pointers and C in strings. Re-derive at every quiz.
- **Never do:** announce the groups. The differentiation is invisible from the student seat (everyone gets "your next task").
