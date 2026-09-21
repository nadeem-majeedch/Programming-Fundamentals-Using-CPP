# Assignment 6 — Instructor Key · INSTRUCTOR-ONLY
Restricted per [../../instructor/ACCESS_CONTROL.md](../../instructor/ACCESS_CONTROL.md).
Marks: correctness 30 · postmortem 10 = **40** ✓.

**Note:** the student sheet's sample embeds a wrong intermediate claim
(diagonal "5"); the authoritative expected diagonal is **2**. Graders must
accept only tables that hand-verified 2 (or that caught and documented the
discrepancy — that is the assignment's reading-comprehension point).

## Reference solution (compiled & executed)

```cpp
// campus.cpp — Assignment 6 reference solution.
#include <iostream>
#include <iomanip>

const int DIM{20};

int totalSum(const int g[][DIM], int r, int c)
{
    int s{0};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j) s += g[i][j];
    return s;
}

void maxRow(const int g[][DIM], int r, int c, int& idx, int& tot)
{
    idx = 0;
    tot = 0;
    for (int j{0}; j < c; ++j) tot += g[0][j];
    for (int i{1}; i < r; ++i) {
        int t{0};
        for (int j{0}; j < c; ++j) t += g[i][j];
        if (t > tot) { tot = t; idx = i; }   // strict > keeps lowest index on ties
    }
}

int diagonalSum(const int g[][DIM], int r, int c)
{
    int m{(r < c) ? r : c};
    int s{0};
    for (int i{0}; i < m; ++i) s += g[i][i];
    return s;
}

int borderSum(const int g[][DIM], int r, int c)
{
    int s{0};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j)
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1) s += g[i][j];
    return s;
}

int countZeros(const int g[][DIM], int r, int c)
{
    int z{0};
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j) if (g[i][j] == 0) ++z;
    return z;
}

int main()
{
    int grid[DIM][DIM]{};
    int r{}, c{};
    if (!(std::cin >> r >> c) || r < 1 || r > DIM || c < 1 || c > DIM) {
        std::cout << "bad dims\n";
        return 1;
    }
    for (int i{0}; i < r; ++i)
        for (int j{0}; j < c; ++j) {
            if (!(std::cin >> grid[i][j])) { std::cout << "bad cell\n"; return 1; }
        }

    int idx{}, tot{};
    maxRow(grid, r, c, idx, tot);
    std::cout << "sum     : " << totalSum(grid, r, c) << '\n';
    std::cout << "maxrow  : " << idx << ' ' << tot << '\n';
    std::cout << "diagonal: " << diagonalSum(grid, r, c) << '\n';
    std::cout << "border  : " << borderSum(grid, r, c) << '\n';
    std::cout << "zeros   : " << countZeros(grid, r, c) << '\n';
    return 0;
}
```

## Verified runs

| Input | Output |
|---|---|
| `3 4 / 1 2 3 4 / 5 0 0 2 / 9 1 1 1` | `29 / 2 12 / 2 / 27 / 2` |
| `1 1 / 7` | `7 / 0 7 / 7 / 7 / 0` |
| `1 5 / 1 2 3 4 5` | `15 / 0 15 / 1 / 15 / 0` (whole grid is border) |
| `2 2 / 5 5 / 5 5` | `20 / 0 10 / 5 / 20 / 0` (row tie → row 0) |
| `3 3 / 0 0 0 / 0 0 0 / 0 0 0` | `0 / 0 0 / 0 / 0 / 9` |

## Hidden-case classes

- 1×1: everything is border and diagonal.
- R×1 / 1×C strips: border = total.
- Row-tie → lowest index (strict `>` check).
- Diagonal on non-square (min clamp).
- Corner counted once (predicate form, not four loops).

## Common student defects

1. Four-loop border → corners twice (the exact L20 bug).
2. Diagonal loop `i < r` on non-square → OOB.
3. `>=` in maxRow → picks highest tied index.
4. Signature `int g[][]` → compile error; the DIM rule exists for this.
