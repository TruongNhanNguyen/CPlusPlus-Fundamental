#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const int INF = std::numeric_limits<int>::max();

void Johnson(std::vector<std::vector<std::pair<int, int>>> &adj_list)
{
    int n = adj_list.size();
    std::vector<std::vector<int>> D(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        D[i][i] = 0;
    }
    for (int u = 0; u < n; u++)
    {
        for (auto &[v, w] : adj_list[u])
        {
            D[u][v] = w;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] == INF)
            {
                std::cout << "INF ";
            }
            else
            {
                std::cout << D[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void test_Johnson()
{
    std::vector<std::vector<std::pair<int, int>>> adj_list = {{{1, 2}, {2, 3}}, {{0, 3}, {2, 1}}, {{0, 1}, {1, 4}}};
    Johnson(adj_list);
    // Output should be:
    // 0 2 3
    // 3 0 1
    // 1 4 0
}

int main()
{
    test_Johnson();
    return 0;
}