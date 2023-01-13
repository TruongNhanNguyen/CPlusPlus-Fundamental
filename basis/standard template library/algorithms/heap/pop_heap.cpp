#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    std::make_heap(v.begin(), v.end()); // v: { 50, 40, 30, 20, 10 }

    std::pop_heap(v.begin(), v.end()); // v: { 40, 20, 30, 10, 50 }
    int max = v.back();
    v.pop_back();
    std::cout << "Maximum element: " << max << std::endl; // Prints "Maximum element: 50"

    return 0;
}
