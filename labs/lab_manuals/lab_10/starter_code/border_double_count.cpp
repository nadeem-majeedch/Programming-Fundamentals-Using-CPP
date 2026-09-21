// Lab 10 · border_double_count.cpp — bug-hunt file.
//
// Border sum of a 3x3 grid with distinct values 1..9:
//   documented correct answer: 1+2+3+4+6+7+8+9 = 40
//   actual (corners 1,3,7,9 counted twice): 60 — verified before publication
//
// Task: explain the double-count from the loop structure, then fix with
// the border predicate r==0 || r==ROWS-1 || c==0 || c==COLS-1 in ONE pass.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic border_double_count.cpp -o bd

#include <iostream>

int main()
{
    const int ROWS{3};
    const int COLS{3};
    int g[ROWS][COLS]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int sum{0};
    for (int c{0}; c < COLS; ++c)     // top and bottom rows (all columns)
    {
        sum += g[0][c];
        sum += g[ROWS - 1][c];
    }
    for (int r{0}; r < ROWS; ++r)     // left and right columns (ALL rows)
    {
        sum += g[r][0];               // corner cells are added a SECOND
        sum += g[r][COLS - 1];        // time here — the double-count
    }
    std::cout << "border: " << sum << '\n';
    return 0;
}
