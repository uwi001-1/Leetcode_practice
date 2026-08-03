#include<iostream>
using namespace std;

// 8167. Two Sum II - Input Array Is Sorted

/***************
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
***************/


class Solution {
public:
    // solve with recursion and dynamic programming
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int l, int r)
    {
        // base case
        if (l == r) return nums[l];

        if (dp[l][r] != INT_MIN)
            return dp[l][r];
        
        int takeLeft = nums[l] - solve(nums, l + 1, r);
        int takeRight = nums[r] - solve(nums, l, r - 1);

        return dp[l][r] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) 
    {
        int n = piles.size();
        dp.assign(n, vector<int>(n, INT_MIN));

        return solve(piles, 0, n - 1) >= 0;
    }
};
