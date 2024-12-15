## sudoku-solver

# Algorithm Mechanism:

The algorithm systematically explores possible solutions by:
a) Finding an empty cell
b) Trying numbers 1-9 in that cell
c) Recursively attempting to solve the rest of the grid
d) If a number doesn't work, it "backtracks" by undoing the last move
This is a brute-force approach with intelligent pruning


# Time Complexity: O(9^(n*n))

Worst-case scenario: The algorithm might need to try almost every possible combination
The complexity is exponential because:

For each empty cell, we try 9 possible numbers
We have n*n (81 for a 9x9 grid) cells potentially to fill


Practically, the actual runtime is much lower due to constraint checking


# Space Complexity: O(n*n)

Recursive call stack depth is proportional to the number of empty cells
Uses additional space for recursion and grid manipulation


# Constraint Reduction:

is_safe() function dramatically reduces the search space
Before placing a number, it checks:
a) Row constraints
b) Column constraints
c) 3x3 sub-grid constraints
This prevents exploring obviously invalid paths


# Key Optimization Techniques:

Early pruning via is_safe() method
Immediate backtracking when a path is impossible
Recursive approach allows quick exploration and rejection of invalid solutions
