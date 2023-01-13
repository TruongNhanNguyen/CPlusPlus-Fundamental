#include <bits/stdc++.h>
#include <cmath>

std::pair<int, int> fermat(int n)
{
    int a = ceil(sqrt(n)); // Find the smallest integer greater than or equal to the square root of n
    int b2 = a * a - n;    // Calculate b^2
    while (sqrt(b2) != floor(sqrt(b2)))
    {                   // Keep iterating until b is an integer
        a++;            // Increment a
        b2 = a * a - n; // Recalculate b^2
    }
    int b = sqrt(b2);                    // Calculate b
    return std::make_pair(a - b, a + b); // Return the pair (a - b, a + b) as the prime factors of n
}

int main()
{
    std::pair<int, int> result = fermat(15); // The result will be (3, 5)
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;
    return 0;
}