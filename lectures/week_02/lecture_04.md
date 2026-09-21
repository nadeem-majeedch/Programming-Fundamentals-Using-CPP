# L04 · Console I/O with `cin`/`cout`: Streams, Formatting, and Input Validation Basics

**Module 2 — Variables, Data Types, and Input/Output · Week 2 · Lecture 4 of 32 · 120 minutes**
**Outcomes:** CLO-2 · PF-2.3, PF-2.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Lab 1 week**

## Learning objectives

1. Read values of any built-in type with `std::cin` (chained and single) and
   write formatted output with `std::cout` plus `fixed`, `setprecision`,
   `setw` manipulators from `<iomanip>` (PF-2.3).
2. Predict the stream-state consequences of typing the wrong kind of input,
   and write a program that detects and recovers from a failed read
   (PF-2.4).
3. Explain why `cin >> x` skips leading whitespace but `>>` stops at it
   (PF-2.3).

## Prerequisites

L03 (can declare/initialize typed variables; assignment semantics).

## Concept sequence

1. Streams as faucets: `cout` out, `cin` in
2. Reading into variables: `>>` chains, whitespace behavior
3. Output formatting: `fixed`, `setprecision`, `setw`
4. When input goes wrong: stream state `fail()`
5. Recovery: `clear()` + `ignore()`, re-prompt loop preview
6. Prompt-echo discipline (always echo what you read)

## Teaching topics (detailed)

- **`cin >>` mechanics:** whitespace-delimited tokens; chained
  `cin >> a >> b;` consumes across lines; prompt without newline
  (`std::cout << "age: "`).
- **Formatting:** `std::cout << std::fixed << std::setprecision(2) << price;`
  — money; `setw(6)` columns for tables (used again in M10 grid output);
  `<iomanip>` include.
- **Stream state:** success/fail bits; `if (!(std::cin >> age))` pattern;
  demo: typing `abc` for an int puts the stream in fail state *and leaves the
  bad text in the buffer* — hence recovery = `clear()` + `ignore(...)` before
  re-asking.
- **Echo discipline:** read → echo → compute → label output (traceability
  habit that pays off in labs).
- **Full-body minimum viable validator:** a 12-line program that re-prompts
  until an int arrives (sentinel-free loop previewed honestly: full loops in
  Module 5 — here the pattern is shown once for copy-and-adapt).

## C++ examples required

| File | Role |
|---|---|
| `io_age_check.cpp` ✅ | prompt/read/echo/validate age; fail-state recovery demonstrated live |
| (live) `format_table.cpp` | 3-column formatted table with `setw` (grades sheet) |

## Conceptual explanation (beginner-first)

So far every value lived inside the program text. Real programs *converse*:
they ask (output), the user answers (input), and the program reacts. C++
models both directions as **streams** — imagine faucets: `cout` is the
faucet pouring text onto the screen; `cin` is the drain collecting what the
user types.

`cin >> age` reads *one whitespace-separated token* and converts it into a
number stored in `age`. Two consequences surprise beginners: the read stops
at the first space (one `>>` never grabs a full line), and if the user types
something that cannot be a number, the stream itself *fails* — and stays
failed until you repair it. That failure is not a crash; it is a flag, and
flags can be checked and cleared. That is exactly what "input validation"
means in this course: read, check the flag, repair or re-prompt.

Formatting is the reverse courtesy: `fixed` and `setprecision(2)` make money
look like money (`19.9` → `19.90`) without touching the stored value — only
its *display* changes.

## Terminology and definitions

| Term | Definition |
|---|---|
| Stream | A channel data flows through (`cin` in, `cout`/`cerr` out) |
| Token | A whitespace-separated chunk of input (`>>` reads one) |
| Stream state | The flags describing the last operation: good / failed |
| `fail()` | True when the last read could not produce the requested type |
| `clear()` | Reset the state flags (does NOT discard buffered text) |
| `ignore(n, '\n')` | Discard up to n chars, stopping after a newline (buffer repair) |
| Manipulator | A stream modifier like `fixed`, `setprecision`, `setw` |
| `<iomanip>` | Header providing `setprecision`, `setw` |
| Echo | Re-print what was read, so user and program agree on what happened |
| Prompt | Text printed before a read, telling the user what to type |

## Syntax and C++ examples

```cpp
#include <iostream>
#include <iomanip>     // setprecision, setw

int age{};
std::cout << "Age: ";          // prompt (no newline)
std::cin >> age;               // read one token into age

if (!(std::cin >> value))      // the validation check pattern
{
    std::cin.clear();          // 1) reset flags
    std::cin.ignore(1000, '\n');  // 2) flush the bad line
}

std::cout << std::fixed << std::setprecision(2) << 19.9 << '\n';  // 19.90
std::cout << std::setw(6) << 42 << "|" << '\n';                    // "    42|"
```

| Piece | Meaning |
|---|---|
| `cin >> x;` | Read one token, convert to x's type, store |
| `cin >> a >> b;` | Chained reads (whitespace, incl. newlines, is skipped) |
| `if (!(std::cin >> x))` | The validation test: did the read succeed? |
| `clear()` + `ignore(...)` | The repair PAIR — clear flags, then flush the line |
| `fixed` + `setprecision(2)` | Always-2-decimals display (money) |
| `setw(6)` | Next item printed right-aligned in a 6-wide field |

## Line-by-line code explanation

`examples/io_age_check.cpp`:

1. `#include <limits>` — needed for the *large* count used in the
   professional `ignore` call.
2. `int age{0};` — initialized before any read (never read a dirty box).
3. `if (!(std::cin >> age))` — attempt the read; negate the stream's truth:
   a failed stream is "false", so `!` makes failure enter the `if`.
4. `std::cin.clear();` — reset the fail flag. Without this, every later
   read instantly fails regardless of input.
5. `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` —
   discard up to "a huge number" of characters, stopping after the newline —
   i.e., throw away the whole bad line. Doing `clear()` *without* `ignore()`
   leaves `abc` in the buffer; the next read fails again.
6. `std::cout << "Registered age: " << age << '\n';` — the echo: the user
   sees what the program understood (here, the default 0).
7. The `if (age >= 18) ... else ...` — a first taste of decisions, fully
developed in Module 4.

## Output prediction questions (with answers)

1. `cin >> a >> b;` with input `12 34` on one line — ? — `a=12, b=34`
   (whitespace, including that line break, is skipped between reads).
2. Same statement, input `12 34 56` — what is left unread? — `56` (nothing
   here consumes it — where it *matters* arrives in Module 11).
3. User types `abc` for an int — value of the variable? — Unspecified (often
   0) AND the stream is now failed; both facts matter.
4. `cout << fixed << setprecision(1) << 2.25;` — ? — `2.3` (bankers would
   quibble; the display rounds, the stored value does not).
5. `cout << setw(5) << 42 << "|";` — ? — `   42|` (right-aligned in 5; the
   `|` shows the padding).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Expecting `>>` to read a full line | `"Data Science"` read as just `"Data"` | `getline` for lines (Module 11); `>>` reads tokens |
| `clear()` without `ignore()` | Next read fails again — "validation loop" spins | Always repair with the PAIR |
| `ignore()` without `clear()` | Stream still failed; input discarded for nothing | Same: the pair, in this order |
| Forgetting `<iomanip>` | `error: 'setprecision' was not declared` | Include what you use |
| No prompt before a read | Program appears to "hang" | Print a prompt first (and no newline needed) |
| No echo | Disputes about what was typed | Echo what was read, labeled |

## Common student misconceptions

- **"`cin >> x` reads a whole line."** It stops at the first whitespace —
  `cin >> name` on input `Ada Lovelace` leaves `Lovelace` in the buffer.
- **"A failed read just skips the value."** A failed `cin >>` leaves `x`
  value-initialized to `0` and the stream in a failed state: every later
  read silently does nothing until the stream is cleared — validate
  *before* using, and reset on failure.
- **"Mixed input order is safe."** Mixing `>>` and `getline` without
  clearing the leftover newline is the classic "my getline skipped"
  bug; show why the newline remains and how to consume it.
- **"Formatting is permanent."** `std::setprecision` and field width
  stick for later output too — students are surprised when a later
  `cout` inherits the state; show resetting.

## Classroom demonstrations

1. **Fail live:** run `io_age_check.exe`, type `abc`; show the graceful
   default path. Then comment out the `clear()` line, rebuild, and show the
   next read failing — proving flags persist.
2. **Token vs line:** type `Data Science 101` into a `cin >> s` program;
   print `s` — only `Data` arrived. (Full-line reading is L21/Module 15.)
3. **Display vs value:** print `19.9` before and after `fixed` +
   `setprecision(2)`; then print it with 10 digits to prove the stored
   value never changed.

## Guided student activities
**Lab 1 (2 h, runs in this lecture slot per the calendar):** students complete
[labs/lab_manuals/lab_01](../../labs/README.md) — toolchain verification,
prompt/echo/validation drills. Lecture hour 2 = lab launch + live build of
`io_age_check.cpp` together, then supervised practice.

## Practice problems
- Write a program reading name-age-score and echoing in a `setw`-aligned row.
- Given 4 "user typed garbage" scenarios, write the recovery snippet.
- Predict stream state after each of 5 malformed inputs.
- (🟡 stretch) Make the money formatter round-trip `1234.5` → `1234.50` and
  explain why `setprecision` alone (without `fixed`) does something else.

## Summary

Input and output are streams. `cin >> x` reads one token and converts it;
failure is a *flag*, checked with `if (!(cin >> x))` and repaired with the
pair `clear()` + `ignore(...)`. Formatting manipulators (`fixed`,
`setprecision`, `setw`) change display only, never stored values. Prompt,
read, echo: the conversational discipline that makes every later lab
debuggable. Next (Module 3): what we can *compute* with the values we now
can store and read — operators and expressions.

- "`cin` reads a whole line." (It reads a *token*; spaces split input — full
  lines wait for `getline`, Module 11.)
- "Formatting changes the variable's value." (It changes only the display.)
- "If the user types letters for an int, the variable gets 0."
  (It gets garbage/0 *and* the stream fails — the second half is the trap.)
- "`endl` is required after every output."

## Exit ticket / formative assessment

1. Write the one-line check that tests whether `cin >> n` succeeded.
2. `cin >> a >> b;` with input `12 34 56` — what does `b` hold, and what is
   left unread?
3. Why must recovery call `clear()` *before* `ignore()`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (types quiz) + streams-as-faucets | 10 |
| `cin` mechanics + chains + echo discipline | 30 |
| Formatting with `<iomanip>` (live table) | 20 |
| Break | 10 |
| Stream state, failure demo, recovery pattern | 25 |
| **Lab 1 launch** (manual walk-through + supervised start) | 15 |
| Exit ticket + Module 3 preview | 10 |
