#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    bool found = std::binary_search(v.begin(), v.end(), 30);
    std::cout << std::boolalpha << found << std::endl; // Prints "true"

    found = std::binary_search(v.begin(), v.end(), 35);
    std::cout << std::boolalpha << found << std::endl; // Prints "false"

    return 0;
}
