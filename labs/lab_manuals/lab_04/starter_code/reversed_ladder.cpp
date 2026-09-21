// Lab 04 · reversed_ladder.cpp — bug-hunt file.
// Compiles clean; the defect is LOGIC-stage.
//
// Documented behavior: score 95 must print A.
// Actual: 95 prints D. Trace the ladder to explain WHY, then fix the
// order (not the tests).
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic reversed_ladder.cpp -o rl

#include <iostream>

int main()
{
    int score{};
    std::cin >> score;

    if (score >= 60)
        std::cout << "D\n";
    else if (score >= 70)
        std::cout << "C\n";
    else if (score >= 80)
        std::cout << "B\n";
    else if (score >= 90)
        std::cout << "A\n";
    else
        std::cout << "F\n";
    return 0;
}
