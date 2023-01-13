#include <bits/stdc++.h>

template <typename T>
void insertionSort(std::vector<T> &data)
{
    for (int i = 1; i < data.size(); i++)
    {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void test_insertionSort()
{
    std::vector<int> data = {3, 2, 1, 5, 6, 7, 8, 9};
    std::vector<int> expected_output = {1, 2, 3, 5, 6, 7, 8, 9};
    insertionSort(data);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    insertionSort(data);
    assert(data == expected_output);
    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    insertionSort(data);
    assert(data == expected_output);
    data = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    insertionSort(data);
    assert(data == expected_output);
}

int main() {
    test_insertionSort();
    return 0;
}