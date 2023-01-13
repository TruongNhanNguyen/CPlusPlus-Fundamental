#include <iostream>
#include <string>
#include <vector>

int min3(int a, int b, int c)
{
    return std::min(std::min(a, b), c);
}

int editDistance(std::string s1, std::string s2)
{
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min3(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void test_editDistance()
{
    std::cout << editDistance("kitten", "sitting") << std::endl; // 3
    std::cout << editDistance("flaw", "lawn") << std::endl;      // 2
    std::cout << editDistance("", "ab") << std::endl;            // 2
    std::cout << editDistance("a", "a") << std::endl;            // 0
}

int main()
{
    test_editDistance();
    return 0;
}
