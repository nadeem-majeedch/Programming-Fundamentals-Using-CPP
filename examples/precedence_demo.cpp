// purpose: precedence, associativity, integer vs floating-point division,
//          and negative-modulo behavior — used in L05 for predict-then-run.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic precedence_demo.cpp -o prec

#include <iostream>

int main()
{
    // --- Precedence: * / % bind tighter than + - ---
    std::cout << "2 + 3 * 4        = " << 2 + 3 * 4 << '\n';        // 14
    std::cout << "(2 + 3) * 4      = " << (2 + 3) * 4 << '\n';      // 20

    // Same tier (* / %): evaluated left to right
    std::cout << "20 / 2 * 5        = " << 20 / 2 * 5 << '\n';       // 50, not 2

    // --- Integer division truncates toward zero ---
    std::cout << "7 / 2              = " << 7 / 2 << '\n';         // 3
    std::cout << "-7 / 2             = " << -7 / 2 << '\n';        // -3 (not -4)
    std::cout << "7.0 / 2            = " << 7.0 / 2 << '\n';       // 3.5

    // --- Modulo: remainder; sign follows the DIVIDEND in C++ ---
    std::cout << "7 % 2              = " << 7 % 2 << '\n';         // 1
    std::cout << "-7 % 2             = " << -7 % 2 << '\n';        // -1 (machine-checked)

    // --- Digit extraction: the / 10 and % 10 pair ---
    int number{927};
    int ones{number % 10};          // 7
    int tens{(number / 10) % 10};   // 2
    int hundreds{number / 100};     // 9
    std::cout << "digits of " << number << ": "
              << hundreds << " " << tens << " " << ones << '\n';

    // --- The classic average bug: precedence AND truncation ---
    int a{3};
    int b{4};
    std::cout << "a + b / 2          = " << a + b / 2 << '\n';    // 5  (precedence bug)
    std::cout << "(a + b) / 2        = " << (a + b) / 2 << '\n';  // 3  (truncation bug)
    std::cout << "(a + b) / 2.0      = " << (a + b) / 2.0 << '\n';// 3.5 (correct)

    return 0;
}
