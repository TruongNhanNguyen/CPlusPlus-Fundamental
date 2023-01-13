#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>> &adj_list, int start_node, std::vector<bool> &visited)
{
    visited[start_node] = true;
    std::cout << start_node << " ";
    for (int neighbor : adj_list[start_node])
    {
        if (!visited[neighbor])
        {
            DFS(adj_list, neighbor, visited);
        }
    }
}

void test_DFS()
{
    // Test case 1: DFS on a directed graph
    std::vector<std::vector<int>> adj_list = {{1, 2}, {2}, {0, 3}, {3}};
    std::vector<bool> visited(adj_list.size(), false);
    std::cout << "Test case 1: DFS on a directed graph, starting from node 0" << std::endl;
    DFS(adj_list, 0, visited);
    std::cout << std::endl;
    fill(visited.begin(), visited.end(), false);

    // Test case 2: DFS on an undirected graph
    adj_list = {{1, 2}, {0, 2}, {0, 1}};
    std::cout << "Test case 2: DFS on an undirected graph, starting from node 1" << std::endl;
    DFS(adj_list, 1, visited);
    std::cout << std::endl;
    fill(visited.begin(), visited.end(), false);

    // Test case 3: DFS on a disconnected graph
    adj_list = {{1}, {}, {}, {}};
    std::cout << "Test case 3: DFS on a disconnected graph, starting from node 0" << std::endl;
    DFS(adj_list, 0, visited);
    std::cout << std::endl;
}

int main()
{
    test_DFS();
    return 0;
}