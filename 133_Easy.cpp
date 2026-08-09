#include<iostream>
using namespace std;

// 724. Find Pivot Index

/***************
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
***************/


class Solution {
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();

        // suffix sums
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        // dp[i][M] = max stones current player can get from piles[i..n-1] given current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int M = 1; M <= n; M++) 
            {
                // If we can take all remaining piles, do it.
                if (i + 2 * M >= n) 
                {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int X = 1; X <= 2 * M; X++) 
                {
                    int nextM = max(M, X);

                    int stones = suffix[i] - dp[i + X][nextM];

                    best = max(best, stones);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];    
    }
};
