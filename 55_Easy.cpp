#include<iostream>
using namespace std;

// 100. Same Tree

/***************
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
***************/


class Solution {
public:
    // the concept that the subraction to zero is the number of distinct elements other than 0
    int minimumOperations(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) continue;
            
            if(i == nums.size() - 1 || nums[i] != nums[i+1]) count += 1;
        }
        
        return count;
    }
};
