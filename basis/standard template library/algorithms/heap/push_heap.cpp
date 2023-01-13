#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    std::make_heap(v.begin(), v.end()); // v: { 50, 40, 30, 20, 10 }

    v.push_back(60);
    std::push_heap(v.begin(), v.end()); // v: { 60, 50, 30, 20, 10, 40 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "60 50 30 20 10 40"
    }
    std::cout << std::endl;

    return 0;
}
