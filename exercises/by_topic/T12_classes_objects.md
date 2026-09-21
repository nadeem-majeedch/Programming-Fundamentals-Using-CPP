# T12 · Classes and Objects

Covers: class definition, private data, public interface, constructors,
getters/setters, invariants, `const` member functions, composition,
classes managing collections, struct→class refactor. Lectures L31–L32.
Outcomes PF-16.1–16.4.

21 exercises · ladder 🟢 → 🔴. The invariant is the grading axis: any
public path that can corrupt state fails the exercise.

---

### PF-E-132 · First Class: Counter
**Difficulty:** Beginner · **Lecture:** L31 · **Outcomes:** PF-16.1
**Prerequisites:** E-114
**Problem:** Define `class Counter` with private `int count_` (starts 0) and public `void increment()`, `int value() const`. Demonstrate three increments and print the value.
**Input:** none · **Output:** the value (3).
**Sample:** — → `3`
**Hints:** constructor or default member init sets `count_{0}`.

### PF-E-133 · Private Data Enforcement
**Difficulty:** Beginner · **Lecture:** L31 · **Outcomes:** PF-16.1
**Prerequisites:** E-132
**Problem:** Using E-132's Counter, attempt `c.count_ = 99;` from `main` — record the *exact compiler error* in a comment. Then provide a legal path (`increment()`) and explain why the error is desirable.
**Input:** none · **Output:** working program + quoted error in comment.
**Sample:** — → compiles only after removing the illegal line.
**Hints:** submit the version *with* the comment and *without* the illegal line.

### PF-E-134 · Temperature Class
**Difficulty:** Beginner · **Lecture:** L31 · **Outcomes:** PF-16.2, PF-16.3
**Prerequisites:** E-133
**Problem:** `class Temperature`: private `double celsius_`; public constructor defaulting to 0; `double celsius() const`; `void setCelsius(double)` rejecting below −273.15 (print warning, keep old value); `double fahrenheit() const` (derived). Demonstrate a rejected set and a conversion.
**Input:** none · **Output:** demonstration lines.
**Sample:** — → `setCelsius(-300) rejected` / `fahrenheit: 98.6` for 37.
**Hints:** the invariant is celsius ≥ −273.15; fahrenheit() is computed, not stored.

### PF-E-135 · Rectangle Class (two constructors)
**Difficulty:** Foundational · **Lecture:** L31 · **Outcomes:** PF-16.2
**Prerequisites:** E-134
**Problem:** `class Rect`: private `w_`, `h_` (positive invariant). Default constructor makes a 1×1; parameterized constructor validates and falls back to 1×1 for non-positive inputs. Public `area() const`, `perimeter() const`, `void scale(double k)` (k must be positive). Demonstrate both constructors and a rejected scale.
**Input:** none · **Output:** demonstration lines.
**Sample:** — → `area: 12` / `scale(-2) rejected` / `area after scale(2): 24`
**Hints:** route *all* initialization through the validation helper.

### PF-E-136 · Bank Account Class (the invariant star)
**Difficulty:** Foundational · **Lecture:** L31 · **Outcomes:** PF-16.2, PF-16.3
**Prerequisites:** E-135
**Problem:** `class Account`: private `owner_` (string), `balanceCents_` (long long, ≥ 0 invariant). Constructor takes owner and opening balance (reject negative → 0). Public `bool deposit(long long)`, `bool withdraw(long long)` (reject non-positive; reject overdraft), `long long balance() const`, `void print() const`. Drive a scripted scenario printing each verdict.
**Input:** none · **Output:** transaction log + final balance.
**Sample:** — → `withdraw 900: rejected (insufficient funds)` / `balance: 500`
**Hints:** refactor of E-118 — the *same* rules, now enforced *inside the type*.

### PF-E-137 · Getters, Setters, and const-correctness
**Difficulty:** Foundational · **Lecture:** L31 · **Outcomes:** PF-16.3
**Prerequisites:** E-136
**Problem:** Add `std::string owner() const` and `void rename(const std::string&)` to Account. Write `void audit(const Account& a)` taking the account **by const reference** and calling `owner()` and `balance()` — demonstrate that removing `const` from either member function breaks `audit`. Quote the compiler error in a comment.
**Input:** none · **Output:** audit output + commentary.
**Sample:** — → `audit: Ayesha holds 50000 cents`
**Hints:** const flows outward: const reference → const member functions required.

### PF-E-138 · Student Class (struct→class refactor)
**Difficulty:** Intermediate · **Lecture:** L32 · **Outcomes:** PF-16.4
**Prerequisites:** E-137
**Problem:** Take E-113's Student struct and refactor to `class Student`: private members, constructor validating gpa ∈ [0, 4], setters that validate, `const` getters, `print() const`. Demonstrate: a rejected gpa at construction and via setter; a successful update.
**Input:** none · **Output:** demonstration lines.
**Sample:** — → `set_gpa(9.0) rejected` / `gpa: 3.75`
**Hints:** five-step refactor checklist (L32): privatize → construct → validate setters → const getters → move helpers.

### PF-E-139 · Playlist Class (class managing a collection)
**Difficulty:** Intermediate · **Lecture:** L31 · **Outcomes:** PF-16.2, PF-16.4
**Prerequisites:** E-138
**Problem:** `class Playlist`: private `std::vector<std::string> songs_` and a name. Public: `add(const std::string&)` (reject empty, reject duplicates — return bool), `std::size_t size() const`, `void print() const`, `bool remove(const std::string&)`. Drive a scenario with duplicate-add and remove attempts.
**Input:** none · **Output:** scenario log.
**Sample:** — → `add "Song A": ok` / `add "Song A": rejected (duplicate)` / `after remove: size 1`
**Hints:** the vector is *private* — all mutation flows through validated methods.

### PF-E-140 · Time Class with Wrapping Invariant
**Difficulty:** Intermediate · **Lecture:** L31 · **Outcomes:** PF-16.2
**Prerequisites:** E-139
**Problem:** `class Clock`: private `h_`, `m_` (0–23, 0–59). Constructor validates; `void tick()` advances one minute with correct wrap (23:59 → 00:00); `void addMinutes(int n)` loops or multiplies; `print() const` as `HH:MM`. Demonstrate a wrap sequence and a rejected construction (25:00 → clamp to 23:59 with a warning, or to 00:00 — document your choice).
**Input:** none · **Output:** clock states.
**Sample:** — → `23:58` → tick → `23:59` → tick → `00:00`
**Hints:** tick = `m_ + 1; if (m_ == 60) { m_ = 0; ++h_; if (h_ == 24) h_ = 0; }`.

### PF-E-141 · Fraction Class (reduced automatically)
**Difficulty:** Intermediate · **Lecture:** L31 · **Outcomes:** PF-16.2
**Prerequisites:** E-140
**Problem:** `class Fraction`: private `num_`, `den_` (den > 0 invariant — sign lives in the numerator). Constructor reduces via GCD (reuse E-046 as a helper function); rejects den 0 (→ 1 with warning). Public `Fraction add(const Fraction&) const` returning a *new reduced* Fraction; `print() const` as `a/b`. Demonstrate 1/6 + 1/3 = 1/2 and a rejection.
**Input:** none · **Output:** fraction results.
**Sample:** — → `1/6 + 1/3 = 1/2` / `Fraction(3, 0): denominator rejected, set to 1`
**Hints:** add: `a/b + c/d = (ad + cb)/(bd)` then reduce; invariant holds *after every operation*.

### PF-E-142 · Inventory Class with Search
**Difficulty:** Intermediate · **Lecture:** L31 · **Outcomes:** PF-16.2, PF-16.4
**Prerequisites:** E-141
**Problem:** `class Inventory`: private `std::vector<Item>` where `struct Item { std::string sku; int qty; }` is *public* (data carrier). Public: `bool restock(sku, qty)` (qty > 0; adds item if unknown), `bool sell(sku, qty)` (reject overdraft / unknown sku), `int qtyOf(sku) const` (−1 if unknown), `void print() const`. Script: restock, sell, oversell, unknown-sku sell.
**Input:** none · **Output:** scenario log.
**Sample:** — → `sell SKU1 x3: ok` / `sell SKU1 x99: rejected (only 7)` / `qtyOf(NOPE): -1`
**Hints:** the public struct is a plain record; the *class* guards the vector.

### PF-E-143 · Composition: Car has-an Engine
**Difficulty:** Intermediate · **Lecture:** L31 · **Outcomes:** PF-16.4
**Prerequisites:** E-142
**Problem:** `class Engine`: private rpm (0–8000 invariant), `start()`, `stop()`, `bool running() const`, `int rpm() const`. `class Car`: has a private `Engine engine_;` plus `drive(int minutes)` that *requires* the engine running (prints `engine off` otherwise) and accumulates private `km_` (speed fixed at 60 km/h). Demonstrate: drive-while-off, then start/drive/stop; expose `km() const`.
**Input:** none · **Output:** scenario log.
**Sample:** — → `drive: engine off` / `started` / `drove 20 km` / `km: 20`
**Hints:** composition = a member *object*; Car delegates to Engine — no inheritance (not in course scope).

### PF-E-144 · Operator Overload: Money class
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.2
**Prerequisites:** E-143
**Problem:** `class Money`: private `cents_` (long long, may be negative for debt). Public constructor; `Money operator+(const Money&) const;` and `Money operator-() const;` (negation). Print via `print() const` as `$12.34` / `-$3.50` (negative before the dollar sign). Demonstrate an expense ledger: income + income − expense + negation.
**Input:** none · **Output:** ledger lines.
**Sample:** — → `$10.00 + $25.50 = $35.50` / `−$12.75` / `negated: $12.75`
**Hints:** operators are member functions; keep cents as long long — never floats for money.

### PF-E-145 · Class with Static Member: ID Generator
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.2
**Prerequisites:** E-144
**Problem:** `class Ticket`: private static `int nextId_ = 100;` and private `int id_`. Constructor assigns `id_ = nextId_++`. Public `int id() const`. Demonstrate constructing 3 tickets and printing IDs. In comments: (1) why the counter is shared across all objects, (2) why a per-object counter would be wrong, (3) the testability cost of hidden static state (link to the globals policy).
**Input:** none · **Output:** three IDs + commentary.
**Sample:** — → `100` / `101` / `102`
**Hints:** static members are declared in-class, defined outside the class — show that line.

### PF-E-146 · const-object and const-member-function Drill
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.3
**Prerequisites:** E-145
**Problem:** Make a `const Account` (E-136). Demonstrate: calling `balance()` works; calling `deposit()` fails (quote the error in a comment); calling a *non-const* getter fails until you add `const`. Deliver a two-sentence rule (in comments) for deciding which member functions are const.
**Input:** none · **Output:** working program + documented experiments.
**Sample:** — → compiles with all getters const; the illegal calls live in comments.
**Hints:** const object → only const member functions callable — that's the whole feature.

### PF-E-147 · Vector of Objects: Roster Class
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.4, PF-14.4
**Prerequisites:** E-146
**Problem:** `class Roster`: private `std::vector<Student>` (E-138's class). Public: `bool add(const Student&)` (reject duplicate id), `const Student* findById(int id) const` (pointer or nullptr), `double averageGpa() const` (empty roster → 0.0 with a printed note), `void printAll() const`. Script: add 3, duplicate attempt, find hit/miss, average.
**Input:** none · **Output:** scenario log.
**Sample:** — → `add id 101: ok` / `add id 101: rejected (duplicate)` / `findById(999): not found`
**Hints:** returning `const Student*` keeps the collection read-only through the pointer.

### PF-E-148 · Stack Class (bounded, array-backed)
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.2, PF-16.4
**Prerequisites:** E-147
**Problem:** `class IntStack`: private fixed `int data_[32]; int top_{0};`. Public: `bool push(int)` (full → false), `bool pop(int& out)` (empty → false), `int size() const`, `bool empty() const`. Demonstrate: fill to overflow attempt, drain to underflow attempt, LIFO order printout.
**Input:** none · **Output:** scenario log.
**Sample:** — → `push 33: rejected (full)` / `pop: 32` / `pop on empty: rejected`
**Hints:** top_ is both the size and the next free index; the invariant is `0 <= top_ <= 32`.

### PF-E-149 · Queue Class (circular buffer)
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.2, PF-16.4
**Prerequisites:** E-148
**Problem:** `class IntQueue`: private fixed array of 8, plus `head_`, `count_`. Public: `bool enqueue(int)`, `bool dequeue(int& out)`, `int size() const`. Wrap-around must work: enqueue 8, dequeue 3, enqueue 3 more (indices wrap). Demonstrate FIFO order and both rejection cases.
**Input:** none · **Output:** scenario log.
**Sample:** — → `enqueue 9th: rejected (full)` / `dequeue order: 1 2 3 …` (FIFO)
**Hints:** `tail_ = (head_ + count_) % 8` — the modulo *is* the circle; trace the indices.

### PF-E-150 · Money-Ledger Program (capstone-scale class design)
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.4, PF-15.3
**Prerequisites:** E-149
**Problem:** Combine E-144's Money and E-118/E-136 ideas into `class Ledger`: records dated entries (entry number, Money amount, description) in a private vector; `bool record(Money, const std::string&)` rejects zero amounts; `Money net() const`; `void printStatement() const`. Script 5 entries including a rejection; print the statement and the net.
**Input:** none · **Output:** statement + net.
**Sample:** — → `#1 +$1200.00 salary` … / `net: $977.25`
**Hints:** the Ledger delegates arithmetic to Money — each class does one job.

### PF-E-151 · Encapsulation Siege (adversarial review)
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.1, PF-16.4
**Prerequisites:** E-150
**Problem:** You are given (in comments) a `class Score` with *two* encapsulation holes: a public data member and a setter missing its range check. (1) Show the exact attack code for each hole (as comments). (2) Fix the class. (3) Prove the fix: re-attempt both attacks and quote the compiler errors / rejection behavior you now observe.
**Input:** none · **Output:** fixed class + documented attacks.
**Sample:** — → `attack 1: now a compile error (private)` / `attack 2: rejected by validation`
**Hints:** L31's siege game in written form — every public path must defend the invariant.

### PF-E-152 · Course Synthesis: Library System
**Difficulty:** Advanced Introductory · **Lecture:** L32 · **Outcomes:** PF-16.4, PF-14.4, PF-15.3
**Prerequisites:** E-151
**Problem:** Build `class Library` managing `class Book { title, author, copies }` (Book public struct; Library the guard). Operations: add (reject duplicate title), loan (reject no copies), return (increment), `findByAuthor(author)` printing matches, and `printCatalog()`. Drive a full scenario: 3 adds, duplicate, 2 loans, 1 failed loan, 1 return, author search, catalog print. Every class validates its own state; no public data.
**Input:** none · **Output:** full scenario log.
**Sample:** — → `loan "Dune": ok` / `loan "Dune": rejected (0 copies)` / `by "Ada": 2 found`
**Hints:** this is the L32 synthesis in miniature: structs as data carriers, classes as guardians, vectors as collections, every invariant defended.
