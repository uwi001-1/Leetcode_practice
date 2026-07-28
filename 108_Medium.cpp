#include<iostream>
using namespace std;

// 137. Single Number II

/***************
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
***************/


class Solution {
public:
    string smallestPalindrome(string s) 
    {
        // base case - less than 3
        if(s.size() < 3) return s;

        string word = "";
        string extra = "";
        std::sort(s.begin(), s.end());

        int i;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i+1] == s[i]) 
            {
                word += s[i];
                i++;
            }
            else extra = s[i];
        }
        word += extra;

        // even
        if(s.size() % 2 == 0)
        {
            for(int i = word.size()-1; i >= 0; i--) word += word[i];
        }
        // odd
        else
        {
            for(int i = word.size()-2; i >= 0; i--) word += word[i];
        }

        return word;  
    }
};
