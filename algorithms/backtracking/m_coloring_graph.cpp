#include <iostream>
#include <vector>

bool isSafe(std::vector<int> &colors, std::vector<std::vector<int>> &graph, int vertex, int color)
{
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (colors[graph[vertex][i]] == color)
        {
            return false;
        }
    }
    return true;
}

bool mColoringUtil(std::vector<int> &colors, std::vector<std::vector<int>> &graph, int vertex, int m)
{
    if (vertex == graph.size())
    {
        return true;
    }
    for (int color = 1; color <= m; color++)
    {
        if (isSafe(colors, graph, vertex, color))
        {
            colors[vertex] = color;
            if (mColoringUtil(colors, graph, vertex + 1, m))
            {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

bool mColoring(std::vector<std::vector<int>> &graph, int m)
{
    int n = graph.size();
    std::vector<int> colors(n, 0);
    return mColoringUtil(colors, graph, 0, m);
}

void test_m_coloring()
{
    int num_nodes = 4;
    std::vector<std::vector<int>> graph = {{0, 1, 1, 1},
                                 {1, 0, 1, 0},
                                 {1, 1, 0, 1},
                                 {1, 0, 1, 0}};
    int num_colors = 3;
    bool is_possible = mColoring(graph, num_colors);
    if (is_possible)
    {
        std::cout << "Coloring is possible with " << num_colors << " colors" << std::endl;
    }
    else
    {
        std::cout << "Coloring is not possible with " << num_colors << " colors" << std::endl;
    }

    num_nodes = 5;
    graph = {{0, 1, 1, 1, 0},
             {1, 0, 1, 0, 1},
             {1, 1, 0, 1, 0},
             {1, 0, 1, 0, 1},
             {0, 1, 0, 1, 0}};
    num_colors = 4;
    is_possible = mColoring(graph, num_colors);
    if (is_possible)
    {
        std::cout << "Coloring is possible with " << num_colors << " colors" << std::endl;
    }
    else
    {
        std::cout << "Coloring is not possible with " << num_colors << " colors" << std::endl;
    }
}

int main()
{
    test_m_coloring();
    return 0;
}