#include <deque>
#include <iostream>

int main()
{
    std::deque<int> d{10, 20, 30};

    // Access and modify elements
    std::cout << d.front() << std::endl; // Prints 10
    d.back() = 35;
    d.push_back(40);           // d: { 10, 20, 30, 40 }
    d.pop_back();              // d: { 10, 20, 30 }
    d.push_front(5);           // d: { 5, 10, 20, 30 }
    d.pop_front();             // d: { 10, 20, 30 }
    d.insert(++d.begin(), 15); // d: { 10, 15, 20, 30 }
    d.erase(--d.end());        // d: { 10, 15, 30 }

    // Iterate over the elements
    for (int x : d)
    {
        std::cout << x << " "; // Prints "10 15 30"
    }
    std::cout << std::endl;

    return 0;
}
