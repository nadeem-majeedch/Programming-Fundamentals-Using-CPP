// instructor/projects/reference/p01_grade_calc.cpp — INSTRUCTOR-ONLY
// Reference solution for Project 01 (Student Grade Calculator). Verified:
// g++ -std=c++17 -Wall -Wextra -pedantic (GCC 16.2), executed vs spec T1-T8.
#include <iostream>
#include <iomanip>
#include <string>

const double W_LAB{0.25};
const double W_MID{0.35};
const double W_FIN{0.40};

// weighted: lab/midterm/final in 0..100 -> weighted average.
// Precondition: all three in range (validated at the door). Postcondition: exact weighted mean.
double weighted(double lab, double mid, double fin)
{
    return lab * W_LAB + mid * W_MID + fin * W_FIN;
}

// letterOf: average -> letter per the spec ladder (descending thresholds).
// Pure function: no I/O. Precondition: 0 <= avg <= 100.
char letterOf(double avg)
{
    if (avg >= 90) return 'A';   // spec ladder uses +/- rows; the summary maps
    if (avg >= 87) return 'a';   // A-..C- via the two-letter encoding below.
    if (avg >= 83) return 'b';
    if (avg >= 80) return 'B';
    if (avg >= 77) return 'c';
    if (avg >= 73) return 'C';
    if (avg >= 67) return 'd';
    if (avg >= 60) return 'D';
    return 'F';
}

// letterText: map the ladder result to its exact spec text.
std::string letterText(double avg)
{
    if (avg >= 90) return "A";
    if (avg >= 87) return "A-";
    if (avg >= 83) return "B+";
    if (avg >= 80) return "B";
    if (avg >= 77) return "B-";
    if (avg >= 73) return "C+";
    if (avg >= 70) return "C";
    if (avg >= 67) return "C-";
    if (avg >= 60) return "D";
    return "F";
}

// readMark: one component mark. Three outcomes via `status`:
//   ok    -> out set, return true
//   range -> message printed, return true with status = "range"
//   eof   -> stream failed, return true with status = "eof"
bool readMark(const std::string& component, double& out, std::string& status)
{
    status = "ok";
    if (!(std::cin >> out))
    {
        status = "eof";
        return true;
    }
    if (out < 0.0 || out > 100.0)
    {
        std::cout << "bad mark for " << component << '\n';
        status = "range";
    }
    return true;
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    int count{0};
    int below60{0};
    double sumAvg{0.0};
    double bestAvg{-1.0};            // init below any possible average
    std::string bestName{};

    while (true)
    {
        std::cout << "Student (or DONE): ";
        std::string name{};
        if (!(std::cin >> name))
        {
            std::cout << "bad input\n";   // EOF mid-record: VR1, exit 1
            return 1;
        }
        if (name == "DONE")
        {
            break;
        }

        std::cout << "lab midterm final: ";
        double lab{}, mid{}, fin{};
        std::string status;
        bool rejected{false};
        readMark("lab", lab, status);
        if (status == "eof") { std::cout << "bad input\n"; return 1; }
        if (status == "range") rejected = true;
        readMark("midterm", mid, status);
        if (status == "eof") { std::cout << "bad input\n"; return 1; }
        if (status == "range") rejected = true;
        readMark("final", fin, status);
        if (status == "eof") { std::cout << "bad input\n"; return 1; }
        if (status == "range") rejected = true;
        if (rejected)
        {
            continue;                // record rejected; session continues (VR2/FR6)
        }

        double avg{weighted(lab, mid, fin)};
        std::cout << name << ": " << avg << " -> " << letterText(avg) << '\n';

        ++count;
        sumAvg += avg;
        if (avg < 60) ++below60;
        if (avg > bestAvg) { bestAvg = avg; bestName = name; }
    }

    if (count == 0)
    {
        std::cout << "no students\n";
        return 0;
    }
    std::cout << "students: " << count << "  best: " << bestName << ' '
              << bestAvg << "  class avg: " << sumAvg / count
              << "  below 60: " << below60 << '\n';
    return 0;
}
