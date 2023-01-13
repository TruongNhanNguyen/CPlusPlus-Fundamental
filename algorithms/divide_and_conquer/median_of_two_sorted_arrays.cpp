#include <algorithm>
#include <iostream>

// using namespace std;

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if (m > n)
    {
        std::swap(nums1, nums2);
        std::swap(m, n);
    }
    int i, j, imin = 0, imax = m, half = (m + n + 1) / 2;
    while (imin <= imax)
    {
        i = (imin + imax) / 2;
        j = half - i;
        if (i < m && nums2[j - 1] > nums1[i])
        {
            imin = i + 1;
        }
        else if (i > 0 && nums1[i - 1] > nums2[j])
        {
            imax = i - 1;
        }
        else
        {
            int max_of_left, min_of_right;
            if (i == 0)
            {
                max_of_left = nums2[j - 1];
            }
            else if (j == 0)
            {
                max_of_left = nums1[i - 1];
            }
            else
            {
                max_of_left = std::max(nums1[i - 1], nums2[j - 1]);
            }
            if ((m + n) % 2 == 1)
            {
                return max_of_left;
            }
            if (i == m)
            {
                min_of_right = nums2[j];
            }
            else if (j == n)
            {
                min_of_right = nums1[i];
            }
            else
            {
                min_of_right = std::min(nums1[i], nums2[j]);
            }
            return (max_of_left + min_of_right) / 2.0;
        }
    }
    return 0.0;
}

void test_findMedianSortedArrays()
{
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
    nums1 = {1, 2};
    nums2 = {3, 4};
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
    nums1 = {1, 2, 3};
    nums2 = {4, 5, 6};
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
}

int main()
{
    test_findMedianSortedArrays();
    return 0;
}