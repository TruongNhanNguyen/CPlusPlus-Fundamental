#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40, 50};

    // Iterate over the elements of the vector using a forward iterator
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " "; // Prints "10 20 30 40 50"
    }
    std::cout << std::endl;

    // Modify the elements of the vector using a random-access iterator
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        *it += 1; // Increment the element by 1
    }
    for (int x : v)
    {
        std::cout << x << " "; // Prints "11 21 31 41 51"
    }
    std::cout << std::endl;

    // Insert an element into the vector using an insert iterator
    std::vector<int>::iterator it = v.begin() + 2;
    std::copy(it, it + 1, std::inserter(v, it)); // Insert a copy of the element at position 2
    for (int x : v)
    {
        std::cout << x << " "; // Prints "11 21 31 31 41 51"
    }
    std::cout << std::endl;

    return 0;
}
