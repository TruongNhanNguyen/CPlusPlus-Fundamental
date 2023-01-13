# Linked List

A linked list is a dynamic data structure that consists of a sequence of elements, where each element, called a node, contains a reference to the next element, and sometimes the previous element. Each node typically stores a value, and the reference to the next node, in addition, there are several types of linked lists:

1. **Singly linked list**: In this type of linked list, each node only has a reference to the next node. They're typically used for implementing stacks, queues, and other data structures where the order of the elements is important.

2. **Doubly linked list**: In this type of linked list, each node has a reference to the next and previous node. This allows for traversing the list in both directions, and makes some operations, such as inserting and deleting nodes, more efficient.

3. **Circular linked list**: In this type of linked list, the last node points back to the first node, creating a circular structure. There are two types, singly linked and doubly linked.

There are several operations that can be performed on a linked list, such as:

- **Insertion**: Adding a new node to the list at a specific position.
- **Deletion**: Removing a node from the list at a specific position.
- **Search**: Finding a node with a specific value in the list.
- **Traversal**: Iterating through all the nodes of the list.

The time complexity of these operations can vary depending on the position of the node and the type of linked list. Insertion and deletion, for example, typically have a constant time complexity of $O(1)$ when the position of the node is known, but a linear time complexity of $O(n)$ when the position is not known.

Linked list is typically used in cases where the size of the data is unknown, like when the data is received in chunks, or when it's possible that the data size will grow or shrink.

## Implementation

### Linked List class

```cpp
template <typename T>
class Node {
  public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
  private:
    Node<T>* head;
    int size;
  public:
    LinkedList() {
      head = nullptr;
      size = 0;
    }

    ~LinkedList() {
      Node<T>* temp = head;
      while (temp != nullptr) {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
      }
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return head == nullptr;
    }

    void insertAtBeginning(T data) {
      Node<T>* newNode = new Node<T>(data);
      newNode->next = head;
      head = newNode;
      size++;
    }

    void insertAtEnd(T data) {
      if (head == nullptr) {
        head = new Node<T>(data);
      } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = new Node<T>(data);
      }
      size++;
    }

    void insertAtPosition(T data, int position) {
      if (position == 1) {
        insertAtBeginning(data);
        return;
      }
      if (position == size + 1) {
        insertAtEnd(data);
        return;
      }
      if (position < 1 || position > size + 1) {
        return;
      }
      Node<T>* temp = head;
      for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
      }
      Node<T>* newNode = new Node<T>(data);
      newNode->next = temp->next;
      temp->next = newNode;
      size++;
    }

    void deleteAtBeginning() {
      if (head == nullptr) {
        return;
      }
      Node<T>* temp = head;
      head = head->next
            delete temp;
      size--;
    }

    void deleteAtEnd() {
      if (head == nullptr) {
        return;
      }
      if (head->next == nullptr) {
        delete head;
        head = nullptr;
        size--;
        return;
      }
      Node<T>* temp = head;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
      size--;
    }

    void deleteAtPosition(int position) {
      if (head == nullptr) {
        return;
      }
      if (position < 1 || position > size) {
        return;
      }
      if (position == 1) {
        deleteAtBeginning();
        return;
      }
      if (position == size) {
        deleteAtEnd();
        return;
      }
      Node<T>* temp = head;
      for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
      }
      Node<T>* temp2 = temp->next;
      temp->next = temp->next->next;
      delete temp2;
      size--;
    }
    
    T get(int position) {
        if (position < 1 || position > size) {
            return -1;
        }
        Node<T>* temp = head;
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
};
```

This class provides basic functionalities of a singly linked list such as adding element at the begining, end and at a particular position, removing elements from the beginning, end and a particular position.

### Test cases

```cpp
void test_linked_list() {
    LinkedList<int> list;
    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtPosition(0, 1);
    std::cout << "Linked List size: " << list.getSize() << std::endl;
    std::cout << "Linked List element at position 2: " << list.get(2) << std::endl;
    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAtPosition(1);
    std::cout << "Linked List size after deletions: " << list.getSize() << std::endl;
    if (list.isEmpty())
        std::cout << "Linked List is empty" << std::endl;
    else
        std::cout << "Linked List is not empty" << std::endl;
}
```

In this test case function, we're creating a new linked list and performing several operations such as adding elements at the beginning and end, at a specific position, retrieving an element at specific position, and removing elements from the beginning, end and at a specific position and checking whether the list is empty or not.

> **Note:** It's important to note that this is just a basic implementation of a singly linked list, and in a real-world scenario, you may need to add additional functionality or optimize the performance of the class.