#include<iostream>
using namespace std;

// 1288. Remove Covered Intervals

/***************
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
    Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1
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
