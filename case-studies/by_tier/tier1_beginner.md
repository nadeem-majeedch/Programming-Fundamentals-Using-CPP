# Tier 1 · Beginner — Projector Cases (CS-001–CS-020)

**Lectures L01–L12 · Modules 1–6** · think ~5 minutes · paper only.
Cases ascend in difficulty within the tier. Hints are progressive — reveal
one at a time, on request. Worked solutions: instructor area only.

---

### PF-CS-001 · The Vending Machine

- **Tier:** 1 Beginner · **Lecture:** L01 · Module 1
- **Context:** A drinks machine in the engineering building.
- **Problem:** A can costs 45. A customer inserts coins of values 5, 10, or 25 (one at a time, in that order they are fed). Design the numbered steps the machine follows to decide when to dispense the can and how much change to return; state what happens if the customer walks away before reaching 45.
- **Input:** coin values as they are inserted. **Output:** dispense/no-dispense decision and change amount.
- **Constraints:** total inserted is between 0 and 200; change is always payable in 5s.
- **Thinking questions:** What state must the machine remember between coins? When does the "algorithm" stop? Is the change always exact?

<details><summary>Hints (progressive)</summary>

1. You need one variable for the accumulated total.
2. The stopping condition compares that total against 45.
3. Change = total − 45; convince yourself any legal total makes it a multiple of 5.
</details>

---

### PF-CS-002 · Three-Cup Order

- **Tier:** 1 Beginner · **Lecture:** L03 · Module 2
- **Context:** Sorting three exam papers by score before entering them.
- **Problem:** Three paper slips carry integer scores. Design a pencil-and-paper method that ends with the smallest score on the left slip and the largest on the right, using as few comparisons as possible. State the minimum number of comparisons needed and why fewer is impossible.
- **Input:** three integers. **Output:** the three values in ascending order plus the comparison count.
- **Constraints:** values in 0…100; equal values allowed.
- **Thinking questions:** Which pair should you compare first? After two comparisons, what do you know for certain?

<details><summary>Hints (progressive)</summary>

1. Compare A and B; the smaller one can never be the overall maximum.
2. Then compare the winner's loser against C for the minimum.
3. Three comparisons always suffice; two cannot order three unknowns.
</details>

---

### PF-CS-003 · The Receipt Printer

- **Tier:** 1 Beginner · **Lecture:** L04 · Module 2
- **Context:** A kiosk prints a formatted purchase receipt.
- **Problem:** Given an item name, unit price, and quantity, design the exact screen layout for a receipt line and a total line (see I/O). Decide the data types for each field and justify each choice.
- **Input:** item name (one word), unit price (2 dp), quantity (integer). **Output:** aligned columns — name (width 12), price (width 8, 2 dp), quantity (width 4), line total.
- **Constraints:** quantity ≤ 999; price ≤ 9999.99.
- **Thinking questions:** Why is `double` right for price but wrong for quantity? What breaks if you store money in `int`?

<details><summary>Hints (progressive)</summary>

1. Three fields, three types: string, double, int.
2. The line total multiplies the two numeric fields.
3. Fixed-point formatting uses two digits after the decimal point.
</details>

---

### PF-CS-004 · Elevator Logic

- **Tier:** 1 Beginner · **Lecture:** L07 · Module 4
- **Context:** A two-floor building's elevator controller.
- **Problem:** The elevator reads the current floor (1 or 2) and the requested floor (1 or 2). Specify its decision rule and what it should do when both inputs are equal — the case students forget. Present the rule as a decision table before writing any if-statement.
- **Input:** two integers. **Output:** one verdict: `MOVE UP`, `MOVE DOWN`, or `STAY`.
- **Constraints:** inputs are always 1 or 2.
- **Thinking questions:** How many distinct input combinations exist? Which combinations share an outcome?

<details><summary>Hints (progressive)</summary>

1. 2×2 = 4 combinations, but two of them are the same outcome.
2. Equality of the inputs is one explicit branch.
3. Two moves plus one stay covers all four cells.
</details>

---

### PF-CS-005 · The Grading Curve Debate

- **Tier:** 1 Beginner · **Lecture:** L07 · Module 4
- **Context:** An instructor must convert raw scores to letter grades.
- **Problem:** Design the complete decision ladder for: ≥90 A, ≥80 B, ≥70 C, ≥60 D, else F. Then a colleague suggests testing `>= 90` *last*. Explain, with a concrete score, what goes wrong.
- **Input:** one integer score. **Output:** one letter.
- **Constraints:** scores 0…100; no invalid input.
- **Thinking questions:** Why does ladder order matter when every test is `>=`? Which single score demonstrates the failure?

<details><summary>Hints (progressive)</summary>

1. An if/else-if ladder stops at the first true branch.
2. With `>=` tests, the *largest* threshold must be tested first.
3. Try score = 95 against the reversed ladder.
</details>

---

### PF-CS-006 · Parking Fee

- **Tier:** 1 Beginner · **Lecture:** L07 · Module 4
- **Context:** A city parking garage's pay station.
- **Problem:** The fee is: first hour 50, each additional hour (or part thereof) 30, daily maximum 200. Given arrival and departure hours (integers, same day), compute the fee. Identify which inputs make "part thereof" matter.
- **Input:** two integers (arrival hour, departure hour, departure > arrival). **Output:** one fee amount.
- **Constraints:** 0 ≤ arrival < departure ≤ 24.
- **Thinking questions:** What single arithmetic expression gives billed hours with the "or part thereof" rule? Where does the maximum kick in?

<details><summary>Hints (progressive)</summary>

1. Hours from 1 to 60 minutes both bill as one hour — think of a ceiling.
2. Billed = hours − 1 for hours beyond the first.
3. Compare naive fee against 200 for a full-day stay.
</details>

---

### PF-CS-007 · Password Strength Meter

- **Tier:** 1 Beginner · **Lecture:** L08 · Module 4
- **Context:** A signup form grades password strength.
- **Problem:** A password scores one point for each of: length ≥ 8, contains a digit, contains an uppercase letter, contains a symbol (anything not a letter or digit). Given a one-word password, design the scoring logic and the labels 0–1 `WEAK`, 2 `FAIR`, 3 `GOOD`, 4 `STRONG`.
- **Input:** one word (no spaces, ≤ 30 chars). **Output:** the label.
- **Constraints:** printable characters only; no spaces.
- **Thinking questions:** Which loop shape fits "look through the word until you find a digit"? Can you stop scanning early?

<details><summary>Hints (progressive)</summary>

1. Length is one test; the other three need a scan over characters.
2. `<cctype>` provides classification functions per character.
3. Boolean flags can stop a loop early once a category is found.
</details>

---

### PF-CS-008 · The Countdown Timer

- **Tier:** 1 Beginner · **Lecture:** L09 · Module 5
- **Context:** A microwave's display counts down seconds.
- **Problem:** Given seconds (≤ 600), specify exactly what the display shows at each step from the start until it reaches zero, in mm:ss format. Decide which loop form fits and why.
- **Input:** one integer. **Output:** each remaining value as mm:ss, one per line, ending at 00:00.
- **Constraints:** 1 ≤ seconds ≤ 600.
- **Thinking questions:** What changes between iterations? Why is a for-loop natural here but a while-loop defensible?

<details><summary>Hints (progressive)</summary>

1. mm:ss is just seconds/60 and seconds%60 with two-digit padding.
2. The loop variable is the remaining seconds itself.
3. A for-loop with a decrementing counter, ending at 0 inclusive.
</details>

---

### PF-CS-009 · Coin Split for Pocket Money

- **Tier:** 1 Beginner · **Lecture:** L06 · Module 3
- **Context:** A parent converts a rupee amount into coins.
- **Problem:** Given an amount in rupees (integer), specify how many 25-, 10-, and 5- coins to hand out using a greedy strategy, and justify that greedy is safe for this coin set.
- **Input:** one integer amount (multiple of 5). **Output:** counts of each coin.
- **Constraints:** 0 ≤ amount ≤ 999; amount % 5 == 0.
- **Thinking questions:** Why does taking the largest coin first never block a solution here? Would it stay safe with a 7-coin?

<details><summary>Hints (progressive)</summary>

1. Integer division and remainder do all the work.
2. After 25s, the remainder is < 25 — then apply 10s, then 5s.
3. Each coin divides the next smaller one's structure: the set is "friendly".
</details>

---

### PF-CS-010 · The Secret Number Hunt

- **Tier:** 1 Beginner · **Lecture:** L09 · Module 5
- **Context:** A guessing game between two students.
- **Problem:** One student fixes a secret (1–100); the other guesses repeatedly, receiving `HIGH` or `LOW` each time. Design the loop: when does it stop, what is read each pass, and how would you *guarantee* at most 7 guesses?
- **Input:** guesses until correct. **Output:** HIGH/LOW feedback per guess; a stop condition.
- **Constraints:** secret in 1…100.
- **Thinking questions:** What state shrinks every round? Why is 2⁷ > 100 the key number?

<details><summary>Hints (progressive)</summary>

1. Track the range [lo, hi] of possible secrets.
2. Halve the range every guess by choosing its middle.
3. log₂(100) ≈ 6.64, so 7 halvings always suffice.
</details>

---

### PF-CS-011 · Traffic Light Cycle

- **Tier:** 1 Beginner · **Lecture:** L09 · Module 5
- **Context:** A pedestrian signal cycles on a timer.
- **Problem:** The light cycles GREEN 30s → YELLOW 5s → RED 20s, forever. Given a second-count t, determine the light color. Then generalize: what changes if the cycle length differs per direction?
- **Input:** one integer t ≥ 0. **Output:** color name.
- **Constraints:** t ≤ 10⁶ (think beyond a loop!).
- **Thinking questions:** What does t mod 55 tell you? Can you answer without simulating second-by-second?

<details><summary>Hints (progressive)</summary>

1. The cycle repeats every 55 seconds.
2. The remainder locates you inside one cycle.
3. Map remainder ranges: 0–29, 30–34, 35–54.
</details>

---

### PF-CS-012 · Rainfall Logger

- **Tier:** 1 Beginner · **Lecture:** L10 · Module 5
- **Context:** A weather station records daily rainfall.
- **Problem:** Design the accumulation loop for n daily readings (mm): running total, running maximum with its day number, and count of dry days (0.0). What must reset — and what must *not* reset — each iteration?
- **Input:** n, then n doubles. **Output:** total, max with day, dry count.
- **Constraints:** 1 ≤ n ≤ 366; readings ≥ 0.
- **Thinking questions:** Which variables live *outside* the loop? When is the max updated?

<details><summary>Hints (progressive)</summary>

1. Total, max, dry, and day counter all persist across iterations.
2. Initialize max from the *first* reading, not from 0... or can 0 be right?
3. Update max when reading > max *or* reading == max on a later day — decide the tie rule first.
</details>

---

### PF-CS-013 · The Cashier's Change Maker

- **Tier:** 1 Beginner · **Lecture:** L10 · Module 5
- **Context:** A shopkeeper returns change with the fewest coins.
- **Problem:** Prices are whole rupees; the customer pays with 1000. Design the loop that computes change and its coin breakdown (500, 100, 50, 20, 10, 5, 1), proving the count is minimal for any price.
- **Input:** one integer price. **Output:** change amount + per-coin counts.
- **Constraints:** 0 ≤ price ≤ 1000.
- **Thinking questions:** Which loop handles *all* coin denominations at once? What is the invariant after each coin pass?

<details><summary>Hints (progressive)</summary>

1. A parallel array of denominations lets one loop serve all coins.
2. After handling coin c, the remaining amount is < c.
3. Greedy is minimal here because each denomination is a multiple-sum of smaller ones.
</details>

---

### PF-CS-014 · Class Attendance Percentages

- **Tier:** 1 Beginner · **Lecture:** L10 · Module 5
- **Context:** A tutor tracks who attends weekly sessions.
- **Problem:** Given n students each with an attendance count out of 16 weeks, design the loop computing each student's percentage and the class average. Decide the type of every accumulator and justify the cast you need for the average.
- **Input:** n, then n integers. **Output:** per-student percentage (1 dp) and class average (1 dp).
- **Constraints:** 1 ≤ n ≤ 60; counts in 0…16.
- **Thinking questions:** Where does integer division silently ruin the answer? Which variable holds the running sum of *percentages*?

<details><summary>Hints (progressive)</summary>

1. Percentage = count/16 × 100 — both operands' types decide the result.
2. static_cast to double *before* dividing.
3. Two accumulators: one per-student inside the loop, one class-level outside.
</details>

---

### PF-CS-015 · The Left-to-Right Largest

- **Tier:** 1 Beginner · **Lecture:** L10 · Module 5
- **Context:** A parade marshals pick the tallest scout so far as they walk the line.
- **Problem:** Scouts stand in a line with visible heights. Walking left to right, a scout is "record-breaking" if taller than every scout before them. Design the counting loop and trace it on 5 heights before coding.
- **Input:** n, then n integers. **Output:** count of record-breakers (the first scout always counts).
- **Constraints:** 1 ≤ n ≤ 40; heights 100…200.
- **Thinking questions:** What single variable summarizes "all scouts so far"? Does the *order* of comparisons matter?

<details><summary>Hints (progressive)</summary>

1. Keep the running maximum; compare each new height to it.
2. A tie is *not* a new record — decide strictly greater.
3. One pass, O(n): no second loop needed.
</details>

---

### PF-CS-016 · Sum Until the Sentinel

- **Tier:** 1 Beginner · **Lecture:** L09 · Module 5
- **Context:** A toll booth totals vehicle fares until the operator types the end-of-shift code.
- **Problem:** Design the sentinel-controlled loop: read fares (positive), stop at the agreed sentinel, then report count and total. Explain why the sentinel cannot be a legal fare and where you would read the first value.
- **Input:** integers until sentinel. **Output:** count + total.
- **Constraints:** fares 1…500; sentinel −1.
- **Thinking questions:** Why does read-then-check-then-process avoid processing the sentinel?

<details><summary>Hints (progressive)</summary>

1. The loop condition tests the *most recently read* value.
2. Priming read: read once before the loop starts.
3. Update the variables *inside* the loop body, after the check.
</details>

---

### PF-CS-017 · The Pyramid Builder

- **Tier:** 1 Beginner · **Lecture:** L10 · Module 5
- **Context:** A cinema seats viewers in a triangular arrangement for a photo.
- **Problem:** For height h, specify the exact printed triangle: row i has i stars, centered by leading spaces. Give the loop bounds and the space count formula *before* writing code.
- **Input:** one integer h. **Output:** the centered triangle.
- **Constraints:** 1 ≤ h ≤ 15.
- **Thinking questions:** How many spaces does row i need? What does the outer loop control vs the two inner loops?

<details><summary>Hints (progressive)</summary>

1. Row i (1-based) prints h − i spaces then i stars.
2. Outer loop rows; two inner loops: spaces, then stars.
3. Verify the formula on h = 1 and h = 3 by hand first.
</details>

---

### PF-CS-018 · Bus Fare Zoner

- **Tier:** 1 Beginner · **Lecture:** L12 · Module 6
- **Context:** A transit system charges by zone distance.
- **Problem:** Given traveled distance (integer km), fare is 20 for the first 5 km, then 5 per additional km. Design the computation, then restate it as a single formula valid for all distances — no branching left.
- **Input:** one integer km ≥ 1. **Output:** one fare.
- **Constraints:** km ≤ 100.
- **Thinking questions:** Can max(0, km−5) replace the branch? Which form is easier to test exhaustively?

<details><summary>Hints (progressive)</summary>

1. The branch only decides *how much of* the per-km rate applies.
2. Excess = (km > 5) ? km − 5 : 0 — the conditional operator.
3. Fare = 20 + 5 × max(0, km − 5).
</details>

---

### PF-CS-019 · The Recipe Scaler

- **Tier:** 1 Beginner · **Lecture:** L12 · Module 6
- **Context:** A hostel kitchen scales a recipe for k students.
- **Problem:** A recipe serves 4 with given gram amounts per ingredient. Design the scaling computation that keeps proportions exact for k servings, and decide the output's rounding rule so the kitchen can actually weigh it (nearest 5 g).
- **Input:** k (integer), then the 4 gram amounts (integers, serves 4). **Output:** 4 scaled amounts rounded to nearest 5 g.
- **Constraints:** 1 ≤ k ≤ 40; amounts ≤ 2000.
- **Thinking questions:** Where do fractions appear, and where must they *survive*? Why is rounding *after* all arithmetic essential?

<details><summary>Hints (progressive)</summary>

1. Scale factor = k/4.0 — one cast keeps the math exact.
2. Compute in double, round only at print time.
3. nearest 5 = 5 × floor(x/5 + 0.5).
</details>

---

### PF-CS-020 · Exam Averages with an Absence Rule

- **Tier:** 1 Beginner · **Lecture:** L12 · Module 6
- **Context:** A teacher averages test scores but must handle absences.
- **Problem:** Each student has 3 scores; −1 marks an absent test. Design the average computation that ignores absent tests but flags a student with all three absent. Decide: is a 2-test average *comparable* to a 3-test average? State your policy and defend it.
- **Input:** n, then per student: 3 integers. **Output:** per-student average (−1 if all absent) with the policy note.
- **Constraints:** 1 ≤ n ≤ 50; scores 0…100 or −1.
- **Thinking questions:** Which accumulator counts *present* tests? What is the average when the count is zero — and does 0 lie?

<details><summary>Hints (progressive)</summary>

1. Sum only scores ≥ 0; count them too.
2. Guard division: count == 0 means a flag, not a number.
3. Comparability is a *policy* decision: state it, don't hide it.
</details>
