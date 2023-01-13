#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<int>> &board, int row, int col)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }
    // Check if there is a queen in the same diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<int>> &board, int row)
{
    if (row == board.size())
    {
        // Print the solution
        for (auto &row : board)
        {
            for (auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < board.size(); col++)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            board[row][col] = 0;
        }
    }
}

void test_n_queens()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueens(board, 0);
    n = 5;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    solveNQueens(board, 0);
    n = 6;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    solveNQueens(board, 0);
    n = 7;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    solveNQueens(board, 0);
}

int main()
{
    test_n_queens();
    return 0;
}
