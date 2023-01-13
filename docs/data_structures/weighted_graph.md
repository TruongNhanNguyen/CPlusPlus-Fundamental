# Weighted Graph

## Implementation

```cpp
template <typename T>
class WeightedGraph {
private:
    unordered_map<T, unordered_map<T, int>> adjList;
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

    unordered_map<T, int> getAdjacentVertices(T vertex) {
        return adjList[vertex];
    }
};
```

The `WeightedGraph` class is similar to the `Graph` class I described [here](graph.md), but with the addition of a weight parameter in the `addEdge` function. This weight parameter is used to assign a weight to the edge connecting the `src` and `dest` vertices.
The `getWeight` function retrieves the weight of the edge between two vertices, `src` and `dest`. The `getAdjacentVertices` function returns an `unordered_map` of adjacent vertices and their weights of a given vertex.

## Test Cases

```cpp
void test_weighted_graph() {
    WeightedGraph<int> directed_graph(true);
    directed_graph.addVertex(0);
    directed_graph.addVertex(1);
    directed_graph.addVertex(2);
    directed_graph.addEdge(0, 1, 10);
    directed_graph.addEdge(1, 2, 20);
    cout << "Number of vertices in directed graph: " << directed_graph.getNumVertices() << endl;
    cout << "Number of edges in directed graph: " << directed_graph.getNumEdges() << endl;
    cout << "Weight of edge 0->1: " << directed_graph.getWeight(0, 1) << endl;
    cout << "Adjacent vertices of vertex 0: ";
    for (auto [i, weight] : directed_graph.getAdjacentVertices(0))
        cout << i << "(" << weight << ") ";
    cout << endl;
    
    WeightedGraph<int> undirected_graph(false);
    undirected_graph.addVertex(0);
    undirected_graph.addVertex(1);
    undirected_graph.addVertex(2);
    undirected_graph.addEdge(0, 1, 10);
    undirected_graph.addEdge(1, 2, 20);
    cout << "Number of vertices in undirected graph: " << undirected_graph.getNumVertices() << endl;
    cout << "Number of edges in undirected graph: " << undirected_graph.getNumEdges() << endl;
    cout << "Weight of edge 0->1: " << undirected_graph.getWeight(0, 1) << endl;
    cout << "Adjacent vertices of vertex 0: ";
    for (auto [i, weight] : undirected_graph.getAdjacentVertices(0))
        cout << i << "(" << weight << ") ";
    cout << endl;
}
```

This test case function creates a directed graph and an undirected graph, adds vertices and edges between them with weight, and demonstrates the use of the basic functions provided by the `WeightedGraph` class such as `addVertex`, `addEdge`, `getNumVertices`, `getNumEdges`, `getWeight`, `getAdjacentVertices`. It first creates a directed graph and adds vertices and edges to it, then it prints the number of vertices, edges, weight of edge and adjacent vertices of a vertex. Then it creates an undirected graph, adds vertices and edges to it, and prints the number of vertices, edges, weight of edge and adjacent vertices of a vertex similarly.

Keep in mind that this is a simple implementation of a weighted graph and there are many other variations and more advanced algorithms that can be implemented on a graph data structure.
