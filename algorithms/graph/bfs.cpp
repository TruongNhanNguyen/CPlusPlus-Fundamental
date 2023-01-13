#include <iostream>
#include <queue>
#include <vector>

void BFS(std::vector<std::vector<int>> &adj_list, int start_node)
{
    std::vector<bool> visited(adj_list.size(), false);
    std::queue<int> to_visit;
    to_visit.push(start_node);
    visited[start_node] = true;
    while (!to_visit.empty())
    {
        int current = to_visit.front();
        to_visit.pop();
        std::cout << current << " ";
        for (int neighbor : adj_list[current])
        {
            if (!visited[neighbor])
            {
                to_visit.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void test_BFS()
{
    // Test case 1: BFS on a directed graph
    std::vector<std::vector<int>> adj_list = {{1, 2}, {2}, {0, 3}, {3}};
    std::cout << "Test case 1: BFS on a directed graph, starting from node 0" << std::endl;
    BFS(adj_list, 0);
    std::cout << std::endl;

    // Test case 2: BFS on an undirected graph
    adj_list = {{1, 2}, {0, 2}, {0, 1}};
    std::cout << "Test case 2: BFS on an undirected graph, starting from node 1" << std::endl;
    BFS(adj_list, 1);
    std::cout << std::endl;

    // Test case 3: BFS on a disconnected graph
    adj_list = {{1}, {}, {}, {}};
    std::cout << "Test case 3: BFS on a disconnected graph, starting from node 0" << std::endl;
    BFS(adj_list, 0);
    std::cout << std::endl;
}

int main()
{
    test_BFS();
    return 0;
}