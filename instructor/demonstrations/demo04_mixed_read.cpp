// DEMO-04 companion · cin >> then getline interplay (MC-13, fixed variant).
// build: g++ -std=c++17 -Wall -Wextra -pedantic demo04_mixed_read.cpp -o demo04
// input: 25<Enter>Maria Chen<Enter>
//
// Live act: delete the cin.ignore(...) line, rebuild, rerun -> the name read
// is EMPTY (getline consumes the newline `>>` left behind). Re-add the line,
// rebuild, rerun -> fixed. Trace the pipe picture each time.

#include <iostream>
#include <limits>
#include <string>

int main()
{
    int age{};
    std::string name;

    std::cout << "Age: ";
    std::cin >> age;

    // Remove this line during the demo to reproduce the empty-name bug:
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << ", age " << age << '\n';
    return 0;
}
