# Graph Algorithms

**Graph algorithms** are a set of algorithms that operate on graphs and are used to solve problems related to graph theory. Some examples of graph problems include finding the shortest path between two nodes, finding the *minimum spanning tree* of a graph, *detecting cycles* in a graph, and *finding the connected components* of a graph.

There are several common techniques and algorithms used to solve graph problems, including:

1. **Breadth-first search (BFS)**: a technique for traversing a graph where we explore all the neighbors of a node before moving on to the next level of nodes. This algorithm can be used to find the shortest path between two nodes in an unweighted graph.

2. **Depth-first search (DFS)**: a technique for traversing a graph where we explore as far as possible along each branch before backtracking. This algorithm can be used to find the connected components of a graph, detect cycles in a graph, and solve other problems.

3. **Dijkstra's algorithm**: a technique for finding the shortest path between two nodes in a weighted graph.

4. **Bellman-Ford algorithm**: a technique for finding the shortest path between a single source node and all other nodes in a weighted graph.

5. **Prim's algorithm** and **Kruskal's algorithm**: these are two different algorithms for finding the minimum spanning tree of a graph, i.e., a tree that spans all the nodes in the graph and has the minimum total edge weight.

6. **Topological sort**: an algorithm for finding a linear ordering of the nodes in a directed acyclic graph (DAG) such that for every directed edge $(u, v)$, node $u$ comes before node $v$ in the ordering.

7. **Strongly connected components**: is an algorithm used to find the strongly connected components of a directed graph and also used for finding cycle