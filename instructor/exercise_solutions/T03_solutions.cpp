// instructor/exercise_solutions/T03_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-027 .. PF-E-042 (Loops).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T03_solutions.cpp -o t03
#include <iostream>
#include <iomanip>

namespace e027 { // Count-Up
void run()
{
    int n{};
    std::cin >> n;
    for (int i{1}; i <= n; ++i)
        std::cout << i << '\n';
}
} // namespace e027

namespace e028 { // Count-Down Timer
void run()
{
    int n{};
    std::cin >> n;
    for (int i{n}; i >= 1; --i)
        std::cout << i << '\n';
    std::cout << "LIFT OFF\n";
}
} // namespace e028

namespace e029 { // Multiplication Table (Single)
void run()
{
    int n{};
    std::cin >> n;
    for (int k{1}; k <= 12; ++k)
        std::cout << n << " x " << k << " = " << n * k << '\n';
}
} // namespace e029

namespace e030 { // Sum of First n Naturals
void run()
{
    int n{};
    std::cin >> n;
    long long sum{0};
    for (int i{1}; i <= n; ++i)
        sum += i;
    std::cout << sum << '\n';
}
} // namespace e030

namespace e031 { // Sentinel-Triggered Averager
void run()
{
    int value{};
    int count{0};
    long long sum{0};
    std::cin >> value;
    while (value != -1)
    {
        sum += value;
        ++count;
        std::cin >> value;
    }
    if (count == 0)
        std::cout << "no data\n";
    else
        std::cout << "count: " << count << '\n'
                  << "average: " << std::fixed << std::setprecision(2)
                  << static_cast<double>(sum) / count << '\n';
}
} // namespace e031

namespace e032 { // Digit Sum
void run()
{
    int n{};
    std::cin >> n;
    int sum{0};
    int digits{0};
    int work{n};
    while (work > 0)
    {
        sum += work % 10;
        ++digits;
        work /= 10;
    }
    std::cout << "digit sum: " << sum << '\n' << "digits: " << digits << '\n';
}
} // namespace e032

namespace e033 { // Digit Reversal
void run()
{
    int n{};
    std::cin >> n;
    int rev{0};
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    std::cout << rev << '\n';
}
} // namespace e033

namespace e034 { // Do-While Age Gate
void run()
{
    int age{};
    int attempts{0};
    do
    {
        std::cin >> age;
        ++attempts;
    } while (age < 3 || age > 120);
    std::cout << "accepted: " << age << '\n' << "attempts: " << attempts << '\n';
}
} // namespace e034

namespace e035 { // Power Table
void run()
{
    int base{}, k{};
    std::cin >> base >> k;
    long long power{1};
    for (int i{1}; i <= k; ++i)
    {
        power *= base;
        std::cout << power << '\n';
    }
}
} // namespace e035

namespace e036 { // Factorial with Overflow Watch
void run()
{
    int n{};
    std::cin >> n;
    long long fact{1};
    for (int i{2}; i <= n; ++i)
        fact *= i;
    std::cout << fact << '\n';
    // Experimental note: 13! = 6227020800 > INT_MAX (2147483647), so 12
    // is the largest n whose factorial fits in int... verify: 12! =
    // 479001600 < INT_MAX, 13! overflows. The int version wraps silently.
    std::cout << "note: 12 is the largest safe n for int\n";
}
} // namespace e036

namespace e037 { // Fibonacci Sequence
void run()
{
    int k{};
    std::cin >> k;
    long long a{1};
    long long b{1};
    for (int i{1}; i <= k; ++i)
    {
        std::cout << a << (i < k ? " " : "\n");
        long long next{a + b};
        a = b;
        b = next;
    }
    std::cout << "note: 47 terms exceed int (fib(47) > INT_MAX)\n";
}
} // namespace e037

namespace e038 { // Rectangle of Stars (nested)
void run()
{
    int rows{}, cols{};
    std::cin >> rows >> cols;
    for (int r{0}; r < rows; ++r)
    {
        for (int c{0}; c < cols; ++c)
            std::cout << '*';
        std::cout << '\n';
    }
    std::cout << '\n';
    for (int r{0}; r < rows; ++r)
    {
        for (int c{0}; c < cols; ++c)
        {
            bool border{r == 0 || r == rows - 1 || c == 0 || c == cols - 1};
            std::cout << (border ? '*' : ' ');
        }
        std::cout << '\n';
    }
}
} // namespace e038

namespace e039 { // Prime Checker
void run()
{
    int n{};
    std::cin >> n;
    bool prime{n >= 2};
    if (n == 2)
        prime = true;
    else if (n % 2 == 0)
        prime = false;
    else
    {
        for (int i{3}; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                prime = false;
                break;
            }
        }
    }
    std::cout << (prime ? "prime\n" : "composite\n");
}
} // namespace e039

namespace e040 { // Right-Angled Number Triangle
void run()
{
    int n{};
    std::cin >> n;
    for (int r{1}; r <= n; ++r)
    {
        for (int d{1}; d <= r; ++d)
            std::cout << d << (d < r ? " " : "");
        std::cout << '\n';
    }
    for (int r{1}; r <= n; ++r)
    {
        for (int s{0}; s < 2 * (n - r); ++s)
            std::cout << ' ';
        for (int d{1}; d <= r; ++d)
            std::cout << d << (d < r ? " " : "");
        std::cout << '\n';
    }
}
} // namespace e040

namespace e041 { // Collatz Length
void run()
{
    long long n{};
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "invalid\n";
        return;
    }
    int steps{0};
    long long peak{n};
    while (n != 1)
    {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        if (n > peak)
            peak = n;
        ++steps;
    }
    std::cout << "steps: " << steps << '\n' << "peak: " << peak << '\n';
}
} // namespace e041

namespace e042 { // Number Pyramid with Digit Rules
void run()
{
    int rows{};
    std::cin >> rows;
    if (rows < 1 || rows > 15)
    {
        std::cout << "invalid\n";
        return;
    }
    for (int r{1}; r <= rows; ++r)
    {
        for (int s{0}; s < rows - r; ++s)
            std::cout << "  ";
        long long sq{static_cast<long long>(r) * r};
        if (sq == 0)
            std::cout << '0';
        while (sq > 0) // digits of r^2, reversed
        {
            std::cout << sq % 10;
            sq /= 10;
            if (sq > 0)
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}
} // namespace e042

int main()
{
    e027::run();
    e030::run();
    e033::run();
    e036::run();
    e039::run();
    e041::run();
    return 0;
}
