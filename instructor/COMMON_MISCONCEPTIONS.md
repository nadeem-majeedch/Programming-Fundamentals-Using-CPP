# COMMON_MISCONCEPTIONS — Quick Reference

**Instructor-only.** One-line index of the 27-entry bank:
[misconception-bank/misconception_bank.md](misconception-bank/misconception_bank.md)
(full entries: incorrect belief, why it occurs, minimal example, questioning
strategy, corrected version, practice task, instructor warning).

**Teaching rhythm:** seed the misconception with a question → demonstrate the
symptom (edit-in-place, never pre-broken files) → name it with its MC-ID →
assign the bank's practice task. IDs are used by students too — the
midterm/final DEBUG items cite them.

| ID | Topic | The wrong belief, in one line | Home lecture |
|---|---|---|---|
| MC-00 | Semicolon = statement terminator | "the error is *in* line N" | L01 |
| MC-01 | Assignment vs comparison | "`=` in a condition? The compiler stops me." | L07 |
| MC-02 | Operator precedence | "multiplication first, rest left-to-right" | L05 |
| MC-03 | Integer division | "division always gives the decimal answer" | L05 |
| MC-04 | Infinite loop: no progress | "the loop ends when the work is done" | L09 |
| MC-05 | Sentinel loop: missing re-read | "the check in the condition makes it safe" | L09 |
| MC-06 | Read outside the loop check | "the read's position is cosmetic" | L09 |
| MC-07 | Off-by-one bounds | "process N items → loop `i <= N`" | L10 |
| MC-08 | Zero-based indexing | "first element is `a[1]`" | L10 |
| MC-09 | Copy vs alias | "the function got my variable — changes stick" | L13/L15 |
| MC-10 | Uninitialized variables | "variables start at zero" | L03 |
| MC-11 | 1-D array bounds | "out of bounds crashes — I'd notice" | L17 |
| MC-12 | 2-D array axes | "`grid[c][r]` ≈ `grid[r][c]`, just swap the loops" | L19 |
| MC-13 | String input & whitespace | "`cin >> name` reads the whole name"; "'A' == \"A\"" | L04 |
| MC-14 | Search boundaries & preconditions | "binary search works on any array" | L23 |
| MC-15 | Sorting comparison direction | "it compiles and swaps, so it's basically right" | L24 |
| MC-16 | Print vs return | "it's on screen, so the program has it" | L13 |
| MC-17 | Pointer declaration syntax | "`int* a, b;` = two pointers" | L25 |
| MC-18 | Null dereference | "reading through null gives 0" | L25 |
| MC-19 | Semicolon after struct | "the error is inside my struct" | L28 |
| MC-20 | Constructors | "just a function named like the class" | L31 |
| MC-21 | Access modifiers | "`private` keeps hackers out" | L31 |
| MC-22 | Class vs object | "defining the class created my data" | L31 |
| MC-23 | File-open failure | "missing file → crash or complaint" | L29 |
| MC-24 | Memory leaks | "the OS cleans up; leaks don't matter here" | L27 |
| MC-25 | Dangling / double-delete | "`delete p;` destroys `p`" | L27 |
| MC-26 | Exceptions | "try/catch is a fancy if; catch-all is hygiene" | L30 |

**Scope notes:** all examples in the bank compile clean under the course
contract (`g++ -std=c++17 -Wall -Wextra -pedantic`, GCC 16.2 — see
[BUILD_REPORT.md](../../BUILD_REPORT.md)). Buggy variants are shown as
commented lines or described edits, never shipped as compilable files.
