# The STL Iterators

Iterators are objects that allow you to iterate over the elements of a container or range, and to perform operations such as access, modification, and insertion. In C++, iterators are implemented as template classes, and they are defined in the `<iterator>` header.

There are five categories of iterators in C++: input iterators, output iterators, forward iterators, bidirectional iterators, and random-access iterators. Each category of iterators has a corresponding iterator trait class, which can be used to determine the properties of an iterator. Here is a brief summary of the properties of each category of iterators:

- **Input iterators**: These iterators allow you to read the elements of a container or range in a single pass, from beginning to end. They support the `operator*`, `operator->`, and `operator++` operations, and they can be tested for equality and inequality.

- **Output iterators**: These iterators allow you to write to the elements of a container or range in a single pass, from beginning to end. They support the `operator*` and `operator++` operations, and they can be tested for equality and inequality.

- **Forward iterators**: These iterators combine the properties of input iterators and output iterators, and they allow you to read and write the elements of a container or range in a single pass, from beginning to end. They also support the `operator*` and `operator++` operations, and they can be tested for equality and inequality.

- **Bidirectional iterators**: These iterators add the ability to move backwards in a container or range, in addition to the properties of forward iterators. They support the `operator*`, `operator->`, `operator++` and `operator--` operations, and they can be tested for equality and inequality.

- **Random-access iterators**: These iterators allow you to access and modify the elements of a container or range with constant time complexity, using the `operator[]` and `operator+` operations. They also support all the operations of bidirectional iterators, and they can be tested for equality, inequality, less than, greater than, less than or equal to, and greater than or equal to.

Here is an example of using iterators to iterate over the elements of a vector and to perform some operations

```cpp
```