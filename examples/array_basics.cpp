// purpose: array initialization forms, traversal discipline, contiguity of
//          memory, and the out-of-bounds reality — used in L17.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic array_basics.cpp -o arrbasic

#include <iostream>

int main()
{
    // --- Four initialization forms and their exact semantics ---
    int full[3] = {10, 20, 30};       // all three explicit
    int partial[3] = {10};            // rest are ZEROED: {10, 0, 0}
    int inferred[] = {1, 2, 3};       // size deduced: 3
    int zeroed[3]{};                  // all zero

    std::cout << "full     : " << full[0] << ' ' << full[1] << ' '
              << full[2] << '\n';
    std::cout << "partial  : " << partial[0] << ' ' << partial[1] << ' '
              << partial[2] << '\n';
    std::cout << "inferred : " << inferred[0] << ' ' << inferred[1] << ' '
              << inferred[2] << '\n';
    std::cout << "zeroed   : " << zeroed[0] << ' ' << zeroed[1] << ' '
              << zeroed[2] << '\n';

    // --- Traversal discipline: const size + i < N ---
    const int N{5};
    int scores[N]{72, 88, 95, 61, 79};

    for (int i{0}; i < N; ++i)        // valid indices: 0..N-1
    {
        std::cout << "scores[" << i << "] = " << scores[i] << '\n';
    }

    // --- Elements are writable through their index ---
    scores[2] = 100;                  // replace 95
    std::cout << "after fix, scores[2] = " << scores[2] << '\n';

    // --- Memory is contiguous: addresses step by sizeof(int) ---
    std::cout << "addresses (contiguous, 4-byte steps on this platform):\n";
    for (int i{0}; i < N; ++i)
    {
        std::cout << "  &scores[" << i << "] = " << &scores[i] << '\n';
    }
    // Note: address FORMAT is platform-specific (how it prints is not
    // standard C++; that a block is contiguous IS standard).

    // --- Out of bounds: NO compiler error, NO reliable runtime error ---
    // scores[5] = 1;   // legal-looking, UNDEFINED BEHAVIOR — do not run.
    // The discipline that replaces the missing check:
    //   const int N + for (i = 0; i < N; ++i) + never index by accident.

    return 0;
}
