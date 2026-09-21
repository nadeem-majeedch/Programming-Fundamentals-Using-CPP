// Lab 05 · missing_update.cpp — bug-hunt file (PREDICT BEFORE RUNNING).
//
// Task: read the loop and answer on paper:
//   1. Why does this loop never terminate?
//   2. What would make it terminate (minimal change)?
// THEN run it with a timeout (or Ctrl+C) and confirm your prediction.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic missing_update.cpp -o mu

#include <iostream>

int main()
{
    int i{0};
    while (i < 10)
    {
        std::cout << i << ' ' << std::flush;   // prints forever — why?
    }
    std::cout << '\n';
    return 0;
}
