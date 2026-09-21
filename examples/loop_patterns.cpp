// purpose: the six named loop patterns from L10, each as a small labeled
//          demo — accumulate, count-if, find-first, validate-every,
//          enumerate-pairs, table-render.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic loop_patterns.cpp -o patterns

#include <iostream>

int main()
{
    int values[]{12, 5, 8, 21, 4, 8};   // demo data (arrays formal in M9)
    const int N{6};

    // 1. ACCUMULATE: total of all elements
    int total{};
    for (int i{0}; i < N; ++i)
    {
        total += values[i];
    }
    std::cout << "1. ACCUMULATE    total        = " << total << '\n';

    // 2. COUNT-IF: how many equal 8?
    int count{};
    for (int i{0}; i < N; ++i)
    {
        if (values[i] == 8)
        {
            ++count;
        }
    }
    std::cout << "2. COUNT-IF      equals 8     = " << count << " times\n";

    // 3. FIND-FIRST: first element > 10, then stop (break)
    for (int i{0}; i < N; ++i)
    {
        if (values[i] > 10)
        {
            std::cout << "3. FIND-FIRST    first > 10   = " << values[i]
                      << " at index " << i << '\n';
            break;                       // exit the nearest loop
        }
    }

    // 4. VALIDATE-EVERY: are all values positive? (flag + early exit)
    bool all_positive{true};
    for (int i{0}; i < N; ++i)
    {
        if (values[i] <= 0)
        {
            all_positive = false;
            break;
        }
    }
    std::cout << "4. VALIDATE-ALL  all positive = " << all_positive << '\n';

    // 5. ENUMERATE-PAIRS: all unordered pairs i < j
    std::cout << "5. PAIRS: ";
    for (int i{0}; i < N; ++i)
    {
        for (int j{i + 1}; j < N; ++j)
        {
            std::cout << "(" << values[i] << "," << values[j] << ") ";
        }
    }
    std::cout << '\n';

    // 6. TABLE-RENDER: 3x3 multiplication table (nested counted loops)
    std::cout << "6. TABLE:\n";
    for (int row{1}; row <= 3; ++row)
    {
        for (int col{1}; col <= 3; ++col)
        {
            std::cout << row * col << '\t';
        }
        std::cout << '\n';
    }

    // 7. CONTINUE demo: skip evens while summing odds
    int odd_sum{};
    for (int i{0}; i < N; ++i)
    {
        if (values[i] % 2 == 0)
        {
            continue;               // jump to the next iteration
        }
        odd_sum += values[i];
    }
    std::cout << "7. CONTINUE      odd sum      = " << odd_sum << '\n';

    return 0;
}
