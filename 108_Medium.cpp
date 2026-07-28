#include<iostream>
using namespace std;

// 137. Single Number II

/***************
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
***************/


class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        // first sort it
        std::sort(nums.begin(), nums.end());

        int i;
        for(i = 0; i < nums.size() -1; i += 3)
        {
            if (nums[i] != nums[i + 1]) return nums[i];
        }

        return nums.back();       
    }
};
