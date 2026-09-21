# Practical Assessment — Instructor Variants & Solutions
**INSTRUCTOR-ONLY** per [../../../instructor/ACCESS_CONTROL.md](../../../instructor/ACCESS_CONTROL.md).

Four variants (A–D). Each paper = the student tasks below + hidden-case notes.
All solutions were compiled with the course contract and executed (see
`../../../docs/ASSESSMENT_AUDIT.md` §5). Hidden cases are listed per task.

---

## Variant A

### Task 1 (20 mk) — Grade Stats with Validation
Read integers 0..100 until sentinel −1 (re-prompt not required; EOF ends too).
Print count, max, min, mean (2 dp), or exactly `no data`.

**Solution A**
```cpp
#include <iostream>
#include <iomanip>
int main()
{
    int count{0}, mx{0}, mn{0};
    long long sum{0};
    int v{};
    while (std::cin >> v && v != -1) {
        if (v < 0 || v > 100) continue;          // classify & skip
        if (count == 0) { mx = v; mn = v; }
        else { if (v > mx) mx = v; if (v < mn) mn = v; }
        ++count; sum += v;
    }
    if (count == 0) { std::cout << "no data\n"; return 0; }
    std::cout << count << ' ' << mx << ' ' << mn << ' '
              << std::fixed << std::setprecision(2)
              << static_cast<double>(sum) / count << '\n';
    return 0;
}
```
Verified: `80 90 -1` → `2 90 80 85.00`; `101 -1` → `no data`; `-1` → `no data`.
**Hidden:** empty input; 0 as only value (min=0 boundary); 100 boundary; mixed invalid/valid.

### Task 2 (25 mk) — Column Report
Read R then C (1 ≤ R,C ≤ 10), then R×C integers. Print each column's sum on one
line, space-separated.

**Solution A**
```cpp
#include <iostream>
int main()
{
    int r{}, c{};
    if (!(std::cin >> r >> c) || r < 1 || r > 10 || c < 1 || c > 10) return 1;
    long long col[10]{};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j) {
            int v{}; std::cin >> v; col[j] += v;
        }
    for (int j{0}; j < c; ++j) std::cout << col[j] << (j + 1 < c ? ' ' : '\n');
    return 0;
}
```
Verified: `2 3 | 1 2 3 4 5 6` → `5 7 9`.
**Hidden:** single row; single column; negatives; max size 10×10.

### Task 3 (30 mk + 5 test table) — `Battery` class
Private `level_` (0..100, init 0). Public: `charge(int amt)` clamps into range and
returns the new level; `drain(int amt)` refuses to go below 0 (returns bool);
`level() const`. Main must demonstrate a refused over-drain.

**Solution A**
```cpp
#include <iostream>
class Battery
{
public:
    int charge(int amt)
    {
        if (amt < 0) amt = 0;
        level_ += amt;
        if (level_ > 100) level_ = 100;
        return level_;
    }
    bool drain(int amt)
    {
        if (amt < 0 || amt > level_) return false;
        level_ -= amt;
        return true;
    }
    int level() const { return level_; }
private:
    int level_{0};
};
int main()
{
    Battery b;
    std::cout << b.charge(150) << '\n';     // 100 (clamped)
    std::cout << std::boolalpha << b.drain(120) << ' ' << b.level() << '\n'; // false 100
    b.drain(40);
    std::cout << b.level() << '\n';         // 60
    return 0;
}
```
Verified: prints `100`, `false 100`, `60`.
**Hidden:** drain exactly level_ (true, → 0); drain 1 from 0 (false); charge 0.
**Test table (5 mk):** student's table must include a refusal case and a boundary case.

---

## Variant B

### Task 1 (20 mk) — Sentence Word Counter
Read one line; print the number of whitespace-separated words, and the longest
word's length. Empty line → `0 0`.

**Solution B**
```cpp
#include <iostream>
#include <string>
#include <sstream>
int main()
{
    std::string line{};
    if (!std::getline(std::cin, line)) { std::cout << "0 0\n"; return 0; }
    std::istringstream in{line};
    int words{0}, longest{0};
    std::string w{};
    while (in >> w) {
        ++words;
        if (static_cast<int>(w.size()) > longest) longest = static_cast<int>(w.size());
    }
    std::cout << words << ' ' << longest << '\n';
    return 0;
}
```
Verified: `the quick brown fox` → `4 6`; empty → `0 0`.
**Hidden:** single word; multiple spaces; leading/trailing spaces; EOF without newline.

### Task 2 (25 mk) — Row Swap
Read R, C (≤ 10), grid, then two row indices i, j (0-based, guaranteed valid).
Swap those rows in place; print the grid.

**Solution B**
```cpp
#include <iostream>
int main()
{
    int r{}, c{};
    std::cin >> r >> c;
    int g[10][10]{};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j) std::cin >> g[i][j];
    int i{}, j{};
    std::cin >> i >> j;
    for (int k{0}; k < c; ++k) {
        int t{g[i][k]}; g[i][k] = g[j][k]; g[j][k] = t;
    }
    for (int a{0}; a < r; ++a)
        for (int b{0}; b < c; ++b)
            std::cout << g[a][b] << (b + 1 < c ? ' ' : '\n');
    return 0;
}
```
Verified: 2×3 grid 1..6, swap rows 0,1 → `4 5 6 / 1 2 3`.
**Hidden:** i == j (no-op); adjacent rows; first/last rows.

### Task 3 (30 mk + 5) — `Library` record struct + search
`struct Book { std::string title; int copies; };` Read n books, then a query
title; print the copies or `not found`. Comparison is case-sensitive.

**Solution B**
```cpp
#include <iostream>
#include <string>
struct Book { std::string title; int copies{}; };
int main()
{
    int n{};
    if (!(std::cin >> n) || n < 1 || n > 100) return 1;
    Book b[100]{};
    for (int i{0}; i < n; ++i) std::cin >> b[i].title >> b[i].copies;
    std::string q{}; std::cin >> q;
    for (int i{0}; i < n; ++i)
        if (b[i].title == q) { std::cout << b[i].copies << '\n'; return 0; }
    std::cout << "not found\n";
    return 0;
}
```
Verified: 3 books + `C++` → prints its copies; `Java` → `not found`.
**Hidden:** query is first/last element; single book; duplicate titles (first wins — document in table).

---

## Variants C and D

Same task structure, permuted topics:
- **C:** Task 1 digit-sum statistics; Task 2 matrix diagonal sum with validation;
  Task 3 `Timer` class (`start/stop/seconds() const`, invariant seconds_ ≥ 0,
  stop without start refuses). Hidden cases: double stop; zero-duration.
- **D:** Task 1 CSV mean (name,score per line, skip-and-report); Task 2 in-place
  array rotation by k; Task 3 `Playlist` of `struct Track{name,seconds}` with
  `total() const` and `longest() const`. Hidden cases: empty playlist, single
  track, tie for longest (first wins).

Solutions for C/D are structurally identical to A/B's patterns (same rubric lines,
same hidden-case *classes*); assemble them from the corresponding T-pool solutions
in `../../../instructor/exercise_solutions/` (T04 digit series, T06 grid tasks, T10
structs, T11 CSV, T12 classes) — those files compile and execute verified.

---

## Grading sheet (per student, per task)

| Line | 0 | full | Notes |
|---|---|---|---|
| Compiles with contract | 0 | yes/no gate | non-compiling = task capped at 0 |
| Sample cases correct | 0 | per-case | shown on paper |
| Hidden cases correct | 0 | per-case | classes listed above |
| Quality rubric | 0–4 | naming, structure, guards | shared rubric |
| Test table (task 3) | 0–5 | refusal + boundary required | |
