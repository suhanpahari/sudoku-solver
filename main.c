#include <stdio.h>
#include <stdbool.h>

#define N 9 // 9x9 Sudoku grid

// Function to print the Sudoku grid
void print_grid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a specific cell
bool is_safe(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }
    
    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }
    
    // Check 3x3 sub-grid
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Recursive function to solve Sudoku using backtracking
bool solve_sudoku(int grid[N][N]) {
    int row, col;
    bool is_empty = false;
    
    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                is_empty = true;
                break;
            }
        }
        if (is_empty) {
            break;
        }
    }
    
    // If no empty cell found, puzzle is solved
    if (!is_empty) {
        return true;
    }
    
    // Try placing numbers 1-9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            // Place the number
            grid[row][col] = num;
            
            // Recursively try to solve the rest of the grid
            if (solve_sudoku(grid)) {
                return true;
            }
            
            // If placing the number doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }
    
    // Trigger backtracking
    return false;
}

int main() {
    int grid[N][N];
    
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    
    // Input the grid row by row
    for (int row = 0; row < N; row++) {
        printf("Enter row %d (9 numbers, space-separated): ", row + 1);
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    
    printf("\nInput Sudoku Grid:\n");
    print_grid(grid);
    
    // Solve the Sudoku
    if (solve_sudoku(grid)) {
        printf("\nSolved Sudoku Grid:\n");
        print_grid(grid);
    } else {
        printf("\nNo solution exists.\n");
    }
    
    return 0;
}
