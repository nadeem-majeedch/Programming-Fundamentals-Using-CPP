// purpose: addresses, & and *, nullptr discipline, and pointer arithmetic
//          with the type-scaled step — used in L25.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic pointer_basics.cpp -o ptr

#include <iostream>

int main()
{
    // --- Every variable has an address; & reveals it ---
    int x{5};
    std::cout << "x        = " << x << '\n';
    std::cout << "&x       = " << &x << "   (address: format is platform-specific)\n";

    // --- Pointer declaration + dereference (read AND write) ---
    int* p{&x};                  // p holds the address of x
    std::cout << "p        = " << p << "   (same address as &x)\n";
    std::cout << "*p       = " << *p << "   (the value AT that address)\n";

    *p = 12;                     // write THROUGH the pointer
    std::cout << "after *p = 12: x = " << x << "   (x changed!)\n";

    // --- Pointer vs pointee sizes ---
    std::cout << "sizeof(p) = " << sizeof(p) << " bytes (an address)"
              << ", sizeof(*p) = " << sizeof(*p) << " bytes (an int)\n";

    // --- nullptr: the pointer that points nowhere, on purpose ---
    int* safe{nullptr};
    if (safe == nullptr)         // ALWAYS check before dereferencing
    {
        std::cout << "safe is nullptr — not dereferenced\n";
    }
    // *safe = 1;   // CRASH if uncommented: dereferencing nullptr is UB

    // --- Repointing: p can aim elsewhere during its lifetime ---
    int y{99};
    p = &y;                      // reseat the pointer (references cannot do this)
    std::cout << "p now points to y: *p = " << *p << '\n';

    // --- Arrays and pointer arithmetic: step size scales by type ---
    int    ints[4]{10, 20, 30, 40};
    double reals[4]{1.5, 2.5, 3.5, 4.5};

    int*    pi{ints};       // array name decays to &ints[0]
    double* pr{reals};

    std::cout << "\nint steps    : " << pi << " -> " << (pi + 1) << "  (+4 bytes)\n";
    std::cout << "double steps : " << pr << " -> " << (pr + 1) << "  (+8 bytes)\n";

    // *(a + i) is EXACTLY a[i] — two spellings of one idea
    for (int i{0}; i < 4; ++i)
    {
        std::cout << "*(ints + " << i << ") = " << *(ints + i)
                  << "   ints[" << i << "] = " << ints[i] << '\n';
    }

    return 0;
}
