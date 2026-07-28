#include<iostream>
using namespace std;

// 3517. Smallest Palindromic Rearrangement I

/***************
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s. 

Example 1:
Input: s = "z"
Output: "z"
Explanation:
A string of only one character is already the lexicographically smallest palindrome.

Example 2:
Input: s = "babab"
Output: "abbba"
Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:
Input: s = "daccad"
Output: "acddca"
Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
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
