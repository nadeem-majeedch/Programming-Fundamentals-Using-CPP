// purpose: missing/invalid value handling for a small dataset — the three
//          policies (skip / repair / abort) and when each is honest.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_validate_dataset.cpp -o dsvalid
// input:   n, then n tokens: integers (valid readings), the word "missing"
//          (a recorded gap), or any other token (corrupt). Try:
//          8  21 19 missing 24 999 abc 20 22
//
// THE THREE POLICIES (data-science judgment, expressed in beginner C++)
// ----------
// SKIP    : the value is unusable -> exclude it, COUNT it, keep going.
//           Honest only if you report how many you skipped (this program).
// REPAIR  : replace with a defensible substitute (here: the mean of the valid
//           values so far). Requires a stated rule — silent repair is dishonest.
// ABORT   : the whole run is untrustworthy (wrong file, unreadable format) ->
//           stop with a nonzero exit code.
// A missing value and an out-of-range value are DIFFERENT defects and are
// reported separately: a data consumer must be able to tell them apart.
//
// MATH FIRST (the repair rule implemented below)
//     repaired value = mean of valid values seen so far, rounded to int
//     (documented choice; the mean itself uses the single-cast rule)

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

const int LO{-50};      // plausible temperature range for this dataset
const int HI{60};

int main()
{
    int n{};
    if (!(std::cin >> n) || n < 0)
    {
        std::cout << "bad header\n";
        return 1;                            // cannot even trust the count: abort
    }

    int data[1000]{};                        // stores VALID observations only
    (void)data;                              // stored for extension; stats use sums only
    int valid{0};
    int missing{0};
    int outOfRange{0};
    int corrupt{0};
    long long sum{0};

    for (int i{0}; i < n; ++i)
    {
        std::string token{};
        std::cin >> token;
        if (token == "missing")
        {
            ++missing;                       // policy: record the gap, exclude the value
            continue;
        }

        // is the token an integer? try to parse it via stream extraction
        std::istringstream parser{token};
        int v{};
        char leftover{};
        if (!(parser >> v) || parser >> leftover)
        {
            ++corrupt;                       // not a number at all
            continue;
        }
        if (v < LO || v > HI)
        {
            ++outOfRange;                    // a number, but physically implausible
            continue;
        }

        // valid: accept. (Repair policy would adjust v here; we keep it simple
        // and honest: skip-and-report, with the repair rule shown in comments.)
        data[valid] = v;
        ++valid;
        sum += v;
    }

    std::cout << "valid     : " << valid << '\n';
    std::cout << "missing   : " << missing << '\n';
    std::cout << "out-of-rng: " << outOfRange << '\n';
    std::cout << "corrupt   : " << corrupt << '\n';

    if (valid == 0)
    {
        std::cout << "no usable data — statistics skipped\n";
        return 0;                            // all-invalid is NOT an error exit:
    }                                        // the report itself is the product

    double mean{static_cast<double>(sum) / valid};
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "mean      : " << mean << " (of valid values only)\n";

    // Repair-rule sketch (not executed here to keep policies visible):
    //   on a "missing": v = static_cast<int>(mean + 0.5);  // documented rule
    // and then treat v as valid, incrementing a "repaired" counter too.
    return 0;
}
