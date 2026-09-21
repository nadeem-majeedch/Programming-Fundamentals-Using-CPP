// DEMO-05 · Three type conversions for the data student: truncating cast,
// correct cast-before-divide mean, and safe proportion (empty-data guarded).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic demo05_ds_conversions.cpp -o demo05
// input:   none (fixed demonstration data)
//
// Used in demonstrations/demo_group2_operators.md (DEMO-05, DS angle) to make
// integer division, cast placement, and 0..1 proportions observable.

#include <iostream>
#include <vector>

int main()
{
    const std::vector<int> readings{88, 92, 79, 74};

    // 1. Truncating cast: double -> int (fraction lost, no rounding).
    const double raw_mean = 82.75;
    std::cout << "static_cast<int>(82.75) = "
              << static_cast<int>(raw_mean) << '\n'; // 82

    // 2. Mean: WRONG (int division happens first) vs RIGHT (cast before /).
    int sum = 0;
    for (int r : readings)
        sum += r;
    const int n = static_cast<int>(readings.size());

    const int wrong_mean = sum / n;                                  // int / int
    const double right_mean = static_cast<double>(sum) / n;          // cast first
    std::cout << "sum=" << sum << " n=" << n << '\n';
    std::cout << "wrong  sum/n (int)  = " << wrong_mean << '\n';     // 83
    std::cout << "right  cast first    = " << right_mean << '\n';    // 83.25

    // 3. Proportion in 0..1: even readings / all readings, guarded for n==0.
    int evens = 0;
    for (int r : readings)
        if (r % 2 == 0) ++evens;

    if (n == 0) {
        std::cout << "proportion: undefined (no data)\n";
    } else {
        const double p = static_cast<double>(evens) / n;
        std::cout << "proportion even = " << p << '\n';              // 0.75
    }
    return 0;
}
