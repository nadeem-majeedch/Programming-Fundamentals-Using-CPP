// Lab 08 · failed_swap.cpp — bug-hunt file (PREDICT BEFORE RUNNING).
//
// On paper: what do a and b print, and WHY? Then fix TWO ways:
//   fix A — reference parameters
//   fix B — pointer parameters
// The corrected program must print 9 5 (b a).
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic failed_swap.cpp -o fs

#include <iostream>

void mySwap(int x, int y)
{
    int tmp{x};
    x = y;
    y = tmp;
}

int main()
{
    int a{5};
    int b{9};
    mySwap(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
