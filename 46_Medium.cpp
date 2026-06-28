#include<iostream>
using namespace std;

// 55. Jump Game

/***************
You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
***************/


class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        // if the list is just 1 element then return true
        if(nums.size() == 1) return true;

        int furthest = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // can't reach index i
            if(i > furthest) return false; 
            
            // furthest we can go is the max of the last and the new one in new index
            furthest = max(furthest, i + nums[i]);

            // if we can reach or cross the last index return true
            if(furthest >= nums.size()-1) return true;
        }
        
        return false;
    }
};
