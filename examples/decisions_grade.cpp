// purpose: if / else-if chain design in three versions — naive (buggy),
//          corrected, and guard-clause style — used in L07.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic decisions_grade.cpp -o grade

#include <iostream>

int main()
{
    int score{};

    std::cout << "Enter score (0-100): ";
    if (!(std::cin >> score))
    {
        std::cout << "Not a number.\n";
        return 1;
    }

    // --- Version 1: NAIVE — the classic ordering bug ---------------
    // (kept for comparison; a score of 95 prints "D" because the first
    //  matching branch wins, and 95 >= 60 matches before 95 >= 90 could)
    // if (score >= 60) { std::cout << "D\n"; }
    // else if (score >= 70) { std::cout << "C\n"; }
    // else if (score >= 80) { std::cout << "B\n"; }
    // else if (score >= 90) { std::cout << "A\n"; }
    // else { std::cout << "F\n"; }

    // --- Version 2: CORRECTED — descending order, most specific first ---
    if (score >= 90)
    {
        std::cout << "Grade: A\n";
    }
    else if (score >= 80)
    {
        std::cout << "Grade: B\n";
    }
    else if (score >= 70)
    {
        std::cout << "Grade: C\n";
    }
    else if (score >= 60)
    {
        std::cout << "Grade: D\n";
    }
    else
    {
        std::cout << "Grade: F\n";
    }

    // --- Version 3: RANGE CHECK done right (and the silent bug beside it) ---
    bool valid{score >= 0 && score <= 100};
    std::cout << "valid range check: " << valid << '\n';

    // bool wrong{0 <= score <= 100};   // always true! compiles with a
    // warning under -Wall in most compilers; it means (0 <= score) <= 100.

    return 0;
}
