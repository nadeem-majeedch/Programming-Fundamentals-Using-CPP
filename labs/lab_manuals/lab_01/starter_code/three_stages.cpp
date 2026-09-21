// Lab 01 · three_stages.cpp — bug-hunt file (DO NOT fix before class).
// Guided task 2: classify each defect by STAGE (compile / link / runtime /
// logic), then fix. One defect per stage.
//
// Defect A (compile):   the missing semicolon after the return statement.
// Defect B (runtime):   the program asks for a number but crashes if the
//                       stream fails — input `abc` and observe (cin failure
//                       makes value uninitialized-flow; we guard it).
// Defect C (logic):     the sum adds the WRONG second operand.

#include <iostream>

int main()
{
    int value{};
    std::cout << "enter a number: ";
    if (!(std::cin >> value))
    {
        std::cout << "stream failed — that is the runtime defect\n";
        return 1;
    }

    int sum{value + 1};   // LOGIC defect: should be value + value
    std::cout << "sum: " << sum << '\n';
    return 0
}
