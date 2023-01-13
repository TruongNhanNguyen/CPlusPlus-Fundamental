#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    // Iterate over the elements of the vector using an input iterator
    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << " "; // Prints "10 20 30 40 50"
        ++it;
    }
    std::cout << std::endl;

    return 0;
}
