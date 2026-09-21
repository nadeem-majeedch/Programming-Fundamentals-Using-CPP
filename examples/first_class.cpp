// purpose: first class — private data, constructors, validated mutator,
//          const getters, and the struct-vs-class contrast — used in L31.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic first_class.cpp -o firstclass

#include <iostream>
#include <string>

// The invariant this class protects: 0.0 <= gpa <= 4.0
class Student
{
public:                                  // the interface: outside code's only door
    // Default constructor: born valid.
    Student() = default;

    // Parameterized constructor with validation: invalid data cannot
    // create an object with a broken invariant.
    Student(std::string name, int id, double gpa)
        : name_{std::move(name)}, id_{id}, gpa_{clamp_gpa(gpa)}
    {
    }

    // Getters: read-only, therefore const member functions.
    const std::string& name() const { return name_; }
    int id() const { return id_; }
    double gpa() const { return gpa_; }

    // Mutator WITH validation: the only way gpa changes from outside.
    bool set_gpa(double gpa)
    {
        if (gpa < 0.0 || gpa > 4.0)
        {
            return false;                // reject: invariant cannot be broken
        }
        gpa_ = gpa;
        return true;
    }

    void print() const                   // read-only -> const
    {
        std::cout << name_ << " (id " << id_ << ", gpa " << gpa_ << ")\n";
    }

private:                                 // the data: invisible from outside
    static double clamp_gpa(double gpa)  // constructor helper
    {
        if (gpa < 0.0)
        {
            return 0.0;
        }
        if (gpa > 4.0)
        {
            return 4.0;
        }
        return gpa;
    }

    std::string name_{"unnamed"};
    int id_{0};
    double gpa_{0.0};
};

// The same data as a plain struct: NOTHING stops this corruption...
struct LooseStudent
{
    std::string name;
    int id{};
    double gpa{};
};

int main()
{
    Student a{"Ayesha", 101, 3.8};
    a.print();

    // Valid change through the guarded door:
    if (a.set_gpa(3.9))
    {
        std::cout << "set_gpa(3.9) accepted\n";
    }

    // Invalid change REJECTED by the class:
    if (!a.set_gpa(99.0))
    {
        std::cout << "set_gpa(99.0) rejected — invariant protected\n";
    }
    a.print();

    // ...whereas the struct accepts the corruption silently:
    LooseStudent loose{"Ben", 102, 3.2};
    loose.gpa = 99.0;                    // compiles; invariant destroyed
    std::cout << "loose struct accepted gpa = " << loose.gpa << " (!)\n";

    // Outside access to private data is a COMPILE error (the feature):
    // std::cout << a.gpa_;   // error: 'double Student::gpa_' is private
    std::cout << "public getter: a.gpa() = " << a.gpa() << '\n';

    return 0;
}
