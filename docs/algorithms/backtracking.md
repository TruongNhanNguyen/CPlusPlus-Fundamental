# Backtracking Algorithms

Backtracking is a general algorithm for finding all solutions to some computational problems, notably constraint satisfaction problems, that incrementally builds candidates to the solutions, and abandons each partial candidate c ("backtracks") as soon as it determines that c cannot possibly be completed to a valid solution.

One of the most common examples of backtracking algorithm is the N-Queens problem, where the goal is to place N queens on an NxN chessboard such that no two queens threaten each other. The problem can be solved by starting from the first row, placing a queen in each column, and recursively moving to the next row. If at any point it is discovered that the current placement of queens is invalid, the algorithm backtracks to the previous row and tries a different column to place the queen.

Another example is the Sudoku solver, where the goal is to fill in a 9x9 grid of numbers such that each row, column, and 3x3 sub-grid contains all the digits from 1 to 9. The problem can be solved by starting from the first cell, trying all possible digits, and recursively moving to the next cell. If at any point it is discovered that the current configuration of the grid is invalid, the algorithm backtracks to the previous cell and tries a different digit.

Another example is the m-coloring problem, where the goal is to color a graph with m colors such that no two adjacent vertices have the same color. The problem can be solved by starting from the first vertex, trying all possible m colors, and recursively moving to the next vertex. If at any point it is discovered that the current coloring of the graph is invalid, the algorithm backtracks to the previous vertex and tries a different color.

Backtracking algorithm can also be used in other problem such as maze solving, subset sum problem, rat in a maze problem and many more.