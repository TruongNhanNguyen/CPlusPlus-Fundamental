#include <iostream>
#include <iterator>
#include <list>

int main()
{
    std::list<int> l{10, 20, 30, 40, 50};

    // Iterate over the elements of the list using a bidirectional iterator
    std::list<int>::iterator it = l.begin();
    while (it != l.end())
    {
        std::cout << *it << " "; // Prints "10 20 30 40 50"
        ++it;
    }
    std::cout << std::endl;

    // Insert an element into the list using a bidirectional iterator
    it = l.insert(++it, 60);
    for (int x : l)
    {
        std::cout << x << " "; // Prints "10 20 60 30 40 50"
    }
    std::cout << std::endl;

    // Erase an element from the list using a bidirectional iterator
    it = l.erase(--it);
    for (int x : l)
    {
        std::cout << x << " "; // Prints "10 20 30 40 50"
    }
    std::cout << std::endl;

    return 0;
}
