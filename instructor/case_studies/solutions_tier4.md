# Tier 4 Instructor Companion — CS-061–CS-080

Per case: expected concepts · common incorrect approaches · discussion
points · solution outline · worked solution · test cases · extension.
Worked solutions marked **compiled ✓** were built with the course
contract and executed.

---

## PF-CS-061 · The Off-by-One Autopsy

**Expected concepts:** binary search invariant, boundary disciplines
(PF-12.1, PF-9.3).

**Common incorrect approaches:** "fix" by clamping mid (masks the
invariant break); changing two things at once (no causal attribution);
never tracing.

**Discussion points:** Two coherent disciplines: [low, high] inclusive
with `low <= high`, `high = mid − 1`; OR [low, high) with `low < high`,
`high = mid`. Mixing them is the bug. Trace discipline: table with
low/high/mid/verdict per round — the audit tool.

**Solution outline:** buggy trace on [2,4,6,8], key 8, `high = n`:
low=0, high=4, mid=2 (a[2]=6<8) → low=3; mid=3 (a[3]=8) found — wait,
that *finds* it. Choose the key 9 (absent): low=0,high=4,mid=2→low=3;
mid=3(8<9)→low=4; mid=4 → **a[4] out of bounds read** (garbage) — may
loop or crash. The defect: indexing n.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-061 — corrected binary search (inclusive discipline)
#include <iostream>

int binarySearch(const int* a, int n, int key)
{
    int low{0}, high{n - 1};
    while (low <= high)
    {
        int mid{low + (high - low) / 2};
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[4]{2, 4, 6, 8};
    for (int k : {2, 8, 9, 1})
        std::cout << k << " -> index " << binarySearch(a, 4, k) << '\n';
    return 0;
}
```

**Test cases (verified):** 2→0, 8→3, 9→−1, 1→−1; empty array n=0 → −1
(no dereference).

**Extension:** count comparisons for present/absent keys; compare with
CS-060's counters.

---

## PF-CS-062 · Pointer Cipher Walk

**Expected concepts:** pointer arithmetic, '\0' terminator contract,
one-past-the-end (PF-13.1).

**Common incorrect approaches:** `while (p != nullptr)` — never true at
end (arrays decay to addresses, not null); dereferencing the
one-past-end pointer; shifting non-letters (constraints say letters,
but the guard is the teaching point).

**Discussion points:** p++ advances one element (char = 1 byte here);
`*p != '\0'` is the contract — the terminator is the sentinel.
One-past-the-end pointer is legal to *hold*, illegal to *dereference*.
Wrap: 'Z'+1 → 'A' via if, not arithmetic luck.

**Solution outline:** two walks: print chars; print shifted with
wrap. `for (const char* p = s; *p != '\0'; ++p)`.

**Worked solution (compiled ✓):**

```cpp
// PF-CS-062 — pointer walk + Caesar shift
#include <iostream>

int main()
{
    char word[41]{};
    std::cin >> word;

    for (const char* p = word; *p != '\0'; ++p)
        std::cout << *p << '\n';

    for (const char* p = word; *p != '\0'; ++p)
    {
        char c{*p};
        if (c == 'Z')
            c = 'A';
        else
            c = static_cast<char>(c + 1);
        std::cout << c;
    }
    std::cout << '\n';
    return 0;
}
```

**Test cases (verified):** "CAT" → vertical C,A,T then `DBU`; "Z" →
vertical Z then `A`; "XYZ" → `YZA` (double wrap ✓).

**Extension:** shift by k with modulo ('A' + (c−'A'+k)%26) —
generalized cipher, same walk.

---

## PF-CS-063 · The Alias Explosion (design-level)

**Expected concepts:** aliasing model, reference vs pointer capabilities
(PF-13.2).

**Common incorrect approaches:** thinking r = y reseats the reference
(it assigns THROUGH the alias); assuming *p and r "interfere".

**Discussion points:** Three names, one object. Sequence prediction:
x=5; r=9; *p=11 → all read 11. Illegal for r: re-binding; illegal for
p: nothing (except dereferencing null — a *capability* difference).
Mental model: reference = a second label glued on the box; pointer = a
slip of paper with the box's address.

**Solution outline:** five mixed mutations; predict-then-run; the
verdict table.

**Test cases (behavioral):** the sequence ends with x==r==*p==11;
&p==&x (aliases share address).

**Extension:** const int& cr = x — read-only alias; what breaks?

---

## PF-CS-064 · Out-Parameter vs Return (design-level)

**Expected concepts:** failure-interface design, call-site visibility
(PF-13.3, PF-8.1).

**Common incorrect approaches:** double parse(const string&) returning
0.0 on failure (0.0 is legal data!); bool return + silent out-param
untouched convention violated (must document).

**Discussion points:** The reader test: `double v = parse(s);` — did
*you* remember it can fail? vs `if (parse(s, v)) ...` — failure
acknowledged by syntax. Design principle: make failure *unignorable*
when failure is common/normal; sentinel only when failure is truly
exceptional and a safe sentinel exists (there rarely is one).

**Solution outline:** both interfaces; same istringstream core;
behavior table for valid/garbage inputs.

**Test cases (behavioral):** "3.14" → 3.14, ok; "abc" → fail channel
fires; "" → fail; "3.14x" → stream reads 3.14 then trailing — policy
decision (strict = fail on trailing junk).

**Extension:** strict full-consumption parse — read a sentinel char
and require EOF.

---

## PF-CS-065 · The Dangling Return (design-level)

**Expected concepts:** automatic storage duration, dangling pointers,
ownership (PF-13.4).

**Common incorrect approaches:** "it printed 42 on my machine so it's
fine" (UB is not a verdict — it's roulette); fixing with static local
(thread-unsafe, shared-state surprise); returning new int (ownership
ambiguity — who deletes?).

**Discussion points:** v dies at the brace; the returned address points
into a recycled frame. Two clean fixes: return by value (copy; the
course default) and caller-supplied storage `void makeValue(int& out)`.
Static works but is a trap (second call overwrites). new/delete here is
ownership ceremony for nothing.

**Solution outline:** defect explained; both fixes coded; the
course-standard pick argued (value return).

**Test cases (behavioral):** fixed version: value usable, no UB;
static version demonstrates overwrite on second call (the trap made
visible).

**Extension:** struct return (two values) — value semantics scale.

---

## PF-CS-066 · Leak Hunter (design-level)

**Expected concepts:** ownership, exit paths, RAII (PF-14.1).

**Common incorrect approaches:** delete only on the happy path;
delete without [] on new[] (UB); "the OS reclaims it anyway" (true at
exit — irrelevant for a long-running loop).

**Discussion points:** Every exit path (return, break, exception —
exceptions are L30+ but name them) must free. One-owner rule. The
course answer: don't hand-manage — std::vector frees by scope
(RAII). The trace: 10⁶ iterations × 4 KB leaked = 4 GB — the service's
nightly death.

**Solution outline:** leak paths identified; fix A: delete[] on all
paths; fix B: std::vector<int> buf(1000) per iteration.

**Test cases (behavioral):** with fix B, no delete anywhere and no
leak by construction; fix A requires auditing every path — count
them (≥3).

**Extension:** a function with 5 returns — refactor to one exit vs
RAII, compare maintenance.

---

## PF-CS-067 · Grow-on-Demand Array (design-level)

**Expected concepts:** capacity vs size, geometric growth, amortized
cost (PF-14.1, PF-6.3).

**Common incorrect approaches:** growing by +10 (amortized O(n) per
push — the "wait, which is it?" in the hint resolves to: total copies
~n²/20 vs ~2n for doubling); forgetting to delete the old block (leak
per growth); copying with = on a pointer (shallow — here ints, fine;
flag for structs later).

**Discussion points:** Capacities 1,2,4,8,16,32 for 17 pushes; total
copies 1+2+4+8+16 = 31 ≈ 2n−1. Doubling: amortized O(1). +10: pushes
10,20,30... total copies ~n²/20 → amortized O(n). The trace IS the
proof. (std::vector does exactly this — now they know why.)

**Solution outline:** grow(): newCap = cap*2; allocate; copy; delete[]
old; cap = newCap. push(): if size==cap grow(); a[size++]=v.

**Test cases (design trace):** 17 pushes → cap 32, 31 copies total;
push after clear reuses capacity (size vs cap distinction).

**Extension:** shrink on pop when size < cap/4 (with hysteresis
discussion — why /4 not /2).

---

## PF-CS-068 · Struct Record Migration (design-level)

**Expected concepts:** struct as record unit, whole-record swaps (PF-14.2).

**Common incorrect approaches:** migrating only some fields (the
misalignment bug survives); copying field-by-field in the swap (verbose,
error-prone) instead of struct assignment.

**Discussion points:** One swap moves all fields: `Student t = a[i]; ...`
— the struct IS the unit. The bug class "sorted scores, scattered
names" becomes unrepresentable. Adding a field: one struct line vs
every parallel array + every swap site.

**Solution outline:** struct Student{string name; int id; double gpa;};
array<Student,5>; sort by gpa with record swaps.

**Test cases (design trace):** 5 records sorted by gpa desc; names
still paired with scores; tie → policy.

**Extension:** add section field — count the edit sites: 1.

---

## PF-CS-069 · Registry with Sentinel Search (design-level)

**Expected concepts:** find-or-(−1), verdict taxonomy, loop-as-dialogue
(PF-14.2).

**Common incorrect approaches:** findItem printing "not found" itself
(policy stolen from caller); qty allowed negative by a sloppy withdraw
path (invariant breach).

**Discussion points:** Verdicts: unknown SKU / insufficient / non-positive
amount — three messages, three counters maybe. Who validates: findItem
finds; the transaction loop decides. Final table = one loop after the
sentinel.

**Solution outline:** findItem → index or −1; loop reads sku, action,
amount until `q`; branches produce verdicts; final table prints.

**Test cases (design trace):** valid sale, unknown SKU, oversell,
amount 0, then `q` → 4 verdicts + table with untouched stock for
rejected ops.

**Extension:** receipt of all *rejected* transactions at the end (the
audit pattern from CS-087, mini version).

---

## PF-CS-070 · Top-K Report (design-level)

**Expected concepts:** selection vs sorting, cost crossover (PF-14.2,
PF-12.3).

**Common incorrect approaches:** sorting everything and slicing (fine!
but then the case is trivial — the discussion is *when* it's fine);
repeated max without removing the winner (same name k times).

**Discussion points:** Repeated extraction: k passes × O(n) = O(kn);
mark winners (swap-to-back or flag). Crossover: k≈n → sort O(n log n)
wins. Tie rule: earlier entry wins (stability again — CS-059 echo).

**Solution outline:** for round in 0..k−1: scan for max among
unmarked; record; mark.

**Test cases (design trace):** 8 records k=3 → correct podium; ties
at the podium boundary → earlier wins; k=n → same as full sort (argue).

**Extension:** streaming top-k with a "worst of the k" threshold —
one scan, O(nk) worst but O(n) typical.

---

## PF-CS-071 · Binary Search Contract Test (design-level)

**Expected concepts:** test-battery design, boundary stress (PF-12.1,
PF-6.1).

**Common incorrect approaches:** only happy paths; forgetting empty
(can crash before any logic runs); assuming duplicates "just work"
(returns *an* index — which one is unspecified!).

**Discussion points:** The battery: empty; singleton; first; last;
absent-below; absent-above; absent-middle; duplicates. Which catches
`low < high` vs `<=` confusion? Two-element absent tests: singleton
discipline breaks on the second element. Absent-below with the wrong
mid-update loops forever — the discriminator named.

**Solution outline:** table of 8 tests × expected result; run against
both the correct and the confused implementation — the confusion one
fails (or hangs) specifically on two-element/absent cases.

**Test cases (design trace):** enumerated in the table; duplicates
→ any valid index (document the contract).

**Extension:** property test: for ALL keys in range±5, verify found
implies a[key]==k — brute force the property.

---

## PF-CS-072 · Median Without Full Sort (design-level)

**Expected concepts:** copy-then-sort, even/odd medians, contract
rejection (PF-12.2, PF-7.2).

**Common incorrect approaches:** sorting the caller's array (side
effect!); even-n median with integer division (a[n/2−1]+a[n/2])/2 in
ints truncates .5; n==0 "handled" by returning 0.

**Discussion points:** Copy cost O(n) — acceptable; caller data is
sacred. Even median needs double math. Counting selection: values
0..100 → counting array finds the middle in O(range+n) — compare with
sort O(n log n): counting wins here BECAUSE range is bounded (the
constraint is the algorithm's license).

**Solution outline:** copy; sort copy; n odd → a[n/2]; even →
(a[n/2−1]+a[n/2])/2.0; n==0 → documented rejection.

**Test cases (design trace):** {1,3,2} → 2; {4,1,3,2} → 2.5; all-equal
→ that value; 0 rejected before touching anything.

**Extension:** median *without copying* by marking — is the
complication worth it? (No — discuss.)

---

## PF-CS-073 · The NullPointerException Class (design-level)

**Expected concepts:** pointer safety checklist, defense patterns
(PF-13.4).

**Common incorrect approaches:** checking `p != nullptr` *after*
dereferencing earlier in the function; setting p = nullptr BEFORE
delete (leak!); trusting initialization.

**Discussion points:** The checklist: (1) initialize at birth
(nullptr), (2) check before every dereference, (3) null immediately
after delete, (4) prefer references when "never null" is the contract,
(5) prefer stack/containers over new. Snippet 3 (may-never-set loop)
is the sneakiest — the check exists but on a garbage pointer.

**Solution outline:** three snippets rewritten; checklist as the
deliverable.

**Test cases (behavioral):** each snippet's defect demonstrated
safely (e.g., the check firing), then the fixed version's clean run.

**Extension:** wrap the pattern in a tiny "optional-like" struct
(hasValue + value) — proto-RAII.

---

## PF-CS-074 · Struct vs Parallel Arrays Benchmark (design-level)

**Expected concepts:** layout trade-off analysis (PF-14.2, PF-6.1).

**Common incorrect approaches:** declaring structs "always faster"
(the case is about *engineering*, not speed); forgetting the
human-factor axis (maintenance).

**Discussion points:** The matrix: sort-a-column (struct wins:
records move whole), update-one-record (struct: one indexed write),
add-a-field (struct: 1 edit; parallel: 4+ edits), pass-a-student
(struct: one argument). Verdict: struct for a beginner codebase —
speed differences are noise at course scale; correctness-by-design
is not.

**Solution outline:** the matrix filled with ✓/✗/notes + verdict
paragraph.

**Test cases:** n/a — analysis case; assessment via rubric
(plausibility of each cell).

**Extension:** when DO parallel arrays win? (SoA for vectorization —
name it, defer it.)

---

## PF-CS-075 · Two-Key Sort (design-level)

**Expected concepts:** composite comparators, transitivity (PF-12.2).

**Common incorrect approaches:** comparing name then, inside the
equality branch, comparing name again (wrong key); non-transitive
"priority" logic (a<b, b<c, but a!;<c) — corruption.

**Discussion points:** less(a,b) = name-first, score-tiebreak. The
comparator must be a strict weak ordering; for the course:
consistent, transitive, and a<b ⟺ !(b<a). Trace the tie case. Any
class sort + this comparator = sorted directory.

**Solution outline:** bool before(a,b){ if(name != ) return name<;
return score <; } + selection sort using before().

**Test cases (design trace):** ties by name resolved by score;
full-ties (same name+score) → order irrelevant (documents stability
non-requirement here).

**Extension:** reverse the secondary key only (name asc, score desc)
— comparator algebra.

---

## PF-CS-076 · The Cost Ladder (design-level)

**Expected concepts:** big-O cost models, amortization, data-dependent
algorithm choice (PF-12.3, PF-6.3).

**Common incorrect approaches:** declaring the hash-like counting array
the universal winner (the O(range) memory is the catch); ignoring
query count q in the total.

**Discussion points:** (10⁶, 1): linear O(n) once — sort's overhead
never amortizes. (10³, 10⁶): counting array O(1001 + 10⁶) ≈ O(q) —
wins big. (10⁶, 10⁶): sort-once O(n log n + q log n) ≈ 2×10⁷ vs
counting O(n+q)=2×10⁶ BUT range ≤1000 required — counting wins *if*
the data fits the license. The constraint IS the design input.

**Solution outline:** per-scenario arithmetic + winner table.

**Test cases:** the three scenarios as given; edge: q=0 (build cost
only — linear "wins" by default).

**Extension:** hybrid: counting for range ≤1000, sort-else — decision
code, not just prose.

---

## PF-CS-077 · Merge Sorted Queues (design-level)

**Expected concepts:** two-index merge, tail handling (PF-12.2).

**Common incorrect approaches:** restarting scans per element (O(nm));
forgetting the tail copy (last elements vanish); tie rule unstated
(spec: A wins ties — state it in code comment).

**Discussion points:** Invariant: C[0..k) holds the k smallest of
A∪B. Each comparison emits exactly one → ≤ m+n−1 comparisons from
comparisons; tails copy free. Trace: A=[1,4,9], B=[2,3,10] → 1,2,3,4,9,10.

**Solution outline:** i,j,k walkers; take smaller; advance that side;
copy remainders.

**Test cases (design trace):** the spec trace; one empty array →
copy the other; all-equal arrays → A-wins-ties yields A-elements first.

**Extension:** merge k sorted lists pairwise vs tournament — cost
comparison ( teaser only).

---

## PF-CS-078 · The Nightly Settlement File (design-level)

**Expected concepts:** file pipeline, skip taxonomy, closing reports
(PF-15.1).

**Common incorrect approaches:** exiting on the first malformed line
(one bad line kills the batch — wrong for settlement); allowing
negative balance transiently then "fixing later" (invariant breach);
not distinguishing "cannot open" (fatal) from "bad line" (data note).

**Discussion points:** getline+istringstream per line; verdicts:
applied / overdraft-skipped / malformed-skipped / invalid-amount-skipped.
Counters per verdict; closing report = balances + counters. Empty file
→ zero-everything report (valid!). The invariant: balance ≥ 0 after
every line.

**Solution outline:** open-fail → fatal message; loop: parse, classify,
apply-or-skip; report.

**Test cases (design trace):** mixed file with one of each verdict;
empty file; missing file → fatal + exit 2 (ties to CS-086's codes).

**Extension:** daily summary appended to a *second* file (audit
trail).

---

## PF-CS-079 · Configuration with Defaults (design-level)

**Expected concepts:** last-write-wins, defaults-at-print, warning
policy (PF-15.1).

**Common incorrect approaches:** applying defaults during the read
(then a later override looks like it "didn't take"); treating unknown
keys as fatal (too strict for humans editing files).

**Discussion points:** Defaults print AFTER the read completes —
because any line could still override. Unknown key: warn, continue
(human-friendly policy; contrast CS-104's strict mode). Trace: file
missing volume → `volume=80 (default)`.

**Solution outline:** seen-flags per key; store values; after EOF,
print all keys with default markers.

**Test cases (design trace):** full file → no defaults; missing one →
default line; duplicate key → last wins + warning; unknown key →
warning.

**Extension:** type-validate values (volume must parse as int) —
merge with CS-056 parsing.

---

## PF-CS-080 · The Self-Validating Form (design-level)

**Expected concepts:** re-prompt loops, EOF as a control path, rejection
analytics (PF-15.2).

**Common incorrect approaches:** unbounded re-prompt with no EOF check
(infinite loop when input closes — piped tests hang); counting
rejections per *submission* not per *field*; validating after reading
all fields (late errors annoy users — here, order matters).

**Discussion points:** Exit conditions: valid OR stream dead — two
doors, one loop. cin.clear()+ignore on bad reads (L30 preview; here,
name the mechanism). Per-field counters feed the UI designer: WHERE
does the form fail? EOF: graceful stop with partial-report.

**Solution outline:** per field: loop { prompt; read; if(!stream)
EOF-path; if(valid) break; ++rejects[field]; } — then summary.

**Test cases (design trace):** clean entry; age 200 then 30 (1
rejection); GPA "abc" then 3.2; EOF mid-form → graceful partial
summary.

**Extension:** form *templates* — field specs in an array driving one
generic loop (data-driven validation).
