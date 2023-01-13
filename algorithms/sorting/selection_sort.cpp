#include <bits/stdc++.h>

template <typename T>
void selectionSort(std::vector<T> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
    }
}

void test_selectionSort()
{
    std::vector<int> data = {3, 2, 1, 5, 6, 7, 8, 9};
    std::vector<int> expected_output = {1, 2, 3, 5, 6, 7, 8, 9};
    selectionSort(data);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    selectionSort(data);
    assert(data == expected_output);
    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    selectionSort(data);
    assert(data == expected_output);
    data = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    selectionSort(data);
    assert(data == expected_output);
}

int main()
{
    test_selectionSort();
    return 0;
}