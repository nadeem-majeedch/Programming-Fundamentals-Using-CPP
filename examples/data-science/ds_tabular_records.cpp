// purpose: tabular data with structs — rows of records, per-column statistics,
//          and a one-key group aggregation (the seed of the pivot table).
// build:   g++ -std=c++17 -Wall -Wextra -pedantic ds_tabular_records.cpp -o dstab
// input:   n rows, each: <name-token> <age:int> <gpa:double 0..4>
//          Try: 4  Ana 20 3.4  Ben 22 2.8  Ana 21 3.9  Cy 20 3.1
//
// MATH FIRST
// ----------
// A table T with columns (name, age, gpa) and n rows.
//     column mean:  mean(c) = (T[0].c + ... + T[n-1].c) / n
// GROUP mean by key k (here: name):
//     mean(c, k) = (sum of T[i].c where T[i].name == k) / (rows matching k)
// The two-pass shape: PASS 1 collects the distinct keys; PASS 2 accumulates
// per-key sums. (One pass would need a map — a data-structures-course tool.
// At fundamentals scale, two passes over a small array is clear and correct.)
//
// EDGE CASES: zero rows; a group with a single member; GPA out of [0,4]
// (validation: the row is rejected and counted — a table is only as good
// as its worst row).

#include <iostream>
#include <iomanip>
#include <string>

const int MAX_ROWS{100};

struct Student                     // one ROW of the table
{
    std::string name;
    int age{};
    double gpa{};
};

int main()
{
    Student rows[MAX_ROWS]{};
    int n{};
    if (!(std::cin >> n) || n < 0 || n > MAX_ROWS)
    {
        std::cout << "bad table header\n";
        return 1;
    }

    int loaded{0};
    int rejected{0};
    for (int i{0}; i < n; ++i)
    {
        Student s{};
        std::cin >> s.name >> s.age >> s.gpa;
        if (s.age < 16 || s.age > 90 || s.gpa < 0.0 || s.gpa > 4.0)
        {
            ++rejected;                        // validate the whole row, not fields alone
            continue;
        }
        rows[loaded] = s;
        ++loaded;
    }

    std::cout << "rows: " << loaded << "  rejected: " << rejected << "\n\n";
    if (loaded == 0)
    {
        std::cout << "no usable rows\n";
        return 0;
    }

    // --- column statistics (the whole table) ---
    long long ageSum{0};                       // ages are counts: integer sum
    double gpaSum{0.0};                        // GPA is a measure: floating sum
    for (int i{0}; i < loaded; ++i)
    {
        ageSum += rows[i].age;
        gpaSum += rows[i].gpa;
    }
    double ageMean{static_cast<double>(ageSum) / loaded};
    double gpaMean{gpaSum / loaded};

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "mean age: " << ageMean << "   mean gpa: " << gpaMean << "\n\n";

    // --- group mean of GPA by name (two passes, no maps) ---
    std::cout << "gpa by student:\n";
    bool grouped[MAX_ROWS]{};                  // which rows already joined a group
    for (int i{0}; i < loaded; ++i)
    {
        if (grouped[i])
        {
            continue;
        }
        const std::string key{rows[i].name};   // new group discovered
        double sum{0.0};
        int members{0};
        for (int j{0}; j < loaded; ++j)        // PASS 2: accumulate this group
        {
            if (!grouped[j] && rows[j].name == key)
            {
                sum += rows[j].gpa;
                ++members;
                grouped[j] = true;
            }
        }
        std::cout << "  " << key << ": " << sum / members
                  << "  (" << members << " row"
                  << (members == 1 ? "" : "s") << ")\n";
    }

    // --- sample check: Ana has two rows (3.4, 3.9) -> Ana: 3.65 (2 rows) ---
    return 0;
}
