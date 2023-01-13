#include <bits/stdc++.h>

template <typename T>
class Graph
{
private:
    std::unordered_map<T, std::vector<T>> adjList;
    bool directed;

public:
    Graph(bool directed) : directed(directed) {}

    void addVertex(T vertex)
    {
        adjList[vertex] = {};
    }

    void addEdge(T src, T dest)
    {
        adjList[src].push_back(dest);
        if (!directed)
        {
            adjList[dest].push_back(src);
        }
    }
    int getNumVertices()
    {
        return adjList.size();
    }

    int getNumEdges()
    {
        int numEdges = 0;
        for (auto [vertex, edges] : adjList)
        {
            numEdges += edges.size();
        }
        if (!directed)
        {
            numEdges /= 2;
        }
        return numEdges;
    }
    std::vector<T> getAdjacentVertices(T vertex)
    {
        return adjList[vertex];
    }
};

void test_graph()
{
    Graph<int> directed_graph(true);
    directed_graph.addVertex(0);
    directed_graph.addVertex(1);
    directed_graph.addVertex(2);
    directed_graph.addEdge(0, 1);
    directed_graph.addEdge(1, 2);
    std::cout << "Number of vertices in directed graph: " << directed_graph.getNumVertices() << std::endl;
    std::cout << "Number of edges in directed graph: " << directed_graph.getNumEdges() << std::endl;
    std::cout << "Adjacent vertices of vertex 0: ";
    for (auto i : directed_graph.getAdjacentVertices(0))
        std::cout << i << " ";
    std::cout << std::endl;

    Graph<int> undirected_graph(false);
    undirected_graph.addVertex(0);
    undirected_graph.addVertex(1);
    undirected_graph.addVertex(2);
    undirected_graph.addEdge(0, 1);
    undirected_graph.addEdge(1, 2);
    std::cout << "Number of vertices in undirected graph: " << undirected_graph.getNumVertices() << std::endl;
    std::cout << "Number of edges in undirected graph: " << undirected_graph.getNumEdges() << std::endl;
    std::cout << "Adjacent vertices of vertex 0: ";
    for (auto i : undirected_graph.getAdjacentVertices(0))
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    test_graph();
    return 0;
}