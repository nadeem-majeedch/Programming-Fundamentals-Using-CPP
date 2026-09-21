// instructor/projects/reference/p02_expenses.cpp — INSTRUCTOR-ONLY
// Reference solution for Project 02 (Expense Tracking System). Verified:
// g++ -std=c++17 -Wall -Wextra -pedantic (GCC 16.2), executed vs spec T1-T10.
// Design note: index-sort variant — data arrays stay in entry order; the
// sorted report is produced by sorting an array of INDICES by amount, so
// category alignment stays trivially correct (the NFR-endorsed design).
#include <iostream>
#include <iomanip>
#include <string>

const int CAP{200};
const int N_CAT{5};

// addEntry is inlined into main's loop: the undo bookkeeping shares the same
// arrays and counters, and splitting them would split the invariant.
// catIndex: category word -> slot; -1 if unknown. Pure.
int catIndex(const std::string& c)
{
    if (c == "food") return 0;
    if (c == "transport") return 1;
    if (c == "printing") return 2;
    if (c == "supplies") return 3;
    if (c == "other") return 4;
    return -1;
}

// catName: slot -> canonical word (inverse of catIndex). Pure.
std::string catName(int slot)
{
    const char* names[N_CAT]{"food", "transport", "printing", "supplies", "other"};
    return names[slot];
}

// (entry insertion lives in main's loop so undo shares one bookkeeping path)


int main()
{
    std::cout << std::fixed << std::setprecision(2);

    double amounts[CAP]{};
    int cats[CAP]{};
    double catTotal[N_CAT]{};
    int catCount[N_CAT]{};
    int count{0};

    while (true)
    {
        std::cout << "expense (cat amount | undo | done): ";
        std::string word{};
        if (!(std::cin >> word)) break;            // EOF = done
        if (word == "done") break;
        if (word == "undo")
        {
            if (count == 0)
            {
                std::cout << "nothing to undo\n";
            }
            else
            {
                --count;
                catTotal[cats[count]] -= amounts[count];
                --catCount[cats[count]];
            }
            continue;
        }
        if (catIndex(word) < 0)
        {
            std::cout << "bad category\n";
            continue;
        }
        double amount{};
        if (!(std::cin >> amount)) { std::cout << "bad amount\n"; return 1; }
        if (amount < 0.01 || amount > 5000.0) { std::cout << "bad amount\n"; continue; }
        if (count >= CAP)
        {
            std::cout << "full\n";
            continue;
        }
        int slot{catIndex(word)};
        amounts[count] = amount;
        cats[count] = slot;
        ++count;
        catTotal[slot] += amount;
        ++catCount[slot];
    }

    if (count == 0)
    {
        std::cout << "no expenses\n";
        return 0;
    }

    double total{0.0};
    for (int i{0}; i < count; ++i) total += amounts[i];

    std::cout << "total: " << total << "\n";
    std::cout << "by category:\n";
    for (int c{0}; c < N_CAT; ++c)
    {
        double share{0.0};
        if (total > 0.0) share = catTotal[c] / total * 100.0;
        std::cout << catName(c) << ' ' << catTotal[c] << ' ' << share << "%\n";
    }

    // largest: first wins ties — scan in entry order
    int best{0};
    for (int i{1}; i < count; ++i) if (amounts[i] > amounts[best]) best = i;
    std::cout << "largest: " << amounts[best] << " (" << catName(cats[best]) << ")\n";

    // sorted report: insertion sort on an index array (data untouched)
    int order[CAP]{};
    for (int i{0}; i < count; ++i) order[i] = i;
    for (int i{1}; i < count; ++i)
    {
        int key{order[i]};
        int j{i - 1};
        while (j >= 0 && amounts[order[j]] > amounts[key])
        {
            order[j + 1] = order[j];
            --j;
        }
        order[j + 1] = key;
    }
    std::cout << "sorted:";
    for (int i{0}; i < count; ++i) std::cout << ' ' << amounts[order[i]];
    std::cout << '\n';

    int over{0};
    for (int i{0}; i < count; ++i) if (amounts[i] > 100.0) ++over;
    std::cout << "over 100: " << over << '\n';
    return 0;
}
