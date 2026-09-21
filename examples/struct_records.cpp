// purpose: struct definition, brace initialization, member access (., ->),
//          functions over records, and vector-of-struct aggregates — L28.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic struct_records.cpp -o records

#include <iostream>
#include <string>
#include <vector>

struct Address                    // nested record type
{
    std::string city;
    std::string country;
};

struct Student                    // pure data — behavior comes in Module 16
{
    std::string name;
    int id{};
    double gpa{};
    Address home;                 // nested struct as a member
};

// Read-only: const& per the passing-mode checklist (no copy, no modification).
void print(const Student& s)
{
    std::cout << s.name << " (id " << s.id << ", gpa " << s.gpa
              << ", " << s.home.city << ", " << s.home.country << ")\n";
}

// Write-back through a reference.
void promote(Student& s)
{
    if (s.gpa < 4.0)
    {
        s.gpa += 0.1;
    }
}

// Factory: build and return a record by value.
Student make(std::string name, int id, double gpa,
             std::string city, std::string country)
{
    Student s{};
    s.name = std::move(name);     // std::move is explained in the lecture
    s.id = id;                    // notes; it simply transfers the string.
    s.gpa = gpa;
    s.home = Address{std::move(city), std::move(country)};
    return s;
}

// Aggregates over a collection of records (M9 algorithms, new element type).
double average_gpa(const std::vector<Student>& roster)
{
    double total{};
    for (const Student& s : roster)
    {
        total += s.gpa;
    }
    return total / static_cast<double>(roster.size());
}

int find_by_id(const std::vector<Student>& roster, int id)
{
    for (std::vector<Student>::size_type i{0}; i < roster.size(); ++i)
    {
        if (roster[i].id == id)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main()
{
    // Brace initialization: members in declaration order.
    Student a{"Ayesha", 101, 3.8, Address{"Lahore", "Pakistan"}};
    Student b{};                       // all members default (id 0, gpa 0.0)
    b.name = "Ben";
    b.id = 102;
    b.gpa = 3.2;
    b.home = Address{"Karachi", "Pakistan"};

    std::vector<Student> roster{a, b};
    roster.push_back(make("Chen", 103, 3.9, "Singapore", "Singapore"));

    std::cout << "Roster:\n";
    for (const Student& s : roster)
    {
        print(s);
    }

    promote(roster[1]);
    std::cout << "\nafter promote, " << roster[1].name << "'s gpa = "
              << roster[1].gpa << '\n';

    // Arrow access: (*p).member or p->member (two spellings, one meaning).
    Student* p{&roster[0]};
    std::cout << "via (*p).gpa = " << (*p).gpa
              << ", via p->gpa = " << p->gpa << '\n';

    std::cout << "average gpa = " << average_gpa(roster) << '\n';
    std::cout << "find id 103 -> index " << find_by_id(roster, 103) << '\n';
    std::cout << "find id 999 -> index " << find_by_id(roster, 999)
              << " (-1 = not found)\n";

    // Whole-struct assignment copies every member.
    Student copy{a};
    std::cout << "\ncopy of a: " << copy.name << " " << copy.home.city << '\n';

    return 0;
}
