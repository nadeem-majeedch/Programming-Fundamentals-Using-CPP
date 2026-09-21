// instructor/exercise_solutions/T10_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-112 .. PF-E-121 (Structures).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T10_solutions.cpp -o t10
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

namespace e112 { // Define and Print a Point
struct Point
{
    double x;
    double y;
};

void run()
{
    Point a{1.0, 2.0};
    Point b{};
    b.x = 3.0;
    b.y = 4.0;
    std::cout << std::fixed << std::setprecision(2) << '(' << a.x << ", "
              << a.y << ")\n"
              << '(' << b.x << ", " << b.y << ")\n"
              << "midpoint (" << (a.x + b.x) / 2 << ", " << (a.y + b.y) / 2
              << ")\n";
}
} // namespace e112

namespace e113 { // Student Record Basics
struct Student
{
    std::string name;
    int id;
    double gpa;
};

void run()
{
    Student s;
    std::cin >> s.name >> s.id >> s.gpa;
    std::cout << std::left << std::setw(15) << s.name << std::right
              << std::setw(6) << s.id << std::fixed << std::setprecision(2)
              << std::setw(8) << s.gpa << '\n';
}
} // namespace e113

namespace e114 { // Struct Copy vs Alias
struct Student2
{
    std::string name;
    double gpa;
};

void run()
{
    Student2 a{"Ada", 3.75};
    Student2 b{a}; // member-wise COPY: independent record
    b.gpa = 2.0;
    std::cout << "after copy-mutate: original gpa " << a.gpa << '\n';
    Student2& alias{a}; // alias: same object, second name
    alias.gpa = 4.0;
    std::cout << "after alias-mutate: original gpa " << a.gpa << '\n';
}
} // namespace e114

namespace e115 { // Rectangle Area/Perimeter Functions
struct Rect
{
    double w;
    double h;
};

double area(const Rect& r)
{
    return r.w * r.h;
}

double perimeter(const Rect& r)
{
    return 2 * (r.w + r.h);
}

void scale(Rect& r, double k)
{
    r.w *= k;
    r.h *= k;
}

void run()
{
    Rect r;
    std::cin >> r.w >> r.h;
    std::cout << std::fixed << std::setprecision(2) << "area: " << area(r)
              << '\n' << "perimeter: " << perimeter(r) << '\n';
    scale(r, 2.0);
    std::cout << "scaled: " << r.w << " x " << r.h << '\n';
}
} // namespace e115

namespace e116 { // Song Library (vector of structs)
struct Song
{
    std::string title;
    std::string artist;
    int seconds;
};

void run()
{
    int n{};
    std::cin >> n;
    std::vector<Song> songs(static_cast<std::size_t>(n));
    for (int i{0}; i < n; ++i)
        std::cin >> songs[static_cast<std::size_t>(i)].title
                 >> songs[static_cast<std::size_t>(i)].artist
                 >> songs[static_cast<std::size_t>(i)].seconds;
    int total{0};
    int longestIdx{0};
    for (int i{0}; i < n; ++i)
    {
        total += songs[static_cast<std::size_t>(i)].seconds;
        if (songs[static_cast<std::size_t>(i)].seconds
            > songs[static_cast<std::size_t>(longestIdx)].seconds)
            longestIdx = i;
    }
    std::string query;
    std::cin >> query;
    std::cout << "total: " << total / 60 << ':' << std::setfill('0')
              << std::setw(2) << total % 60 << '\n'
              << "longest: " << songs[static_cast<std::size_t>(longestIdx)].title
              << '\n'
              << "by " << query << ":\n";
    for (const Song& s : songs)
        if (s.artist == query)
            std::cout << "  " << s.title << " (" << s.seconds << "s)\n";
}
} // namespace e116

namespace e117 { // Nested Struct: Address inside Student
struct Address
{
    std::string city;
    std::string country;
};

struct StudentN
{
    std::string name;
    int id;
    double gpa;
    Address home;
};

void run()
{
    StudentN s;
    std::cin >> s.name >> s.id >> s.gpa >> s.home.city >> s.home.country;
    std::cout << s.name << ' ' << s.id << ' ' << s.gpa << " ("
              << s.home.city << ", " << s.home.country << ")\n";
    std::cout << "home.country: " << s.home.country << '\n';
    StudentN* p{&s};
    std::cout << "via p->home.city: " << p->home.city << '\n';
}
} // namespace e117

namespace e118 { // Bank Account Struct with Invariant Checks
struct Account
{
    std::string owner;
    long long balanceCents;
};

bool deposit(Account& a, long long cents)
{
    if (cents <= 0)
        return false;
    a.balanceCents += cents;
    return true;
}

bool withdraw(Account& a, long long cents, std::string& reason)
{
    if (cents <= 0)
    {
        reason = "non-positive amount";
        return false;
    }
    if (cents > a.balanceCents)
    {
        reason = "insufficient funds";
        return false;
    }
    a.balanceCents -= cents;
    return true;
}

void run()
{
    Account a;
    std::cin >> a.owner >> a.balanceCents;
    std::string action;
    while (std::cin >> action && action != "q")
    {
        long long amount{};
        std::cin >> amount;
        if (action == "deposit")
        {
            std::cout << (deposit(a, amount) ? "ok" : "rejected: non-positive")
                      << '\n';
        }
        else if (action == "withdraw")
        {
            std::string reason;
            std::cout << (withdraw(a, amount, reason)
                              ? "ok"
                              : "rejected: " + reason)
                      << '\n';
        }
    }
    std::cout << "final: " << a.balanceCents << '\n';
}
} // namespace e118

namespace e119 { // Parallel Arrays vs Struct (rewrite)
struct StudentR
{
    std::string name;
    int id;
    double gpa;
};

void run()
{
    // Parallel-array shredding: sorting gpas[] alone reorders GPAs but
    // leaves names[]/ids[] in place — records no longer match.
    StudentR roster[3]{{"Ben", 102, 3.2}, {"Ayesha", 101, 3.8}, {"Chen", 103, 3.9}};
    std::cout << "before:\n";
    for (const StudentR& s : roster)
        std::cout << "  " << s.name << ' ' << s.id << ' ' << s.gpa << '\n';
    for (int i{0}; i < 2; ++i) // sort by gpa; the RECORD moves as a unit
    {
        int best{i};
        for (int j{i + 1}; j < 3; ++j)
            if (roster[j].gpa > roster[best].gpa)
                best = j;
        if (best != i)
        {
            StudentR t{roster[i]};
            roster[i] = roster[best];
            roster[best] = t;
        }
    }
    std::cout << "after (intact):\n";
    for (const StudentR& s : roster)
        std::cout << "  " << s.name << ' ' << s.id << ' ' << s.gpa << '\n';
}
} // namespace e119

namespace e120 { // Struct with Array Member: Temperature Station
struct Station
{
    std::string name;
    double temps[7]{};
};

void analyze(const Station& st)
{
    double minV{st.temps[0]};
    double maxV{st.temps[0]};
    double sum{0.0};
    for (double t : st.temps)
    {
        if (t < minV)
            minV = t;
        if (t > maxV)
            maxV = t;
        sum += t;
    }
    double avg{sum / 7.0};
    std::cout << std::fixed << std::setprecision(2) << "min: " << minV << '\n'
              << "max: " << maxV << '\n' << "avg: " << avg << '\n';
    std::cout << "above:";
    for (int i{0}; i < 7; ++i)
        if (st.temps[i] > avg)
            std::cout << ' ' << i;
    std::cout << '\n';
}

void run()
{
    Station st;
    std::cin >> st.name;
    for (double& t : st.temps)
        std::cin >> t;
    analyze(st);
}
} // namespace e120

namespace e121 { // Course Roster Analytics
struct StudentA
{
    std::string name;
    int id;
    double gpa;
};

void printHighest(const std::vector<StudentA>& roster)
{
    std::size_t best{0};
    for (std::size_t i{1}; i < roster.size(); ++i)
        if (roster[i].gpa > roster[best].gpa)
            best = i;
    std::cout << "highest: " << roster[best].name << ' ' << roster[best].gpa
              << '\n';
}

void printBands(const std::vector<StudentA>& roster)
{
    int b1{0}, b2{0}, b3{0}, b4{0};
    for (const StudentA& s : roster)
    {
        if (s.gpa >= 3.5)
            ++b1;
        else if (s.gpa >= 3.0)
            ++b2;
        else if (s.gpa >= 2.0)
            ++b3;
        else
            ++b4;
    }
    std::cout << "bands: " << b1 << ' ' << b2 << ' ' << b3 << ' ' << b4 << '\n';
}

void sortById(std::vector<StudentA>& roster)
{
    for (std::size_t i{0}; i + 1 < roster.size(); ++i)
    {
        std::size_t best{i};
        for (std::size_t j{i + 1}; j < roster.size(); ++j)
            if (roster[j].id < roster[best].id)
                best = j;
        if (best != i)
        {
            StudentA t{roster[i]};
            roster[i] = roster[best];
            roster[best] = t;
        }
    }
}

void run()
{
    int n{};
    std::cin >> n;
    std::vector<StudentA> roster;
    for (int i{0}; i < n; ++i)
    {
        StudentA s;
        std::cin >> s.name >> s.id >> s.gpa;
        roster.push_back(s);
    }
    printHighest(roster);
    printBands(roster);
    sortById(roster);
    std::cout << "sorted by id:\n";
    for (const StudentA& s : roster)
        std::cout << "  " << s.id << ' ' << s.name << '\n';
    int query{};
    std::cin >> query;
    bool found{false};
    for (const StudentA& s : roster)
        if (s.id == query)
        {
            std::cout << s.name << ' ' << s.id << ' ' << s.gpa << '\n';
            found = true;
        }
    if (!found)
        std::cout << "not found\n";
}
} // namespace e121

int main()
{
    e112::run();
    e114::run();
    e119::run();
    std::cout << "=== stdin-driven demos follow ===\n";
    e113::run();
    e117::run();
    e120::run();
    e121::run();
    return 0;
}
