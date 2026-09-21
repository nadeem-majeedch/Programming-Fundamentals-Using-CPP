// purpose: sorting a dataset of observations and reading ranks off positions —
//          selection sort on data, then min/median/max fall out of the order.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_sort_observations.cpp -o dssort
// input:   n, then n integers (e.g., exam scores). Try: 8  72 91 85 85 68 79 95 88
//
// MATH FIRST
// ----------
// After sorting ascending:  position p (1-based) = the p-th smallest value.
//     minimum  = x(1)          maximum = x(n)
//     median   = x((n+1)/2)                (n odd)
//              = (x(n/2) + x(n/2+1)) / 2   (n even)
//     rank of a VALUE v = its position(s); equal values share a rank band —
//     reporting "68 is rank 1 of 8" is only meaningful together with n.
//
// WHY SORT AT ALL: many summary statistics (median, quartiles, percentiles)
// are *order statistics* — they are defined by position in sorted data.
// The sort is the whole computation for them; the reporting is a lookup.
//
// EDGE CASES: n = 1 (every statistic is the same value), duplicate values
// (85 twice below: median lands between/equal to duplicates), already-sorted
// input (selection sort still does its full scan — O(n^2) compares, few swaps).

#include <iostream>
#include <iomanip>

// selectionSort: ascending, in place (from L24). Returns swap count so the
// report can show *cost*, not just results — a data-science habit.
int selectionSort(int a[], int n)
{
    int swaps{0};
    for (int i{0}; i < n - 1; ++i)
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int t{a[i]};
            a[i] = a[minIdx];
            a[minIdx] = t;
            ++swaps;
        }
    }
    return swaps;
}

int main()
{
    int n{};
    if (!(std::cin >> n) || n <= 0 || n > 1000)
    {
        std::cout << "no data\n";
        return 0;
    }

    int data[1000]{};
    for (int i{0}; i < n; ++i)
    {
        std::cin >> data[i];
    }

    int swaps{selectionSort(data, n)};

    std::cout << "sorted: ";
    for (int i{0}; i < n; ++i)
    {
        std::cout << data[i] << (i + 1 < n ? ' ' : '\n');
    }
    if (n == 1)
    {
        std::cout << '\n';
    }

    double median{};
    if (n % 2 == 1)
    {
        median = data[n / 2];
    }
    else
    {
        median = (data[n / 2 - 1] + data[n / 2]) / 2.0;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "min    : " << data[0] << '\n';
    std::cout << "median : " << median << '\n';
    std::cout << "max    : " << data[n - 1] << '\n';
    std::cout << "swaps  : " << swaps << " (selection sort cost)\n";

    // top-k peek: the k largest, printed from largest down (k capped by n)
    const int k{(n < 3) ? n : 3};
    std::cout << "top " << k << " : ";
    for (int p{0}; p < k; ++p)
    {
        std::cout << data[n - 1 - p] << (p + 1 < k ? ' ' : '\n');
    }
    if (k == 0)
    {
        std::cout << '\n';
    }

    // --- sample check: sorted 68 72 79 85 85 88 91 95 ---
    //   median = (85 + 85)/2 = 85.0; min 68; max 95; top3 = 95 91 88
    return 0;
}
