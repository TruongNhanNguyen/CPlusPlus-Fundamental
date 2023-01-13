#include <bits/stdc++.h>

int factorial(int n)
{
  if (n == 0)
  {
    return 1; // The factorial of 0 is 1
  }
  else
  {
    return n * factorial(n - 1); // Recursively call the factorial function with n - 1
  }
}

int main()
{
  int result = factorial(5); // The result will be 120 (5 * 4 * 3 * 2 * 1)
  std::cout << result << std::endl;
  return 0;
}
