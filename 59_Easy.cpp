#include<iostream>
using namespace std;

// 28. Find the Index of the First Occurrence in a String

/***************
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.
***************/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // if there are not enough length of magazine, then we can't complete the ransomNote
        if(magazine.size() < ransomNote.size()) return false; 

        bool once = false;

        // loop the ransomNote
        int i = 0;

        while(true)
        {
            once = false; 

            for(int j = 0; j < magazine.size(); j++)
            {
                if(ransomNote[i] == magazine[j])
                {
                    // change the letter of ransomNote found in magazine to ' ' 
                    magazine[j] = ' ';
                    once = true;
                    break;
                }
            }

            i++; 
            
            // if one of the letter is not found or we searched all of the ransomNote
            if(i >= ransomNote.size() || once == false) break;
        }
        return once;
    }
};
