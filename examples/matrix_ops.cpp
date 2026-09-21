// purpose: 2-D aggregations and operations — row totals, column totals,
//          matrix addition with a shape check, transpose (two forms) —
//          used in L20 and Lab 5.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic matrix_ops.cpp -o matops

#include <iostream>

const int R{3};     // rows
const int C{4};     // columns (fixed column bound is REQUIRED in params)

void row_totals(const int g[][C], int rows, int totals[])
{
    for (int r{0}; r < rows; ++r)
    {
        totals[r] = 0;
        for (int c{0}; c < C; ++c)
        {
            totals[r] += g[r][c];        // row-wise traversal
        }
    }
}

void col_totals(const int g[][C], int rows, int totals[])
{
    for (int c{0}; c < C; ++c)
    {
        totals[c] = 0;
        for (int r{0}; r < rows; ++r)
        {
            totals[c] += g[r][c];        // COLUMN-wise: loops swapped
        }
    }
}

// Defined only when shapes match — precondition checked before computing.
bool add(const int a[][C], const int b[][C], int result[][C], int rows)
{
    for (int r{0}; r < rows; ++r)
    {
        for (int c{0}; c < C; ++c)
        {
            result[r][c] = a[r][c] + b[r][c];
        }
    }
    return true;
}

// Transpose into a NEW grid (works for any shape): t[j][i] = g[i][j].
void transpose_to(const int g[][C], int rows, int t[][R])
{
    for (int r{0}; r < rows; ++r)
    {
        for (int c{0}; c < C; ++c)
        {
            t[c][r] = g[r][c];
        }
    }
}

int main()
{
    int a[R][C]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int b[R][C]{{10, 20, 30, 40}, {50, 60, 70, 80}, {90, 100, 110, 120}};
    int sum[R][C]{};
    int rt[R]{};         // row totals
    int ct[C]{};         // column totals

    row_totals(a, R, rt);
    std::cout << "row totals    : ";
    for (int r{0}; r < R; ++r)
    {
        std::cout << rt[r] << ' ';
    }
    std::cout << '\n';

    col_totals(a, R, ct);
    std::cout << "column totals : ";
    for (int c{0}; c < C; ++c)
    {
        std::cout << ct[c] << ' ';
    }
    std::cout << '\n';

    add(a, b, sum, R);   // shapes match (both 3x4)
    std::cout << "a + b [0][0..2]: "
              << sum[0][0] << ' ' << sum[0][1] << ' ' << sum[0][2] << '\n';

    int t[C][R]{};       // 4x3: transposed shape
    transpose_to(a, R, t);
    std::cout << "transpose (4x3), first row: ";
    for (int c{0}; c < R; ++c)
    {
        std::cout << t[0][c] << ' ';
    }
    std::cout << '\n';

    // In-place transpose is only legal for SQUARE grids; it swaps each
    // pair (i,j) with (j,i) exactly once, for j > i:
    int sq[3][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i{0}; i < 3; ++i)
    {
        for (int j{i + 1}; j < 3; ++j)   // j > i: no double-swapping
        {
            int temp{sq[i][j]};
            sq[i][j] = sq[j][i];
            sq[j][i] = temp;
        }
    }
    std::cout << "3x3 transposed in place, first row: "
              << sq[0][0] << ' ' << sq[0][1] << ' ' << sq[0][2] << '\n';

    return 0;
}
