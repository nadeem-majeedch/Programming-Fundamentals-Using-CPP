# Teaching-Material Validation Report

**Scope:** the instructor-ready lesson plans for all 32 lectures and the
runnable example programs in `examples/`.
**Method:** automated checks (section scanner, compiler, scripted
execution, link checker) plus manual reading. Evidence is quoted per
check. Date: 2026-09-18.

---

## 1. Every lecture has all 12 required sections — **PASS**

Required sections (task list): lecture title/number (file header) ·
learning objectives · conceptual explanation (beginner-first) ·
terminology and definitions · syntax and C++ examples · line-by-line
code explanation · output prediction questions · common errors and
debugging examples · classroom demonstrations · guided student
activities · practice problems · summary and exit ticket.

- Evidence: section scanner over `lectures/week_*/lecture_*.md`
  → **32/32 files contain all 12 sections**;
  heading order also verified (Conceptual → … → Demonstrations →
  Guided activities → Practice → Summary → Exit ticket): **0 order
  issues** after normalization.
- Section titles are consistently worded across files, e.g.
  `## Conceptual explanation (beginner-first)`,
  `## Output prediction questions (with answers)`,
  `## Exit ticket / formative assessment`.

## 2. Every executable example compiles and runs — **PASS**

Compile contract (per [CPP_STANDARD.md](CPP_STANDARD.md)):
`g++ -std=c++17 -Wall -Wextra -pedantic <file> -o <exe>`

- Evidence: **29/29 files** in `examples/*.cpp` compiled with **zero
  warnings** (GCC 16.2.0, MinGW-w64, UCRT).
- **All 29 were executed** (not merely compiled). Spot-checked output
  verified against the expectations documented in the lesson plans:

| Program | Input | Observed (matches plan) |
|---|---|---|
| `hello_world` | — | `Hello, world!` |
| `types_and_sizes` | — | `count = 42`, `average = 91.5`, `grade = A` |
| `precedence_demo` | — | `2 + 3 * 4 = 14`, `7 / 2 = 3`, `-7 / 2 = -3` |
| `conversion_demo` | — | `5.7 → 5`, `nine / 2.0 = 4.5` |
| `decisions_grade` | `85` / `90` | `Grade: B` / `Grade: A` |
| `io_age_check` | `abc`, then `25` | recovery message, then `Status: minor`→`adult` for 19 |
| `loops_sum_digits` | `90 80 -1` then `907` | `sum = 170`; `Digit sum of 907 = 16` |
| `switch_menu` | `d` | `Deleting a record...` (+ if-version twin, `?:` max = 10) |
| `array_algorithms` | — | sum 58, avg 9.66667, min 4 @ index 4, search miss → -1 |
| `grid_basics` | — | 3×4 row-wise grid; `grid[1][2] = 7`, then 70 after write |
| `matrix_ops` | — | row totals `10 26 42`; in-place 3×3 transpose first row `1 4 7` |
| `search_compare` | — | linear 13 comparisons vs binary 4; unsorted precondition violation demonstrated |
| `sorting_traced` | — | selection pass-0 `1 2 9 5 7`, 10 comparisons / 3 exchanges; bubble trace matches |
| `pointer_basics` | — | `&x == p`, `*p = 12` changes `x`, `nullptr` guard shown |
| `passing_modes` | — | by-value leaves `n = 10`; reference and pointer swap work |
| `dynamic_memory_caution` | `3` | `sum of 1..3 = 6`; vector version with no delete (RAII) |
| `struct_records` | — | roster print, `p->gpa` == `(*p).gpa`, find by id / miss −1 |
| `first_class` | — | `set_gpa(99.0)` rejected — invariant protected; loose struct accepts 99 |
| `struct_to_class` | — | `[class ] bump(20) rejected — score stays 95` |
| `file_read_write` | — | 3 records saved/loaded round-trip; append log verified |
| `robust_pipeline` | mixed file | `line 2: bad number — skipped`; good/bad counts reported |
| `string_algorithms` | — | palindrome `Racecar` = 1; `count_words("one  two") = 2`; longest = `algorithms` |

- Programs requiring input were tested with piped inputs; no program
  hangs with closed stdin. **Claim discipline:** only the 29 files
  above are marked tested; "(live)" in-class demo snippets embedded in
  lecture plans are labeled as instructor demos, not as tested files.

## 3. Incorrect output / syntax errors — **PASS (none outstanding)**

- During verification two defects were found and fixed, then
  re-verified:
  1. `string_processing.cpp` — spurious `cin.ignore` swallowed piped
     input; removed (nothing preceded the `getline`).
  2. `robust_pipeline.cpp` / `file_read_write.cpp` — used `std::stoi`
     + exceptions, contrary to the course standard policy (exceptions
     deferred); converted to `std::istringstream` stream-state parsing.
  3. `conversion_demo.cpp` — brace-init narrowing rejected by
     `-pedantic`; teaching example switched to the `=` form with a
     comment (the pedagogical point is preserved).
- Final sweep: 29/29 compile warning-free, all outputs match.

## 4. Broken links — **PASS**

- Evidence: `bash tools/check_links.sh` →
  **OK: 353 relative markdown links checked, all resolve.**

## 5. Required topic coverage — **PASS**

grep across the 32 lecture files:

| Topic | Where (primary) | Coverage |
|---|---|---|
| Input validation | L04, L09, L30 (+ labs) | present from Module 2 onward; dedicated lecture L30 |
| Scope and lifetime | L03, L08 (L15) | dedicated lecture content (L15 area) + taught at declaration (L03) |
| Function design | M7–M8 (L13–L16) | two full modules, signature-first workflow |
| Array processing | M9–M10 (L17–L20) | two modules + string/array algorithms |
| Algorithmic complexity intuition | L10, L23, L24 | counted statements → O(n) vs O(n²) vs O(log n), measured comparison counters |
| Pointers and memory safety | L25–L27 | pointers, references, decay; leaks/dangling/double-delete with RAII default |
| File handling | L29 | streams, modes, eof trap, record round-trips |
| Introductory OOP | L31–L32 | encapsulation, invariants, constructors, const getters, struct→class refactor |

## 6. Pedagogical requirements — **PASS (by construction + audit)**

- Beginner-first: every lecture opens with
  *Conceptual explanation (beginner-first)* before formal terminology.
- Short programs before large: each *Syntax and C++ examples* section
  builds minimal snippets first; multi-function programs
  (`functions_refactor`, `robust_pipeline`) appear only in later
  modules.
- *Why*, not only *how*: every conceptual section motivates the
  construct (e.g., why `break` exists, why arrays decay, why RAII).
- Dry runs and tracing: trace tables in L05, L09, L11, L12, L21–L24;
  output-prediction sections require simulation before running.
- Standard C++ vs compiler-specific: address *format* explicitly
  flagged platform-specific in `pointer_basics`; sizes described as
  "typical-but-not-guaranteed" in L03; no compiler extensions used
  (`-pedantic` clean); `labs/TOOLCHAIN.md` (docs/TOOLCHAIN.md) covers
  per-OS differences.

## 7. No unrelated modifications — **PASS**

- Change set confined to `lectures/`, `examples/`,
  `examples/README.md`, `docs/CHANGELOG.md`, and this report.
- No build artifacts committed (`*.exe`, `*.o`: 0 in the tree);
  compilation used a temporary build directory.

## Verdict

**PASS** — 32/32 lesson plans complete and correctly ordered;
29/29 examples compile warning-free and run with verified output;
links, topics, and encoding all clean.

*Not committed or pushed (no git repository), per instructions.*
