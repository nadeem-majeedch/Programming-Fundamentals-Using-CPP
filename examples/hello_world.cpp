// purpose: the smallest complete C++ program — used in week 1 to introduce
//          program anatomy, compilation, and console output.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello

#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";

    // std::endl also flushes the stream; for plain output a newline is enough.
    std::cout << "This program teaches: main(), statements, and output."
              << '\n';

    return 0;
}
