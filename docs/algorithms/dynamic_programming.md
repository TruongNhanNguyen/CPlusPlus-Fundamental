# Dynamic Programming

Dynamic programming is a technique for solving problems by breaking them down into smaller subproblems and caching the results of those subproblems to avoid redundant computation. It is often used for optimization problems, where the goal is to find the best solution among a set of possible solutions.

There are two main approaches to dynamic programming: top-down and bottom-up. The top-down approach, also known as memoization, starts with the original problem and recursively breaks it down into smaller subproblems. The bottom-up approach, also known as tabulation, starts with the smallest subproblems and builds up to the original problem.

Some common dynamic programming algorithms include:

- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- Knapsack problem
- Matrix Chain Multiplication
- Bellman-Ford and Dijkstra's shortest path algorithms
- Edit distance
- Computing Fibonacci numbers

Dynamic programming algorithms are typically implemented using a combination of recursion and caching. It is important to carefully choose the data structure for caching the results, as it can have a big impact on the performance of the algorithm.

It is also important to note that not all problems can be solved using dynamic programming, it is only applicable when the problem exhibits the overlapping subproblems property, and when the optimal solution to a problem can be constructed by combining optimal solutions to subproblems.