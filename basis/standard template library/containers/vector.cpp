#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30};

    // Access and modify elements
    std::cout << v[0] << std::endl; // Prints 10
    v[1] = 25;
    v.push_back(40); // v: { 10, 25, 30, 40 }
    v.pop_back();    // v: { 10, 25, 30 }

    // Iterate over the elements
    for (int x : v)
    {
        std::cout << x << " "; // Prints "10 25 30"
    }
    std::cout << std::endl;

    // Resize the vector
    v.resize(5, 0); // v: { 10, 25, 30, 0, 0 }
    v.resize(2);    // v: { 10, 25 }

    return 0;
}
