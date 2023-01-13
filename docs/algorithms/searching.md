# Searching Algorithms

These algorithms are used to search for an item in a collection of data, such as finding a specific element in an array. Examples include linear search and binary search.

There are several common types of searching algorithms, including:

- **Linear search**: Linear search, also known as a sequential search, is a simple search algorithm that checks each element of an array sequentially from the beginning to the end. The time complexity of linear search is $O(n)$, where n is the number of elements in the array, so it becomes less efficient as the size of the data set increases.

- **Binary search**: Binary search is an efficient algorithm that can be used to search a sorted array. The algorithm works by repeatedly dividing the search interval in half. The time complexity of binary search is $O(\log{n})$, making it more efficient than linear search for large data sets.

- **Interpolation search**: Interpolation search is an algorithm that can be used to search a sorted array. It improves on binary search by assuming that the target value is uniformly distributed throughout the array, and thus narrowing down the search interval based on where the target value is likely to be. Its time complexity is $O\left(\log{(\log{n})}\right)$

- **Jump search**: Jump search is an efficient algorithm that can be used to search a sorted array. The algorithm works by jumping a fixed number of elements before starting a linear search. The time complexity of Jump search is $O(\sqrt{n})$.

- **Exponential search**: Exponential search is an efficient algorithm that can be used to search a sorted array. The algorithm works by first searching for the target value in the first two elements of the array, then the next four elements, then the next 8 elements, and so on. The time complexity of Exponential search is $O(\log{n})$

- **Fibonacci search**: The Fibonacci search algorithm is an efficient algorithm that can be used to search a sorted array. It improves on the binary search algorithm by dividing the search interval in proportion to the Fibonacci series, which is closely related to the golden ratio.

All of these algorithms have their own specific use case and trade-offs, you can pick the best one based on the specific requirements of your problem.

It's worth noting that some of the searching algorithms can be applied only on sorted arrays, so if the array is not sorted and the array size is not huge, the best approach would be linear search, otherwise, you need to sort the array first then use a more efficient algorithm like binary search.