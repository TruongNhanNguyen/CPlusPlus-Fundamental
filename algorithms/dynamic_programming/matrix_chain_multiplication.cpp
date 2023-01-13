#include <bits/stdc++.h>

int MatrixChainMultiplication(const std::vector<int> &dims)
{
    int n = dims.size() - 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]);
            }
        }
    }
    return dp[0][n - 1];
}

void test_MatrixChainMultiplication()
{
    std::vector<int> dims1 = {1, 2, 3, 4};
    assert(MatrixChainMultiplication(dims1) == 18);

    std::vector<int> dims2 = {10, 20, 30, 40, 30};
    assert(MatrixChainMultiplication(dims2) == 30000);

    std::vector<int> dims3 = {40, 20, 30, 10, 30};
    assert(MatrixChainMultiplication(dims3) == 26000);
}

int main()
{
    test_MatrixChainMultiplication();
    return 0;
}