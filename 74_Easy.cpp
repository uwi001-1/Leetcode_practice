#include<iostream>
using namespace std;

// 69. Sqrt(x)

/***************
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:
Input: x = 4
Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
***************/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // base case
        vector<int> ans = {-1, -1};

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                // first occurence
                if(ans[0] == -1) ans[0] = i;

                // second occurence till the end
                ans[1] = i;
            }
        }
        return ans;
    }
};
