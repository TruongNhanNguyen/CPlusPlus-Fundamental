#include <bits/stdc++.h>

template <typename T>
void heapSort(std::vector<T> &data)
{
    int n = data.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(data, n, i);
    }
    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

template <typename T>
void heapify(std::vector<T> &data, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && data[left] > data[largest])
    {
        largest = left;
    }
    if (right < n && data[right] > data[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

void test_heapSort(){
    std::vector<int> data = { 3,2,1,5,6,7,8,9};
    std::vector<int> expected_output = { 1,2,3,5,6,7,8,9};
    heapSort(data);
    assert(data == expected_output);
    data = {};
    expected_output = {};
    heapSort(data);
    assert(data == expected_output);
    data = {1,2,3,4,5,6,7,8,9,10};
    expected_output = {1,2,3,4,5,6,7,8,9,10};
    heapSort(data);
    assert(data == expected_output);
    data = {10,9,8,7,6,5,4,3,2,1};
    expected_output = {1,2,3,4,5,6,7,8,9,10};
    heapSort(data);
    assert(data == expected_output);
}

int main() {
    test_heapSort();
    return 0;
}