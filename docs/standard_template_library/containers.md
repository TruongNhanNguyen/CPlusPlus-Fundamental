# The STL Containers

The STL provides several types of containers that can store and manage collections of objects. Each container has its own characteristics and is suitable for different use cases.

Here is a brief overview of the main types of containers in the STL:

1. `vector`: A `vector` is a dynamic array that can grow or shrink as needed. It provides fast random access to its elements and efficient insertion and removal at the end. It uses contiguous memory to store its elements, which means that all elements are stored in a single block of memory.

2. `list`: A `list` is a doubly-linked list that provides fast insertion and removal at any position, but slow random access to its elements. It uses non-contiguous memory to store its elements, which means that each element is stored in a separate block of memory.

3. `deque`: A `deque` (double-ended queue) is a dynamic array that can grow or shrink as needed. It provides fast insertion and removal at both ends, but slow random access to its elements. It uses contiguous memory to store its elements, which means that all elements are stored in a single block of memory.

4. `set`: A `set` is an ordered container that stores unique elements in a balanced binary tree. It provides fast insertion, removal, and lookup of elements, but does not allow duplicate elements.

5. `map`: A `map` is an ordered container that stores key-value pairs in a balanced binary tree. It provides fast insertion, removal, and lookup of elements based on the key.

6. `unordered_*`: The `unordered_*` containers are hash tables that store elements in an unordered fashion. They provide fast insertion, removal, and lookup of elements, but do not preserve the order of the elements.

Here is an example of using the vector and list containers in C++:

```cpp
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30};
    v.push_back(40); // v: { 10, 20, 30, 40 }
    v.pop_back();    // v: { 10, 20, 30 }
    v[1] = 25;       // v: { 10, 25, 30 }

    std::list<int> l{10, 20, 30};
    l.push_back(40);           // l: { 10, 20, 30, 40 }
    l.pop_back();              // l: { 10, 20, 30 }
    l.push_front(5);           // l: { 5, 10, 20, 30 }
    l.pop_front();             // l: { 10, 20, 30 }
    l.insert(++l.begin(), 15); // l: { 10, 15, 20, 30 }
    l.erase(--l.end());        // l: { 10, 15, 30 }

    return 0;
}
```