#include <bits/stdc++.h>

template <typename T>
int binary_search_helper(std::vector<T> &data, T target, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == target)
        {
            return mid;
        }
        else if (data[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

template <typename T>
int exponential_search(std::vector<T> &data, T target)
{
    int n = data.size();
    if (data[0] == target)
    {
        return 0;
    }

    int i = 1;
    while (i < n && data[i] <= target)
    {
        i = i * 2;
    }

    int index = std::min(i, n) - 1;
    int low = i / 2;
    int high = index;
    return binary_search_helper(data, target, low, high);
}

void test_exponential_search()
{
    std::vector<int> data1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int expected_output1 = 2;
    assert(exponential_search(data1, target1) == expected_output1);

    std::vector<int> data2 = {10, 20, 30, 40, 50, 60};
    int target2 = 40;
    int expected_output2 = 3;
    assert(exponential_search(data2, target2) == expected_output2);

    std::vector<int> data3 = {10, 20, 30, 40};
    int target3 = 100;
    int expected_output3 = -1;
    assert(exponential_search(data3, target3) == expected_output3);
}

int main()
{
    test_exponential_search();
    return 0;
}