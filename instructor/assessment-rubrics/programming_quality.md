# Rubric — Programming Quality (0–10 per artifact)

Applied to assignments, the practical, and the project. Graders score each line;
no half-points.

| Points | Criterion |
|---|---|
| 0–2 | **Naming & readability** — names state purpose; consistent style per `docs/STYLE_GUIDE.md`; no dead code |
| 0–2 | **Structure** — appropriate functions with single purposes; no duplicated blocks; main reads as an outline |
| 0–2 | **Safety & guards** — inputs validated at the boundary; array bounds exact; no unexplained raw ownership (vector by default) |
| 0–2 | **Const-correctness & passing modes** — `const` on read-only parameters; references for out/in-out; pointers only where justified |
| 0–2 | **Comments** — contract comments (pre/post) on every non-trivial function; comments explain *why*, not *what* |

## Score bands

- **9–10** — usable as a class model after trivial renaming.
- **7–8** — correct and clean; minor style lapses.
- **5–6** — works but structure or guards are weak in one dimension.
- **3–4** — works; two-plus dimensions weak (e.g., monolith + no validation).
- **0–2** — does not compile (caps artifact at correctness floor anyway) or unreadable.

## Calibration anchors

- A `monolith.cpp`-style 80-line main = structure ≤ 1.
- A solution with `double&` used where a value return was cleaner but explained = passing modes 1–2 (judgment documented).
- Missing precondition on `safeDivide` = comments −1, safety unchanged (guards may still exist in code).
