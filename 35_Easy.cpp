#include<iostream>
using namespace std;

// 88. Merge Sorted Array

/***************
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:  
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
***************/


class Solution {
public:
    // using counting sort 
    
    int maxIceCream(vector<int>& costs, int coins) 
    {
        // count represent how many icecream bars cost exactly index coins
        vector<int> count(100001, 0);
        
        // increase the count of index if the cost of the icecream bar is that index
        // count[5] = 2 means that there are two icecream bars of 5 costs
        for(int i = 0; i < costs.size(); i++)
        {
            count[costs[i]] += 1;
        }

        int total = 0;

        // loop through the count array and buy the most bars starting from cheapest icecream bars
        for(int price = 1; price <= 100000; price++)
        {
            // if we can buy
            while(count[price] > 0 && coins >= price)
            {
                // reduce the number of count of that price
                count[price] -= 1;

                // coins reduces by that cost
                coins -= price;

                // the total buy increases by 1
                total += 1;
            }
        }

        return total;
    }
};
