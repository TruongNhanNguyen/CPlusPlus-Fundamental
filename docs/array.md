# Array

An array is a data structure that stores a collection of values of the same type. In C++, you can declare an array by specifying the type of the elements it will store and the number of elements it will hold. Here is an example of how you can declare and initialize an array of integers in C++:

```cpp
int arr[5] = {1, 2, 3, 4, 5};  // Declare and initialize an array of 5 integers
```

You can also modify the elements of an array using the same notation. For example:

```cpp
arr[0] = 10;  // Set the first element of the array to 10
```

You can also use a loop to iterate over the elements of an array. For example:

```cpp
for (int i = 0; i < 5; i++) {
  cout << arr[i] << " ";  // Print each element of the array followed by a space
}
```

There are a few more things you should know about arrays in C++:

1. You can also declare an array with a size that is not known at compile time. To do this, you can use the `new` operator to dynamically allocate memory for the array:

    ```cpp
    int size;
    cin >> size;  // Read the size of the array from the user
    int* arr = new int[size];  // Dynamically allocate memory for the array
    ```

2. You can use the `delete[]` operator to free the memory that was dynamically allocated for an array:

    ```cpp
    delete[] arr;  // Free the memory that was dynamically allocated for the array
    ```

3. You can pass an array as an argument to a function by specifying the name of the array without the square brackets. For example:
    
    ```cpp
    void print_array(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";  // Print each element of the array followed by a space
        }
    }

    int arr[5] = {1, 2, 3, 4, 5};
    print_array(arr, 5);  // Call the print_array function with the array and its size as arguments
    ```

4. C++ also has multidimensional arrays, which are arrays of arrays. You can declare a multidimensional array by specifying multiple sets of square brackets. For example:

    ```cpp
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};  // Declare and initialize a 2x3 array
    ```

    You can access the elements of a multidimensional array using multiple sets of square brackets. For example:

    ```cpp
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";  // Print each element of the array followed by a space
        }
    }

    ```