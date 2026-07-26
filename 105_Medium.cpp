#include<iostream>
using namespace std;

// 628. Maximum Product of Three Numbers

/***************
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6
***************/


class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        // for last three
        int product = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];

        // for taking the negative higher first two and last 1
        int pro = product;
        if(nums[0] < 0 && nums[1] < 0)
        {
            pro = nums[0] * nums[1] * nums[nums.size()-1];
        }

        int ans = max(pro, product);

        // if ans is negative and we have a zero in the array
        if(ans < 0)
        {
            for(int i = 0; i < nums.size(); i++) if(nums[i] == 0) return 0;
        }

        return ans;    
    }
};
