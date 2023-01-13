#include <bits/stdc++.h>

template <typename T>
class Heap
{
private:
    std::vector<T> heap;
    bool isMin;
    void heapify(int index)
    {
        int extreme = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < heap.size() && (isMin ? heap[left] < heap[extreme] : heap[left] > heap[extreme]))
            extreme = left;
        if (right < heap.size() && (isMin ? heap[right] < heap[extreme] : heap[right] > heap[extreme]))
            extreme = right;
        if (extreme != index)
        {
            std::swap(heap[index], heap[extreme]);
            heapify(extreme);
        }
    }

public:
    Heap(bool isMin) : isMin(isMin) {}
    bool empty() { return heap.empty(); }
    void insert(T data)
    {
        heap.push_back(data);
        int index = heap.size() - 1;
        while (index > 0 && (isMin ? heap[index] < heap[(index - 1) / 2] : heap[index] > heap[(index - 1) / 2]))
        {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    T extractExtreme()
    {
        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return min;
    }
};

void test_heap()
{
    Heap<int> min_heap(true);
    Heap<int> max_heap(false);

    min_heap.insert(5);
    min_heap.insert(3);
    min_heap.insert(10);
    min_heap.insert(1);
    min_heap.insert(2);

    std::cout << "Min Heap: ";
    while (!min_heap.empty())
    {
        std::cout << min_heap.extractExtreme() << " ";
    }
    std::cout << std::endl;

    max_heap.insert(5);
    max_heap.insert(3);
    max_heap.insert(10);
    max_heap.insert(1);
    max_heap.insert(2);

    std::cout << "Max Heap: ";
    while (!max_heap.empty())
    {
        std::cout << max_heap.extractExtreme() << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test_heap();
    return 0;
}