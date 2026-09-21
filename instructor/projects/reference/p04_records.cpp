// instructor/projects/reference/p04_records.cpp — INSTRUCTOR-ONLY
// Reference solution for Project 04 (Student Record Management System).
// Verified: g++ -std=c++17 -Wall -Wextra -pedantic (GCC 16.2), executed vs T1-T10.
// File grammar: id;name;program;gpa;graduated  (graduated: 0|1)
//
// INVARIANTS (class comment as shipped to students):
//   I1: 0.00 <= gpa <= 4.00
//   I2: graduated only ever goes false -> true
//   I3: program is one of cs|ds|se, fixed at construction (no mutator exists)
//   Roster invariant: ids unique (enforced by add)
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>

class Student
{
public:
    // empty(): placeholder record used only as the make() out-parameter —
    // carries no invariant claims (all-inked defaults), never observable
    // through the roster because make() overwrites it before add() sees it.
    static Student empty()
    {
        return Student{"S-0000", "?", "cs", 0.0, false};
    }

    // make: factory — the only way to create a valid Student from raw fields.
    // Returns false (and leaves `out` untouched) if any invariant would break.
    static bool make(const std::string& id, const std::string& name,
                     const std::string& program, double gpa, bool graduated,
                     Student& out)
    {
        if (gpa < 0.0 || gpa > 4.0) return false;           // I1
        if (program != "cs" && program != "ds" && program != "se") return false; // I3
        if (id.empty() || name.empty()) return false;
        out = Student{id, name, program, gpa, graduated};
        return true;
    }

    std::string id() const        { return id_; }
    std::string name() const      { return name_; }
    std::string program() const   { return program_; }
    double gpa() const            { return gpa_; }
    bool isGraduated() const      { return graduated_; }

    bool setGpa(double g)                     // guarded mutator (I1)
    {
        if (g < 0.0 || g > 4.0) return false;
        gpa_ = g;
        return true;
    }

    bool graduate()                           // guarded mutator (I2)
    {
        if (graduated_) return false;
        graduated_ = true;
        return true;
    }

private:
    Student(std::string id, std::string name, std::string program,
            double gpa, bool graduated)
        : id_{std::move(id)}, name_{std::move(name)}, program_{std::move(program)},
          gpa_{gpa}, graduated_{graduated} {}

    std::string id_;
    std::string name_;
    std::string program_;
    double gpa_;
    bool graduated_;
};

class Roster
{
public:
    // add: keeps the roster invariant (unique ids). Returns false if the id
    // already exists or the record breaks an invariant.
    bool add(const Student& s)
    {
        if (findIndex(s.id()) >= 0) return false;
        students_.push_back(s);
        return true;
    }

    const Student* findById(const std::string& id) const
    {
        int i{findIndex(id)};
        return i < 0 ? nullptr : &students_[i];
    }

    // mutable access for the two guarded mutators only
    Student* findByIdMutable(const std::string& id)
    {
        int i{findIndex(id)};
        return i < 0 ? nullptr : &students_[i];
    }

    int count() const { return static_cast<int>(students_.size()); }
    int graduatedCount() const
    {
        int k{0};
        for (const Student& s : students_) if (s.isGraduated()) ++k;
        return k;
    }

    // activeMean: mean gpa over non-graduated students; 0.0 when none (policy).
    double activeMean() const
    {
        double sum{0.0};
        int active{0};
        for (const Student& s : students_)
            if (!s.isGraduated()) { sum += s.gpa(); ++active; }
        return active == 0 ? 0.0 : sum / active;
    }

    void programCounts(int (&counts)[3]) const   // cs, ds, se — all students
    {
        counts[0] = counts[1] = counts[2] = 0;
        for (const Student& s : students_)
        {
            if (s.program() == "cs") ++counts[0];
            else if (s.program() == "ds") ++counts[1];
            else ++counts[2];
        }
    }

    // saveTo: write every record through its public observers only.
    bool saveTo(const std::string& path) const
    {
        std::ofstream of{path};
        if (!of.is_open()) return false;
        for (const Student& s : students_)
            of << s.id() << ';' << s.name() << ';' << s.program() << ';'
               << std::fixed << std::setprecision(2) << s.gpa() << ';'
               << (s.isGraduated() ? 1 : 0) << '\n';
        return true;
    }

private:
    int findIndex(const std::string& id) const
    {
        for (int i{0}; i < static_cast<int>(students_.size()); ++i)
            if (students_[i].id() == id) return i;
        return -1;
    }
    std::vector<Student> students_;
};

// loadRoster: skip-and-report; invariant-breaking lines never enter.
int loadRoster(const std::string& path, Roster& roster, int& skipped)
{
    std::ifstream in{path};
    if (!in.is_open()) return 0;
    int loaded{0};
    skipped = 0;
    std::string line{};
    while (std::getline(in, line))
    {
        if (line.empty()) continue;
        std::istringstream ls{line};
        std::string id, name, program, gpaTok, gradTok;
        if (!std::getline(ls, id, ';'))      { ++skipped; continue; }
        if (!std::getline(ls, name, ';'))    { ++skipped; continue; }
        if (!std::getline(ls, program, ';')) { ++skipped; continue; }
        if (!std::getline(ls, gpaTok, ';'))  { ++skipped; continue; }
        if (!std::getline(ls, gradTok))      { ++skipped; continue; }
        double gpa{};
        try { gpa = std::stod(gpaTok); } catch (...) { ++skipped; continue; }
        if (gradTok != "0" && gradTok != "1") { ++skipped; continue; }
        Student s{Student::empty()};
        if (!Student::make(id, name, program, gpa, gradTok == "1", s))
        {
            ++skipped;                        // invariant-breaking line: T6
            continue;
        }
        if (!roster.add(s))                   // duplicate id in file
        {
            ++skipped;
            continue;
        }
        ++loaded;
    }
    return loaded;
}


int main()
{
    Roster roster;
    int skipped{0};
    int loaded{loadRoster("roster.txt", roster, skipped)};
    std::cout << "loaded: " << loaded << " skipped: " << skipped << '\n';

    while (true)
    {
        std::cout << "menu (add|gpa|graduate|find|report|quit): ";
        std::string cmd{};
        if (!(std::cin >> cmd)) break;

        if (cmd == "add")
        {
            std::string id, name, program;
            std::cin >> id >> name >> program;
            Student s{Student::empty()};
            if (!Student::make(id, name, program, 0.0, false, s))
            {
                std::cout << "bad program\n";   // VR1 (or malformed id/name)
                continue;
            }
            if (!roster.add(s)) { std::cout << "duplicate id\n"; continue; }
            std::cout << "ok\n";
        }
        else if (cmd == "gpa")
        {
            std::string id, valueTok;
            std::cin >> id >> valueTok;
            double g{};
            try { g = std::stod(valueTok); }
            catch (...) { std::cout << "bad input\n"; continue; }
            Student* s{roster.findByIdMutable(id)};
            if (s == nullptr) { std::cout << "no such id\n"; continue; }
            std::cout << (s->setGpa(g) ? "ok" : "rejected") << '\n';
        }
        else if (cmd == "graduate")
        {
            std::string id{};
            std::cin >> id;
            Student* s{roster.findByIdMutable(id)};
            if (s == nullptr) { std::cout << "no such id\n"; continue; }
            std::cout << (s->graduate() ? "ok" : "already graduated") << '\n';
        }
        else if (cmd == "find")
        {
            std::string id{};
            std::cin >> id;
            const Student* s{roster.findById(id)};
            if (s == nullptr) { std::cout << "none\n"; continue; }
            std::cout << s->id() << ' ' << s->name() << ' ' << s->program()
                      << ' ' << std::fixed << std::setprecision(2) << s->gpa()
                      << (s->isGraduated() ? " graduated" : " active") << '\n';
        }
        else if (cmd == "report")
        {
            int counts[3]{};
            roster.programCounts(counts);
            std::cout << "students: " << roster.count()
                      << " graduated: " << roster.graduatedCount()
                      << " gpa-mean: " << std::fixed << std::setprecision(2)
                      << roster.activeMean() << '\n';
            std::cout << "cs: " << counts[0] << " ds: " << counts[1]
                      << " se: " << counts[2] << '\n';
        }
        else if (cmd == "quit")
        {
            break;
        }
        else
        {
            std::cout << "bad input\n";
        }
    }
    if (roster.saveTo("roster.txt"))
    {
        std::cout << "saved: " << roster.count() << '\n';
        return 0;
    }
    std::cout << "cannot save\n";
    return 2;
}
