#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    // Find the maximum element
    auto result = std::max_element(v.begin(), v.end());
    if (result != v.end())
    {
        std::cout << "Max element: " << *result << std::endl; // Prints "Max element: 50"
    }

    // Sort the elements in ascending order
    std::sort(v.begin(), v.end());
    for (int x : v)
    {
        std::cout << x << " "; // Prints "10 20 30 40 50"
    }
    std::cout << std::endl;

    // Find all even elements
    std::vector<int> even;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even), [](int x)
                 { return x % 2 == 0; });
    for (int x : even)
    {
        std::cout << x << " "; // Prints "10 20 30 50"
    }
    std::cout << std::endl;

    return 0;
}
