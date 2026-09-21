# website/ — Course Website (generated)

A complete, dependency-free static website for the course, generated from the
repository markdown (the single source of truth) by
[../tools/build_site.py](../tools/build_site.py).

## Deployment (GitHub Pages)

The site deploys automatically to
**https://nadeem-majeedch.github.io/Programming-Fundamentals-Using-CPP/**
via GitHub Actions on every push to `main`
([.github/workflows/pages.yml](../.github/workflows/pages.yml)): build →
upload `website/site` as the Pages artifact → deploy. One-time setup after
the first run: **Settings → Pages → Source: “GitHub Actions”**. The build is
zero-dependency (Python 3 stdlib only), so the workflow needs no package
installation.

Pages serves project sites under the repository subpath. The site is built
for this: every link is relative, no absolute-root paths exist anywhere, and
`.nojekyll` is emitted so `site.js` is served as-is. Each page carries a
canonical URL for the production subpath (`SITE_BASE_URL` in
`tools/build_site.py`).

## Build (local)

```bash
python tools/build_site.py     # from the repository root
```

Output lands in `website/site/` — **97 HTML pages + styles.css + site.js** —
and is fully self-contained (open `site/index.html` in a browser, or serve the
folder with any static file server; a plain `python -m http.server` from
inside `site/` works). Re-run after any content edit; never hand-edit
`website/site/`.

## What the site contains

| Section | Page | Source |
|---|---|---|
| Course home | `index.html` | `COURSE_OVERVIEW.md` (lede) + curated cards |
| Overview / outcomes / schedule | `overview.html`, `outcomes.html`, `schedule.html` | root documents |
| Lecture materials | `lectures.html` + 32 lecture pages | `lectures/week_NN/lecture_MM.md` |
| Laboratory manual | `labs.html` + 16 lab pages | `labs/lab_manuals/lab_NN/manual.md` |
| Case studies | `cases.html` + 5 tier pages + DS page | `case-studies/` |
| Exercises | `exercises.html` + 12 topic banks + 3 DS parts | `exercises/by_topic/`, `exercises/data-science/` |
| Assignments | `assignments.html` + 8 specs + 2 review guides | `assignments/`, `exams/*/review_guide.md` |
| Projects | `projects.html` + 5 specs | `projects/project-0N/project.md` |
| Resources | `resources.html` | `docs/CPP_STANDARD.md`, `docs/TOOLCHAIN.md`, `resources/glossary.md`, example library, lab templates, getting-help |
| Instructor info | `instructor.html` | `TEACHING_GUIDE.md` + support model |

Sub-pages: `lectures/`, `labs/`, `cases/`, `exercises/` (incl. mirrored
`exercises/ds/datasets/`), `assignments/`, `projects/`.

## Design system (in `styles.css`, embedded in the generator)

- **Typography:** serif body (Georgia stack), monospace UI/nav/code — an
  academic, textbook feel with no web fonts.
- **Colors:** warm paper background, ink text, one blue accent; token colors
  for syntax highlighting (`.tok-k/.tok-c/.tok-s/.tok-n/.tok-p`).
- **Responsive:** three breakpoints (≤64rem tablet, ≤40rem phone, print);
  tables scroll horizontally on narrow screens; nav wraps gracefully.
- **Accessibility:** `lang`, landmark `<main>`, labelled primary nav,
  `aria-current` (section-aware), skip link, visible `:focus-visible` styles,
  semantic single-H1 headings, no images (so no alt debt).
- **Syntax highlighting:** `site.js` (source: `tools/site_src.js`) — a small
  dependency-free C++ tokenizer applied to `<pre><code>` blocks.

## Integrity rules

- The site is **regenerated, never hand-edited**; repository markdown wins.
- Student-facing only: no instructor-only content is mirrored, and no links
  target restricted folders (`instructor/exams`, `answer_keys`,
  `exercise_solutions`, `projects/`, `case_studies/`,
  `assessment-rubrics/`) — links to such documents are de-linked to plain
  code text by the build, never silently dropped and never leaked.
- QA evidence: [../docs/WEBSITE_QA.md](../docs/WEBSITE_QA.md).
