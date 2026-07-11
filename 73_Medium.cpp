#include<iostream>
using namespace std;

// 34. Find First and Last Position of Element in Sorted Array

/***************
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
***************/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // base case
        vector<int> ans = {-1, -1};

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                // first occurence
                if(ans[0] == -1) ans[0] = i;

                // second occurence till the end
                ans[1] = i;
            }
        }
        return ans;
    }
};
