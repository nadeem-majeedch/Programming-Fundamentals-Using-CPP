# Misconception and Debugging Bank — MC-00…MC-26

**Instructor-only.** 27 structured entries covering the 22 mandated topics plus
5 supporting diagnostics (MC-00, MC-05, MC-06, MC-08, MC-17, MC-19). Every
`[MC-xx]` reference in the delivery guides, demonstrations, and the
[DEBUGGING_GUIDE.md](../DEBUGGING_GUIDE.md) resolves here. Quick reference:
[../COMMON_MISCONCEPTIONS.md](../COMMON_MISCONCEPTIONS.md).

**Entry format:** ID · Topic · Incorrect belief · Why it occurs · Correct
explanation · Minimal C++ example (compilable under the course contract) ·
Questioning strategy · Corrected version · Practice task · Instructor warning.

Code conventions: `g++ -std=c++17 -Wall -Wextra -pedantic`; all examples below
were extracted and compiled clean (see the enhancement report § 17). Where the
buggy example would be *silent* at runtime, the "example" shows the buggy line
and the corrected version shows the fix — the buggy line is never shipped as a
compilable file.

---

## MC-00 · Statement termination (semicolon)

- **Topic:** the semicolon terminates a *statement*, not a line.
- **Incorrect belief:** "the error on line N is *in* line N."
- **Why:** editors and slides end visual lines where code lines end; students map lines to meaning.
- **Correct:** a statement ends at `;` (or `}`). The diagnostic's line number is where the compiler *noticed* — usually the line *after* the real defect.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int x = 5;               // buggy form: int x = 5   (no ';')
      std::cout << x << '\n';  // <- diagnostic points HERE, one line late
      return 0;
  }
  ```
- **Questioning:** "Read the diagnostic aloud. Which line does it name? What is on *that* line? What is on the line before it?"
- **Corrected:** `int x = 5;` — one character, reported one line away.
- **Practice:** three diagnostics, each naming line N; students write what they'd look at first (answer: N−1).
- **Warning:** this is the *first* diagnostic ritual students learn — do the anchor-word reading slowly in L01 and repeat it verbatim all semester.

---

## MC-01 · Assignment vs comparison

- **Topic:** `=` in a condition assigns and *then* tests the assigned value.
- **Incorrect belief:** "the compiler would stop me if I wrote `=` instead of `==`."
- **Why:** in math, `=` means equality; keyboards have one equals key; `==` looks like a typo.
- **Correct:** `if (mark = 60)` *sets* `mark` to 60; the condition's value is 60 (non-zero → true), so the branch always runs — and the variable is silently destroyed. Under `-Wall -Wextra` the compiler warns; under default flags it can be fully silent.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int mark = 55;
      if (mark == 60)          // corrected form; buggy form: mark = 60
          std::cout << "Distinction\n";
      else
          std::cout << "No distinction\n";
      std::cout << "mark is now " << mark << '\n';
      return 0;
  }
  ```
- **Questioning:** "Before compiling: error, warning, or silence? Which flag family is our witness?"
- **Corrected:** `if (mark == 60)` — and read the contract's `-Wparentheses`-family warning when the buggy form is typed live.
- **Practice:** find the one wrong operator in a 10-line ladder; explain the damage in one sentence.
- **Warning:** the *silence under default flags* is the security lesson — never skip the vote before compiling.

---

## MC-02 · Operator precedence assumptions

- **Topic:** precedence is a fixed agreement the compiler follows — and students misremember it as "multiplication first, everything else left-to-right."
- **Incorrect belief:** "`a + b / 2` computes `(a + b) / 2` because it reads that way" or "`*` always runs before `%`."
- **Why:** natural reading order; `* / %` *and* `+ -` occupy two tiers, not one.
- **Correct:** `* / %` bind tighter than `+ -`; operators of the *same* tier associate left-to-right. `(a + b) / 2` needs the parentheses it gets.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      std::cout << 2 + 3 * 4 << '\n';        // 14, not 20
      std::cout << 17 / 5 * 5 << '\n';       // 15: (17/5)=3, then 3*5
      std::cout << (2 + 3) * 4 << '\n';      // 20: parentheses override
      return 0;
  }
  ```
- **Questioning:** "Who decided the order — the compiler, the standard, or the reader? What is the *agreement* for same-tier operators?"
- **Corrected:** parenthesize when intent differs from the ladder — but learn the ladder rather than parenthesizing everything.
- **Practice:** predict-then-run three expressions; state the rule applied in each.
- **Warning:** `17 / 5 * 5` is the killer — same-tier left-to-right *and* integer division, two lessons in one line.

---

## MC-03 · Integer division

- **Topic:** `/` between two ints discards the remainder.
- **Incorrect belief:** "division always gives the decimal answer; C++ just *prints* it wrong."
- **Why:** calculators and pencil math; the type rules of expressions are invisible.
- **Correct:** the *expression's* type is decided by its operands: `17 / 5` is int/int → int 3 (remainder via `%`). Cast *before* dividing: `static_cast<double>(sum) / n`.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int a = 17, b = 5;
      std::cout << a / b << '\n';                                  // 3
      std::cout << a % b << '\n';                                  // 2
      std::cout << static_cast<double>(a) / b << '\n';             // 3.4
      std::cout << static_cast<double>(a / b) << '\n';             // 3 — too late!
      return 0;
  }
  ```
- **Questioning:** "Where in this line does the division *happen* — and what are the types *at that moment*?"
- **Corrected:** cast-before-divide; casting after is a no-op on an already-truncated value.
- **Practice:** the mean of 88+92+79+73; the minutes→h:mm converter.
- **Warning:** this is the course's most *recurring* silent bug — DS students meet it again in every average; reference MC-03 by name each time.

---

## MC-04 · Infinite loops: condition never falsified

- **Topic:** a `while` loop whose condition has no path to false.
- **Incorrect belief:** "the loop will end when the work is done" — confusing *work* with the *condition*.
- **Why:** the three-part contract (init → check → progress) lives in one line for `for` but is scattered across lines for `while`.
- **Correct:** every pass must move something toward false: a counter incremented, a value read, a distance shrunk.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int count = 10;
      while (count > 0)      // buggy body omitted the update -> hang
      {
          std::cout << count << '\n';
          --count;           // the progress step: delete me to hang
      }
      return 0;
  }
  ```
- **Questioning:** "What *must* change every pass for the condition to eventually fail? Where does that change happen?"
- **Corrected:** the `--count;` (or equivalent) present and *reachable*.
- **Practice:** three loop bodies; label each "terminates / hangs" and justify.
- **Warning:** always demo hangs *bounded* (timeout, piped EOF); a frozen projector costs five minutes.

---

## MC-05 · Infinite loops: missing read/update in sentinel loops

- **Topic:** the sentinel loop that never re-reads.
- **Incorrect belief:** "I put the sentinel check in the condition — the loop is safe."
- **Why:** the check lives in the condition but the *progress* (the next read) lives in the body; students copy the check and forget the read.
- **Correct:** the read-inside-the-condition idiom: `while (std::cin >> value && value != SENTINEL)` — one read, checked before use.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int value, total = 0;
      while (std::cin >> value && value != 0)   // read-in-condition
          total += value;
      std::cout << "total: " << total << '\n';
      return 0;
  }
  ```
- **Questioning:** "Trace two iterations: how many *reads* happened? If the body never reads again, what value is re-checked forever?"
- **Corrected:** the read-inside-condition idiom, or a priming read + trailing read pair.
- **Practice:** repair a hanging sentinel loop by adding exactly one line; name where it goes and why.
- **Warning:** students "fix" hangs by adding `break` — treat the symptom, not the contract; reject that fix in review.

---

## MC-06 · Loop reads outside the condition (sentinel consumed / junk re-fed)

- **Topic:** where the read happens relative to the check.
- **Incorrect belief:** "checking `value != 0` *before* the body's work is enough; the read's position is cosmetic."
- **Why:** when the read sits inside the body *after* the work, the sentinel value is processed before it is re-checked — the last read's value is used one pass late.
- **Correct:** the checked read must be the *only* read, positioned in the condition (or a priming read before the loop and the re-read as the body's last line).
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int value = -1, count = 0;
      // corrected idiom: read, THEN check, THEN process
      while (std::cin >> value && value != -1)
          ++count;
      std::cout << "processed: " << count << " values\n";
      return 0;
  }
  ```
- **Questioning:** "In the broken order, which value got *added* that should never have been? Which iteration noticed?"
- **Corrected:** read-in-condition; the stream-state pair (`clear`+`ignore`) at L30 is the same lesson with a failed stream.
- **Practice:** state-table trace (read → check → add → read) of a 3-value input; find the row where the broken version diverges.
- **Warning:** this is the *exam's* sentinel-trace item — make every student fill the four-column state table once.

---

## MC-07 · Off-by-one bounds: `<=` vs `<`

- **Topic:** loop bounds and array limits.
- **Incorrect belief:** "to process N items, loop `i <= N` — N is the count."
- **Why:** English counting ("count to five") vs index arithmetic (first index 0, last index N−1).
- **Correct:** N items → `i < N` when indices start at 0; `<=` visits N+1 items and touches `a[N]` — one past the end.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      const int N = 5;
      int a[N] = {2, 4, 6, 8, 10};
      for (int i = 0; i < N; ++i)      // buggy: i <= N
          std::cout << a[i] << '\n';
      return 0;
  }
  ```
- **Questioning:** "How many iterations does the buggy loop run? What does it try to read on the last one — and did the compiler stop it?"
- **Corrected:** `i < N`; on paper, draw the boxes and the final index.
- **Practice:** desk-check the boundary iteration of three loops; identify which over-runs.
- **Warning:** the exam's favorite TRACE family; enforce the box-drawing before any code is written.

---

## MC-08 · Zero-based indexing (0 vs 1 start)

- **Topic:** the first index is 0 because an index measures *distance* from the start.
- **Incorrect belief:** "the first element is `a[1]` — 1 means first."
- **Why:** ordinal language ("first, second, third") versus measurement language.
- **Correct:** `a[0]` is the first element; `a[N-1]` the last; `a[i]` is *i steps away from the start*.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      char word[] = "hi";
      std::cout << word[0] << '\n';    // 'h' — the FIRST character
      std::cout << word[1] << '\n';    // 'i'
      return 0;
  }
  ```
- **Questioning:** "If the index is a distance, how far away is the first box? What lives at distance 0 from your own chair?"
- **Corrected:** box-row drawing with indices *above* the boxes.
- **Practice:** given `a[] = {7, 9, 4}`, write what `a[0]`, `a[2]`, and `a[3]` are (the last: out of bounds).
- **Warning:** keep the 0-start and the MC-07 bound discipline as *one* lesson — they are the same arithmetic seen from two ends.

---

## MC-09 · Pass-by-value vs pass-by-reference (copy vs alias)

- **Topic:** what actually travels into a function.
- **Incorrect belief:** "the function received my variable — changes must stick" (or its twin: "references always copy on exit").
- **Why:** the call site looks identical (`f(x)`); only the signature differs.
- **Correct:** by value = a *copy* (frame picture: a new box); by reference = an *alias* (another label on the same box). `&` in the parameter list is the single character that decides.
- **Minimal example:**
  ```cpp
  #include <iostream>
  void bump_copy(int n)  { ++n; std::cout << "inside copy:  " << n << '\n'; }
  void bump_ref(int& n)  { ++n; std::cout << "inside ref:   " << n << '\n'; }
  int main()
  {
      int x = 5;
      bump_copy(x);
      std::cout << "after copy-call: " << x << '\n';   // 5 - unchanged
      bump_ref(x);
      std::cout << "after ref-call:  " << x << '\n';   // 6 - changed
      return 0;
  }
  ```
- **Questioning:** "Whose box did `++n` increment — draw both frames. What single character would flip the outcome?"
- **Corrected:** choose the mode deliberately: outputs want `&`, read-only large data wants `const &`, small copies stay by value.
- **Practice:** three signatures, one caller; predict `x` after each; verify.
- **Warning:** the frame picture is the *only* explanation that survives exams — draw it every single time.

---

## MC-10 · Uninitialized variables

- **Topic:** a declared-but-uninitialized variable holds garbage.
- **Incorrect belief:** "variables start at zero until I set them."
- **Why:** calculators clear to zero; slides show tidy initialized code; the garbage read is rarely demonstrated.
- **Correct:** an uninitialized local holds an indeterminate value — reading it is undefined behavior. Initialize at declaration (`int total = 0;` or brace-init `int total{};`).
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int total = 0;          // buggy: int total;
      int data[] = {4, 9, 2};
      for (int i = 0; i < 3; ++i)
          total += data[i];
      std::cout << "total: " << total << '\n';   // 15, deterministically
      return 0;
  }
  ```
- **Questioning:** "What is in `total` *before* the loop? Did the compiler warn us? Which flags?"
- **Corrected:** initialize at declaration; `-Wall -Wextra` flags the common paths.
- **Practice:** accumulator roulette — three variants of the same loop (init 0, init 1, uninitialized); predict each output.
- **Warning:** never let the "garbage value" demo be the *last* word — the lesson is the *habit* (initialize), not the entertainment.

---

## MC-11 · Array bounds violations (1-D)

- **Topic:** writing or reading past the end of an array.
- **Incorrect belief:** "if I write past the end, the compiler errors or the program crashes — so I'd know."
- **Why:** the contract's warnings catch many things, and students over-generalize "the tools protect me."
- **Correct:** C++ does not police array bounds at runtime. Out-of-bounds access is undefined behavior — *typically* silent corruption of a neighbor variable or a garbage read. The compiler cannot save you; only your loop discipline can.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      const int N = 5;
      int a[N] = {1, 2, 3, 4, 5};
      int sentinel = 99;                    // innocent neighbor
      for (int i = 0; i <= N; ++i)          // buggy: visits a[5]
          std::cout << a[i] << ' ';
      std::cout << "\nsentinel: " << sentinel << '\n';
      return 0;
  }
  ```
- **Questioning:** "That loop 'ran fine'. Did it? What *should* we check before trusting any array loop?" (the bound).
- **Corrected:** `i < N`; `const int N` shared by the array and every loop; never retype sizes.
- **Practice:** predict-then-run the above on the teaching machine; document what *actually* happened (it may vary — that is the point).
- **Warning:** the demo outcome varies by compiler/optimization — present it as "one possible symptom of undefined behavior," never as the guaranteed result.

---

## MC-12 · 2-D array indexing (axis confusion)

- **Topic:** `[row][col]` order and per-axis loop bounds.
- **Incorrect belief:** "`grid[c][r]` and `grid[r][c]` are interchangeable if you 'just swap the loop variables'."
- **Why:** the two subscripts look symmetric; under time pressure the fingers type the wrong order.
- **Correct:** first subscript = row (vertical), second = column (horizontal); row-major traversal: outer over rows, inner over columns; swapped inner bounds (`c < ROWS`) is the classic silent overrun.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      const int ROWS = 2, COLS = 3;
      int g[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
      for (int r = 0; r < ROWS; ++r) {
          for (int c = 0; c < COLS; ++c)    // buggy: c < ROWS
              std::cout << g[r][c] << ' ';
          std::cout << '\n';
      }
      return 0;
  }
  ```
- **Questioning:** "Which subscript picks the row? Draw the 2×3 grid and point while naming `g[1][2]`."
- **Corrected:** name the loop variables `r`/`c` and bind each bound to *its* axis; paper grid before code.
- **Practice:** column-totals function on a 3×4 grid; students must state the axis rule before coding.
- **Warning:** the colour-the-cells board act is the highest-yield fix — budget the time; `[c][r]` reflexes are corrected by pictures, not lectures.

---

## MC-13 · String input and whitespace (`>>` vs `getline`, char vs literal)

- **Topic:** `cin >>` stops at whitespace; `getline` consumes the line; `'A'` is a char, `"A"` is a string.
- **Incorrect belief:** "`cin >> name` reads the whole name" and "'A' and \"A\" are the same value."
- **Why:** both read "text"; the delimiter rules are invisible until a two-word name breaks.
- **Correct:** `>>` reads one whitespace-delimited token and leaves the newline queued; `getline` reads to the newline. Mixed reads need `cin.ignore(...)` between them. `'A'` is a `char`; `"A"` is a string literal — they are different types entirely.
- **Minimal example:**
  ```cpp
  #include <iostream>
  #include <limits>
  #include <string>
  int main()
  {
      int age = 0;
      std::string name;
      std::cin >> age;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, name);       // buggy without the ignore: empty
      std::cout << name << " is " << age << '\n';
      return 0;
  }
  ```
- **Questioning:** "Where exactly is the newline right now? Who put it there? Who will eat it?"
- **Corrected:** the ignore-line between token-read and line-read; `'A'` with single quotes for chars.
- **Practice:** read `25` then `Maria Chen` with and without the ignore; then compare `if (ch == 'A')` vs `if (ch == "A")` (the latter is a compile error — read it).
- **Warning:** the `'A' == "A"` diagnostic is a *gift* — a type-system lesson in one error message; read it aloud with the class.

---

## MC-14 · Search boundaries and preconditions

- **Topic:** linear-search return conventions; binary search's sorted precondition and boundary conditions.
- **Incorrect belief:** "binary search works on any array — it's just faster linear search" and "search should return 0 when not found."
- **Why:** the algorithm's *shape* is taught; its *contract* is footnotes.
- **Correct:** binary search requires sorted input — on unsorted data it returns *silently wrong* answers. Not-found must be a value no valid index could be: `−1`. Loop bounds: `lo <= hi` (inclusive) vs `lo < hi` (half-open) must match the update rules exactly.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int linear_search(const int* a, int n, int target)
  {
      for (int i = 0; i < n; ++i)
          if (a[i] == target)
              return i;
      return -1;                    // convention: no valid index collides
  }
  int main()
  {
      int a[] = {4, 8, 15, 16, 23};
      std::cout << linear_search(a, 5, 15) << '\n';   // 3
      std::cout << linear_search(a, 5, 99) << '\n';   // -1
      return 0;
  }
  ```
- **Questioning:** "What does the algorithm *assume*? What happens to every assumption we've broken this semester?" (silence).
- **Corrected:** check the precondition first when a search "fails"; test found/absent/first/last boundaries.
- **Practice:** the four-case test battery (present, absent, first, last) on both searches; design it from the spec before seeing the code.
- **Warning:** binary-search boundary bugs are the exam's hardest TRACE item — the loop-condition/update pairing is where off-by-one (MC-07) meets searching.

---

## MC-15 · Sorting logic (comparison direction)

- **Topic:** one flipped comparison reverses or corrupts a sort.
- **Incorrect belief:** "as long as it compiles and swaps something, the sort is 'basically right'."
- **Why:** the pass structure dominates attention; the comparison looks like a detail.
- **Correct:** ascending selection sort takes the *minimum* remaining (`<`); bubble swaps when the left is *larger* (`>`). One flipped operator → descending output, or worse, thrashing. Inner bounds (`n-1-i`) matter for correctness of the pass region.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int a[] = {5, 2, 9, 1};
      const int n = 4;
      for (int i = 0; i < n - 1; ++i) {
          int minIdx = i;
          for (int j = i + 1; j < n; ++j)
              if (a[j] < a[minIdx])       // buggy: >  -> descending
                  minIdx = j;
          int t = a[i]; a[i] = a[minIdx]; a[minIdx] = t;
      }
      for (int i = 0; i < n; ++i)
          std::cout << a[i] << ' ';
      std::cout << '\n';
      return 0;
  }
  ```
- **Questioning:** "Trace pass 1 only: which element *should* land first? Which did? What single character decides?"
- **Corrected:** comparison direction matches the goal; state "ascending ⇒ min-selection" out loud before coding.
- **Practice:** trace pass 1 of a 6-element array by hand; swap the operator and re-trace.
- **Warning:** symptom-only diagnosis ("prints descending") should be resolved by tracing pass 1 — resist running the whole sort.

---

## MC-16 · Print vs return

- **Topic:** a function that prints its result cannot give it to the caller.
- **Incorrect belief:** "the function shows the right number on screen, so the program has it."
- **Why:** output *looks* like success; the data-flow distinction is invisible on screen.
- **Correct:** `cout` is a side channel for humans; `return` is the data channel between functions. A `void` function that prints computes and *discards*.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int total_of(int a, int b)      // buggy shape: void + print
  {
      return a + b;
  }
  int main()
  {
      int t = total_of(2, 3);
      std::cout << "doubled: " << 2 * t << '\n';   // 10 — only possible via return
      return 0;
  }
  ```
- **Questioning:** "The caller wants to *double* the total. Which line of the print-version could do that? Where does the value live between functions?"
- **Corrected:** compute-and-return in the function; print in the caller (separation of concerns).
- **Practice:** convert a print-version to return-version; then write the caller that uses the value twice.
- **Warning:** this misconception survives every quick fix — assign the conversion task, not just the explanation.

---

## MC-17 · Pointer declaration syntax (`int* a, b;`)

- **Topic:** `*` binds to the *name*, not the type, in a comma list.
- **Incorrect belief:** "`int* a, b;` declares two pointers."
- **Why:** `int*` reads as a type name; the comma-list optics hide the binding.
- **Correct:** `int* a, b;` is `int *a; int b;` — one pointer, one int. One declaration per line removes the trap entirely.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int x = 7;
      int* p = &x;     // one declaration per line: no ambiguity
      int  q = x;      // b in the buggy pair was an int like this
      std::cout << *p << ' ' << q << '\n';   // 7 7
      return 0;
  }
  ```
- **Questioning:** "In `int* a, b;`, to which *name* does the star attach? What is `b`?"
- **Corrected:** one pointer declaration per line; star next to the name (`int *p`) if your style guide allows — the course uses `int* p` alone on its line.
- **Practice:** classify three comma-lists: how many pointers in each?
- **Warning:** style consistency matters more than which side the star sits on — pick the course style and never mix within a file.

---

## MC-18 · Null dereference

- **Topic:** dereferencing a null pointer is a scheduled crash.
- **Incorrect belief:** "a null pointer is just a pointer with 0 — reading through it gives 0."
- **Why:** printing the pointer shows `0`; the dereference step is invisible.
- **Correct:** a null pointer points at nothing; `*p` through null is undefined behavior — typically an immediate crash. Guard *before* dereferencing: `if (p) { use *p }`.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int* p = nullptr;        // buggy demo: *p = 5;  (crash — do not ship)
      if (p)
          *p = 5;              // guard first: reflex installed here
      else
          std::cout << "p points nowhere; skipping\n";
      return 0;
  }
  ```
- **Questioning:** "The crash happened at `*p` — what question should we have asked *one line earlier*?"
- **Corrected:** the `if (p)` guard (or establish the pointer non-null by construction).
- **Practice:** add guards to three dereference sites; justify each in one line.
- **Warning:** the *controlled* null-deref demo is the one crash we schedule — frame it exactly that way, and keep it off graded machines.

---

## MC-19 · Missing semicolon after a struct definition

- **Topic:** `struct ... { ... };` needs the trailing semicolon.
- **Incorrect belief:** "the compiler error is inside my struct — a field is broken."
- **Why:** the diagnostic lands on the *next* declaration; the struct itself looks fine (MC-00's one-line-later rule at its most confusing).
- **Correct:** a class/struct definition is a declaration that ends with `};` — the semicolon is part of the definition.
- **Minimal example:**
  ```cpp
  #include <iostream>
  struct Weather
  {
      double temp;
      int    wind;
  };                        // buggy: semicolon omitted -> chaos below
  int main()
  {
      Weather w{21.5, 8};
      std::cout << w.temp << '\n';
      return 0;
  }
  ```
- **Questioning:** "The error names a line *after* the struct. What declaration were we in the middle of?"
- **Corrected:** `};` — and the habit: when a brace-type definition is involved, look *up* from the reported line.
- **Practice:** read three cascading diagnostics; identify the real defect line in each.
- **Warning:** in my experience roughly a third of beginners hit this in the first structs week — pre-empt it by *drawing* the `};` as part of the syntax diagram.

---

## MC-20 · Constructors are not ordinary functions

- **Topic:** a constructor's name matches the class and has *no return type* — not even `void`.
- **Incorrect belief:** "a constructor is just a function named like the class; I can call it again to reset the object."
- **Why:** it *looks* like a member function; the no-return-type rule has no everyday analogue.
- **Correct:** constructors run automatically at object creation; declaring `void Student()` inside the class makes it an ordinary member that *shadows* nothing and never runs automatically. Re-"constructing" an existing object is not a thing; assign new values through methods instead.
- **Minimal example:**
  ```cpp
  #include <iostream>
  #include <string>
  class Student
  {
  public:
      Student(std::string n, int m) : name(n), marks(m) {}   // no return type
      std::string name;
      int marks;
  };
  int main()
  {
      Student s{"Ayesha", 88};      // constructor runs HERE, automatically
      std::cout << s.name << ' ' << s.marks << '\n';
      return 0;
  }
  ```
- **Questioning:** "Where is the constructor *called* in this code? What would `void Student()` change about that automation?"
- **Corrected:** correct signature; validation inside; reset via methods, never by re-construction.
- **Practice:** write the constructor for a 3-field class; then deliberately add `void` and read the compiler's complaint.
- **Warning:** the "no return type, not even void" line must be stated *and* tested — it is a reliable quiz item and a reliable lab failure.

---

## MC-21 · Access modifiers are discipline, not security

- **Topic:** `private` is interface enforcement, not encryption.
- **Incorrect belief:** "`private` keeps hackers out of my data."
- **Why:** the word "private" carries security connotations from everyday English.
- **Correct:** `private` means *only the class's own members* may touch the data — a compile-time rule that protects *your program's invariants from your own code*, including future you. There is no runtime wall; memory is still memory.
- **Minimal example:**
  ```cpp
  #include <iostream>
  class Account
  {
  public:
      void deposit(double amt)
      {
          if (amt > 0)
              balance += amt;      // the rule lives with the data
      }
      double get() const { return balance; }
  private:
      double balance = 0;          // unreachable from main — by design
  };
  int main()
  {
      Account a;
      a.deposit(50);
      std::cout << a.get() << '\n';    // 50
      // a.balance = -999;            // <- compile error: the wall works
      return 0;
  }
  ```
- **Questioning:** "Who was the wall built against? (Hint: the person typing in `main`.) What rule can now never be broken from outside?"
- **Corrected:** private data + validating methods = invariant protection.
- **Practice:** attempt the illegal access; read the diagnostic; then enforce the "balance never negative" invariant in `deposit`.
- **Warning:** do not oversell "safety" — the honest framing ("future-you is the adversary") lands better and is technically true.

---

## MC-22 · Class vs object

- **Topic:** a class is a *type* (blueprint); an object is a built *thing*.
- **Incorrect belief:** "the class and the object are the same thing; defining a class created my data."
- **Why:** the definition *is* most of the code students write; the object is one line of `main`.
- **Correct:** the class definition allocates nothing; each *object* gets its own member boxes at declaration. The L03 box picture scales: class = box *design*, object = box.
- **Minimal example:**
  ```cpp
  #include <iostream>
  class Counter            // design only — no memory yet
  {
  public:
      void bump() { ++count; }
      int  get()  const { return count; }
  private:
      int count = 0;
  };
  int main()
  {
      Counter a, b;        // TWO objects, TWO independent boxes
      a.bump(); a.bump();
      b.bump();
      std::cout << a.get() << ' ' << b.get() << '\n';   // 2 1
      return 0;
  }
  ```
- **Questioning:** "How many `count` boxes exist after `Counter a, b;`? What did the class definition itself allocate?"
- **Corrected:** objects own storage; classes own the *rules*.
- **Practice:** three objects with divergent histories; predict each `get()` before running.
- **Warning:** this misconception silently produces "shared state" bugs in labs — catch it by asking *how many boxes* questions from day one of Module 16.

---

## MC-23 · File-open failure unchecked

- **Topic:** an `ifstream` that fails to open still "reads" — producing nothing, silently.
- **Incorrect belief:** "if the file is missing, the program crashes or complains."
- **Why:** every earlier failure mode *said something*; file silence is new and unexpected.
- **Correct:** a failed stream puts itself in a fail state; reads become no-ops; the loop body never runs; the program exits 0 having done nothing. Check `if (!in)` immediately after opening — every time, no exceptions.
- **Minimal example:**
  ```cpp
  #include <iostream>
  #include <fstream>
  #include <string>
  int main()
  {
      std::ifstream in("no_such_file.txt");
      if (!in)                            // the guard: non-negotiable
      {
          std::cerr << "ERROR: cannot open no_such_file.txt\n";
          return 1;
      }
      std::string line;
      while (std::getline(in, line))
          std::cout << line << '\n';
      return 0;
  }
  ```
- **Questioning:** "Run it without the guard: what did it print? What was the exit code? Is 'silent success' worse than a crash — for whom?"
- **Corrected:** the open-check guard with a message and a non-zero exit (or documented fallback).
- **Practice:** delete the data file and run both variants; write the two-sentence incident report ("what happened, what the user should see").
- **Warning:** the empty-read family (print nothing, exit 0) is the #1 real-world student bug in Module 15 — grade the guard's *presence* in every file-handling submission.

---

## MC-24 · Memory leaks ("the program ended, so it's fine")

- **Topic:** every `new` must be matched by exactly one `delete`.
- **Incorrect belief:** "the OS reclaims everything at exit, so leaks don't matter in coursework."
- **Why:** short-lived demo programs genuinely show no symptom; the cost is deferred.
- **Correct:** the OS does reclaim at exit — but the *habit* is what fails later: long-running programs, loops, and servers leak until they die. Ownership is a design property: one owner, one delete — or better, `std::vector`, which owns and releases automatically.
- **Minimal example:**
  ```cpp
  #include <iostream>
  #include <vector>
  int main()
  {
      // buggy shape:  for (int i = 0; i < 10; ++i) { int* p = new int{i}; }
      //   -> ten allocations, zero releases: the leak.
      std::vector<int> kept;          // the grown-up version
      for (int i = 0; i < 10; ++i)
          kept.push_back(i);
      std::cout << "kept " << kept.size() << " values, no manual deletes\n";
      return 0;
  }
  ```
- **Questioning:** "Who owned each allocation? When did the lease end? What happens to this design when the loop runs once per second, forever?"
- **Corrected:** match every `new` with one `delete`; prefer `std::vector` for owned data.
- **Practice:** ledger audit — list every allocation in a program and its release; find the orphan.
- **Warning:** raw `new`/`delete` in this course is *read-and-recognize*: students explain leaks in reviews; they write `vector` in submissions.

---

## MC-25 · Dangling pointers and double-delete

- **Topic:** `delete` ends the *lease*; the pointer's arrow survives pointing at freed memory.
- **Incorrect belief:** "`delete p;` destroys `p` itself, so it can't be used again — and deleting twice is a harmless no-op."
- **Why:** the delete line *looks* like it removes the variable; nothing visible happens to the arrow.
- **Correct:** `delete` releases the pointed-to memory; `p` still holds the (now stale) address. Using `*p` afterwards is undefined behavior; `delete`ing the same address twice is undefined behavior. Discipline: null the pointer after delete (`p = nullptr;`) and never delete an address twice.
- **Minimal example:**
  ```cpp
  #include <iostream>
  int main()
  {
      int* p = new int{42};
      std::cout << *p << '\n';   // 42
      delete p;                  // lease ended...
      p = nullptr;               // ...arrow retired — the discipline
      if (p)
          std::cout << *p << '\n';   // never runs: guard + null = safe
      std::cout << "clean exit\n";
      return 0;
  }
  ```
- **Questioning:** "After `delete p;` what does `p` *contain*? What would `*p` do — and why can't the compiler warn us here?"
- **Corrected:** delete → null → guard; one owner (MC-24's rule) makes double-delete structurally impossible.
- **Practice:** annotate a 12-line program with lease start/end arrows; mark the exact line where each pointer went stale.
- **Warning:** never "demo" the dangling read on lab machines — diagram it on the board instead; the symptom (garbage vs crash) is UB and varies, which is itself the lesson.

---

## MC-26 · Exception handling: responsibility and recovery

- **Topic:** `throw` transfers the problem upward; *someone* must `catch` or the program terminates.
- **Incorrect belief:** "`try`/`catch` is a fancy `if` — the error is 'handled' anywhere nearby, or a catch-all `catch(...)` is good hygiene."
- **Why:** the try-block visually *contains* the risk, so students assume containment; recovery responsibility is abstract.
- **Correct:** the exception *propagates* up the call stack until a matching `catch` is found; none → `std::terminate` and the program dies. Design the division of labor: guards for expected input problems (re-prompt the user), exceptions for rule violations the caller must decide about. `catch` by `const&`; empty catch-alls swallow failures silently.
- **Minimal example:**
  ```cpp
  #include <iostream>
  #include <stdexcept>
  double safe_divide(double a, double b)
  {
      if (b == 0)
          throw std::runtime_error("divide by zero");
      return a / b;
  }
  int main()
  {
      try {
          std::cout << safe_divide(10, 0) << '\n';
      } catch (const std::runtime_error& e) {
          std::cout << "caught: " << e.what() << '\n';   // recovery lives HERE
      }
      return 0;
  }
  ```
- **Questioning:** "Who is responsible for recovery — the thrower or the catcher? What happens to the frames between them if nobody catches?"
- **Corrected:** deliberate throw sites, matching catches, `const&` parameters, meaningful messages.
- **Practice:** remove the catch and observe the terminate; then add a second exception type and discuss clause ordering.
- **Warning:** the course division (guards vs exceptions) is stated in L30 and enforced in the project rubric — wrong tool for the problem is a *design* mark, not a syntax one.
