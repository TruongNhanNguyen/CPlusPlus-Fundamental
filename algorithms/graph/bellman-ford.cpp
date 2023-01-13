#include <iostream>
#include <vector>

const int INF = 1e9; // a large value representing infinity

// Helper function to print the distance array
void print_distances(std::vector<int> &dist)
{
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INF)
        {
            std::cout << "INF ";
        }
        else
        {
            std::cout << dist[i] << " ";
        }
    }
    std::cout << std::endl;
}

// Function to implement Bellman-Ford algorithm
// adj_list: adjacency list representation of the graph
// num_vertices: number of vertices in the graph
// start_node: the starting node
std::vector<int> BellmanFord(std::vector<std::vector<std::pair<int, int>>> &adj_list, int num_vertices, int start_node)
{
    std::vector<int> dist(num_vertices, INF); // initialize distance array with INF
    dist[start_node] = 0;                     // starting node has distance 0

    for (int i = 1; i <= num_vertices - 1; i++)
    { // relax all edges |V| - 1 times
        for (int u = 0; u < num_vertices; u++)
        { // for each vertex
            for (auto [v, w] : adj_list[u])
            { // for each edge (u, v) with weight w
                if (dist[u] != INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < num_vertices; u++)
    { // check for negative-weight cycles
        for (auto [v, w] : adj_list[u])
        {
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                std::cout << "Graph contains negative weight cycle" << std::endl;
                return std::vector<int>();
            }
        }
    }
    return dist;
}

void test_BellmanFord()
{
    std::vector<std::vector<std::pair<int, int>>> adj_list = {
        {{1, -1}, {2, 4}},
        {{2, 3}, {3, 2}, {4, 2}},
        {{5, 5}},
        {{1, 1}, {2, 5}, {5, 8}},
        {{6, 2}},
        {{4, 1}, {6, 6}},
        {{}}};
    int num_vertices = 7;
    int start_node = 0;

    std::vector<int> dist = BellmanFord(adj_list, num_vertices, start_node);
    if (!dist.empty())
    {
        print_distances(dist);
    }
}

int main()
{
    test_BellmanFord();
    return 0;
}
