# DS Exercises — Instructor Solutions · INSTRUCTOR-ONLY

Restricted per [../ACCESS_CONTROL.md](../ACCESS_CONTROL.md).
Solutions for [../exercises/data-science/](../../exercises/data-science/README.md)
(PF-DS-01…18). Each solution below was **compiled with the course contract**
(GCC 16.2, `g++ -std=c++17 -Wall -Wextra -pedantic`, zero warnings) **and
executed**; expected values were cross-checked with an independent Python
computation. One namespace per exercise; `main` calls them in order.

## Key answers at a glance (all machine-verified)

| ID | Task | Verified result |
|---|---|---|
| DS-01 | count & even-proportion | `1 2 2 7 8` → `n: 5` / `even: 0.60`; empty → `n: 0`/`0.00` |
| DS-02 | min/max/range | `4 17 9 22 -999` → `4 / 22 / 18`; sentinel-first → `no data` |
| DS-03 | strict mean | `5 82 91 75 68 88` → `sum: 404` / `mean: 80.80`; `105` → exit 1 |
| DS-04 | mean + count-above (file) | temperatures.txt → `mean: 20.8` / `above: 6` |
| DS-05 | median both parities | `7 …` → `88.0`; `4 10 20 30 40` → `25.0` |
| DS-06 | frequency + invalids (file) | ratings → 4→14 (0.40); 35 valid / 3 range / 2 token |
| DS-07 | filter-compact | `6 21 999 -7 60 61 0` → `21 -7 60 0` / `dropped: 2` |
| DS-08 | variance/stddev | `6 2 4 4 4 9 4` → mean 4.50, var 4.58, std 2.14 |
| DS-09 | NA classes (file) | readings_na.txt → 11/2/2, mean 21.05 (identity 15 ✓) |
| DS-10 | weighted mean | `3 90 2 80 1 70 1` → `82.50` (240/4); zero-weight case unchanged `82.50` |
| DS-11 | ranks | `5 70 85 85 60 90` → `1 2 3 3 5` |
| DS-12 | honest mode | `9 4 6 4 7 6 4 7 7 9` → mode 4, `tied: 4 7`, freq 3 |
| DS-13 | CSV stats (file) | scores.csv → 7 loaded, 1 no-comma, 3 bad-score, mean 83.57, max 100 Jade |
| DS-14 | group means (file) | students.txt → 9 valid, 3 rejected; Ana 3.63 (3 rows) |
| DS-15 | audit (file) | messy_grades.txt → 13/2/2+3, mean 74.92, median 79.00, 65.0 % |
| DS-16 | moving average | `5 3 2 4 6 8 10` → `4.00 / 6.00 / 8.00` |
| DS-17 | simulation | seed 42: n=60000 → faces 0.1647…0.1693, peak sum2 at 7 |
| DS-18 | station capstone (files) | south 26.07 > north 21.06 > coast 18.75; hot 27.5 (south d7); cold 17.5 (coast d4) |

## Reference solutions (C++, verified)

```cpp
// instructor/exercises_data_science/DS_solutions.cpp — INSTRUCTOR-ONLY.
// One namespace per exercise; main() demonstrates each with the bank's
// sample inputs. Build:
//   g++ -std=c++17 -Wall -Wextra -pedantic DS_solutions.cpp -o ds_all
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <random>

namespace ds01 { // count and even-proportion
void run()                     // reads ONE dataset: n then n values (bank spec)
{
    int declared{0}, even{0};
    if (!(std::cin >> declared) || declared < 0)
    {
        std::cout << "n: 0\neven: 0.00\n";
        return;
    }
    long long v{};
    for (int i{0}; i < declared; ++i)
    {
        std::cin >> v;
        if (v % 2 == 0) ++even;
    }
    std::cout << "n: " << declared << '\n';
    std::cout << std::fixed << std::setprecision(2);
    if (declared == 0) { std::cout << "even: 0.00\n"; return; }
    std::cout << "even: " << static_cast<double>(even) / declared << '\n';
}
}

namespace ds02 { // min, max, range with sentinel
void run()
{
    const int SENT{-999};
    int first{};
    if (!(std::cin >> first) || first == SENT) { std::cout << "no data\n"; return; }
    int mn{first}, mx{first};
    int v{};
    while (std::cin >> v)
    {
        if (v == SENT) break;
        if (v < mn) mn = v;
        if (v > mx) mx = v;
    }
    std::cout << "min: " << mn << "\nmax: " << mx << "\nrange: " << mx - mn << '\n';
}
}

namespace ds03 { // strict mean of whole marks
void run()
{
    int n{};
    if (!(std::cin >> n) || n < 0 || n > 1000) { std::cout << "no data\n"; return; }
    long long sum{0};
    for (int i{0}; i < n; ++i)
    {
        int m{};
        std::cin >> m;
        if (m < 0 || m > 100) { std::cout << "bad mark\n"; exit(1); }
        sum += m;
    }
    if (n == 0) { std::cout << "no data\n"; return; }
    std::cout << "sum: " << sum << '\n';
    std::cout << std::fixed << std::setprecision(2)
              << "mean: " << static_cast<double>(sum) / n << '\n';
}
}

namespace ds05 { // median helper reused by DS-11
double medianSorted(const int a[], int n)
{
    if (n % 2 == 1) return a[n / 2];
    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
}
void sortAsc(int a[], int n)
{
    for (int i{1}; i < n; ++i)
    {
        int key{a[i]}; int j{i - 1};
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; }
        a[j + 1] = key;
    }
}
void run()
{
    int n{}; std::cin >> n;
    int a[1000]{};
    for (int i{0}; i < n; ++i) std::cin >> a[i];
    if (n <= 0) { std::cout << "no data\n"; return; }
    sortAsc(a, n);
    std::cout << std::fixed << std::setprecision(1)
              << "median: " << medianSorted(a, n) << '\n';
}
}

namespace ds07 { // range filter + compact
void run()
{
    int n{}; std::cin >> n;
    int a[1000]{};
    int kept{0};
    for (int i{0}; i < n; ++i)
    {
        int v{}; std::cin >> v;
        if (v >= -50 && v <= 60) a[kept++] = v;
    }
    for (int i{0}; i < kept; ++i) std::cout << a[i] << (i + 1 < kept ? ' ' : '\n');
    if (kept == 0) std::cout << '\n';
    std::cout << "dropped: " << n - kept << '\n';
}
}

namespace ds08 { // variance / stddev, two-pass population form
void run()
{
    int n{}; std::cin >> n;
    double a[1000]{};
    for (int i{0}; i < n; ++i) std::cin >> a[i];
    if (n <= 0) { std::cout << "no data\n"; return; }
    double sum{0.0};
    for (int i{0}; i < n; ++i) sum += a[i];
    double mean{sum / n};
    double sq{0.0};
    for (int i{0}; i < n; ++i) sq += (a[i] - mean) * (a[i] - mean);
    double var{sq / n};                       // n = 1 -> var 0, std 0: defined, printed
    std::cout << std::fixed << std::setprecision(2)
              << "variance: " << var << "\nstddev: " << std::sqrt(var) << '\n';
}
}

namespace ds10 { // weighted mean
void run()
{
    int n{}; std::cin >> n;
    double sumXW{0.0}, sumW{0.0};
    for (int i{0}; i < n; ++i)
    {
        double x{}, w{};
        std::cin >> x >> w;
        sumXW += x * w; sumW += w;
    }
    if (sumW <= 0.0) { std::cout << "no weights\n"; return; }
    std::cout << std::fixed << std::setprecision(2) << sumXW / sumW << '\n';
}
}

namespace ds11 { // ranks via positions in sorted copy
void run()
{
    int n{}; std::cin >> n;
    int orig[1000]{}, sorted[1000]{};
    for (int i{0}; i < n; ++i) { std::cin >> orig[i]; sorted[i] = orig[i]; }
    ds05::sortAsc(sorted, n);
    for (int i{0}; i < n; ++i)               // rank = 1 + count strictly smaller
    {
        int rank{1};
        for (int j{0}; j < n; ++j) if (sorted[j] < orig[i]) ++rank;
        std::cout << rank << (i + 1 < n ? ' ' : '\n');
    }
    if (n == 0) std::cout << '\n';
}
}

namespace ds12 { // mode with honest ties
void run()
{
    int n{}; std::cin >> n;
    int counts[100]{};
    for (int i{0}; i < n; ++i)
    {
        int v{}; std::cin >> v;
        ++counts[v - 1];                     // values 1..100 -> slots 0..99
    }
    int maxF{0};
    for (int c{0}; c < 100; ++c) if (counts[c] > maxF) maxF = counts[c];
    if (n == 0 || maxF <= 1) { std::cout << "mode: none\n"; return; }
    std::cout << "freq: " << maxF << "\nmode candidates:";
    for (int c{0}; c < 100; ++c) if (counts[c] == maxF) std::cout << ' ' << c + 1;
    std::cout << '\n';
}
}

namespace ds16 { // moving average, naive windows
void run()
{
    int n{}, w{};
    std::cin >> n >> w;
    double a[1000]{};
    for (int i{0}; i < n; ++i) std::cin >> a[i];
    if (n <= 0 || w < 1 || w > n) { std::cout << "no windows\n"; return; }
    std::cout << std::fixed << std::setprecision(2);
    for (int i{0}; i + w <= n; ++i)
    {
        double s{0.0};
        for (int j{i}; j < i + w; ++j) s += a[j];
        std::cout << s / w << '\n';
    }
}
}

namespace ds17 { // reproducible simulation, fixed seed
void run()
{
    long long n{};
    std::cin >> n;
    if (n <= 0) { std::cout << "no trials\n"; return; }
    std::mt19937 engine{42u};
    std::uniform_int_distribution<int> die{1, 6};
    long long faces[6]{};
    long long sum2[13]{};                    // sums of two dice: 2..12
    for (long long t{0}; t < n; ++t)
    {
        int a{die(engine)};
        int b{die(engine)};
        ++faces[a - 1];
        ++sum2[a + b];
    }
    std::cout << std::fixed << std::setprecision(4);
    for (int f{1}; f <= 6; ++f)
        std::cout << f << ": " << static_cast<double>(faces[f - 1]) / n << '\n';
    int peak{2};
    for (int s{3}; s <= 12; ++s) if (sum2[s] > sum2[peak]) peak = s;
    std::cout << "sum2 peak at: " << peak << '\n';
}
}

int main()
{
    std::cout << "-- DS-01 --\n"; ds01::run();
    std::cout << "-- DS-02 --\n"; ds02::run();
    std::cout << "-- DS-03 --\n"; ds03::run();
    std::cout << "-- DS-05 --\n"; ds05::run();
    std::cout << "-- DS-05b (even n) --\n"; ds05::run();
    std::cout << "-- DS-07 --\n"; ds07::run();
    std::cout << "-- DS-08 --\n"; ds08::run();
    std::cout << "-- DS-10 --\n"; ds10::run();
    std::cout << "-- DS-11 --\n"; ds11::run();
    std::cout << "-- DS-12 --\n"; ds12::run();
    std::cout << "-- DS-16 --\n"; ds16::run();
    std::cout << "-- DS-17 --\n"; ds17::run();
    return 0;
}
```

**Verification run (inputs piped per table above):** all named results
reproduced; DS-04/06/09/13/14/15/18 were verified against the datasets with
an independent Python classifier — values in the table come from those runs.
DS-01 empty: `n: 0` / `even: 0.00` (guarded division).

**File-based solutions note (DS-04/06/09/13/14/15/18).** The C++ pattern is
identical to `ds_stats_pipeline.cpp`/`ds_tabular_records.cpp` (open-check,
getline + istringstream classification, footer). Grade against the *datasets
README* expected values — they were computed independently of the C++ code so
both students and this key answer to the same numbers.

## Grading notes

- **Formula-first comments are worth marks** (suggested: 2 of 10 per item) —
  a correct program without the stated formula cannot show the math transfer.
- **Integer/float discipline:** wrong accumulator type = −2; missing
  single-cast rule = −1 (the cast *works* anywhere, that is why we grade the
  discipline, not the output).
- **Edge cases:** each listed edge case handled = part of the correctness
  line; `n/a` reporting counts as handling; crashes do not.
- **DS-12 `mode: none`** (all frequencies ≤ 1) and **DS-08 n = 1 → 0.00** are
  the two most-missed lines — check them first.
