#include <iostream>
#include <vector>

void radixsort(std::vector<int> &a)
{
    int max_val = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }

    int exp = 1;
    while (max_val / exp > 0)
    {
        std::vector<int> output(a.size());
        std::vector<int> count(10, 0);

        for (int i = 0; i < a.size(); i++)
        {
            count[(a[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        a = output;
        exp *= 10;
    }
}

void test_radixSort()
{
    std::vector<int> input = {170, 45, 75, 90, 802, 24, 2, 66};
    radixsort(input);
    for (auto i : input)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test_radixSort();
    return 0;
}
