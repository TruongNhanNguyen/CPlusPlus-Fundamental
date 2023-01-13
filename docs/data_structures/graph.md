# Graph

A graph is a mathematical representation of a set of objects in which some pairs of the objects are connected by links. The objects are represented by vertices (or nodes), and the links are represented by edges. There are different types of graphs, including:

- **Directed graphs** (or digraphs), in which the edges have a direction and connect one vertex to another.
- **Undirected graphs**, in which the edges have no direction and connect a pair of vertices.
- **Weighted graphs**, in which the edges have a value (or weight) associated with them.
- **Multi-graphs**, in which multiple edges can connect the same pair of vertices.
- **Simple graphs**, in which no loops or multiple edges are allowed.


Graphs are widely used in computer science to model many types of problems, such as:

- Social networks, where vertices represent people and edges represent relationships between them.
- Web pages, where vertices represent pages and edges represent hyperlinks between them.
- Maps, where vertices represent locations and edges represent roads or paths between them.


The most common way to implement a graph is to use an adjacency list representation, where each vertex is represented by a list of adjacent vertices. In this representation, the space complexity is $O(V + E)$ where $V$ is the number of vertices and $E$ is the number of edges.
Another way to represent a graph is by using an adjacency matrix, which is a $V \times V$ matrix where the entry at row $i$ and column $j$ is 1 if there is an edge between vertex $i$ and vertex $j$, and 0 otherwise. This representation has a space complexity of $O(V^2)$

## Implementation

### Graph class

We will implement a graph class in C++ that can be either directed or undirected, and has basic functions such as adding vertices and edges, and getting the number of vertices and edges

```cpp
template <typename T>
class Graph {
private:
    unordered_map<T, vector<T>> adjList;
    bool directed;

public:
    Graph(bool directed) : directed(directed) {}

    void addVertex(T vertex) {
        adjList[vertex] = {};
    }

    void addEdge(T src, T dest) {
        adjList[src].push_back(dest);
        if (!directed) {
            adjList[dest].push_back(src);
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
};
```

This implementation uses an `unordered_map` to store the adjacency list, where each key represents a vertex, and the corresponding value is a vector of vertices that the key vertex is connected to.

The class takes a boolean value in constructor indicating whether the graph is directed or not. The `addVertex` function adds a new vertex to the graph by adding an empty entry in the adjacency list.

The `addEdge` function adds an edge to the graph by adding the estination vertex to the list of adjacent vertices of the source vertex. 

The `getNumVertices` function returns the number of vertices in the graph by getting the size of the adjacency list. 

The `getNumEdges` function returns the number of edges in the graph by summing up the number of edges of each vertex and dividing by 2 if the graph is undirected.

The `getAdjacentVertices` function returns the list of adjacent vertices of a given vertex.

### Test cases

```cpp
void test_graph() {
    Graph<int> directed_graph(true);
    directed_graph.addVertex(0);
    directed_graph.addVertex(1);
    directed_graph.addVertex(2);
    directed_graph.addEdge(0, 1);
    directed_graph.addEdge(1, 2);
    cout << "Number of vertices in directed graph: " << directed_graph.getNumVertices() << endl;
    cout << "Number of edges in directed graph: " << directed_graph.getNumEdges() << endl;
    cout << "Adjacent vertices of vertex 0: ";
    for (auto i : directed_graph.getAdjacentVertices(0))
        cout << i << " ";
    cout << endl;
    
    Graph<int> undirected_graph(false);
    undirected_graph.addVertex(0);
    undirected_graph.addVertex(1);
    undirected_graph.addVertex(2);
    undirected_graph.addEdge(0, 1);
    undirected_graph.addEdge(1, 2);
    cout << "Number of vertices in undirected graph: " << undirected_graph.getNumVertices() << endl;
    cout << "Number of edges in undirected graph: " << undirected_graph.getNumEdges() << endl;
    cout << "Adjacent vertices of vertex 0: ";
    for (auto i : undirected_graph.getAdjacentVertices(0))
        cout << i << " ";
    cout << endl;
}
```

This test case function creates a directed graph and an undirected graph, adds vertices and edges between them, and demonstrates the use of the basic functions provided by the Graph class such as `addVertex`, `addEdge`, `getNumVertices`, `getNumEdges`, `getAdjacentVertices` .

It first creates a directed graph and adds vertices and edges to it, then it prints the number of vertices, edges and adjacent vertices of a vertex. Then it creates an undirected graph, adds vertices and edges to it, and prints the number of vertices, edges, and adjacent vertices of a vertex similarly.

This is a simple implementation of a graph and there are many other variations and more advanced algorithms that can be implemented on a graph data structure.