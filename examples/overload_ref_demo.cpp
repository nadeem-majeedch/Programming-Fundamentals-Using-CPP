// purpose: overload resolution, a working swap via references, and the
//          min/max output-parameter pattern — used in L15.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic overload_ref_demo.cpp -o overload

#include <iostream>
#include <string>

// --- Overload set: same name, DIFFERENT parameter lists ---
void print(int value)
{
    std::cout << "print(int)        : " << value << '\n';
}

void print(double value)
{
    std::cout << "print(double)     : " << value << '\n';
}

void print(const std::string& value)
{
    std::cout << "print(string)     : " << value << '\n';
}

// void print(int value, double d = 0.0);  // + void print(int) would be
// AMBIGUOUS with print(3) — defaults must not create competing overloads.

// --- Reference parameters: the failed L13 swap, fixed ---
void swap(int& a, int& b)      // aliases for the caller's variables
{
    int temp{a};
    a = b;
    b = temp;
}

// --- Output parameters: two results through two references ---
void min_max(const int values[], int n, int& min_out, int& max_out)
{
    min_out = values[0];
    max_out = values[0];
    for (int i{1}; i < n; ++i)
    {
        if (values[i] < min_out)
        {
            min_out = values[i];
        }
        if (values[i] > max_out)
        {
            max_out = values[i];
        }
    }
}

int main()
{
    // Resolution: exact match wins; char promotes to int (teachable!)
    print(42);          // print(int)
    print(4.5);         // print(double)
    print('x');         // print(int)  — char promotes
    print(std::string{"hi"});   // print(string)

    // swap that works
    int a{1};
    int b{9};
    swap(a, b);
    std::cout << "after swap: a=" << a << " b=" << b << '\n';

    // min/max with two outputs
    int values[]{4, 17, 8, 23, 15};
    int smallest{};
    int largest{};
    min_max(values, 5, smallest, largest);
    std::cout << "min = " << smallest << ", max = " << largest << '\n';

    return 0;
}
