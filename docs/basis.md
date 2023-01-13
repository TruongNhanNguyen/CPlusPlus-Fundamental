# Basis of CPlusPlus

## Variable

A variable is a *named location* in memory that you can use to *store a value*. In C++, you need to specify the type of a variable when you declare it, such as an *integer, float, or string*. Here is an example of how to declare and initialize variables in C++:

```cpp
int age = 35;   // Declare an integer variable called "age" and initialize it with the value 35
double pi = 3.14159;  // Declare a double-precision floating point variable called "pi" and initialize it with the value 3.14159
char letter = 'A';    // Declare a character variable called "letter" and initialize it with the value 'A'
string name = "John";  // Declare a string variable called "name" and initialize it with the value "John"
```

You can also declare multiple variables of the same type in a single statement, like this:

```cpp
int x, y, z;  // Declare three integer variables called x, y, and z
```

You can also declare a variable and leave it uninitialized, like this:

```cpp
int result;  // Declare an integer variable called "result"
```

In this case, the variable will be assigned a default value (e.g., 0 for integers) until you assign it a different value.

## Data types, how many of them in C++.

C++ has a variety of built-in data types that you can use to store different kinds of data. Here is a list of some of the most common data types in C++:

1. **Integers**: Integers are whole numbers that can be either positive, negative, or zero. C++ has several integer data types, including `char`, `short`, `int`, and `long`, which vary in size and range. For example, char is a 1-byte integer type that can store values from -128 to 127, while `long` is a 4-byte integer type that can store values from -2147483648 to 2147483647.

2. Floating-point numbers: Floating-point numbers are numbers with a decimal point, such as 3.14 or -1.5. C++ has two floating-point data types: `float` and `double`. `float` is a 4-byte type that can store values with single-precision accuracy, while `double` is an 8-byte type that can store values with double-precision accuracy.

3. **Characters**: Characters are single letters, digits, or symbols that are represented as a single byte in memory. C++ has a `char` data type that can store a single character.

4. **Strings**: A string is a sequence of characters that are stored as an array of char values. C++ does not have a built-in `string` data type, but you can use the string type from the `string` library to store and manipulate strings.

5. **Booleans**: The `bool` data type is a logical type that can store either true or false. It is often used in conditional statements to test the truth value of a condition.

These are just a few of the many data types that are available in C++. In addition to these built-in types, you can also define your own *custom data types using structures and classes*.

Here are some examples of using the different data types in C++:

```cpp
// Integers
int x = 10;  // Declare and initialize an integer variable called "x" with the value 10
short s = -5;  // Declare and initialize a short integer variable called "s" with the value -5
long l = 1000000;  // Declare and initialize a long integer variable called "l" with the value 1000000

// Floating-point numbers
float f = 3.14;  // Declare and initialize a float variable called "f" with the value 3.14
double d = -1.5;  // Declare and initialize a double variable called "d" with the value -1.5

// Characters
char c = 'A';  // Declare and initialize a character variable called "c" with the value 'A'

// Strings
string str = "Hello, world!";  // Declare and initialize a string variable called "str" with the value "Hello, world!"

// Booleans
bool flag = true;  // Declare and initialize a boolean variable called "flag" with the value true
```

## Operators

Operators are special symbols that perform operations on variables and values. C++ has a variety of operators, including arithmetic operators, comparison operators, and logical operators. Here are some examples of common operators in C++:

1. **Arithmetic operators**: These operators perform basic arithmetic operations, such as *addition*, *subtraction*, *multiplication*, and *division*. For example:

    ```cpp
    int x = 10 + 5;  // Addition operator, result is 15
    int y = 10 - 5;  // Subtraction operator, result is 5
    int z = 10 * 5;  // Multiplication operator, result is 50
    int a = 10 / 5;  // Division operator, result is 2
    ```

2. **Comparison operators**: These operators compare two values and return a boolean result (`true` or `false`). For example:
   
    ```cpp
    bool b1 = (10 == 5);  // Equal to operator, result is false
    bool b2 = (10 != 5);  // Not equal to operator, result is true
    bool b3 = (10 > 5);  // Greater than operator, result is true
    bool b4 = (10 < 5);  // Less than operator, result is false
    ```

3. **Logical operators**: These operators perform logical operations, such as `AND`, `OR`, and `NOT`. For example:

    ```cpp
    bool b1 = true && false;  // AND operator, result is false
    bool b2 = true || false;  // OR operator, result is true
    bool b3 = !true;  // NOT operator, result is false
    ```

4. **Assignment operators**: These operators assign a value to a variable. The most basic assignment operator is the equal sign (`=`), which assigns a value to a variable. For example
   
    ```cpp
    int x = 10;  // Assign the value 10 to the variable x
    ```

    There are also compound assignment operators, which perform an operation and assign the result to a variable in a single step. For example:

    ```cpp
    int x = 10;
    x += 5;  // Add 5 to x and assign the result (15) to x
    x *= 2;  // Multiply x by 2 and assign the result (30) to x
    ```

5. **Increment and decrement operators**: These operators increase or decrease the value of a variable by 1. The increment operator (`++`) increases the value of a variable by 1, while the decrement operator (`--`) decreases the value by 1. For example:

    ```cpp
    int x = 10;
    x++;  // Increment x by 1, x is now 11
    x--;  // Decrement x by 1, x is now 10
    ```

6. Bitwise operators: These operators perform bitwise operations on integer values. For example:

    ```cpp
    int x = 10;  // Binary representation of 10 is 1010
    int y = 5;   // Binary representation of 5 is 0101
    int z = x & y;  // Bitwise AND operator, result is 0 (0000)
    int a = x | y;  // Bitwise OR operator, result is 15 (1111)
    int b = x ^ y;  // Bitwise XOR operator, result is 15 (1111)
    ```

There are many other operators in C++, including ternary operator, type casting operators, and more.

## Control structures

Control structures are blocks of code that allow you to control the flow of your program. They allow you to execute certain blocks of code conditionally or repeatedly, depending on the conditions you specify. Here are some common control structures in C++:

1. **Conditional statements**: Conditional statements allow you to execute certain blocks of code only if a certain condition is met. The most basic conditional statement is the `if` statement, which has the following syntax:

    ```cpp
    if (condition) {
        // Code to execute if the condition is true
    }
    ```

    You can also use the `else` keyword to specify a block of code to execute if the condition is not met:

    ```cpp
    if (condition) {
        // Code to execute if the condition is true
    } else {
        // Code to execute if the condition is false
    }
    ```

    You can also use the `else if` keyword to specify additional conditions to test:

    ```cpp
    if (condition1) {
        // Code to execute if condition1 is true
    } else if (condition2) {
        // Code to execute if condition1 is false and condition2 is true
    } else {
        // Code to execute if both condition1 and condition2 are false
    }
    ```

2. **Loops**: Loops allow you to execute a block of code repeatedly until a certain condition is met. C++ has two types of loops: `for` loops and `while` loops.

    The `for` loop has the following syntax:

    ```cpp
    for (initialization; condition; increment) {
        // Code to execute as long as the condition is true
    }
    ```

    The `while` loop has the following syntax:

    ```cpp
    while (condition) {
        // Code to execute as long as the condition is true
    }
    ```

    You can use the `break` and `continue` keywords to control the flow of a loop. The `break` keyword exits the loop, while the `continue` keyword skips the rest of the current iteration and moves on to the next one.

3. **Function calls**: A function is a block of code that performs a specific task and can be called from other parts of your program. You can call a function by using its name followed by a pair of parentheses and any required arguments. For example:

    ```cpp
    void print_hello() {
        cout << "Hello, world!" << endl;
    }

    int main() {
        print_hello();  // Call the print_hello function
        return 0;
    }
    ```

## Functions

A function is a block of code that performs a specific task and can be called from other parts of your program. Functions are a useful way to organize and reuse code, as they allow you to define a task once and then call it from multiple places in your program.

In C++, you can define a function by specifying its return type, name, and parameters. For example, here is how you could define a function that adds two numbers and returns the result:

```cpp
int add(int x, int y) {
  return x + y;  // Return the sum of x and y
}
```

You can then call this function from other parts of your program by using its name followed by a pair of parentheses and any required arguments:

```cpp
int result = add(10, 5);  // Call the add function with the arguments 10 and 5
```

Functions can also accept optional arguments by using default values. For example:

```cpp
int add(int x, int y, int z = 0) {
  return x + y + z;  // Return the sum of x, y, and z
}

int result1 = add(10, 5);  // Call the add function with the arguments 10 and 5, z will be 0
int result2 = add(10, 5, 3);  // Call the add function with the arguments 10, 5, and 3
```

In this example, the `add` function can be called with two or three arguments. If only two arguments are provided, the third argument will default to `0`.