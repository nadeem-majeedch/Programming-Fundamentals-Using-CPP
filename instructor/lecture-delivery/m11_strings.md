# Delivery Guide — Module 11 · Strings and Character Processing (Week 11)

**Guides:** L21, L22 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L21 · Characters and Strings: `char` Processing and the `std::string` Class

1. **Lecture/title:** L21 — Characters and Strings: `char` Processing and the `std::string` Class
2. **Module/week:** Module 11 · Week 11 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_11/lecture_21.md): [lecture_21.md](../../lectures/week_11/lecture_21.md)): process individual `char`s with `<cctype>` classifiers; use `std::string` construction, indexing, length, and concatenation; compare strings correctly; choose `getline` vs `>>` deliberately.
4. **Prerequisite knowledge:** L17 arrays (a string *is* an indexed sequence); L04 I/O (the getline trap returns).
5. **Prep checklist:** compile `examples/string_processing.cpp` this morning; rehearse the `'A'` vs `"A"` diagnostic; load PF-CS-053; check your terminal's rendering of `tolower` on non-letters (locale note).
6. **Materials & files:** `examples/string_processing.cpp`; case PF-CS-053 The Name Formatter; [MC-13](../misconception-bank/misconception_bank.md) (returning from L04, now with string machinery).
7. **Opening question (10):** "What is a string, really? You've used them since L01." — elicit *sequence of characters*; then: "so how would `name[0]` behave?" — arrays answer before strings teach.
8. **Concept sequence (30):** (a) `char` as small integer + `<cctype>` classifiers/converters (`isalpha`, `isdigit`, `toupper`, `tolower`) (10); (b) `std::string`: indexing, `.length()`/`.size()`, concatenation, comparison (12); (c) `getline` vs `>>` revisited *with string methods* — the mixed-reading pattern done right (8).
9. **Explanation guidance:** strings are taught as *arrays with manners* — same indexing, but the object knows its length and grows. Comparison is the trap to teach explicitly: `==` on strings compares *content* (unlike C-strings — note it, do not drill it); case-sensitivity shown via `"Apple" == "apple"` being false, then `tolower`-normalized comparison as the fix.
10. **Demonstration (15):** [DEMO-22](../demonstrations/demo_group4_arrays_strings.md) — `string_processing.cpp`: classifier sweep over a mixed string, concatenate, compare; planned error: `'A' == "A"` — a compile diagnostic that *teaches* type distinctions (char vs string literal); read it with the class.
11. **Output prediction:** classifier output for `"Ci2Zn"`-style mixed strings; the case-insensitive compare vote; length of a string with a trailing space (counting is believing).
12. **Case study (15):** **PF-CS-053 The Name Formatter** — normalization pipeline (trim/case/initials) as character-level decisions; DS note: this is data *cleaning*, the most honest preview of real data work.
13. **Guided coding (20):** pairs build a password-policy checker (length, digit present, letter present — classifiers from (a)); TAs test with empty string, all-digits, unicode-paste behavior (observe, document, don't fix — encoding honesty).
14. **Common misconceptions:** [MC-13](../misconception-bank/misconception_bank.md) full treatment (mixed `>>`/getline with the fixed pipe picture); char-vs-string literal confusion (the demo's diagnostic); "strings can be compared with `<` meaningfully for sorting" — *deferred to L24/L25 discussion*, noted in pacing.
15. **Debugging activity:** symptom: "my checker accepts 'abc' but rejects 'abc '" — trailing-space behavior; trace the length/classifier logic; fix choice discussed (trim vs policy).
16. **Independent practice (20):** T07 opening items (classifiers, indexing, concat); DS students: DS-07's string-validation cousin.
17. **Exit ticket (5):** (1) `isalpha('3')`, `isdigit('3')`, `toupper('q')` — outputs. (2) Why does `==` work on `std::string` but the lecture says "compare carefully"?
18. **Summary (5):** derive: "a string is an array of characters that knows its own length — arrays plus bookkeeping."
19. **Support:** classifier reference card (the six `<cctype` functions with one-line semantics); pair the getline trap re-trace before solo work.
20. **Extension:** build `myToupper` from char arithmetic (`c - 'a' + 'A'`) — connects L05 arithmetic to L21 chars; predict-then-run.
21. **Reflection:** who still mixes `>>` and getline? (L29's file reading inherits this — flag names.) Did the `'A' == "A"` diagnostic produce the type-distinction click?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L22 · String Algorithms: Reverse, Palindrome, Counting, Word Processing

1. **Lecture/title:** L22 — String Algorithms: Reverse, Palindrome, Counting, Word Processing
2. **Module/week:** Module 11 · Week 11 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 7) — **case-heavy variant**
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_11/lecture_22.md): [lecture_22.md](../../lectures/week_11/lecture_22.md)): implement string reversal and palindrome checks (with normalization); count character classes; split text into words; design these as functions returning useful values.
4. **Prerequisite knowledge:** L21 string machinery; L18 algorithm patterns (transfer to characters).
5. **Prep checklist:** quiz 7 staged; compile `examples/string_algorithms.cpp`; load PF-CS-055 + PF-CS-054; prepare the two-index palindrome frame picture.
6. **Materials & files:** `examples/string_algorithms.cpp`; cases PF-CS-055 Palindrome Judge with Punctuation, PF-CS-054 Word Hunt with Word Boundaries; quiz 7 + key.
7. **Opening question (10):** "Is `'Madam, I'm Adam'` a palindrome? Write your *rule* first." — the class's rules will differ (punctuation? case? spaces?); the debate *is* the lesson: specification before implementation.
8. **Concept sequence (25 — quiz-day hybrid):** (a) two-index reversal/palindrome walk (left/right converging) on the frame picture (12); (b) counting pass + word-splitting pass (state machine: in-word/out-word) (8); (c) quiz-day consolidation: sort-versus-transform thinking for reverse-in-place (5).
9. **Explanation guidance:** the two-index walk is new machinery — trace it on paper for `"racecar"` (3 comparisons) before any code. Normalization as *pre-processing*: build the cleaned string first, judge second — layering, not interleaving. The word-state machine (in-word/out-word) is the course's first *algorithmic state* idea — name it as such; it returns in file parsing (L29) and beyond.
10. **Demonstration (15):** [DEMO-22/23](../demonstrations/demo_group4_arrays_strings.md) — `string_algorithms.cpp`: reverse in place (two-index swap), palindrome with normalization, word count; planned error: loop condition `left < right` vs `left <= right` on odd-length — the middle character matters; the trace shows why `<=` overchecks harmlessly but `<` misses nothing.
11. **Output prediction:** palindrome votes on three inputs (clean, punctuated, mixed-case); word count on double-spaced text (the state machine earns its keep); reverse of odd-length string.
12. **Case study (20 — case-heavy):** **PF-CS-055 Palindrome Judge with Punctuation** — the full spec debate; teams produce *rule lists* first, implementations second; PF-CS-054 named as the pair's second case if time.
13. **Guided coding (15):** pairs implement normalized palindrome + word count as *functions* (contracts first — L13 discipline); TAs check early-exit in palindrome (mismatch → return false immediately).
14. **Common misconceptions:** forgetting normalization layers; off-by-one in the converging walk; word-boundary edge cases (leading/trailing/double spaces) — all surfaced by the case debate rather than pre-taught.
15. **Debugging activity:** symptom: "my palindrome judge rejects 'A man, a plan...'" — normalization missing; the layers are checked one at a time (which layer lies?).
16. **Independent practice (10 — quiz-day trim):** one algorithm from T07 (reverse or count) + the word-boundary edge cases.
17. **Quiz 7 (15):** per cadence.
18. **Exit ticket (5):** (1) Why `left < right` (not `<=`) suffices for palindrome tests. (2) The in-word/out-word state machine: what event flips the state?
19. **Summary (5):** derive: "string algorithms are array algorithms wearing characters — the patterns transfer, the specification is the hard part."
20. **Support:** two-index ruler bookmarks (physical sliders on the printed string); state-machine diagram pre-drawn for the word splitter.
21. **Reflection:** did teams write rules *before* code? (L11's discipline, week 11 — is it habitual now?) Quiz 7's char items → who needs the classifier card reissued?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 25 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 20 |
| Independent practice | 10 |
| Quiz 7 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
