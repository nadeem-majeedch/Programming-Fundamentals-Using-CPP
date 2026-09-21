// Lab 06 · digit_reversal.cpp — trace-table subject.
//
// Task: hand-trace with input 907 BEFORE running. Fill the trace table:
//   pass | n  | digit | reversed
//   -----+----+-------+---------
//   0    |907 |       | 0
//   ...  |    |       |
//
// Then run and check: expected final reversed = 709.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic digit_reversal.cpp -o dr

#include <iostream>

int main()
{
    int n{};
    std::cin >> n;
    int reversed{0};
    while (n > 0)
    {
        int digit{n % 10};
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    std::cout << reversed << '\n';
    return 0;
}
