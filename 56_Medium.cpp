#include<iostream>
using namespace std;

// 120. Triangle

/***************
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
    Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
***************/


class Solution {
public:
    // At each step, you can only go to one of the two numbers right above you
    // Find the path with the smallest total sum

    int minimumTotal(vector<vector<int>>& triangle) 
        // triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    {
        // bottom-up dynamic programming 

        // copy the last row
        vector<int> dp = triangle.back(); 
        // dp = [4, 1, 8, 3]

        for(int i = triangle.size()-2; i >= 0; i--)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                // for each cell, pick the better option below
                // Each number chooses the cheaper child and adds its own value
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
            // with [6,5,7] -> dp = [7,6,10,3]
            // with [3,4] -> dp = [9,10,10,3]
            // with [2] -> dp = [11,10,10,3]
        }

        // return 11 in this case
        return dp[0]; 
    }
};
