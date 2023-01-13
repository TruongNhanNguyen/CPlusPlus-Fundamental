#include <bits/stdc++.h>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << max(10, 20) << std::endl;     // Prints "20"
    std::cout << max(3.14, 2.71) << std::endl; // Prints "3.14"
    std::cout << max('a', 'z') << std::endl;   // Prints "z"

    return 0;
}
