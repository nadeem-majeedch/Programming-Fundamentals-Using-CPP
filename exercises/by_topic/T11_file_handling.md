# T11 · File Handling

Covers: `ifstream`/`ofstream`, open modes, read-as-test loops, record
round-trips, robust processing (skip-and-report), append, tokenizing
file data. Lectures L29–L30. Outcomes PF-15.1–15.4.

10 exercises · ladder 🟢 → 🔴.

---

### PF-E-122 · Write and Read Back Lines
**Difficulty:** Beginner · **Lecture:** L29 · **Outcomes:** PF-15.1
**Prerequisites:** E-079
**Problem:** Read 3 lines of text; write them to `notes.txt` (one per line, numbered inside the file as `1. …` etc.). Reopen and print the file's contents. Verify (comment) what the file contains.
**Input:** three lines · **Output:** the re-read file.
**Sample:** input `alpha beta` → file line `1. alpha beta`, echoed back.
**Hints:** write, close (let scope do it), reopen — three phases.

### PF-E-123 · Copy File (line by line)
**Difficulty:** Beginner · **Lecture:** L29 · **Outcomes:** PF-15.1
**Prerequisites:** E-122
**Problem:** Copy `notes.txt` (from E-122, or create it) to `notes_copy.txt` with the read-as-test `getline` loop. Print the number of lines copied. Handle the missing source with an error message and non-zero exit.
**Input:** none · **Output:** copy confirmation + line count.
**Sample:** — → `copied 3 lines`
**Hints:** `while (std::getline(in, line))` — never test `eof()` first.

### PF-E-124 · Number File Statistics
**Difficulty:** Foundational · **Lecture:** L29 · **Outcomes:** PF-15.1, PF-15.2
**Prerequisites:** E-123
**Problem:** Read integers from `numbers.txt` (whitespace-separated, count unknown). Print count, sum, min, max, mean (2 decimals). Missing file → `cannot open` + exit 1. Empty file → print that report explicitly.
**Input:** file · **Output:** five statistics (or messages).
**Sample:** file `10 20 30` → `count: 3` / `mean: 20.00`
**Hints:** seed min/max with the *first successful read* (L11's seeding lesson).

### PF-E-125 · Append Diary with Timestamp Count
**Difficulty:** Foundational · **Lecture:** L29 · **Outcomes:** PF-15.1
**Prerequisites:** E-124
**Problem:** Read lines until an empty line; append each to `diary.txt` in append mode. Then report the total number of entries the file now holds (re-read and count). Demonstrate (comment) what would happen without `std::ios::app`.
**Input:** lines until empty · **Output:** appended confirmation + total count.
**Sample:** two new entries → `appended: 2` / `total entries now: 5`
**Hints:** append mode preserves; plain output mode truncates — the L29 horror demo.

### PF-E-126 · Student Record File Round-Trip
**Difficulty:** Foundational · **Lecture:** L29 · **Outcomes:** PF-15.2, PF-15.3
**Prerequisites:** E-125, E-113
**Problem:** Write n students (name, id, gpa) to `students.txt` as `name id gpa` lines; then load them back into a `std::vector<Student>` and print the roster with average GPA. State the format contract in a comment at both writer and reader.
**Input:** n + records · **Output:** loaded roster + average.
**Sample:** 2 students → roster lines + `average gpa: 3.55`
**Hints:** one record per line; the reader mirrors the writer field-for-field.

### PF-E-127 · Skip-and-Report Loader
**Difficulty:** Intermediate · **Lecture:** L30 · **Outcomes:** PF-15.3, PF-15.4
**Prerequisites:** E-126
**Problem:** `scores.txt` contains lines like `Ayesha,88` — but some lines are malformed (missing comma, non-numeric score, empty). Load with skip-and-report: print each bad line number with a reason, load the good ones, print final good/bad counts and the average of loaded scores.
**Input:** file (create it from a provided pattern) · **Output:** per-line reports + summary.
**Sample:** → `line 2: skipped (no comma)` / `loaded 4, skipped 2` / `average: 81.25`
**Hints:** `getline` + `istringstream` per line (L30's separation trick).

### PF-E-128 · Word Frequency from File
**Difficulty:** Intermediate · **Lecture:** L30 · **Outcomes:** PF-15.2, PF-11.4
**Prerequisites:** E-127
**Problem:** Read `story.txt` (several lines of lowercase words). Count word frequencies with parallel arrays (no map), print the top 3 words by count (ties: alphabetical) and the total word count.
**Input:** file · **Output:** top-3 + total.
**Sample:** → `the: 12` / `a: 9` / `cat: 5` / `total: 87`
**Hints:** read with `while (in >> word)`; reuse E-090's table logic per word.

### PF-E-129 · Two-File Merge (sorted score files)
**Difficulty:** Intermediate · **Lecture:** L30 · **Outcomes:** PF-15.2, PF-9.4
**Prerequisites:** E-128
**Problem:** `a.txt` and `b.txt` each hold ascending integers (unknown counts). Merge into `merged.txt` preserving order *without loading both fully into arrays* — stream merge with two input streams (peek one value ahead per file).
**Input:** two files · **Output:** `merged.txt` + line count printed.
**Sample:** a = `1 4`, b = `2 3 9` → merged `1 2 3 4 9`
**Hints:** keep one *pending* value per stream; take the smaller; refill from that stream.

### PF-E-130 · Config Reader with Defaults
**Difficulty:** Advanced Introductory · **Lecture:** L30 · **Outcomes:** PF-15.3, PF-15.4
**Prerequisites:** E-129
**Problem:** Read `config.txt` with lines `key value` (keys: `theme`, `volume`, `difficulty`). Unknown keys are skipped with a report; missing file or missing keys fall back to defaults (`dark`, 50, `normal`). Print the effective configuration and each anomaly found.
**Input:** file (possibly missing/malformed) · **Output:** effective config + anomaly list.
**Sample:** → `theme=light` / `volume=50 (default)` / `anomaly: line 3 unknown key 'lang'`
**Hints:** per line: `istringstream` → key + value; a small `if/else` chain maps keys; track which keys were seen.

### PF-E-131 · Transaction Log Audit
**Difficulty:** Advanced Introductory · **Lecture:** L30 · **Outcomes:** PF-15.3, PF-15.4, PF-14.4
**Prerequisites:** E-130
**Problem:** `transactions.txt` holds lines `account action amount` (action ∈ deposit, withdraw). Audit: apply valid transactions to a starting-balance table for 3 accounts (A101, A102, A103 — read initial balances first), skip-and-report malformed lines and overdrafts, then print each account's final balance, total processed amount, and anomaly count.
**Input:** file + initial balances · **Output:** per-account report + anomaly count.
**Sample:** → `A101: 4500 (12 processed)` / `A102: 0 (overdraft attempt on line 7)` / `anomalies: 3`
**Hints:** reuse E-118's deposit/withdraw logic over file records; the audit summary is the deliverable.
