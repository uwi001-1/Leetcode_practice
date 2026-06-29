#include<iostream>
using namespace std;

// 1967. Number of Strings That Appear as Substrings in Word

/***************
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
    Explanation:
    - "a" appears as a substring in "abc".
    - "abc" appears as a substring in "abc".
    - "bc" appears as a substring in "abc".
    - "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.

Example 2:

Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
    Explanation:
    - "a" appears as a substring in "aaaaabbbbb".
    - "b" appears as a substring in "aaaaabbbbb".
    - "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.

Example 3:
Input: patterns = ["a","a","a"], word = "ab"
Output: 3
    Explanation: Each of the patterns appears as a substring in word "ab".
***************/


class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        // if the list is just 1 element then return true
        if(nums.size() == 1) return true;

        int furthest = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // can't reach index i
            if(i > furthest) return false; 
            
            // furthest we can go is the max of the last and the new one in new index
            furthest = max(furthest, i + nums[i]);

            // if we can reach or cross the last index return true
            if(furthest >= nums.size()-1) return true;
        }
        
        return false;
    }
};
