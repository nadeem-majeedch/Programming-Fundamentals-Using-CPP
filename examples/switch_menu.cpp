// purpose: switch anatomy — grouped cases, default, and the same logic as
//          an if/else-if chain for comparison — used in L08.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic switch_menu.cpp -o menu

#include <iostream>

int main()
{
    char choice{};

    std::cout << "Choose: (a)dd  (d)elete  (q)uit\n";
    std::cin >> choice;

    // --- switch version ---
    switch (choice)
    {
        case 'a':
        case 'A':                       // grouped: accept both cases
            std::cout << "Adding a record...\n";
            break;                      // without break, execution falls through

        case 'd':
        case 'D':
            std::cout << "Deleting a record...\n";
            break;

        case 'q':
        case 'Q':
            std::cout << "Quitting...\n";
            break;

        default:                        // runs when no case matched
            std::cout << "Unknown choice: " << choice << '\n';
            break;
    }

    // --- identical logic as if / else-if (for side-by-side comparison) ---
    if (choice == 'a' || choice == 'A')
    {
        std::cout << "(if-version) Adding a record...\n";
    }
    else if (choice == 'd' || choice == 'D')
    {
        std::cout << "(if-version) Deleting a record...\n";
    }
    else if (choice == 'q' || choice == 'Q')
    {
        std::cout << "(if-version) Quitting...\n";
    }
    else
    {
        std::cout << "(if-version) Unknown choice.\n";
    }

    // Selector-type note: switch works on integral/char types only.
    // switch (std::string{"hi"}) { }   // error: string not allowed

    // Conditional operator: for VALUE selection, not statements.
    int x{10};
    int y{3};
    int max_value{(x > y) ? x : y};
    std::cout << "max via ?: = " << max_value << '\n';

    return 0;
}
