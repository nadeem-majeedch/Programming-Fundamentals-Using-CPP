// purpose: prompt/read/echo a validated age — used in L04 to teach stream
//          state and the clear()/ignore() recovery idiom.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic io_age_check.cpp -o io_age

#include <iostream>
#include <limits>   // std::numeric_limits

int main()
{
    int age{0};

    std::cout << "Enter your age: ";
    if (!(std::cin >> age))
    {
        // The read failed (letters were typed). The stream is now in a
        // failed state AND the bad text is still waiting in the buffer.
        std::cin.clear();   // 1. reset the error flags
        // 2. discard the rest of the bad line (up to and including '\n')
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That was not a number. Using age 0 as a default.\n";
        age = 0;
    }

    // Echo discipline: always repeat what was understood.
    std::cout << "Registered age: " << age << '\n';

    if (age >= 18)
    {
        std::cout << "Status: adult\n";
    }
    else
    {
        std::cout << "Status: minor\n";
    }

    return 0;
}
