# exercise_solutions/ — INSTRUCTOR-ONLY

**Restricted content** per
[../../instructor/ACCESS_CONTROL.md](../ACCESS_CONTROL.md). Do **not**
publish or mirror this directory to students.

## Contents

- `TNN_solutions.cpp` — compilable solution programs, one per topic file
  (`exercises/by_topic/TNN_*.md`; T12 is split into `T12_solutions.cpp`
  and `T12b_solutions.cpp`). Every exercise's solution lives in its
  own namespace (`namespace eNNN { … }`) with a `run()` entry point; each
  file's `main` runs a representative demo sequence — deterministic
  exercises run with no input, interactive ones read stdin.
- Each solution is numbered to its exercise ID (`PF-E-013` → `namespace
  e013`), prints exactly the sample output promised by the exercise
  record, and follows [../../docs/CODE_STYLE.md](../../docs/CODE_STYLE.md).
- Interactive exercises read from stdin; all others are deterministic.

## Build & run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic T01_solutions.cpp -o t01
./t01          # menu: pick an exercise number, or 'a' for all
```

All thirteen files compile warning-free under the course contract and
every exercise has been executed and its output verified against the
record's sample (see [../../docs/TEACHING_VALIDATION.md](../../docs/TEACHING_VALIDATION.md)).

## Publication model

| Phase | Where solutions live |
|---|---|
| Now (authoring) | this directory only |
| After a class session | the matching drill solution may be copied to `exercises/in_class/solutions/` |
| After a due date | the matching homework solution may be copied to `exercises/homework/solutions/` |

Students receive the **exercise records only** — records contain graded
hints, never solution code.
