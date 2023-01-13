#include <iostream>
#include <list>

int main()
{
    std::list<int> l{10, 20, 30};

    // Access and modify elements
    std::cout << l.front() << std::endl; // Prints 10
    l.back() = 35;
    l.push_back(40);           // l: { 10, 20, 30, 40 }
    l.pop_back();              // l: { 10, 20, 30 }
    l.push_front(5);           // l: { 5, 10, 20, 30 }
    l.pop_front();             // l: { 10, 20, 30 }
    l.insert(++l.begin(), 15); // l: { 10, 15, 20, 30 }
    l.erase(--l.end());        // l: { 10, 15, 30 }

    // Iterate over the elements
    for (int x : l)
    {
        std::cout << x << " "; // Prints "10 15 30"
    }
    std::cout << std::endl;

    return 0;
}
