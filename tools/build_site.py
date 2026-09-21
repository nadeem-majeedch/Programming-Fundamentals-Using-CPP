#!/usr/bin/env python3
"""Website generator for the Programming Fundamentals Using C++ course.

Converts course Markdown (the single source of truth) into a small, static,
dependency-free website under website/site/. Deterministic: same repo state
produces the same site. Re-run after content edits; never hand-edit site/.

Usage:  python tools/build_site.py            (from repository root)
"""
import html
import json
import os
import re
import shutil

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "website", "site")

# ---------------------------------------------------------------- markdown --

def md_to_html(md):
    """Small, predictable Markdown subset renderer (headings, tables, lists,
    fenced code, blockquotes, emphasis, links, hr). Repo markdown is
    well-formed and machine-generated, so this stays deliberately simple."""

    def inline(s):
        s = html.escape(s, quote=False)
        s = re.sub(r"`([^`]+)`", r"<code>\1</code>", s)
        s = re.sub(r"\[([^\]]+)\]\(([^)]+)\)", _pf_link, s)
        s = re.sub(r"\*\*([^*]+)\*\*", r"<strong>\1</strong>", s)
        s = re.sub(r"(?<!\w)\*([^*\n]+)\*(?!\w)", r"<em>\1</em>", s)
        return s

    out = []
    lines = md.splitlines()
    i, n = 0, len(lines)
    in_code = False
    code_lang = ""
    code_buf = []
    while i < n:
        line = lines[i]
        if line.strip().startswith("```"):
            if not in_code:
                in_code = True
                code_lang = line.strip()[3:].strip()
                code_buf = []
            else:
                in_code = False
                lang = f" class=\"language-{html.escape(code_lang)}\"" if code_lang else ""
                out.append(f"<pre><code{lang}>{html.escape(chr(10).join(code_buf))}</code></pre>")
            i += 1
            continue
        if in_code:
            code_buf.append(line)
            i += 1
            continue

        if not line.strip():
            i += 1
            continue
        if line.strip() in ("---", "***", "___"):
            out.append("<hr>")
            i += 1
            continue

        m = re.match(r"^(#{1,4})\s+(.*)$", line)
        if m:
            level = len(m.group(1))  # page h1 is supplied by the layout
            text = m.group(2).strip()
            slug = re.sub(r"[^a-z0-9]+", "-", text.lower()).strip("-")
            out.append(f'<h{level} id="{slug}">{inline(text)}</h{level}>')
            i += 1
            continue

        if line.lstrip().startswith(">"):
            buf = []
            while i < n and lines[i].lstrip().startswith(">"):
                buf.append(lines[i].lstrip()[1:].strip())
                i += 1
            out.append("<blockquote>" + inline(" ".join(buf)) + "</blockquote>")
            continue

        # table
        if "|" in line and i + 1 < n and re.match(r"^\s*\|?[\s:|-]+\|[\s:|-]*$", lines[i + 1]):
            def cells(row):
                row = row.strip().strip("|")
                return [c.strip() for c in row.split("|")]
            header = cells(line)
            i += 2
            rows = []
            while i < n and "|" in lines[i] and lines[i].strip():
                rows.append(cells(lines[i]))
                i += 1
            thead = "<tr>" + "".join(f"<th>{inline(c)}</th>" for c in header) + "</tr>"
            body = "".join(
                "<tr>" + "".join(f"<td>{inline(c)}</td>" for c in row) + "</tr>"
                for row in rows)
            out.append(f"<table><thead>{thead}</thead><tbody>{body}</tbody></table>")
            continue

        m = re.match(r"^(\s*)[-*]\s+(.*)$", line)
        if m:
            items = []
            while i < n:
                m2 = re.match(r"^(\s*)[-*]\s+(.*)$", lines[i])
                if not m2:
                    break
                parts = [m2.group(2)]
                i += 1
                # absorb wrapped continuation lines (indented, not new items)
                while (i < n and lines[i].strip()
                       and re.match(r"^\s{2,}", lines[i])
                       and not re.match(r"^\s*(?:[-*]|\d+[.)])\s+", lines[i])):
                    parts.append(lines[i].strip())
                    i += 1
                items.append(" ".join(parts))
            out.append("<ul>" + "".join(f"<li>{inline(t)}</li>" for t in items) + "</ul>")
            continue

        m = re.match(r"^\s*(\d+)[.)]\s+(.*)$", line)
        if m:
            items = []
            while i < n:
                m2 = re.match(r"^\s*(\d+)[.)]\s+(.*)$", lines[i])
                if not m2:
                    break
                parts = [m2.group(2)]
                i += 1
                while (i < n and lines[i].strip()
                       and re.match(r"^\s{2,}", lines[i])
                       and not re.match(r"^\s*(?:[-*]|\d+[.)])\s+", lines[i])):
                    parts.append(lines[i].strip())
                    i += 1
                items.append(" ".join(parts))
            out.append("<ol>" + "".join(f"<li>{inline(t)}</li>" for t in items) + "</ol>")
            out.append("</ol>")
            continue

        # paragraph
        buf = [line.strip()]
        i += 1
        while i < n and lines[i].strip() and not re.match(r"^(#{1,4}\s|\s*[-*]\s|\s*\d+[.)]\s|\||>|```|---$)", lines[i]):
            buf.append(lines[i].strip())
            i += 1
        out.append("<p>" + inline(" ".join(buf)) + "</p>")
    return "\n".join(out)


def strip_h1(md):
    return re.sub(r"^#.*?\n", "", md, count=1)


def _pf_link(m):
    """Convert an inline markdown link to HTML; repo-relative .md links become
    root-anchored pf: URIs so they can be resolved site-wide after the build
    (or de-linked honestly if no site equivalent exists)."""
    text, href = m.group(1), m.group(2)
    trailing = "/" if href.endswith("/") else ""
    if (href.endswith((".md", "/")) and not href.startswith(("http://", "https://", "pf:"))):
        parts = [p for p in href.split("/") if p not in (".", "")] if "/" in href else [href]
        if ".." in parts:
            while parts and parts[0] == "..":
                parts.pop(0)
        href = "pf:" + "/".join(parts) + trailing
    return f'<a href="{href}">{text}</a>'


def read(rel):
    with open(os.path.join(ROOT, rel), encoding="utf-8") as f:
        return f.read()

# ------------------------------------------------------------------ layout --

CSS = ":root{--ink:#1a2433;--muted:#5b6b7f;--paper:#fbfaf7;--card:#ffffff;--line:#e4e1d8;--accent:#1d5c99;--accent-ink:#ffffff;--ok:#1a7f4b;--code-bg:#f2f1ec;--mono:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace}*{box-sizing:border-box}html{scroll-behavior:smooth}body{margin:0;font-family:Georgia,'Times New Roman',serif;font-size:17px;line-height:1.65;color:var(--ink);background:var(--paper)}a{color:var(--accent)}a:hover{text-decoration:underline}code,pre{font-family:var(--mono);font-size:.85em}code{background:var(--code-bg);padding:.1em .3em;border-radius:3px}pre{background:var(--code-bg);border:1px solid var(--line);border-radius:6px;padding:.9rem 1rem;overflow-x:auto;line-height:1.5}pre code{background:none;padding:0}header.site{background:var(--accent);color:var(--accent-ink);padding:.7rem 1rem}header.site .wrap{display:flex;flex-wrap:wrap;align-items:center;gap:.4rem 1.2rem;max-width:72rem;margin:0 auto}header.site .brand{font-family:var(--mono);font-weight:700;font-size:1.02rem;text-decoration:none;color:inherit;white-space:nowrap}header.site nav ul{list-style:none;display:flex;flex-wrap:wrap;gap:.15rem .55rem;margin:0;padding:0;font-family:var(--mono);font-size:.8rem}header.site nav a{color:var(--accent-ink);text-decoration:none;opacity:.92;padding:.28rem .4rem;border-radius:4px}header.site nav a:hover,header.site nav a[aria-current=page]{opacity:1;background:rgba(255,255,255,.18);text-decoration:none}main{max-width:72rem;margin:0 auto;padding:1.6rem 1rem 3rem}main.narrow{max-width:52rem}.breadcrumbs{font-family:var(--mono);font-size:.78rem;color:var(--muted);margin-bottom:1.1rem}.breadcrumbs a{color:var(--muted)}h1{font-size:1.9rem;line-height:1.25;margin:.2rem 0 1rem}h1.page-title{margin-top:0}h2{font-size:1.35rem;margin:2rem 0 .6rem;padding-bottom:.25rem;border-bottom:2px solid var(--line)}h3{font-size:1.08rem;margin:1.4rem 0 .4rem}h4{font-size:.98rem;margin:1.1rem 0 .3rem}table{border-collapse:collapse;width:100%;margin:.8rem 0;font-size:.92rem}th,td{border:1px solid var(--line);padding:.45rem .6rem;text-align:left;vertical-align:top}thead th{background:#efede6;font-family:var(--mono);font-size:.8rem}tbody tr:nth-child(even){background:#f7f6f1}blockquote{margin:1rem 0;padding:.6rem 1rem;border-left:4px solid var(--accent);background:var(--card);color:var(--muted)}ul,ol{padding-left:1.4rem}li{margin:.2rem 0}hr{border:none;border-top:1px solid var(--line);margin:2rem 0}.cardgrid{display:grid;grid-template-columns:repeat(auto-fill,minmax(15rem,1fr));gap:1rem;margin:1rem 0}.cardgrid section{background:var(--card);border:1px solid var(--line);border-radius:8px;padding:1rem 1.1rem}.cardgrid h2,.cardgrid h3{margin:.1rem 0 .4rem;border:none;font-size:1rem}.cardgrid p{margin:.2rem 0;font-size:.9rem;color:var(--muted)}.lede{font-size:1.08rem;color:var(--muted);max-width:44rem}.pager{display:flex;justify-content:space-between;gap:1rem;margin-top:2.4rem;padding-top:1rem;border-top:1px solid var(--line);font-family:var(--mono);font-size:.82rem}.pager span{color:var(--muted)}.tag{display:inline-block;font-family:var(--mono);font-size:.72rem;background:#efede6;border:1px solid var(--line);border-radius:4px;padding:.06rem .45rem;color:var(--muted);margin-left:.4rem;vertical-align:middle}footer.site{border-top:1px solid var(--line);color:var(--muted);font-family:var(--mono);font-size:.78rem;padding:1rem;text-align:center}footer.site a{color:var(--muted)}.skip{position:absolute;left:-9999px}.skip:focus{left:.5rem;top:.5rem;background:var(--card);padding:.4rem .8rem;z-index:10;border:2px solid var(--accent)}:focus-visible{outline:2px solid var(--accent);outline-offset:2px}a:focus-visible{outline-offset:3px}.tok-c{color:#7a8288;font-style:italic}.tok-s{color:#a03b3b}.tok-n{color:#1a6b47}.tok-k{color:#1d5c99;font-weight:600}.tok-p{color:#7a5c99}@media(max-width:64rem){body{font-size:16px}h1{font-size:1.6rem}main{padding:1.2rem .8rem 2.5rem}header.site nav ul{gap:.05rem .4rem}header.site nav a{padding:.32rem .38rem;font-size:.76rem}table{font-size:.84rem;display:block;overflow-x:auto}.cardgrid{grid-template-columns:repeat(auto-fill,minmax(13rem,1fr))}}@media(max-width:40rem){body{font-size:15.5px}h1{font-size:1.45rem}header.site .wrap{gap:.2rem .6rem}header.site nav a{padding:.34rem .42rem;font-size:.78rem}}@media print{header.site,footer.site,.breadcrumbs,.pager{display:none}body{background:#fff;font-size:11pt}pre,table{page-break-inside:avoid}}"

PAGES = [
    ("index.html", "Home", None),
    ("overview.html", "Overview", "overview.md"),
    ("outcomes.html", "Outcomes", "outcomes.md"),
    ("schedule.html", "Schedule", "schedule.md"),
    ("lectures.html", "Lectures", "lectures.md"),
    ("labs.html", "Labs", "labs.md"),
    ("cases.html", "Case Studies", "cases.md"),
    ("exercises.html", "Exercises", "exercises.md"),
    ("assignments.html", "Assignments", "assignments.md"),
    ("projects.html", "Projects", "projects.md"),
    ("resources.html", "Resources", "resources.md"),
    ("instructor.html", "Instructor Info", "instructor.md"),
]


def page(href):
    return href


# Public site URL base (no trailing slash). GitHub Pages hosts this project
# under /<repo-name>/; every page emits a matching <link rel="canonical">.
SITE_BASE_URL = "https://nadeem-majeedch.github.io/Programming-Fundamentals-Using-CPP"


def render(title, body_html, narrow=False, active=None, depth=0, canonical_frag=""):
    up = "../" * depth  # site-root-relative chrome must work from any depth
    # canonical path fragment ({FRAGMENT} is replaced by write_page for anchors)
    site_path = active or "index.html"
    # sub pages mark their top-level section (e.g. lectures/... -> Lectures)
    section = (active.split("/")[0] + ".html") if active and "/" in active else active
    nav = "".join(
        f'<li><a href="{up}{p[0]}"{" aria-current=\"page\"" if active == p[0] or section == p[0] else ""}>{p[1]}</a></li>'
        for p in PAGES)
    crumbs = f'<nav class="breadcrumbs" aria-label="Breadcrumb"><a href="{up}index.html">Home</a> › {html.escape(title)}</nav>' if active != "index.html" else ""
    cls = "narrow" if narrow else ""
    page_h1 = "Programming Fundamentals Using C++" if active == "index.html" else html.escape(title)
    return f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{html.escape(title)} · Programming Fundamentals Using C++</title>
<meta name="description" content="Programming Fundamentals Using C++ — a 16-week, 32-lecture first course in programming for university students.">
<link rel="canonical" href="{SITE_BASE_URL}/{site_path}{canonical_frag}">
<link rel="stylesheet" href="{up}styles.css">
<script src="{up}site.js" defer></script>
</head>
<body>
<a class="skip" href="#main">Skip to content</a>
<header class="site">
  <div class="wrap">
    <a class="brand" href="{up}index.html">Programming Fundamentals Using C++</a>
    <nav aria-label="Primary">
      <ul>{nav}</ul>
    </nav>
  </div>
</header>
<main id="main" class="{cls}">
{crumbs}
<h1 class="page-title">{page_h1}</h1>
{body_html}
<div class="pager"><span>Programming Fundamentals Using C++ · C++17 · 16 weeks</span><a href="#main" onclick="window.scrollTo({{top:0,behavior:'smooth'}});return false;">Back to top ↑</a></div>
</main>
<footer class="site">
  <p>Generated from the course repository · the repository files are the source of truth · <a href="https://isocpp.org" rel="noopener">Standard C++</a></p>
</footer>
</body>
</html>
"""


def write_page(name, title, body, narrow=False):
    page_name, _, frag = name.partition("#")
    path = os.path.join(OUT, *page_name.split("/"))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    depth = page_name.count("/")
    canonical_frag = ("#" + frag) if frag else ""
    with open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(render(title, body, narrow=narrow, active=page_name, depth=depth, canonical_frag=canonical_frag))
    print(f"  {name}")

# ------------------------------------------------------------------- pages --

# Repo-relative .md links in source markdown are normalized at conversion time
# to root-anchored `pf:` URIs (relative-depth noise removed), then resolved
# after the build: mapped targets -> site pages; files mirrored into the site
# (lecture pages, DS datasets) -> their site copy; unmapped repository docs ->
# de-linked plain text. Instructor-only files are never linked from the site.
pf_map = {
    "COURSE_OVERVIEW.md": "overview.html",
    "LEARNING_OUTCOMES.md": "outcomes.html",
    "COURSE_SCHEDULE.md": "schedule.html",
    "README.md": "index.html",
    "TEACHING_GUIDE.md": "instructor.html",
    "labs/README.md": "labs.html",
    "lectures/README.md": "lectures.html",
    "case-studies/README.md": "cases.html",
    "exercises/README.md": "exercises.html",
    "assignments/README.md": "assignments.html",
    "projects/README.md": "projects.html",
    "exams/README.md": "assignments.html",
    "exams/midterm/review_guide.md": "assignments/midterm-review.html",
    "exams/final/review_guide.md": "assignments/final-review.html",
    "student/GETTING_HELP.md": "resources.html#getting-help",
    "student/README.md": "index.html",
    "resources/glossary.md": "resources.html#glossary",
    "docs/TOOLCHAIN.md": "resources.html#toolchain-setup",
    "docs/CPP_STANDARD.md": "resources.html#cpp-standard",
    "labs/resources/debug_log_template.md": "resources.html#lab-templates",
    "labs/resources/submission_template.md": "resources.html#lab-templates",
    # context-relative aliases (links written relative to docs/ or labs/)
    "CPP_STANDARD.md": "resources.html#cpp-standard",
    "TOOLCHAIN.md": "resources.html#toolchain-setup",
    "debug_log_template.md": "resources.html#lab-templates",
    "resources/debug_log_template.md": "resources.html#lab-templates",
    "resources/submission_template.md": "resources.html#lab-templates",
    # context-relative directory links
    "by_tier/": "cases.html",
    "datasets/stations/": "exercises/ds/datasets.html",
    "projects/project-01/project.md": "projects/project-01.html",
    "projects/project-02/project.md": "projects/project-02.html",
    "projects/project-03/project.md": "projects/project-03.html",
    "projects/project-04/project.md": "projects/project-04.html",
    "projects/project-05/project.md": "projects/project-05.html",
    # links written relative to projects/ in projects/README.md
    "project-01/project.md": "projects/project-01.html",
    "project-02/project.md": "projects/project-02.html",
    "project-03/project.md": "projects/project-03.html",
    "project-04/project.md": "projects/project-04.html",
    "project-05/project.md": "projects/project-05.html",
    "instructor/assessment-rubrics/project.md": "projects.html",
    # review guides cross-link each other relative to exams/<name>/
    "midterm/review_guide.md": "assignments/midterm-review.html",
    "final/review_guide.md": "assignments/final-review.html",
}

def body_from_md(rel, drop_first_heading=True):
    md = read(rel)
    if drop_first_heading:
        md = strip_h1(md)
    return md_to_html(md)


def build_home():
    md = read("COURSE_OVERVIEW.md")
    # pull the catalog description (section 1.1 body) for the lede
    m = re.search(r"### 1\.1 Description\n\n(.*?)\n\n", md, re.S)
    lede = m.group(1).strip() if m else "A first course in structured programming using C++."
    cards = [
        ("Start here", "overview.html", "What the course is, who it serves, how it works, and the grading plan."),
        ("16-week schedule", "schedule.html", "All 32 lectures, module by module, with assessments and the weekly rhythm."),
        ("Lecture materials", "lectures.html", "Planning notes and materials for every one of the 32 lectures."),
        ("Laboratory manual", "labs.html", "16 supervised labs: guided tasks, debugging drills, rubrics."),
        ("Case studies", "cases.html", "Problem-solving cases discussed in class, beginner to capstone."),
        ("Exercises", "exercises.html", "The exercise bank plus the data-science track, with datasets."),
        ("Assignments", "assignments.html", "Eight programming assignments with specs and due weeks."),
        ("Projects", "projects.html", "Five mini-projects, from grade calculator to the integrated capstone."),
        ("Resources", "resources.html", "Toolchain setup, glossary, examples, and study help."),
        ("Instructor information", "instructor.html", "Who teaches this, how to get help, office-hours and support model."),
    ]
    grid = "".join(
        f'<section><h3><a href="{h}">{t}</a></h3><p>{d}</p></section>'
        for t, h, d in cards)
    body = f"""<p class="lede">{inline_keep(lede)}</p>
<div class="cardgrid">
{grid}
</section>
</div>
<h2 id="at-a-glance">At a glance</h2>
<table>
<tr><th>Field</th><th>Value</th></tr>
<tr><td>Level</td><td>Undergraduate year 1 — no prior programming assumed</td></tr>
<tr><td>Structure</td><td>16 weeks · 16 modules · 32 lectures × 2 h + labs</td></tr>
<tr><td>Language</td><td>C++ (C++17 standard), portable across Windows/macOS/Linux</td></tr>
<tr><td>Audiences</td><td>BS Computer Science · BS Data Science · general undergraduates</td></tr>
<tr><td>Assessment</td><td>Assignments · labs · quizzes · midterm · capstone project · final</td></tr>
</table>
<h2 id="the-learning-pathway">The learning pathway</h2>
<ol>
<li><strong>Set up</strong> — install a compiler and run your first program (<a href="resources.html">Resources</a>).</li>
<li><strong>Follow the modules</strong> — two lectures per week; skim the week's plan before lecture (<a href="schedule.html">Schedule</a>).</li>
<li><strong>Practice the same week</strong> — examples re-run alone, in-class drills, then homework (<a href="exercises.html">Exercises</a>).</li>
<li><strong>Build upward</strong> — labs every other week; projects P1–P4 as bands complete (<a href="labs.html">Labs</a>, <a href="projects.html">Projects</a>).</li>
<li><strong>Consolidate</strong> — review guides before the midterm and final (<a href="assignments.html">Assignments &amp; exams</a>).</li>
</ol>"""
    write_page("index.html", "Home", body)


def inline_keep(s):
    s = html.escape(s, quote=False)
    s = re.sub(r"\*\*([^*]+)\*\*", r"<strong>\1</strong>", s)
    s = re.sub(r"(?<!\w)\*([^*\n]+)\*(?!\w)", r"<em>\1</em>", s)
    s = re.sub(r"`([^`]+)`", r"<code>\1</code>", s)
    return s


def build_generated(page_file, title, source_rels, intro=""):
    parts = []
    if intro:
        parts.append(f'<p class="lede">{intro}</p>')
    for rel in source_rels:
        md = read(rel)
        md = strip_h1(md)
        # make relative repo links inert-but-honest: point them at the repo path listing
        parts.append(md_to_html(md))
    write_page(page_file, title, "\n".join(parts))


def rel_links(markdown_text, base_depth):
    pass


def build_lectures():
    rows = []
    for w in range(1, 17):
        wk = f"week_{w:02d}"
        l1, l2 = 2 * w - 1, 2 * w
        rows.append((wk, l1, l2))
    cards = []
    for wk, l1, l2 in rows:
        md = read(f"lectures/{wk}/lecture_{l1:02d}.md")
        title = re.search(r"^#\s+(.+)$", md, re.M)
        title = title.group(1).strip() if title else wk

        l1f = f"lectures/{wk}/lecture_{l1:02d}.html"
        l2f = f"lectures/{wk}/lecture_{l2:02d}.html"
        # lecture 2 title
        md2 = read(f"lectures/{wk}/lecture_{l2:02d}.md")
        t2 = re.search(r"^#\s+(.+)$", md2, re.M)
        t2 = t2.group(1).strip() if t2 else f"Lecture {l2}"
        cards.append(f"""<section>
<h3>Week {w} · <a href="{l1f}">{html.escape(title)}</a></h3>
<p>L{l1}: {html.escape(title)}<br>L{l2}: <a href="{l2f}">{html.escape(t2)}</a></p>
</section>""")
    body = ('<p class="lede">Planning material for all 32 lectures, organized by week. '
            'Each lecture page carries its objectives, concept sequence, examples used, '
            'common misconceptions, and the in-class activity.</p>'
            f'<div class="cardgrid">{"".join(cards)}</div>')
    write_page("lectures.html", "Lecture Materials", body)

    # individual lecture pages
    for wk, l1, l2 in rows:
        for l in (l1, l2):
            rel = f"lectures/{wk}/lecture_{l:02d}.md"
            md = read(rel)
            title_m = re.search(r"^#\s+(.+)$", md, re.M)
            ptitle = title_m.group(1).strip() if title_m else wk
            write_page(f"lectures/{wk}/lecture_{l:02d}.html", ptitle,
                       body_from_md(rel), narrow=True)


def build_labs():
    md = read("labs/README.md")
    rows = []
    for w in range(1, 17):
        rel = f"labs/lab_manuals/lab_{w:02d}/manual.md"
        man = read(rel)
        t = re.search(r"^#\s+(.+)$", man, re.M)
        title = t.group(1).strip() if t else f"Lab {w:02d}"
        rows.append(f'<li><a href="labs/lab_{w:02d}.html">{html.escape(title)}</a></li>')
    body = (body_from_md("labs/README.md")
            + '<h2 id="the-sixteen-labs">The sixteen labs</h2><ol>' + "".join(rows) + "</ol>")
    write_page("labs.html", "Laboratory Manual", body)
    for w in range(1, 17):
        rel = f"labs/lab_manuals/lab_{w:02d}/manual.md"
        man = read(rel)
        t = re.search(r"^#\s+(.+)$", man, re.M)
        title = t.group(1).strip() if t else f"Lab {w:02d}"
        write_page(f"labs/lab_{w:02d}.html", title, body_from_md(rel), narrow=True)


def build_cases():
    tiers = ["tier1_beginner", "tier2_foundational", "tier3_intermediate",
             "tier4_advanced", "tier5_expert_introductory"]
    names = ["Tier 1 · Beginner", "Tier 2 · Foundational", "Tier 3 · Intermediate",
             "Tier 4 · Advanced", "Tier 5 · Expert Introductory"]
    links = "".join(
        f'<li><a href="cases/{t}.html">{n}</a></li>' for t, n in zip(tiers, names))
    body = (body_from_md("case-studies/README.md")
            + '<h2 id="the-five-tiers">The five tiers</h2><ul>' + links + '</ul>'
            + '<p>The data-science section supplements the main bank: '
              '<a href="cases/ds-cases.html">DS case studies (PF-DS-CS-1…8)</a>.</p>')
    write_page("cases.html", "Problem-Solving Case Studies", body)
    for t, n in zip(tiers, names):
        rel = f"case-studies/by_tier/{t}.md"
        write_page(f"cases/{t}.html", f"Case Studies · {n}", body_from_md(rel))
    write_page("cases/ds-cases.html", "Case Studies · Data Science",
               body_from_md("case-studies/data-science.md"))


def build_exercises():
    topics = sorted(f for f in os.listdir(os.path.join(ROOT, "exercises", "by_topic"))
                    if f.endswith(".md"))
    links = "".join(
        f'<li><a href="exercises/{f[:-3]}.html">{f[:-3].replace("_", " ")}</a></li>'
        for f in topics)
    ds = sorted(f for f in os.listdir(os.path.join(ROOT, "exercises", "data-science"))
                if f.startswith("DS_"))
    dslinks = "".join(
        f'<li><a href="exercises/ds/{f[:-3]}.html">{f[:-3]}</a></li>' for f in ds)
    body = (body_from_md("exercises/README.md")
            + '<h2 id="topic-banks-t01-t12">Topic banks (T01–T12)</h2><ul>' + links + '</ul>'
            + '<h2 id="data-science-track">Data-science track</h2><ul>' + dslinks + '</ul>'
            + '<p>Datasets for the DS exercises: '
              '<a href="exercises/ds/datasets.html">dataset directory with documented defects</a>.</p>')
    write_page("exercises.html", "Programming Exercises", body)
    for f in topics:
        rel = f"exercises/by_topic/{f}"
        write_page(f"exercises/{f[:-3]}.html", f"Exercises · {f[:-3].replace('_',' ')}",
                   body_from_md(rel))
    for f in ds:
        rel = f"exercises/data-science/{f}"
        write_page(f"exercises/ds/{f[:-3]}.html", f"DS Exercises · {f[:-3]}",
                   body_from_md(rel))
    write_page("exercises/ds/datasets.html", "DS Datasets",
               body_from_md("exercises/data-science/datasets/README.md"))


def build_assignments():
    items = []
    for n in range(1, 9):
        rel = f"assignments/assignment_{n:02d}/assignment.md"
        man = read(rel)
        t = re.search(r"^#\s+(.+)$", man, re.M)
        title = t.group(1).strip() if t else f"Assignment {n}"
        items.append(f'<li><a href="assignments/assignment_{n:02d}.html">{html.escape(title)}</a></li>')
        write_page(f"assignments/assignment_{n:02d}.html", title, body_from_md(rel), narrow=True)
    review = [("Midterm review guide", "exams/midterm/review_guide.md", "assignments/midterm-review.html"),
              ("Final review guide", "exams/final/review_guide.md", "assignments/final-review.html")]
    extra = "".join(f'<li><a href="{h}">{t}</a></li>' for t, _, h in review)
    for t, rel, out in review:
        write_page(out, t, body_from_md(rel), narrow=True)
    body = (body_from_md("assignments/README.md")
            + '<h2 id="the-eight-assignments">The eight assignments</h2><ol>' + "".join(items) + '</ol>'
            + '<h2 id="exam-review-guides">Exam review guides</h2><ul>' + extra + '</ul>')
    write_page("assignments.html", "Assignments & Exams", body)


def build_projects():
    items = []
    for n in range(1, 6):
        rel = f"projects/project-{n:02d}/project.md"
        man = read(rel)
        t = re.search(r"^#\s+(.+)$", man, re.M)
        title = t.group(1).strip() if t else f"Project {n}"
        items.append(f'<li><a href="projects/project-{n:02d}.html">{html.escape(title)}</a></li>')
        write_page(f"projects/project-{n:02d}.html", title, body_from_md(rel), narrow=True)
    body = (body_from_md("projects/README.md")
            + '<h2 id="the-five-projects">The five projects</h2><ol>' + "".join(items) + '</ol>')
    write_page("projects.html", "Projects", body)


def build_resources():
    items = []
    for f in sorted(os.listdir(os.path.join(ROOT, "examples"))):
        if f.endswith(".cpp"):
            code = read(f"examples/{f}")
            m = re.search(r"//\s*purpose:\s*(.+)", code)
            purpose = m.group(1).strip() if m else ""
            items.append((f, purpose, code))
    rows = "".join(
        f'<tr><td><code>{html.escape(f)}</code></td><td>{html.escape(p[:110])}</td></tr>'
        for f, p, _ in items)
    showcase = ""
    for f, p, code in items[:3]:
        showcase += f"<h3>{html.escape(f)}</h3><p>{html.escape(p)}</p>" \
                    f"<pre><code class=\"language-cpp\">{html.escape(code.strip())}</code></pre>"
    body = f"""<p class="lede">Toolchain setup, the C++ standard contract, the glossary, the example program library, lab templates, and where to get help.</p>
<h2 id="cpp-standard">The C++ standard and compiler contract</h2>
{body_from_md("docs/CPP_STANDARD.md")}
<h2 id="toolchain-setup">Toolchain setup</h2>
{body_from_md("docs/TOOLCHAIN.md")}
<h2 id="example-program-library">Example program library</h2>
<p>Every example compiles with the course contract. This table lists the full library; three complete programs are shown below.</p>
<table><thead><tr><th>File</th><th>Teaches</th></tr></thead><tbody>{rows}</tbody></table>
<h2 id="three-complete-examples">Three complete examples</h2>
{showcase}
<h2 id="lab-templates">Lab submission and debug-log templates</h2>
<p>Every lab submission uses these two templates (linked from each lab manual).</p>
{body_from_md("labs/resources/submission_template.md")}
{body_from_md("labs/resources/debug_log_template.md")}
<h2 id="glossary">Glossary</h2>
{body_from_md("resources/glossary.md")}
<h2 id="getting-help">Getting help</h2>
{body_from_md("student/GETTING_HELP.md")}"""
    write_page("resources.html", "Resources", body)


def build_instructor_info():
    body = """<p class="lede">Who teaches this course and how the support model works.
No personal contact details are published on this site — your section's
Learning Management System lists the instructor's name, office location,
and office hours for the current term.</p>
<h2 id="teaching-model">Teaching model</h2>
""" + body_from_md("TEACHING_GUIDE.md", ) + """
<h2 id="support-model">Support model</h2>
<ul>
<li><strong>Lectures:</strong> two 2-hour sessions weekly — concepts, live coding, in-class exercises.</li>
<li><strong>Labs:</strong> supervised practice weeks 2–15; TAs guide, they do not solve
(<a href="labs.html">laboratory manual</a>).</li>
<li><strong>Office hours:</strong> at least 2 hours per week per instructor and TA —
see the LMS for this term's schedule and locations.</li>
<li><strong>Stuck?</strong> Follow the 30-minute rule in the
<a href="resources.html#getting-help">getting-help guide</a>: attempt, document, then bring
your trace table to office hours.</li>
<li><strong>Study help:</strong> <a href="resources.html">glossary, examples, and toolchain docs</a>.</li>
</ul>
<h2 id="course-policies">Course policies</h2>
""" + body_from_md("COURSE_OVERVIEW.md") + """
<h2 id="contributing-and-contact">Contributing and contact</h2>
<p>Corrections and improvements to the course materials follow the repository's
contributing rules. Students: report broken links or confusing passages to
your instructor or TA — the materials improve every term from exactly such reports.</p>"""
    write_page("instructor.html", "Instructor Information", body)


def build_overview_pages():
    write_page("overview.html", "Course Overview", body_from_md("COURSE_OVERVIEW.md"))
    write_page("outcomes.html", "Learning Outcomes", body_from_md("LEARNING_OUTCOMES.md"))
    write_page("schedule.html", "16-Week Schedule", body_from_md("COURSE_SCHEDULE.md"))


# link rewriting: repo-relative markdown links inside generated pages would
# point outside website/site. Rewrite links that target known site pages to
# their site equivalents; leave others as honest relative paths (the QA step
# reports them) — but for a self-contained site we rewrite to a repo-map page.
def fix_links():
    """Resolve pf: URIs (site-root anchored) to relative links from each page.

    pf:<repo path> targets resolve in order: explicit pf_map -> mirrored site
    copies (lecture pages, DS datasets) -> None. Unresolvable targets become
    plain text (code), so the site never ships a dead link and never links
    into instructor-only material."""
    def resolve(target):
        if target in pf_map:
            return pf_map[target]
        if target.startswith("lectures/") and target.endswith(".md"):
            return target[:-3] + ".html"
        if target.startswith("exercises/data-science/datasets/"):
            rel = target[len("exercises/data-science/"):]
            return "exercises/ds/" + rel
        return None

    # copy mirrored assets into the site (byte-identical to the repo files)
    ds_src = os.path.join(ROOT, "exercises", "data-science", "datasets")
    ds_dst = os.path.join(OUT, "exercises", "ds", "datasets")
    if os.path.isdir(ds_src):
        if os.path.isdir(ds_dst):
            shutil.rmtree(ds_dst)
        shutil.copytree(ds_src, ds_dst)
        n_files = sum(len(fs) for _, _, fs in os.walk(ds_dst))
        print(f"  copied {n_files} dataset files -> exercises/ds/datasets/")

    unresolved = set()
    for dirpath, _, files in os.walk(OUT):
        for f in files:
            if not f.endswith(".html"):
                continue
            p = os.path.join(dirpath, f)
            depth = os.path.relpath(p, OUT).count(os.sep)
            up = "../" * depth
            text = open(p, encoding="utf-8").read()

            def sub(m):
                target = resolve(m.group(1))
                if target is None:
                    unresolved.add(m.group(1))
                    return m.group(0)  # leave marker; stripped below
                frag = ""
                if "#" in target:
                    target, frag = target.split("#", 1)
                href = up + target
                return f'href="{href}#{frag}"' if frag else f'href="{href}"'

            text = re.sub(r'href="pf:([^"]+)"', sub, text)
            # any leftover markers (unresolved) -> de-link to plain code text
            text = re.sub(r'<a href="pf:[^"]+">(.*?)</a>', r"<code>\1</code>", text)
            open(p, "w", encoding="utf-8", newline="\n").write(text)
    if unresolved:
        print("  de-linked (no site equivalent):", ", ".join(sorted(unresolved)))


# ------------------------------------------------- lightweight highlighter --

# The highlighter is a standalone, lintable asset (tools/site_src.js);
# it is copied verbatim into the site rather than embedded here.
def _load_site_js():
    src = os.path.join(ROOT, "tools", "site_src.js")
    with open(src, encoding="utf-8") as f:
        return f.read()


def main():
    if os.path.isdir(OUT):
        shutil.rmtree(OUT)
    os.makedirs(OUT)
    print("Building site into website/site/ …")
    build_overview_pages()
    build_home()
    build_lectures()
    build_labs()
    build_cases()
    build_exercises()
    build_assignments()
    build_projects()
    build_resources()
    build_instructor_info()
    # .nojekyll: serve everything as static files (no Jekyll processing)
    with open(os.path.join(OUT, ".nojekyll"), "w", encoding="utf-8") as f:
        f.write("")
    with open(os.path.join(OUT, "styles.css"), "w", encoding="utf-8", newline="\n") as f:
        f.write(CSS)
    with open(os.path.join(OUT, "site.js"), "w", encoding="utf-8", newline="\n") as f:
        f.write(_load_site_js())
    fix_links()
    n_html = sum(1 for _, _, fs in os.walk(OUT) for f in fs if f.endswith(".html"))
    print(f"Done: {n_html} HTML pages + styles.css")


if __name__ == "__main__":
    main()
