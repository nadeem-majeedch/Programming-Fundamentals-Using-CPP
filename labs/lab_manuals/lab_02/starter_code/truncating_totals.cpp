// Lab 02 · truncating_totals.cpp — bug-hunt file.
// Build it first; it compiles CLEANLY. The bug is LOGIC-stage.
//
// Expected (documented): 3 items at 12.50 each -> total 37.50
// Actual: total prints 37 (why? — integer arithmetic swallowed the .50)
//
// Fix: make the arithmetic match the money type. Then re-verify all rows.

#include <iostream>
#include <iomanip>

int main()
{
    int quantity{3};
    int unitCents{1250};          // price stored as integer cents

    int totalCents{quantity * unitCents};
    std::cout << std::fixed << std::setprecision(2)
              << "total: " << totalCents << '\n';   // shows 3750.00 — wrong unit!

    // The naive double version students will write first:
    int price{13};                // should model 12.50 — truncation here
    int total{quantity * price};  // 39 vs the true 37.50
    std::cout << "naive total: " << total << '\n';
    return 0;
}
