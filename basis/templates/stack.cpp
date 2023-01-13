#include <bits/stdc++.h>

template <typename T>
class Stack
{
public:
    void push(T x)
    {
        data_.push_back(x);
    }
    T pop()
    {
        T x = data_.back();
        data_.pop_back();
        return x;
    }
    bool empty() const
    {
        return data_.empty();
    }

private:
    std::vector<T> data_;
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty())
    {
        std::cout << s.pop() << " "; // Prints "30 20 10"
    }
    std::cout << std::endl;

    return 0;
}
