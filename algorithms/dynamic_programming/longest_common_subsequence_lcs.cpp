#include <cassert>
#include <iostream>
#include <string>

std::string X, Y;
int m, n;
int dp[100][100];

void printLCS(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (X[i - 1] == Y[j - 1])
    {
        printLCS(i - 1, j - 1);
        std::cout << X[i - 1];
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
        printLCS(i - 1, j);
    }
    else
    {
        printLCS(i, j - 1);
    }
}

void LCS()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void test_LCS()
{
    X = "AGGTAB";
    Y = "GXTXAYB";
    LCS();
    assert(dp[X.length()][Y.length()] == 4);
    std::cout << "LCS of " << X << " and " << Y << " : ";
    printLCS(X.length(), Y.length());

    X = "ABCD";
    Y = "EACB";
    LCS();
    assert(dp[X.length()][Y.length()] == 2);
    std::cout << "LCS of " << X << " and " << Y << " : ";
    printLCS(X.length(), Y.length());
}

int main()
{
    test_LCS();
    return 0;
}
