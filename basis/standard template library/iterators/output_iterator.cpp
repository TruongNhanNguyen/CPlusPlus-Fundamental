#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};
    // You can create an output iterator by using the back_inserter method from the <iterator> header
    std::back_insert_iterator<std::vector<int>> it = std::back_inserter(data);
    *it = 6;
    *it = 7;
    *it = 8;
    // The iterator will push elements on the back of the vector, so data should now be [1,2,3,4,5,6,7,8]
    for (int i : data)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
