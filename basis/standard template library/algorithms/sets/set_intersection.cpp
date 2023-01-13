#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1{10, 20, 30};
    std::vector<int> v2{20, 30, 40};
    std::vector<int> result;

    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));
    // result: { 20, 30 }

    for (int x : result)
    {
        std::cout << x << " "; // Prints "20 30"
    }
    std::cout << std::endl;

    return 0;
}
