// purpose: integer vs floating-point data in a data-science context —
//          exact counts vs approximate measurements, where the cast goes,
//          and why money/counts stay integer. Formula-first header.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_types_precision.cpp -o dstype
//
// MATH FIRST
// ----------
// A dataset has two kinds of numbers:
//   * COUNTS  (int):  how many observations. 12 is exactly 12. Use int/long long.
//   * MEASURES (double): heights, temperatures, prices. 0.1 is NOT exact in
//     binary floating point; repeated addition drifts slightly.
// The mean of measures x1..xn is  mean = (x1 + ... + xn) / n.
// The division is the ONLY step that needs floating point; the sum of counts
// stays exact in an integer type. In code: cast once, at the division.

#include <iostream>
#include <iomanip>

int main()
{
    // --- A count variable: exact arithmetic, always ---
    int students{24};                    // exactly 24; int arithmetic is exact
    int absent{3};
    int present{students - absent};      // 21, no rounding, ever
    std::cout << "present: " << present << '\n';

    // --- A measurement variable: approximate by nature ---
    double heightCm{170.8};              // binary float cannot store 0.8 exactly
    double twice{heightCm * 2};          // 341.6 stored to ~15-16 significant digits
    std::cout << "twice height: " << twice << '\n';

    // --- Drift demonstration: repeated addition of 0.1 ---
    double sum{0.0};
    for (int i{0}; i < 10; ++i)
    {
        sum += 0.1;                      // each 0.1 is the NEAREST representable double
    }
    std::cout << std::setprecision(17);
    std::cout << "0.1 added ten times: " << sum << '\n';
    // Typical output: 0.99999999999999989  -- close to 1, not equal.
    // Data-science habit: compare floating results with a tolerance,
    // never with ==. Integer counts would have been exact here.

    // --- The mean: cast exactly once, at the division ---
    int scores[]{82, 91, 75, 68, 88};    // scores entered as whole marks (counts of points)
    const int n{5};
    long long total{0};                  // long long: exact even for huge n
    for (int i{0}; i < n; ++i)
    {
        total += scores[i];
    }
    double mean{static_cast<double>(total) / n};   // <-- the single cast
    std::cout << std::setprecision(6);
    std::cout << "total: " << total << " (exact integer)\n";
    std::cout << "mean : " << mean << '\n';

    // --- The classic defect this lecture prevents ---
    int badMean{static_cast<int>(total) / n};      // integer division: 404/5
    std::cout << "integer-divided mean: " << badMean << "   <-- lost .8\n";

    // --- Comparing floating results correctly ---
    double computed{sum};
    const double tolerance{1e-9};
    if (computed > 1.0 - tolerance && computed < 1.0 + tolerance)
    {
        std::cout << "sum is 1 within tolerance 1e-9\n";
    }
    else
    {
        std::cout << "sum differs from 1 by more than the tolerance\n";
    }
    return 0;
}
