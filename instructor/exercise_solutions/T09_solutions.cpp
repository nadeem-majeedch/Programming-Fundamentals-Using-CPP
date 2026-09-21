// instructor/exercise_solutions/T09_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-102 .. PF-E-111 (Pointers and References).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T09_solutions.cpp -o t09
#include <iostream>
#include <iomanip>
#include <vector>

namespace e102 { // Address Bookkeeping
void run()
{
    int x{42};
    int y{10};
    int* p{&x};
    std::cout << "x: " << x << "  p points to x: " << (*p == x ? "yes" : "no")
              << '\n';
    p = &y; // repointing: y is untouched, p now aliases y
    *p = 7; // write THROUGH p changes y
    std::cout << "after repoint and *p=7, y: " << y << '\n';
    // Addresses themselves are printed with &x / p; their FORMAT is
    // platform-specific (implementation-defined), which is why we verify
    // relationships (*p == y), not printed text.
}
} // namespace e102

namespace e103 { // Read and Write Through a Pointer
void run()
{
    int a{}, b{};
    std::cin >> a >> b;
    std::cout << "before: " << a << ' ' << b << '\n';
    int* pa{&a};
    int* pb{&b};
    int tmp{*pa}; // swap entirely through dereferences
    *pa = *pb;
    *pb = tmp;
    std::cout << "after: " << a << ' ' << b << '\n';
}
} // namespace e103

namespace e104 { // Null Discipline
void safePrint(const int* p)
{
    if (p == nullptr)
        std::cout << "null pointer\n";
    else
        std::cout << *p << '\n';
}

void run()
{
    int* nothing{nullptr};
    safePrint(nothing);
    int x{42};
    safePrint(&x);
    int* p{new int{99}};
    delete p;
    p = nullptr; // null-out after delete: "may crash" becomes "testable"
    safePrint(p);
}
} // namespace e104

namespace e105 { // Pointer Walk Over an Array
void run()
{
    int n{};
    std::cin >> n;
    int a[10]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    long long sumIdx{0};
    for (int i{0}; i < n; ++i)
        sumIdx += a[i];
    long long sumPtr{0};
    for (const int* p = a; p != a + n; ++p)
        sumPtr += *p;
    long long span{(a + n - 1) - a}; // pointer diff counts ELEMENTS
    std::cout << "sum: " << sumIdx << '\n'
              << "sum(p): " << sumPtr << '\n' << "span: " << span << '\n';
}
} // namespace e105

namespace e106 { // Reference vs Pointer vs Value
void bumpByValue(int x)
{
    ++x; // a copy is incremented; the caller sees nothing
    // (x is otherwise unused: the whole point is that the copy's change
    // is invisible to the caller — silencing the compiler would hide
    // the lesson, so we mark it intentionally)
    static_cast<void>(x);
}

void bumpByPointer(int* p)
{
    if (p != nullptr)
        ++(*p);
}

void bumpByReference(int& r)
{
    ++r;
}

void run()
{
    int n{};
    std::cin >> n;
    bumpByValue(n);
    std::cout << "after value: " << n << '\n';
    bumpByPointer(&n);
    std::cout << "after pointer: " << n << '\n';
    bumpByReference(n);
    std::cout << "after reference: " << n << '\n';
    // Pointer and reference produce identical memory effects here; the
    // pointer can additionally be null or repointed, the reference is a
    // one-time alias that must be bound and never re-bound.
}
} // namespace e106

namespace e107 { // Min/Max Finder Returning Two Results
void findMinMax(const int* a, int n, int& minOut, int& maxOut)
{
    if (n <= 0 || a == nullptr)
    {
        std::cout << "error: empty array\n";
        return;
    }
    minOut = a[0];
    maxOut = a[0];
    for (int i{1}; i < n; ++i)
    {
        if (a[i] < minOut)
            minOut = a[i];
        if (a[i] > maxOut)
            maxOut = a[i];
    }
}

const int* findMax(const int* a, int n)
{
    if (n <= 0 || a == nullptr)
        return nullptr;
    const int* best{a};
    for (const int* p{a + 1}; p != a + n; ++p)
        if (*p > *best)
            best = p;
    return best;
}

void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int mn{}, mx{};
    findMinMax(a, n, mn, mx);
    std::cout << "min: " << mn << '\n' << "max: " << mx << '\n';
    const int* pMax{findMax(a, n)};
    if (pMax != nullptr)
        std::cout << "via pointer: " << *pMax << '\n';
}
} // namespace e107

namespace e108 { // Runtime Array with new[]/delete[]
void run()
{
    int n{};
    std::cin >> n;
    long long* data{new long long[n]{}};
    for (int i{0}; i < n; ++i)
        data[i] = static_cast<long long>(i + 1) * (i + 1);
    std::cout << "first 5:";
    for (int i{0}; i < (n < 5 ? n : 5); ++i)
        std::cout << ' ' << data[i];
    std::cout << '\n' << "last 2:";
    for (int i{(n > 2 ? n - 2 : 0)}; i < n; ++i)
        std::cout << ' ' << data[i];
    std::cout << '\n';
    long long sum{0};
    for (int i{0}; i < n; ++i)
        sum += data[i];
    std::cout << "sum: " << sum << '\n';
    // delete data;   <-- WRONG: new[] must pair with delete[]
    delete[] data; // correct pairing
}
} // namespace e108

namespace e109 { // Leak Hunt
void run()
{
    int n{};
    std::cin >> n;
    // BROKEN (conceptual, not run): each iteration leaks the old block.
    //   for (int i{0}; i < n; ++i) {
    //       p = new int[10];   // old block becomes unreachable: LEAK
    //       p[0] = i;
    //   }
    // FIX 1 (raw): delete[] p; BEFORE reassigning.
    // FIX 2 (RAII): std::vector manages the memory — no delete anywhere.
    std::vector<long long> v(static_cast<std::size_t>(n));
    for (int i{0}; i < n; ++i)
        v[static_cast<std::size_t>(i)] = i;
    for (int i{0}; i < n; ++i)
        std::cout << v[static_cast<std::size_t>(i)]
                  << (i < n - 1 ? " " : "\n");
    std::cout << "raw version: freed every iteration\n";
    std::cout << "vector version: no delete anywhere (RAII)\n";
}
} // namespace e109

namespace e110 { // Dangling Pointer Demonstration (safe version)
void run()
{
    // hazard 1: leak — allocate without delete: memory unreachable but
    //   not freed. Silent; only tools observe it. Fix: pair every new
    //   with delete, or better: use std::vector.
    // hazard 2: use-after-delete — dereferencing a freed pointer is
    //   undefined behavior (garbage value, crash, or "seems to work").
    //   Fix: p = nullptr; immediately after delete; test before use.
    // hazard 3: double-delete — freeing the same block twice corrupts
    //   the allocator. Fix: single ownership of each allocation; the
    //   null-out idiom makes accidental double delete harmless because
    //   deleting nullptr is a defined no-op.
    std::cout << "hazard 1 (leak): unreachable memory, silent -> fix: "
                 "pair new/delete or use RAII\n";
    std::cout << "hazard 2 (use-after-delete): UB -> fix: null-out after "
                 "delete, check before use\n";
    std::cout << "hazard 3 (double-delete): UB -> fix: single ownership; "
                 "delete(nullptr) is a safe no-op\n";
}
} // namespace e110

namespace e111 { // Dynamic 2-D Grid
void run()
{
    int r{}, c{};
    std::cin >> r >> c;
    // Flat array chosen: ONE allocation, ONE delete, cache-friendly.
    // Row-pointer alternative needs r+1 deletes and exact ordering.
    long long* grid{new long long[r * c]{}};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j)
            grid[i * c + j] = i * 10 + j;
    for (int i{0}; i < r; ++i)
    {
        for (int j{0}; j < c; ++j)
            std::cout << grid[i * c + j] << (j < c - 1 ? " " : "\n");
    }
    delete[] grid;
    std::cout << "freed\n";
}
} // namespace e111

int main()
{
    e102::run();
    e104::run();
    e109::run();
    e110::run();
    std::cout << "=== stdin-driven demos follow ===\n";
    e103::run();
    e105::run();
    e107::run();
    e108::run();
    e111::run();
    return 0;
}
