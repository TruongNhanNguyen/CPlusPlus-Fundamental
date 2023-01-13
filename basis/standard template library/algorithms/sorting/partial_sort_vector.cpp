#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{30, 20, 10, 40, 50, 60};

    std::partial_sort(v.begin(), v.begin() + 3, v.end()); // v: { 10, 20, 30, 40, 50, 60 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "10 20 30 40 50 60"
    }
    std::cout << std::endl;

    return 0;
}
