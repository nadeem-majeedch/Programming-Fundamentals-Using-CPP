// Lab 11 · word_count_naive.cpp — bug-hunt file.
//
// Documented correct behavior: any whitespace run separates words.
//   input "the   cat"  -> 2 words
//   input "a b"        -> 2 words
// Actual (this naive version): "the   cat" -> 4 words.
//
// Task: rewrite the counting logic with an in-word state flag so runs of
// spaces count as ONE separator. Test on empty line and tabs too.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic word_count_naive.cpp -o wc

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    int words{0};
    for (char ch : line)
        if (ch == ' ')
            ++words;              // counts every space — runs break it
    if (!line.empty())
        ++words;                  // the last word

    std::cout << words << '\n';
    return 0;
}
