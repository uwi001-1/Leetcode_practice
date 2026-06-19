#include<iostream>
using namespace std;

// 189. Rotate Array

/***************
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
***************/


// doesn't work 
// Time Limit Exceeded
/**************** 
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int loop = 0;
        while(loop != k)
        {
            vector<int> arr;
            arr.push_back(nums[nums.size()-1]);
            
            loop += 1;

            for(int i = 0; i<nums.size()-1; i++)
            {
                arr.push_back(nums[i]);
            }

            nums = arr;
        }
    }
};
***************/