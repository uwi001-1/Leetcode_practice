#include<iostream>
using namespace std;

// 3467. Transform Array by Parity

/***************
You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.
Return the resulting array after performing these operations.

Example 1:
Input: nums = [4,3,2,1]
Output: [0,0,1,1]
Explanation:
Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
After sorting nums in non-descending order, nums = [0, 0, 1, 1].

Example 2:
Input: nums = [1,5,1,4,2]
Output: [0,0,1,1,1]
Explanation:
Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
***************/


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        // sort the array 
        std::sort(prices.begin(), prices.end());

        int cost = prices[0] + prices[1];

        if(cost > money) return money;
        if(cost == money) return 0;
        return money - cost;   
    }
};
