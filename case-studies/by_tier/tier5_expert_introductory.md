# Tier 5 · Expert Introductory — Projector Cases (CS-081–CS-108)

**Lectures L29–L32 · Modules 15–16** · think ~5 minutes · paper only.
Cases ascend in difficulty within the tier. Worked solutions: instructor
area only. These cases synthesize files, validation, records, and classes —
the capstone tier.

---

### PF-CS-081 · The Attendance Register File

- **Tier:** 5 Expert · **Lecture:** L29 · Module 15
- **Context:** A tutor's attendance app persists one line per student.
- **Problem:** Design the file format (fields, separator, header row or not) and the loader that reports: total lines, loaded records, skipped lines with reasons. Decide what the loader does with an empty file and with a file that has *only* a header.
- **Input:** format spec + sample file. **Output:** load report.
- **Constraints:** ≤ 200 lines; fields: name, weeks present (0–16).
- **Thinking questions:** What makes a line "skippable"? Should the header be data or metadata?

<details><summary>Hints (progressive)</summary>

1. Skip reasons: empty line, wrong field count, out-of-range count.
2. Metadata lines are detected and consumed before the data loop.
3. Every skip increments a counter *and* names its reason.
</details>

---

### PF-CS-082 · Sensor Log to Summary Report

- **Tier:** 5 Expert · **Lecture:** L29 · Module 15
- **Context:** A data-science mini-pipeline: raw log in, summary out.
- **Problem:** Design the two-file pipeline: read `sensor.log` (timestamp, value), compute min/max/mean/count, write `summary.txt` with aligned columns. Specify behavior for a missing input file and for zero valid records. Which errors are *fatal* and which are *data quality* notes?
- **Input:** log format spec. **Output:** summary file contents.
- **Constraints:** values −40…125; ≤ 10⁴ lines.
- **Thinking questions:** What must open-failure do that bad-data must not? Where is the report written vs printed?

<details><summary>Hints (progressive)</summary>

1. Cannot open input = fatal (print + exit); bad lines = count and continue.
2. Zero valid records: the summary says so — never divide by zero.
3. The output file is created only if the pipeline succeeded... or always? Decide.
</details>

---

### PF-CS-083 · The Deduplicating Saver

- **Tier:** 5 Expert · **Lecture:** L29 · Module 15
- **Context:** A mailing list must never contain a duplicate email.
- **Problem:** Design the loader-saver: read emails (one per line), keep first occurrences in input order, write the cleaned list back. Specify the comparison (exact? case-insensitive?) and what the report shows (in, kept, dropped).
- **Input:** email list file. **Output:** cleaned file + counts.
- **Constraints:** ≤ 500 lines; emails ≤ 40 chars.
- **Thinking questions:** What structure answers "have I seen this?" fast — at this scale? Does order survive your plan?

<details><summary>Hints (progressive)</summary>

1. A seen-list of kept emails, scanned linearly: fine at 500.
2. Case policy must be explicit — pick one and state it in the report.
3. Keep-first preserves order; the drop counter tells the rest.
</details>

---

### PF-CS-084 · The Rolling Grade Book

- **Tier:** 5 Expert · **Lecture:** L29 · Module 15
- **Context:** An instructor appends marks weekly to one file.
- **Problem:** Design the two modes: APPEND (add `name score` to the file) and REPORT (read all, compute per-student averages from possibly multiple lines). Specify what APPEND does if the file doesn't exist yet, and what REPORT does with a student whose scores differ wildly across weeks.
- **Input:** mode + records. **Output:** file changes or report.
- **Constraints:** scores 0…100; names unique per week only.
- **Thinking questions:** Which open mode preserves prior content? Who aggregates — the writer or the reader?

<details><summary>Hints (progressive)</summary>

1. Append mode creates-or-continues; truncation is the danger to avoid.
2. REPORT aggregates at read time; the file stays raw.
3. Multiple lines per student: accumulate per name as you read.
</details>

---

### PF-CS-085 · Retry-Safe Config Loader

- **Tier:** 5 Expert · **Lecture:** L30 · Module 15
- **Context:** A kiosk boots from a config file that users may corrupt.
- **Problem:** Design the loader with fallbacks: missing file → built-in defaults; partial file → defaults for missing keys; corrupt values → defaults per key with a warning log. Specify the *order* of checks and what the boot log prints for a brand-new installation.
- **Input:** config scenarios (missing, partial, corrupt). **Output:** effective config + log.
- **Constraints:** three keys with defaults; ≤ 20 lines.
- **Thinking questions:** Which failure is invisible without logging? What makes a default "safe"?

<details><summary>Hints (progressive)</summary>

1. Three layers: file exists? key present? value valid?
2. Corrupt-but-present is the sneaky case — validate, don't just read.
3. New installation: every default fires; the log must say so explicitly.
</details>

---

### PF-CS-086 · The Error-Message Designer

- **Tier:** 5 Expert · **Lecture:** L30 · Module 15
- **Context:** A beginner program prints `Error` for every failure; users are lost.
- **Problem:** Redesign the error reporting for a marks-file app: enumerate the failure modes (cannot open, empty, bad line, out-of-range score, duplicate student) and write the exact message for each, including line numbers and the offending content. Then decide the exit-code discipline (0 = ok, 1 = usage, 2 = data).
- **Input:** the failure-mode list. **Output:** message table + exit codes.
- **Constraints:** messages ≤ 80 chars; user-facing (no jargon).
- **Thinking questions:** What does a user need to *fix* the problem? Which failures are recoverable in the same run?

<details><summary>Hints (progressive)</summary>

1. Message = what failed + where + what was found.
2. Recoverable data errors warn and continue; structural ones stop.
3. Exit codes let scripts react — but only if the discipline is consistent.
</details>

---

### PF-CS-087 · Transaction Log Replay

- **Tier:** 5 Expert · **Lecture:** L30 · Module 15
- **Context:** A wallet app reconstructs its balance from a transaction log.
- **Problem:** Design the replay: read `T depos|withdraw amount` lines in order, apply to a starting balance, and produce an audit trail (running balance per line). Specify the two halt-worthy anomalies (overdraft attempt, malformed line) versus continue-worthy ones, and the final verdict line.
- **Input:** log format + starting balance. **Output:** audit trail + verdict.
- **Constraints:** amounts in paisa (integer cents); balance ≥ 0 invariant.
- **Thinking questions:** Why does order matter absolutely? What does the audit trail add that the final balance does not?

<details><summary>Hints (progressive)</summary>

1. Replay is sequential: each line's verdict depends on all before it.
2. Skip-and-note for malformed; halt or guard for overdrafts — pick a policy and defend it.
3. The trail is the evidence; the verdict is the conclusion.
</details>

---

### PF-CS-088 · Multi-File Merger with Cross-Checks

- **Tier:** 5 Expert · **Lecture:** L30 · Module 15
- **Context:** Two branches both edited the roster; a merge is needed.
- **Problem:** Design the merge of `roster_a.txt` and `roster_b.txt` (same format): union by id, report conflicts (same id, different data) and files-only entries. Specify the conflict policy (keep A? keep B? reject both?) and the summary counts. What is the output if the files are identical?
- **Input:** two file formats. **Output:** merged file + report.
- **Constraints:** ids unique within a file; ≤ 100 records each.
- **Thinking questions:** What is the merge key? Which report counters must sum to the total union?

<details><summary>Hints (progressive)</summary>

1. Index one file by id as you read the other.
2. Every record lands in exactly one bucket: kept-A, kept-B, conflict, new.
3. Identical inputs → all records "kept", zero conflicts — verify that.
</details>

---

### PF-CS-089 · The CLI Calculator Object

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A course project wraps a calculator in a class.
- **Problem:** Design class Calculator: private accumulator, public reset(), apply(op, operand) for + − * /, and value() accessor. Specify the failure policy for /0 and for unknown ops (rejected with a reason, accumulator untouched). Why is the accumulator private — what misuse does that prevent?
- **Input:** operation sequences. **Output:** accumulator state after each apply.
- **Constraints:** doubles; ≤ 100 ops per session.
- **Thinking questions:** What state must survive between calls? Which public method could corrupt it if public?

<details><summary>Hints (progressive)</summary>

1. One data member: the accumulator; methods are the only writers.
2. apply returns bool (or reason): rejected ops change nothing.
3. Private + accessors means no external code can bypass the /0 guard.
</details>

---

### PF-CS-090 · Bank Account Invariants

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A teaching example: why free-floating variables cause chaos.
- **Problem:** Design class Account with private cents (long long) and methods deposit, withdraw, balance. Every method must preserve the invariant: cents ≥ 0 and no partial application on failure. Trace three attempted violations through your design. What does "invariant" buy that comments cannot?
- **Input:** method call sequences including violations. **Output:** verdicts + final balance.
- **Constraints:** amounts ≥ 0; withdraw > balance rejected.
- **Thinking questions:** Which single entry point could break the invariant if public? What must deposit(−5) do?

<details><summary>Hints (progressive)</summary>

1. All writes flow through two methods: small attack surface.
2. Negative amounts are rejected: deposit(−5) returns false, changes nothing.
3. The invariant holds *after every method* — that is the contract tests verify.
</details>

---

### PF-CS-091 · Playlist with History

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A music app remembers what played.
- **Problem:** Design class Playlist: private vector of tracks and a play index; methods add (reject duplicates), next (advances, wraps), current. Specify what next() returns at the wrap point and what current() returns for an empty playlist. Which method is the only one allowed to touch the index?
- **Input:** command sequences. **Output:** per-command results.
- **Constraints:** ≤ 100 tracks; names ≤ 30 chars.
- **Thinking questions:** Which member is state, which is cache? What breaks if add() also resets the index?

<details><summary>Hints (progressive)</summary>

1. State: tracks + index; everything else derives.
2. Only next() mutates the index — single-writer rule.
3. Empty playlist: current() reports it explicitly, never indexes.
</details>

---

### PF-CS-092 · The Thermometer Class Ladder

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A lab app stores temperatures in one unit, reports in three.
- **Problem:** Design class Temperature storing private celsius; setCelsius with validation (≥ −273.15), and accessors celsius(), fahrenheit(), kelvin(). Decide: one setter or three (setC, setF, setK)? Defend with the conversion-rounding problem when setting via F then reading C.
- **Input:** set/read sequences in mixed units. **Output:** reported values.
- **Constraints:** 1 dp output; internal storage full precision.
- **Thinking questions:** Where should the absolute-zero check live? Does setting by F and reading C lose precision — and is that acceptable?

<details><summary>Hints (progressive)</summary>

1. Convert F/K to C at the boundary; store one truth.
2. Validation lives in setters — the only doors in.
3. F→C→F round trips are exact at full precision; decide the display policy for 1 dp.
</details>

---

### PF-CS-093 · Composing a Garage (Has-A)

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A garage object contains car objects.
- **Problem:** Design Car (private model, km; drive(km) validates km > 0) and Garage containing an array of Cars with park(car, slot), totalKm(). Specify what totalKm() does with an empty slot and why Garage never touches Car's km directly — through which method does it read?
- **Input:** park/drive sequences. **Output:** per-op verdicts + totalKm.
- **Constraints:** 5 slots; slot may be empty.
- **Thinking questions:** What does Garage *own*? Which Car methods are its legal interface?

<details><summary>Hints (progressive)</summary>

1. Has-a: Garage has Cars; it uses their public methods only.
2. Empty slots contribute 0 km but must be skipped, not indexed.
3. totalKm() sums via km() accessor — never reaches into data.
</details>

---

### PF-CS-094 · The Registry Class (aggregation)

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A club registers members and must answer queries.
- **Problem:** Design class Registry: private vector of Member structs; add (id-unique), remove (by id, report missing), findById, averageAge. Specify each method's failure verdict and which two methods are const. What does the class guarantee about id-uniqueness that plain arrays never could?
- **Input:** command sequences. **Output:** per-command verdicts + query results.
- **Constraints:** ≤ 200 members; ages 15–99.
- **Thinking questions:** Where does uniqueness live — data or method? Which methods only *read*?

<details><summary>Hints (progressive)</summary>

1. add() enforces uniqueness; nothing else can insert.
2. findById and averageAge are const: they promise no mutation.
3. averageAge on empty registry: define the verdict, don't divide by zero.
</details>

---

### PF-CS-095 · Files to Objects: Student Roster

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** The capstone seam: file I/O feeding a class.
- **Problem:** Design the loader that fills a class Roster from `students.txt` (name, id, gpa) using Roster::load(path), then Roster::report() prints ranked stats. Decide the class interface first (what would a *user* of Roster want?), then implement load against it. What must load() return for a missing file vs partial garbage?
- **Input:** file format + sample. **Output:** report + return-code spec.
- **Constraints:** ≤ 300 records; gpa 0.0–4.0 validated.
- **Thinking questions:** Which design comes first — file parsing or class interface? What does the caller need to distinguish failures?

<details><summary>Hints (progressive)</summary>

1. Interface first: load(path) → bool/int code; report() const.
2. Missing file and bad-data are different results — two channels.
3. load uses the same validated intake as the manual path: one door.
</details>

---

### PF-CS-096 · The Undo Stack Text Editor

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A mini-editor supports one-level or multi-level undo.
- **Problem:** Design class Editor over a single string: insert(pos, text), delete_(pos, len), undo(). For one-level undo, specify what must be saved before each mutation and the failure verdict for undo() with an empty history. Then argue what changes for k-level undo.
- **Input:** edit sequences. **Output:** string state per step + undo results.
- **Constraints:** positions validated; text ≤ 200 chars.
- **Thinking questions:** What is the minimal history record? What does undo() restore — state or inverse operation?

<details><summary>Hints (progressive)</summary>

1. Save the whole string before each edit: simple, correct, memory-heavy.
2. Inverse operations (re-insert the deleted text) are the memory-cheap alternative — compare.
3. Empty history: undo() reports and changes nothing.
</details>

---

### PF-CS-097 · Vending Machine State Machine

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A vending machine is a state machine wearing a class.
- **Problem:** Design class VendingMachine: states IDLE → PAID → DISPENSED, methods insertCoin(5/10/25), select(item), refund(). Specify the legal transitions and each method's verdict in the wrong state (e.g., select before payment). What is the state variable's role in preventing invalid sequences?
- **Input:** coin/selection sequences. **Output:** per-op verdicts + state trace.
- **Constraints:** one item type, price 45; ≤ 20 coins per session.
- **Thinking questions:** Which methods change state? What makes "select while IDLE" impossible to *act on* wrongly?

<details><summary>Hints (progressive)</summary>

1. insertCoin moves IDLE→PAID (and stays PAID on overpay); select moves PAID→DISPENSED.
2. Wrong-state calls: rejected with a reason, state unchanged.
3. The state member *is* the guard: every method checks it first.
</details>

---

### PF-CS-098 · Grade Analyzer with Tiered Reports

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** The term project skeleton: data in, statistics out.
- **Problem:** Design the synthesis: class GradeBook (private records vector) with load from file, band counting (A–F ladder from CS-005), highest/lowest, and a histogram printer. Specify the interface *before* the implementation and identify which methods are const, which mutate. What does load() do on its *second* call — replace or append, and why must that be explicit?
- **Input:** marks file + report spec. **Output:** full report.
- **Constraints:** ≤ 300 records; ladder thresholds fixed.
- **Thinking questions:** Which public methods would a test harness call first? What does append-vs-replace change for the caller?

<details><summary>Hints (progressive)</summary>

1. load, bandCounts, extremes, histogram: name them, then build.
2. Readers are const; only load mutates state.
3. Second load: replace (fresh object per file) — document the choice in the header.
</details>

---

### PF-CS-099 · The Persisted Inventory (files + class)

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** An inventory class must survive program restarts.
- **Problem:** Design class Inventory with save(path) and load(path) mirroring its private vector of Item{sku, qty}. Specify the file format you choose and why, the behavior when load reads a file the class itself did not write (foreign format), and what save() does to an existing file. Which method is the class's single source of truth for the format?
- **Input:** command sessions incl. save/load. **Output:** file contents + verdicts.
- **Constraints:** ≤ 100 items; qty ≥ 0.
- **Thinking questions:** Who owns format knowledge — the caller or the class? What breaks if load trusts the file blindly?

<details><summary>Hints (progressive)</summary>

1. Format lives in save/load only: change it in one place.
2. load validates every field; foreign/garbage lines are rejected with reasons.
3. save() truncates deliberately — state that in its contract comment.
</details>

---

### PF-CS-100 · The Checkout Queue Simulator

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A data-science question: how long is the queue after n customers?
- **Problem:** Design the simulation: customers arrive with service times (from a file), one cashier serves FIFO; compute each customer's wait and the average. Specify the event order (arrival vs service completion) and the tie rule when both happen at the same minute. What does the model *assume* that real queues violate?
- **Input:** arrival+service pairs. **Output:** per-customer wait + average.
- **Constraints:** ≤ 100 customers; integer minutes.
- **Thinking questions:** What two times determine a wait? Where does the queue live in your data structures?

<details><summary>Hints (progressive)</summary>

1. wait = service start − arrival; start = max(arrival, prev finish).
2. One running "cashier free at" time suffices — no real queue needed.
3. Assumptions to name: no balking, no service interruptions, FIFO fairness.
</details>

---

### PF-CS-101 · The Audit-Safe Ledger Class

- **Tier:** 5 Expert · **Lecture:** L31 · Module 16
- **Context:** A ledger must answer "what did I do?" after the fact.
- **Problem:** Design class Ledger: private cents balance plus a private history vector; deposit/withdraw return verdicts *and* append to history only on success. Specify audit(...) reports: full trail, net, and rejected-count. What breaks if history is public — and what does "history only on success" make the audit mean?
- **Input:** operation sequences. **Output:** per-op verdicts + audit reports.
- **Constraints:** integer cents; overdrafts rejected.
- **Thinking questions:** Which two states grow together — and who keeps them consistent? What is a rejected operation's footprint?

<details><summary>Hints (progressive)</summary>

1. Balance and history must agree: both private, both touched by the same methods.
2. Rejected ops: zero footprint — audit shows only real money.
3. net() derives from history; balance() from cents: a consistency check between them.
</details>

---

### PF-CS-102 · Weather Station Class + File Roundtrip

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A station stores readings in a class and persists them.
- **Problem:** Design class WeatherLog: add(reading) validates −40…125, daily summary() (min/max/avg), save/load to file. Trace a full roundtrip: add five, save, clear, load, summary — what must match exactly? Specify what load does with a file containing 200 (out of range): accept, reject, or truncate the load?
- **Input:** add/save/load/summary sequences. **Output:** summaries + roundtrip verdict.
- **Constraints:** ≤ 1000 readings; 1 dp output.
- **Thinking questions:** Which invariant must survive the roundtrip? Is a partially valid file loaded fully, partially, or not at all?

<details><summary>Hints (progressive)</summary>

1. Summary before save == summary after load: the test.
2. All-or-nothing load (validate first, then commit) is simplest to reason about.
3. The file format is the class's private affair — like PF-CS-099.
</details>

---

### PF-CS-103 · The Two-Class Report Pipeline

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A sales office wants daily reports from raw tickets.
- **Problem:** Design two cooperating classes: TicketParser (file → records, with validation report) and SalesStats (records → totals, top item, hourly histogram). Specify the hand-off type between them (vector of struct?) and where each validation error lives. Why is splitting the work better than one god-class?
- **Input:** ticket file format. **Output:** report + validation summary.
- **Constraints:** ≤ 500 tickets; fields: item, qty, minute-of-day.
- **Thinking questions:** What is the contract at the seam? Which class is reusable tomorrow?

<details><summary>Hints (progressive)</summary>

1. Parser knows files; Stats knows numbers: one job each.
2. Hand-off: vector<Sale> — plain data, no I/O types cross the seam.
3. Reusability test: can Stats run on data from anywhere else? Then the seam is right.
</details>

---

### PF-CS-104 · The Integrity-Checked Config

- **Tier:** 5 Expert · **Lecture:** L30 · Module 15
- **Context:** Config files get edited by hand; formats drift.
- **Problem:** Design the loader that validates *structure* (key count, ordering, no duplicates) before *values*, and reports the first structural error with its line number, refusing the whole file. Contrast with per-key fallback (PF-CS-085): when is all-or-nothing the right policy? Trace a file with a duplicate key.
- **Input:** config scenarios. **Output:** accept/reject + first error.
- **Constraints:** 5 required keys in fixed order.
- **Thinking questions:** What does "first error" cost the user vs "all errors"? Who benefits from strictness?

<details><summary>Hints (progressive)</summary>

1. Structural pass: exactly the 5 keys, in order, once each.
2. Value validation runs only after structure passes.
3. Strict suits machine-written files; fallback suits human-edited ones — say which this is.
</details>

---

### PF-CS-105 · Student Records: The Composite Challenge

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** The capstone: struct-in-class-in-file.
- **Problem:** Design the full stack: struct Module { code, marks }; class Student (private modules vector; addModule validates unique codes and 0–100 marks; average()); then persist/load a vector of Students. Specify the file format for nested records and the loader's verdict for a module line with an unknown student id. What makes this case "composite"?
- **Input:** persistence format spec + commands. **Output:** records + averages + load report.
- **Constraints:** ≤ 50 students; ≤ 8 modules each.
- **Thinking questions:** Which layers validate which rules? What does "unknown id" mean for load order?

<details><summary>Hints (progressive)</summary>

1. Student validates its own modules; the vector-of-students loader validates references.
2. Two-pass load: students first, then modules — or reject orphan ids.
3. Composite = three layers, each with a contract: struct, class, file.
</details>

---

### PF-CS-106 · The Exam Seating Optimizer

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** An exam hall must separate classmates to deter copying.
- **Problem:** Given students (name, section) and a hall grid (rows × cols), design the seating that ensures no two adjacent seats (left/right, front/back) share a section when possible, reporting the unseatable leftovers. Specify "when possible" precisely — what makes an arrangement impossible? Trace a 2×4 hall with sections A:5, B:3.
- **Input:** student list + hall dims. **Output:** seating grid + leftovers.
- **Constraints:** ≤ 40 students; halls ≤ 8×8.
- **Thinking questions:** What is the greedy rule, and when does it strand a student? Which data structure holds the grid?

<details><summary>Hints (progressive)</summary>

1. Alternate sections row by row; snake direction to avoid vertical repeats.
2. Impossibility = one section outnumbers the rest by more than the checker pattern allows.
3. Leftovers are reported, never dropped silently.
</details>

---

### PF-CS-107 · The Library Fine Calculator (full spec)

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** A library charges fines with overlapping rules.
- **Problem:** Design the fine computation: base per-day rate, doubled for "reserved" books, capped at the book's replacement cost, waived when the library was closed (given closure dates). Given due/return dates + flags, compute the fine and produce the itemized receipt. Which rule wins when two caps interact? Trace three conflicting scenarios.
- **Input:** due date, return date, flags, closure list. **Output:** itemized fine.
- **Constraints:** ≤ 60 days late; dates within one year.
- **Thinking questions:** What is the *order* of rule application? Which days count — and do closures shorten or shift?

<details><summary>Hints (progressive)</summary>

1. Compute per-day charges first, then caps, then waivers — pick and defend an order.
2. Closures remove chargeable days: subtract, don't freeze.
3. The receipt must show each rule's contribution — no silent arithmetic.
</details>

---

### PF-CS-108 · The Capstone Mini-System

- **Tier:** 5 Expert · **Lecture:** L32 · Module 16
- **Context:** The course's final synthesis: a small but complete system.
- **Problem:** Design "CampusCafe": class Menu (items, prices), class Order (items + qty), class Register (balances, receipts to file), and a menu-driven session that validates every input, persists receipts, and prints a shift report. Specify the class responsibilities, the file formats, and the failure policy for every input path. Which single design decision would you revisit first after user testing — and why?
- **Input:** interactive session script. **Output:** receipts file + shift report.
- **Constraints:** ≤ 20 menu items; money in integer paisa; session ends with `shutdown`.
- **Thinking questions:** What does each class *own*? Where do the three modules meet — what crosses each boundary?

<details><summary>Hints (progressive)</summary>

1. Menu knows items; Order knows quantities; Register knows money and files.
2. Boundaries: Menu→Order (price lookup), Order→Register (charged amounts).
3. The revisit candidate: whatever the user-testing transcript shows users fumbling — predict it.
</details>
