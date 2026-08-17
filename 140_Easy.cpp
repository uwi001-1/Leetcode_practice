#include<iostream>
using namespace std;

// Q3. Max Consecutive Ones

/***************
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
***************/


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> ans(nums.size(), 0);
        int index = 0;

        for(int i = 0; i < n; i++)
        {
            ans[index] = nums[i];
            index++;
            ans[index] = nums[n+i];
            index++; 
        }   

        return ans;
    }
};
