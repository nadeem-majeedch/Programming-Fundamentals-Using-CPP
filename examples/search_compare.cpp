// purpose: linear vs binary search with comparison counters, plus the
//          sorted-precondition violation demo — used in L23.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic search_compare.cpp -o search

#include <iostream>

// Linear search with a comparison counter (for evidence, not for production).
int linear_search_count(const int a[], int n, int key, int& comparisons)
{
    comparisons = 0;
    for (int i{0}; i < n; ++i)
    {
        ++comparisons;
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Binary search: PRECONDITION — a[] is sorted ascending.
// mid uses the overflow-safe form low + (high - low) / 2.
int binary_search_count(const int a[], int n, int key, int& comparisons)
{
    comparisons = 0;
    int low{0};
    int high{n - 1};
    while (low <= high)                  // '<' instead of '<=' is a classic bug
    {
        int mid{low + (high - low) / 2}; // recomputed EVERY iteration
        ++comparisons;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            low = mid + 1;               // discard left half
        }
        else
        {
            high = mid - 1;              // discard right half
        }
    }
    return -1;
}

int main()
{
    // Sorted data: both searches apply.
    const int N{16};
    int sorted[N]{2, 5, 8, 12, 16, 23, 38, 42, 56, 61, 72, 88, 91, 97, 99, 105};

    int comparisons{};
    int idx{linear_search_count(sorted, N, 91, comparisons)};
    std::cout << "linear : found 91 at index " << idx << " after "
              << comparisons << " comparisons\n";

    idx = binary_search_count(sorted, N, 91, comparisons);
    std::cout << "binary : found 91 at index " << idx << " after "
              << comparisons << " comparisons (max should be 5 = log2(16))\n";

    // Worst case for linear: absent key.
    idx = linear_search_count(sorted, N, 999, comparisons);
    std::cout << "linear : absent key -> " << idx << " after "
              << comparisons << " comparisons\n";
    idx = binary_search_count(sorted, N, 999, comparisons);
    std::cout << "binary : absent key -> " << idx << " after "
              << comparisons << " comparisons\n";

    // Precondition violation: binary search on UNSORTED data silently
    // returns a wrong answer (no crash!).
    int unsorted[]{88, 2, 99, 5, 23};
    idx = binary_search_count(unsorted, 5, 99, comparisons);
    std::cout << "binary on UNSORTED data for 99 -> index " << idx
              << " (garbage: precondition violated; a["
              << (idx >= 0 ? idx : 0) << "] = "
              << (idx >= 0 ? unsorted[idx] : unsorted[0]) << ")\n";

    return 0;
}
