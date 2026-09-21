// instructor/exercise_solutions/T01_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-001 .. PF-E-013 (Variables and Calculations).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T01_solutions.cpp -o t01
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>

namespace e001 { // Hello, You
void run()
{
    std::cout << "Hello, world!\n";
    std::cout << "Ready to learn C++.\n";
}
} // namespace e001

namespace e002 { // Blank-Frame Printer
void run()
{
    std::cout << "************\n";
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "************\n";
}
} // namespace e002

namespace e003 { // Age in Days
void run()
{
    int years{};
    std::cin >> years;
    int days{years * 365};
    std::cout << days << '\n';
}
} // namespace e003

namespace e004 { // Temperature Converter (C->F)
void run()
{
    double c{};
    std::cin >> c;
    double f{c * 9.0 / 5.0 + 32.0};
    std::cout << std::fixed << std::setprecision(1) << f << '\n';
}
} // namespace e004

namespace e005 { // Circle Report
void run()
{
    const double PI{3.141592653589793};
    double r{};
    std::cin >> r;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "diameter: " << 2 * r << '\n';
    std::cout << "circumference: " << 2 * PI * r << '\n';
    std::cout << "area: " << PI * r * r << '\n';
}
} // namespace e005

namespace e006 { // Receipt Line
void run()
{
    std::string name;
    double price{};
    int qty{};
    std::cin >> name >> price >> qty;
    double total{price * qty};
    std::cout << std::left << std::setw(12) << name
              << std::right << std::setw(4) << qty
              << std::fixed << std::setprecision(2) << std::setw(10)
              << total << '\n';
}
} // namespace e006

namespace e007 { // Digit Splitter
void run()
{
    int n{};
    std::cin >> n;
    int tens{n / 10};
    int units{n % 10};
    std::cout << tens << ' ' << units << '\n';
    std::cout << "sum: " << tens + units << '\n';
    std::cout << "product: " << tens * units << '\n';
}
} // namespace e007

namespace e008 { // Seconds Decomposer
void run()
{
    int total{};
    std::cin >> total;
    int h{total / 3600};
    int m{(total % 3600) / 60};
    int s{total % 60};
    std::cout << h << ':' << std::setfill('0') << std::setw(2) << m << ':'
              << std::setw(2) << s << '\n';
}
} // namespace e008

namespace e009 { // Coin Change (Static)
void run()
{
    int cents{};
    std::cin >> cents;
    int c25{cents / 25};
    cents %= 25;
    int c10{cents / 10};
    cents %= 10;
    int c5{cents / 5};
    cents %= 5;
    std::cout << "25c: " << c25 << '\n' << "10c: " << c10 << '\n'
              << "5c: " << c5 << '\n' << "1c: " << cents << '\n';
}
} // namespace e009

namespace e010 { // Swap Visualization
void run()
{
    int a{};
    int b{};
    std::cin >> a >> b;
    std::cout << "before: " << a << ' ' << b << '\n';
    int tmp{a};
    a = b;
    b = tmp;
    std::cout << "after good swap: " << a << ' ' << b << '\n';
    // The bad swap: a = b; b = a;  -- after the first assignment both
    // names hold b's value, so the original a is lost forever.
    int c{a};
    a = b;
    b = a; // c's original value is gone; this block demonstrates the loss
    std::cout << "after bad swap: " << c << ' ' << b << '\n';
}
} // namespace e010

namespace e011 { // Expression Forensics
void run()
{
    int a{7};
    double b{2.0};
    int c{3};
    // Predictions: a/c = 2 (integer division), a/b = 3.5 (promotion),
    // a%c = 1, a+b*c = 13 (b*c promotes to double), (a+b)*c = 27.0
    std::cout << "a/c: " << a / c << '\n';
    std::cout << "a/b: " << a / b << '\n';
    std::cout << "a%c: " << a % c << '\n';
    std::cout << "a+b*c: " << a + b * c << '\n';
    std::cout << "(a+b)*c: " << (a + b) * c << '\n';
}
} // namespace e011

namespace e012 { // Salary Calculator
void run()
{
    double wage{};
    double regular{};
    double overtime{};
    std::cin >> wage >> regular >> overtime;
    double gross{wage * regular + wage * 1.5 * overtime};
    double tax{gross * 0.11};
    const double LEVY{180.0};
    double net{gross - tax - LEVY};
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "gross: " << gross << '\n' << "tax: " << tax << '\n'
              << "levy: " << LEVY << '\n' << "net: " << net << '\n';
}
} // namespace e012

namespace e013 { // Deterministic Chaos (Integer Overflow)
void run()
{
    int n{1};
    long long m{1};
    for (int step{1}; step <= 10; ++step)
    {
        n = n * 10 + 7;
        m = m * 10 + 7;
        std::cout << step << ": " << n << ' ' << m << '\n';
    }
    // The two columns agree until the value exceeds INT_MAX (2147483647),
    // which happens at the 10th step (7777777777 > INT_MAX). int overflow
    // wraps (typical, not guaranteed by the standard); long long does not.
}
} // namespace e013

int main()
{
    e001::run();
    std::cout << "---\n";
    e002::run();
    std::cout << "---\n";
    e011::run();
    std::cout << "---\n";
    e013::run();
    std::cout << "--- (deterministic subset shown; others read stdin)\n";
    e003::run();
    e004::run();
    return 0;
}
