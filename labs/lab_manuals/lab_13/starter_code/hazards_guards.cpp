// Lab 13 · hazards_guards.cpp — the three pointer hazards, GUARDED.
//
// Each hazard below is SHOWN safely: the dangerous line is present but
// guarded/commented, with the explanation next to it. Guided task: run as
//-is, then explain each guard in your own words.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic hazards_guards.cpp -o hg

#include <iostream>

void safePrint(const int* p)
{
    // Guard: no dereference without proof of validity.
    if (p == nullptr)
    {
        std::cout << "null pointer\n";
        return;
    }
    std::cout << *p << '\n';
}

int main()
{
    // Hazard 1 — uninitialized pointer. The bytes exist but point nowhere
    // in particular; reading through it is undefined behavior.
    int* p1{nullptr};                    // the fix: initialize at birth
    safePrint(p1);

    // Hazard 2 — null dereference. Prevented by the check above.
    int value{42};
    int* p2{&value};
    safePrint(p2);

    // Hazard 3 — use-after-delete. After delete, p3 still HOLDS the old
    // address (now invalid). The discipline: null it immediately, so any
    // later use hits the guard instead of undefined behavior.
    int* p3{new int{7}};
    std::cout << *p3 << '\n';
    delete p3;
    p3 = nullptr;                        // the guard line — try removing it
    safePrint(p3);                       // and explain what changes
    return 0;
}
