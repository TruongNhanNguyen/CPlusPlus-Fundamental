#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 20, 10};

    int count = std::count(v.begin(), v.end(), 20);
    std::cout << "Number of occurrences: " << count << std::endl; // Prints "Number of occurrences: 2"

    return 0;
}
