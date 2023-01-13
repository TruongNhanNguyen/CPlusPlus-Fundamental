#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

int random(int min, int max)
{
    srand(time(0));                        // Seed the random number generator with the current time
    return min + rand() % (max - min + 1); // Generate and return a random number between min and max
}

int main()
{
    int result = random(1, 10); // The result will be a random integer between 1 and 10
    std::cout << result << std::endl;
    return 0;
}