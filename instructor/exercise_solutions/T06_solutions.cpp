// instructor/exercise_solutions/T06_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-066 .. PF-E-078 (Arrays).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T06_solutions.cpp -o t06
#include <iostream>
#include <iomanip>

namespace e066 { // Array Echo
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    for (int i{0}; i < n; ++i)
        std::cout << a[i] << (i < n - 1 ? " " : "\n");
    for (int i{n - 1}; i >= 0; --i)
        std::cout << a[i] << (i > 0 ? " " : "\n");
}
} // namespace e066

namespace e067 { // Array Sum and Mean
void run()
{
    int n{};
    std::cin >> n;
    long long sum{0};
    for (int i{0}; i < n; ++i)
    {
        int v{};
        std::cin >> v;
        sum += v;
    }
    std::cout << "sum: " << sum << '\n'
              << "mean: " << std::fixed << std::setprecision(2)
              << static_cast<double>(sum) / n << '\n';
}
} // namespace e067

namespace e068 { // Fill with Pattern
void run()
{
    int a[10]{};
    for (int i{0}; i < 10; ++i)
        a[i] = 3 * i + 2;
    for (int i{0}; i < 10; ++i)
        std::cout << a[i] << (i < 9 ? " " : "\n");
    for (int i{0}; i < 10; ++i)
        a[i] = (i + 1) * (i + 1);
    for (int i{0}; i < 10; ++i)
        std::cout << a[i] << (i < 9 ? " " : "\n");
}
} // namespace e068

namespace e069 { // Count Occurrences
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int key{};
    std::cin >> key;
    int count{0};
    std::cout << "positions: ";
    for (int i{0}; i < n; ++i)
    {
        if (a[i] == key)
        {
            std::cout << i << ' ';
            ++count;
        }
    }
    std::cout << '\n' << "count: " << count << '\n';
}
} // namespace e069

namespace e070 { // Min and Max with Positions
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int minVal{a[0]}, minPos{0}, maxVal{a[0]}, maxPos{0};
    for (int i{1}; i < n; ++i)
    {
        if (a[i] < minVal)
        {
            minVal = a[i];
            minPos = i;
        }
        if (a[i] > maxVal)
        {
            maxVal = a[i];
            maxPos = i;
        }
    }
    std::cout << "min: " << minVal << " (pos " << minPos << ")\n"
              << "max: " << maxVal << " (pos " << maxPos << ")\n";
}
} // namespace e070

namespace e071 { // Reverse In Place
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    std::cout << "before:";
    for (int i{0}; i < n; ++i)
        std::cout << ' ' << a[i];
    std::cout << '\n';
    for (int i{0}; i < n / 2; ++i)
    {
        int tmp{a[i]};
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
    std::cout << "after:";
    for (int i{0}; i < n; ++i)
        std::cout << ' ' << a[i];
    std::cout << '\n';
}
} // namespace e071

namespace e072 { // Remove All Occurrences (compact)
void run()
{
    int n{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    int key{};
    std::cin >> key;
    int out{0};
    for (int i{0}; i < n; ++i)
    {
        if (a[i] != key)
        {
            a[out] = a[i];
            ++out;
        }
    }
    std::cout << "size: " << out << '\n';
    for (int i{0}; i < out; ++i)
        std::cout << a[i] << (i < out - 1 ? " " : "\n");
    if (out == 0)
        std::cout << '\n';
}
} // namespace e072

namespace e073 { // Merge Two Sorted Arrays
void run()
{
    int n1{};
    std::cin >> n1;
    int a[20]{};
    for (int i{0}; i < n1; ++i)
        std::cin >> a[i];
    int n2{};
    std::cin >> n2;
    int b[20]{};
    for (int i{0}; i < n2; ++i)
        std::cin >> b[i];
    int i{0}, j{0};
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            std::cout << a[i++] << ' ';
        else
            std::cout << b[j++] << ' ';
    }
    while (i < n1)
        std::cout << a[i++] << ' ';
    while (j < n2)
        std::cout << b[j++] << ' ';
    std::cout << '\n';
}
} // namespace e073

namespace e074 { // Rotate Left by K
void run()
{
    int n{}, k{};
    std::cin >> n;
    int a[20]{};
    for (int i{0}; i < n; ++i)
        std::cin >> a[i];
    std::cin >> k;
    int b[20]{};
    for (int i{0}; i < n; ++i)
        b[i] = a[(i + k) % n];
    for (int i{0}; i < n; ++i)
        std::cout << b[i] << (i < n - 1 ? " " : "\n");
    // In-place alternative: reverse(0,k-1), reverse(k,n-1), reverse(0,n-1).
}
} // namespace e074

namespace e075 { // Histogram of Scores
void run()
{
    int n{};
    std::cin >> n;
    int bands[10]{};
    for (int i{0}; i < n; ++i)
    {
        int s{};
        std::cin >> s;
        while (s < 0 || s > 100)
        {
            std::cout << "re-prompt: out of range\n";
            std::cin >> s;
        }
        int band{s / 10};
        if (band == 10)
            band = 9; // 100 folds into 90-100
        ++bands[band];
    }
    for (int b{0}; b < 10; ++b)
    {
        int lo{b * 10};
        std::cout << lo << '-' << (b == 9 ? 100 : lo + 9) << ": ";
        for (int c{0}; c < bands[b]; ++c)
            std::cout << '#';
        std::cout << '\n';
    }
}
} // namespace e075

namespace e076 { // Matrix Addition and Scale
void run()
{
    const int ROWS{2};
    const int COLS{3};
    int a[ROWS][COLS]{};
    int b[ROWS][COLS]{};
    for (int r{0}; r < ROWS; ++r)
        for (int c{0}; c < COLS; ++c)
            std::cin >> a[r][c];
    for (int r{0}; r < ROWS; ++r)
        for (int c{0}; c < COLS; ++c)
            std::cin >> b[r][c];
    std::cout << "A+B:\n";
    for (int r{0}; r < ROWS; ++r)
    {
        for (int c{0}; c < COLS; ++c)
            std::cout << a[r][c] + b[r][c] << ' ';
        std::cout << '\n';
    }
    std::cout << "3xA:\n";
    for (int r{0}; r < ROWS; ++r)
    {
        for (int c{0}; c < COLS; ++c)
            std::cout << 3 * a[r][c] << ' ';
        std::cout << '\n';
    }
}
} // namespace e076

namespace e077 { // Row and Column Totals (2-D)
void run()
{
    const int ROWS{3};
    const int COLS{4};
    int g[ROWS][COLS]{};
    for (int r{0}; r < ROWS; ++r)
        for (int c{0}; c < COLS; ++c)
            std::cin >> g[r][c];
    long long grand{0};
    int bestRow{0};
    long long bestTotal{-1};
    std::cout << "rows:";
    for (int r{0}; r < ROWS; ++r)
    {
        long long total{0}; // fresh accumulator PER ROW
        for (int c{0}; c < COLS; ++c)
            total += g[r][c];
        std::cout << ' ' << total;
        grand += total;
        if (total > bestTotal)
        {
            bestTotal = total;
            bestRow = r;
        }
    }
    std::cout << '\n' << "cols:";
    for (int c{0}; c < COLS; ++c)
    {
        long long total{0};
        for (int r{0}; r < ROWS; ++r)
            total += g[r][c];
        std::cout << ' ' << total;
    }
    std::cout << '\n' << "grand: " << grand << '\n'
              << "largest row: " << bestRow << '\n';
}
} // namespace e077

namespace e078 { // Diagonal Difference (square matrix)
void run()
{
    int n{};
    std::cin >> n;
    int g[8][8]{};
    for (int r{0}; r < n; ++r)
        for (int c{0}; c < n; ++c)
            std::cin >> g[r][c];
    long long mainDiag{0};
    long long antiDiag{0};
    for (int i{0}; i < n; ++i)
    {
        mainDiag += g[i][i];
        antiDiag += g[i][n - 1 - i];
    }
    long long diff{mainDiag - antiDiag};
    if (diff < 0)
        diff = -diff;
    bool symmetric{true};
    for (int r{0}; r < n && symmetric; ++r)
        for (int c{r + 1}; c < n; ++c)
            if (g[r][c] != g[c][r])
            {
                symmetric = false;
                break;
            }
    std::cout << "diff: " << diff << '\n'
              << "symmetric: " << (symmetric ? "yes" : "no") << '\n';
}
} // namespace e078

int main()
{
    e066::run();
    e070::run();
    e072::run();
    e077::run();
    return 0;
}
