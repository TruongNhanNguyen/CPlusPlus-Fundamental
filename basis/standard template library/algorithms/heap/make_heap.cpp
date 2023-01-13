#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    std::make_heap(v.begin(), v.end()); // v: { 50, 40, 30, 20, 10 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "50 40 30 20 10"
    }
    std::cout << std::endl;

    return 0;
}
