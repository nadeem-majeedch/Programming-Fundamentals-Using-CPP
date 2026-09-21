// purpose: frequency counting for categorical/graded data — index shifting,
//          the mode by counting, and relative frequencies as proportions.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_frequency_counts.cpp -o dsfreq
// input:   n, then n survey ratings 1..5. Try: 10  1 3 3 5 2 3 4 5 3 2
//
// MATH FIRST
// ----------
// FREQUENCY of category c:   f(c) = how many observations equal c
// RELATIVE frequency:        f(c) / n            (a proportion in [0, 1])
// Mode: the value(s) with the LARGEST frequency. There can be ties —
// a dataset can be bimodal; this program reports the smallest tied value
// and states how many share the maximum (honest reporting beats hiding ties).
//
// INDEX SHIFTING (the classic beginner trap)
//     ratings run 1..5 but C++ indices run 0..4, so count[r] means:
//         count[r - 1]     (subtract the offset when WRITING)
//         value r          (add the offset when READING)
// Alternative: waste slot 0 and use count[1..5] — same idea, different offset.
//
// EDGE CASES: n = 0 (no data), values outside 1..5 (count as invalid,
// do not corrupt the table), every value the same (single-spike table).

#include <iostream>
#include <iomanip>

const int MIN_RATING{1};
const int MAX_RATING{5};

int main()
{
    int n{};
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "no data\n";
        return 0;
    }

    int counts[MAX_RATING - MIN_RATING + 1]{};   // {0,0,0,0,0} — zero-initialized
    int invalid{0};

    for (int i{0}; i < n; ++i)
    {
        int r{};
        std::cin >> r;
        if (r < MIN_RATING || r > MAX_RATING)
        {
            ++invalid;                           // out-of-range: not a category
            continue;
        }
        ++counts[r - MIN_RATING];                // <-- the index shift
    }

    int validCount{n - invalid};

    std::cout << "rating  count  relative\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int r{MIN_RATING}; r <= MAX_RATING; ++r)
    {
        double relative{0.0};
        if (validCount > 0)
        {
            relative = static_cast<double>(counts[r - MIN_RATING]) / validCount;
        }
        std::cout << "  " << r << "     " << counts[r - MIN_RATING]
                  << "      " << relative << '\n';
    }
    if (invalid > 0)
    {
        std::cout << "(" << invalid << " invalid values excluded)\n";
    }

    // --- mode by counting: scan the table, not the data ---
    int mode{MIN_RATING};
    int ties{1};
    for (int r{MIN_RATING + 1}; r <= MAX_RATING; ++r)
    {
        if (counts[r - MIN_RATING] > counts[mode - MIN_RATING])
        {
            mode = r;
            ties = 1;
        }
        else if (counts[r - MIN_RATING] == counts[mode - MIN_RATING] &&
                 counts[mode - MIN_RATING] > 0)
        {
            ++ties;                              // another category shares the max
        }
    }
    std::cout << "mode : " << mode;
    if (ties > 1)
    {
        std::cout << " (bimodal/multimodal: " << ties << " categories tie)";
    }
    std::cout << '\n';

    // --- sample check: 10 ratings -> counts 1,2,4,1,2; mode 3 (4 times) ---
    return 0;
}
