# Assignment 8 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

## Reference solution (compiled & executed)

```cpp
// ledger.cpp — Assignment 8 reference solution.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

struct Score { std::string name; int value{}; };

// parseLine: strict two-field parse with range check.
bool parseLine(const std::string& line, Score& out)
{
    std::istringstream in{line};
    std::string name{};
    int value{};
    if (!(in >> name)) return false;              // blank
    if (!(in >> value)) return false;             // missing/bad score
    std::string extra{};
    if (in >> extra) return false;                // too many fields
    if (value < 0 || value > 100) return false;   // out of range
    out.name = name;
    out.value = value;
    return true;
}

int main()
{
    std::ifstream in{"ledger.txt"};
    if (!in) {
        std::cout << "cannot open ledger.txt\n";
        return 2;
    }

    std::vector<Score> records{};
    int skipped{0};
    std::string line{};
    while (std::getline(in, line)) {
        Score s{};
        if (parseLine(line, s)) records.push_back(s);
        else ++skipped;
    }

    long long sum{0};
    int bestIdx{-1};
    for (int i{0}; i < static_cast<int>(records.size()); ++i) {
        sum += records[i].value;
        if (bestIdx < 0 || records[i].value > records[bestIdx].value) bestIdx = i;
    }

    double mean{0.0};
    if (!records.empty()) mean = static_cast<double>(sum) / records.size();

    std::cout << "loaded : " << records.size() << '\n';
    std::cout << "skipped: " << skipped << '\n';
    if (records.empty()) {
        std::cout << "mean   : n/a\nbest   : n/a\n";
    } else {
        std::cout << "mean   : " << std::fixed << std::setprecision(2) << mean << '\n';
        std::cout << "best   : " << records[bestIdx].name << '\n';
    }

    std::ofstream out{"report.txt", std::ios::app};
    if (!out) {
        std::cout << "cannot write report.txt\n";
        return 2;
    }
    out << "loaded : " << records.size() << ", skipped: " << skipped << '\n';
    return 0;
}
```

## Verified runs

| ledger.txt | stdout |
|---|---|
| 6-line sample above | `loaded : 3 / skipped: 2 / mean   : 85.00 / best   : Cara` (88+72+95=255/3=85.00) |
| missing file | `cannot open ledger.txt`, exit 2 |
| empty file | `loaded : 0 / skipped: 0 / mean   : n/a / best   : n/a`, exit 0 |
| only-bad file | `loaded : 0 / skipped: N / mean n/a / best n/a`, exit 0 |
| tie `Zoe 90 / Ali 90` | `best   : Zoe` (file order) |

## Hidden-case classes

- Name-only line → skipped (missing score).
- Extra third token → skipped (field-count rule).
- Score 0 and 100 boundaries → valid.
- Append behavior: second run's summary appended (test table shows two summaries).
- Unwritable report path (read-only dir, if the lab allows) → `cannot write`, exit 2.

## Common student defects

1. `>>`-based parse → blank lines loop forever or miscount; getline+istringstream is the spec.
2. Treating extra tokens as valid (trailing `3` swallowed silently) — field-count rule catches it.
3. mean printed as `85` (missing fixed/precision).
4. Overwriting `report.txt` (`ios::trunc` default) — append mode required.
5. Early `return 1` on bad lines — batch data must not abort the run.
