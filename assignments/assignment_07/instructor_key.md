# Assignment 7 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// textkit.cpp — Assignment 7 reference solution.
#include <iostream>
#include <string>
#include <cctype>

static bool isBoundary(const std::string& t, int i)
{
    if (i < 0 || i >= static_cast<int>(t.size())) return true;
    return !std::isalpha(static_cast<unsigned char>(t[i]));
}

// wholeWord: does w occur in t as a whole word (case-sensitive)?
bool wholeWord(const std::string& t, const std::string& w)
{
    if (w.empty()) return false;
    for (int i{0}; i + static_cast<int>(w.size()) <= static_cast<int>(t.size()); ++i) {
        if (t.compare(i, w.size(), w) == 0 &&
            isBoundary(t, i - 1) && isBoundary(t, i + static_cast<int>(w.size()))) {
            return true;
        }
    }
    return false;
}

void runWc()
{
    std::string line{};
    std::getline(std::cin, line);
    int words{0}, longest{0};
    int i{0}, n{static_cast<int>(line.size())};
    while (i < n) {
        while (i < n && std::isspace(static_cast<unsigned char>(line[i]))) ++i;
        if (i >= n) break;
        int start{i};
        while (i < n && !std::isspace(static_cast<unsigned char>(line[i]))) ++i;
        ++words;
        if (i - start > longest) longest = i - start;
    }
    std::cout << "words " << words << " chars " << n
              << " longest " << longest << '\n';
}

void runWord()
{
    std::string w{}, t{};
    std::cin >> w;
    std::cin.ignore(10000, '\n');      // consume rest of command line
    std::getline(std::cin, t);
    std::cout << (wholeWord(t, w) ? "yes" : "no") << '\n';
}

void runSortn()
{
    int n{};
    std::cin >> n;
    int a[100]{};
    for (int i{0}; i < n; ++i) std::cin >> a[i];
    int swaps{0};
    for (int i{0}; i < n - 1; ++i) {
        int m{i};
        for (int j{i + 1}; j < n; ++j) if (a[j] < a[m]) m = j;
        if (m != i) {
            int t{a[i]}; a[i] = a[m]; a[m] = t;
            ++swaps;
        }
    }
    for (int i{0}; i < n; ++i) std::cout << a[i] << (i + 1 < n ? ' ' : '\n');
    if (n == 1) std::cout << '\n';
    std::cout << "swaps " << swaps << '\n';
}

int main()
{
    std::string mode{};
    std::cin >> mode;
    if (mode == "wc") runWc();
    else if (mode == "word") runWord();
    else if (mode == "sortn") runSortn();
    else std::cout << "bad mode\n";
    return 0;
}
```

## Verified runs

| Input | Output |
|---|---|
| `wc / the␣␣␣cat sat` | `words 3 chars 11 longest 3` |
| `wc /` (empty line) | `words 0 chars 0 longest 0` |
| `word / cat / the category cat` | `yes` |
| `word / cat / concatenate` | `no` |
| `word / cat / cat` | `yes` (whole line) |
| `sortn / 4 / 5 2 9 1` | `1 2 5 9` / `swaps 2` |
| `sortn / 3 / 1 2 3` | `1 2 3` / `swaps 0` |
| `sortn / 1 / 42` | `42` / `swaps 0` |

## Hidden-case classes

- Tab-separated words in wc.
- Whole-word at position 0 and at line end (both boundaries true).
- Query word longer than the target line → `no` without OOB (loop bound check).
- Reverse-sorted n=5 → 2 swaps (5↔1, 4↔2)… actually reverse 5 4 3 2 1:
  pass 0: max scan picks 1 at end → swap → 1 4 3 2 5 (1); pass 1: 2↔4 (2);
  pass 2: 3 in place; pass 3: 4 in place → 2 swaps. Table must show 2.
- n = 100 fill.

## Common student defects

1. `std::sort` used despite the ban — correctness capped, and quality line 0.
2. Boundary test using `!isalpha(next)` only — misses start-of-line hit.
3. Substring match without bounds → `compare` throwing `out_of_range`.
4. Swap counted on self-swaps (`m == i`) → count inflated.
5. `cin.ignore` missing between `>> w` and getline → target reads empty.
