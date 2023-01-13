#include <bits/stdc++.h>

template <typename T>
int binary_search(std::vector<T>& data, T target) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (data[middle] == target) {
            return middle;
        } else if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1; // Target not found
}

void test_binary_search() {
    std::vector<int> data1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int expected_output1 = 2;
    assert(binary_search(data1, target1) == expected_output1);
    
    std::vector<int> data2 = {10, 20, 30, 40, 50, 60};
    int target2 = 40;
    int expected_output2 = 3;
    assert(binary_search(data2, target2) == expected_output2);
    
    std::vector<int> data3 = {10, 20, 30, 40};
    int target3 = 100;
    int expected_output3 = -1;
    assert(binary_search(data3, target3) == expected_output3);
}

int main() {
    test_binary_search();
    return 0;
}