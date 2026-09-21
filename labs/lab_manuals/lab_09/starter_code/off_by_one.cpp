// Lab 09 · off_by_one.cpp — bug-hunt file (READ, DO NOT RUN YET).
//
// Two defects, both LOGIC-stage. Find them on paper first:
//   Defect A: the fill loop writes past the end of the array —
//             undefined behavior, may "work" today and crash tomorrow.
//   Defect B: the sum loop skips the LAST element.
//
// Documented correct behavior for input n=4, values 3 1 4 1:
//   prints "3 1 4 1" then "sum: 9".
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic off_by_one.cpp -o obo

#include <iostream>

int main()
{
    const int SIZE{10};
    int a[SIZE]{};
    int n{};
    std::cin >> n;

    for (int i{0}; i <= n; ++i)        // Defect A lives here
        std::cin >> a[i];

    int sum{0};
    for (int i{0}; i < n - 1; ++i)     // Defect B lives here
        sum += a[i];

    for (int i{0}; i < n; ++i)
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    std::cout << "sum: " << sum << '\n';
    return 0;
}
