# Stack

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed. Stacks are often represented by an array or a linked list, with the last element added being the first element in the array or at the head of the linked list.

Stacks are often used in computer science for a variety of tasks, such as:

- Memory management, where the stack is used to keep track of function call frames.
- Backtracking, where the stack is used to keep track of previous states.
- Parsing, where the stack is used to evaluate expressions.

The main operations that can be performed on a stack are:

- `push`: adds an element to the top of the stack.
- `pop`: removes the top element from the stack.
- `peek`: returns the top element of the stack without removing it.
- `isEmpty`: checks if the stack is empty.

The time complexity of these operations is typically constant, $O(1)$, since the element is always added or removed from the top of the stack.

## Implementation

### Stack

```cpp
template <typename T>
class Stack {
  private:
    T* data;
    int size;
    int capacity;
  public:
    Stack(int capacity) : size(0), capacity(capacity) {
      data = new T[capacity];
    }

    ~Stack() {
      delete[] data;
    }

    void push(T value) {
      if (size == capacity) {
        throw runtime_error("Stack overflow");
      }
      data[size] = value;
      size++;
    }

    T pop() {
      if (isEmpty()) {
        throw runtime_error("Stack underflow");
      }
      size--;
      return data[size];
    }

    T peek() {
      if (isEmpty()) {
        throw runtime_error("Stack is empty");
      }
      return data[size-1];
    }

    bool isEmpty() {
      return size == 0;
    }
};
```

This stack class uses an array to store the elements, and has a fixed capacity. The class has a constructor that takes a single argument for the initial capacity, and a destructor that deallocates memory when the stack is no longer needed.
The class defines several member functions such as `push`, `pop`, `peek`, and `isEmpty` which can add elements, remove elements, check the top element and check if the stack is empty respectively.

### Test cases

```cpp
void test_stack() {
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Stack top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Stack top element after pop: " << stack.peek() << endl;
    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
    stack.pop();
    stack.pop();
    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
    try {
        stack.pop();
    } catch (const runtime_error& error) {
        cout << error.what() << endl;
    }
    try {
        cout << "Stack top element: " << stack.peek() << endl;
    } catch (const runtime_error& error) {
        cout << error.what() << endl;
    }
}
```

In this test cases function, we're creating a new stack with capacity 5, then performing several operations such as adding elements to the stack using the `push` function, checking the top element of the stack using the `peek` function,removing elements from the top of the stack using the `pop` function and checking if the stack is empty using the `isEmpty` function. At last, it also has `try-catch` block to handle the exception if the stack is empty and the `pop` function is called.