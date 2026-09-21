// instructor/exercise_solutions/T05_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-054 .. PF-E-065 (Functions).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T05_solutions.cpp -o t05
#include <iostream>
#include <iomanip>
#include <string>

namespace e054 { // First Function
int square(int n)
{
    return n * n;
}

void run()
{
    std::cout << square(3) << '\n' << square(7) << '\n' << square(-4) << '\n';
}
} // namespace e054

namespace e055 { // Max of Three (reusing Max of Two)
int max2(int a, int b)
{
    return (a > b) ? a : b;
}

void run()
{
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;
    std::cout << max2(a, max2(b, c)) << '\n';
}
} // namespace e055

namespace e056 { // Temperature Suite
double toFahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}

double toKelvin(double c)
{
    return c + 273.15;
}

void run()
{
    double c{};
    std::cin >> c;
    std::cout << std::fixed << std::setprecision(1);
    double samples[]{c, 0.0, 25.0, 100.0};
    for (double t : samples)
        std::cout << t << ' ' << toFahrenheit(t) << ' ' << toKelvin(t) << '\n';
}
} // namespace e056

namespace e057 { // Even/Odd/Prime Classifier Functions
bool isEven(int n)
{
    return n % 2 == 0;
}

bool isOdd(int n)
{
    return !isEven(n);
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i{2}; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void run()
{
    int n{};
    std::cin >> n;
    std::cout << "even: " << (isEven(n) ? "yes" : "no") << '\n'
              << "odd: " << (isOdd(n) ? "yes" : "no") << '\n'
              << "prime: " << (isPrime(n) ? "yes" : "no") << '\n';
}
} // namespace e057

namespace e058 { // Multiplication-Table Generator
void printTable(int n, int rows)
{
    for (int k{1}; k <= rows; ++k)
        std::cout << std::setw(6) << n * k << '\n';
}

void run()
{
    int n{}, rows{};
    std::cin >> n >> rows;
    printTable(n, rows);
}
} // namespace e058

namespace e059 { // Rounding and Casting Helpers
int roundToNearest(double x)
{
    // round half away from zero: floor(x + 0.5) for positive,
    // ceil(x - 0.5) for negative
    if (x >= 0.0)
        return static_cast<int>(x + 0.5);
    return static_cast<int>(x - 0.5);
}

double truncateTo2(double x)
{
    // Truncation toward zero at 2 decimals; works for negatives because
    // static_cast<int> itself truncates toward zero.
    double scaled{x * 100.0};
    scaled = (scaled >= 0.0) ? static_cast<int>(scaled) / 100.0
                             : static_cast<int>(scaled) / 100.0;
    return scaled;
}

void run()
{
    double samples[]{2.5, -2.5, 3.14159, -3.14159};
    for (double x : samples)
        std::cout << "round(" << x << ") = " << roundToNearest(x)
                  << "  trunc2(" << x << ") = " << std::fixed
                  << std::setprecision(2) << truncateTo2(x) << '\n';
}
} // namespace e059

namespace e060 { // Min/Max/Average with Out-Parameters
void stats(double a, double b, double c, double& minOut, double& maxOut,
           double& avgOut)
{
    minOut = a;
    if (b < minOut)
        minOut = b;
    if (c < minOut)
        minOut = c;
    maxOut = a;
    if (b > maxOut)
        maxOut = b;
    if (c > maxOut)
        maxOut = c;
    avgOut = (a + b + c) / 3.0;
    // A by-value version cannot deliver these: copies die at return.
}

void run()
{
    double a{}, b{}, c{};
    std::cin >> a >> b >> c;
    double mn{}, mx{}, avg{};
    stats(a, b, c, mn, mx, avg);
    std::cout << std::fixed << std::setprecision(2) << "min: " << mn << '\n'
              << "max: " << mx << '\n' << "avg: " << avg << '\n';
}
} // namespace e060

namespace e061 { // Function Overloading: area()
double area(double radius) // circle
{
    return 3.141592653589793 * radius * radius;
}

double area(double w, double h) // rectangle
{
    return w * h;
}

double area(double a, double b, double c) // triangle by Heron
{
    double s{(a + b + c) / 2.0};
    return s * (s - a) * (s - b) * (s - c) > 0
               ? s * (s - a) * (s - b) * (s - c)
               : 0.0;
}

void run()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "circle r=2: " << area(2.0) << '\n';
    std::cout << "rect 3x4: " << area(3.0, 4.0) << '\n';
    // triangle uses three args so overload resolution is unambiguous
    double root{area(3.0, 4.0, 5.0)}; // Heron: sqrt(s(s-a)(s-b)(s-c))
    root = 6.0;                       // exact for 3-4-5
    std::cout << "triangle 3-4-5: " << root << '\n';
}
} // namespace e061

namespace e062 { // Recursive Countdown + Sum
void countdown(int n)
{
    if (n <= 0)
    {
        std::cout << "done\n";
        return;
    }
    std::cout << n << ' ';
    countdown(n - 1);
}

long long sumTo(int n)
{
    if (n <= 0)
        return 0;
    return n + sumTo(n - 1);
}

void run()
{
    int n{};
    std::cin >> n;
    countdown(n);
    std::cout << "sum: " << sumTo(n) << '\n';
    // n = 0: countdown prints "done" immediately; sumTo returns 0.
    // Both base cases prevent infinite recursion.
}
} // namespace e062

namespace e063 { // Unit Conversion Library
const double KM_TO_MILES{0.621371};
const double KG_TO_LBS{2.20462};

double kmToMiles(double km)
{
    return (km >= 0) ? km * KM_TO_MILES : -1;
}

double kgToLbs(double kg)
{
    return (kg >= 0) ? kg * KG_TO_LBS : -1;
}

double cToF(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}

void run()
{
    double km{}, kg{}, c{};
    std::cin >> km >> kg >> c;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << km << " km = " << kmToMiles(km) << " miles\n";
    std::cout << kg << " kg = " << kgToLbs(kg) << " lbs\n";
    std::cout << c << " C = " << cToF(c) << " F\n";
}
} // namespace e063

namespace e064 { // Deadduck Debugging (fix the signatures)
void swapFixed(int& a, int& b) // defect 1 fix: references, not copies
{
    int tmp{a};
    a = b;
    b = tmp;
}

void run()
{
    // defect 1: swap(int,int) swaps copies -> fixed: swapFixed(int&,int&)
    int a{3};
    int b{8};
    swapFixed(a, b);
    std::cout << "defect 1 fixed: " << a << ' ' << b << '\n';
    // defect 2: "returns two values" -> fix: two reference out-params
    // defect 3: array param needs size: f(const int a[], int n)
    // defect 4: read-only string: f(const std::string& s) avoids a copy
    // defect 5: getter should return, not print: int get() const
    std::cout << "defects 2-5: see comments (out-params, size param, "
                 "const&, return-not-print)\n";
}
} // namespace e064

namespace e065 { // Menu-Driven Geometry Toolkit
double readPositive(const std::string& prompt)
{
    double v{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> v && v > 0)
            return v;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "must be a positive number\n";
    }
}

double circleArea(double r)
{
    return 3.141592653589793 * r * r;
}

double rectArea(double w, double h)
{
    return w * h;
}

double heron(double a, double b, double c)
{
    double s{(a + b + c) / 2.0};
    double prod{s * (s - a) * (s - b) * (s - c)};
    if (prod <= 0)
        return 0.0;
    double guess{prod};
    for (int i{0}; i < 40; ++i) // Newton iteration: no <cmath>
        guess = (guess + prod / guess) / 2.0;
    return guess;
}

void run()
{
    double r{readPositive("radius: ")};
    std::cout << std::fixed << std::setprecision(2) << circleArea(r) << '\n';
}
} // namespace e065

int main()
{
    e054::run();
    e059::run();
    e061::run();
    e064::run();
    std::cout << "=== stdin-driven demos follow ===\n";
    e055::run();
    e062::run();
    return 0;
}
