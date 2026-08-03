#include<iostream>
using namespace std;

// 2390. Removing Stars From a String

/***************
You are given a string s, which contains stars *.

In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 
Example 1:
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
***************/


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN);

        // No stones left.
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) 
        {
            int take = 0;

            // Try taking 1, 2 or 3 stones.
            for (int k = 0; k < 3 && i + k < n; k++) 
            {
                take += stoneValue[i + k];

                dp[i] = max(
                    dp[i],
                    take - dp[i + k + 1]
                );
            }
        }

        if (dp[0] > 0)
            return "Alice";

        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};
