# L21 · Characters and Strings: `char` Processing and the `std::string` Class

**Module 11 — Strings and Character Processing · Week 11 · Lecture 21 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-11.1, PF-11.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Apply `<cctype>` character classification and conversion functions
   (`isdigit`, `isalpha`, `isspace`, `isupper`, `islower`, `toupper`,
   `tolower`) inside loops over text (PF-11.1).
2. Manipulate `std::string` objects: indexing, `length()`, `+`/`+=`,
   comparison, `substr`, `find`, and choose `getline` vs `>>` correctly
   (PF-11.2).
3. Explain the array-of-chars view of strings (including the `'\0'`
   terminator concept for C-strings) and why `std::string` is the course
   default (PF-11.2).

## Prerequisites

M9 (array indexing/traversal — strings *are* traversed arrays); L06
(`char`/`int` casts); L04 (why `>>` stops at whitespace).

## Concept sequence

1. Text as data: from `char` (L03) to sequences of `char`
2. `<cctype>` toolkit with a classification table demo
3. `std::string`: declaration, indexing, length
4. Building and comparing strings (`+`, `+=`, `==`, `<`)
5. Slicing and searching: `substr`, `find`
6. Reading full lines: `getline` (and its `>>` interaction trap)

## Teaching topics (detailed)

- **char classification:** each `<cctype>` predicate demonstrated on
  `'7'`, `' '`, `'Q'`, `'q'`; `toupper('a')` → `'A'`; char arithmetic
  (`'a' + 2`) revisited from L06 — digit value trick: `c - '0'`.
- **`std::string` basics:** `std::string name{"Ayesha"};`;
  `name[0]` (index, no bounds check — same discipline as arrays),
  `name.length()` (size_t printed via `static_cast<int>` per style);
  indexing loop = M9 traversal skills applied to text.
- **Building/comparison:** `+` concatenation, `+=` append; lexicographic
  `==`, `<` (dictionary order — "apple" < "banana"; case matters:
  `"Zebra" < "apple"`, why: char codes — ties to L06 char↔int).
- **`substr(pos, len)` and `find(needle)`:** `find` returns `std::string::npos`
  when absent — the not-found check pattern; first-occurrence semantics;
  slicing a fixed-format record (`"2026-09-18"` → year/month/day).
- **`getline(cin, line)`:** reads whole lines incl. spaces; the classic
  `cin >> n; getline(cin, s);` trap (leftover newline consumed by getline →
  empty string) demonstrated live and fixed with `cin.ignore()` — the
  full treatment lands in Module 15; here it is named and worked around.
- **C-string note (concept only):** `char word[] = "hi";` and the invisible
  `'\0'` terminator — one slide, historical context, `std::string` stays the
  default ([docs/CPP_STANDARD.md](../../docs/CPP_STANDARD.md) § 4).

## C++ examples required

| File | Role |
|---|---|
| `string_processing.cpp` ✅ | classification table, indexing/length, compare, substr/find with npos check, getline demo |
| (live) `name_formatter.cpp` | initials extractor: `getline` full name → toupper initials (builds toward L22) |

## Common student misconceptions

- "`std::string` is a built-in type like `int`." (It's a library class — the
  Module 16 preview; behaves like one for now.)
- "`find` returns -1 when not found." (`std::string::npos` — an unsigned
  giant; comparing to -1 "works" by accident but is wrong; course pattern:
  `if (pos != std::string::npos)`.)
- "`substr` mutates the string." (It returns a *new* string.)
- "`getline` and `>>` mix freely." (The leftover-newline trap; demonstrated,
  not hidden.)

## Conceptual explanation (beginner-first)

Strings are the first *objects* most students meet, even before Module 16
names the idea: a `std::string` bundles data (the characters) with
operations it knows how to do on itself — tell its length, find a
substring, hand back a piece, compare itself to another. The dot
syntax `s.size()` reads as "s, report your size" — that mental model
pays off in M16, so plant it now.

Under the comfort, the array knowledge from Module 9 still applies:
`s[i]` is a real `char`, indices run `0..size()-1`, and out-of-range
accesses are exactly as dangerous as array overruns. The *additional*
machinery is modest: `find` (position of a substring or
`std::string::npos` if absent), `substr` (copy a slice), and
comparison operators that order strings by character codes —
dictionary order, with the uppercase/lowercase wrinkle that
`"apple" < "Banana"` is **false** because 'a' (97) sorts after 'B' (66).

## Terminology and definitions

| Term | Definition |
|---|---|
| `std::string` | The library text type; grows as needed, remembers its length |
| Member function | Operation called on an object with dot syntax: `s.size()` |
| Indexing / length | `s[i]` is a `char`; valid `0..s.size()-1` |
| `find` | Position of first match; `std::string::npos` when absent |
| `std::string::npos` | The largest `size_t` value — the "not found" sentinel |
| `substr(pos, len)` | Copy of the slice starting at `pos`, up to `len` chars |
| Lexicographic order | `<` `>` compare char codes position by position |
| `<cctype>` | Per-char tests/maps: `isalpha`, `isdigit`, `toupper`, `tolower`, `isspace` |
| `getline` | Reads a full line (spaces included) into a string |
| Leftover newline | `cin >> x` leaves `\n`; the next `getline` reads it as an empty line |

## Syntax and C++ examples

```cpp
std::string name{"Grace Hopper"};

std::cout << name.size() << '\n';        // 12
std::cout << name[0] << '\n';            // 'G' — a plain char
name[0] = 'g';                           // assignment through the index

std::size_t pos = name.find(' ');        // 5
if (pos != std::string::npos)
    std::cout << name.substr(0, pos);    // "grace" after the write above

// lexicographic comparison — code-point order, not dictionary intuition
// "apple" < "Banana" is FALSE: 'a'(97) > 'B'(66)

// classification & mapping
char ch{'q'};
if (std::isalpha(static_cast<unsigned char>(ch)))
    ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));   // 'Q'

// the getline pattern (and the repair after >>)
int age{};
std::cin >> age;
std::cin.ignore(1000, '\n');             // drain the leftover newline
std::string title;
std::getline(std::cin, title);           // now reads the whole line
```

## Line-by-line code explanation

`examples/string_processing.cpp`:

1. The classification table prints `isalpha/isupper/isdigit/isspace`
   results for a fixed character set — a reference students copy.
2. The indexing block mutates `s[1]` and prints — strings are mutable
   through their indices, like arrays.
3. The `find`/`substr` block guards with `!= std::string::npos` before
   slicing: slicing with `npos`-derived garbage is the classic crash.
4. The comparison block orders three words by `<` and prints the
   order; the apple/Banana pair demonstrates code-point order vs
   dictionary intuition.
5. The `getline` demo deliberately follows a `cin >> int` with
   `cin.ignore` — the repair pattern shown, not just told.

## Output prediction questions (with answers)

1. `"Compiler".size()` — ? — 8.
2. `std::string s{"abc"}; s[1] = 'B';` — ? — `aBc`.
3. `"data".find('a')` — ? — 1 (first match); `.find('z')` — `npos`.
4. `"2026-09-18".substr(5, 2)` — ? — `"09"`.
5. `"apple" < "Banana"` — ? — **false**: 'a' (97) vs 'B' (66) — first
   position decides.
6. After `cin >> n` with input `7⏎Ada`, what does an un-repaired
   `getline` return? — `""` (it consumes the leftover newline).

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| Mixing `>>` and `getline` | getline returns empty | `cin.ignore(1000, '\n')` between them |
| Indexing `s[s.size()]` | Out of range — UB (empty strings: `s[0]` too) | Valid range `0..size()-1`; check emptiness |
| Slicing after unguarded `find` | substr from garbage position | Test `pos != std::string::npos` first |
| Assuming case-insensitive `<` | Wrong sort order vs. intuition | Know that comparison is code-point order |
| `toupper(s[i])` used raw | Works usually; UB for negative chars | Cast to `unsigned char` (established pattern) |
| Building output with `+` on chars | `s + 'x'` fine; `"a" + 'x'` not | Concatenate onto a `std::string` variable |

## Classroom demonstrations

1. **The empty getline:** run the un-repaired `cin >> n; getline(...)`
   with input `7⏎Ada Lovelace` — the name vanishes; add `ignore`, it
   returns. One demo, one rule, remembered all semester.
2. **npos is huge:** print `std::string::npos` — the class sees the
   giant number and why `-1` comparisons are fragile.
3. **Code-point sort:** sort `{"apple", "Banana", "cherry"}` with `<`
   — the order surprises; connect to ASCII codes on the board.

## Guided student activities
**String safari (20 min):** 8 task cards (count digits in a plate number,
upper-case a word, extract the domain from an email, compare two names for
dictionary order, find the first space, slice a date, classify one char,
append a suffix) — pairs solve on paper, then 3 are coded live by volunteer
typing.

## Practice problems

- Classification table: given 10 chars, predict each `<cctype>` result.
- Write `count_vowel`, `to_upper_copy`, `contains_digit` functions over
  strings.
- Date slicer: split `"YYYY-MM-DD"` into three ints (with `stoi` mention).
- (🟡 stretch) Why does `"apple" < "Banana"`? Print the char codes
  involved.

## Summary

`std::string` bundles characters with operations — dot syntax plants
the object mental model early. Indexing is array indexing; `find` needs
its `npos` guard; comparisons follow code points, not intuition; and
`getline` needs its `cin.ignore` repair after `>>`. Next (L22): the
algorithms that build text — cleaning, splitting, and formatting.

## Exit ticket / formative assessment

1. Write the not-found check for `find`.
2. `std::string s{"abc"}; s[1] = 'B';` — final value? What type is `s[1]`?
3. Which reads `"Data Science 101"` fully — `cin >> s` or
   `getline(cin, s)`?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (2-D quiz) + text-as-data motivation | 10 |
| `<cctype>` toolkit + char arithmetic | 25 |
| Break | 10 |
| `std::string` operations + substr/find + getline trap | 45 |
| String safari activity | 20 |
| Exit ticket + L22 preview | 10 |
