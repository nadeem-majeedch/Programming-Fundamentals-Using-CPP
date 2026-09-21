// purpose: block scope, shadowing, the global-mutable bug, and a static
//          local — used in L14 (students predict each printed line first).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic scope_lifetime_demo.cpp -o scope

#include <iostream>

int counter{0};              // GLOBAL mutable — the course BANS this; shown
                             // here only to demonstrate why.
const int kMaxTries{3};      // GLOBAL constant — allowed and encouraged.

void add_point()
{
    counter = counter + 1;   // hidden coupling: any function can mutate this
}

void shadow_demo()
{
    int total{100};          // function-local 'total'
    {
        int total{5};        // SHADOWS the outer 'total' (legal, confusing)
        std::cout << "inner total = " << total << '\n';   // 5
    }
    std::cout << "outer total = " << total << '\n';       // 100 (untouched)
}

int next_id()
{
    static int id{100};      // static local: exists across calls (avoid in
                             // course code — shown for completeness)
    ++id;
    return id;
}

int main()
{
    // 1. Block scope: a variable declared in a block dies at its '}'
    {
        int inside{7};
        std::cout << "inside = " << inside << '\n';
    }
    // std::cout << inside;   // ERROR: 'inside' does not exist here

    // 2. Shadowing
    shadow_demo();

    // 3. The global-mutable bug: two callers, invisible coupling
    add_point();
    add_point();
    std::cout << "counter = " << counter << " (who changed it? everyone.)\n";

    // 4. Static local: same call, different result — testability broken
    std::cout << "next_id() = " << next_id() << '\n';   // 101
    std::cout << "next_id() = " << next_id() << '\n';   // 102 (!)

    // 5. Named constant vs magic number
    for (int attempt{1}; attempt <= kMaxTries; ++attempt)
    {
        std::cout << "attempt " << attempt << " of " << kMaxTries << '\n';
    }

    return 0;
}
