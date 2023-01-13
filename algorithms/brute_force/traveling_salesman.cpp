#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 1e9;

int tsp(std::vector<std::vector<int>> &dist, std::vector<int> &path, std::vector<bool> &visited, int current_pos, int n, int remaining)
{
    if (remaining == 0)
    {
        return dist[current_pos][path[0]];
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int current_dist = dist[current_pos][i];
            if (current_dist != INF)
            {
                path.push_back(i);
                visited[i] = true;
                ans = std::min(ans, current_dist + tsp(dist, path, visited, i, n, remaining - 1));
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    return ans;
}

void test_tsp()
{
    std::vector<std::vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int n = dist.size();
    std::vector<int> path;
    std::vector<bool> visited(n, false);
    path.push_back(0);
    visited[0] = true;
    int ans = tsp(dist, path, visited, 0, n, n - 1);
    std::cout << "Minimum distance: " << ans << std::endl;
    std::cout << "Path: [ ";
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << path[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    test_tsp();
    return 0;
}
