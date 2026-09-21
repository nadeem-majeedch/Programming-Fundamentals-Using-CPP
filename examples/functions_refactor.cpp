// purpose: the flat gradebook program (before) and its decomposed version
//          (after) — used in L13 to teach function anatomy and the I/O
//          boundary principle.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic functions_refactor.cpp -o refactor

#include <iostream>
#include <string>

// ---------- BEFORE: everything inline in main (repeated, unnameable) ----------
// std::cout << "average = " << (a + b) / 2.0 << '\n';
// ... and every caller repeats the formula, the rounding, the label.

// ---------- AFTER: functions with single responsibilities ----------

// compute_average: pure computation — no I/O (I/O boundary principle)
double compute_average(double a, double b)
{
    return (a + b) / 2.0;
}

// to_letter: pure mapping from a number to a grade character
char to_letter(double average)
{
    if (average >= 90.0)
    {
        return 'A';
    }
    if (average >= 80.0)
    {
        return 'B';
    }
    if (average >= 70.0)
    {
        return 'C';
    }
    if (average >= 60.0)
    {
        return 'D';
    }
    return 'F';
}

// print_report: the ONLY place that touches cout in this program
void print_report(std::string name, double average, char letter)
{
    std::cout << name << ": average = " << average
              << ", grade = " << letter << '\n';
}

int main()
{
    std::string name{};
    double exam1{};
    double exam2{};

    std::cout << "Student name: ";
    std::cin >> name;
    std::cout << "Two exam scores: ";
    std::cin >> exam1 >> exam2;

    double avg{compute_average(exam1, exam2)};   // data flows in...
    char letter{to_letter(avg)};                 // ...and returns flow back

    print_report(name, avg, letter);             // I/O at the boundary

    return 0;
}
