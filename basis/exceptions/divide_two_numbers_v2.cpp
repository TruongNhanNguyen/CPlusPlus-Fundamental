#include <iostream>
#include <stdexcept> // for std::runtime_error and std::invalid_argument

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int get_number(const std::string &s)
{
    if (s.empty())
    {
        throw std::invalid_argument("Empty string");
    }
    int number = 0;
    for (char c : s)
    {
        if (!isdigit(c))
        {
            throw std::invalid_argument("Invalid character");
        }
        number = number * 10 + (c - '0');
    }
    return number;
}

int main()
{
    try
    {
        int a = get_number("10");
        int b = get_number("0");
        int result = divide(a, b);
        std::cout << result << std::endl; // This line is not reached
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl; // Prints "Invalid character"
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl; // This catch block is not reached
    }

    return 0;
}
