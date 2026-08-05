#include<iostream>
using namespace std;

// 3300. Minimum Element After Replacement With Digit Sum

/***************
You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

Example 1:
Input: nums = [10,12,13,14]
Output: 1
Explanation:
nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:
Input: nums = [999,19,199]
Output: 10
Explanation:
nums becomes [27, 10, 19] after all replacements, with minimum element 10.
***************/


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> arr;
        int num = 0;

        // less than pivot
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot) arr.push_back(nums[i]);

            if(nums[i] == pivot) num++;
        }   

        // no. of pivots to the array
        while(num > 0)
        {
            arr.push_back(pivot);
            num--;
        }

        // more than pivot
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] > pivot) arr.push_back(nums[j]);
        }

        return arr; 
    }
};
