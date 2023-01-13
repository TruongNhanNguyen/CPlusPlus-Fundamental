#include <forward_list>
#include <iostream>
#include <iterator>

int main()
{
    std::forward_list<int> fl{10, 20, 30, 40, 50};

    // Iterate over the elements of the forward list using a forward iterator
    std::forward_list<int>::iterator it = fl.begin();
    while (it != fl.end())
    {
        std::cout << *it << " "; // Prints "10 20 30 40 50"
        ++it;
    }
    std::cout << std::endl;

    // Insert an element into the forward list using a forward iterator
    it = fl.insert_after(fl.before_begin(), 60);
    for (int x : fl)
    {
        std::cout << x << " "; // Prints "60 10 20 30 40 50"
    }
    std::cout << std::endl;

    return 0;
}
