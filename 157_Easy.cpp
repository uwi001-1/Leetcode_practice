#include<iostream>
using namespace std;

// 2124. Check if All A's Appears Before All B's

/***************
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. 
Otherwise, return false.

Example 1:
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.

Example 2:
Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.

Example 3:
Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
***************/


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int dec = 0;
        int inc = 0; 

        int decCount = 0;
        int incCount = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                decCount++;
                if(inc < incCount) inc = incCount;
                incCount = 0;
            }
            else if(nums[i -1] < nums[i])
            {
                incCount++;
                if(dec < decCount) dec = decCount;
                decCount = 0;
            }
            else
            {
                if(inc < incCount) inc = incCount;
                incCount = 0;

                if(dec < decCount) dec = decCount;
                decCount = 0;
            }
        }

        if(inc < incCount) inc = incCount;
        if(dec < decCount) dec = decCount;

        return max(inc, dec) + 1;
    }
};
