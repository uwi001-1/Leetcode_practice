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
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<int> arr = candies;
        std::sort(arr.begin(), arr.end());

        // as arr is sorted 
        int max = arr[candies.size() -1]; 

        vector<bool> ans;

        for(int i = 0; i < candies.size(); i++)
        {
            if(candies[i] + extraCandies >= max) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};
