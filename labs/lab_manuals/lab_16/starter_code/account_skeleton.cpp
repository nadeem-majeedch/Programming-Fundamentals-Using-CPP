// Lab 16 · account_skeleton.cpp — OOP mini-project starting point.
//
// Guided task: this minimal class already enforces one invariant
// (balance >= 0 after every method). Independent work extends it into the
// mini-project class pair.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic account_skeleton.cpp -o acc

#include <iostream>

class Account
{
public:
    Account()
        : cents_{0}
    {
    }

    // Contract: amount > 0; returns success; state untouched on failure.
    bool deposit(long long amount)
    {
        if (amount <= 0)
            return false;
        cents_ += amount;
        return true;
    }

    // Contract: 0 < amount <= balance; preserves cents_ >= 0.
    bool withdraw(long long amount)
    {
        if (amount <= 0 || amount > cents_)
            return false;
        cents_ -= amount;
        return true;
    }

    long long balance() const          // const: promises no mutation
    {
        return cents_;
    }

private:
    long long cents_;                  // invariant: cents_ >= 0
};

int main()
{
    Account a;
    std::cout << a.deposit(500) << ' ' << a.balance() << '\n';
    std::cout << a.withdraw(900) << ' ' << a.balance() << '\n';
    std::cout << a.withdraw(200) << ' ' << a.balance() << '\n';
    return 0;
}

// TODO (independent task): design Inventory + Item with the same discipline
// — private state, guarded methods, const readers, an invariant written in
// one comment line, and test evidence for every rejection path.
