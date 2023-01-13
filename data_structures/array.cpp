#include <bits/stdc++.h>

template <typename T>
class Array
{
private:
    T *data;
    int size;
    int capacity;
    void resize(int newCapacity)
    {
        T *temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

public:
    Array() : size(0), capacity(1)
    {
        data = new T[capacity];
    }

    Array(int s) : size(s), capacity(s)
    {
        data = new T[capacity];
    }

    Array(const Array &arr) : size(arr.size), capacity(arr.capacity)
    {
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr.data[i];
        }
    }

    ~Array()
    {
        delete[] data;
    }

    T &operator[](int index)
    {
        return data[index];
    }

    Array &operator=(const Array &arr)
    {
        if (&arr == this)
        {
            return *this;
        }
        delete[] data;
        size = arr.size;
        capacity = arr.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = arr.data[i];
        }
        return *this;
    }

    void push_back(T value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size] = value;
        size++;
    }

    void pop_back()
    {
        if (size > 0)
        {
            size--;
            if (size <= (capacity / 4))
            {
                resize(capacity / 2);
            }
        }
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    bool empty()
    {
        return size == 0;
    }

    void clear()
    {
        size = 0;
        resize(1);
    }
};

void test_array()
{
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    std::cout << "Array size: " << arr.getSize() << std::endl;
    std::cout << "Array capacity: " << arr.getCapacity() << std::endl;
    for (int i = 0; i < arr.getSize(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    arr.pop_back();
    std::cout << "Array size after pop: " << arr.getSize() << std::endl;
    std::cout << "Array capacity after pop: " << arr.getCapacity() << std::endl;

    Array<int> arr2 = arr;
    std::cout << "Copy Array size: " << arr2.getSize() << std::endl;
    std::cout << "Copy Array capacity: " << arr2.getCapacity() << std::endl;
    for (int i = 0; i < arr2.getSize(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    if (arr.empty())
        std::cout << "Array is empty" << std::endl;
    else
        std::cout << "Array is not empty" << std::endl;

    arr2.clear();
    if (arr2.empty())
        std::cout << "Array is empty after clearing" << std::endl;
    else
        std::cout << "Array is not empty after clearing" << std::endl;
}

int main()
{
    test_array();
    return 0;
}