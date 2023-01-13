# The STL Sorting Algorithms

Sorting algorithms are used to rearrange the elements of a container or range in a specific order, such as ascending or descending. Here are some examples of sorting algorithms in the STL.

1. `sort`: This is a general-purpose sorting algorithm that uses a comparison function to determine the order of the elements. By default, it sorts the elements in ascending order. Here is an example of using sort to sort a vector of integers in descending order.

2. `stable_sort`: This sorting algorithm is similar to sort, but it preserves the relative order of elements that compare equal. This is useful if you want to sort a range and preserve the original order of elements that have the same value.

3. `partial_sort`: This sorting algorithm sorts the elements in a range, but only up to a certain point. It is useful if you want to find the N smallest or largest elements in a range, without having to sort the entire range.