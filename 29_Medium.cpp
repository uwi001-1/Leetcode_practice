#include<iostream>
using namespace std;

// 189. Rotate Array

/***************
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
***************/


class Solution {
public:
    // array(nums) here is passed by reference
    void rotate(vector<int>& nums, int k) 
    {
        // to handle k > nums.size() cases
        k = k % nums.size();

        // to loop 
        int loop = nums.size() - k;
        
        // new array to push in elements in the order
        vector<int> arr;
        
        while(loop != nums.size())
        {
            // add values from nums.size()-k
            arr.push_back(nums[loop]);
            
            loop += 1;
        }

        // loop the rest of the array
        for(int i = 0; i<nums.size()-k; i++)
        {
            arr.push_back(nums[i]);
        }

        // as we are returning the nums array as it is passed by reference
        nums = arr;
    }
};


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