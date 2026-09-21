# BUILD_REPORT.md — Environment, Build & Reproducibility

**Course:** Programming Fundamentals Using C++ · **Report date:** 2026-09-19
**Companion document:** [FINAL_AUDIT_REPORT.md](FINAL_AUDIT_REPORT.md) (audit findings and verdict — read that for PASS/FAIL)

This report documents *how* the repository is built and validated, and how every
claim in the audit report can be reproduced.

---

## 1. Reference environment

| Component | Version used for validation |
|---|---|
| OS | Windows (Git Bash / MSYS environment) |
| Compiler | GCC (MinGW-w64) **16.2.0** — `gcc.exe (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 16.2.0` |
| C++ standard | **C++17** — fixed by the course contract ([docs/CPP_STANDARD.md](docs/CPP_STANDARD.md)) |
| Python (website + audit tooling) | **3.13.14** (standard library only — no third-party packages) |
| Website | Static output of `tools/build_site.py`; dependency-free CSS/JS ([tools/site_src.js](tools/site_src.js)) |
| Deployment | `.github/workflows/pages.yml` (GitHub Actions; same generator) |

Compiler flags contract (used for **every** compile in this audit):

```bash
g++ -std=c++17 -Wall -Wextra -pedantic <file>.cpp -o <out>
```

## 2. How to build and verify everything from a clean environment

```bash
# 0. Requirements: g++ >= 11 (C++17), python >= 3.8 (stdlib only)

# 1. Website build (deterministic: two runs are byte-identical)
python tools/build_site.py            # -> website/site/ (97 pages + styles.css + site.js + .nojekyll)

# 2. Repository markdown link check
bash tools/check_links.sh             # -> "OK: 612 relative markdown links checked, all resolve."

# 3. Compile sweep (all 72 .cpp files; one file intentionally fails — see §4)
mkdir -p /tmp/pf_build && cd /tmp/pf_build
find /path/to/repo -name '*.cpp' | while read f; do
  g++ -std=c++17 -Wall -Wextra -pedantic "$f" -o "$(basename "$f" .cpp)" || echo "FAILED: $f"
done 2> compile_log.txt
grep -c "warning\|error" compile_log.txt   # expected: only the lab_01 planted-defect file

# 4. Deterministic executions (examples with fixed input produce fixed output)
./hello_world | diff - expected/hello.txt    # pattern used for all deterministic examples
```

All audit programs that read input were driven with **deterministic inputs** (fixed
stdin, fixed dataset files from `exercises/data-science/datasets/`); no test
depends on wall-clock time or randomness (the one pseudo-random example,
`ds_simulation.cpp`, seeds its generator deterministically and documents its fixed output).

## 3. Artifacts produced by the build/validation tooling

| Artifact | Produced by | Purpose |
|---|---|---|
| `website/site/` (97 HTML pages + `styles.css` + `site.js` + `.nojekyll`) | `tools/build_site.py` | Student-facing site; **never hand-edited** — regenerate |
| `tools/site_src.js` | (source, hand-maintained) | Site syntax highlighter; linted with `node --check` |
| `.github/workflows/pages.yml` | (source) | Pages deployment; builds the site in CI — no local build needed to deploy |
| `docs/*.md` audit reports (CURRICULUM_VALIDATION, EXERCISE_VALIDATION, CASE_STUDY_AUDIT, LAB_AUDIT, ASSESSMENT_AUDIT, DS_TRACK_VALIDATION, PROJECT_LADDER_VALIDATION, TEACHING_VALIDATION, WEBSITE_QA, CHANGELOG) | prior phase audits | Per-package evidence trails |
| `FINAL_AUDIT_REPORT.md` | this audit | Cross-cutting final verdict |

Scratch artifacts (build dirs, sample output files written by executed file-I/O
examples: `scores.txt`, `mixed_scores.txt`, `app_log.txt`) were **removed** after
validation; the repo contains no leftover build outputs. `website/site/` is
regenerable and not scratch.

## 4. Reproducibility notes & known-intentional exception

* **Website build is deterministic.** Two consecutive runs with no content changes
  produced **byte-identical** trees (verified during this audit). Re-run after any
  markdown edit: `python tools/build_site.py`.
* **One intentional compile failure** exists in the repository:
  `labs/lab_manuals/lab_01/starter_code/three_stages.cpp` — the Lab 1 *bug hunt*
  plants exactly one defect at each translation stage (lexer, preprocessor,
  compiler, linker); its `manual.md` §9 instructs students to diagnose, not fix,
  before class. It is excluded from the "must compile" contract and marked in-file.
* **File-I/O examples write into the current working directory** when executed
  (documented in-file). Run them from a scratch directory if you do not want
  sample files in your working tree.
* Compiler beyond GCC 16.2: MSVC and Clang are documented as supported in
  [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md); nothing in the course uses
  compiler-specific extensions (see audit report §3, portability check).

## 5. Verification summary (counts cross-referenced in the audit report)

* 72 `.cpp` files compiled under the contract flags (71 clean + 1 intentional defect).
* ~40 deterministic executions of compiled binaries (examples, DS pipeline,
  quiz/exam answer harness, assignment keys, project reference solutions).
* Website: full crawl of 97 pages — 2,064 internal links, 0 broken; 0 placeholder hits; solution-exposure scan 0 leaks.
* Repository markdown: 612/612 relative links resolve (`tools/check_links.sh`).
