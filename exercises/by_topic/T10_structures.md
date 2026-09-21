# T10 · Structures

Covers: `struct` definition, initialization, member access, nested
structs, structs with functions (pass by value / `const&` / `&`),
vectors of records, records with arrays inside. Lectures L28.
Outcomes PF-14.3, PF-14.4.

10 exercises · ladder 🟢 → 🔴.

---

### PF-E-112 · Define and Print a Point
**Difficulty:** Beginner · **Lecture:** L28 · **Outcomes:** PF-14.3
**Prerequisites:** E-066
**Problem:** Define `struct Point { double x; double y; };`. Create two points (one brace-initialized, one member-assigned), print both as `(x, y)` with 2 decimals, and print their midpoint.
**Input:** none · **Output:** three points.
**Sample:** — → `(1.00, 2.00)` / `(3.00, 4.00)` / `midpoint (2.00, 3.00)`
**Hints:** midpoint = average of coordinates — member access chains.

### PF-E-113 · Student Record Basics
**Difficulty:** Beginner · **Lecture:** L28 · **Outcomes:** PF-14.3, PF-14.4
**Prerequisites:** E-112
**Problem:** Define `struct Student { std::string name; int id; double gpa; };`. Read one student's fields from input, store in a Student, and print a formatted record line (columns 15, 6, 6).
**Input:** name (one word), id, gpa · **Output:** one formatted line.
**Sample:** `Ayesha 101 3.75` → `Ayesha           101   3.75`
**Hints:** struct first, then a variable of it — the type/variable distinction is the point.

### PF-E-114 · Struct Copy vs Alias
**Difficulty:** Foundational · **Lecture:** L28 · **Outcomes:** PF-14.3
**Prerequisites:** E-113
**Problem:** Using E-113's struct: copy a Student into another variable and mutate the copy's GPA; then make a *reference* alias and mutate through it. Print the original after each step and explain both outcomes in comments.
**Input:** none (fixed demo) · **Output:** two GPA observations + commentary.
**Sample:** — → `after copy-mutate: original gpa 3.75` / `after alias-mutate: original gpa 4.00`
**Hints:** `Student b{a};` vs `Student& alias{a};` — the `&` changes everything.

### PF-E-115 · Rectangle Area/Perimeter Functions
**Difficulty:** Foundational · **Lecture:** L28 · **Outcomes:** PF-14.3, PF-14.4
**Prerequisites:** E-114
**Problem:** Define `struct Rect { double w; double h; };`. Write `double area(const Rect&)`, `double perimeter(const Rect&)`, and `void scale(Rect&, double k)` (multiplies both dimensions in place). Demonstrate all three on a read rectangle.
**Input:** two doubles · **Output:** area, perimeter, scaled dimensions.
**Sample:** `3 4` k=2 → `area: 12` / `perimeter: 14` / `scaled: 6 x 8`
**Hints:** read-only functions take `const&`; the mutator takes `&`.

### PF-E-116 · Song Library (vector of structs)
**Difficulty:** Foundational · **Lecture:** L28 · **Outcomes:** PF-14.4, PF-9.3
**Prerequisites:** E-115
**Problem:** Define `struct Song { std::string title; std::string artist; int seconds; };`. Read n (1–15) songs. Print: total playtime (mm:ss), the longest song, and all songs by a queried artist.
**Input:** n + song records, then artist query · **Output:** three report blocks.
**Sample:** query `Ada` → lists her songs with durations.
**Hints:** duration math reuses E-008's decomposition; linear search over the vector.

### PF-E-117 · Nested Struct: Address inside Student
**Difficulty:** Intermediate · **Lecture:** L28 · **Outcomes:** PF-14.3
**Prerequisites:** E-116
**Problem:** Define `struct Address { std::string city; std::string country; };` and add `Address home;` to Student. Read one student (all five fields) and print: the record, then `home.country` alone, then the same through a Student pointer using `->` twice.
**Input:** five field values · **Output:** record + country + pointer access.
**Sample:** — → `home.country: Pakistan` / `via p->home.city: Lahore`
**Hints:** `p->home.city` chains the arrow then the dot.

### PF-E-118 · Bank Account Struct with Invariant Checks
**Difficulty:** Intermediate · **Lecture:** L28 · **Outcomes:** PF-14.3, PF-14.4
**Prerequisites:** E-117
**Problem:** Define `struct Account { std::string owner; long long balanceCents; };`. Write `bool deposit(Account&, long long cents)` and `bool withdraw(Account&, long long cents)` — both reject non-positive amounts; withdraw also rejects overdraft. Drive a sequence of read transactions from `main`, printing `ok`/`rejected: reason` per transaction and the final balance.
**Input:** initial owner+balance, then transactions (type, amount) until type `q` · **Output:** per-transaction verdicts + final balance.
**Sample:** deposit 500 → `ok`; withdraw 900 → `rejected: insufficient funds`
**Hints:** the *struct is data-only* — validation lives in free functions; Module 16 will move it inside.

### PF-E-119 · Parallel Arrays vs Struct (rewrite)
**Difficulty:** Intermediate · **Lecture:** L28 · **Outcomes:** PF-14.4, PF-12.2
**Prerequisites:** E-118
**Problem:** You are given (in comments) a parallel-arrays implementation of 3 students sorted by GPA that "shreds" names from IDs. (1) Demonstrate the shredding in one sentence. (2) Rewrite with `std::vector<Student>` and sort by GPA (any correct sort), keeping records whole. Print the sorted roster both ways.
**Input:** 3 students · **Output:** shredded roster, then intact roster.
**Sample:** — → demonstrates name/ID misalignment, then correct pairing.
**Hints:** sort the struct vector — the record moves as one unit.

### PF-E-120 · Struct with Array Member: Temperature Station
**Difficulty:** Intermediate · **Lecture:** L28 · **Outcomes:** PF-14.3, PF-9.3
**Prerequisites:** E-119
**Problem:** Define `struct Station { std::string name; double temps[7]; };` (daily readings). Read one station; print the week's min, max, average (2 decimals), and which days were above average (day indices). All analysis in a function taking `const Station&`.
**Input:** name + 7 doubles · **Output:** min/max/avg + above-average days.
**Sample:** `Lahore 30 32 35 34 33 31 29` → `min: 29` / `max: 35` / `avg: 32.00` / `above: 2 3 4`
**Hints:** the array lives inside the record — `station.temps[i]`; two passes (compute avg, then compare).

### PF-E-121 · Course Roster Analytics
**Difficulty:** Advanced Introductory · **Lecture:** L28 · **Outcomes:** PF-14.4, PF-9.4, PF-12.2
**Prerequisites:** E-120
**Problem:** Read n (1–30) students (name, id, gpa). Produce: highest-GPA student; count in each GPA band (≥3.5, 3.0–3.49, 2.0–2.99, <2.0); the roster sorted by ID using your own sort on the vector; and search-by-ID (report record or `not found`). All reports as functions taking `const std::vector<Student>&`.
**Input:** n + records, then an ID query · **Output:** four report blocks.
**Sample:** query id `103` → `Ayesha 103 3.90` or `not found`.
**Hints:** reuse your sort (E-095) generalized to records; search on the *sorted* vector may use binary search.
