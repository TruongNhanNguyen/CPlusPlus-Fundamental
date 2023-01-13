#include <iostream>
#include <stdexcept> // for std::runtime_error

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int main()
{
    try
    {
        int result = divide(10, 0);
        std::cout << result << std::endl; // This line is not reached
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl; // Prints "Division by zero"
    }

    return 0;
}