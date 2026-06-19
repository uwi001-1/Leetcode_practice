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
       if(s == "") return true;

       bool found = false;
       int i = 0;

       for(char index : s)
       {
            found = false;
            if(i == t.size()) break;
            
            for(i; i < t.size(); i++)
            {
                if(index == t[i])
                {
                    found = true;
                    i += 1;
                    break;
                }
            } 
        }
        return found;
    }
};
