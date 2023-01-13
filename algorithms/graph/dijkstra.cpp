#include <iostream>
#include <queue>
#include <vector>

const int INF = 1e9;

// Helper function to find the node with the smallest distance
int findMin(std::vector<int> &dist, std::vector<bool> &visited)
{
    int min_dist = INF, min_index = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (!visited[i] && dist[i] < min_dist)
        {
            min_dist = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj_list, int start_node, int end_node)
{
    int n = adj_list.size();
    std::vector<int> dist(n, INF);
    std::vector<bool> visited(n, false);
    dist[start_node] = 0;

    for (int i = 0; i < n; i++)
    {
        int current = findMin(dist, visited);
        visited[current] = true;
        if (current == end_node)
        {
            break;
        }
        for (auto neighbor : adj_list[current])
        {
            int next = neighbor.first;
            int weight = neighbor.second;
            if (dist[next] > dist[current] + weight)
            {
                dist[next] = dist[current] + weight;
            }
        }
    }

    std::cout << "Shortest distance from node " << start_node << " to node " << end_node << " is " << dist[end_node] << std::endl;
}

void test_Dijkstra()
{
    std::vector<std::vector<std::pair<int, int>>> adj_list(6);
    adj_list[0] = {{1, 7}, {2, 9}, {5, 14}};
    adj_list[1] = {{0, 7}, {2, 10}, {3, 15}};
    adj_list[2] = {{0, 9}, {1, 10}, {3, 11}, {5, 2}};
    adj_list[3] = {{1, 15}, {2, 11}, {4, 6}};
    adj_list[4] = {{3, 6}};
    adj_list[5] = {{0, 14}, {2, 2}};

    dijkstra(adj_list, 0, 4); // should output the shortest distance between node 0 and node 4
}

int main()
{
    test_Dijkstra();
    return 0;
}