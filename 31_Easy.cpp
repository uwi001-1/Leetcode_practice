#include<iostream>
using namespace std;

// 392. Is Subsequence

/***************
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
***************/


class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
       // if s is empty then it can be made by t so return true
        if(s == "") return true;

        bool found = false;

        // initiate it outside to not over loop 
        int i = 0;

        for(char index : s)
        {
            // each new char of s, the bool found becomes false
            found = false;

            // if the t has come to an end and a char of s was not found then it's false
            if(i == t.size()) break;
            
            for(i; i < t.size(); i++)
            {
                if(index == t[i])
                {
                    found = true;

                    // i is incremented as we need to move ahead to another mode for cases like 'aaaaa' as s
                    i += 1;
                    
                    break;
                }
            } 
        }
        return found;
    }
};
