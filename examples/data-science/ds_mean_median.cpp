// purpose: mean and median from scratch for a dataset of observations —
//          formula-first, with the empty-input case and the sorted rule.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_mean_median.cpp -o dsmean
// input:   n, then n integers (readings). Try: 7  88 92 79 85 91 72 95
//
// MATH FIRST
// ----------
// MEAN  x̄ = (x1 + x2 + ... + xn) / n            -- defined only for n >= 1
// MEDIAN: sort the data ascending, then
//     n odd  ->  the middle value  x((n+1)/2)   (1-based position)
//     n even ->  average of the two middle values  (x(n/2) + x(n/2+1)) / 2
// The median needs SORTED data; the mean does not. That is why this program
// copies + sorts first (insertion sort from L24), while the mean is one loop.
//
// EDGE CASES
//     n <= 0            -> no data: mean/median undefined, report "no data"
//     n = 1             -> mean = median = the single value
//     even n            -> median is the average (may be a .5 value: use double)

#include <iostream>
#include <iomanip>

// insertionSort: sorts a ascending in place (from L24, unchanged).
void insertionSort(int a[], int n)
{
    for (int i{1}; i < n; ++i)
    {
        int key{a[i]};
        int j{i - 1};
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

// mean: sum divided by count. Precondition: n >= 1. Cast once, at the division.
double mean(const int a[], int n)
{
    long long sum{0};
    for (int i{0}; i < n; ++i)
    {
        sum += a[i];
    }
    return static_cast<double>(sum) / n;
}

// median: middle of SORTED data; even n averages the two middles.
// Precondition: n >= 1 and a is sorted ascending.
double median(const int a[], int n)
{
    if (n % 2 == 1)
    {
        return a[n / 2];                     // odd: index (n+1)/2 - 1 in 0-based
    }
    return (a[n / 2 - 1] + a[n / 2]) / 2.0;  // even: average of the two middles
}

int main()
{
    int n{};
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "no data\n";            // empty / invalid dataset: bail cleanly
        return 0;
    }

    int data[1000]{};
    for (int i{0}; i < n; ++i)
    {
        std::cin >> data[i];
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "count: " << n << '\n';
    std::cout << "mean  : " << mean(data, n) << "   (no sorting needed)\n";

    insertionSort(data, n);                  // median needs order first
    std::cout << "sorted: ";
    for (int i{0}; i < n; ++i)
    {
        std::cout << data[i] << (i + 1 < n ? ' ' : '\n');
    }
    std::cout << "median: " << median(data, n) << '\n';

    // --- sanity anchor for the sample input ---
    // 7 readings 72 79 85 88 91 92 95 -> median is the 4th value: 88
    // mean = 602/7 = 86.0 (exactly, for this sample)
    return 0;
}
