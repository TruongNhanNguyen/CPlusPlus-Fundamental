#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topological_sort(std::vector<std::vector<int>>& adj_list) {
    std::vector<int> in_degree(adj_list.size(), 0);
    for (int i = 0; i < adj_list.size(); i++) {
        for (int neighbor : adj_list[i]) {
            in_degree[neighbor]++;
        }
    }
    std::queue<int> sources;
    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            sources.push(i);
        }
    }
    std::vector<int> order;
    while (!sources.empty()) {
        int current = sources.front();
        sources.pop();
        order.push_back(current);
        for (int neighbor : adj_list[current]) {
            if (--in_degree[neighbor] == 0) {
                sources.push(neighbor);
            }
        }
    }
    return order;
}

void test_topological_sort() {
    std::vector<std::vector<int>> graph1 = {{1}, {2}, {3}}; // test case 1
    std::vector<int> order1 = topological_sort(graph1);
    std::cout << "test case 1: [";
    for (int i : order1) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
    // expected output: test case 1: [0, 1, 2]

    std::vector<std::vector<int>> graph2 = {{1, 2}, {3}, {4}, {4}, {}}; // test case 2
    std::vector<int> order2 = topological_sort(graph2);
    std::cout << "test case 2: [";
    for (int i : order2) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
    // expected output: test case 2: [0, 1, 2, 3, 4]

    std::vector<std::vector<int>> graph3 = {{1}, {2}, {}}; // test case 3
    std::vector<int> order3 = topological_sort(graph3);
    std::cout << "test case 3: [";
    for (int i : order3) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
    // expected output: test case 3: [2, 0, 1]
}

int main() {
    test_topological_sort();
    return 0;
}
