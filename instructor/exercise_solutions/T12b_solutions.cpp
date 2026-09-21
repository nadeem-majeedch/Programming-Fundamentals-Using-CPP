// instructor/exercise_solutions/T12b_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-132 .. PF-E-152 (Classes and Objects), part 2:
// E-142 .. E-152 (collections, composition, synthesis).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T12b_solutions.cpp -o t12b
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

namespace e142 { // Inventory Class with Search
struct Item
{
    std::string sku;
    int qty;
};

class Inventory
{
public:
    bool restock(const std::string& sku, int qty)
    {
        if (qty <= 0)
            return false;
        for (Item& item : items_)
            if (item.sku == sku)
            {
                item.qty += qty;
                return true;
            }
        items_.push_back(Item{sku, qty});
        return true;
    }
    bool sell(const std::string& sku, int qty)
    {
        if (qty <= 0)
            return false;
        for (Item& item : items_)
            if (item.sku == sku)
            {
                if (qty > item.qty)
                    return false; // overdraft
                item.qty -= qty;
                return true;
            }
        return false; // unknown sku
    }
    int qtyOf(const std::string& sku) const
    {
        for (const Item& item : items_)
            if (item.sku == sku)
                return item.qty;
        return -1;
    }
    void print() const
    {
        for (const Item& item : items_)
            std::cout << item.sku << " x " << item.qty << '\n';
    }

private:
    std::vector<Item> items_;
};

void run()
{
    Inventory inv;
    std::cout << "restock SKU1 x10: "
              << (inv.restock("SKU1", 10) ? "ok" : "rejected") << '\n';
    std::cout << "sell SKU1 x3: " << (inv.sell("SKU1", 3) ? "ok" : "rejected") << '\n';
    std::cout << "sell SKU1 x99: " << (inv.sell("SKU1", 99) ? "ok" : "rejected (insufficient)") << '\n';
    std::cout << "sell NOPE x1: " << (inv.sell("NOPE", 1) ? "ok" : "rejected (unknown)") << '\n';
    std::cout << "qtyOf(NOPE): " << inv.qtyOf("NOPE") << '\n';
    inv.print();
}
} // namespace e142

namespace e143 { // Composition: Car has-an Engine
class Engine
{
public:
    void start()
    {
        running_ = true;
    }
    void stop()
    {
        running_ = false;
        rpm_ = 0;
    }
    bool running() const
    {
        return running_;
    }
    void setRpm(int rpm)
    {
        if (rpm >= 0 && rpm <= 8000)
            rpm_ = rpm;
    }

private:
    bool running_{false};
    int rpm_{0};
};

class Car
{
public:
    void startEngine()
    {
        engine_.start();
        engine_.setRpm(1500);
    }
    void stopEngine()
    {
        engine_.stop();
    }
    void drive(int minutes)
    {
        if (!engine_.running())
        {
            std::cout << "drive: engine off\n";
            return;
        }
        km_ += minutes; // 60 km/h = 1 km per minute
    }
    int km() const
    {
        return km_;
    }

private:
    Engine engine_;
    int km_{0};
};

void run()
{
    Car car;
    car.drive(20); // engine off
    car.startEngine();
    car.drive(20);
    car.stopEngine();
    std::cout << "km: " << car.km() << '\n';
}
} // namespace e143

namespace e144 { // Money class with operator overloads
class Money
{
public:
    explicit Money(long long cents = 0)
        : cents_{cents}
    {
    }
    Money operator+(const Money& other) const
    {
        return Money{cents_ + other.cents_};
    }
    Money operator-() const
    {
        return Money{-cents_};
    }
    long long cents() const
    {
        return cents_;
    }
    void print() const
    {
        bool neg{cents_ < 0};
        long long absCents{neg ? -cents_ : cents_};
        std::cout << (neg ? "-$" : "$") << absCents / 100 << '.'
                  << std::setfill('0') << std::setw(2) << absCents % 100;
    }

private:
    long long cents_; // may be negative (debt); never floats for money
};

void run()
{
    Money income1{1000};
    Money income2{2550};
    Money expense{-1275};
    Money net{income1 + income2 + expense};
    income1.print();
    std::cout << " + ";
    income2.print();
    std::cout << " = ";
    (income1 + income2).print();
    std::cout << '\n';
    expense.print();
    std::cout << " negated: ";
    (-expense).print();
    std::cout << '\n';
    std::cout << "net: ";
    net.print();
    std::cout << '\n';
}
} // namespace e144

namespace e145 { // Static Member: ID Generator
class Ticket
{
public:
    Ticket()
        : id_{nextId_++}
    {
    }
    int id() const
    {
        return id_;
    }

private:
    static int nextId_; // shared across ALL objects
    int id_;
};

int Ticket::nextId_{100}; // static data member defined outside the class

void run()
{
    Ticket a;
    Ticket b;
    Ticket c;
    std::cout << a.id() << '\n' << b.id() << '\n' << c.id() << '\n';
    // (1) nextId_ is shared: one counter serves every object.
    // (2) A per-object counter would start at 0 for each ticket — no
    //     uniqueness.
    // (3) Hidden shared state is like a global: two Ticket sequences in
    //     one test run interfere. Testability prefers injected state.
}
} // namespace e145

namespace e146 { // const-object and const-member-function Drill
class AccountC
{
public:
    explicit AccountC(long long cents)
        : balanceCents_{cents}
    {
    }
    long long balance() const
    {
        return balanceCents_;
    }
    bool deposit(long long cents)
    {
        if (cents <= 0)
            return false;
        balanceCents_ += cents;
        return true;
    }

private:
    long long balanceCents_;
};

void run()
{
    const AccountC frozen{500};
    std::cout << "const object balance: " << frozen.balance() << '\n';
    // ILLEGAL on a const object (compile error, kept as comment):
    //   frozen.deposit(100);
    // GCC 16: passing 'const AccountC' as 'this' argument discards
    // qualifiers. Rule: a member function is const unless it MUTATES
    // state; getters and printers are const.
}
} // namespace e146

namespace e147 { // Roster Class (vector of objects)
class StudentR
{
public:
    StudentR(std::string name, int id, double gpa)
        : name_{std::move(name)}, id_{id}, gpa_{gpa}
    {
    }
    int id() const
    {
        return id_;
    }
    double gpa() const
    {
        return gpa_;
    }
    const std::string& name() const
    {
        return name_;
    }

private:
    std::string name_;
    int id_;
    double gpa_;
};

class Roster
{
public:
    bool add(const StudentR& s)
    {
        for (const StudentR& existing : students_)
            if (existing.id() == s.id())
                return false; // duplicate id
        students_.push_back(s);
        return true;
    }
    const StudentR* findById(int id) const
    {
        for (const StudentR& s : students_)
            if (s.id() == id)
                return &s;
        return nullptr;
    }
    double averageGpa() const
    {
        if (students_.empty())
        {
            std::cout << "note: empty roster\n";
            return 0.0;
        }
        double sum{0.0};
        for (const StudentR& s : students_)
            sum += s.gpa();
        return sum / static_cast<double>(students_.size());
    }
    void printAll() const
    {
        for (const StudentR& s : students_)
            std::cout << "  " << s.id() << ' ' << s.name() << ' ' << s.gpa()
                      << '\n';
    }

private:
    std::vector<StudentR> students_;
};

void run()
{
    Roster r;
    std::cout << "add 101: " << (r.add(StudentR{"Ayesha", 101, 3.8}) ? "ok" : "rejected") << '\n';
    std::cout << "add 102: " << (r.add(StudentR{"Ben", 102, 3.2}) ? "ok" : "rejected") << '\n';
    std::cout << "add 101: " << (r.add(StudentR{"Dup", 101, 2.0}) ? "ok" : "rejected (duplicate)") << '\n';
    const StudentR* found{r.findById(102)};
    std::cout << "findById(102): " << (found ? found->name() : "not found") << '\n';
    std::cout << "findById(999): " << (r.findById(999) ? "found" : "not found") << '\n';
    std::cout << std::fixed << std::setprecision(2) << "average: " << r.averageGpa() << '\n';
    r.printAll();
}
} // namespace e147

namespace e148 { // Stack Class (bounded, array-backed)
class IntStack
{
public:
    bool push(int v)
    {
        if (top_ == 32)
            return false; // full
        data_[top_] = v;
        ++top_;
        return true;
    }
    bool pop(int& out)
    {
        if (top_ == 0)
            return false; // empty
        --top_;
        out = data_[top_];
        return true;
    }
    int size() const
    {
        return top_;
    }
    bool empty() const
    {
        return top_ == 0;
    }

private:
    int data_[32]{};
    int top_{0}; // invariant: 0 <= top_ <= 32
};

void run()
{
    IntStack s;
    for (int i{1}; i <= 33; ++i)
    {
        if (!s.push(i))
            std::cout << "push " << i << ": rejected (full)\n";
    }
    int out{};
    while (!s.empty())
        s.pop(out);
    std::cout << "last popped: " << out << '\n';
    std::cout << "pop on empty: " << (s.pop(out) ? "ok" : "rejected") << '\n';
}
} // namespace e148

namespace e149 { // Queue Class (circular buffer)
class IntQueue
{
public:
    bool enqueue(int v)
    {
        if (count_ == 8)
            return false; // full
        data_[(head_ + count_) % 8] = v;
        ++count_;
        return true;
    }
    bool dequeue(int& out)
    {
        if (count_ == 0)
            return false; // empty
        out = data_[head_];
        head_ = (head_ + 1) % 8; // the modulo IS the circle
        --count_;
        return true;
    }
    int size() const
    {
        return count_;
    }

private:
    int data_[8]{};
    int head_{0};
    int count_{0};
};

void run()
{
    IntQueue q;
    int out{};
    for (int i{1}; i <= 8; ++i)
        q.enqueue(i);
    std::cout << "enqueue 9th: " << (q.enqueue(9) ? "ok" : "rejected (full)") << '\n';
    for (int i{0}; i < 3; ++i)
        q.dequeue(out); // 1 2 3 leave
    for (int i{9}; i <= 11; ++i)
        q.enqueue(i); // wraps around the buffer
    std::cout << "size after wrap: " << q.size() << '\n';
    std::cout << "FIFO drain:";
    while (q.size() > 0)
    {
        q.dequeue(out);
        std::cout << ' ' << out;
    }
    std::cout << '\n';
    std::cout << "dequeue on empty: " << (q.dequeue(out) ? "ok" : "rejected") << '\n';
}
} // namespace e149

namespace e150 { // Money-Ledger Program
class MoneyL
{
public:
    explicit MoneyL(long long cents = 0)
        : cents_{cents}
    {
    }
    static MoneyL fromDollars(double dollars)
    {
        return MoneyL{static_cast<long long>(dollars * 100.0 + (dollars >= 0 ? 0.5 : -0.5))};
    }
    long long cents() const
    {
        return cents_;
    }
    void print() const
    {
        bool neg{cents_ < 0};
        long long abs{neg ? -cents_ : cents_};
        std::cout << (neg ? "-$" : "$") << abs / 100 << '.' << std::setfill('0')
                  << std::setw(2) << abs % 100;
    }

private:
    long long cents_;
};

class Ledger
{
public:
    bool record(MoneyL amount, const std::string& description)
    {
        if (amount.cents() == 0)
            return false;
        ++nextNumber_;
        entries_.push_back(Entry{nextNumber_, amount, description});
        return true;
    }
    MoneyL net() const
    {
        long long total{0};
        for (const Entry& e : entries_)
            total += e.amount.cents();
        return MoneyL{total};
    }
    void printStatement() const
    {
        for (const Entry& e : entries_)
        {
            std::cout << '#' << e.number << ' ';
            e.amount.print();
            std::cout << ' ' << e.description << '\n';
        }
    }

private:
    struct Entry
    {
        int number;
        MoneyL amount;
        std::string description;
    };
    std::vector<Entry> entries_;
    int nextNumber_{0};
};

void run()
{
    Ledger ledger;
    std::cout << "record 0: " << (ledger.record(MoneyL{0}, "zero") ? "ok" : "rejected") << '\n';
    ledger.record(MoneyL::fromDollars(1200.00), "salary");
    ledger.record(MoneyL::fromDollars(-85.50), "groceries");
    ledger.record(MoneyL::fromDollars(-137.25), "transport");
    ledger.record(MoneyL::fromDollars(25.00), "refund");
    ledger.printStatement();
    std::cout << "net: ";
    ledger.net().print();
    std::cout << '\n';
}
} // namespace e150

namespace e151 { // Encapsulation Siege
class Score
{
public:
    explicit Score(int initial) { setValue(initial); }
    int value() const { return value_; }
    void setValue(int v)
    {
        if (v >= 0 && v <= 100) // FIXED: validation restored
            value_ = v;
        else
            std::cout << "setValue(" << v << ") rejected\n";
    }

private:
    int value_{0}; // FIXED: was public — the first hole
};

void run()
{
    Score s{95};
    // ATTACK 1 (fixed): s.value_ = -1;  ->
    //   error: 'int Score::value_' is private within this context
    // ATTACK 2 (fixed): s.setValue(500); ->
    //   rejected at runtime by validation
    s.setValue(500);            // demonstrates the rejection
    std::cout << "value survives siege: " << s.value() << '\n';
}
} // namespace e151

namespace e152 { // Course Synthesis: Library System
struct Book
{
    std::string title;
    std::string author;
    int copies{0};
};

class Library
{
public:
    bool addBook(const std::string& title, const std::string& author, int copies)
    {
        if (copies <= 0 || findByTitle(title) != nullptr)
            return false;
        catalog_.push_back(Book{title, author, copies});
        return true;
    }
    bool loan(const std::string& title)
    {
        Book* b{findByTitle(title)};
        if (b == nullptr || b->copies == 0)
            return false;
        --b->copies;
        return true;
    }
    bool returnBook(const std::string& title)
    {
        Book* b{findByTitle(title)};
        if (b == nullptr)
            return false;
        ++b->copies;
        return true;
    }
    void findByAuthor(const std::string& author) const
    {
        int found{0};
        for (const Book& b : catalog_)
            if (b.author == author)
            {
                std::cout << "  " << b.title << '\n';
                ++found;
            }
        std::cout << "by \"" << author << "\": " << found << " found\n";
    }
    void printCatalog() const
    {
        for (const Book& b : catalog_)
            std::cout << "  " << b.title << " (" << b.copies << " in)\n";
    }

private:
    Book* findByTitle(const std::string& title)
    {
        for (Book& b : catalog_)
            if (b.title == title)
                return &b;
        return nullptr;
    }
    std::vector<Book> catalog_;
};

void run()
{
    Library lib;
    std::cout << "add Dune: " << (lib.addBook("Dune", "Frank Herbert", 2) ? "ok" : "rejected") << '\n';
    std::cout << "add C++ Primer: " << (lib.addBook("C++ Primer", "Ada", 1) ? "ok" : "rejected") << '\n';
    std::cout << "add Algorithms: " << (lib.addBook("Algorithms", "Ada", 1) ? "ok" : "rejected") << '\n';
    std::cout << "add Dune again: " << (lib.addBook("Dune", "X", 1) ? "ok" : "rejected (duplicate)") << '\n';
    std::cout << "loan Dune: " << (lib.loan("Dune") ? "ok" : "rejected") << '\n';
    std::cout << "loan Dune: " << (lib.loan("Dune") ? "ok" : "rejected") << '\n';
    std::cout << "loan Dune: " << (lib.loan("Dune") ? "ok" : "rejected (0 copies)") << '\n';
    std::cout << "return Dune: " << (lib.returnBook("Dune") ? "ok" : "rejected") << '\n';
    lib.findByAuthor("Ada");
    lib.printCatalog();
}
} // namespace e152

int main()
{
    e142::run();
    e143::run();
    e144::run();
    e145::run();
    e146::run();
    e147::run();
    e148::run();
    e149::run();
    e150::run();
    e151::run();
    e152::run();
    return 0;
}
