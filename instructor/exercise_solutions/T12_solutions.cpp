// instructor/exercise_solutions/T12_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-132 .. PF-E-152 (Classes and Objects), part 1:
// E-132 .. E-141 (the class mechanics half).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T12_solutions.cpp -o t12
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

namespace e132 { // First Class: Counter
class Counter
{
public:
    void increment()
    {
        ++count_;
    }
    int value() const
    {
        return count_;
    }

private:
    int count_{0};
};

void run()
{
    Counter c;
    c.increment();
    c.increment();
    c.increment();
    std::cout << c.value() << '\n';
}
} // namespace e132

namespace e133 { // Private Data Enforcement
void run()
{
    e132::Counter c;
    c.increment();
    // ILLEGAL (kept out of the build; this is the exact experiment):
    //   c.count_ = 99;
    // GCC 16 error: 'int Counter::count_' is private within this context
    // That error IS the feature: outside code cannot corrupt the state.
    std::cout << "legal path only: " << c.value() << '\n';
}
} // namespace e133

namespace e134 { // Temperature Class
class Temperature
{
public:
    Temperature() = default;
    explicit Temperature(double c)
        : celsius_{c}
    {
    }
    double celsius() const
    {
        return celsius_;
    }
    void setCelsius(double c)
    {
        if (c < -273.15)
        {
            std::cout << "setCelsius(" << c << ") rejected\n";
            return;
        }
        celsius_ = c;
    }
    double fahrenheit() const
    {
        return celsius_ * 9.0 / 5.0 + 32.0;
    }

private:
    double celsius_{0.0};
};

void run()
{
    Temperature t;
    t.setCelsius(-300.0); // rejected: below absolute zero
    t.setCelsius(37.0);
    std::cout << std::fixed << std::setprecision(1) << "fahrenheit: "
              << t.fahrenheit() << '\n';
}
} // namespace e134

namespace e135 { // Rectangle Class (two constructors)
class Rect
{
public:
    Rect()
        : w_{1.0}, h_{1.0}
    {
    }
    Rect(double w, double h)
    {
        if (w <= 0 || h <= 0)
        {
            w_ = 1.0;
            h_ = 1.0;
        }
        else
        {
            w_ = w;
            h_ = h;
        }
    }
    double area() const
    {
        return w_ * h_;
    }
    double perimeter() const
    {
        return 2 * (w_ + h_);
    }
    void scale(double k)
    {
        if (k <= 0)
        {
            std::cout << "scale(" << k << ") rejected\n";
            return;
        }
        w_ *= k;
        h_ *= k;
    }

private:
    double w_;
    double h_;
};

void run()
{
    Rect a{3.0, 4.0};
    std::cout << std::fixed << std::setprecision(2) << "area: " << a.area()
              << '\n';
    a.scale(-2.0); // rejected
    a.scale(2.0);
    std::cout << "area after scale(2): " << a.area() << '\n';
    Rect bad{0.0, 5.0}; // falls back to 1x1
    std::cout << "fallback area: " << bad.area() << '\n';
}
} // namespace e135

namespace e136 { // Bank Account Class
class Account
{
public:
    explicit Account(const std::string& owner, long long opening = 0)
        : owner_{opening < 0 ? std::string{} : owner}, balanceCents_{opening < 0 ? 0 : opening}
    {
    }
    bool deposit(long long cents)
    {
        if (cents <= 0)
            return false;
        balanceCents_ += cents;
        return true;
    }
    bool withdraw(long long cents)
    {
        if (cents <= 0)
            return false;
        if (cents > balanceCents_)
            return false;
        balanceCents_ -= cents;
        return true;
    }
    long long balance() const
    {
        return balanceCents_;
    }
    void print() const
    {
        std::cout << owner_ << ": " << balanceCents_ << " cents\n";
    }

private:
    std::string owner_;
    long long balanceCents_;
};

void run()
{
    Account a{"Ayesha", 500};
    std::cout << "deposit 200: " << (a.deposit(200) ? "ok" : "rejected") << '\n';
    std::cout << "withdraw 900: " << (a.withdraw(900) ? "ok" : "rejected (insufficient funds)") << '\n';
    std::cout << "withdraw -5: " << (a.withdraw(-5) ? "ok" : "rejected (non-positive)") << '\n';
    a.print();
}
} // namespace e136

namespace e137 { // Getters, Setters, and const-correctness
class AccountB
{
public:
    explicit AccountB(std::string owner, long long cents)
        : owner_{std::move(owner)}, balanceCents_{cents}
    {
    }
    std::string owner() const // const getter: callable on const objects
    {
        return owner_;
    }
    long long balance() const
    {
        return balanceCents_;
    }
    void rename(const std::string& newName)
    {
        if (!newName.empty())
            owner_ = newName;
    }

private:
    std::string owner_;
    long long balanceCents_;
};

void audit(const AccountB& a)
{
    // Both calls require const member functions; dropping const from
    // either breaks this function with:
    //   'passing ... as this argument discards qualifiers'
    std::cout << "audit: " << a.owner() << " holds " << a.balance()
              << " cents\n";
}

void run()
{
    AccountB a{"Ayesha", 50000};
    audit(a);
    a.rename("A. Karim");
    audit(a);
}
} // namespace e137

namespace e138 { // Student Class (struct->class refactor)
class Student
{
public:
    Student(std::string name, int id, double gpa)
        : name_{std::move(name)}, id_{id}
    {
        setGpa(gpa); // construct valid: same validation path
    }
    void setGpa(double gpa)
    {
        if (gpa >= 0.0 && gpa <= 4.0)
            gpa_ = gpa;
        else
            std::cout << "set_gpa(" << gpa << ") rejected\n";
    }
    double gpa() const
    {
        return gpa_;
    }
    int id() const
    {
        return id_;
    }
    void print() const
    {
        std::cout << name_ << ' ' << id_ << ' ' << gpa_ << '\n';
    }

private:
    std::string name_;
    int id_;
    double gpa_{0.0};
};

void run()
{
    Student s{"Ayesha", 101, 3.75};
    s.setGpa(9.0); // rejected
    s.setGpa(3.9);
    s.print();
}
} // namespace e138

namespace e139 { // Playlist Class
class Playlist
{
public:
    explicit Playlist(std::string name)
        : name_{std::move(name)}
    {
    }
    bool add(const std::string& song)
    {
        if (song.empty())
            return false;
        for (const std::string& s : songs_)
            if (s == song)
                return false; // duplicate
        songs_.push_back(song);
        return true;
    }
    bool remove(const std::string& song)
    {
        for (std::size_t i{0}; i < songs_.size(); ++i)
            if (songs_[i] == song)
            {
                songs_.erase(songs_.begin() + static_cast<long>(i));
                return true;
            }
        return false;
    }
    std::size_t size() const
    {
        return songs_.size();
    }
    void print() const
    {
        std::cout << name_ << " (" << songs_.size() << "): ";
        for (const std::string& s : songs_)
            std::cout << s << ' ';
        std::cout << '\n';
    }

private:
    std::string name_;
    std::vector<std::string> songs_;
};

void run()
{
    Playlist p{"Favourites"};
    std::cout << "add Song A: " << (p.add("Song A") ? "ok" : "rejected") << '\n';
    std::cout << "add Song A: " << (p.add("Song A") ? "ok" : "rejected (duplicate)") << '\n';
    std::cout << "add Song B: " << (p.add("Song B") ? "ok" : "rejected") << '\n';
    p.remove("Song A");
    std::cout << "after remove: size " << p.size() << '\n';
    p.print();
}
} // namespace e139

namespace e140 { // Time Class with Wrapping Invariant
class ClockT
{
public:
    ClockT(int h, int m)
    {
        if (h < 0 || h > 23 || m < 0 || m > 59)
        {
            std::cout << "invalid time " << h << ':' << m << ", clamped to 00:00\n";
            h_ = 0;
            m_ = 0;
        }
        else
        {
            h_ = h;
            m_ = m;
        }
    }
    void tick()
    {
        ++m_;
        if (m_ == 60)
        {
            m_ = 0;
            ++h_;
            if (h_ == 24)
                h_ = 0;
        }
    }
    void print() const
    {
        std::cout << std::setfill('0') << std::setw(2) << h_ << ':'
                  << std::setw(2) << m_ << '\n';
    }

private:
    int h_{0};
    int m_{0};
};

void run()
{
    ClockT c{23, 58};
    c.print();
    c.tick();
    c.print();
    c.tick();
    c.print();
    ClockT bad{25, 0}; // rejected, clamped
}
} // namespace e140

namespace e141 { // Fraction Class
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t{b};
        b = a % b;
        a = t;
    }
    return a;
}

class Fraction
{
public:
    Fraction(int num, int den)
        : num_{num}, den_{den}
    {
        if (den_ == 0)
        {
            std::cout << "denominator rejected, set to 1\n";
            den_ = 1;
        }
        normalize();
    }
    Fraction add(const Fraction& other) const
    {
        // a/b + c/d = (a*d + c*b) / (b*d); constructor reduces.
        return Fraction{num_ * other.den_ + other.num_ * den_,
                        den_ * other.den_};
    }
    void print() const
    {
        std::cout << num_ << '/' << den_;
    }

private:
    void normalize()
    {
        int g{gcd(num_ < 0 ? -num_ : num_, den_)};
        if (g > 1)
        {
            num_ /= g;
            den_ /= g;
        }
        if (den_ < 0)
        { // sign lives in the numerator
            den_ = -den_;
            num_ = -num_;
        }
    }
    int num_;
    int den_;
};

void run()
{
    Fraction sixth{1, 6};
    Fraction third{1, 3};
    Fraction sum{sixth.add(third)};
    std::cout << "1/6 + 1/3 = ";
    sum.print();
    std::cout << '\n';
    Fraction bad{3, 0}; // rejected, denominator set to 1
    std::cout << "bad reduced: ";
    bad.print();
    std::cout << '\n';
}
} // namespace e141

int main()
{
    e132::run();
    e133::run();
    e134::run();
    e135::run();
    e136::run();
    e137::run();
    e138::run();
    e139::run();
    e140::run();
    e141::run();
    return 0;
}
