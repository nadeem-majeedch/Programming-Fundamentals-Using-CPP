// instructor/exercise_solutions/T02_solutions.cpp — INSTRUCTOR-ONLY
// Solutions for PF-E-014 .. PF-E-026 (Conditions).
// Build: g++ -std=c++17 -Wall -Wextra -pedantic T02_solutions.cpp -o t02
#include <iostream>
#include <iomanip>
#include <string>

namespace e014 { // Pass/Fail
void run()
{
    int score{};
    std::cin >> score;
    if (score >= 60)
        std::cout << "PASS\n";
    else
        std::cout << "FAIL\n";
}
} // namespace e014

namespace e015 { // Adult or Minor
void run()
{
    int age{};
    std::cin >> age;
    if (age < 18)
        std::cout << "minor\n";
    else
        std::cout << "adult\n";
    std::cout << (age < 18 ? "minor\n" : "adult\n");
}
} // namespace e015

namespace e016 { // Positive/Negative/Zero
void run()
{
    int n{};
    std::cin >> n;
    if (n > 0)
        std::cout << "positive\n";
    else if (n < 0)
        std::cout << "negative\n";
    else
        std::cout << "zero\n";
}
} // namespace e016

namespace e017 { // Leap Year
void run()
{
    int year{};
    std::cin >> year;
    bool leap{false};
    if (year % 4 == 0)
    {
        if (year % 100 != 0 || year % 400 == 0)
            leap = true;
    }
    std::cout << (leap ? "leap\n" : "common\n");
}
} // namespace e017

namespace e018 { // Triangle Validity + Type
void run()
{
    double a{}, b{}, c{};
    std::cin >> a >> b >> c;
    bool valid{a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a};
    if (!valid)
    {
        std::cout << "invalid\n";
        return;
    }
    if (a == b && b == c)
        std::cout << "equilateral\n";
    else if (a == b || b == c || a == c)
        std::cout << "isosceles\n";
    else
        std::cout << "scalene\n";
}
} // namespace e018

namespace e019 { // GPA Band
void run()
{
    double gpa{};
    std::cin >> gpa;
    if (gpa < 0.0 || gpa > 4.0)
        std::cout << "out of range\n";
    else if (gpa >= 3.5)
        std::cout << "first\n";
    else if (gpa >= 3.0)
        std::cout << "two-one\n";
    else if (gpa >= 2.0)
        std::cout << "two-two\n";
    else if (gpa >= 1.0)
        std::cout << "pass\n";
    else
        std::cout << "fail\n";
}
} // namespace e019

namespace e020 { // Electricity Tariff
void run()
{
    int units{};
    std::cin >> units;
    const double FEE{150.0};
    double cost{FEE};
    if (units <= 100)
        cost += units * 1.20;
    else if (units <= 300)
        cost += 100 * 1.20 + (units - 100) * 1.80;
    else
        cost += 100 * 1.20 + 200 * 1.80 + (units - 300) * 2.50;
    std::cout << std::fixed << std::setprecision(2) << cost << '\n';
}
} // namespace e020

namespace e021 { // Short-Circuit Guard Drill
void run()
{
    int divisor{}, dividend{};
    std::cin >> divisor >> dividend;
    if (divisor != 0 && dividend / divisor >= 0) // guard protects the divide
        std::cout << "quotient ok\n";
    else if (divisor == 0)
        std::cout << "cannot divide\n";
    else
        std::cout << "quotient ok\n";
    // Without the guard, divisor==0 reaching the division crashes.
    std::cin >> divisor >> dividend;
    if (divisor != 0)
        std::cout << dividend / divisor << '\n';
    else
        std::cout << "cannot divide\n";
}
} // namespace e021

namespace e022 { // BMI Classifier
void run()
{
    double weight{}, height{};
    std::cin >> weight >> height;
    if (weight <= 0 || height <= 0)
    {
        std::cout << "invalid input\n";
        return;
    }
    double bmi{weight / (height * height)};
    std::cout << std::fixed << std::setprecision(1) << bmi << ' ';
    if (bmi < 18.5)
        std::cout << "under\n";
    else if (bmi < 25.0)
        std::cout << "normal\n";
    else if (bmi < 30.0)
        std::cout << "over\n";
    else
        std::cout << "obese\n";
}
} // namespace e022

namespace e023 { // Simple Calculator (switch)
void run()
{
    double x{}, y{};
    char op{};
    std::cin >> x >> op >> y;
    std::cout << std::fixed << std::setprecision(2);
    switch (op)
    {
    case '+':
        std::cout << x + y << '\n';
        break;
    case '-':
        std::cout << x - y << '\n';
        break;
    case '*':
        std::cout << x * y << '\n';
        break;
    case '/':
        if (y == 0.0)
            std::cout << "undefined\n";
        else
            std::cout << x / y << '\n';
        break;
    default:
        std::cout << "unknown op\n";
        break;
    }
}
} // namespace e023

namespace e024 { // Days in Month
void run()
{
    int month{}, year{};
    std::cin >> month >> year;
    bool leap{(year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)};
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        std::cout << 31 << '\n';
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        std::cout << 30 << '\n';
        break;
    case 2:
        std::cout << (leap ? 29 : 28) << '\n';
        break;
    default:
        std::cout << "invalid month\n";
        break;
    }
}
} // namespace e024

namespace e025 { // Rock-Paper-Scissors Arbitrator
void run()
{
    char a{}, b{};
    std::cin >> a >> b;
    if ((a != 'r' && a != 'p' && a != 's') || (b != 'r' && b != 'p' && b != 's'))
    {
        std::cout << "invalid move\n";
        return;
    }
    switch (a)
    {
    case 'r':
        if (b == 's')
            std::cout << "A wins\n";
        else if (b == 'p')
            std::cout << "B wins\n";
        else
            std::cout << "draw\n";
        break;
    case 'p':
        if (b == 'r')
            std::cout << "A wins\n";
        else if (b == 's')
            std::cout << "B wins\n";
        else
            std::cout << "draw\n";
        break;
    case 's':
        if (b == 'p')
            std::cout << "A wins\n";
        else if (b == 'r')
            std::cout << "B wins\n";
        else
            std::cout << "draw\n";
        break;
    default:
        break;
    }
}
} // namespace e025

namespace e026 { // Tax Bracket Advisor
double taxFor(double income)
{
    double tax{0.0};
    const double B1{600000.0};
    const double B2{400000.0};
    const double B3{500000.0};
    double rest{income};
    double slice{rest < B1 ? rest : B1};
    tax += slice * 0.00;
    rest -= slice;
    if (rest > 0)
    {
        slice = rest < B2 ? rest : B2;
        tax += slice * 0.05;
        rest -= slice;
    }
    if (rest > 0)
    {
        slice = rest < B3 ? rest : B3;
        tax += slice * 0.10;
        rest -= slice;
    }
    if (rest > 0)
        tax += rest * 0.15;
    return tax;
}

void run()
{
    double income{};
    if (!(std::cin >> income) || income < 0)
    {
        std::cout << "invalid income\n";
        return;
    }
    double tax{taxFor(income)};
    double effective{income > 0 ? tax / income * 100.0 : 0.0};
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "tax: " << tax << '\n' << "effective: " << effective << "%\n";
}
} // namespace e026

int main()
{
    e017::run(); // leap year: reads a year
    e024::run(); // days in month: reads month year
    e026::run(); // tax: reads income
    return 0;
}
