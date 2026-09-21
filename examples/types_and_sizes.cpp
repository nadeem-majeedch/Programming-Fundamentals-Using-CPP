// purpose: demonstrate every built-in type, brace initialization, and the
//          sizeof operator — used in L03 to introduce typed memory.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic types_and_sizes.cpp -o types

#include <iostream>

int main()
{
    int count{42};                // whole numbers
    double average{91.5};         // measurements, decimals
    char grade{'A'};              // one character, single quotes
    bool enrolled{true};          // logical value

    const double Pi{3.14159};     // named constant, cannot be reassigned

    std::cout << "count     = " << count << '\n';
    std::cout << "average   = " << average << '\n';
    std::cout << "grade     = " << grade << '\n';
    std::cout << "enrolled  = " << enrolled << '\n';   // bool prints as 1
    std::cout << "Pi        = " << Pi << '\n';

    // sizeof: how many bytes each type occupies on THIS platform
    std::cout << "size of int    : " << sizeof(int) << " bytes\n";
    std::cout << "size of double : " << sizeof(double) << " bytes\n";
    std::cout << "size of char   : " << sizeof(char) << " bytes\n";
    std::cout << "size of bool   : " << sizeof(bool) << " bytes\n";

    // Narrowing is REJECTED by brace initialization — uncomment to see the
    // compiler error (this is a feature, not a bug):
    // int bad{3.7};              // error: narrowing conversion

    // The assignment form would compile but silently truncate:
    int sloppy = 3.7;             // sloppy == 3 (fraction discarded)
    std::cout << "sloppy (from 3.7 via =) = " << sloppy << '\n';

    return 0;
}
