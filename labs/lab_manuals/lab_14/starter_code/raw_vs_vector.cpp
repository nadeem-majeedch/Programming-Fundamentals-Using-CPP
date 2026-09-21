// Lab 14 · raw_vs_vector.cpp — same program two ways.
//
// Version A (raw): explicit new[]/delete[] with the ownership rules that
// make it safe — exactly one owner, every exit path frees, null-out after
// delete. The comments name each hazard the rules prevent.
//
// Version B (RAII): std::vector frees itself at scope exit. No delete
// anywhere, and the hazards above cannot occur by construction. This is
// the course default; version A exists so you understand what the vector
// does FOR you.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic raw_vs_vector.cpp -o rvv

#include <iostream>
#include <vector>

int main()
{
    // ---- Version A: raw, with the full safety ceremony ----
    int n{5};
    int* data{new int[n]{}};             // owner: this function
    for (int i{0}; i < n; ++i)
        data[i] = (i + 1) * (i + 1);
    long long sumA{0};
    for (int i{0}; i < n; ++i)
        sumA += data[i];
    std::cout << "raw sum: " << sumA << '\n';
    delete[] data;                       // must pair new[] with delete[]
    data = nullptr;                      // prevents use-after-delete

    // ---- Version B: managed ----
    std::vector<int> v(5);
    for (int i{0}; i < n; ++i)
        v[i] = (i + 1) * (i + 1);
    long long sumB{0};
    for (int x : v)
        sumB += x;
    std::cout << "vector sum: " << sumB << '\n';
    return 0;                            // vector frees itself here
}
