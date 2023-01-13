# Array

An array is a fundamental data structure in computer science. It is a fixed-size sequence of elements of the same type, where each element is identified by its index, also known as its position or location in the array. Arrays are stored in contiguous memory locations, which means that all the elements are next to each other in memory, making it easy and efficient to access any element directly by its index.

In many programming languages, arrays are implemented as objects that have properties and methods for managing the elements, such as size, capacity, and so on. They are also often used to implement other data structures, such as stacks and queues.

Here are some common operations that can be performed on an array:

- **Access**: Retrieving the value of an element at a specific index.
- **Insertion**: Adding an element at a specific index.
- **Deletion**: Removing an element at a specific index.
- **Search**: Finding the index of an element with a specific value.
- **Traversal**: Iterating through all the elements of the array.
- **Sorting**: Arranging the elements in a specific order, such as ascending or descending.

The time complexity of these operations can vary depending on the implementation, but most arrays have a constant time complexity of $O(1)$ for accessing and inserting elements, and a linear time complexity of $O(n)$ for searching and deleting elements. However, sorting an array can have a time complexity of $O(n\log{n})$ for more efficient algorithms such as Merge and Quick sort.

Arrays have many use cases, and they are often used to store large amounts of data that need to be accessed quickly, such as lists of numbers, images, and so on. They are also used to implement other data structures such as stacks and queues, and used in algorithms for sorting, searching, and traversing data.

It's worth noting that arrays have a fixed size, if you need dynamic data structures with a size that can change at runtime you can use dynamic arrays or other data structures such as linked list.

## Implementation

### Array class

```cpp
template <typename T>
class Array {
  private:
    T *data;
    int size;
    int capacity;
    void resize(int newCapacity) {
      T *temp = new T[newCapacity];
      for (int i = 0; i < size; i++) {
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      capacity = newCapacity;
    }
  public:
    Array() : size(0), capacity(1) {
      data = new T[capacity];
    }

    Array(int s) : size(s), capacity(s) {
      data = new T[capacity];
    }

    Array(const Array& arr) : size(arr.size), capacity(arr.capacity) {
      data = new T[capacity];
      for (int i = 0; i < size; i++) {
        data[i] = arr.data[i];
      }
    }

    ~Array() {
      delete[] data;
    }

    T& operator[](int index) {
      return data[index];
    }

    Array& operator=(const Array& arr) {
      if (&arr == this) {
        return *this;
      }
      delete[] data;
      size = arr.size;
      capacity = arr.capacity;
      data = new T[capacity];
      for (int i = 0; i < size; i++) {
        data[i] = arr.data[i];
      }
      return *this;
    }

    void push_back(T value) {
      if (size == capacity) {
        resize(capacity * 2);
      }
      data[size] = value;
      size++;
    }

    void pop_back() {
      if (size > 0) {
        size--;
        if (size <= (capacity / 4)) {
          resize(capacity / 2);
        }
      }
    }

    int getSize() {
      return size;
    }

    int getCapacity() {
      return capacity;
    }

    bool empty() {
      return size == 0;
    }

    void clear() {
      size = 0;
      resize(1);
    }
};
```

This class defines an array that can store elements of any type using templates. The class has a constructor that takes a single argument for the initial size, or default constructor for creating empty array.It also uses copy constructor for creating a copy of array. The class also has a destructor that deallocates memory when the array is no longer needed.

The class overloads the assignment operator, to make assignment between two arrays, and the square bracket operator, to access elements by index. The class also defines several member functions such as push_back, `pop_back`, `getSize`, `getCapacity`, `empty`, and clear which can add or remove elements to the end of array, retrieve the current size and capacity of the array, check if the array is empty and `clear` the array respectively.

The `Array` class also includes a resize function that is used when the array needs to upgrade.

### Test cases

```cpp
void test_array() {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    std::cout << "Array size: " << arr.getSize() << std::endl;
    std::cout << "Array capacity: " << arr.getCapacity() << std::endl;
    for (int i = 0; i < arr.getSize(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    arr.pop_back();
    std::cout << "Array size after pop: " << arr.getSize() << std::endl;
    std::cout << "Array capacity after pop: " << arr.getCapacity() << std::endl;

    Array<int> arr2 = arr;
    std::cout << "Copy Array size: " << arr2.getSize() << std::endl;
    std::cout << "Copy Array capacity: " << arr2.getCapacity() << std::endl;
    for (int i = 0; i < arr2.getSize(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    if (arr.empty())
        std::cout << "Array is empty" << std::endl;
    else
        std::cout << "Array is not empty" << std::endl;

    arr2.clear();
    if (arr2.empty())
        std::cout << "Array is empty after clearing" << std::endl;
    else
        std::cout << "Array is not empty after clearing" << std::endl;
}
```

In this test case we are creating a new array and performing several operations such as adding elements using `push_back`, removing elements using `pop_back`, printing the size, capacity and elements of the array, then creating a copy of the array and printing its size, capacity and elements. Also checking the array is empty or not. At last clearing the array and checking the array is empty or not.