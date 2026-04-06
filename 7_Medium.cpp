#include<iostream>
using namespace std;

// 371. Sum of Two Integers

/***************
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
***************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> newL(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            int multiple = 1;
            for(int j = 0; j <nums.size(); j++)
            {
                if(i != j)       //multiply except the self 
                {
                    multiple = multiple * nums[j];
                }
            }
            newL[i] = multiple;
        }
        return newL;
    }
};
