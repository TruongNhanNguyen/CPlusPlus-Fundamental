#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{30, 20, 10, 40};

    std::sort(v.begin(), v.end(), std::greater<int>()); // v: { 40, 30, 20, 10 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "40 30 20 10"
    }
    std::cout << std::endl;

    return 0;
}
