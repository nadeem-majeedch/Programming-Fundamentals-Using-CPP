// purpose: a first numerical simulation — repeat a random experiment, count
//          outcomes, and compare EMPIRICAL frequencies with expected ones.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_simulation.cpp -o dssim
// input:   trials n (1 .. 10,000,000). Try: 60   then  10000
//
// MATH FIRST
// ----------
// One fair die: each face has EXPECTED probability 1/6.
// After n trials, face f shows EMPirically   p̂(f) = count(f) / n.
// The law of large numbers says p̂ → 1/6 as n grows — this program *shows*
// that convergence numerically: small n wobbles, large n settles.
// Also: sum of two dice — expected mean of one die is (1+2+...+6)/6 = 3.5;
// the empirical mean  (sum of all faces shown) / n  should approach 3.5.
//
// RANDOMNESS IN STANDARD C++ (no libraries beyond <random>)
//     std::mt19937 engine{seed}   — the random NUMBER ENGINE (deterministic
//                                   given the seed: reproducible runs!)
//     distribution maps engine output to the shape we want:
//         uniform_int_distribution<int> die{1, 6}
//     Reproducibility matters in data work: same seed -> same "random" data,
//     which makes results testable. We use a FIXED seed here on purpose.
//
// EDGE CASES: n <= 0 (no trials -> all proportions undefined), huge n
// (counts must be long long: 10M trials can each add 1 — int would be fine
// at 10M but long long removes the ceiling and the worry).

#include <iostream>
#include <iomanip>
#include <random>

int main()
{
    long long n{};
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "no trials\n";
        return 0;
    }

    const unsigned int seed{42};             // fixed seed: every run is identical
    std::mt19937 engine{seed};
    std::uniform_int_distribution<int> die{1, 6};

    long long counts[6]{};                   // counts[f-1] = times face f appeared
    long long sum{0};                        // sum of all faces shown

    for (long long t{0}; t < n; ++t)
    {
        int face{die(engine)};
        ++counts[face - 1];                  // index shift again: face 1 -> slot 0
        sum += face;
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "trials: " << n << "  (seed " << seed << ", reproducible)\n";
    std::cout << "face  count      empirical  expected\n";
    for (int f{1}; f <= 6; ++f)
    {
        double empirical{static_cast<double>(counts[f - 1]) / n};
        std::cout << "  " << f << "   " << std::setw(9) << counts[f - 1]
                  << "   " << empirical << "    0.1667\n";
    }
    double mean{static_cast<double>(sum) / n};
    std::cout << "mean of faces shown: " << mean
              << "  (expected 3.5)\n";

    // --- what to notice ---
    // n = 60:    empirical proportions scatter far from 0.1667 — noise dominates
    // n = 10000: proportions hug 0.1667 much tighter; mean hugs 3.5
    // The gap between empirical and expected shrinking as n grows IS the
    // law of large numbers, observed rather than believed.
    return 0;
}
