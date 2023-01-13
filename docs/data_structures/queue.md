# Queue

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. This means that the first element added to the queue is the first one to be removed. Queues are often represented by an array or a linked list, with the first element added being the first element in the array or at the head of the linked list.

Queues are often used in computer science for a variety of tasks, such as:

- *Scheduling tasks*, where the queue is used to keep track of pending tasks that need to be executed.
- *Handling network packets*, where the queue is used to store incoming packets that need to be processed.
- *Breadth-first search* algorithm, where the queue is used to keep track of the next set of nodes to explore.

The main operations that can be performed on a queue are:

- `enqueue`: adds an element to the end of the queue.
- `dequeue`: removes the first element from the queue.
- `peek`: returns the first element of the queue without removing it.
- `isEmpty`: checks if the queue is empty.


The time complexity of these operations is typically constant, $O(1)$, since the element is always added or removed from the front or end of the queue.

## Implementation

### Queue class

```cpp
template <typename T>
class Queue {
  private:
    T* data;
    int size;
    int capacity;
    int head;
    int tail;
  public:
    Queue(int capacity) : size(0), capacity(capacity), head(0), tail(capacity - 1) {
      data = new T[capacity];
    }

    ~Queue() {
      delete[] data;
    }

    void enqueue(T value) {
      if (size == capacity) {
        throw runtime_error("Queue overflow");
      }
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue underflow");
        }
        T value = data[head];
        head = (head + 1) % capacity;
        size--;
        return value;
    }

    T peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return data[head];
    }

    bool isEmpty() {
        return size == 0;
    }
};
```

This queue class uses an array to store the elements and has a fixed `capacity`. The class has a constructor that takes a single argument for the initial `capacity`, and a destructor that deallocates memory when the queue is no longer needed.
The class defines several member functions such as `enqueue`, `dequeue`, `peek`, and `isEmpty` which can add elements, remove elements, check the first element and check if the queue is empty respectively.

### Test cases

```cpp
void test_queue() {
    Queue<int> queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Queue front element: " << queue.peek() << endl;
    queue.dequeue();
    cout << "Queue front element after dequeue: " << queue.peek() << endl;
    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
    queue.dequeue();
    queue.dequeue();
    if (queue.isEmpty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
    try {
        queue.dequeue();
    } catch (const runtime_error& error) {
        cout << error.what() << endl;
    }
    try {
        cout << "Queue front element: " << queue.peek() << endl;
    } catch (const runtime_error& error) {
        cout << error.what() << endl;
    }
}
```

In this test cases function, we're creating a new queue with capacity 5, then performing several operations such as adding elements to the queue using the `enqueue` function, checking the front element of the queue using the `peek` function,removing elements from the front of the queue using the `dequeue` function and checking if the queue is empty using the `isEmpty` function. At last, it also has `try-catch` block to handle the exception if the queue is empty and the `dequeue` function is called.

It's important to note that this is just a basic implementation of a queue, and in a real-world scenario, you may need to add additional functionality or optimize the performance of the class.