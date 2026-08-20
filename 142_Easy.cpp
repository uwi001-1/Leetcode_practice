#include<iostream>
using namespace std;

// Q1. Set Mismatch

/***************
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
***************/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        vector<int> ans(2);

        
        int index = 1;
        bool once = false;

        for (int i = 0; i < nums.size() - 1; i++) {
            
            // Duplicate
            if (nums[i] == nums[i + 1]) {
                ans[0] = nums[i];
            }
            
            // Missing number
            else if (nums[i + 1] - nums[i] > 1) {
                ans[1] = nums[i] + 1;
            }
        } 

        // missing in the beginning
        if(nums[0] != 1) ans[1] = 1;

        // missing in the end
        if (nums[nums.size() - 1] != nums.size()) ans[1] = nums.size();
        
        return ans;
    }
};
