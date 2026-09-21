// Lab 15 · robust_read.cpp — guided starter: robust line parsing.
//
// Demonstrates the stream-state error strategy used throughout this lab:
// open-check -> getline loop -> per-line istringstream parse -> classify.
//
// Input format: lines "name score" (score 0..100). Bad lines are DATA
// (counted and reported), never crashes. Missing file is fatal (reported,
// exit code 2).
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic robust_read.cpp -o rr
// Run:   ./rr scores.txt   (create the file first, or see the lab task)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: " << argv[0] << " <file>\n";
        return 1;                        // usage error
    }

    std::ifstream in{argv[1]};
    if (!in)
    {
        std::cout << "cannot open " << argv[1] << '\n';
        return 2;                        // fatal: no data at all
    }

    std::string line;
    int lineNo{0};
    int good{0};
    int bad{0};
    long long total{0};
    while (std::getline(in, line))
    {
        ++lineNo;
        std::istringstream row{line};
        std::string name;
        int score{};
        if (row >> name && row >> score && score >= 0 && score <= 100)
        {
            ++good;
            total += score;
        }
        else
        {
            ++bad;
            std::cout << "line " << lineNo << ": skipped\n";
        }
    }
    if (good > 0)
        std::cout << "loaded " << good << ", skipped " << bad
                  << ", average " << static_cast<double>(total) / good << '\n';
    else
        std::cout << "loaded 0, skipped " << bad << '\n';
    return 0;
}
