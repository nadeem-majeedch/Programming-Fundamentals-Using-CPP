// purpose: <cctype> classification, std::string operations, substr/find
//          with the npos check, and getline vs >> — used in L21.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic string_processing.cpp -o strproc

#include <cctype>     // isdigit, isalpha, isspace, toupper, tolower
#include <iostream>
#include <string>

int main()
{
    // --- <cctype> classification table ---
    char samples[]{'7', ' ', 'Q', 'q'};
    for (char c : samples)
    {
        std::cout << '\'' << c << "\': digit=" << static_cast<bool>(std::isdigit(static_cast<unsigned char>(c)))
                  << " alpha=" << static_cast<bool>(std::isalpha(static_cast<unsigned char>(c)))
                  << " upper->" << static_cast<char>(std::toupper(static_cast<unsigned char>(c)))
                  << " lower->" << static_cast<char>(std::tolower(static_cast<unsigned char>(c)))
                  << '\n';
    }

    // --- std::string basics: indexing + length ---
    std::string name{"Ayesha"};
    std::cout << "\nname = " << name << ", length = " << name.length() << '\n';
    name[0] = 'a';                        // writable via index
    std::cout << "after name[0]='a': " << name << '\n';

    // --- Building and comparing ---
    std::string greeting{"Hi, " + name + "!"};    // + concatenates
    std::cout << greeting << '\n';
    std::cout << "std::string{\"apple\"} < \"banana\"  = "
              << (std::string{"apple"} < std::string{"banana"}) << '\n';
    std::cout << "std::string{\"Zebra\"} < \"apple\"   = "
              << (std::string{"Zebra"} < std::string{"apple"})
              << "  (char codes: 'Z'=90 < 'a'=97)\n";

    // --- substr and find (with the npos not-found check) ---
    std::string date{"2026-09-18"};
    std::string year{date.substr(0, 4)};          // pos, length
    std::string month{date.substr(5, 2)};
    std::cout << "\nyear=" << year << " month=" << month << '\n';

    std::string::size_type dash{date.find('-')};  // first occurrence
    if (dash != std::string::npos)                // THE not-found check
    {
        std::cout << "first '-' at index " << dash << '\n';
    }
    if (date.find("xyz") == std::string::npos)
    {
        std::cout << "\"xyz\" not found (npos)\n";
    }

    // --- getline vs >> : reading a full line with spaces ---
    std::cout << "\nCourse name (with spaces): ";
    std::string course{};
    std::getline(std::cin, course);            // reads the WHOLE line
    std::cout << "getline read: \"" << course << "\"\n";
    // (cin >> course would have stopped at the first space — L04's rule.)
    // TRAP (taught in the lecture): after a cin >> read, a leftover '\n'
    // remains; then getline reads an EMPTY line unless you ignore() it first.

    return 0;
}
