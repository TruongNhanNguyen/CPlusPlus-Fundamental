#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40};

    std::random_device rd;
    std::mt19937 g(rd());
    std::random_shuffle(v.begin(), v.end(), g); // Shuffle the elements randomly

    for (int x : v)
    {
        std::cout << x << " "; // Prints a shuffled sequence of integers
    }
    std::cout << std::endl;

    return 0;
}
