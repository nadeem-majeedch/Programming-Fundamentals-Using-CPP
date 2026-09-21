// Lab 03 · workbench.cpp — expression workbench.
// Predict each value on paper FIRST, then run and reconcile.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic workbench.cpp -o workbench

#include <iostream>

int main()
{
    std::cout << "1. 2 + 3 * 4          = " << 2 + 3 * 4 << '\n';
    std::cout << "2. (2 + 3) * 4        = " << (2 + 3) * 4 << '\n';
    std::cout << "3. 17 / 5             = " << 17 / 5 << '\n';
    std::cout << "4. 17 % 5             = " << 17 % 5 << '\n';
    std::cout << "5. 17.0 / 5           = " << 17.0 / 5 << '\n';
    std::cout << "6. 7 / 2 * 2          = " << 7 / 2 * 2 << '\n';
    int a{5};
    a += 3 * 2;
    std::cout << "7. a += 3 * 2         = " << a << '\n';
    std::cout << "8. static_cast<int>(4.9) = " << static_cast<int>(4.9) << '\n';
    return 0;
}
