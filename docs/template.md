# Template

In C++, templates are a powerful feature that allow you to write generic and reusable code. Templates allow you to define functions and classes that can operate on a wide range of types, without having to specify the types explicitly. This can greatly improve the flexibility and maintainability of your code.

There are two types of templates in C++: function templates and class templates. Function templates are used to define generic functions that can work with different types, and class templates are used to define generic classes that can contain data and functions of different types.

Here is an example of a simple function template that returns the maximum of two values:

```cpp
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
```

In this example, the template parameter `T` is a placeholder for the type of the values that the function will operate on. When the function is called, the compiler will instantiate a new version of the function for each type that is passed as an argument.

Here is an example of a simple class template that implements a stack data structure:

```cpp
