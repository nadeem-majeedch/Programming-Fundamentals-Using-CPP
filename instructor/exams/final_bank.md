# Final Question Bank — All 16 Modules (L01–L32)
**INSTRUCTOR-ONLY.** 48 items · 112 marks in pool. The final draws from the
Modules 9–16 pool only (76 % of paper marks there, ≥ 60 % required); Modules 1–8
are assessed on the midterm and by the cumulative-item design of the final's
sections.
Tags: `[type · module · lecture · CLO · difficulty · marks]`.
Type legend: MCQ / TRACE / DEBUG / SHORT / DESIGN / CODE / CCOMP / CPLX (complexity intuition).

All tracing/coding answers machine-verified with GCC 16.2 under the course contract
(see `ASSESSMENT_AUDIT.md` §5).

---

## Section A — MCQ (8 items · 1 mark each)

**A1** `[MCQ · M9 · L17 · CLO-6 · E · 1]`
For `int a[8]`, valid indices are:
A. 1..8  B. 0..8  C. 0..7  D. 1..7
**Answer:** C

**A2** `[MCQ · M9 · L18 · CLO-6 · E · 1]`
`a[i]` with an out-of-range i is:
A. compile error  B. runtime exception  C. undefined behavior  D. returns 0
**Answer:** C

**A3** `[MCQ · M10 · L20 · CLO-6 · E · 1]`
Row-major traversal of `g[ROWS][COLS]` uses:
A. outer over columns  B. outer over rows, inner over columns  C. diagonals  D. reverse rows
**Answer:** B

**A4** `[MCQ · M11 · L22 · CLO-6 · E · 1]`
`s.find("xy")` when "xy" is absent returns:
A. 0  B. -1  C. `std::string::npos`  D. throws
**Answer:** C

**A5** `[MCQ · M13 · L25 · CLO-7 · E · 1]`
`p++` on an `int* p` advances by:
A. 1 bit  B. 1 byte  C. one element (sizeof(int))  D. 8 bytes always
**Answer:** C

**A6** `[MCQ · M14 · L27 · CLO-7 · E · 1]`
Memory from `new int[10]` must be released with:
A. delete  B. delete[]  C. free  D. nothing
**Answer:** B

**A7** `[MCQ · M15 · L29 · CLO-8 · E · 1]`
`!in` immediately after opening an ifstream tests:
A. empty file  B. open failure  C. read error only  D. EOF
**Answer:** B

**A8** `[MCQ · M16 · L31 · CLO-8 · E · 1]`
A private data member may be accessed by:
A. anyone  B. member functions of the class (and friends)  C. derived classes only  D. free functions in the same file
**Answer:** B

---

## Section B — Output tracing (10 items · 2 marks each)

**B1** `[TRACE · M9 · L17 · CLO-6 · E · 2]`
```cpp
int a[]{4, 1, 7};
int best{a[0]};
for (int i{1}; i < 3; ++i) if (a[i] > best) best = a[i];
std::cout << best << '\n';
```
**Answer:** `7`

**B2** `[TRACE · M9 · L18 · CLO-6 · M · 2]`
```cpp
int a[5]{};
for (int i{0}; i < 5; ++i) a[i] = i * i;
std::cout << a[1] + a[4] << '\n';
```
**Answer:** `17` (1 + 16)

**B3** `[TRACE · M10 · L19 · CLO-6 · M · 2]`
```cpp
int g[2][3]{{1, 2, 3}, {4, 5, 6}};
int sum{0};
for (int c{0}; c < 3; ++c) sum += g[1][c];
std::cout << sum << '\n';
```
**Answer:** `15` (row 1: 4 + 5 + 6)

**B4** `[TRACE · M11 · L21 · CLO-6 · E · 2]`
```cpp
std::string s{"hello"};
std::cout << s.size() << ' ' << s.substr(1, 3) << ' '
          << (s.find("ll") == 2 ? "hit" : "miss") << '\n';
```
**Answer:** `5 ell hit`

**B5** `[TRACE · M11 · L22 · CLO-6 · M · 2]`
```cpp
std::string s{"Data-42"};
int digits{0};
for (char ch : s) if (std::isdigit(static_cast<unsigned char>(ch))) ++digits;
std::cout << digits << '\n';
```
**Answer:** `2`

**B6** `[TRACE · M12 · L23 · CLO-6 · M · 2]`
```cpp
// binary search, a = {2, 4, 6, 8, 10}, key = 8
// low=0 high=4; mid=2 -> a[2]=6 < 8 -> low=3; mid=3 -> found
std::cout << /* comparisons before success */ 2 << '\n';
```
**Answer:** `2` (mids checked: 2, then 3)

**B7** `[TRACE · M12 · L24 · CLO-6 · M · 2]`
```cpp
// selection sort pass 0 on {5, 2, 9, 1}: array becomes?
```
**Answer:** `1 2 9 5` (min 1 swapped into position 0)

**B8** `[TRACE · M13 · L26 · CLO-7 · M · 2]`
```cpp
int x{4};
int* p{&x};
*p = *p + 5;
p = nullptr;
std::cout << x << '\n';
```
**Answer:** `9` (write happened before nulling; printing x, not *p)

**B9** `[TRACE · M14 · L27 · CLO-7 · M · 2]`
```cpp
struct P { int x; };
P a{3};
P b{a};
b.x = 9;
std::cout << a.x << '\n';
```
**Answer:** `3` (struct assignment copies; b is independent)

**B10** `[TRACE · M16 · L31 · CLO-8 · M · 2]`
```cpp
class C {
public:
    void set(int v) { x_ = v; }
    int get() const { return x_; }
private:
    int x_{0};
};
C c; c.set(7);
std::cout << c.get() << '\n';
```
**Answer:** `7`

---

## Section C — Debugging (8 items · 2 marks each)

**C1** `[DEBUG · M9 · L17 · CLO-6 · M · 2]`
Sum loop misses the last element of `int a[4]`.
```cpp
for (int i{0}; i < 3; ++i) sum += a[i];
```
**Answer:** Bound is 3, should be 4 (`i < 4`); off-by-one on the upper limit.

**C2** `[DEBUG · M9 · L17 · CLO-6 · H · 2]`
```cpp
int a[3]{1, 2, 3};
for (int i{0}; i <= 3; ++i) sum += a[i];
```
**Answer:** Reads a[3] — out of bounds (undefined behavior). `<=` must be `<`. Note the symptom may be silent; that is the teaching point.

**C3** `[DEBUG · M10 · L19 · CLO-6 · M · 2]`
Border sum double-counts corners of a grid.
**Answer:** The four corner cells satisfy both the row pass and the column pass; fix with a single pass over all cells using the predicate `r==0 || r==ROWS-1 || c==0 || c==COLS-1`.

**C4** `[DEBUG · M11 · L21 · CLO-6 · M · 2]`
After `cin >> age;`, the next `getline` reads an empty line.
**Answer:** The `>>` extraction leaves the newline in the stream; getline consumes it immediately. Fix: consume the rest of the line before the next getline (course stream-state form: clear/flush the residue), then read.

**C5** `[DEBUG · M12 · L23 · CLO-6 · H · 2]`
Binary search with `high = n;` and `low <= high;` loops forever on absent keys.
**Answer:** Mixing disciplines: with high = n the test must be `low < high`; with `low <= high` the bound must be `high = n - 1`. Pick one discipline consistently (course convention: `high = n - 1`, `low <= high`).

**C6** `[DEBUG · M13 · L26 · CLO-7 · M · 2]`
Program crashes on the second use of a pointer after `delete p;`.
**Answer:** Use-after-delete. Apply both guards: initialize to nullptr at birth; after delete, immediately set `p = nullptr;` and check before every dereference.

**C7** `[DEBUG · M14 · L27 · CLO-7 · M · 2]`
```cpp
for (...) {
    int* p{new int[1000]};
    if (cond) return;   // A
    delete[] p;
}
```
**Answer:** Leak on the early-return path (line A skips delete[]). Fixes: single owner freeing on every exit path, or replace with `std::vector` (RAII, the course default).

**C8** `[DEBUG · M16 · L32 · CLO-8 · M · 2]`
`withdraw(999999)` on a balance of 500 succeeds.
**Answer:** The balance invariant is broken because the write path bypasses validation (direct member access or an unsanitized setter). Place validation in the public mutator — the only door to the private state.

---

## Section D — Short conceptual (6 items · 2 marks each)

**D1** `[SHORT · M9 · L17 · CLO-6 · E · 2]`
Why initialize a max-tracker from `a[0]` rather than 0?
**Answer:** With all-negative data, 0 is never a valid candidate and would report a value absent from the array; a[0] starts from a real element.

**D2** `[SHORT · M10 · L19 · CLO-6 · M · 2]`
State the signature rule for passing 2-D arrays to functions.
**Answer:** The column dimension must appear: `void f(int g[][COLS], int rows);` — the compiler needs it for indexing arithmetic.

**D3** `[SHORT · M12 · L23 · CLO-6 · E · 2]`
What precondition does binary search impose and what guarantee does it provide?
**Answer:** Input must be sorted; it then finds the key (or reports absence) in O(log n) comparisons — the sortedness is what makes halving sound.

**D4** `[SHORT · M13 · L25 · CLO-7 · E · 2]`
When is a reference parameter preferable to a pointer parameter?
**Answer:** When the argument must exist and never be null and no reseating is needed — references state "this is the object" directly; pointers are for optionality/retargeting.

**D5** `[SHORT · M15 · L30 · CLO-8 · M · 2]`
State the course exit-code discipline.
**Answer:** 0 = success; 1 = usage error (bad invocation); 2 = data/environment failure (e.g., cannot open input). Accept reversed 1/2 wording only if the paper's own convention line defines it.

**D6** `[SHORT · M16 · L32 · CLO-8 · E · 2]`
What does "has-a" composition mean for a `Garage` containing `Car`s?
**Answer:** Garage owns/contains Car objects and operates on them only through their public interface — composition builds larger types from smaller ones.

---

## Section E — Complexity intuition (4 items · 2 marks each)

**E1** `[CPLX · M12 · L23 · CLO-6 · E · 2]`
Linear search on n = 1000, absent key — about how many comparisons?
**Answer:** n (1000); every element is examined.

**E2** `[CPLX · M12 · L23 · CLO-6 · E · 2]`
Binary search on n = 1000 — about how many comparisons?
**Answer:** ⌈log2 1000⌉ ≈ 10.

**E3** `[CPLX · M12 · L24 · CLO-6 · M · 2]`
Why is insertion sort O(n) on already-sorted input but O(n²) worst case?
**Answer:** Each element is compared only with its predecessor chain until the first not-greater element — on sorted input that is one comparison each (n total); worst case every element travels to the front (n²/2).

**E4** `[CPLX · M12 · L24 · CLO-6 · M · 2]`
Your measured comparison counters show binary search ≈ 10 and linear ≈ 1000 on the same absent-key workload. In one sentence: what does this tell you about scaling to n = 1,000,000?
**Answer:** The gap widens with n — linear scales with n (~10⁶ checks), binary with log n (~20 checks); sortedness pays for itself as data grows.

---

## Section F — Algorithm design (4 items · 3 marks each)

**F1** `[DESIGN · M11 · L21 · CLO-6 · M · 3]`
Design a whole-word counter for "cat" in a line of text that does not match "category". Give the boundary predicate.
**Answer:** Scan for occurrences of "cat"; a hit counts only if the character before (if any) and after (if any) are non-letter boundaries (start/end of text or non-alpha). Boundaries: text starts with cat, ends with cat, "cats", "concatenate", multiple hits per line.

**F2** `[DESIGN · M12 · L23 · CLO-6 · M · 3]`
Design the search for the first duplicate in an unsorted array of ≤ 1000 ints. State algorithm choice, complexity, and boundary inputs.
**Answer:** Brute force with a nested loop is O(n²) but simple and fine at n ≤ 1000 (course scale); alternatives: sort-then-adjacent-scan O(n log n) (loses original order of the *first* pair unless indices tracked), or an O(n) seen-set (beyond current toolkit — mention only). Boundaries: no duplicate, duplicate at first pair, all equal, single element.

**F3** `[DESIGN · M14 · L28 · CLO-7 · M · 3]`
Design a `struct Record { string name; int score; }` top-N report from parallel arrays. Which defects of parallel arrays does the struct remove?
**Answer:** Sort one array of Records with a comparator on score; the name/score pair cannot misalign. Parallel arrays invite half-updated swaps (record-misalignment bug class); structs make the pair atomic under assignment.

**F4** `[DESIGN · M15 · L30 · CLO-8 · H · 3]`
Design a robust CSV loader (name,score) that reports loaded/skipped counts and continues past malformed lines. State the per-line algorithm and exit codes.
**Answer:** getline each line; istringstream extract name and score; on extraction failure → skip counter + continue, else load. Exit 0 always unless the file cannot open → exit 2 (data/environment). Boundaries: empty file, all-bad file, missing score, extra fields, blank line.

---

## Section G — Coding (4 items · 6 marks each)

**G1** `[CODE · M9 · L17 · CLO-6 · M · 6]`
Read n (1 ≤ n ≤ 100) then n integers; print the second-largest distinct value or `N/A`.
**Answer:**
```cpp
#include <iostream>
int main()
{
    int n{};
    if (!(std::cin >> n) || n < 1 || n > 100) { std::cout << "bad n\n"; return 1; }
    long long best{0}, second{0};
    bool hasBest{false}, hasSecond{false};
    for (int i{0}; i < n; ++i) {
        long long v{};
        std::cin >> v;
        if (!hasBest || v > best) {
            if (hasBest && best != v) { second = best; hasSecond = true; }
            best = v; hasBest = true;
        } else if (v != best && (!hasSecond || v > second)) {
            second = v; hasSecond = true;
        }
    }
    if (!hasSecond) std::cout << "N/A\n";
    else std::cout << second << '\n';
    return 0;
}
```
Verified: `5 | 3 9 9 4 1` → `4`; `3 | 7 7 7` → `N/A`; `2 | -5 -2` → `-5`.

**G2** `[CODE · M11 · L22 · CLO-6 · M · 6]`
Count vowels, consonants, and digits in a whole input line.
**Answer:**
```cpp
#include <iostream>
#include <string>
#include <cctype>
int main()
{
    std::string line{};
    if (!std::getline(std::cin, line)) return 1;
    int vowels{0}, consonants{0}, digits{0};
    for (char ch : line) {
        unsigned char u{static_cast<unsigned char>(ch)};
        if (std::isdigit(u)) ++digits;
        else if (std::isalpha(u)) {
            char lo{static_cast<char>(std::tolower(u))};
            if (lo=='a'||lo=='e'||lo=='i'||lo=='o'||lo=='u') ++vowels;
            else ++consonants;
        }
    }
    std::cout << vowels << ' ' << consonants << ' ' << digits << '\n';
    return 0;
}
```
Verified: `Hello, World 42!` → `3 7 2` (letters H,e,l,l,o,W,o,r,l,d = 10 alpha: vowels e,o,o = 3; consonants H,l,l,W,r,l,d = 7; digits 4,2 = 2).

**G3** `[CODE · M12 · L24 · CLO-6 · M · 6]`
Implement insertion sort for `int a[], int n` and print the array after each pass.
**Answer:**
```cpp
#include <iostream>
void print(const int a[], int n)
{
    for (int i{0}; i < n; ++i) std::cout << a[i] << (i + 1 < n ? ' ' : '\n');
}
void insertionSort(int a[], int n)
{
    for (int i{1}; i < n; ++i) {
        int key{a[i]};
        int j{i - 1};
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; }
        a[j + 1] = key;
        print(a, n);
    }
}
int main()
{
    int a[100]{}, n{};
    if (!(std::cin >> n) || n < 1 || n > 100) return 1;
    for (int i{0}; i < n; ++i) std::cin >> a[i];
    insertionSort(a, n);
    return 0;
}
```
Verified for `4 | 5 2 9 1`: passes print `2 5 9 1`, `2 5 9 1`, `1 2 5 9`.

**G4** `[CODE · M16 · L32 · CLO-8 · H · 6]`
Class `Counter` with private count (init 0): `inc()`, `dec()` that never lets count go below 0 (returns bool success), `value() const`. Main demonstrates the rejected decrement.
**Answer:**
```cpp
#include <iostream>
class Counter
{
public:
    void inc() { ++count_; }
    bool dec()
    {
        if (count_ == 0) return false;
        --count_;
        return true;
    }
    int value() const { return count_; }
private:
    int count_{0};
};
int main()
{
    Counter c;
    std::cout << std::boolalpha << c.dec() << ' ' << c.value() << '\n'; // false 0
    c.inc(); c.inc();
    std::cout << c.dec() << ' ' << c.value() << '\n';                   // true 1
    return 0;
}
```
Verified: prints `false 0` then `true 1`.

---

## Section H — Code completion (4 items · 3 marks each)

**H1** `[CCOMP · M9 · L17 · CLO-6 · E · 3]`
Complete the in-place reversal loop.
```cpp
for (int i{0}, j{n - 1}; i /*(a)*/ j; ++i, /*(b)*/) {
    int t{a[i]}; a[i] = a[j]; a[j] = t;
}
```
**Answer:** (a) `<`  (b) `--j`

**H2** `[CCOMP · M10 · L19 · CLO-6 · M · 3]`
Complete the diagonal sum.
```cpp
int diag{0};
for (int r{0}; r < ROWS; ++r) diag += g[r]/*(a)*/[/*(b)*/];
```
**Answer:** (a) nothing (index r) — (b) `r`  → full line: `diag += g[r][r];`
*(Accept: (a) `[r]` (b) `r`.)*

**H3** `[CCOMP · M14 · L27 · CLO-7 · M · 3]`
Complete the guarded allocation.
```cpp
int* data{new int[n]{}};
/*(a)*/ data;            // fill
for (int i{0}; i < n; ++i) data[i] = i;
/*(b)*/[] data;          // release + guard
data = /*(c)*/;
```
**Answer:** (a) *(unused marker line — see grading note)* (b) `delete` (c) `nullptr`
*(Grading note: accept the canonical three lines `for (...) ...`, `delete[] data;`, `data = nullptr;`.)*

**H4** `[CCOMP · M16 · L31 · CLO-8 · M · 3]`
Complete the class so the invariant holds.
```cpp
class Wallet {
public:
    bool spend(int amt)
    {
        if (amt < 0 /*(a)*/ amt > balance_) return false;
        balance_ /*(b)*/ amt;
        return true;
    }
private:
    int balance_{100};
};
```
**Answer:** (a) `||`  (b) `-=`

---

### Pool marks total
Section A 8·1 + B 10·2 + C 8·2 + D 6·2 + E 4·2 + F 4·3 + G 4·6 + H 4·3
= 8 + 20 + 16 + 12 + 8 + 12 + 24 + 12 = **112 marks across 48 items**
(papers select subsets per the blueprint in `PAPER_ASSEMBLY.md`).
