#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Helper function to reverse the graph
vector<vector<int>> reverseGraph(vector<vector<int>> &adj_list)
{
    int V = adj_list.size();
    vector<vector<int>> reverse_adj_list(V);
    for (int i = 0; i < V; i++)
    {
        for (int j : adj_list[i])
        {
            reverse_adj_list[j].push_back(i);
        }
    }
    return reverse_adj_list;
}

void DFS(vector<vector<int>> &adj_list, int v, vector<bool> &visited, stack<int> &finish_times)
{
    visited[v] = true;
    for (int neighbor : adj_list[v])
    {
        if (!visited[neighbor])
        {
            DFS(adj_list, neighbor, visited, finish_times);
        }
    }
    finish_times.push(v);
}

void SCCUtil(vector<vector<int>> &adj_list, int v, vector<bool> &visited, vector<int> &scc)
{
    visited[v] = true;
    scc.push_back(v);
    for (int neighbor : adj_list[v])
    {
        if (!visited[neighbor])
        {
            SCCUtil(adj_list, neighbor, visited, scc);
        }
    }
}

vector<vector<int>> SCC(vector<vector<int>> &adj_list)
{
    int V = adj_list.size();
    vector<bool> visited(V, false);
    stack<int> finish_times;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(adj_list, i, visited, finish_times);
        }
    }
    vector<vector<int>> reverse_adj_list = reverseGraph(adj_list);
    visited = vector<bool>(V, false);
    vector<vector<int>> sccs;
    while (!finish_times.empty())
    {
        int v = finish_times.top();
        finish_times.pop();
        if (!visited[v])
        {
            vector<int> scc;
            SCCUtil(reverse_adj_list, v, visited, scc);
            sccs.push_back(scc);
        }
    }
    return sccs;
}

void test_SCC()
{
    vector<vector<int>> adj_list = {{1, 2}, {2, 3}, {3, 1}, {4, 3}, {4, 5}, {5, 6}};
    vector<vector<int>> scc = SCC(adj_list);
    for (auto component : scc)
    {
        cout << "Component: ";
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    // Output:
    // Component: 1 2 3
    // Component: 4 5
    // Component: 6
}

int main()
{
    test_SCC();
    return 0;
}