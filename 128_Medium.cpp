#include<iostream>
using namespace std;

// 82. Remove Duplicates from Sorted List II

/***************
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
***************/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> positive;
        vector<int> negative;
        vector<int> arr;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) negative.push_back(nums[i]);
            else positive.push_back(nums[i]);
        }    

        for(int j = 0; j < nums.size() / 2; j++)
        {
            arr.push_back(positive[j]);
            arr.push_back(negative[j]);
        }

        return arr;
    }
};
