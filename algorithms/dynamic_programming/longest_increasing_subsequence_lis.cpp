#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    vector<int> prev(nums.size(), -1);
    int max_len = 0;
    int max_len_end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            max_len_end = i;
        }
    }
    vector<int> result;
    while (max_len_end != -1)
    {
        result.push_back(nums[max_len_end]);
        max_len_end = prev[max_len_end];
    }
    reverse(result.begin(), result.end());
    return result;
}

void test_longestIncreasingSubsequence()
{
    vector<int> nums1 = {4, 2, 3, 6, 10, 1, 12};
    vector<int> expected1 = {2, 3, 6, 10, 12};
    auto result1 = longestIncreasingSubsequence(nums1);
    assert(result1 == expected1);

    vector<int> nums2 = {-4, 10, 3, 7, 15};
    vector<int> expected2 = {-4, 3, 7, 15};
    auto result2 = longestIncreasingSubsequence(nums2);
    assert(result2 == expected2);
}

int main()
{
    test_longestIncreasingSubsequence();
    return 0;
}