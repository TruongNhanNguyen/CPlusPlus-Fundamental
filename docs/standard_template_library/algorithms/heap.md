# The STL Heap Algorithms

Heap algorithms are used to transform a range of elements into a heap, and to perform operations on a heap such as extracting the maximum element. Here are some examples of heap algorithms in the STL:

1. `make_heap`: This algorithm transforms a range of elements into a heap. It takes two iterators as arguments, indicating the beginning and end of the range to be transformed. The heap is constructed according to a specified comparison function, which can be provided as an optional third argument. By default, the comparison function is `std::less<T>`, which means that the heap is a max-heap, with the largest element at the top.

2. `pop_heap`: This algorithm removes the top element from a heap. It takes two iterators as arguments, indicating the beginning and end of the heap. The removed element is moved to the end of the range, and the heap is restructured to maintain the heap property.

3. `push_heap`: This algorithm inserts an element into a heap. It takes two iterators as arguments, indicating the beginning and end of the heap. The element is inserted at the end of the range, and the heap is restructured to maintain the heap property.