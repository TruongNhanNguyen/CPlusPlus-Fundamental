#include <cassert>
#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int fib(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (memo.count(n))
        return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

void test_fib()
{
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(10) == 55);
}

int main()
{
    test_fib();
    return 0;
}
