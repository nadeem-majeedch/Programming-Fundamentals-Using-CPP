// purpose: sentinel-controlled while loop and digit-sum via % and / —
//          used in L09 (three-part loop discipline + trace tables).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic loops_sum_digits.cpp -o loopsum

#include <iostream>

int main()
{
    // --- Sentinel-controlled loop: read until user types -1 ---
    int sum{0};        // accumulator: starts at 0
    int count{0};      // counter:     starts at 0
    int mark{};

    std::cout << "Enter marks (-1 to stop): ";
    std::cin >> mark;                    // priming read (before the loop)

    while (std::cin && mark != -1)       // test at the top: may run 0 times;
                                         // the stream check also ends the loop
                                         // when input ends without a sentinel
    {
        sum += mark;                     // process
        ++count;

        std::cin >> mark;                // update read (last statement!)
    }

    if (count > 0)
    {
        std::cout << "Read " << count << " marks, sum = " << sum << '\n';
    }
    else
    {
        std::cout << "No marks entered.\n";
    }

    // --- Digit sum: while + % 10 + / 10 (from L05's digit extraction) ---
    int number{};
    std::cout << "Enter a positive number: ";
    std::cin >> number;

    int digit_sum{0};
    int work{number};
    while (work > 0)          // runs log10(number) times
    {
        digit_sum += work % 10;   // take the last digit
        work /= 10;               // drop the last digit
    }
    std::cout << "Digit sum of " << number << " = " << digit_sum << '\n';

    return 0;
}
