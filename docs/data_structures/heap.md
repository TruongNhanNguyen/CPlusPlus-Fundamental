# Heap

A heap is a specialized tree-based data structure that satisfies the heap property. The most common types of heaps are the binary heap and the binary heap is of two types:

- **Min heap**: In which the value of the root node is less than or equal to the values of its children.
- **Max heap**: In which the value of the root node is greater than or equal to the values of its children.

Heaps are typically implemented as arrays, and the elements are rearranged to satisfy the heap property as new elements are inserted or removed. Common operations that can be performed on a heap include:

- **Insertion**: Adding a new element to the heap
- **Deletion**: Removing the root element from the heap
- **Extract Min/Max**: Removing the root element and returning its value
- **Peek Min/Max**: Returning the value of the root element without removing it
- **Building Heap**: Given an array of element, building a heap out of it.

## Implementation

### Heap class

Let's implement a Heap class in C++ that can be a min heap or a max heap and with basic functions such as insertion, deletion and extraction of minimum or maximum element

```cpp
template <typename T>
class Heap {
private:
    vector<T> heap;
    bool isMin;
    void heapify(int index) {
        int extreme = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < heap.size() && (isMin ? heap[left] < heap[extreme] : heap[left] > heap[extreme]))
            extreme = left;
        if (right < heap.size() && (isMin ? heap[right] < heap[extreme] : heap[right] > heap[extreme]))
            extreme = right;
        if (extreme != index) {
            swap(heap[index], heap[extreme]);
            heapify(extreme);
        }
    }
public:
    Heap(bool isMin) : isMin(isMin) {}
    void insert(T data) {
        heap.push_back(data);
        int index = heap.size() - 1;
        while (index > 0 && (isMin ? heap[index] < heap[(index - 1) / 2] : heap[index] > heap[(index - 1) / 2])) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    T extractExtreme() {
        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return min;
    }
};
```

### Test Cases

You can create an instance of this class by specifying whether it is a min heap or a max heap, and then call its `insert`, `extractExtreme` methods.

```cpp
void test_heap() {
    Heap<int> min_heap(true);
    Heap<int> max_heap(false);

    min_heap.insert(5);
    min_heap.insert(3);
    min_heap.insert(10);
    min_heap.insert(1);
    min_heap.insert(2);

    std::cout << "Min Heap: ";
    while (!min_heap.empty()) {
        std::cout << min_heap.extractExtreme() << " ";
    }
    std::cout << std::endl;

    max_heap.insert(5);
    max_heap.insert(3);
    max_heap.insert(10);
    max_heap.insert(1);
    max_heap.insert(2);

    std::cout << "Max Heap: ";
    while (!max_heap.empty()) {
        std::cout << max_heap.extractExtreme() << " ";
    }
    std::cout << std::endl;
}
```

It creates two instances of the `Heap` class, one for min heap and one for max heap, and inserts some values in them. The test case then uses the `extractExtreme` method to extract and print out the elements from the heap in the correct order, so that for min heap the output is sorted in ascending order and for max heap the output is sorted in descending order. 

You can add various test cases to test this implementation and also test the functionality of this class thoroughly.

Please note that this is just a basic implementation and there are many other variations and more advanced algorithms that can be implemented on heap data structure like *Heap* sort, *Dijkstra's* algorithm, *Prim's* algorithm etc. 