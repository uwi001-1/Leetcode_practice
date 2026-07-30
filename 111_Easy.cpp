#include<iostream>
using namespace std;

// 4. Median of Two Sorted Arrays

/***************
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5
***************/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // add the two arrays
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());    

        // now let's sort it 
        std::sort(nums1.begin(), nums1.end());

        double med; 

        // odd
        if(nums1.size() % 2 == 1)
        {
            med = nums1[nums1.size() / 2];
        }

        // even
        else 
        {
            med = (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
        }

        return med;
    }
};
