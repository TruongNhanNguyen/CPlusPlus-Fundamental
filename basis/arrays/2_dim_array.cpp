#include <bits/stdc++.h>

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}}; // Declare and initialize a 2x3 array
    int first = arr[0][0];                  // first will be 1
    int second = arr[0][1];                 // second will be 2
    int third = arr[1][0];                  // third will be 4
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << " "; // Print each element of the array followed by a space
        }
    }

    return 0;
}