# L29 · Text Files with `ifstream`/`ofstream`: Reading, Writing, Appending, EOF

**Module 15 — File Handling and Error Management · Week 15 · Lecture 29 of 32 · 120 minutes**
**Outcomes:** CLO-8 · PF-15.1, PF-15.2 · [LEARNING_OUTCOMES.md](../../LEARNING_OUTCOMES.md)

## Learning objectives

1. Open text files for reading (`std::ifstream`) and writing/appending
   (`std::ofstream` with `std::ios::app`), always checking open success
   before use (PF-15.1).
2. Read files in all three canonical ways — token (`>>`), full line
   (`getline`), and record (token + getline combination) — and write
   formatted records that round-trip (PF-15.1, PF-15.2).
3. Implement the two correct EOF-loop idioms and explain why
   `while (!in.eof())` with an in-body read is wrong (PF-15.2).

## Prerequisites

L04 (stream state, `clear`/`ignore`); L21 (`getline`, the leftover-newline
trap — now solved systematically); L28 (struct records — the data being
persisted); M9 (arrays for loaded data).

## Concept sequence

1. Why files: persistence beyond `main`'s lifetime (capstone requirement)
2. `<fstream>`: ifstream/ofstream; open modes; open-check discipline
3. Reading: token loops, line loops, record parsing
4. Writing & appending: `ofstream`, `std::ios::app`; round-trip thinking
5. EOF: the two correct idioms and the one classic bug
6. Connecting to the capstone: load/save functions for records

## Teaching topics (detailed)

- **Open/check discipline:** `std::ifstream in{"data.txt"}; if (!in) { ...
  error path; }` — the missing-open check is *the* Module 15 style crime;
  output side: `std::ofstream out{"report.txt"};` (truncates!) vs
  `std::ofstream log{"log.txt", std::ios::app};` (appends) — the truncation
  surprise demonstrated on a file the class cares about.
- **Token reading:** `while (in >> word)` — whitespace-delimited, same
  semantics as `cin >>` (L04); counting words/numbers; numeric files
  (scores) aggregated with M18 accumulator patterns.
- **Line reading:** `while (std::getline(in, line))` — full lines with
  spaces; line counting, longest line, substring search per line (L21
  skills at file scale).
- **Record parsing:** fixed-format lines (`name,score`) — extract with
  `getline(in, name, ',')` then `in >> score` + `in.ignore()` — the
  delimiter-getline pattern; building a `std::vector<Student>` from a file
  (L28's roster becomes persistent).
- **EOF idioms:** correct: `while (in >> x)` / `while (getline(in, line))`
  — the read *is* the test; wrong: `while (!in.eof()) { in >> x; ... }`
  — reads the last value twice (the classic bug, demonstrated); why: eof
  sets only *after* a failed read.
- **Round-trip rule:** whatever `save` writes, `load` must parse —
  demonstrated with a save format that breaks its own loader (delimiter
  inside a name), then fixed (documented format contract).

## C++ examples required

| File | Role |
|---|---|
| `file_read_write.cpp` ✅ | token read, line read, append log, record save/load round-trip with open checks throughout |
| (live) `roster_persist.cpp` | L28's roster gains `save_roster`/`load_roster` — the capstone skeleton completes |

## Common student misconceptions

- "Opening for output is safe." (It truncates an existing file — data loss
  shown live; append mode exists for a reason.)
- "`eof()` predicts the next read." (It reports the *last* one; the
  read-as-test idiom is the fix.)
- "Files are checked by `if (file == NULL)`." (Stream truthiness /
  `is_open()` — and the check happens *right after open*, every time.)
- "Reading numbers from text requires parsing bytes." (Streams convert
  text→numbers automatically; bad tokens fail the stream — L04 recovery
  applies at file scale.)

## Conceptual explanation (beginner-first)

Variables live and die with the program. Close the terminal and the
roster, the scores, the diary — all gone. **Files** make data outlive
the program: same streams you already know (`cin`/`cout` are streams;
a file is just another stream connected to disk), so the reading and
writing skills transfer directly.

The workflow has four stations, each with a check: **open** (does the
file exist / is it writable?), **read or write** (same `>>`, `getline`,
and `<<` you've used all semester), **close** (or let the stream object
die at scope exit — its destructor closes, another RAII echo from
L27), and **verify** (stream state tells you whether the last operation
worked).

Two traps deserve their fame. Opening a file for output **truncates**
it instantly — open for append (`std::ios::app`) if you mean to add.
And the **eof trap**: testing `while (!in.eof())` reads one line too
far, because eof becomes true only *after* a read fails. The course
idiom — reading as the loop condition (`while (std::getline(in, line))`)
— sidesteps the whole trap: the read both attempts and reports.

## Terminology and definitions

| Term | Definition |
|---|---|
| `ifstream` | Input file stream — reads a file |
| `ofstream` | Output file stream — writes (truncates by default!) |
| `fstream` | Both directions; modes selected by flags |
| Open modes | `std::ios::app` (append), `std::ios::trunc` (default for output) |
| `is_open()` / stream-as-bool | The two accepted ways to check an open succeeded |
| Read-as-test idiom | `while (getline(in, line))` — attempt and check in one |
| eof trap | eof() reflects the *previous* read; testing it first over-reads |
| Record round-trip | Save structured records, load them back identically |
| Text format contract | The exact delimiter/order rule a loader can parse |
| RAII close | The stream's destructor closes the file at scope exit |

## Syntax and C++ examples

```cpp
#include <fstream>

// writing: output mode TRUNCATES an existing file
std::ofstream out{"scores.txt"};
if (!out)                          // check immediately, every time
{
    std::cerr << "cannot open scores.txt for writing\n";
    return 1;
}
out << 92 << ' ' << 87 << ' ' << 74 << '\n';
// out closes automatically at scope exit (RAII)

// appending: keeps existing content
std::ofstream logFile{"diary.txt", std::ios::app};
logFile << "new entry\n";

// reading token-by-token — read-as-test, no eof() in sight
std::ifstream in{"scores.txt"};
if (!in) { std::cerr << "missing scores.txt\n"; return 1; }
int score{};
while (in >> score)                // attempt+check in one condition
    std::cout << score << ' ';

// reading line-by-line
std::ifstream lines{"diary.txt"};
std::string line;
while (std::getline(lines, line))
    std::cout << line << '\n';
```

## Line-by-line code explanation

`examples/file_read_write.cpp` (four sections, open checks throughout):

1. **Token write/read:** writes three ints, closes, reopens, reads with
   `while (in >> score)` — the stream converts text back to numbers
   automatically; a non-numeric token fails the stream and ends the
   loop (the L04 input-state story, at file scale).
2. **Line read:** `getline` loop preserves spaces — for record-ish
   text; demonstrates the while-condition idiom and prints a numbered
   report.
3. **Append log:** opens twice — once in default (truncating) mode,
   once in append — and the file's before/after contents are printed:
   truncation shown, not asserted.
4. **Record round-trip:** saves a mini-roster as `name,score` lines,
   then loads it back into a `vector<Student>`-style structure and
   prints it — the format contract (comma delimiter, one record per
   line, name has no commas) stated in a comment both functions
   reference.

## Output prediction questions (with answers)

1. Open `diary.txt` (5 entries) for *output* and write 1 line — how
   many entries remain? — 1: output mode truncated the file.
2. `while (!in.eof()) in >> x;` with trailing newline — ? — The last
   value is processed twice: eof is checked before the failing read.
3. Reading `92 87 abc 74` with `while (in >> x)` — which scores print?
   — 92, 87; the `abc` fails the stream, so 74 is never reached.
4. Two runs of the append program — how many `new entry` lines? — 2:
   append preserves.
5. What if the load function's contract expects `,` but the file used
   spaces? — Every record parses wrong (name absorbs the digits) —
   format contracts must match exactly.

## Common errors and debugging examples

| Error | Symptom | Fix |
|---|---|---|
| No open check | Reads fail silently — empty results | `if (!in)` right after construction |
| Output-mode data loss | An existing file's contents vanish | Append mode (`std::ios::app`) for adding |
| eof() as the loop condition | Last record double-processed | Read-as-test: `while (getline(in, line))` |
| Mixed `>>` and `getline` on files | getline gets leftover newline | `in.ignore(...)` after token reads (L04 rule) |
| Format contract drift | Loader mis-parses every record | Comment the contract at both ends; round-trip test |
| Hardcoded absolute paths | Works on one machine only | Relative paths / project directory |

## Classroom demonstrations

1. **Truncation horror:** create a 5-line diary, run the output-mode
   writer, `type`/`cat` the file — one line remains. Append mode rerun:
   six lines. Never forgotten afterwards.
2. **The eof double-read:** run the eof-bug loop with a printed
   counter — the phantom extra iteration appears; replace with the
   read-as-test idiom and it vanishes.
3. **Round-trip ceremony:** save the roster, show the raw text file,
   load it in a fresh run — data outlives the program, visibly.

## Guided student activities
**Round-trip sabotage (20 min):** pairs receive a save function and a load
function with a mismatched format contract (delimiter clash, missing
ignore, wrong order); they must (1) break a supplied data file, (2) fix the
contract, (3) prove the round-trip with before/after file dumps.

## Practice problems

- Write `count_numbers(in_file)` and `longest_line(in_file)` with open
  checks.
- Record loader: `students.txt` (name,score lines) → vector → average (full
  pipeline).
- Append-mode diary program; verify truncation vs append on the same file.
- (🟡 stretch) Explain exactly why the eof-bug double-reads, with a trace of
  stream states per iteration.

## Summary

Files are streams to disk: open (and check!), read/write with the
familiar operators, close by RAII. The two famous traps — truncating
output mode and the eof double-read — both have one-line course idioms
(`std::ios::app`; read-as-test). Record round-trips make data outlive
the program and complete the capstone's persistence piece. Next
(L30): the full input-validation and error-handling toolkit.

## Exit ticket / formative assessment

1. Write the open-and-check idiom for reading `data.txt`.
2. Which idiom counts lines correctly — `while (getline(...))` or
   `while (!eof())`? Why in one clause?
3. What flag appends instead of truncates?

## Estimated time allocation (120 min)

| Segment | Minutes |
|---|---|
| Recall (structs quiz) + persistence motivation | 10 |
| Open/check + modes + reading trio | 40 |
| Break | 10 |
| EOF idioms + record round-trip + capstone persistence | 35 |
| Round-trip sabotage activity | 20 |
| Exit ticket + L30 preview | 5 |
