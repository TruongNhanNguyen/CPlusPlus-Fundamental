#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40};

    std::rotate(v.begin(), v.begin() + 2, v.end()); // v: { 30, 40, 10, 20 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "30 40 10 20"
    }
    std::cout << std::endl;

    return 0;
}
