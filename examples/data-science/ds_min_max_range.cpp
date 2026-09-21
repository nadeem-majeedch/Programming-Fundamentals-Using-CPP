// purpose: min, max, and range of a dataset with sentinel input —
//          init-from-first-element rule, one-pass trackers, empty-input case.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_min_max_range.cpp -o dsminmax
// input:   integers until sentinel -999 (sentinel is NOT data). Try: 4 17 9 22 -999
//
// MATH FIRST
// ----------
// min  = the smallest observation          range = max - min
// Both trackers need an ORDERING-free definition: they are "the value v such
// that no other value is smaller/larger". Computing them takes one pass:
//     start: best = first observation
//     each next value v:  if v > best_max, best_max = v
//                         if v < best_min, best_min = v
// WHY INIT FROM THE FIRST DATA VALUE (not 0, not ±infinity):
//     data may be all negative (then 0 is wrong as a max) or all above 1000
//     (then 0 is wrong as a min). The first element is always a real value.
//
// EDGE CASES
//     first value is the sentinel -> empty dataset: report "no data"
//     single value                -> min = max, range = 0
//     equal values                -> fine; trackers just never update

#include <iostream>
#include <iomanip>

const int SENTINEL{-999};

int main()
{
    std::cout << "enter readings, end with " << SENTINEL << ":\n";

    int first{};
    if (!(std::cin >> first) || first == SENTINEL)
    {
        std::cout << "no data\n";            // empty dataset: min/max undefined
        return 0;
    }

    int minValue{first};                     // init from a REAL data value
    int maxValue{first};
    int count{1};
    long long sum{first};                    // bonus running sum for the report

    int v{};
    while (std::cin >> v && v != SENTINEL)   // priming read done above
    {
        if (v < minValue)
        {
            minValue = v;
        }
        if (v > maxValue)
        {
            maxValue = v;
        }
        ++count;
        sum += v;
    }

    int range{maxValue - minValue};
    double mean{static_cast<double>(sum) / count};

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "count: " << count << '\n';
    std::cout << "min  : " << minValue << '\n';
    std::cout << "max  : " << maxValue << '\n';
    std::cout << "range: " << range << '\n';
    std::cout << "mean : " << mean << '\n';

    // --- sample check: 4 17 9 22 -> count 4, min 4, max 22, range 18, mean 13.0 ---
    return 0;
}
