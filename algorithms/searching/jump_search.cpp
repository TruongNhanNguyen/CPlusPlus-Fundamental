#include <bits/stdc++.h>

template <typename T>
int jump_search(std::vector<T>& data, T target) {
    int n = data.size();
    int step = sqrt(n);
    int prev = 0;

    while (data[std::min(step, n)-1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    while (data[prev] < target) {
        prev++;
        if (prev == std::min(step, n)) {
            return -1;
        }
    }

    if (data[prev] == target) {
        return prev;
    }
    return -1;
}

void test_jump_search() {
    std::vector<int> data1 = {1, 2, 3, 4, 5};
    int target1 = 3;
    int expected_output1 = 2;
    assert(jump_search(data1, target1) == expected_output1);

    std::vector<int> data2 = {10, 20, 30, 40, 50, 60};
    int target2 = 40;
    int expected_output2 = 3;
    assert(jump_search(data2, target2) == expected_output2);

    std::vector<int> data3 = {10, 20, 30, 40};
    int target3 = 100;
    int expected_output3 = -1;
    assert(jump_search(data3, target3) == expected_output3);
}

int main() {
    test_jump_search();
    return 0;
}