# The STL Searching Algorithms

Searching algorithms are used to search for specific elements or values in a container or range. Here are some examples of searching algorithms in the STL:

1. `find`: This algorithm searches for a specific element in a range and returns an iterator to the first occurrence of the element, or `end` if the element is not found. It can be used with any type of range, as long as the element type is comparable using the `==` operator. Here is an example of using `find` to search for an element in a `vector`.

2. `count`: This algorithm counts the number of occurrences of a specific element in a range. It returns the count as an integer. Here is an example of using `count` to count the number of occurrences of an element in a `vector`.

3. `binary_search`: This algorithm performs a binary search on a sorted range to find a specific element. It returns a boolean value indicating whether the element was found or not. Here is an example of using `binary_search` to search for an element in a sorted `vector`.