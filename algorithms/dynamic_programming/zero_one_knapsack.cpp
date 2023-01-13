#include <cassert>
#include <iostream>
#include <vector>

// Function to solve the knapsack problem
int knapsack(int W, std::vector<int> wt, std::vector<int> val, int n)
{
    // dp[i] is going to store the maximum value which can be achieved by using items up to i
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));

    // fill dp[i][j] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = std::max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

void test_knapsack()
{
    int W1 = 50;
    std::vector<int> val1 = {60, 100, 120};
    std::vector<int> wt1 = {10, 20, 30};
    int n1 = val1.size();
    assert(knapsack(W1, wt1, val1, n1) == 220);
    int W2 = 10;
    std::vector<int> val2 = {1, 4, 5, 7};
    std::vector<int> wt2 = {1, 3, 4, 5};
    int n2 = val2.size();
    assert(knapsack(W2, wt2, val2, n2) == 9);
    // more test cases ...
}

int main()
{
    test_knapsack();
    return 0;
}