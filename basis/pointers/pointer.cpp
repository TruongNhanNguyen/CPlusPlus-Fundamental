#include <bits/stdc++.h>

int main()
{
    int *p = new int; // Dynamically allocate an integer on the heap
    *p = 10;          // Store the value 10 in the memory location pointed to by p
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    delete p; // Deallocate the memory that was dynamically allocated for the integer

    return 0;
}