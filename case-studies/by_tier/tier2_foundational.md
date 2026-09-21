# Tier 2 · Foundational — Projector Cases (CS-021–CS-040)

**Lectures L13–L16 · Modules 7–8** · think ~5 minutes · paper only.
Cases ascend in difficulty within the tier. Worked solutions: instructor
area only.

---

### PF-CS-021 · Leap Year Interrogation

- **Tier:** 2 Foundational · **Lecture:** L13 · Module 7
- **Context:** A calendar library needs a leap-year routine other teams will call.
- **Problem:** Write the decision rule for leap years (divisible by 4, except centuries unless divisible by 400) as a *single* boolean expression, then wrap it as a function with a one-line contract comment. Which form — nested ifs or one expression — is easier to test exhaustively?
- **Input:** a set of test years. **Output:** true/false per year.
- **Constraints:** years 1…9999.
- **Thinking questions:** What is the minimal test set that exercises every branch? Where do boolean operators replace nesting?

<details><summary>Hints (progressive)</summary>

1. The two "except" clauses combine with && and ||.
2. (y%4==0 && y%100!=0) || y%400==0 — verify on 1900, 2000, 2024.
3. A pure function (bool → bool) is testable without I/O.
</details>

---

### PF-CS-022 · The Safe Division Service

- **Tier:** 2 Foundational · **Lecture:** L13 · Module 7
- **Context:** A calculator app exposes divide() to other modules.
- **Problem:** Design divide(a, b) so the caller can always tell whether the division succeeded. Choose the interface: return code + out-parameter, or a sentinel? Defend your choice for beginners, and specify behavior for b == 0.
- **Input:** pairs of integers. **Output:** quotient or an explicit failure signal.
- **Constraints:** b may be 0; a in −10⁶…10⁶.
- **Thinking questions:** What is wrong with returning −99999 for "error"? Who owns the decision when division fails?

<details><summary>Hints (progressive)</summary>

1. A sentinel can collide with a legal quotient.
2. Two channels: one return for the value, one reference/bool for validity.
3. The caller decides policy; the function reports facts.
</details>

---

### PF-CS-023 · Unit Converter with Contracts

- **Tier:** 2 Foundational · **Lecture:** L13 · Module 7
- **Context:** A physics toolkit converts temperatures.
- **Problem:** Design celsiusToFahrenheit(double) and its inverse. State each function's precondition and postcondition as comments, and decide what the inverse should return for inputs below absolute zero (−273.15 °C).
- **Input:** temperatures. **Output:** converted values or a documented rejection.
- **Constraints:** valid range −273.15…1000 °C.
- **Thinking questions:** Should the rejection be a value or a boolean channel? What does the comment contract promise callers?

<details><summary>Hints (progressive)</summary>

1. F = C×9/5 + 32; the inverse undoes each operation in reverse order.
2. Below absolute zero the *input* is invalid — decide: error channel vs clamped value.
3. Precondition: C ≥ −273.15; postcondition: |result − expected| < 1e-9.
</details>

---

### PF-CS-024 · The Collatz Witness

- **Tier:** 2 Foundational · **Lecture:** L14 · Module 7
- **Context:** A math club explores the 3n+1 conjecture.
- **Problem:** Design collatzSteps(n) returning the number of steps to reach 1. Then use it in a loop to find which n in 1…100 takes the most steps. Why must the helper function exist at all — what goes wrong if the logic is inlined in the search loop?
- **Input:** none (fixed scan 1…100). **Output:** the n with maximum steps and that step count.
- **Constraints:** n ≤ 100 (fits easily in int; intermediate values stay small here).
- **Thinking questions:** Which loop tracks the maximum? What does "one responsibility per function" buy here?

<details><summary>Hints (progressive)</summary>

1. collatzSteps does one job: count steps for a single n.
2. The scan loop is a different job: track (best n, best count).
3. Inline the logic and the scan's max-tracking disappears inside step arithmetic — harder to test, harder to read.
</details>

---

### PF-CS-025 · Invoice Splitter

- **Tier:** 2 Foundational · **Lecture:** L14 · Module 7
- **Context:** Roommates split a restaurant bill fairly.
- **Problem:** Design splitBill(total, people) returning each share, and decide — *before coding* — the types: should money be double or integer (paisa/cents)? Specify behavior for people ≤ 0 and for totals that do not divide evenly (who rounds, and by how much?).
- **Input:** total (2 dp) and people. **Output:** per-person share with an explicit remainder policy.
- **Constraints:** 1 ≤ people ≤ 20; total ≤ 100000.
- **Thinking questions:** Why do professionals store money in integer cents? What is the *contract* when the division is uneven?

<details><summary>Hints (progressive)</summary>

1. Compute in cents: total×100 as long long.
2. Share = cents/people; leftover cents must go somewhere — state the rule.
3. people ≤ 0 is a caller error: document it, and decide the function's response.
</details>

---

### PF-CS-026 · The Recursive-Looking Password

- **Tier:** 2 Foundational · **Lecture:** L14 · Module 7
- **Context:** An IT policy requires repeated-character detection in passwords.
- **Problem:** Design hasDoubleChar(s) — true if two *adjacent* equal characters exist (e.g., "book" yes, "bok" no). Specify the loop bounds that avoid reading past the end, and justify why the last character needs special handling.
- **Input:** one word. **Output:** true/false.
- **Constraints:** length ≤ 40; no spaces.
- **Thinking questions:** What is the neighbor of s[i]? For which i is that neighbor valid?

<details><summary>Hints (progressive)</summary>

1. Compare s[i] with s[i+1].
2. i must stop at size()−2 — the classic off-by-one.
3. An empty or 1-char string has no adjacent pair: false.
</details>

---

### PF-CS-027 · Overload Tournament

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A geometry module wants one name, area(), for several shapes.
- **Problem:** Design the overload set area(square), area(rectangle), area(circle), area(triangle-base-height). For each, specify parameters, types, and what makes the call unambiguous. Which overload is *dangerous* for ambiguity, and why?
- **Input:** a mix of shape calls. **Output:** each area.
- **Constraints:** dimensions > 0; use π = 3.14159265358979.
- **Thinking questions:** How does the compiler pick? Could two overloads accept the same call?

<details><summary>Hints (progressive)</summary>

1. Overloads differ in parameter count or types.
2. area(int) vs area(double) can collide at call sites with int literals — discuss.
3. Count of parameters (2 for rect, 1 for circle) is the safest discriminator.
</details>

---

### PF-CS-028 · The Swap Handoff

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A sorting routine will need in-place exchanges.
- **Problem:** Three versions of mySwap are proposed: by value, by pointer, by reference. Predict the observable effect of each on the caller's variables, then select the version the sorting routine should adopt and justify why the other two fail or merely work.
- **Input:** two variables in a driver. **Output:** before/after values.
- **Constraints:** integer values.
- **Thinking questions:** What actually travels in each mechanism? Which version makes caller intent visible at the call site?

<details><summary>Hints (progressive)</summary>

1. By value copies: the caller's originals never move.
2. Pointer and reference both reach the caller's storage.
3. References make the call read like the value version but behave like the pointer version — that is exactly their power and their danger.
</details>

---

### PF-CS-029 · Statistics on Demand

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A lab instrument reports min, max, and mean of a sensor burst.
- **Problem:** Design ONE function computeStats(a, n, minOut, maxOut, meanOut) using reference out-parameters, and a second design returning a small struct-like trio via three functions. Compare the two interfaces: call sites, failure modes, readability. Which fits a beginner codebase and why?
- **Input:** n, then n doubles. **Output:** min, max, mean.
- **Constraints:** 1 ≤ n ≤ 1000; values ≥ 0.
- **Thinking questions:** What happens to out-parameters when n == 0? Who initializes them?

<details><summary>Hints (progressive)</summary>

1. Out-parameters must be initialized by the caller or in the function's guard.
2. n == 0 must be rejected *before* reading a[0].
3. One function keeps the three numbers consistent; three functions risk a stale mix.
</details>

---

### PF-CS-030 · Default Grading Modes

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A grading script runs in strict or lenient mode.
- **Problem:** Design curve(score, mode) where mode has a default (lenient). Lenient rounds up from x.5; strict truncates. Specify the two behaviors with example scores, then decide: should the default be the *dangerous* mode or the safe one? Defend with a concrete transcript.
- **Input:** scores with and without explicit mode. **Output:** adjusted scores.
- **Constraints:** scores 0…100; mode 'S' or 'L'.
- **Thinking questions:** What does a default argument promise every existing call site? Who is harmed if the default changes later?

<details><summary>Hints (progressive)</summary>

1. Default arguments live in the declaration, not per-call.
2. 89.5 → 90 lenient, 89 strict: the transcript that argues the policy.
3. Defaults should be the mode that cannot inflate grades silently.
</details>

---

### PF-CS-031 · The Recursive Countdown

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** A launch console prints a countdown.
- **Problem:** Write countDown(n) two ways — loop and recursion. For the recursive version, identify the base case, the recursive case, and what guarantees termination. Which version risks stack overflow, and for roughly what n?
- **Input:** one n. **Output:** identical lines from both versions.
- **Constraints:** 0 ≤ n ≤ 10000.
- **Thinking questions:** What is the smallest input the base case must cover? What shrinks in every recursive call?

<details><summary>Hints (progressive)</summary>

1. Base case n == 0 prints and returns.
2. Each call passes n−1: strictly shrinking.
3. Recursion depth equals n — thousands deep is where the stack complains (implementation-defined limit).
</details>

---

### PF-CS-032 · Recursive Sum of Digits

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** A checksum algorithm needs digit sums.
- **Problem:** Design digitSum(n) recursively (digitSum(907) = 16). State the base case for single digits and the recurrence. Then prove (informally) why the recursion terminates for every non-negative int — what strictly decreases?
- **Input:** one integer ≥ 0. **Output:** digit sum.
- **Constraints:** 0 ≤ n ≤ 2×10⁹ (consider long long).
- **Thinking questions:** Which expression peels one digit? Why is n/10 the shrinking part?

<details><summary>Hints (progressive)</summary>

1. digitSum(n) = n%10 + digitSum(n/10).
2. Base: n < 10 → n.
3. n/10 < n for all n ≥ 10, so the chain must hit a single digit.
</details>

---

### PF-CS-033 · Tower of Hanoi — Move Counter

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** A puzzle demonstration for open house.
- **Problem:** State the minimum number of moves for the Tower of Hanoi with n disks, derive it as a recurrence hanoi(n) = 2·hanoi(n−1) + 1, and design the recursive function that *prints* each move for n = 3. Verify by counting your own printed lines.
- **Input:** n disks. **Output:** move list + total count.
- **Constraints:** 1 ≤ n ≤ 10.
- **Thinking questions:** Which disk moves last in the recursion? Why does the count double (plus one) each time?

<details><summary>Hints (progressive)</summary>

1. Move n−1 aside, move the big disk, move n−1 back: two subproblems.
2. hanoi(1) = 1; each level doubles the work.
3. 2ⁿ − 1; for n = 3 that is 7 moves — count them.
</details>

---

### PF-CS-034 · Function Table Refactor

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** A weather report repeats the same 12 lines three times with tiny differences.
- **Problem:** Given the pseudo-code of a 60-line main() with three near-identical blocks, design the function decomposition: what becomes a parameter, what stays local, what the function returns. Give the new main() in outline.
- **Input:** pseudo-code on the projector. **Output:** decomposition sketch.
- **Constraints:** differences are only in the city name and the multiplier.
- **Thinking questions:** What is the *only* thing that varies? Should the function print or return — and what decides it?

<details><summary>Hints (progressive)</summary>

1. Parameters carry the variation: name and multiplier.
2. Printing functions are easy to call but hard to test; returning values is the reverse.
3. For this course: compute-and-return, print at the call site.
</details>

---

### PF-CS-035 · The Pass-by-Value Budget

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A tutor explains why one prototype compiles but does nothing.
- **Problem:** A student writes void addTax(double price) { price *= 1.17; } and calls it on a variable. Explain the observable behavior, then produce two correct alternatives (reference; return value) and argue which fits the call site total = addTax(total).
- **Input:** a price. **Output:** corrected behavior + both fixes.
- **Constraints:** tax rate 17%.
- **Thinking questions:** Where does the copy live and die? What does the caller have to *do* differently in each fix?

<details><summary>Hints (progressive)</summary>

1. The parameter is a copy; the mutation dies with it.
2. Fix A: double& price. Fix B: return the new value.
3. Fix B forces the call site to show assignment — visible data flow.
</details>

---

### PF-CS-036 · Primes in a Range — Function Anatomy

- **Tier:** 2 Foundational · **Lecture:** L14 · Module 7
- **Context:** A cryptography teaser lists primes in a range.
- **Problem:** Decompose into isPrime(n) and printPrimes(lo, hi). Specify each signature, the loop in isPrime (including the √n stopping rule and why it is safe), and the division of labor. Which function should know about printing?
- **Input:** lo, hi. **Output:** primes in [lo, hi].
- **Constraints:** 2 ≤ lo ≤ hi ≤ 10⁴.
- **Thinking questions:** What is the smallest divisor worth testing? Why is testing even numbers beyond 2 wasted work?

<details><summary>Hints (progressive)</summary>

1. If d divides n, so does n/d — one of them is ≤ √n.
2. Test 2, then odd divisors only.
3. printPrimes owns I/O; isPrime returns bool — one job each.
</details>

---

### PF-CS-037 · The Bilingual Menu (Overload vs Default)

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** An app greets users in English or Urdu.
- **Problem:** Two designs: (a) greet(string name, string lang = "en"); (b) overloads greet(string name) and greet(string name, string lang). Produce both, show the call matrix, and decide which communicates intent better for exactly two languages — and what breaks if a third language arrives.
- **Input:** calls from a driver. **Output:** greeting per call.
- **Constraints:** languages: en, ur (ur greets with "Assalam-o-Alaikum").
- **Thinking questions:** When are two overloads better than one default? Which design scales to three languages with less edit risk?

<details><summary>Hints (progressive)</summary>

1. Both compile; the difference is at the call site and in maintenance.
2. A third language under design (b) means another overload; under (a), another branch.
3. Branching inside one function centralizes policy — usually the winner here.
</details>

---

### PF-CS-038 · Scope Detective

- **Tier:** 2 Foundational · **Lecture:** L15 · Module 8
- **Context:** A student's program prints the "wrong" number and swears it is a compiler bug.
- **Problem:** Presented with a short program that shadows a global total with a local one inside a function, predict the exact output *before* running it, name the rule that explains it, and state the two remedies (rename; scope resolution) plus when each is appropriate.
- **Input:** the listed program. **Output:** predicted output + the rule.
- **Constraints:** —
- **Thinking questions:** Which declaration wins inside the function? What does ::total refer to?

<details><summary>Hints (progressive)</summary>

1. The innermost declaration wins name lookup.
2. Shadowing is legal but a readability hazard.
3. :: reaches the global — a band-aid; renaming is the cure.
</details>

---

### PF-CS-039 · Menu Loop with Function Dispatch

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** An ATM simulator offers 4 operations in a loop.
- **Problem:** Design the main loop: display menu, read choice, dispatch to one of four void functions, exit cleanly on 5, reject invalid choices with a message. Specify which loop form and how invalid input returns to the menu without crashing.
- **Input:** menu choices until 5. **Output:** menu + operation results + rejection lines.
- **Constraints:** choices 1–5; anything else must not terminate the loop.
- **Thinking questions:** Which control structure fits "repeat until exit"? Where is the invalid-input branch placed?

<details><summary>Hints (progressive)</summary>

1. A while-loop around menu+dispatch; the exit is a condition, not a break-by-default.
2. switch inside the loop; default handles garbage.
3. Keep the menu printing inside the loop so every path re-displays it.
</details>

---

### PF-CS-040 · Recursive Binary Strings

- **Tier:** 2 Foundational · **Lecture:** L16 · Module 8
- **Context:** A hardware course enumerates switch settings.
- **Problem:** Design printPatterns(n) that prints all 2ⁿ strings of n bits in order (n=2: 00, 01, 10, 11), recursively. Identify the base case (n == 0) and the two recursive choices. Then state the output size for n = 20 and whether printing it is reasonable.
- **Input:** n. **Output:** all bit strings.
- **Constraints:** 1 ≤ n ≤ 10 for printing; n = 20 answered analytically.
- **Thinking questions:** What are the two branches at each position? How does the recursion's depth relate to n?

<details><summary>Hints (progressive)</summary>

1. At each position: append '0' or '1', recurse, undo.
2. Depth = n; the tree has 2ⁿ leaves.
3. 2²⁰ ≈ 10⁶ lines — printable but pointless; the analysis is the answer.
</details>
