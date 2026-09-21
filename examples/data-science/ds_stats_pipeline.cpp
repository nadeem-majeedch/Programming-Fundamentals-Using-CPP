// purpose: a complete mini data pipeline over a text data file —
//          open-check, line parsing, three-way validation with counts,
//          mean/median report, and exit codes a data job should use.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_stats_pipeline.cpp -o dspipe
// usage:   ./dspipe readings.txt      (file format below)
//
// FILE FORMAT (one observation per line)
//     <station-name> <reading>
//     e.g.   N-01 21.5
// Line classes:
//     valid   : name + numeric reading within [LO, HI]
//     missing : name + "NA"            (the file *records* the gap)
//     invalid : anything else (missing field, non-numeric, out of range)
//
// MATH FIRST
//     mean = (sum of valid readings) / (number of valid readings)
//     median = middle of the SORTED valid readings (even n: average of middles)
//     Only VALID readings enter the statistics — mixing classes would lie.
//
// EDGE CASES
//     file won't open            -> exit 2 (data/environment failure)
//     zero valid readings        -> statistics reported as n/a, exit 0
//     one valid reading          -> mean = median = that reading
//
// DATA-SCIENCE HABIT DEMONSTRATED: the report ends with a one-line
// "data quality" summary (loaded / missing / invalid). A statistic without
// its denominator context is not a result.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

const double LO{-50.0};
const double HI{60.0};
const int CAP{1000};

// insertionSort on doubles (L24 pattern, retyped for measurements)
void sortReadings(double a[], int n)
{
    for (int i{1}; i < n; ++i)
    {
        double key{a[i]};
        int j{i - 1};
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <datafile>\n";
        return 1;                            // usage error
    }

    std::ifstream in{argv[1]};
    if (!in.is_open())
    {
        std::cout << "cannot open " << argv[1] << '\n';
        return 2;                            // data/environment failure
    }

    double readings[CAP]{};
    int valid{0};
    int missing{0};
    int invalid{0};
    double sum{0.0};
    std::string line{};

    while (std::getline(in, line))
    {
        if (line.empty())
        {
            continue;                        // blank line: not an observation, not an error
        }
        std::istringstream ls{line};
        std::string name{};
        std::string valueToken{};
        if (!(ls >> name))                   // defensive: whitespace-only line
        {
            continue;
        }
        if (!(ls >> valueToken))
        {
            ++invalid;                       // name but no value field
            continue;
        }
        if (valueToken == "NA")
        {
            ++missing;                       // recorded gap: a known unknown
            continue;
        }
        std::istringstream vs{valueToken};
        double v{};
        char leftover{};
        if (!(vs >> v) || (vs >> leftover))
        {
            ++invalid;                       // non-numeric (or "21.5x")
            continue;
        }
        if (v < LO || v > HI)
        {
            ++invalid;                       // out of physical range
            continue;
        }
        if (valid >= CAP)
        {
            std::cout << "capacity exceeded — increase CAP\n";
            return 2;
        }
        readings[valid] = v;
        ++valid;
        sum += v;
    }

    std::cout << "loaded : " << valid << '\n';
    std::cout << "missing: " << missing << '\n';
    std::cout << "invalid: " << invalid << '\n';

    if (valid == 0)
    {
        std::cout << "mean   : n/a\nmedian : n/a\n";
        return 0;                            // the quality report IS the result
    }

    double mean{sum / valid};                // doubles all through: measures, not counts

    sortReadings(readings, valid);
    double median{};
    if (valid % 2 == 1)
    {
        median = readings[valid / 2];
    }
    else
    {
        median = (readings[valid / 2 - 1] + readings[valid / 2]) / 2.0;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "mean   : " << mean << '\n';
    std::cout << "median : " << median << '\n';
    return 0;
}
