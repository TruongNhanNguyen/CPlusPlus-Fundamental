#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
int linear_search(std::vector<T> &data, T target)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == target)
        {
            return i;
        }
    }
    return -1; // Target not found
}

void test_linear_search()
{
    std::vector<int> data1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int expected_output1 = 2;
    assert(linear_search(data1, target1) == expected_output1);

    std::vector<int> data2 = {10, 20, 30, 40, 50, 60};
    int target2 = 40;
    int expected_output2 = 3;
    assert(linear_search(data2, target2) == expected_output2);

    std::vector<int> data3 = {10, 20, 30, 40};
    int target3 = 100;
    int expected_output3 = -1;
    assert(linear_search(data3, target3) == expected_output3);
}

int main()
{
    test_linear_search();
    return 0;
}