#include <algorithm>
#include <iostream>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

bool activityCompare(Activity a, Activity b)
{
    return (a.finish < b.finish);
}

void printMaxActivities(Activity arr[], int n)
{
    sort(arr, arr + n, activityCompare);
    int i = 0;
    cout << "Selected activities: " << i << " ";
    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << j << " ";
            i = j;
        }
    }
}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}
