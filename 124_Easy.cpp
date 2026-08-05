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
// no need to make a vector array of the sum and sort it 
// rather, keep checking with each new sum and min()
// and ans with MAX VALUE

    int minElement(vector<int>& nums) 
    {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;

            while(nums[i] > 0)
            {
                sum += nums[i] % 10;
                nums[i] = nums[i] / 10;
            }

            ans = min(ans,sum);
        }    

        return ans;
    }
};
