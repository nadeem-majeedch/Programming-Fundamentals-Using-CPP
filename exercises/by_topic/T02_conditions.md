# T02 · Conditions

Covers: boolean expressions, `if/else`, `else if` chains, logical
operators, short-circuit guards, `switch`, nested decisions, the
conditional operator. Lectures L07–L08. Outcomes PF-4.1–PF-4.4.

13 exercises · ladder 🟢 → 🔴.

---

### PF-E-014 · Pass/Fail
**Difficulty:** Beginner · **Lecture:** L07 · **Outcomes:** PF-4.1
**Prerequisites:** E-003
**Problem:** Read a score (integer). Print `PASS` if it is 60 or more, otherwise `FAIL`.
**Input:** one integer · **Output:** one word.
**Sample:** `72` → `PASS`
**Hints:** `>=` — 60 itself passes.

### PF-E-015 · Adult or Minor
**Difficulty:** Beginner · **Lecture:** L07 · **Outcomes:** PF-4.1
**Prerequisites:** E-014
**Problem:** Read an age. Print `minor` (under 18) or `adult`. Then print the same decision made with the conditional operator instead of `if/else`.
**Input:** one integer · **Output:** one word, printed twice.
**Sample:** `15` → `minor` / `minor`
**Hints:** the `?:` version assigns the word to a variable, then prints once.

### PF-E-016 · Positive/Negative/Zero
**Difficulty:** Beginner · **Lecture:** L07 · **Outcomes:** PF-4.1
**Prerequisites:** E-015
**Problem:** Read an integer; classify it as `positive`, `negative`, or `zero` using an `if/else if/else` chain.
**Input:** one integer · **Output:** one word.
**Sample:** `-9` → `negative`
**Hints:** test zero *first* or *last* — just be consistent.

### PF-E-017 · Leap Year
**Difficulty:** Foundational · **Lecture:** L07 · **Outcomes:** PF-4.2
**Prerequisites:** E-016
**Problem:** Read a year; print `leap` or `common`. Rule: divisible by 4, except centuries not divisible by 400.
**Input:** one integer (year) · **Output:** one word.
**Sample:** `1900` → `common` / `2000` → `leap` / `2024` → `leap`
**Hints:** nest the century test inside the divisible-by-4 test; test 1900, 2000, 2024, 2023.

### PF-E-018 · Triangle Validity + Type
**Difficulty:** Foundational · **Lecture:** L07 · **Outcomes:** PF-4.2
**Prerequisites:** E-017
**Problem:** Read three side lengths. First check validity (each side positive; sum of any two greater than the third). If invalid print `invalid`; otherwise print `equilateral`, `isosceles`, or `scalene`.
**Input:** three doubles · **Output:** one word.
**Sample:** `3 3 3` → `equilateral` / `1 2 9` → `invalid`
**Hints:** validity first, as a guard; the three type tests are mutually exclusive.

### PF-E-019 · Grade Point Average Band
**Difficulty:** Foundational · **Lecture:** L07 · **Outcomes:** PF-4.2
**Prerequisites:** E-016
**Problem:** Read a GPA (0.0–4.0). Print the band: `first` (≥ 3.5), `two-one` (≥ 3.0), `two-two` (≥ 2.0), `pass` (≥ 1.0), else `fail`. Reject values outside 0.0–4.0 with `out of range`.
**Input:** one double · **Output:** one word.
**Sample:** `2.9` → `two-two` / `4.5` → `out of range`
**Hints:** descending chain — order matters (L07's ordered rule set).

### PF-E-020 · Electricity Tariff
**Difficulty:** Intermediate · **Lecture:** L07 · **Outcomes:** PF-4.2, PF-2.1
**Prerequisites:** E-019
**Problem:** Read electricity units consumed. First 100 units cost 1.20 each, next 200 cost 1.80 each, all beyond cost 2.50 each; plus a fixed 150 meter fee (charged even at 0 units). Print the total bill with 2 decimals.
**Input:** one integer (units ≥ 0) · **Output:** one money value.
**Sample:** `350` → `610.00`
**Hints:** split into bands with `if/else if` on *cumulative* totals, or subtract tier by tier.

### PF-E-021 · Short-Circuit Guard Drill
**Difficulty:** Intermediate · **Lecture:** L07 · **Outcomes:** PF-4.2
**Prerequisites:** E-020
**Problem:** Read a divisor and a dividend. Using **one** `if` with a short-circuit guard, print the quotient when the divisor is non-zero, otherwise print `cannot divide`. Then read a second pair and do the same without the guard — observe the crash (run it; note what happens in a comment).
**Input:** two pairs of integers · **Output:** quotient or message.
**Sample:** `0 5` → `cannot divide` / `2 9` → `4`
**Hints:** `(divisor != 0) && (...)`; the unguarded version is *expected* to misbehave — that's the lesson.

### PF-E-022 · BMI Classifier
**Difficulty:** Intermediate · **Lecture:** L07 · **Outcomes:** PF-4.2, PF-3.2
**Prerequisites:** E-019
**Problem:** Read weight (kg) and height (m). Compute BMI = weight / height². Print the BMI (1 decimal) and the class: `< 18.5` under, `< 25` normal, `< 30` over, else obese. Reject non-positive height/weight.
**Input:** two doubles · **Output:** BMI and class word.
**Sample:** `68 1.7` → `23.5 normal`
**Hints:** validate inputs first; the chain thresholds are the *lower bounds* of each class.

### PF-E-023 · Simple Calculator (switch)
**Difficulty:** Intermediate · **Lecture:** L08 · **Outcomes:** PF-4.3
**Prerequisites:** E-021
**Problem:** Read two doubles and an operator character (`+ - * /`). Use a `switch` to print the result (2 decimals); division by zero prints `undefined`; any other operator prints `unknown op`.
**Input:** double, char, double · **Output:** one value or message.
**Sample:** `7 / 2` → `3.50`
**Hints:** five cases + `default`; the zero-divisor test lives *inside* case `'/'`.

### PF-E-024 · Days in Month (switch with fall-through groups)
**Difficulty:** Intermediate · **Lecture:** L08 · **Outcomes:** PF-4.3
**Prerequisites:** E-023
**Problem:** Read a month number (1–12) and a year. Print the number of days, using grouped `case` labels (31-day and 30-day groups) and a leap-year test for February. Reject months outside 1–12.
**Input:** int, int · **Output:** one integer or `invalid month`.
**Sample:** `2 2024` → `29` / `2 1900` → `28`
**Hints:** reuse E-017's leap logic; grouped labels are the *legitimate* fall-through.

### PF-E-025 · Rock-Paper-Scissors Arbitrator
**Difficulty:** Intermediate · **Lecture:** L08 · **Outcomes:** PF-4.3, PF-4.4
**Prerequisites:** E-024
**Problem:** Read two moves as characters (`r`, `p`, `s`) for players A and B. Print `A wins`, `B wins`, or `draw`. Validate moves first (`invalid move`). Implement the decision with a `switch` on player A **nested inside** validation — no chained `if` allowed.
**Input:** two chars · **Output:** one phrase.
**Sample:** `r s` → `A wins` / `p p` → `draw`
**Hints:** only 3 non-draw pairs exist for A; enumerate them per case.

### PF-E-026 · Tax Bracket Advisor (nested + guard clauses)
**Difficulty:** Advanced Introductory · **Lecture:** L08 · **Outcomes:** PF-4.2, PF-4.4
**Prerequisites:** E-022, E-026-level design
**Problem:** Read annual taxable income (double, ≥ 0). Compute tax: 0% on the first 600,000; 5% of the next 400,000; 10% of the next 500,000; 15% beyond 1,500,000. Print tax owed and effective rate (2 decimals). Use guard clauses for invalid input (negative, non-numeric) and no nested ifs deeper than one level.
**Input:** one double · **Output:** two money/percent values.
**Sample:** `1200000` → `tax: 50000.00` / `effective: 4.17%`
**Hints:** compute per-band slices with early returns; the effective rate is tax/income × 100.
