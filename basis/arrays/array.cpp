#include <bits/stdc++.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of 5 integers
    int first = arr[0];           // first will be 1
    std::cout << first << std::endl;
    arr[0] = 10; // Set the first element of the array to 10
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " "; // Print each element of the array followed by a space
    }
    return 0;
}