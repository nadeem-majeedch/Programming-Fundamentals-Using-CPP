// instructor/exercise_solutions/T04_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-043 .. PF-E-053 (Number Problems).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T04_solutions.cpp -o t04
#include <iostream>
#include <iomanip>

namespace e043 { // Even/Odd Reporter (range)
void run()
{
    int lo{}, hi{};
    std::cin >> lo >> hi;
    for (int i{lo}; i <= hi; ++i)
    {
        // C++ truncates toward zero: -3 % 2 == -1, so test != 0, not == 1.
        bool even{(i % 2) == 0};
        std::cout << i << (even ? " even" : " odd");
        if (i < hi)
            std::cout << ' ';
    }
    std::cout << '\n';
}
} // namespace e043

namespace e044 { // Multiples Counter
void run()
{
    int k{}, n{};
    std::cin >> k >> n;
    int count{0};
    long long sum{0};
    for (int i{k}; i <= n; i += k)
    {
        ++count;
        sum += i;
    }
    std::cout << "count: " << count << '\n' << "sum: " << sum << '\n';
}
} // namespace e044

namespace e045 { // Perfect Number Check
void run()
{
    int n{};
    std::cin >> n;
    long long sum{1 < n ? 1 : 0}; // 1 is a proper divisor of every n > 1
    std::cout << "divisors: ";
    bool first{true};
    for (int i{1}; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int other{n / i};
            if (first)
            {
                std::cout << i;
                first = false;
            }
            else
                std::cout << ' ' << i;
            if (other != i && other != n)
            {
                sum += i;
                sum += other;
            }
            else if (other == i)
                sum += i;
        }
    }
    std::cout << '\n';
    std::cout << (sum == n ? "perfect" : "not perfect") << '\n';
}
} // namespace e045

namespace e046 { // GCD (Euclid, iterative)
void run()
{
    long long a{}, b{};
    std::cin >> a >> b;
    int steps{0};
    while (b != 0)
    {
        long long t{b};
        b = a % b;
        a = t;
        ++steps;
    }
    std::cout << "gcd: " << a << '\n' << "steps: " << steps << '\n';
}
} // namespace e046

namespace e047 { // Armstrong Numbers (range)
int digitCount(int n)
{
    int d{1};
    while (n >= 10)
    {
        n /= 10;
        ++d;
    }
    return d;
}

int ipow(int base, int exp)
{
    int result{1};
    for (int i{0}; i < exp; ++i)
        result *= base;
    return result;
}

void run()
{
    for (int n{1}; n <= 999; ++n)
    {
        int digits{digitCount(n)};
        int sum{0};
        int work{n};
        while (work > 0)
        {
            sum += ipow(work % 10, digits);
            work /= 10;
        }
        if (sum == n)
            std::cout << n << " (digits^" << digits << " sum)\n";
    }
}
} // namespace e047

namespace e048 { // Binary Representation
void run()
{
    long long n{};
    std::cin >> n;
    if (n == 0)
    {
        std::cout << "0\n";
        return;
    }
    char bits[64]{};
    int i{0};
    while (n > 0)
    {
        bits[i++] = static_cast<char>('0' + n % 2);
        n /= 2;
    }
    while (i > 0)
        std::cout << bits[--i];
    std::cout << '\n';
}
} // namespace e048

namespace e049 { // Prime Twins Gap Report
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i{3}; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void run()
{
    int prevPrime{-1};
    int pairs{0};
    int largestGap{0};
    int gapFrom{0};
    int gapTo{0};
    std::cout << "twins: ";
    for (int n{2}; n <= 500; ++n)
    {
        if (!isPrime(n))
            continue;
        if (prevPrime >= 0)
        {
            int gap{n - prevPrime};
            if (gap == 2)
            {
                std::cout << '(' << prevPrime << ',' << n << ") ";
                ++pairs;
            }
            if (gap > largestGap)
            {
                largestGap = gap;
                gapFrom = prevPrime;
                gapTo = n;
            }
        }
        prevPrime = n;
    }
    std::cout << '\n';
    std::cout << "pairs: " << pairs << '\n';
    std::cout << "largest gap: " << largestGap << " (" << gapFrom << " to "
              << gapTo << ")\n";
}
} // namespace e049

namespace e050 { // Harmonic Series with Cutoff
void run()
{
    double eps{};
    std::cin >> eps;
    double h{0.0};
    int terms{0};
    int i{1};
    while (true)
    {
        double term{1.0 / i};
        if (term < eps)
            break;
        h += term;
        ++terms;
        ++i;
    }
    std::cout << "terms: " << terms << '\n' << std::fixed
              << std::setprecision(6) << "H: " << h << '\n';
}
} // namespace e050

namespace e051 { // Palindromic Number Iterator
long long reverseNumber(long long n)
{
    long long rev{0};
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

void run()
{
    int lo{}, hi{};
    std::cin >> lo >> hi;
    int count{0};
    for (int n{lo}; n <= hi; ++n)
    {
        if (reverseNumber(n) == n)
        {
            std::cout << n << (count == 0 ? "" : "");
            std::cout << ' ';
            ++count;
        }
    }
    std::cout << '\n' << "count: " << count << '\n';
}
} // namespace e051

namespace e052 { // Collatz Longest Chain Under N
int chainLength(long long n, long long& peak)
{
    int steps{0};
    peak = n;
    while (n != 1)
    {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        if (n > peak)
            peak = n;
        ++steps;
    }
    return steps;
}

void run()
{
    int n{};
    std::cin >> n;
    int bestStart{1};
    int bestLen{0};
    long long bestPeak{1};
    for (int start{1}; start <= n; ++start)
    {
        long long peak{};
        int len{chainLength(start, peak)};
        if (len > bestLen)
        {
            bestLen = len;
            bestStart = start;
            bestPeak = peak;
        }
    }
    std::cout << "start: " << bestStart << '\n'
              << "length: " << bestLen << '\n' << "peak: " << bestPeak << '\n';
}
} // namespace e052

namespace e053 { // Goldbach Verification Sweep
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
    bool allVerified{true};
    for (int even{4}; even <= 200; even += 2)
    {
        bool found{false};
        for (int p{2}; p <= even / 2 && !found; ++p)
        {
            if (isPrime(p) && isPrime(even - p))
            {
                std::cout << even << " = " << p << " + " << even - p << '\n';
                found = true;
            }
        }
        if (!found)
            allVerified = false;
    }
    std::cout << (allVerified ? "verified" : "counterexample found") << '\n';
}
} // namespace e053

int main()
{
    e046::run();
    e048::run();
    e050::run();
    e052::run();
    return 0;
}
