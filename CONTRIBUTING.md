# Contributing to Programming Fundamentals Using C++

Thanks for helping improve this course. These rules keep the repository
consistent for students, instructors, and future contributors.

## 1. Scope of contributions

Welcome: lecture notes, examples, exercises (with solutions), lab manuals,
assignment specs, quiz/exam items, project ideas, reference sheets, fixes to
typos and broken builds, tooling scripts.

Not in scope for this repository: content for other courses, course-external
opinion essays, and content that cannot be verified (see § 5).

## 2. Ground rules

- **Stay in scope.** All work happens inside this course directory; never touch
  sibling course folders or unrelated files.
- **Beginner-first voice.** Assume no prior programming experience. Define a
  term at first use or link to [resources/glossary.md](resources/glossary.md).
- **Every claim is checkable.** No invented references; see § 5.
- **Code must run.** See § 4 for the compile contract.
- **Respect the audience split.** Instructor-only material belongs only in
  `instructor/`, `instructor/exams/`, `instructor/assessment-rubrics/`, and
  `exercises/*/solutions/` (see [instructor/ACCESS_CONTROL.md](instructor/ACCESS_CONTROL.md)).

## 3. Naming & structure conventions

| Kind | Convention | Example |
|---|---|---|
| Directories | lowercase `snake_case` | `week_04/`, `instructor_notes/` |
| Lecture notes | `lecture_NN.md` (global numbering) | `lectures/week_04/lecture_07.md` |
| C++ sources | lowercase `snake_case.cpp` | `vector_search.cpp` |
| Assessments | `assignment_N`, `quiz_N`, `lab_N`, `midterm`, `final` | `assignments/assignment_2/` |
| Docs | `UPPER_SNAKE.md` at root, lowercase elsewhere | `COURSE_OVERVIEW.md`, `docs/cpp_core_guidelines.md` |

Every directory keeps a `README.md` that lists its layout and naming rules —
update it whenever you add a new kind of file.

## 4. Code requirements (the compile contract)

All C++ in this repository:

1. Compiles with **C++17** and the pedagogical warning set:
   `g++ -std=c++17 -Wall -Wextra -pedantic` (or the equivalent for
   clang/MSVC — see [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md)).
2. Compiles **warning-free** (warnings are bugs in beginner materials).
3. Uses `int main()` returning `int`; includes only what it uses;
   prefers `{}` initialization; follows [docs/CODE_STYLE.md](docs/CODE_STYLE.md).
4. Avoids undefined behavior of every kind; platform-specific behavior must be
   called out in a comment.

Test before submitting a contribution:

```bash
tools/check_links.sh          # markdown link integrity
g++ -std=c++17 -Wall -Wextra -pedantic examples/your_file.cpp -o /tmp/your_file && /tmp/your_file
```

## 5. Reference policy (no invented citations)

- Cite only sources you have personally verified: books (with author, title,
  publisher, and edition/ISBN), official documentation
  ([cppreference](https://en.cppreference.com/),
  [isocpp.org](https://isocpp.org/)), standards documents (ISO/IEC), or
  stable institutional pages.
- **Never fabricate:** author names, titles, page numbers, URLs, DOIs,
  statistics, or quotes. If you cannot verify it, do not cite it.
- Course-internal cross-references use relative markdown links, not citations.

## 6. Commit style

- Subject: imperative mood, ≤ 72 chars, scoped
  (`lectures: add trace-table example to lecture 08`).
- One logical change per commit; do not mix student-facing and instructor-only
  content in one commit.
- Never commit assessment keys to student-facing paths.

## 7. Review checklist (used by maintainers)

- [ ] Compiles warning-free under C++17 (compile contract § 4).
- [ ] Outcomes referenced with `PF-…` codes where the content is assessed.
- [ ] Beginner vocabulary respected; terms defined at first use.
- [ ] Links resolve (run `tools/check_links.sh`).
- [ ] Audience split intact; no key/answer material in student paths.
- [ ] Directory `README.md` updated if the layout changed.
- [ ] No unrelated files touched.

## 8. Licensing

By contributing you agree that your contributions are licensed under the
repository license ([LICENSE](LICENSE)).
