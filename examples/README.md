# examples/ — Runnable Demo Programs

Small, standalone, heavily commented C++ programs required by the lecture
planning files. One file = one teaching point. ✅ exists · ⏳ required by a
lecture, to be authored with the example batches
([../docs/CONTENT_ROADMAP.md](../docs/CONTENT_ROADMAP.md)).

## Compile contract (applies to every file here)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello
./hello
```

Warning-free, portable, no extensions — policy in
[../docs/CPP_STANDARD.md](../docs/CPP_STANDARD.md) § 3, style in
[../docs/CODE_STYLE.md](../docs/CODE_STYLE.md).

## Index (by module)

### Data-science track — [data-science/](data-science/README.md)

Nine data-oriented programs (descriptive statistics, frequency counting,
validation policies, a file pipeline, tabular records, and a reproducible
simulation) for the BS Data Science audience, plus suggested extensions in
[data-science/extensions.md](data-science/extensions.md). Instructor notes:
`../instructor/examples_data_science/` (restricted).

| File | Teaches | Required by |
|---|---|---|
| `hello_world.cpp` ✅ | program anatomy, `cout`, build & run | L01, L02 |
| `types_and_sizes.cpp` ✅ | built-in types, brace init, `sizeof`, narrowing | L03 |
| `io_age_check.cpp` ✅ | `cin`, stream state, fail recovery | L04 |
| `precedence_demo.cpp` ✅ | precedence, associativity, int vs double division, negative `%` | L05 |
| `conversion_demo.cpp` ✅ | promotion, narrowing, `static_cast`, char codes | L06 |
| `decisions_grade.cpp` ✅ | `if/else` design, guard-clause refactor | L07 |
| `switch_menu.cpp` ✅ | `switch` vs `if/else if`, grouped cases, `default` | L08 |
| `loops_sum_digits.cpp` ✅ | sentinel loop, digit-sum via `%`/`/` | L09 |
| `loop_patterns.cpp` ✅ | the six named patterns with traces | L10, L11 |
| `buggy_off_by_one.cpp` ✅ | seeded bugs for trace/debug drills | L12, L16 |
| `functions_refactor.cpp` ✅ | flat → decomposed gradebook | L13 |
| `scope_lifetime_demo.cpp` ✅ | block scope, shadowing, global-mutable bug | L14 |
| `overload_ref_demo.cpp` ✅ | overload resolution, swap, output parameters | L15 |
| `array_basics.cpp` ✅ | init forms, traversal, OOB (commented) | L17 |
| `array_algorithms.cpp` ✅ | fill/print, sum, min/max, count-if, reverse, linear search | L18 |
| `grid_basics.cpp` ✅ | 2-D declaration, row-major addresses | L19 |
| `matrix_ops.cpp` ✅ | row/col totals, addition, transpose | L20 |
| `string_processing.cpp` ✅ | `<cctype>`, string ops, substr/find, getline | L21 |
| `string_algorithms.cpp` ✅ | reverse, palindrome, word count, longest word | L22 |
| `search_compare.cpp` ✅ | linear vs binary with counters | L23 |
| `sorting_traced.cpp` ✅ | selection + bubble with snapshots and counters | L24 |
| `pointer_basics.cpp` ✅ | addresses, `&`/`*`, nullptr, arithmetic walk | L25 |
| `passing_modes.cpp` ✅ | value/reference/pointer/array passing evidence | L26 |
| `dynamic_memory_caution.cpp` ✅ | leak/dangle/double-delete + RAII contrast | L27 |
| `struct_records.cpp` ✅ | struct, nested, vector-of-records algorithms | L28 |
| `file_read_write.cpp` ✅ | token/line/record I/O, append, round-trip | L29 |
| `robust_pipeline.cpp` ✅ | skip-and-report, error tiers, clear/ignore | L30 |
| `first_class.cpp` ✅ | class: private data, constructors, validation | L31 |
| `struct_to_class.cpp` ✅ | refactor checklist applied side-by-side | L32 |

Live-typed demos named in lectures (`greet.cpp`, `anatomy_break.cpp`,
`digit_extractor.cpp`, …) are instructor-typed on stage and are not committed
as files unless promoted by a roadmap batch.

## Conventions

- File names `snake_case.cpp`; a file with `main()` compiles standalone.
- No header files here — headers appear with classes in lecture notes.
- Every file starts with a one-paragraph purpose comment.
- Programs read from `stdin` (never hard-coded absolute paths).
