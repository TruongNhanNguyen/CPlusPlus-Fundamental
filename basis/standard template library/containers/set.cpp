#include <iostream>
#include <set>

int main()
{
    std::set<int> s{10, 20, 30};

    // Insert and remove elements
    s.insert(25); // s: { 10, 20, 25, 30 }
    s.erase(20);  // s: { 10, 25, 30 }

    // Lookup elements
    std::cout << std::boolalpha << s.count(10) << std::endl; // Prints "true"
    std::cout << std::boolalpha << s.count(20) << std::endl; // Prints "false"

    // Iterate over the elements
    for (int x : s)
    {
        std::cout << x << " "; // Prints "10 25 30"
    }
    std::cout << std::endl;

    return 0;
}
