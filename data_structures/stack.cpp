#include <bits/stdc++.h>

template <typename T>
class Stack
{
private:
    T *data;
    int size;
    int capacity;

public:
    Stack(int capacity) : size(0), capacity(capacity)
    {
        data = new T[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(T value)
    {
        if (size == capacity)
        {
            throw std::runtime_error("Stack overflow");
        }
        data[size] = value;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack underflow");
        }
        size--;
        return data[size];
    }

    T peek()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return data[size - 1];
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

void test_stack()
{
    Stack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Stack top element: " << stack.peek() << std::endl;
    stack.pop();
    std::cout << "Stack top element after pop: " << stack.peek() << std::endl;
    if (stack.isEmpty())
        std::cout << "Stack is empty" << std::endl;
    else
        std::cout << "Stack is not empty" << std::endl;
    stack.pop();
    stack.pop();
    if (stack.isEmpty())
        std::cout << "Stack is empty" << std::endl;
    else
        std::cout << "Stack is not empty" << std::endl;
    try
    {
        stack.pop();
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
    try
    {
        std::cout << "Stack top element: " << stack.peek() << std::endl;
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }
}

int main()
{
    test_stack();
    return 0;
}