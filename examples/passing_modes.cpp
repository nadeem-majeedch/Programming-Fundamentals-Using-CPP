// purpose: the three passing modes with printed evidence — scalar by value
//          (fails to modify), array decay (modifies), swap via references
//          and via pointers — used in L26.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic passing_modes.cpp -o passing

#include <iostream>

// Pass by VALUE: the caller's int is COPIED; changes stay local.
void bump_value(int x)
{
    x = x + 1;
    std::cout << "  inside bump_value     : x = " << x << '\n';
}

// Pass by REFERENCE: alias for the caller's variable.
void bump_reference(int& x)
{
    x = x + 1;
    std::cout << "  inside bump_reference : x = " << x << '\n';
}

// Arrays DECAY: no copy is made; callee writes reach the caller's array.
// The size does NOT travel with the array — it must be a separate parameter.
void fill(int a[], int n, int value)
{
    for (int i{0}; i < n; ++i)
    {
        a[i] = value;
    }
}

// Read-only array: const protects the caller's data.
void print_array(const int a[], int n)
{
    for (int i{0}; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

// The same swap in both notations.
void swap_ref(int& a, int& b)
{
    int temp{a};
    a = b;
    b = temp;
}

void swap_ptr(int* a, int* b)
{
    int temp{*a};
    *a = *b;
    *b = temp;
}

int main()
{
    // --- Scalar: by value vs by reference ---
    int n{10};
    std::cout << "before            : n = " << n << '\n';
    bump_value(n);
    std::cout << "after bump_value  : n = " << n << "  (unchanged!)\n";
    bump_reference(n);
    std::cout << "after bump_ref    : n = " << n << "  (modified)\n";

    // --- Array: modification propagates (decay, no copy) ---
    int data[3]{0, 0, 0};
    fill(data, 3, 7);                 // callee wrote; caller sees it
    std::cout << "after fill(7)     : ";
    print_array(data, 3);

    // --- Same effect, two notations: references vs pointers ---
    int a{3};
    int b{8};
    swap_ref(a, b);
    std::cout << "swap_ref : a=" << a << " b=" << b << '\n';
    swap_ptr(&a, &b);                 // note the & at the call site
    std::cout << "swap_ptr : a=" << a << " b=" << b << '\n';

    return 0;
}
