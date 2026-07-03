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
    int strStr(string haystack, string needle) 
    {
        // if haystack is smaller we can't find the needle in it
        if(haystack.size() < needle.size()) return -1; 

        int sizeNeedle = needle.size();
        int index = 0; 
        bool yes = true; 

        // the first char of needle
        char first = needle[0];

        for(int i = 0; i < haystack.size() - needle.size() + 1; i++) // this loop as we don't over loop to search the first letter
        {
            if(haystack[i] == first)
            {
                // now the first letter is same so search till the needle size
                index = i;

                int j = 0; 
                int k = i;

                while(j < sizeNeedle)
                {
                    // check each letter after the first letter was found
                    if(haystack[k] == needle[j]) yes = true;
                    else
                    {
                        yes = false; 
                        break;
                    }
                    k++;
                    j++;
                }

                // if found break.. as we need the index of first occurrence
                if(yes == true) break;
            }
            else yes = false;
        }
        
        if(yes) return index;
        else return -1;
    }
};
