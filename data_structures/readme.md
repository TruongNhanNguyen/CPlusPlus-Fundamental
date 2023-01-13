# Data Structures

Data structure is a way of organizing and storing data in a computer so that it can be accessed and modified efficiently. Examples of common data structures include arrays, linked lists, stacks, queues, trees, and graphs. Each data structure has its own set of advantages and use cases, and choosing the right one for a particular problem can have a big impact on the performance of an algorithms.

There are many different types of data structures, each with its own set of advantages and use cases. Here are some common data structures and their characteristics:

- [Arrays](../docs/data_structures/array.md): An array is a fixed-size sequence of elements of the same type. Elements are stored in contiguous memory locations and can be accessed directly by their index. Accessing an element in an array has a constant time complexity of $O(1)$, but searching for an element has a linear time complexity of $O(n)$.

- [Linked Lists](../docs/data_structures/linked_list.md): A linked list is a dynamic sequence of elements, where each element (node) contains a reference to the next element. Linked lists can be singly-linked, where each node points to the next one, or doubly-linked, where each node points to both the next and previous nodes. Inserting or deleting a node from a linked list has a constant time complexity of $O(1)$, but searching for a node has a linear time complexity of $O(n)$.

- [Stack](../docs/data_structures/stack.md): A stack is a Last-In-First-Out (LIFO) data structure, where elements are added and removed from the top of the stack. Accessing the top element of a stack has a constant time complexity of $O(1)$, but searching for an element has a linear time complexity of $O(n)$.

- [Queue](../docs/data_structures/queue.md): A queue is a First-In-First-Out (FIFO) data structure, where elements are added to the back of the queue and removed from the front. Accessing the front element of a queue has a constant time complexity of $O(1)$, but searching for an element has a linear time complexity of $O(n)$.

- [Trees](../docs/data_structures/tree.md): A tree is a non-linear data structure that simulates a hierarchical structure with a root and zero or more child nodes. There are several types of trees, such as binary trees, where each node has at most two children, and AVL trees, which are balanced binary trees that always have a height of $O(\log{n})$. Searching for an element in a binary tree has a time complexity of $O(\log{n})$, but it may be less efficient with skewed or unbalanced trees.

- [Hash table](../docs/data_structures/hash_table.md): A hash table is a data structure that uses a hash function to map keys to indices in an array, where the corresponding values can be stored. Hash tables are used to implement various types of associative arrays, or dictionaries, and are efficient at searching, inserting, and deleting elements with a time complexity of $O(1)$ on average.

- [Graphs](../docs/data_structures/graph.md): Graphs are a non-linear data structure that consist of a set of vertices and edges that connect them. They have various types like directed and undirected graph, weighted and unweighted graph. Each type have their own properties and use cases.

- [Trie](../docs/data_structures/trie.md): A trie, also known as a prefix tree, is a tree-like data structure that is used to store a collection of strings where each node represents a character in a string. Tries are very efficient for searching and inserting strings, and are commonly used in spell-checking, autocomplete, and IP routing applications.

- [Heap](../docs/data_structures/heap.md): A heap is a complete binary tree where the value of each node is greater than or equal to its children (in a max-heap) or less than or equal to its children (in a min-heap). Heaps are typically implemented using an array, and can be efficiently used for sorting, searching for the minimum or maximum element, and implementing priority queues.

- And so on: AVL Tree, Splay Tree, Red-Black Tree, etc