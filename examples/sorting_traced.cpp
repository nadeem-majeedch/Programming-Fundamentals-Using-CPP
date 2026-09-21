// purpose: selection sort and bubble sort with per-pass snapshots and
//          comparison/exchange counters — used in L24.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic sorting_traced.cpp -o sort

#include <iostream>

void swap(int& a, int& b)
{
    int temp{a};
    a = b;
    b = temp;
}

void print_array(const int a[], int n)
{
    for (int i{0}; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

// SELECTION SORT: find min of the unsorted suffix, swap it into place.
// Invariant: positions [0, i) are final and sorted.
void selection_sort_traced(int a[], int n)
{
    int comparisons{0};
    int exchanges{0};
    for (int i{0}; i < n - 1; ++i)
    {
        int min_index{i};
        for (int j{i + 1}; j < n; ++j)
        {
            ++comparisons;
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(a[i], a[min_index]);
            ++exchanges;
        }
        std::cout << "  pass " << i << ": ";
        print_array(a, n);
    }
    std::cout << "  selection: " << comparisons << " comparisons, "
              << exchanges << " exchanges\n";
}

// BUBBLE SORT (optimized): adjacent compares, shrinking bound, early exit.
// Invariant: after pass k, the last k elements are final (largest bubbles up).
void bubble_sort_traced(int a[], int n)
{
    int comparisons{0};
    int exchanges{0};
    for (int k{0}; k < n - 1; ++k)
    {
        bool swapped{false};
        for (int j{0}; j < n - 1 - k; ++j)   // shrink: last k already final
        {
            ++comparisons;
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ++exchanges;
                swapped = true;
            }
        }
        std::cout << "  pass " << k << ": ";
        print_array(a, n);
        if (!swapped)
        {
            std::cout << "  early exit: no swaps in this pass\n";
            break;
        }
    }
    std::cout << "  bubble: " << comparisons << " comparisons, "
              << exchanges << " exchanges\n";
}

int main()
{
    int data1[]{5, 2, 9, 1, 7};
    int data2[]{5, 2, 9, 1, 7};
    const int N{5};

    std::cout << "SELECTION SORT of {5,2,9,1,7}:\n";
    selection_sort_traced(data1, N);

    std::cout << "BUBBLE SORT of {5,2,9,1,7}:\n";
    bubble_sort_traced(data2, N);

    // Best case for optimized bubble: already sorted input.
    int sorted[]{1, 2, 3, 4, 5};
    std::cout << "BUBBLE SORT best case {1,2,3,4,5}:\n";
    bubble_sort_traced(sorted, N);

    return 0;
}
