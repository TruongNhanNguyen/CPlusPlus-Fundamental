#include <bits/stdc++.h>

template <typename T>
int interpolation_search(std::vector<T> &data, T target)
{
    int left = 0;
    int right = data.size() - 1;
    while (left <= right && target >= data[left] && target <= data[right])
    {
        int pos = left + ((target - data[left]) * (right - left) / (data[right] - data[left]));

        if (data[pos] == target)
        {
            return pos;
        }
        if (data[pos] < target)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
    return -1; // Target not found
}

void test_interpolation_search()
{
    std::vector<int> data1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int expected_output1 = 2;
    assert(interpolation_search(data1, target1) == expected_output1);

    std::vector<int> data2 = {10, 20, 30, 40, 50, 60};
    int target2 = 40;
    int expected_output2 = 3;
    assert(interpolation_search(data2, target2) == expected_output2);

    std::vector<int> data3 = {10, 20, 30, 40};
    int target3 = 100;
    int expected_output3 = -1;
    assert(interpolation_search(data3, target3) == expected_output3);
}

int main()
{
    test_interpolation_search();
    return 0;
}
