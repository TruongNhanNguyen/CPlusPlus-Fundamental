#include <iostream>
#include <vector>

void countingsort(std::vector<int> &arr, int k)
{
    std::vector<int> counting_arr(k + 1);
    std::vector<int> output_arr(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        counting_arr[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        counting_arr[i] += counting_arr[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output_arr[counting_arr[arr[i]] - 1] = arr[i];
        counting_arr[arr[i]]--;
    }
    arr = output_arr;
}

void test_countingsort()
{
    std::vector<int> input = {4, 2, 2, 8, 3, 3, 1};
    int k = 8;
    countingsort(input, k);
    for (auto i : input)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test_countingsort();
    return 0;
}
