#include<iostream>
using namespace std;

// 58. Length of Last Word

/***************
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
    Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
    Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
    Explanation: The last word is "joyboy" with length 6.
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
