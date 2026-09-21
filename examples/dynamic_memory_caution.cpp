// purpose: new/delete discipline, the three failure modes (leak, dangling,
//          double-delete), and the RAII contrast with std::vector — L27.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic dynamic_memory_caution.cpp -o dynmem

#include <iostream>
#include <vector>

// A "use" function so the compiler cannot optimize allocations away.
long long consume(const int* data, int n)
{
    long long total{};
    for (int i{0}; i < n; ++i)
    {
        total += data[i];
    }
    return total;
}

int main()
{
    // --- The four-step discipline: allocate, use, release, null-out ---
    int* scalar{new int{42}};         // allocate + construct
    std::cout << "*scalar = " << *scalar << '\n';    // use
    delete scalar;                    // release (matching form: scalar delete)
    scalar = nullptr;                 // null-out (turns dangling into checkable)

    // --- Dynamic array: runtime size (stack arrays cannot do this) ---
    int n{};
    std::cout << "How many values? ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "Nothing to do.\n";
        return 0;
    }

    int* data{new int[n]{}};          // value-initialized to 0
    for (int i{0}; i < n; ++i)
    {
        data[i] = i + 1;              // use like any array
    }
    std::cout << "sum of 1.." << n << " = " << consume(data, n) << '\n';
    delete[] data;                    // MATCHING form: delete[] for new[]
    data = nullptr;

    // ============================================================
    // The three failure modes — SHOWN AS TEXT, not executed.
    // Uncommenting any of these would exhibit undefined behavior.
    // ============================================================
    //
    // (1) LEAK: reassign before delete — the block becomes unreachable.
    //     int* p{new int{1}};
    //     p = new int{2};      // the first block is now unreachable forever
    //     delete p;            // frees only the SECOND block
    //
    // (2) DANGLING: use after delete — reads freed memory.
    //     delete p;
    //     std::cout << *p;     // UNDEFINED BEHAVIOR
    //
    // (3) DOUBLE-DELETE: releasing the same block twice.
    //     delete p;
    //     delete p;            // UNDEFINED BEHAVIOR
    //     (safe variant: p = nullptr after the first delete — deleting a
    //      null pointer is a well-defined no-op)

    // --- RAII: std::vector manages its own heap memory ---
    int m{};
    std::cout << "How many (vector)? ";
    std::cin >> m;
    std::vector<int> values(static_cast<std::vector<int>::size_type>(m), 0);
    for (int i{0}; i < m; ++i)
    {
        values[static_cast<std::vector<int>::size_type>(i)] = i + 1;
    }
    long long total{};
    for (int v : values)
    {
        total += v;
    }
    std::cout << "vector sum = " << total
              << "  (no delete anywhere — the vector releases itself)\n";
    // values dies at the end of main -> its heap block is freed automatically.
    // THAT is RAII: resource lifetime tied to object lifetime.

    return 0;
}
