#include <bits/stdc++.h>

template <typename T>
void bubbleSort(std::vector<T> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = 0; j < data.size() - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

void test_bubbleSort()
{
    std::vector<int> data = {3, 2, 1, 5, 6, 7, 8, 9};
    std::vector<int> expected_output = {1, 2, 3, 5, 6, 7, 8, 9};
    bubbleSort(data);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    bubbleSort(data);
    assert(data == expected_output);
    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(data);
    assert(data == expected_output);
    data = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubbleSort(data);
    assert(data == expected_output);
}

int main()
{
    test_bubbleSort();
    return 0;
}