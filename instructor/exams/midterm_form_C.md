# Midterm Examination — Form C
**Programming Fundamentals Using C++ · Weeks 1–8 · 100 minutes · 50 marks**
**INSTRUCTOR-ONLY** — see [answer_keys.md](answer_keys.md); printing checklist strips Answer lines before exam day.
Name: ____________________ ID: ____________ Section: ______

Instructions: answer all questions. No books, notes, or devices. Marks per part shown.
*Form C differs from Forms A/B in ≥ 30 % of items; section marks identical.*

## Q1 · MCQ (6 × 1 = 6 marks)
1. `[M1]` Compiles but misbehaves — the error class is: A. syntax B. runtime or logic C. linker D. none
2. `[M2]` `cin >> a >> b;` with input `4 9` gives: A. a=4 b=9 B. a=49 b=0 C. a=4 b=4 D. error
3. `[M3]` `int x{5}; x += n++ * 2;` (n unknown) is: A. well-defined B. undefined (unsequenced) C. compile error D. always 15
4. `[M4]` Short-circuit in `(b != 0 && a/b > 2)` is: A. both sides always evaluated B. division skipped when b==0 C. div-by-zero returns 0 D. compiler reorders
5. `[M5]` Accumulators are initialized: A. inside each pass B. before the loop C. after D. never
6. `[M6]` Decomposition means: A. splitting into ordered sub-problems B. deleting code C. merging loops D. renaming

## Q2 · Output tracing (4 × 2 = 8 marks)
1. (M2) `int a{}, b{}; cin >> a >> b; cout << a/b << ' ' << a%b;` — input `7 2`.
2. (M7) `void tweak(int a, int& b){++a; ++b;} int p{4}, q{4}; tweak(p, q); cout << p << ' ' << q;`
3. (M8) `void shadow(){int x{99}; cout << x;} int x{1}; int main(){cout << x; shadow(); cout << x;}`
4. (M5) `int t{0}; for (int i{1}; i <= 4; ++i) t += i; cout << t;`

## Q3 · Debugging (3 × 2 = 6 marks)
1. (M4) Elevator verdict table has no row for requested == current; program prints garbage verdict.
2. (M6) Validator accepts age 300 — name the missing test category and one catching case.
3. (M5) Count-down prints one extra 0 because the boundary uses `>=` but the spec says stop before 0.

## Q4 · Short conceptual (3 × 2 = 6 marks)
1. (M1) One sentence: why reuse `std::cout` instead of writing your own output routine?
2. (M3) State what the standard guarantees about `%` (the identity), and what is *not* guaranteed (sign of negative operands on truncating compilers).
3. (M8) When is recursion preferable to iteration? Give the course's concrete pattern.

## Q5 · Algorithm design (2 × 3 = 6 marks)
1. (M6) Decision table + boundaries: parking fee (30 free / 20 ≤2h / 50 ≤5h / +10 per extra hour, cap 120).
2. (M6) Decompose "receipts block for n items, 17% tax" — signatures + contracts.

## Q6 · Coding (3 × 4 = 12 marks)
1. (M2) Temperature conversion C→F with input validation, 1 decimal.
2. (M4) Median of three integers.
3. (M7) `bool isPerfect(int n)` + all ≤ 10000.

## Q7 · Code completion (2 × 3 = 6 marks)
1. (M5) Priming-read while loop: `cin >> v; while (v __(a)__ -1) { cout << v; __(b)__; }`
2. (M7) `double avg(int a, int b)` completing to a floating mean: `return (a + b) / __(a)__;`

---
**END**
