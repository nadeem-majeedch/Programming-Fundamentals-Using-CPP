// Lab 07 · monolith.cpp — refactor subject.
//
// Task: decompose main() into three one-job functions. Contract-first:
// write the three signatures as comments BEFORE moving any code. The
// program's output must be IDENTICAL before and after (regression rule).
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic monolith.cpp -o mono

#include <iostream>
#include <iomanip>

int main()
{
    // block 1: rectangle
    double w{3.0};
    double h{4.0};
    double area{w * h};
    std::cout << std::fixed << std::setprecision(2)
              << "rect " << w << "x" << h << " = " << area << '\n';

    // block 2: circle
    double r{2.0};
    double cArea{3.14159265358979 * r * r};
    std::cout << "circle r=" << r << " = " << cArea << '\n';

    // block 3: triangle
    double base{3.0};
    double height{5.0};
    double tArea{0.5 * base * height};
    std::cout << "tri " << base << "-" << height << " = " << tArea << '\n';
    return 0;
}
