# Toolchain Setup — Students

**Audience:** students (also used by instructors to prepare lab machines).
**Goal:** from zero to a running C++17 program in under 30 minutes.

## 0. What you need

1. A C++17 compiler (pick your OS below).
2. An editor — we standardize on **VS Code** with the Microsoft C/C++
   extension (any editor works; the course shows VS Code).

## 1. Windows

Two supported options; pick **one**.

### Option A — MSYS2 / MinGW-w64 (recommended for this course)

1. Install MSYS2 from <https://www.msys2.org/> following its steps 1–3.
2. In the **MSYS2 UCRT64** shell:

   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```

3. Add `C:\msys64\ucrt64\bin` to your Windows `Path` (Settings → search
   "environment variables" → Path → New).
4. Open a **new** PowerShell/VS Code window and verify:

   ```bash
   g++ --version
   ```

### Option B — Visual Studio (Community)

1. Install Visual Studio Community from <https://visualstudio.microsoft.com/>.
2. In the installer, select the **"Desktop development with C++"** workload.
3. Build with the *x64 Native Tools Command Prompt*:

   ```bash
   cl /std:c++17 /W4 /EHsc hello_world.cpp
   ```

   MSVC flag mapping: `/std:c++17` ↔ `-std=c++17`, `/W4` ↔ `-Wall -Wextra`.

## 2. macOS

1. Install the command-line tools (Terminal):

   ```bash
   xcode-select --install
   ```

2. Verify:

   ```bash
   clang++ --version
   ```

   Apple clang understands `-std=c++17` directly.

## 3. Linux (Debian/Ubuntu example)

```bash
sudo apt update
sudo apt install -y build-essential gdb
g++ --version
```

(Fedora: `sudo dnf install gcc-c++ gdb`; Arch: `sudo pacman -S gcc gdb`.)

## 4. Editor: VS Code in 4 steps

1. Install VS Code: <https://code.visualstudio.com/>.
2. Install the **C/C++** extension (publisher: Microsoft).
3. Open your course folder (`File → Open Folder`).
4. Create `hello_world.cpp`, press **F5**, choose **C++ (GDB/LLDB)** — the
   extension generates a build task. If you prefer the terminal:

   ```bash
   g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello
   ./hello
   ```

## 5. Verify your setup (do this now)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic hello_world.cpp -o hello
./hello
```

Expected output ends with something like `Hello, world!`. If any step fails,
check the troubleshooting table below or bring the exact error text to office
hours — that text is the first debugging skill the course teaches.

| Symptom | Likely cause | Fix |
|---|---|---|
| `g++: command not found` | PATH missing (Windows) | Redo Option A step 3; open a NEW terminal |
| `'cl' is not recognized` | Used plain terminal with VS | Use the x64 Native Tools prompt |
| `undefined reference to main` | Compiled the wrong/no file | Compile the file that has `main()` |
| Program builds but window closes instantly | Some IDEs close console | Run from a terminal |

## 6. Why the course standardizes the command line first

GUI build systems hide the three error classes the course teaches
(compile/link/runtime). The one-line `g++` command keeps cause and effect
visible; IDE projects are introduced as convenience, never as a prerequisite.

## 7. Verify-a-compiler matrix (instructors)

| OS | Default course compiler | C++17 flag |
|---|---|---|
| Windows | g++ 13 (MSYS2 UCRT64) | `-std=c++17` |
| Windows (alt) | MSVC 19.x | `/std:c++17` |
| macOS | Apple clang 15+ | `-std=c++17` |
| Linux | gcc 12+ | `-std=c++17` |

All course code compiles warning-free on every row of this matrix
(see the compile contract in [CPP_STANDARD.md](CPP_STANDARD.md) § 3).
