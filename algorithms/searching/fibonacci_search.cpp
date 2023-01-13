#include <bits/stdc++.h>

template <typename T>
int FibonacciSearch(const std::vector<T> &arr, T target)
{
    int fibMMm2 = 0;              // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;              // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    // Observe that fibM is going to store
    // (m-2) + (m-1) = m-1'th Fibonacci No.
    // So we can use it as a counter in the
    // while loop below

    // If we have not found the element in
    // the array
    while (fibM < arr.size())
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marking the eliminated range from
    // front.
    int offset = -1;

    // while there are elements to be inspected.
    while (fibM > 1)
    {
        int i = std::min(offset + fibMMm2, (int)arr.size() - 1);

        if (arr[i] < target)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > target)
        {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            return i;
        }
    }

    // If we reached here means element
    // was not present.
    return -1;
}

void test_FibonacciSearch()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 4;
    int expected_output = 3;
    assert(FibonacciSearch(data, target) == expected_output);

    target = 11;
    expected_output = -1;
    assert(FibonacciSearch(data, target) == expected_output);

    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    target = 18;
    expected_output = 17;
    assert(FibonacciSearch(data, target) == expected_output);

    target = 0;
    expected_output = -1;
    assert(FibonacciSearch(data, target) == expected_output);
}

int main()
{
    test_FibonacciSearch();
    return 0;
}