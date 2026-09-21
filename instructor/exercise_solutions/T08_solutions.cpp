// instructor/exercise_solutions/T08_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-091 .. PF-E-101 (Searching and Sorting).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T08_solutions.cpp -o t08
#include <iostream>
#include <iomanip>

namespace e091 { // Linear Search (with sentinel)
int linearSearch(const int a[], int n, int key)
{
    for (int i{0}; i < n; ++i)
        if (a[i] == key)
            return i;
    return -1;
}

void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int key{};
    std::cin >> key;
    while (key != -1)
    {
        int pos{linearSearch(a, n, key)};
        if (pos >= 0)
            std::cout << pos << '\n';
        else
            std::cout << "not found\n";
        std::cin >> key;
    }
}
} // namespace e091

namespace e092 { // Count Comparisons (linear)
int linearSearchCounted(const int a[], int n, int key, long long& comps)
{
    for (int i{0}; i < n; ++i)
    {
        ++comps;
        if (a[i] == key)
            return i;
    }
    return -1;
}

void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int key{};
    std::cin >> key;
    long long comps{0};
    int pos{linearSearchCounted(a, n, key, comps)};
    if (pos >= 0)
        std::cout << pos << " (" << comps << " comparisons)\n";
    else
        std::cout << "not found (" << comps << " comparisons)\n";
    std::cout << "theory: best 1, worst " << n << '\n';
}
} // namespace e092

namespace e093 { // Is It Sorted?
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    bool asc{true}, desc{true};
    for (int i{1}; i < n; ++i)
    {
        if (a[i - 1] > a[i])
            asc = false;
        if (a[i - 1] < a[i])
            desc = false;
    }
    if (asc)
        std::cout << "ascending\n";
    else if (desc)
        std::cout << "descending\n";
    else
        std::cout << "unsorted\n";
}
} // namespace e093

namespace e094 { // Binary Search on Sorted Input
int binarySearch(const int a[], int n, int key)
{
    int low{0};
    int high{n - 1};
    while (low <= high)
    {
        int mid{low + (high - low) / 2};
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    bool sorted{true};
    for (int i{1}; i < n; ++i)
        if (a[i - 1] > a[i])
            sorted = false;
    if (!sorted)
    {
        std::cout << "input not sorted\n";
        return;
    }
    int key{};
    std::cin >> key;
    while (key != -1)
    {
        int pos{binarySearch(a, n, key)};
        if (pos >= 0)
            std::cout << pos << '\n';
        else
            std::cout << "not found\n";
        std::cin >> key;
    }
}
} // namespace e094

namespace e095 { // Selection Sort with Snapshots
void run()
{
    int n{};
    std::cin >> n;
    int a[15]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    long long comps{0};
    long long swaps{0};
    for (int i{0}; i < n - 1; ++i)
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
        {
            ++comps;
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
        {
            int tmp{a[i]};
            a[i] = a[minIdx];
            a[minIdx] = tmp;
            ++swaps;
        }
        std::cout << "pass " << i << ':';
        for (int k{0}; k < n; ++k)
            std::cout << ' ' << a[k];
        std::cout << '\n';
    }
    std::cout << "comparisons: " << comps << '\n' << "swaps: " << swaps << '\n';
}
} // namespace e095

namespace e096 { // Bubble Sort with Early Exit
void run()
{
    int n{};
    std::cin >> n;
    int a[15]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    long long comps{0};
    long long swaps{0};
    int passes{0};
    for (int pass{0}; pass < n - 1; ++pass)
    {
        bool swapped{false};
        for (int j{0}; j < n - 1 - pass; ++j)
        {
            ++comps;
            if (a[j] > a[j + 1])
            {
                int tmp{a[j]};
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                ++swaps;
                swapped = true;
            }
        }
        ++passes;
        std::cout << "pass " << pass << ':';
        for (int k{0}; k < n; ++k)
            std::cout << ' ' << a[k];
        std::cout << '\n';
        if (!swapped)
            break;
    }
    std::cout << "passes: " << passes << '\n'
              << "comparisons: " << comps << '\n' << "swaps: " << swaps << '\n';
}
} // namespace e096

namespace e097 { // Sort Then Binary Search (full workflow)
void run()
{
    int n{}, key{};
    std::cin >> n;
    int values[30]{};
    int index[30]{};
    for (int i{0}; i < n; ++i)
    {
        std::cin >> values[i];
        index[i] = i;
    }
    std::cin >> key;
    for (int i{0}; i < n - 1; ++i) // selection sort moves value AND index
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
            if (values[j] < values[minIdx])
                minIdx = j;
        if (minIdx != i)
        {
            int tv{values[i]};
            values[i] = values[minIdx];
            values[minIdx] = tv;
            int ti{index[i]};
            index[i] = index[minIdx];
            index[minIdx] = ti;
        }
    }
    std::cout << "sorted:";
    for (int i{0}; i < n; ++i)
        std::cout << ' ' << values[i];
    std::cout << '\n';
    int low{0}, high{n - 1}, pos{-1};
    while (low <= high)
    {
        int mid{low + (high - low) / 2};
        if (values[mid] == key)
        {
            pos = mid;
            break;
        }
        if (values[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (pos >= 0)
        std::cout << key << " was originally at index " << index[pos] << '\n';
    else
        std::cout << "not found\n";
}
} // namespace e097

namespace e098 { // Median and Quartiles
void sortArray(int a[], int n)
{
    for (int i{0}; i < n - 1; ++i)
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
            if (a[j] < a[minIdx])
                minIdx = j;
        if (minIdx != i)
        {
            int t{a[i]};
            a[i] = a[minIdx];
            a[minIdx] = t;
        }
    }
}

void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    sortArray(a, n);
    double median;
    if (n % 2 == 1)
        median = a[n / 2];
    else
        median = (a[n / 2 - 1] + a[n / 2]) / 2.0;
    int half{n / 2};
    double q1, q3;
    if (half % 2 == 1)
    {
        q1 = a[half / 2];
        q3 = a[n - 1 - half / 2];
    }
    else
    {
        q1 = (a[half / 2 - 1] + a[half / 2]) / 2.0;
        q3 = (a[n - half / 2] + a[n - half / 2 - 1]) / 2.0;
    }
    std::cout << "sorted:";
    for (int i{0}; i < n; ++i)
        std::cout << ' ' << a[i];
    std::cout << '\n'
              << std::fixed << std::setprecision(1) << "median: " << median
              << '\n' << "Q1: " << q1 << '\n' << "Q3: " << q3 << '\n';
}
} // namespace e098

namespace e099 { // Deduplicate (sorted)
void run()
{
    int n{};
    std::cin >> n;
    int a[30]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    // sort
    for (int i{0}; i < n - 1; ++i)
    {
        int minIdx{i};
        for (int j{i + 1}; j < n; ++j)
            if (a[j] < a[minIdx])
                minIdx = j;
        if (minIdx != i)
        {
            int t{a[i]};
            a[i] = a[minIdx];
            a[minIdx] = t;
        }
    }
    // compact: duplicates are adjacent in sorted order
    int out{1};
    for (int i{1}; i < n; ++i)
    {
        if (a[i] != a[out - 1])
        {
            a[out] = a[i];
            ++out;
        }
    }
    std::cout << "unique: " << out << '\n';
    for (int i{0}; i < out; ++i)
        std::cout << a[i] << (i < out - 1 ? " " : "\n");
}
} // namespace e099

namespace e100 { // Frequency Sort (two-key ordering)
void run()
{
    int n{};
    std::cin >> n;
    int table[100]{};
    for (int i{0}; i < n; ++i)
    {
        int v{};
        std::cin >> v;
        ++table[v];
    }
    // collect distinct values
    int values[100]{};
    int distinct{0};
    for (int v{0}; v < 100; ++v)
        if (table[v] > 0)
            values[distinct++] = v;
    // selection sort by (count desc, value asc)
    for (int i{0}; i < distinct - 1; ++i)
    {
        int best{i};
        for (int j{i + 1}; j < distinct; ++j)
        {
            if (table[values[j]] > table[values[best]])
                best = j;
            else if (table[values[j]] == table[values[best]]
                     && values[j] < values[best])
                best = j;
        }
        if (best != i)
        {
            int t{values[i]};
            values[i] = values[best];
            values[best] = t;
        }
    }
    for (int i{0}; i < distinct; ++i)
        std::cout << values[i] << ':' << table[values[i]] << '\n';
}
} // namespace e100

namespace e101 { // Search Strategy Showdown
void run()
{
    int n{}, k{};
    std::cin >> n;
    static int a[2000]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    std::cin >> k;
    long long linearComps{0};
    long long binaryComps{0};
    for (int q{0}; q < k; ++q)
    {
        int key{};
        std::cin >> key;
        for (int i{0}; i < n; ++i)
        {
            ++linearComps;
            if (a[i] == key)
                break;
        }
        int low{0}, high{n - 1};
        while (low <= high)
        {
            ++binaryComps;
            int mid{low + (high - low) / 2};
            if (a[mid] == key)
                break;
            if (a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    std::cout << "linear: " << linearComps << '\n'
              << "sort+binary: " << binaryComps << " (sort cost 0: input sorted)\n";
    std::cout << "verdict: binary wins when k << n (amortizes the sort)\n";
}
} // namespace e101

int main()
{
    e093::run();
    e095::run();
    e098::run();
    e099::run();
    return 0;
}
