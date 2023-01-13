# Exceptions Handling

Exception handling is a mechanism in C++ that allows you to handle runtime errors or unexpected conditions in your code. It allows you to separate the error-handling code from the normal code, making it easier to read and maintain.

```cpp
#include <iostream>
#include <stdexcept>  // for std::runtime_error

int divide(int a, int b) {
  if (b == 0) {
    throw std::runtime_error("Division by zero");
  }
  return a / b;
}

int main() {
  try {
    int result = divide(10, 0);
    std::cout << result << std::endl;  // This line is not reached
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;  // Prints "Division by zero"
  }

  return 0;
}
```

In this example, the divide function divides two integers and throws a `std::runtime_error` exception if the second argument is zero. The main function calls the divide function and encloses it in a `try` block. If an exception is thrown, it is caught by the `catch` block and the error message is printed.

`Exceptions` are a powerful tool for handling errors and unexpected conditions in your code. They allow you to write cleaner and more maintainable code by separating the error-handling code from the normal code.