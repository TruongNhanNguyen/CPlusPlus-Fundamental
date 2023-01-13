#include <bits/stdc++.h>

template <typename T>
class Queue
{
private:
    T *data;
    int size;
    int capacity;
    int head;
    int tail;

public:
    Queue(int capacity) : size(0), capacity(capacity), head(0), tail(capacity - 1)
    {
        data = new T[capacity];
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(T value)
    {
        if (size == capacity)
        {
            throw std::runtime_error("Queue overflow");
        }
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue underflow");
        }
        T value = data[head];
        head = (head + 1) % capacity;
        size--;
        return value;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return data[head];
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

void test_queue()
{
    Queue<int> queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue front element: " << queue.peek() << std::endl;
    queue.dequeue();
    std::cout << "Queue front element after dequeue: " << queue.peek() << std::endl;
    if (queue.isEmpty())
        std::cout << "Queue is empty" << std::endl;
    else
        std::cout << "Queue is not empty" << std::endl;
    queue.dequeue();
    queue.dequeue();
    if (queue.isEmpty())
        std::cout << "Queue is empty" << std::endl;
    else
        std::cout << "Queue is not empty" << std::endl;
    try
    {
        queue.dequeue();
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
    try
    {
        std::cout << "Queue front element: " << queue.peek() << std::endl;
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

int main()
{
    test_queue();
    return 0;
}