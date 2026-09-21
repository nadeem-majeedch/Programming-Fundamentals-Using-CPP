# docs/ — Repository Standards & Documentation

Project-level standards that govern **all content** in this repository.
Every author and contributor is expected to have read these before writing
lecture notes or code.

| Document | Purpose |
|---|---|
| [CPP_STANDARD.md](CPP_STANDARD.md) | Which C++ standard the course teaches, why, and the exact compiler flags contract |
| [TOOLCHAIN.md](TOOLCHAIN.md) | Compiler + editor setup for Windows, macOS, Linux (student-facing instructions) |
| [CODE_STYLE.md](CODE_STYLE.md) | The course C++ style guide used in every rubric and code review |
| [CONTENT_ROADMAP.md](CONTENT_ROADMAP.md) | What exists now and the ordered plan for authoring the remaining content |
| [CHANGELOG.md](CHANGELOG.md) | Dated change log for course materials |
| [cpp_core_guidelines.md](cpp_core_guidelines.md) | Author-facing notes on applying selected Core Guidelines to beginner teaching |

## Scope

`docs/` documents the *repository*, not the C++ language. Language reference
material for students lives in [resources/](../resources/README.md); per-lecture
explanations live in [lectures/](../lectures/README.md).

## Conventions for this directory

- File names: lowercase `snake_case.md`.
- Every document states its **audience** (student / instructor / author) at the top.
- Standards here are enforced in review (see
  [../CONTRIBUTING.md](../CONTRIBUTING.md) § 7); disputes are resolved by
  editing the document, not by exception.
- Student-facing entries in this folder (TOOLCHAIN.md) must stay installable
  without instructor help.

## Related documents

- Repository map and directory purposes: [../README.md](../README.md)
- Teaching policy: [../TEACHING_GUIDE.md](../TEACHING_GUIDE.md)
- Contribution rules: [../CONTRIBUTING.md](../CONTRIBUTING.md)
