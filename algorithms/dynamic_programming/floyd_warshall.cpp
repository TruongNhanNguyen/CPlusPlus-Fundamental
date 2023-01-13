#include <bits/stdc++.h>

const int INF = 1e9;

void FloydWarshall(std::vector<std::vector<int>> &graph)
{
    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void test_FloydWarshall()
{
    int INF = INT_MAX;
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};
    std::vector<std::vector<int>> expected_result = {
        {0, 3, 5, 6},
        {8, 0, 2, 3},
        {5, 7, 0, 1},
        {2, 9, 9, 0}};

    // Run Floyd-Warshall algorithm
    FloydWarshall(graph);

    // Compare result with expected output
    assert(graph == expected_result);
}

int main()
{
    test_FloydWarshall();
    return 0;
}