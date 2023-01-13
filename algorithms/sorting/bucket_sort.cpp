#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<float> &arr)
{
    vector<vector<float>> buckets(arr.size());
    for (auto &i : arr)
    {
        int bucketIndex = int(arr.size() * i);
        buckets[bucketIndex].push_back(i);
    }

    for (auto &bucket : buckets)
    {
        sort(bucket.begin(), bucket.end());
    }
    arr.clear();
    for (auto &bucket : buckets)
    {
        for (auto &i : bucket)
        {
            arr.push_back(i);
        }
    }
}

void test_bucketSort()
{
    vector<float> input = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(input);
    for (auto i : input)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    test_bucketSort();
    return 0;
}
