#include <bits/stdc++.h>

template <typename T>
void quickSort(std::vector<T> &data, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(data, left, right);
        quickSort(data, left, pivotIndex);
        quickSort(data, pivotIndex + 1, right);
    }
}

template <typename T>
int partition(std::vector<T> &data, int left, int right)
{
    T pivot = data[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

void test_quickSort()
{
    std::vector<int> data = {3, 2, 1, 5, 6, 7, 8, 9};
    std::vector<int> expected_output = {1, 2, 3, 5, 6, 7, 8, 9};
    quickSort(data, 0, data.size() - 1);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    quickSort(data, 0, data.size() - 1);
    assert(data == expected_output);
    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(data, 0, data.size() - 1);
    assert(data == expected_output);
    data = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expected_output = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quickSort(data, 0, data.size() - 1);
    assert(data == expected_output);
}

int main() {
    test_quickSort();
    return 0;
}
