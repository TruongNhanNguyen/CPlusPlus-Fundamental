#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;

void Prim(vector<vector<pair<int, int>>> &adj_list, int start_node)
{
    int V = adj_list.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});
    key[start_node] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : adj_list[u])
        {
            int v = edge.first, weight = edge.second;
            if (key[v] > weight)
            {
                key[v] = weight;
                pq.push({weight, v});
                parent[v] = u;
            }
        }
    }
    // print the MST
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

void test_Prim()
{
    vector<vector<pair<int, int>>> adj_list = {
        {{1, 1}, {2, 4}}, // 0
        {{2, 2}, {3, 3}}, // 1
        {{3, 5}},         // 2
        {{}}              // 3
    };
    Prim(adj_list, 0);
    /*
        0 - 1
        1 - 2
    */

    vector<vector<pair<int, int>>> adj_list2 = {
        {{1, 5}, {2, 4}, {3, 2}}, // 0
        {{2, 2}, {4, 3}},         // 1
        {{4, 1}},                 // 2
        {{4, 5}},                 // 3
        {{}}                      // 4
    };
    Prim(adj_list2, 0);
    /*
        0 - 3
        3 - 4
        4 - 2
    */
}

int main()
{
    test_Prim();
    return 0;
}