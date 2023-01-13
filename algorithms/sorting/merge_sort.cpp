#include <bits/stdc++.h>

template <typename T>
void mergeSort(std::vector<T> &data)
{
    if (data.size() <= 1)
    {
        return;
    }
    size_t middle = data.size() / 2;
    std::vector<T> left(data.begin(), data.begin() + middle);
    std::vector<T> right(data.begin() + middle, data.end());
    mergeSort(left);
    mergeSort(right);
    merge(left, right, data);
}

template <typename T>
void merge(const std::vector<T> &left, const std::vector<T> &right, std::vector<T> &result)
{
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result[k++] = left[i++];
        }
        else
        {
            result[k++] = right[j++];
        }
    }
    while (i < left.size())
    {
        result[k++] = left[i++];
    }
    while (j < right.size())
    {
        result[k++] = right[j++];
    }
}

void test_mergeSort()
{
    std::vector<int> data = {3, 2, 1, 5, 6, 7, 8, 9};
    std::vector<int> expected_output = {1, 2, 3, 5, 6, 7, 8, 9};
    mergeSort(data);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    mergeSort(data);
    assert(data == expected_output);
    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mergeSort(data);
    assert(data == expected_output);
    data = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expected_output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mergeSort(data);
    assert(data == expected_output);
}

int main()
{
    test_mergeSort();
    return 0;
}