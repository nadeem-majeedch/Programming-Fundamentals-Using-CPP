// purpose: the six core array algorithms as functions — fill/print, sum/
//          average, min/max with index, count-if, reverse-in-place, linear
//          search — used in L18 and re-used across Modules 12-14.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic array_algorithms.cpp -o arralg

#include <iostream>

// Print the array in one line.  Read-only: const array parameter.
void print_array(const int a[], int n)
{
    for (int i{0}; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

// Sum of all elements (accumulator pattern).
int sum(const int a[], int n)
{
    int total{};
    for (int i{0}; i < n; ++i)
    {
        total += a[i];
    }
    return total;
}

// Minimum value AND its index (two outputs -> two int& parameters).
void min_with_index(const int a[], int n, int& min_value, int& min_index)
{
    min_value = a[0];
    min_index = 0;
    for (int i{1}; i < n; ++i)
    {
        if (a[i] < min_value)
        {
            min_value = a[i];
            min_index = i;
        }
    }
}

// Count elements satisfying a property shown here as "even".
int count_even(const int a[], int n)
{
    int count{};
    for (int i{0}; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            ++count;
        }
    }
    return count;
}

// Reverse IN PLACE: swap symmetric pairs (i, n-1-i).
void reverse_in_place(int a[], int n)
{
    for (int i{0}; i < n / 2; ++i)
    {
        int temp{a[i]};
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

// Linear search: index of first occurrence, or -1.
int linear_search(const int a[], int n, int key)
{
    for (int i{0}; i < n; ++i)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int N{6};
    int data[N]{12, 5, 8, 21, 4, 8};

    std::cout << "data            : ";
    print_array(data, N);

    std::cout << "sum             : " << sum(data, N) << '\n';
    std::cout << "average         : "
              << static_cast<double>(sum(data, N)) / N << '\n';

    int min_value{};
    int min_index{};
    min_with_index(data, N, min_value, min_index);
    std::cout << "min             : " << min_value << " at index "
              << min_index << '\n';

    std::cout << "even count      : " << count_even(data, N) << '\n';

    reverse_in_place(data, N);
    std::cout << "reversed        : ";
    print_array(data, N);

    std::cout << "search 21       : index "
              << linear_search(data, N, 21) << '\n';
    std::cout << "search 99       : index "
              << linear_search(data, N, 99) << " (-1 = not found)\n";

    return 0;
}
