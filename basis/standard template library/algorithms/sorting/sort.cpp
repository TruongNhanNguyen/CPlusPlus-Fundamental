#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{30, 20, 10, 40};

    std::sort(v.begin(), v.end()); // v: { 10, 20, 30, 40 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "10 20 30 40"
    }
    std::cout << std::endl;

    return 0;
}
