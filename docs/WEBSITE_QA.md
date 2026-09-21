# Website QA Report

**Scope:** the generated course website — `website/site/` (97 HTML pages +
`styles.css` + `site.js` + mirrored DS datasets), produced by
`tools/build_site.py` from repository markdown.

**Method:** automated link crawl of the entire site graph from `index.html`
(all `href`/`src` targets and cross-page fragments resolved on disk), regex
audits of rendered text for solution/restricted content, per-page
accessibility attribute checks, plus live rendering in a browser preview at
desktop and mobile widths (screenshots inspected for layout, nav state, and
syntax highlighting). Date: 2026-09-18.

---

## 1. Required pages and sections — **PASS**

All twelve required sections exist, are reachable from the primary nav on
every page, and are reachable by the crawler from `index.html`:
`index, overview, outcomes, schedule, lectures, labs, cases, exercises,
assignments, projects, resources, instructor` — missing: **none**.

Sub-page coverage: lectures **33** (32 lectures + index), labs **17**
(16 + index), cases **7**, exercises **17** (12 topic banks + 3 DS parts +
index + datasets), assignments **11** (8 specs + 2 review guides + index),
projects **6** (5 + index).

## 2. Broken internal links and fragments — **PASS**

Full crawl: **0 broken links, 0 missing fragments across 97 pages**; exactly
one external link (`https://isocpp.org`, `rel="noopener"`).

Defects found and fixed during QA (all re-verified after the fix):

| # | Defect | Fix |
|---|---|---|
| 1 | Root-relative chrome (`styles.css`, nav, brand, breadcrumbs) broken on all 85 sub-pages — 1,415 broken links at first crawl | `render()` emits `../`-prefixed URLs from page depth |
| 2 | 140 raw repo-relative `.md` links from mirrored markdown (depths like `../../LEARNING_OUTCOMES.md`) | pf: normalization + site-wide resolver: mapped targets → pages, mirrored files → site copies, repo docs → de-linked `<code>` text |
| 3 | 16 lab-page links to `debug_log_template.md` / `submission_template.md` | Both templates now rendered on `resources.html#lab-templates` |
| 4 | `#top` pager anchor missing on every page | Pager targets `#main` (always present) |
| 5 | `by_tier/`, `datasets/stations/` directory links dead | Mapped to `cases.html`, `exercises/ds/datasets.html`; datasets mirrored into the site (11 files) |
| 6 | ` lectures/week_../lecture_MM.md` links on lecture pages | Resolved to sibling lecture pages |

## 3. Content integrity / solution exposure — **PASS**

- Automated text audit (tag-stripped, case-insensitive) for `model answer`,
  `sample solution`, `reference solution`, `grader notes`, `distractor
  analysis`, `marking scheme`: **2 hits, both policy sentences** on
  `assignments.html` stating *where* restricted keys live — no solution
  content.
- Answer-line pattern scan (`Answer:`, `Correct answer`): **0 hits**.
- Instructor-only directories (`instructor/exams`, `answer_keys`,
  `exercise_solutions`, `projects`, `case_studies`, `assessment-rubrics`):
  **0 links** from any shipped page; no such file is mirrored into `site/`.
  Repository-doc references that have no student-facing equivalent are
  de-linked to inline code text — visible, honest, non-navigating.

## 4. Accessibility — **PASS**

Per-page audit over all 97 pages: `lang="en"`, viewport meta, labelled
primary nav, skip link, `aria-current` on the active section (section-aware
for sub-pages), one semantic `<h1>` per page, `:focus-visible` outlines,
`<main>` landmark — **0 defects**. No images are used, so no alt-text debt.

## 5. Responsive rendering — **PASS**

Verified live in the browser preview: 40rem-wide rendering shows the wrapped
nav, single-column flow, and horizontally scrollable tables (screenshot
inspected on home, resources, and a lecture page). Breakpoints: ≤64rem
(tablet), ≤40rem (phone), plus a print stylesheet that hides chrome.

## 6. Syntax highlighting — **PASS**

`site.js` (linted with `node --check`, functionally exercised in Node
against a C++ sample: keywords, comments, strings, numbers, preprocessor all
class correctly) is referenced by every page; 66 pages carry code blocks.
Blocks without C++ punctuation (shell commands) are intentionally skipped.

## 7. Structural rendering checks — **PASS**

Live-DOM verification on a lecture page: correct document title, single
`<h1>` with the full lecture title (a title-truncation defect that collapsed
titles to "L01 · L01" was found and fixed), H2 sections in order, numbered
lists render as true `<ol>` sequences with wrapped lines merged into their
items (a list-splitting defect was found and fixed).

## 8. Placeholder content — **PASS**

No "TBD"/"placeholder"/"lorem" sections are shipped; pages whose source
markdown is complete render complete. Unmapped repository documents appear
only as de-linked code text, never as dead links or empty sections.

---

## Overall: **PASS**

Nothing committed, pushed, or deployed; the site is a local build under
`website/site/`.
