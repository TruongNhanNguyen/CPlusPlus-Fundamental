#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40};

    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end())
    {
        std::cout << "Found element: " << *it << std::endl; // Prints "Found element: 30"
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
