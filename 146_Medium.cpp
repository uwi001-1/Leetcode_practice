#include<iostream>
using namespace std;

// Q3. Find All Numbers Disappeared in an Array

/***************
Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
***************/


// Hash Table --> 0ms
class Solution {
public:
    // Hash table 
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> freq(nums.size() + 1, 0);
        vector<int> arr;

        for(int n: nums)
        {
            freq[n]++;
        }  

        for(int i = 1; i <= nums.size(); i++)
        {
            if(freq[i] == 0) arr.push_back(i);
        }

        return arr;
    }
};
