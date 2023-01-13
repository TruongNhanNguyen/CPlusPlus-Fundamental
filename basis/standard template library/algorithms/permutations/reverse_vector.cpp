#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40};

    std::reverse(v.begin(), v.end()); // v: { 40, 30, 20, 10 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "40 30 20 10"
    }
    std::cout << std::endl;

    return 0;
}
