# The STL Algorithms

The STL provides a wide range of algorithms that can be used to perform various operations on containers and ranges of elements. Here is a brief overview of some of the main types of algorithms in the STL:

1. **Sorting algorithms**: These algorithms are used to sort the elements of a container or range in ascending or descending order. Examples include `sort`, `stable_sort`, and `nth_element`.

2. **Searching algorithms**: These algorithms are used to search for specific elements in a container or range. Examples include `find`, `count`, and `binary_search`.

3. **Permutation algorithms**: These algorithms are used to rearrange the elements of a container or range in various ways. Examples include `reverse`, `rotate`, and `random_shuffle`.

4. **Set algorithms**: These algorithms are used to perform set operations on containers and `ranges`, such as `union`, `intersection`, and difference. Examples include `set_union`, `set_intersection`, and `set_difference`.

5. **Heap algorithms**: These algorithms are used to transform a range into a heap, or to perform operations on a heap. Examples include `make_heap`, `push_heap`, and `pop_heap`.

Here is an example of using the sort algorithm to sort a vector of integers in ascending order:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{30, 20, 10, 40};

    std::sort(v.begin(), v.end()); // v: { 10, 20, 30, 40 }

    for (int x : v)
    {
        std::cout << x << " "; // Prints "10 20 30 40"
    }
    std::cout << std::endl;

    return 0;
}
```