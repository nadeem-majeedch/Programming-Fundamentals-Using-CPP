# Content Roadmap

**Audience:** authors and maintainers.
**Current phase: FOUNDATION** — architecture, standards, and navigation are
complete; content authoring begins next, in the order below.

## 1. Guiding principle

Content is authored **week-first**: for each week, lecture notes → examples →
in-class exercises → homework exercises (+ solutions) → assessment items.
Nothing is marked complete until it compiles/passes
[CONTRIBUTING.md](../CONTRIBUTING.md) checks.

## 2. What exists now (foundation phase)

| Area | Status |
|---|---|
| Root documents (7) | ✅ complete |
| Directory architecture (14 dirs + subfolders) | ✅ complete |
| docs/ standards (standard, toolchain, style, roadmap) | ✅ complete |
| **Curriculum plan (16 modules · 32 lectures)** | ✅ complete — see `CURRICULUM_VALIDATION.md` |
| lectures/ planning files | ✅ all 32 authored |
| examples/ | 🟡 1 of 28 required files (index fully specified in `examples/README.md`) |
| exercises/, labs/, assignments/, quizzes/, exams/, projects/ | ⏳ directories + aligned READMEs; manuals/specs authored next |
| resources/ | 🟡 README + placeholder tracker |
| instructor/, student/, tools/, website/ | ✅ scaffolding + READMEs |

Legend: ✅ done · 🟡 partially seeded · ⏳ planned

## 3. Authoring order (recommended)

1. **Examples batch 1 (Modules 1–5):** `types_and_sizes.cpp`,
   `io_age_check.cpp`, `precedence_demo.cpp`, `conversion_demo.cpp`,
   `decisions_grade.cpp`, `switch_menu.cpp`, `loops_sum_digits.cpp`,
   `loop_patterns.cpp` — each file's exact content is specified by its
   lecture planning file.
2. **Lab manuals 1–4** from the lecture files' activity/exercise sections;
   exercise sets for Modules 1–5 (in-class + homework).
3. **Assessment layer 1:** Assignment 1 (CLO-2) + `quiz_1` + Lab 1–2 manuals.
4. **Examples batches 2–3 (Modules 6–12)** + Assignments 2–3, quiz keys.
5. **Midterm paper + key** per the blueprint in `exams/README.md`.
6. **Examples batch 4 (Modules 13–16)** + Assignment 4 + capstone pack.
7. **Final paper + key**, review guides, glossary completion, cheat sheets.
6. **Polish pass:** glossary completion, cheat sheets, website landing page,
   instructor slide sources.

## 4. Definition of done (per item)

- [ ] Compiles warning-free under the [compile contract](CPP_STANDARD.md) (code items).
- [ ] Outcomes referenced with `PF-…` codes (assessed items).
- [ ] Links resolve (`tools/check_links.sh`).
- [ ] Audience split intact (no keys in student paths).
- [ ] Directory README updated (if layout changed).
- [ ] Changelog entry added ([CHANGELOG.md](CHANGELOG.md)).

## 5. Non-goals for v1

C++20/23 features, modules, CI pipelines, autograder integration, LMS exports.
Each has a documented migration path ([CPP_STANDARD.md](CPP_STANDARD.md) § 5).

## 6. Tracking

Work is tracked per-batch; completed batches are logged in
[CHANGELOG.md](CHANGELOG.md) with dates and scope. The authoritative list of
what is missing is this document's § 2 table — keep it honest.
