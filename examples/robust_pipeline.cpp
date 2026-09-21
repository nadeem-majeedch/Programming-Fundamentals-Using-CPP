// purpose: robust input/file handling — the three error tiers, the
//          clear()/ignore() idiom, and the skip-and-report pipeline — L30.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic robust_pipeline.cpp -o robust

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// Tier 1 response (user-fixable): bounded re-prompt with full state repair.
int read_int_bounded(const std::string& prompt, int lo, int hi, int attempts)
{
    for (int used{1}; used <= attempts; ++used)
    {
        std::cout << prompt;
        int value{};
        if (std::cin >> value)             // read succeeded...
        {
            if (value >= lo && value <= hi)
            {
                return value;              // ...and is in range
            }
            std::cout << "  out of range (" << lo << "-" << hi << ")\n";
        }
        else
        {
            std::cout << "  not a number\n";
        }
        // repair: reset state AND discard the poisoned line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "  giving up; using default " << lo << '\n';
    return lo;                             // Tier 1 fallback: documented default
}

int main()
{
    // --- Tier 1: user-fixable input error ---
    int age{read_int_bounded("Enter age (3-120): ", 3, 120, 3)};
    std::cout << "accepted age = " << age << "\n\n";

    // Create a deliberately messy data file for the pipeline demo.
    {
        std::ofstream seed{"mixed_scores.txt"};
        seed << "Ayesha,88\n"       // good
             << "oops,abc\n"        // bad: points not a number
             << "Ben,72\n"          // good
             << "\n"                // bad: empty line
             << "Chen,95\n"         // good
             << "Dana,9999\n";      // bad: out of range
    }

    // --- Tier 2 (environment/data errors): SKIP-AND-REPORT pipeline ---
    std::ifstream in{"mixed_scores.txt"};
    if (!in)                        // environment error: report + graceful exit
    {
        std::cerr << "error: cannot open mixed_scores.txt\n";
        return 1;                   // non-zero exit code = failure signal
    }

    int processed{};
    int skipped{};
    std::string line{};
    int line_number{0};

    std::cout << "processing mixed_scores.txt:\n";
    while (std::getline(in, line))     // correct EOF idiom: the read is the test
    {
        ++line_number;
        // parse "name,points"
        std::string::size_type comma{line.find(',')};
        if (comma == std::string::npos)
        {
            ++skipped;
            std::cout << "  line " << line_number << ": no comma — skipped\n";
            continue;
        }
        std::string name{line.substr(0, comma)};
        std::string points_text{line.substr(comma + 1)};

        int points{};
        std::istringstream parse{points_text};   // string as a stream
        if (!(parse >> points))                  // stream-state check (L04/L15)
        {
            ++skipped;
            std::cout << "  line " << line_number << ": bad number — skipped ("
                      << name << ")\n";
            continue;
        }

        if (points < 0 || points > 100)        // range = invalid class (L12)
        {
            ++skipped;
            std::cout << "  line " << line_number << ": out of range — skipped ("
                      << name << ", " << points << ")\n";
            continue;
        }

        ++processed;
        std::cout << "  line " << line_number << ": ok (" << name
                  << ", " << points << ")\n";
    }

    // End-of-run report: robustness is MEASURED.
    std::cout << "\nreport: processed " << processed << ", skipped "
              << skipped << ", total " << (processed + skipped) << '\n';

    // --- Tier 3 (program bugs): impossible internal states use assert ---
    // #include <cassert>
    // assert(processed + skipped == line_number);
    // (assertions document invariants for developers; they are NOT user-input
    //  handling — that is what Tiers 1 and 2 are for.)
    //
    // Note: this program avoids try/catch entirely — text-to-number parsing
    // goes through istringstream + stream-state checks, per the course
    // policy of deferring exceptions (docs/CPP_STANDARD.md § 4.2).

    return 0;
}
