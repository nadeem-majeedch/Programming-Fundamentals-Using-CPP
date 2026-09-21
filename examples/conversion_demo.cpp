// purpose: implicit promotion, assignment conversion, static_cast, and
//          char codes — used in L06 (predict-first, then run).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic conversion_demo.cpp -o conv

#include <iostream>

int main()
{
    // --- Promotion: int operand is promoted when mixed with double ---
    std::cout << "3 + 0.5               = " << 3 + 0.5 << '\n';   // 3.5

    // --- Assignment conversion ---
    double widened{5};                  // int -> double: safe
    std::cout << "double widened{5}     = " << widened << '\n';

    // int narrowed{5.7};               // brace form REJECTS narrowing
    int truncated = 5.7;                // = form compiles, truncates
    std::cout << "int truncated = 5.7   = " << truncated << '\n';  // 5
    // --- Explicit casts: the course-standard way to narrow ---
    double price{19.99};
    int dollars{static_cast<int>(price)};
    std::cout << "static_cast<int>(19.99)   = " << dollars << '\n';    // 19

    int negative = -3.9;                // = form: silent truncation
    int neg_cast{static_cast<int>(-3.9)};
    std::cout << "static_cast<int>(-3.9)    = " << neg_cast << '\n';   // -3
    std::cout << "int negative = -3.9        = " << negative << '\n';  // -3 (truncated toward zero)

    // --- Promotion inside expressions: 9 / 2.0 is double division ---
    int nine{9};
    std::cout << "nine / 2.0               = " << nine / 2.0 << '\n';  // 4.5
    int half{static_cast<int>(nine / 2.0)};
    std::cout << "int half{int(9/2.0)}      = " << half << '\n';       // 4

    // --- char <-> int: characters are small numbers ---
    char letter{'A'};
    std::cout << "static_cast<int>('A')     = " << static_cast<int>(letter) << '\n'; // 65
    std::cout << "static_cast<char>(66)     = " << static_cast<char>(66) << '\n';    // B

    // --- bool from a number: nonzero -> true (printed as 1) ---
    bool flag = 3.9;                    // = form: narrowing allowed silently
    std::cout << "bool flag = 3.9             = " << flag << '\n';        // 1

    return 0;
}
