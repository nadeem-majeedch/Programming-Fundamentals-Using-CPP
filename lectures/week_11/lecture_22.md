# L22 · String Algorithms: Reverse, Palindrome, Counting, Word Processing

**Module 11 — Strings and Character Processing · Week 11 · Lecture 22 of 32 · 120 minutes**
**Outcomes:** CLO-6 · PF-11.3, PF-11.4 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md) · **Quiz 3 (Modules 9–10)**

## Learning objectives

1. Implement per-character string algorithms — reverse (in place), palindrome
   check (two-pointer), vowel/word counting, case-normalization — with
   correct index bounds (PF-11.3).
2. Implement word-level processing: splitting on single spaces, longest-word
   scan, initials extraction, and search-and-replace of a whole word
   (PF-11.4).
3. Select character-level vs word-level strategies for a text task and
   justify via the structure of the data (PF-11.4).

## Prerequisites

L21 (`std::string` operations, `<cctype>`); M9–M10 (two-pointer idea seeded
by anti-diagonal traversal); L15 (functions with `const std::string&`
parameters).

## Concept sequence

1. From operations to *algorithms over text* (naming the reusable shapes)
2. Reverse in place: swap symmetry (`i` vs `len-1-i`) — transpose echo
3. Palindrome via two pointers converging
4. Counting patterns: vowels, digits, words (state machines light)
5. Word-level processing: token scan, longest word, initials
6. Character-level vs word-level decision criteria

## Teaching topics (detailed)

- **Reverse in place:** `for i in 0..len/2: swap(s[i], s[len-1-i])` —
  direct analogy to L20's `j > i` transpose argument; trace table for
  `"abcde"` (3 swaps) and `"abcd"` (2 swaps — middle untouched).
- **Palindrome two-pointer:** `is_pal(s)`: `i=0, j=len-1`; advance while
  `s[i]==s[j]`; early `false`; case-insensitive variant with `tolower` on
  both ends; empty and 1-char strings are palindromes (boundary cases from
  L12).
- **Counting:** vowels via `switch` group or `find` on `"aeiou"`; digits via
  `isdigit`; **word count as space-transitions:** count when
  `s[i] != ' ' && (i == 0 || s[i-1] == ' ')` — the word-boundary pattern
  (robust against double spaces; contrast with naive `count ' '` + 1).
- **Word-level scan:** index-walking tokenizer (find space → extract token →
  jump index) producing longest word + initials; naming each token loop;
  `substr` + `find(' ', pos)` as the two-step token extraction.
- **Strategy selection:** character-level when the answer depends on
  individual chars (counting, case); word-level when it depends on
  *sequences* (longest word, search-replace); hybrid for initials
  (word-level structure, char-level ops).

## C++ examples required

| File | Role |
|---|---|
| `string_algorithms.cpp` ✅ | reverse, palindrome (case-insensitive), vowel count, word count (boundary pattern), longest word — five labeled functions |
| (live) `initials_and_replace.cpp` | initials extractor finished from L21 + whole-word replace |

## Common student misconceptions

- "Palindrome needs a reversed copy to compare." (Two pointers avoid the
  copy — and the comparison logic is the same.)
- "Words are separated by exactly one space." (Real text has doubles/tabs —
  the boundary pattern handles it; naive split fails L12's invalid-class
  tests.)
- "`s.length()` inside the loop condition is recomputed and wrong." (It is
  recomputed but *correct*; the trap is mutating length mid-loop.)
- "Case-insensitive compare means `toupper` one side." (Both sides.)

## Conceptual explanation (beginner-first)

L21 gave you the string *vocabulary*; today we write string
*algorithms* — small functions that transform or analyze text. Two
new ideas do the heavy lifting.

The first is the **two-pointer walk**. To reverse a string you don't
need a second string: put one finger at each end, swap the characters
your fingers touch, move the fingers toward each other, stop when they
meet or cross. The same walk *is* the palindrome test: compare the
characters at the two fingers as they advance; any mismatch disqualifies
the string. One pattern, two classic algorithms — and no copying.

The second is the **boundary event**. To count words correctly, don't
count spaces — count *transitions* from "outside a word" to "inside
one." A single boolean (`inWord`) tracks which side you're on; every
space→letter crossing increments the counter. This state-machine idea
correctly handles double spaces, tabs, and leading/trailing spaces —
the cases where naive splitting fails (L12's invalid-class tests made
concrete).

Both are char-level scans — the same accumulate/count skeletons from
Module 9, with a character predicate instead of a numeric one.

## Terminology and definitions

| Term | Definition |
|---|---|
| Two-pointer walk | Index pair converging from both ends; swap or compare as they go |
| In-place reversal | Swapping within the same string — no second buffer |
| Palindrome | Reads the same both directions (test: two-pointer mismatch check) |
| Case-insensitive compare | Map both sides with `tolower` before comparing |
| Word boundary | A space→letter transition (start) or letter→space transition (end) |
| State machine | A variable (`inWord`) remembering which region you're scanning |
| Vowel count | COUNT-IF over characters with a predicate set |
| Longest word | FIND-FIRST/EXTREMES hybrid over boundary-delimited tokens |
| Character predicate | A bool-valued test applied per character |

## Syntax and C++ examples

```cpp
// reverse in place — two pointers converge
void reverse_in_place(std::string& s)
{
    int left{0};
    int right{static_cast<int>(s.size()) - 1};
    while (left < right)
    {
        char tmp{s[left]};
        s[left]  = s[right];
        s[right] = tmp;
        ++left;
        --right;
    }
}

// palindrome, case-insensitive — same walk, comparing instead of swapping
bool is_palindrome(const std::string& s)
{
    int left{0};
    int right{static_cast<int>(s.size()) - 1};
    while (left < right)
    {
        char a{static_cast<char>(std::tolower(static_cast<unsigned char>(s[left])))};
        char b{static_cast<char>(std::tolower(static_cast<unsigned char>(s[right])))};
        if (a != b)
            return false;                // early exit: any mismatch ends it
        ++left;
        --right;
    }
    return true;
}

// word count — the boundary-event state machine
int count_words(const std::string& s)
{
    int words{0};
    bool inWord{false};
    for (char ch : s)
    {
        bool isSpace{std::isspace(static_cast<unsigned char>(ch)) != 0};
        if (!isSpace && !inWord)         // space→letter crossing
            ++words;                     // a word begins
        inWord = !isSpace;
    }
    return words;
}

// vowel count — COUNT-IF with a character predicate
int count_vowels(const std::string& s)
{
    int count{0};
    for (char ch : s)
    {
        char lower{static_cast<char>(std::tolower(static_cast<unsigned char>(ch)))};
        if (lower == 'a' || lower == 'e' || lower == 'i' ||
            lower == 'o' || lower == 'u')
            ++count;
    }
    return count;
}
```

## Line-by-line code explanation

`examples/string_algorithms.cpp` (five labeled functions):

1. `reverse_in_place` — takes the string **by reference** (`std::string&`):
   the caller's string is mutated, exactly like the in-place array
   functions of Module 9. The `left < right` condition handles both
   even and odd lengths (middle char stays put in odd).
2. `is_palindrome` — same two pointers, but it *compares* mapped copies
   (`tolower` on both sides) rather than mutating; `return false`
   inside the loop is the early-exit discipline from linear search.
3. `count_words` — the state machine: `inWord` flips only on space/
   non-space transitions; the counter increments only when entering a
   word, so `"a  b"` (two spaces) counts 2, never 3.
4. `longest_word` — walks tokens between boundaries, tracking the best
   length (and its substring) so far: EXTREMES applied to text.
5. `main` runs all five on a fixed suite including `""`, `"a"`,
   `"Racecar"`, and `"  one  two  "` — the boundary inputs from L12's
   test-plan discipline, now part of the example's own evidence table.

## Output prediction questions (with answers)

1. `reverse("abcd")` — which pairs swap? — (a,d) and (b,c); result
   `"dcba"`.
2. `is_palindrome("Racecar")` — ? — true (r↔r, a↔a, c↔c; middle 'e'
   ignored); `is_palindrome("Race car")` — false (the space mismatches).
3. `count_words("  hi   there ")` — ? — 2 (naive space-counting would
   say 6).
4. `count_vowels("Programming Fundamentals")` — ? — 6 (o, a, i, u, a,
   a).
5. `reverse("a")` and `reverse("")` — ? — unchanged; the loop body
   never runs (`left < right` is immediately false) — the empty/one-
   element boundary case handled by the condition, not special code.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| `right = s.size()` (not − 1) | First swap touches `s[size()]` — UB | `static_cast<int>(s.size()) - 1` |
| `while (left <= right)` in reverse | Middle char swapped with itself — harmless here, wrong habit | `left < right` |
| Case-sensitive palindrome | "Racecar" fails | `tolower` both characters |
| Counting spaces instead of words | Double spaces inflate the count | Boundary-event state machine |
| Forgetting `&` in the parameter | Reverse works on a *copy* — caller sees no change | `std::string&` for in-place; `const std::string&` for read-only |
| Mutating `s` while iterating over it | Iterator/index invalidation surprises | Trace first; know when you mutate |

## Classroom demonstrations

1. **Fingers on paper:** two student volunteers are `left`/`right` on a
   wall-sized string; three swap rounds walk the reversal physically.
2. **The naive counter fails:** run a space-counting `count_words` on
   `"one  two"` (answer 3), then the boundary version (answer 2) —
   the state machine earns its keep.
3. **Early exit on film:** add a print inside `is_palindrome`'s mismatch
   branch — the class sees the algorithm bail at the first difference.

## Guided student activities
**Algorithm relay (20 min):** four stations (reverse, palindrome, word
count, longest word); each team writes the function at station 1, traces it
on a given input at station 2, adversarially tests another team's at
station 3; boundary inputs (`""`, `"a"`, `"  a  "`) are the ammo.

## Practice problems

- Implement `reverse_in_place`, `is_palindrome` (case-insensitive),
  `count_words` (double-space-proof), `longest_word`.
- Trace `is_palindrome("Racecar")` — show pointer positions per iteration.
- Fix a naive word counter on `"one  two"` (two spaces).
- (🟡 stretch) Sentence capitalizer: capitalize the first letter of every
  word — hybrid strategy justification required.

## Summary

Two new patterns unlock text algorithms: the two-pointer walk (reversal
and palindrome testing without copies) and the boundary-event state
machine (word counting that survives messy spacing). Both are the
Module 5/9 skeletons with character predicates — and in-place string
functions need `std::string&`, the reference parameter previewing
Module 13. Next (L23): searching arrays properly — linear vs binary.

## Exit ticket / formative assessment

1. Trace: `reverse("abcd")` — which pairs swap?
2. `count_words("  hi   there ")` — naive vs boundary-pattern answers?
3. Which strategy for "count two-letter words"? (Word-level — justify in a
   clause.)

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (string ops quiz) | 10 |
| **Quiz 3 (Modules 9–10, 15 min)** | 15 |
| Reverse + palindrome (two-pointer) | 30 |
| Break | 10 |
| Counting + word-level processing + strategy selection | 30 |
| Algorithm relay | 15 |
| Exit ticket + Module 12 preview | 10 |
