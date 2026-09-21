# T07 · Strings

Covers: `std::string` operations, indexing, find/substr, `<cctype>`,
getline, word algorithms (two-pointer, boundary events), C-strings.
Lectures L21–L22 (and L04's getline rules). Outcomes PF-11.x.

12 exercises · ladder 🟢 → 🔴.

---

### PF-E-079 · Name Greeting
**Difficulty:** Beginner · **Lecture:** L21 · **Outcomes:** PF-11.1
**Prerequisites:** E-001
**Problem:** Read a full name (may contain spaces) with `getline` and print `Hello, <name>!` plus the name's length.
**Input:** one line · **Output:** greeting + length.
**Sample:** `Ada Lovelace` → `Hello, Ada Lovelace!` / `length: 12`
**Hints:** `getline`, not `cin >>` — spaces matter.

### PF-E-080 · Initials Extractor
**Difficulty:** Beginner · **Lecture:** L21 · **Outcomes:** PF-11.1, PF-11.2
**Prerequisites:** E-079
**Problem:** Read a full name; print the uppercase initials (first letter of each word) followed by periods.
**Input:** one line · **Output:** initials.
**Sample:** `ada lovelace` → `A.L.`
**Hints:** first character is an initial; every letter *after a space* is too.

### PF-E-081 · Vowel/Consonant Census
**Difficulty:** Beginner · **Lecture:** L21 · **Outcomes:** PF-11.2
**Prerequisites:** E-080
**Problem:** Read one word; count vowels, consonants, and non-letters (using `<cctype>`), case-insensitively. Print all three.
**Input:** one word · **Output:** three counts.
**Sample:** `R2-D2` → `vowels: 0` / `consonants: 2` / `other: 3`
**Hints:** `tolower` first; a letter that isn't a vowel is a consonant.

### PF-E-082 · Word Count (robust)
**Difficulty:** Foundational · **Lecture:** L22 · **Outcomes:** PF-11.2, PF-11.4
**Prerequisites:** E-081
**Problem:** Read a whole line; count words correctly despite double spaces, leading/trailing spaces, and tabs. Print the count and the longest word's length.
**Input:** one line · **Output:** count + longest length.
**Sample:** `  one  two three  ` → `words: 3` / `longest: 5`
**Hints:** the boundary-event state machine (L22); track current word length as you scan.

### PF-E-083 · String Reversal (both ways)
**Difficulty:** Foundational · **Lecture:** L22 · **Outcomes:** PF-11.3
**Prerequisites:** E-082
**Problem:** Read a line. Print it reversed two ways: (1) a new reversed string built with `+=`, (2) in-place two-pointer reversal of a copy. Print both and confirm equal.
**Input:** one line · **Output:** two reversed lines + verdict.
**Sample:** `abc de` → `ed cba` / `ed cba` / `match: yes`
**Hints:** method 2 needs `std::string&` — reference parameters preview.

### PF-E-084 · Palindrome Judge (case/space insensitive)
**Difficulty:** Foundational · **Lecture:** L22 · **Outcomes:** PF-11.3, PF-11.4
**Prerequisites:** E-083
**Problem:** Read a line; judge palindrome ignoring case, spaces, and punctuation (digits count as characters). Print verdict and the cleaned string used.
**Input:** one line · **Output:** verdict + cleaned string.
**Sample:** `A man, a plan!` → `not palindrome` / `cleaned: amanaplan`
**Hints:** clean into a new string first, then two-pointer judge — two passes beat one clever one.

### PF-E-085 · Substring Finder with All Positions
**Difficulty:** Foundational · **Lecture:** L21 · **Outcomes:** PF-11.2
**Prerequisites:** E-084
**Problem:** Read a text line and a search word. Print every position (0-based) where the word occurs and the total count. Overlaps count (e.g. `aa` in `aaaa` occurs at 0, 1, 2).
**Input:** two lines · **Output:** positions + count (or `none`).
**Sample:** text `ababab`, word `ab` → `positions: 0 2 4` / `count: 3`
**Hints:** `find` with a start position in a loop; advance by one for overlaps.

### PF-E-086 · Case Normalizer
**Difficulty:** Intermediate · **Lecture:** L22 · **Outcomes:** PF-11.2, PF-11.3
**Prerequisites:** E-085
**Problem:** Read a line; produce the "title case" version: first letter of each word uppercase, all other letters lowercase. Preserve all non-letter characters and spacing exactly.
**Input:** one line · **Output:** normalized line.
**Sample:** `  hello, C++ WORLD! ` → `  Hello, C++ World! `
**Hints:** boundary events tell you when a word *starts*; `tolower`/`toupper` per char.

### PF-E-087 · CSV Tokenizer
**Difficulty:** Intermediate · **Lecture:** L22 · **Outcomes:** PF-11.2, PF-11.4
**Prerequisites:** E-086
**Problem:** Read a comma-separated line (e.g. `12,7,,9`); split into tokens and print each on its own numbered line. Empty fields (between consecutive commas) must appear as empty tokens. Print the token count.
**Input:** one CSV line · **Output:** numbered tokens + count.
**Sample:** `12,7,,9` → `1: 12` / `2: 7` / `3: (empty)` / `4: 9` / `count: 4`
**Hints:** don't forget the final token after the last comma (L22's classic bug).

### PF-E-088 · C-String Walk (char buffer)
**Difficulty:** Intermediate · **Lecture:** L17 · **Outcomes:** PF-11.3
**Prerequisites:** E-087
**Problem:** Copy a read word into a `char buffer[32]` (validate length ≤ 30 first). Walk the buffer with the terminator scan (`while (buf[i] != '\0')`) to count letters vs digits, then print the buffer in reverse using the same walk backwards. No `std::string` in the processing code.
**Input:** one word · **Output:** letter/digit counts + reversed buffer.
**Sample:** `ab12` → `letters: 2` / `digits: 2` / `reversed: 21ba`
**Hints:** find the length first by walking forward, then walk backward from length−1.

### PF-E-089 · Caesar Cipher (encrypt + decrypt)
**Difficulty:** Advanced Introductory · **Lecture:** L22 · **Outcomes:** PF-11.2, PF-11.4
**Prerequisites:** E-088
**Problem:** Read a shift k (1–25) and a line. Encrypt: letters shift by k (wrapping A–Z / a–z), all other characters unchanged. Print the ciphertext. Then decrypt it back and print, confirming it matches the input.
**Input:** integer + line · **Output:** ciphertext + decrypted plaintext.
**Sample:** k=3, `Hello, World!` → `Khoor, Zruog!` / then `Hello, World!`
**Hints:** per char: if upper, `'A' + (ch - 'A' + k) % 26` — the modular wrap; decrypt is shift 26−k.

### PF-E-090 · Word Frequency Table
**Difficulty:** Advanced Introductory · **Lecture:** L22 · **Outcomes:** PF-11.4, PF-9.3
**Prerequisites:** E-089
**Problem:** Read a line of lowercase words (space-separated, ≤ 20 words, each ≤ 15 chars). Build a frequency table **without** `std::map`: parallel arrays of distinct words and counts. Print each distinct word with its count, in first-appearance order, then the most frequent word (first wins ties).
**Input:** one line · **Output:** table + winner.
**Sample:** `a b a c b a` → `a: 3` / `b: 2` / `c: 1` / `top: a`
**Hints:** for each word, linear-search the distinct list — found: increment; missing: append.
