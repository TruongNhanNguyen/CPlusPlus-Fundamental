#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y)
            return false;
        if (size[root_x] > size[root_y])
            swap(root_x, root_y);
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
        return true;
    }

private:
    vector<int> parent, size;
};

vector<pair<int, pair<int, int>>> kruskals(int n, vector<pair<int, pair<int, int>>> edges)
{
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    vector<pair<int, pair<int, int>>> mst;
    for (auto [w, e] : edges)
    {
        if (uf.unite(e.first, e.second))
            mst.push_back({w, e});
    }
    return mst;
}

void test_Kruskals()
{
    int n = 5, m = 7;
    vector<pair<int, pair<int, int>>> edges = {{1, {0, 1}}, {4, {0, 2}}, {3, {1, 2}}, {2, {1, 3}}, {5, {2, 3}}, {1, {3, 4}}, {4, {4, 0}}};
    auto mst = kruskals(n, edges);
    for (auto [w, e] : mst)
        cout << e.first << "-" << e.second << " " << w << endl;
}

int main()
{
    test_Kruskals();
    return 0;
}