# tools/ — Repository Maintenance Scripts

Scripts for **authors and maintainers** while authoring content. Students do
not need anything here.

## Scripts

| Script | Purpose | Usage |
|---|---|---|
| `check_links.sh` | verify all relative markdown links in the repository resolve to existing files | `bash tools/check_links.sh` |
| `new_week.sh` | (planned) scaffold a week's lecture-note stubs from the template | — ⏳ planned |

`check_links.sh` extracts `[text](target)` links from every `.md` file and
fails on any relative target that does not exist. It intentionally skips
`http(s)` and `mailto:` targets, and it understands `#anchors` by checking the
file only. Run it before every contribution
([../CONTRIBUTING.md](../CONTRIBUTING.md) § 4).

## Planned (see [../docs/CONTENT_ROADMAP.md](../docs/CONTENT_ROADMAP.md))

- `new_week.sh` — create `lectures/week_NN/` stubs from the note template.
- `build_examples.sh` — compile every `examples/*.cpp` with the compile
  contract; fail on any warning.

## Conventions

- POSIX `bash`, no dependencies beyond `git bash`/standard Unix tools
  (works on the Windows Git Bash used by the course authors).
- Scripts print `OK` and exit 0 on success; print the failing item and exit 1
  otherwise.
