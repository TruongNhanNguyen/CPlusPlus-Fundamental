#include <bits/stdc++.h>

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~LinkedList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtBeginning(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtEnd(T data)
    {
        if (head == nullptr)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node<T>(data);
        }
        size++;
    }

    void insertAtPosition(T data, int position)
    {
        if (position == 1)
        {
            insertAtBeginning(data);
            return;
        }
        if (position == size + 1)
        {
            insertAtEnd(data);
            return;
        }
        if (position < 1 || position > size + 1)
        {
            return;
        }
        Node<T> *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node<T> *newNode = new Node<T>(data);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node<T> *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        size--;
    }

    void deleteAtPosition(int position)
    {
        if (head == nullptr)
        {
            return;
        }
        if (position < 1 || position > size)
        {
            return;
        }
        if (position == 1)
        {
            deleteAtBeginning();
            return;
        }
        if (position == size)
        {
            deleteAtEnd();
            return;
        }
        Node<T> *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node<T> *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        size--;
    }

    T get(int position)
    {
        if (position < 1 || position > size)
        {
            return -1;
        }
        Node<T> *temp = head;
        for (int i = 1; i < position; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};

void test_linked_list()
{
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

int main()
{
    test_linked_list();
    return 0;
}