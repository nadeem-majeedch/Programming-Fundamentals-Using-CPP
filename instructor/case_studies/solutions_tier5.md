# Tier 5 Instructor Companion — CS-081–CS-108

Per case: expected concepts · common incorrect approaches · discussion
points · solution outline · worked solution · test cases · extension.
Worked solutions marked **compiled ✓** were built with the course
contract and executed; synthesis-level cases carry verified design
outlines and, where a full program is reasonable, compiled code.

---

## PF-CS-081 · The Attendance Register File (design-level)

**Expected concepts:** format design, skip taxonomy, metadata vs data
(PF-15.1).

**Common incorrect approaches:** no header decision (every loader
guesses differently); skip without a reason (unauditable); treating a
header-only file as an error (it's a valid empty register).

**Discussion points:** Format: `name weeks` per line, header optional?
— decide and document. Skip reasons: blank, wrong field count, weeks
out of 0..16. Loader report: total/loaded/skipped-with-reasons.

**Solution outline:** getline loop; istringstream; classify each line;
counters; report.

**Test cases (design trace):** clean file; one blank + one out-of-range
line; header-only; empty file → all four reports distinct.

**Extension:** strict mode — any skip aborts the load (contrast
lenient; when is each right?).

---

## PF-CS-082 · Sensor Log to Summary Report (design-level)

**Expected concepts:** two-file pipelines, fatal-vs-data errors (PF-15.1).

**Common incorrect approaches:** writing the summary before checking
the input opened; dividing by zero valid-count on empty input; printing
errors into the output FILE (mixing channels).

**Discussion points:** Fatal: cannot open input (report to stderr/
console, no summary). Data-quality: bad lines counted, pipeline
continues. Zero valid: summary says so — never a NaN. Output created
even for zero records (a report that says "no data" is a report).

**Solution outline:** open input (fatal check) → read/validate/count →
min/max/mean → open output → write aligned report.

**Test cases (design trace):** good file → correct stats; missing
file → fatal, no summary.txt; all-bad lines → "no valid records"
summary.

**Extension:** timestamp gaps detection — monotonicity check.

---

## PF-CS-083 · The Deduplicating Saver (design-level)

**Expected concepts:** seen-structures, order preservation, case policy
(PF-15.1, PF-11.2).

**Common incorrect approaches:** case-insensitive compare without
saying which spelling is KEPT (policy hole); O(n²) accepted silently —
at 500 fine, say why fine (scale talk).

**Discussion points:** Keep-first preserves input order. Case policy:
normalize to lower for comparison, keep the FIRST spelling seen (or
normalize output — pick one, print it in the report). Counts: in, kept,
dropped.

**Solution outline:** vector<string> kept; for each email: lowered
lookup; if absent push + write; count drops.

**Test cases (design trace):** duplicates dropped; case-variants per
policy; empty file → 0/0/0.

**Extension:** sorted-output mode — second file, stable dedup.

---

## PF-CS-084 · The Rolling Grade Book (design-level)

**Expected concepts:** append vs read modes, reader-side aggregation
(PF-15.1).

**Common incorrect approaches:** opening for write and truncating
history (the classic); writing aggregates into the file (mixing raw and
derived data).

**Discussion points:** ios::app creates-or-continues — check the open
verdict. REPORT aggregates at read time: file stays raw; format never
changes. Widely-varying scores: policy question (flag volatility? just
average?) — the spec says average; the discussion names the
alternative.

**Solution outline:** APPEND: ofstream app; REPORT: read all lines,
map name → (sum, count), print averages.

**Test cases (design trace):** append twice, report sees both; report
on missing file → clean message; same student 3 weeks → one averaged
line.

**Extension:** per-week class average line embedded in report —
derived data stays OUT of the file.

---

## PF-CS-085 · Retry-Safe Config Loader (design-level)

**Expected concepts:** layered fallbacks, boot logging (PF-15.2).

**Common incorrect approaches:** one big try/fail (no layering);
silent defaults (new install looks "loaded"); validating presence but
not value legality (volume=banana accepted).

**Discussion points:** Three layers: file-exists → key-present →
value-valid; each logs. Boot log for a new install: every default
fired — the log IS the installation receipt. Corrupt-but-present is
the sneaky case: parse, then range-check.

**Solution outline:** for each key: try file value; validate; else
default + log.

**Test cases (design trace):** missing file → 3 defaults; partial →
1 default; corrupt volume → default + warning; full valid → no log
lines except "config loaded".

**Extension:** write-back: save effective config on first boot —
self-healing installation.

---

## PF-CS-086 · The Error-Message Designer (design-level)

**Expected concepts:** message engineering, exit-code discipline
(PF-15.2, PF-6.1).

**Common incorrect approaches:** bare `Error` (unfixable by users);
line numbers omitted (find the needle); jargon (`istringstream failed
state`).

**Discussion points:** Message = what + where + what-was-found. Table:
cannot open (fatal, exit 1-usage/2-data), empty file, bad line N
(show content), out-of-range score line N, duplicate student line N.
Recoverable = warn+continue; structural = stop. Exit codes let shell
scripts branch — the discipline table is the deliverable.

**Solution outline:** message table + code map + one paragraph on
recoverability.

**Test cases (design trace):** each failure mode → exact message
drafted; reviewed against the ≤80-char, no-jargon constraints.

**Extension:** locale/audience variants (operator vs end-user
messages) — one error, two renderings.

---

## PF-CS-087 · Transaction Log Replay (design-level)

**Expected concepts:** sequential replay, halt-vs-continue anomalies,
audit trails (PF-15.1, PF-14.2).

**Common incorrect approaches:** sorting the log first (replay is
order-faithful!); treating overdraft as malformed (different categories:
data vs policy); no running-balance column (the trail is the point).

**Discussion points:** Order matters absolutely — each verdict depends
on history. Halt-worthy vs continue-worthy is POLICY: overdraft =
guard-and-skip (balance untouched) or halt (audit stops)? Defend one.
Malformed = skip-and-note. Final verdict: start, end, applied, skipped.

**Solution outline:** read line → parse → classify → apply-or-note →
append trail row (line, action, amount, balance-after or reason).

**Test cases (design trace):** clean sequence → growing balance;
overdraft mid-way → policy verdict + trail; malformed line → noted;
verdict line arithmetic checks out.

**Extension:** hash-chain the trail (each row hashes the previous) —
tamper-evidence teaser.

---

## PF-CS-088 · Multi-File Merger with Cross-Checks (design-level)

**Expected concepts:** key-based merge, conflict taxonomy, report
arithmetic (PF-15.1, PF-14.2).

**Common incorrect approaches:** no conflict detection (silently
keeping A); buckets not summing to union (lost records); assuming both
files sorted.

**Discussion points:** Index B by id (array of ids at this scale) while
streaming A. Buckets: kept-A, kept-B(only-in-B), conflict, identical
(new bucket — same id AND same data is NOT a conflict). The sum rule:
keptA + onlyB + conflicts + identical = union size. Identical inputs →
all identical-bucket, zero conflicts.

**Solution outline:** read A → read B, classify per id → write union
per policy (A-wins) → report counts.

**Test cases (design trace):** disjoint ids; overlapping-identical;
overlapping-different (conflict); mixed → four counters reconcile.

**Extension:** three-way merge (base + two branches) — the git
problem, sketched.

---

## PF-CS-089 · The CLI Calculator Object

**Expected concepts:** encapsulation, single-writer state, rejection
semantics (PF-16.1).

**Common incorrect approaches:** public accumulator ("flexible" =
corruptible); apply() printing errors (policy theft); allowing /0 to
zero the accumulator silently.

**Discussion points:** Private accumulator + apply(op, operand) →
bool: the ONLY writers are the methods. Rejected op: false + state
untouched — the invariant. value() is the sole reader. Why private:
external code cannot bypass the /0 guard — L31's thesis in miniature.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-089 — calculator class with guarded state
#include <iostream>

class Calculator
{
public:
    void reset()
    {
        acc_ = 0.0;
    }
    bool apply(char op, double operand)
    {
        switch (op)
        {
        case '+': acc_ += operand; return true;
        case '-': acc_ -= operand; return true;
        case '*': acc_ *= operand; return true;
        case '/':
            if (operand == 0.0)
                return false;
            acc_ /= operand;
            return true;
        default:
            return false;
        }
    }
    double value() const
    {
        return acc_;
    }

private:
    double acc_{0.0};
};

int main()
{
    Calculator c;
    std::cout << c.apply('+', 10) << ' ' << c.value() << '\n';   // 1 10
    std::cout << c.apply('*', 3) << ' ' << c.value() << '\n';    // 1 30
    std::cout << c.apply('/', 0) << ' ' << c.value() << '\n';    // 0 30
    std::cout << c.apply('%', 5) << ' ' << c.value() << '\n';    // 0 30
    c.reset();
    std::cout << c.value() << '\n';                              // 0
    return 0;
}
```

**Test cases (verified):** as the inline comments — rejections leave
30 untouched; reset returns to 0.

**Extension:** operation history (vector<char, double>) — undo via
inverse ops.

---

## PF-CS-090 · Bank Account Invariants

**Expected concepts:** invariants, minimal attack surface, rejection
without partial state (PF-16.1).

**Common incorrect approaches:** deposit(−5) "reduces balance" (sign
chaos); withdraw allowed to go negative "temporarily"; a public cents_
field "just for the report".

**Discussion points:** Invariant: cents ≥ 0 after EVERY method. Two
doors (deposit/withdraw) both validate amount > 0 AND sufficiency.
Partial application forbidden: reject before touching state. What
invariant buys: tests assert it after every call — comments don't
compile into guarantees.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-090 — account with enforced invariant
#include <iostream>

class Account
{
public:
    bool deposit(long long amount)
    {
        if (amount <= 0)
            return false;
        cents_ += amount;
        return true;
    }
    bool withdraw(long long amount)
    {
        if (amount <= 0 || amount > cents_)
            return false;
        cents_ -= amount;
        return true;
    }
    long long balance() const
    {
        return cents_;
    }

private:
    long long cents_{0};
};

int main()
{
    Account a;
    std::cout << a.deposit(500) << ' ' << a.balance() << '\n';   // 1 500
    std::cout << a.deposit(-5) << ' ' << a.balance() << '\n';    // 0 500
    std::cout << a.withdraw(900) << ' ' << a.balance() << '\n';  // 0 500
    std::cout << a.withdraw(200) << ' ' << a.balance() << '\n';  // 1 300
    return 0;
}
```

**Test cases (verified):** as inline comments — invariant cents ≥ 0
held through every rejection.

**Extension:** transaction fee policy (withdraw costs 5) — invariant
interacts with policy; where's the check?

---

## PF-CS-091 · Playlist with History (design-level)

**Expected concepts:** single-writer discipline, wrap logic, empty-state
contracts (PF-16.1).

**Common incorrect approaches:** add() resetting the index (user loses
their place); next() on empty playlist indexing [0]; current() as
mutable (a reader must be const).

**Discussion points:** State: tracks + index; only next() writes the
index (single-writer). next() wraps: (i+1)%size. Empty: current()
reports explicitly ("no tracks") — never index. add-duplicate: reject
(consistent with PF-E-139).

**Solution outline:** methods add/next/current; verdict table; wrap
trace.

**Test cases (design trace):** add A,B,C; next thrice → A,B,C; next →
A (wrap); current on empty → explicit report; duplicate add rejected.

**Extension:** previous() — bidirectional wrap; index arithmetic
((i−1+size)%size).

---

## PF-CS-092 · The Thermometer Class Ladder (design-level)

**Expected concepts:** one-internal-truth, boundary validation,
conversion rounding (PF-16.1).

**Common incorrect approaches:** three independent fields C/F/K
(desynchronization!); validation only in the C setter (F and K doors
skip it); 1-dp rounding stored (precision lost per write).

**Discussion points:** Store celsius only; F/K setters convert at the
door then call the C path — one validation point. F→C→F round trip at
full precision is exact; DISPLAY rounding is presentation, not state.
Absolute-zero check lives in the single C door.

**Solution outline:** setCelsius validated; setF/setK convert-and-
delegate; three const accessors convert outward.

**Test cases (design trace):** setF(212) → C 100; setK(0) → rejected
(−273.15 boundary!); setF(−459.67) → exactly −273.15 → accepted;
setF(−500) → rejected.

**Extension:** temperature *scale* enum parameter — one setter,
unit-tagged.

---

## PF-CS-093 · Composing a Garage (Has-A) (design-level)

**Expected concepts:** composition, interface-only access, empty-slot
handling (PF-16.2).

**Common incorrect approaches:** Garage reading car.km_ directly
(friend-style reach-in — breaks the pattern being taught); treating
empty slots as km-0 Cars (phantom objects); index-by-slot without
emptiness checks.

**Discussion points:** Garage HAS Cars; uses public methods only:
park, drive, km(). totalKm() skips empty slots (or treats as 0 —
equivalent here, but skipping documents intent). Why interface-only:
Car can change its internals; Garage unaffected — the maintainability
argument.

**Solution outline:** Car{model, km_, drive, km}; Garage{Car slots[5];
bool used[5]; park/drive/totalKm}.

**Test cases (design trace):** park 2 cars, drive one, totalKm = that
one's km; totalKm with all empty → 0 (valid).

**Extension:** removeCar(slot) — what happens to the Car object?
(lifetime discussion seed for L27 connections).

---

## PF-CS-094 · The Registry Class (design-level)

**Expected concepts:** aggregation, const-correctness, uniqueness
enforcement (PF-16.2).

**Common incorrect approaches:** findById returning a *copy* silently
(caller edits the copy, expects persistence); averageAge dividing by
zero on empty; non-const methods for pure queries.

**Discussion points:** Uniqueness lives in add() — no other door
inserts. findById/find/averageAge are const (promise: no mutation).
Failure verdicts: add-duplicate, remove-missing, find-missing, empty-
average (define!). Class guarantees uniqueness "by construction" —
plain arrays can't promise anything.

**Solution outline:** vector<Member>; add (check id), remove, findById
(const), averageAge (const, empty verdict).

**Test cases (design trace):** add/add-dup/remove/remove-missing/find
hit+miss/average empty + populated.

**Extension:** update-age(id, newAge) — which existing validations
apply? (existence; range.)

---

## PF-CS-095 · Files to Objects: Student Roster (design-level)

**Expected concepts:** interface-first design, file-to-class seam,
dual failure channels (PF-16.3, PF-15.1).

**Common incorrect approaches:** designing load() around the file
format first (format leaks into the interface); one bool return
(cannot distinguish missing-file from garbage-data).

**Discussion points:** Interface first: what does a *user* of Roster
want? load(path) → code (0 ok, 1 missing, 2 bad-data), report() const.
The caller distinguishes failures without knowing the format. load
uses the same validated intake as manual add: ONE door per rule.

**Solution outline:** class Roster{load, size, report, add}; load
parses with CS-056-style robustness; returns codes; report prints
ranked stats.

**Test cases (design trace):** good file → 0 + report; missing → 1;
garbage line → 2 (with line number in the message); empty → 0 with
empty report.

**Extension:** save() — the roundtrip test (CS-102's idea, born
here).

---

## PF-CS-096 · The Undo Stack Text Editor (design-level)

**Expected concepts:** history models, state vs inverse operations
(PF-16.1, PF-14.1).

**Common incorrect approaches:** undo with empty history crashing;
saving history only on SOME edit types (insert undo works, delete
doesn't); k-level undo via k full snapshots (memory × k).

**Discussion points:** One-level: save whole string before each edit —
memory-heavy, trivially correct. Inverse ops: store (pos, deleted-text)
or (pos, inserted-len) — memory-cheap, subtler code. The trade-off IS
the case. k-level: a stack of records; one-level = depth-1 stack.
Empty history: undo() reports "nothing to undo" — state unchanged.

**Solution outline:** class Editor{string s; string backup; bool
canUndo; insert/delete_/undo}; then the k-level sketch.

**Test cases (design trace):** insert, insert, undo → second insert
gone; delete then undo → restored; undo on fresh editor → report;
k=3 with 5 edits → 3 undos then "nothing".

**Extension:** redo (the inverse of the inverse) — two-stack model.

---

## PF-CS-097 · Vending Machine State Machine (design-level)

**Expected concepts:** explicit states, guarded transitions (PF-16.2).

**Common incorrect approaches:** select() dispensing without checking
payment total (state not consulted); refund() in IDLE returning
"refunded 0" silently (policy: report-nothing-or-message — decide);
no state member at all (flags scattered — same thing, worse).

**Discussion points:** States: IDLE → PAID → (DISPENSED → IDLE).
Every method FIRST consults the state member: wrong-state → reject
with reason, state unchanged. The state variable IS the guard —
invalid sequences become unrepresentable actions. Trace the happy
path and three illegal paths.

**Solution outline:** enum-ish int state; insertCoin adds credit
(moves IDLE→PAID at ≥ price... overpay stays PAID with credit);
select only in PAID with sufficient credit; refund anywhere with
credit>0.

**Test cases (design trace):** coins then select → dispensed + change;
select before coins → rejected; double-select → second rejected
(state now DISPENSED/IDLE); refund mid-PAID → credit returned.

**Extension:** two item types with different prices — does the state
machine change shape? (No — the guard logic generalizes.)

---

## PF-CS-098 · Grade Analyzer with Tiered Reports (design-level)

**Expected concepts:** interface-first synthesis, const/mutate split,
load semantics (PF-16.3).

**Common incorrect approaches:** band thresholds inside the print
function (policy scattered — put them in ONE named place); load
appending on second call (silent duplication); histogram without the
band ladder reuse (CS-005 echo).

**Discussion points:** Interface BEFORE implementation: load(path) →
code; bandCounts() const → array; extremes() const → pair; histogram()
const → print. Only load mutates. Second load: REPLACE (document:
fresh object per file) — or append; both defensible, silence is not.
Reuse CS-005's ladder verbatim — policy centralization.

**Solution outline:** class GradeBook with the four methods; report
composition; the replace-vs-append contract comment.

**Test cases (design trace):** load file → band counts match manual
tally; extremes with ties → policy; empty file → zeroed report
(valid); second load replaces.

**Extension:** export report to file — which methods change
signature? (None: a new export(path) const.)

---

## PF-CS-099 · The Persisted Inventory (design-level)

**Expected concepts:** format ownership inside the class, all-or-nothing
load (PF-16.3, PF-15.1).

**Common incorrect approaches:** parsing knowledge duplicated in main
(two sources of truth); load trusting qty fields blindly (negative
stock enters the system); save() appending (file grows forever).

**Discussion points:** save/load are the ONLY format code — change the
format in one place. Foreign/garbage lines: rejected with reason;
all-or-nothing commit (validate whole file into a temp vector, then
swap). save truncates deliberately — contract comment says so. The
roundtrip test: save → clear → load → deep-equal.

**Solution outline:** class Inventory{vector<Item>; save; load};
format: `sku qty` lines; validation mirrors add()'s.

**Test cases (design trace):** roundtrip equality; negative qty in
file → rejected wholesale; empty file → empty inventory (valid);
foreign line → load fails with line number.

**Extension:** format version tag on line 1 — migration story
sketched.

---

## PF-CS-100 · The Checkout Queue Simulator (design-level)

**Expected concepts:** event-time simulation, model assumptions
(PF-16.3, PF-6.3).

**Common incorrect approaches:** simulating tick-by-tick (works, but
the max/prev-finish insight is cleaner); tie rule unstated (arrival ==
previous finish → wait 0 — define!); averaging waits without the
customer count guard.

**Discussion points:** wait_i = start_i − arrival_i; start_i =
max(arrival_i, finish_{i−1}). One running "cashier-free-at" variable
replaces the queue at this scale — say WHY (FIFO order in the file IS
the queue). Assumptions to name: no balking, no interruption, FIFO,
atomic service. The model-vs-reality gap is the discussion.

**Solution outline:** read (arrival, service) pairs; track
finishTime; per customer compute start/wait; accumulate.

**Test cases (design trace):** idle-start customer → wait 0;
overlapping arrivals → queueing; gap in arrivals → cashier idles
(no effect on waits); average = Σwait/n.

**Extension:** two cashiers (pick the earlier-free) — the model
grows a min().

---

## PF-CS-101 · The Audit-Safe Ledger Class (design-level)

**Expected concepts:** dual consistent state, audit semantics (PF-16.1).

**Common incorrect approaches:** public history vector (rejections
could be appended by callers — audit poisoned); balance derived from
history (recompute cost) OR history derived from balance (order lost)
— the design must pick and justify; rejected ops appended (the audit
then shows money that never moved).

**Discussion points:** Two states (cents_, history_) grow together,
both private, both touched by deposit/withdraw ONLY. Rejected op =
zero footprint: the audit shows real money exclusively. net() from
history vs balance() from cents_ — if they ever disagree, a bug
exists: a built-in consistency check (assert-style in tests).

**Solution outline:** class Ledger{deposit, withdraw (both append-on-
success), balance, audit (trail/net/rejected-count)}.

**Test cases (design trace):** mixed ops → trail = successes only;
net(from history) == balance; rejected count reported separately.

**Extension:** timestamps in history — replay CS-087's trail FROM
the ledger (two cases shake hands).

---

## PF-CS-102 · Weather Station Class + File Roundtrip (design-level)

**Expected concepts:** roundtrip invariants, all-or-nothing load
(PF-16.3, PF-15.1).

**Common incorrect approaches:** partial load on error (half data,
no report); summary() after load differing (format precision loss —
save at full precision!); range validation only at add(), not load.

**Discussion points:** The test: summary before save == summary after
load — if not, the format lost information (1-dp save is the classic
bug). Out-of-range 200 in file: all-or-nothing (validate into temp,
commit once). Format is the class's private affair (CS-099 echo).

**Solution outline:** class WeatherLog{add(validated), summary,
save, load(all-or-nothing)}; roundtrip test as the acceptance
criterion.

**Test cases (design trace):** add 5 → save → clear → load → summary
identical; file with 200 → whole load rejected; empty file → empty
log (valid).

**Extension:** growth: load-then-add-then-save (merge semantics) —
what's the policy?

---

## PF-CS-103 · The Two-Class Report Pipeline (design-level)

**Expected concepts:** single-responsibility classes, seam contracts
(PF-16.2, PF-16.3).

**Common incorrect approaches:** one god-class (parse+stats tangled);
I/O types crossing the seam (parser hands over an ifstream — stats
now file-dependent); validation errors surfacing in the stats class.

**Discussion points:** Parser knows files; Stats knows numbers. Hand-
off: vector<Sale> (plain data). Reusability test: can Stats run on
hand-built data? If yes, the seam is right. Validation report lives
with the parser (it has the context: line numbers).

**Solution outline:** struct Sale{item, qty, minute}; TicketParser::
load(path) → (vector<Sale>, report); SalesStats::analyze(vector) →
report; main glues.

**Test cases (design trace):** good file → both reports; corrupt
lines → parser's report, stats unaffected; Stats on manual vector →
works (the seam test).

**Extension:** third consumer (RevenueByItem) — prove the seam
without touching the parser.

---

## PF-CS-104 · The Integrity-Checked Config (design-level)

**Expected concepts:** structure-before-values validation, strictness
policies (PF-15.2).

**Common incorrect approaches:** validating values before structure
(error messages reference keys that may be duplicates); reporting all
errors (spec: FIRST error, line number, refuse); mixing this with
CS-085's lenient mode without stating the audience difference.

**Discussion points:** Pass 1: exactly 5 keys, fixed order, no
duplicates → first violation = reject with line N. Pass 2: value
legality. Strict suits machine-written files (drift = bug); lenient
(CS-085) suits human-edited ones — same data, two policies, different
audiences. Duplicate key trace: line of the second occurrence
reported.

**Solution outline:** structural pass → value pass → accept; error
= first only.

**Test cases (design trace):** perfect file → accept; missing key 3
→ error at first line that breaks order; duplicate → error at dup
line; bad value after good structure → value error.

**Extension:** configurable strictness flag — one loader, two
personalities (does that dilute the design? discuss).

---

## PF-CS-105 · Student Records: The Composite Challenge (design-level)

**Expected concepts:** nested records, layered validation, orphan
references (PF-16.3, PF-14.2).

**Common incorrect approaches:** loading modules before students
(orphan ids); Student allowing duplicate module codes (validation
layer skipped); one flat file format for two entity types (format
ambiguity).

**Discussion points:** Three layers, three contracts: Module (marks
0..100), Student (unique module codes; owns its modules), the file
layer (referential integrity: every module line's id must exist).
Two-pass load: students first, modules second — or single-pass with
forward references deferred (harder). "Composite" = struct-in-class-
in-file, each with its own rules.

**Solution outline:** struct Module; class Student{addModule
validated, average}; vector<Student> loader with id-checking; format
`S name id` + `M id code marks`.

**Test cases (design trace):** clean nested file → averages; module
before its student → verdict per chosen policy; duplicate module code
in one student → rejected; marks 101 → rejected at Student's door.

**Extension:** delete a student — what happens to their modules?
(ownership cascade discussion).

---

## PF-CS-106 · The Exam Seating Optimizer (design-level)

**Expected concepts:** greedy with feasibility checks, invariant
reporting (PF-16.3, PF-6.2).

**Common incorrect approaches:** row-major fill with no adjacency
check (same-section neighbors everywhere); declaring impossibility
without the counting argument; silently dropping leftovers.

**Discussion points:** Feasibility: a section with more students than
ceil(cells/2) can never avoid adjacency (pigeonhole on the checker
pattern). Greedy: place largest-remaining section first, alternate;
snake rows to avoid vertical repeats. Leftovers: reported, never
dropped. Trace 2×4, A:5 B:3 → pigeonhole: 5 > ceil(8/2)=4 →
impossible → leftovers reported (the spec's "when possible" made
precise).

**Solution outline:** feasibility check → greedy placement with
adjacency validation → leftover report.

**Test cases (design trace):** feasible case → clean grid; A:5 B:3
→ impossibility verdict; exact-alternation case → perfect grid;
single section → all adjacency unavoidable (reported).

**Extension:** two-hall split to make an infeasible case feasible —
optimization teaser.

---

## PF-CS-107 · The Library Fine Calculator (design-level)

**Expected concepts:** rule ordering, itemized computation, boundary
dates (PF-16.3, PF-4.2).

**Common incorrect approaches:** applying caps before computing
per-day charges (undercharges); closures freezing time instead of
removing days; undocumented rule precedence (two rules collide →
arbitrary result).

**Discussion points:** Order: (1) count chargeable days (late days
minus closures), (2) per-day charge × rate (×2 if reserved), (3) cap
at replacement cost, (4) waiver check. The receipt itemizes each
step — no silent arithmetic. Boundary: returned ON due date = 0 days.
Two caps interacting: the LOWER binds (min semantics) — name the
rule, don't improvise.

**Solution outline:** date diff (within one year; L29 file or
hard-coded day counts) → filters → charge → caps → itemized receipt.

**Test cases (design trace):** on-time → 0; 5 days, standard →
5×rate; reserved → doubled; closure inside the window → days reduced;
fine > replacement → capped, receipt shows the cap firing.

**Extension:** per-tier rates by book category — the rule table
grows; precedence still first.

---

## PF-CS-108 · The Capstone Mini-System (design-level)

**Expected concepts:** multi-class ownership, boundary contracts,
system-level failure policy (PF-16.3).

**Common incorrect approaches:** classes sharing structs by reference
into each other's internals (no boundaries); receipts written per sale
with no shift summary; money in double at the LAST layer after
promising paisa (drift); no shutdown path (file left unwritten).

**Discussion points:** Ownership: Menu owns items/prices; Order owns
quantities; Register owns money + receipt files. Boundaries:
Menu→Order = price lookup (const), Order→Register = charged totals.
Every input path has a failure verdict (the CS-080 pattern,
systemized). Shift report = aggregation of receipts (CS-087's trail,
born from files). The "revisit first" question: typically the
order-entry loop (users fumble codes) — the design that anticipates
user testing wins.

**Solution outline:** three class sketches + session loop + file
formats + the failure-policy table; the revisit-first paragraph.

**Test cases (design trace):** full session script: browse, order,
pay, edge inputs (qty 0, unknown item, cancel), shutdown → receipts
file valid, shift report reconciles with receipts.

**Extension:** a second register (two files) + end-of-day merge —
CS-088 returns at system scale.
