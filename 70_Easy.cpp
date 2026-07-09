#include<iostream>
using namespace std;

// 283. Move Zeroes

/***************
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
***************/


class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        // first push the elements other than 0 into an array
        vector<int> arr;
        int count = 0; 

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0) arr.push_back(nums[i]);
            else count += 1;
        }

        while(count > 0)
        {
            arr.push_back(0);
            count--;
        }    

        nums = arr;
    }
};
