// purpose: 2-D array declaration, row/column indexing, row-major memory
//          layout, and the two base traversals — used in L19.
// build:   g++ -std=c++17 -Wall -Wextra -pedantic grid_basics.cpp -o grid

#include <iostream>

const int ROWS{3};
const int COLS{4};

void print_grid(const int g[][COLS], int rows)
{
    for (int r{0}; r < rows; ++r)
    {
        for (int c{0}; c < COLS; ++c)
        {
            std::cout << g[r][c] << '\t';
        }
        std::cout << '\n';
    }
}

int main()
{
    // --- Declaration + full initialization (rows of columns) ---
    int grid[ROWS][COLS]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    std::cout << "grid (row-wise print):\n";
    print_grid(grid, ROWS);

    // --- Indexing: [row][col] — row FIRST ---
    std::cout << "grid[1][2] = " << grid[1][2] << "  (row 1, col 2)\n";
    grid[1][2] = 70;                     // elements are writable
    std::cout << "after write, grid[1][2] = " << grid[1][2] << '\n';

    // --- Row-major memory: the grid is a VIEW over a linear block ---
    // Element [r][c] lives at element-offset r * COLS + c.
    std::cout << "\nlinear offsets (r * COLS + c):\n";
    for (int r{0}; r < ROWS; ++r)
    {
        for (int c{0}; c < COLS; ++c)
        {
            std::cout << "grid[" << r << "][" << c << "] -> offset "
                      << r * COLS + c << '\n';
        }
    }

    // --- Addresses: contiguous, stepping by sizeof(int) across the grid ---
    std::cout << "\n&grid[0][0] = " << &grid[0][0]
              << ", &grid[0][1] = " << &grid[0][1]
              << ", &grid[1][0] = " << &grid[1][0] << '\n';
    // (Print format is platform-specific; the ADJACENCY is what matters.)

    // --- Column-wise traversal: same syntax, swapped loops ---
    std::cout << "\ncolumn 0 top-to-bottom: ";
    for (int r{0}; r < ROWS; ++r)
    {
        std::cout << grid[r][0] << ' ';
    }
    std::cout << '\n';

    return 0;
}
