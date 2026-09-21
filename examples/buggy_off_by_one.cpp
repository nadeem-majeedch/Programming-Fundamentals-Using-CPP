// purpose: SEEDED-BUG program for L12/L16 — students must find the three
//          bugs by trace table FIRST, then run to confirm.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic buggy_off_by_one.cpp -o buggy
//
// NOTE: this file intentionally contains logic errors (not syntax errors),
// so it compiles clean but prints WRONG results. That is the lesson.

#include <iostream>

int main()
{
    // Bug 1 (off-by-one): intended to print 1..5, prints 0..4.
    // The loop runs i = 0,1,2,3,4 — five iterations, wrong values.
    std::cout << "Count 1 to 5: ";
    for (int i{0}; i < 5; ++i)
    {
        std::cout << i << ' ';          // BUG: starts at 0, should be 1..5
    }
    std::cout << '\n';

    // Bug 2 (wrong boundary): intended sum of 1..4 = 10, but the condition
    // uses < instead of <=, so it sums 1+2+3 = 6.
    int sum{};
    for (int i{1}; i < 4; ++i)          // BUG: i <= 4 was intended
    {
        sum += i;
    }
    std::cout << "Sum 1..4: " << sum << "   (expected 10)\n";

    // Bug 3 (inverted condition): intended to print only passing scores
    // (>= 60), but prints the failing ones.
    int scores[]{45, 72, 88, 59, 61};
    std::cout << "Passing scores: ";
    for (int i{0}; i < 5; ++i)
    {
        if (scores[i] < 60)             // BUG: < should be >=
        {
            std::cout << scores[i] << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
// Expected output after fixes:
//   Count 1 to 5: 1 2 3 4 5
//   Sum 1..4: 10
//   Passing scores: 72 88 61
