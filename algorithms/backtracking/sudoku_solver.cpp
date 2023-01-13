#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>> &board, int row, int col, int num)
{
    // Check row
    for (int x = 0; x < 9; x++)
    {
        if (board[row][x] == num)
        {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < 9; x++)
    {
        if (board[x][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(std::vector<std::vector<int>> &board, int row, int col)
{
    if (row == 9)
    {
        return true; // We have filled the entire board
    }

    if (col == 9)
    {
        return solveSudoku(board, row + 1, 0);
    }

    if (board[row][col] != 0)
    {
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void test_sudoku_solver()

{
    std::vector<std::vector<int>> board1 = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                            {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                            {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                            {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                            {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                            {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                            {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    bool solved = solveSudoku(board1, 0, 0);
    if (solved)
    {

        std::cout << "Sudoku board 1 solved: " << std::endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                std::cout << board1[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to solve sudoku board 1" << std::endl;
    }

    // Add more test cases here
}

int main()
{
    test_sudoku_solver();
    return 0;
}
