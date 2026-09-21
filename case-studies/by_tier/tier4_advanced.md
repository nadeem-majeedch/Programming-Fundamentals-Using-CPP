# Tier 4 · Advanced — Projector Cases (CS-061–CS-080)

**Lectures L23–L30 · Modules 12–15** · think ~5 minutes · paper only.
Cases ascend in difficulty within the tier. Worked solutions: instructor
area only.

---

### PF-CS-061 · The Off-by-One Autopsy

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** A search routine returns "not found" for a value that exists.
- **Problem:** A binary search contains `high = n` (not n−1) and `low <= high` mixed with `mid = (low+high)/2`. Given the array [2,4,6,8] and key 8, trace the buggy loop precisely, show the state that reads out of bounds or loops forever, and identify the minimal fix set.
- **Input:** the array and key. **Output:** trace table + defect list.
- **Constraints:** n ≤ 20.
- **Thinking questions:** What invariant must [low, high] satisfy? Which line breaks it?

<details><summary>Hints (progressive)</summary>

1. Valid indices are 0…n−1; the initial high violates that.
2. Trace: low=0, high=4 → mid=2 compares a[2]=6 < 8 → low=3, high=4 → mid=3... watch the boundary.
3. Fix: high = n−1 with low <= high, *or* high = n with low < high — pick one discipline.
</details>

---

### PF-CS-062 · Pointer Cipher Walk

- **Tier:** 4 Advanced · **Lecture:** L25 · Module 13
- **Context:** A toy cipher advances a pointer along a message.
- **Problem:** Using only pointer arithmetic (no indexing), design a walk that prints a C-string one character per line, then the same characters shifted +1 (letters wrap Z→A). Specify the stopping condition and why `*p != '\0'` is the contract, not `p != nullptr`.
- **Input:** one word (C-string). **Output:** vertical listing + shifted listing.
- **Constraints:** letters A–Z only; length ≤ 40.
- **Thinking questions:** What does p++ advance *by*? When is the pointer past the string — and is that pointer itself legal?

<details><summary>Hints (progressive)</summary>

1. p++ advances by sizeof(char) — one byte — to the next cell.
2. The terminator is the only sentinel: dereference-compare, don't compare pointers.
3. The one-past-the-end pointer may exist but must never be dereferenced.
</details>

---

### PF-CS-063 · The Alias Explosion

- **Tier:** 4 Advanced · **Lecture:** L26 · Module 13
- **Context:** A code review finds three names for one integer.
- **Problem:** Given int x; int& r = x; int* p = &x; — design the demonstration that changing through r and through *p is observable via x, then predict a five-line sequence of mixed mutations *before* running it. State the one operation that is illegal for r but legal for p.
- **Input:** the listed snippet. **Output:** predicted then actual values.
- **Constraints:** —
- **Thinking questions:** Which name is the object? Which two names are *windows* into it?

<details><summary>Hints (progressive)</summary>

1. x is the object; r is an alias; p holds an address.
2. r = 5, *p = 9, x = 11: all three names report the survivor.
3. r cannot be re-seated to alias y; p can be repointed.
</details>

---

### PF-CS-064 · Out-Parameter vs Return

- **Tier:** 4 Advanced · **Lecture:** L26 · Module 13
- **Context:** A parser must return two values: a code and a value.
- **Problem:** Design parse(const std::string&, int& code) returning double, versus a version returning bool with double& out. Compare call sites and failure semantics; decide which communicates "this can fail" to a reader who only sees the call.
- **Input:** valid and invalid sample strings. **Output:** both interfaces' behavior.
- **Constraints:** inputs are numeric words or garbage.
- **Thinking questions:** Which design forces the caller to acknowledge failure? Where does the sentinel return version leak bugs?

<details><summary>Hints (progressive)</summary>

1. A bool return *demands* an if at the call site — visible control flow.
2. Sentinel values collide with legal data.
3. The out-parameter plus bool return separates "did it work" from "what it was".
</details>

---

### PF-CS-065 · The Dangling Return

- **Tier:** 4 Advanced · **Lecture:** L25 · Module 13
- **Context:** A helper returns int* to a newly computed value.
- **Problem:** Presented with int* makeValue() { int v = 42; return &v; }, predict the defect, the likely (undefined) symptom, and produce two safe designs: return-by-value, and caller-supplied storage via a reference parameter. State which fix is idiomatic for this course and why.
- **Input:** the listed snippet. **Output:** defect analysis + fixed designs.
- **Constraints:** —
- **Thinking questions:** When does v's storage die? What does the returned pointer point *at* after that?

<details><summary>Hints (progressive)</summary>

1. Automatic locals die at the closing brace.
2. The returned address is dangling: dereferencing is UB — anything may happen.
3. Return the int by value (copy is cheap); pointers out only for storage the caller owns.
</details>

---

### PF-CS-066 · Leak Hunter

- **Tier:** 4 Advanced · **Lecture:** L27 · Module 14
- **Context:** A long-running service grows in memory every hour.
- **Problem:** Given a loop that does int* p = new int[1000]; and (only on some paths) delete[] p;, classify which paths leak and redesign the ownership: exactly one owner, delete on every exit path, or replace with a stack/std::vector-based design. Defend the simplest correct choice for this course.
- **Input:** the listed loop. **Output:** leak paths + fixed design.
- **Constraints:** array of 1000 ints per iteration, 10⁶ iterations.
- **Thinking questions:** How many exit paths does the loop body have? What rule makes leaks impossible by construction?

<details><summary>Hints (progressive)</summary>

1. Early returns and exceptions skip the delete.
2. One owner per allocation; every path frees — or no manual new at all.
3. A local std::vector<int> frees itself: RAII beats discipline.
</details>

---

### PF-CS-067 · Grow-on-Demand Array

- **Tier:** 4 Advanced · **Lecture:** L27 · Module 14
- **Context:** A chat log must grow without a size limit.
- **Problem:** Design the growable array: a capacity variable, a size variable, and grow() that allocates double capacity and copies. Trace capacity growth for 17 pushes starting at 1. Why is doubling (not +10) the growth shape to prefer, in big-O terms?
- **Input:** push counts. **Output:** capacity trace + amortized argument.
- **Constraints:** capacity starts at 1; n ≤ 10⁵ conceptually.
- **Thinking questions:** What does a push do when size == capacity? How many total element-copies happen across all growths?

<details><summary>Hints (progressive)</summary>

1. Full → allocate 2×, copy, free the old block.
2. Capacities: 1, 2, 4, 8, 16, 32 — 17 pushes land in 32.
3. Total copies ≈ 2n: doubling makes the *average* push O(1); +10 growth makes it O(n) per push on average... wait, decide: which is it and why?
</details>

---

### PF-CS-068 · Struct Record Migration

- **Tier:** 4 Advanced · **Lecture:** L28 · Module 14
- **Context:** A school converts three parallel arrays into one struct array.
- **Problem:** Given parallel arrays name[], id[], gpa[], design struct Student and the conversion. Then show the sort that reorders the records by gpa and prove records stay intact (one swap moves all fields). What breaks if one field is left in a parallel array?
- **Input:** 5 records as parallel arrays. **Output:** struct design + sorted record list.
- **Constraints:** ids unique; gpa 0.0–4.0.
- **Thinking questions:** What is the unit of swap after the migration? Which bug class disappears entirely?

<details><summary>Hints (progressive)</summary>

1. struct Student { name, id, gpa }; array of Student.
2. Swap copies whole records: t = a[i]; a[i] = a[j]; a[j] = t.
3. Half-migrated data keeps the misalignment bug alive — migrate the whole record.
</details>

---

### PF-CS-069 · Registry with Sentinel Search

- **Tier:** 4 Advanced · **Lecture:** L28 · Module 14
- **Context:** A parts warehouse registers items and looks them up by SKU.
- **Problem:** Design struct Item { sku, qty } plus findItem(items, n, sku) returning the index or −1, and the transaction loop that applies stock movements until the sentinel `q`. Specify the three failure verdicts: unknown SKU, insufficient stock, non-positive amount.
- **Input:** registrations, then movements until `q`. **Output:** per-movement verdicts + final stock table.
- **Constraints:** ≤ 50 items; qty ≥ 0 always enforced.
- **Thinking questions:** Who validates the amount — the loop or the function? Where does the stock table print?

<details><summary>Hints (progressive)</summary>

1. findItem returns an index or −1; the caller interprets.
2. The transaction loop owns validation policy; findItem only finds.
3. Final table prints after the sentinel: one loop, three verdict branches.
</details>

---

### PF-CS-070 · Top-K Report

- **Tier:** 4 Advanced · **Lecture:** L24 · Module 12
- **Context:** A mall dashboard shows the k highest-selling products.
- **Problem:** Design the top-k selection over n sales records (name, units) *without* fully sorting: find the k best by repeated max-extraction (or argue for a full sort when k ≈ n). Trace k = 3 on 8 records. What is the cost of each strategy in comparisons, roughly?
- **Input:** n records, then k. **Output:** the k leaders in order.
- **Constraints:** 1 ≤ k ≤ n ≤ 100; unit counts may tie (state the tie rule).
- **Thinking questions:** What does one extraction cost? When does repeated-max collapse into a sort?

<details><summary>Hints (progressive)</summary>

1. One pass to find the max is O(n); extract k times is O(kn).
2. Mark extracted records as used (or swap them to the back).
3. k ≈ n → just sort: O(n log n) beats O(n²).
</details>

---

### PF-CS-071 · Binary Search Contract Test

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** A library ships binary search; you must certify it.
- **Problem:** Design the *minimal* test battery for binary search over an ascending array: empty, one element, first, last, absent-below, absent-above, absent-middle, duplicates. For each, state the expected result and which loop boundary it stresses. Which single test catches the `low < high` vs `low <= high` confusion?
- **Input:** the test table. **Output:** table + the discriminating test.
- **Constraints:** array ≤ 16 elements.
- **Thinking questions:** What does "absent-below" do to mid? Why is a two-element array a perfect boundary trap?

<details><summary>Hints (progressive)</summary>

1. Empty must return "not found" without indexing — test it first.
2. Two elements exercise mid == low and mid == high both.
3. Absent-below with low <= high and a wrong mid-step can loop forever — that's the discriminator.
</details>

---

### PF-CS-072 · Median Without Full Sort

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** A statistics chip reports medians under tight CPU budgets.
- **Problem:** Design a median routine that sorts a *copy* (justify why not the original), handles even/odd n, and argue whether counting-based selection could beat sorting for small-range data. What does your routine return for n == 0 — and can it ever be "no data"?
- **Input:** n values. **Output:** median (1 dp) or a documented empty verdict.
- **Constraints:** 1 ≤ n ≤ 999; values 0…100.
- **Thinking questions:** Why does sorting in place corrupt the caller's data? What does "copy" cost, and is it acceptable?

<details><summary>Hints (progressive)</summary>

1. The caller's array must survive — copy, sort the copy.
2. Even n averages the two middle elements — careful with integer division.
3. n == 0 is a contract violation: reject before touching anything.
</details>

---

### PF-CS-073 · The NullPointerException Class

- **Tier:** 4 Advanced · **Lecture:** L25 · Module 13
- **Context:** A crash report blames "pointer p" in three functions.
- **Problem:** Three snippets use p without checking: dereference on entry, after delete, and inside a loop that may never set it. Design the checklist that prevents all three defect classes at review time, and rewrite each snippet defensively.
- **Input:** the three snippets. **Output:** checklist + rewritten snippets.
- **Constraints:** —
- **Thinking questions:** Which check belongs at *every* dereference? Which defect has no runtime symptom at all?

<details><summary>Hints (progressive)</summary>

1. Rule: no dereference without proof of validity.
2. Uninitialized pointers: initialize to nullptr at birth.
3. Use-after-delete: set p = nullptr immediately after delete.
</details>

---

### PF-CS-074 · Struct vs Parallel Arrays Benchmark

- **Tier:** 4 Advanced · **Lecture:** L28 · Module 14
- **Context:** A debate: which layout for 10⁴ records?
- **Problem:** Design the argument (not code) comparing parallel arrays vs struct arrays for: sort a column, update one record, add a field, and pass "a student" to a function. Score each layout per operation and crown a winner for a beginner codebase.
- **Input:** the four operations. **Output:** comparison matrix + verdict.
- **Constraints:** —
- **Thinking questions:** Which operations touch one record vs one field? What does the compiler do for you with a struct copy?

<details><summary>Hints (progressive)</summary>

1. Sorting a field still needs record integrity — parallel arrays fight you.
2. Adding a field: struct = one line; parallel = every array plus every swap.
3. Passing a struct copies the unit; passing "a student" from parallel arrays is 3 arguments.
</details>

---

### PF-CS-075 · Two-Key Sort (Name then Score)

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** A directory sorts by name, breaking ties by score.
- **Problem:** Design the comparison-first sort: "less" means name < name, or equal names and score < score. Implement with any class sort using this comparator logic, and trace a tie case. What property must the comparator have (transitivity) and what breaks without it?
- **Input:** 6 (name, score) records with at least two name-ties. **Output:** sorted list.
- **Constraints:** names may repeat; scores 0…100.
- **Thinking questions:** What is the composite key? Why must "equal" be consistent in both branches?

<details><summary>Hints (progressive)</summary>

1. less(a,b) = (a.name < b.name) || (a.name == b.name && a.score < b.score).
2. Trace two equal names: the score decides; equal both → not less either way.
3. A contradictory comparator (a<b and b<a) corrupts any sort — transitivity is the guard.
</details>

---

### PF-CS-076 · The Cost Ladder

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** Three algorithms find whether a value exists; the team must pick.
- **Problem:** Given costs — linear scan O(n); sort-once-then-binary O(n log n + q log n); hash-like counting array O(n + q) for values ≤ 1000 — design the decision guide for (n, q) pairs: (10⁶, 1), (10³, 10⁶), (10⁶, 10⁶). Which wins each, and what data constraint backs the third option?
- **Input:** the three scenarios. **Output:** per-scenario winner + reasoning.
- **Constraints:** values in 0…1000 for option C only.
- **Thinking questions:** What does q (query count) do to amortization? Why can't the counting array scale past 1000?

<details><summary>Hints (progressive)</summary>

1. One query → linear; many queries on small ranges → counting.
2. Sort once pays off only when q log n beats q·n... compare directly.
3. The counting array's memory is O(range) — the range bound is the catch.
</details>

---

### PF-CS-077 · Merge Sorted Queues

- **Tier:** 4 Advanced · **Lecture:** L23 · Module 12
- **Context:** Two sorted daily logs must merge into one sorted log.
- **Problem:** Design the two-index merge of sorted arrays A (m) and B (n) into C, tracing index movement on A=[1,4,9], B=[2,3,10]. Specify the tail handling (what happens when one array empties first) and the total comparison bound.
- **Input:** two sorted arrays. **Output:** merged sorted array.
- **Constraints:** duplicates allowed (state which array wins ties).
- **Thinking questions:** What does the output index count? Why can the merge never need more than m+n−1 comparisons?

<details><summary>Hints (progressive)</summary>

1. Take the smaller head; advance that index only.
2. When one side empties, copy the other's tail directly.
3. Each comparison emits one element; ≤ m+n−1 emissions come from comparisons.
</details>

---

### PF-CS-078 · The Nightly Settlement File

- **Tier:** 4 Advanced · **Lecture:** L29 · Module 15
- **Context:** A bank processes an end-of-day file: deposits and withdrawals.
- **Problem:** Design the pipeline: read records (id, action, amount), apply with an overdraft guard, tally processed vs skipped, and print a closing report. Specify every skip reason and where each is counted. What should the report print if the file is empty?
- **Input:** a transaction file's format spec. **Output:** per-record verdicts + closing report.
- **Constraints:** amounts > 0; balances never negative.
- **Thinking questions:** Which loop reads the file — and what state does each record need? What is the invariant of a balance?

<details><summary>Hints (progressive)</summary>

1. getline + istringstream per line: malformed lines are data, not crashes.
2. Withdraw > balance → skip with reason; both counters advance... decide which counters.
3. Empty file: report prints zeros — and that is correct behavior, not an error.
</details>

---

### PF-CS-079 · Configuration with Defaults

- **Tier:** 4 Advanced · **Lecture:** L30 · Module 15
- **Context:** An app reads `key value` config lines; some keys may be missing.
- **Problem:** Design the loader: apply known keys, report unknown ones, and *after* reading, print the effective config where missing keys show their defaults. Trace on a file missing one of three keys. Decide: is an unknown key fatal, a warning, or silent?
- **Input:** config file contents. **Output:** effective config + anomalies.
- **Constraints:** three known keys; ≤ 20 lines.
- **Thinking questions:** When is a default "used"? Why must defaults print *after* the file is fully read?

<details><summary>Hints (progressive)</summary>

1. Store seen-keys; a missing key falls back at print time.
2. Unknown keys: warn and continue (policy — justify it).
3. A later line could override an earlier one — last-write-wins, then report.
</details>

---

### PF-CS-080 · The Self-Validating Form

- **Tier:** 4 Advanced · **Lecture:** L30 · Module 15
- **Context:** A kiosk collects applicant records with strict validation.
- **Problem:** Design record intake: name (non-empty), age (15–60), GPA (0.0–4.0) — re-prompting on each invalid field until valid, counting rejections per field. When does prompting end, and what does the summary report? Decide whether EOF (input closed) is an error or a graceful stop.
- **Input:** interactive field entries. **Output:** per-field prompts + rejection counts + final record.
- **Constraints:** bounded retries are *not* allowed (loop until valid or EOF).
- **Thinking questions:** What is the loop's exit condition — really? Which failure mode is the user's, and which is the environment's?

<details><summary>Hints (progressive)</summary>

1. Two exits: valid input, or stream closure (EOF) — handle both.
2. Per-field rejection counters make the summary useful to UI designers.
3. Never trust the stream state between reads: clear-and-check is the pattern.
</details>
