#include <bits/stdc++.h>

template <typename T>
class WeightedGraph {
private:
    std::unordered_map<T, std::unordered_map<T, int>> adjList;
    bool directed;

public:
    WeightedGraph(bool directed) : directed(directed) {}

    void addVertex(T vertex) {
        adjList[vertex] = {};
    }

    void addEdge(T src, T dest, int weight) {
        adjList[src][dest] = weight;
        if (!directed) {
            adjList[dest][src] = weight;
        }
    }

    int getNumVertices() {
        return adjList.size();
    }

    int getNumEdges() {
        int numEdges = 0;
        for (auto [vertex, edges] : adjList) {
            numEdges += edges.size();
        }
        if (!directed) {
            numEdges /= 2;
        }
        return numEdges;
    }

    int getWeight(T src, T dest) {
        return adjList[src][dest];
    }

    std::unordered_map<T, int> getAdjacentVertices(T vertex) {
        return adjList[vertex];
    }
};

void test_weighted_graph() {
    WeightedGraph<int> directed_graph(true);
    directed_graph.addVertex(0);
    directed_graph.addVertex(1);
    directed_graph.addVertex(2);
    directed_graph.addEdge(0, 1, 10);
    directed_graph.addEdge(1, 2, 20);
    std::cout << "Number of vertices in directed graph: " << directed_graph.getNumVertices() << std::endl;
    std::cout << "Number of edges in directed graph: " << directed_graph.getNumEdges() << std::endl;
    std::cout << "Weight of edge 0->1: " << directed_graph.getWeight(0, 1) << std::endl;
    std::cout << "Adjacent vertices of vertex 0: ";
    for (auto [i, weight] : directed_graph.getAdjacentVertices(0))
        std::cout << i << "(" << weight << ") ";
    std::cout << std::endl;
    
        WeightedGraph<int> undirected_graph(false);
    undirected_graph.addVertex(0);
    undirected_graph.addVertex(1);
    undirected_graph.addVertex(2);
    undirected_graph.addEdge(0, 1, 10);
    undirected_graph.addEdge(1, 2, 20);
    std::cout << "Number of vertices in undirected graph: " << undirected_graph.getNumVertices() << std::endl;
    std::cout << "Number of edges in undirected graph: " << undirected_graph.getNumEdges() << std::endl;
    std::cout << "Weight of edge 0->1: " << undirected_graph.getWeight(0, 1) << std::endl;
    std::cout << "Adjacent vertices of vertex 0: ";
    for (auto [i, weight] : undirected_graph.getAdjacentVertices(0))
        std::cout << i << "(" << weight << ") ";
    std::cout << std::endl;
}

int main() {
    test_weighted_graph();
    return 0;
}
