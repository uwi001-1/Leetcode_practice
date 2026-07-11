#include<iostream>
using namespace std;

// 34. Find First and Last Position of Element in Sorted Array

/***************
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
***************/


class Solution {
public:
    int totalWaviness(int num1, int num2) 
    {
        // use brute force
        int count = 0;

        for(int i = num1; i <= num2; i++)
        {
            // change it into a string so we can loop it
            string s = to_string(i);

            // base case; if size is less than 3 cannot have waviness
            if(s.size() < 3) continue;

            for(int j = 1; j < s.size()-1; j++)
            {
                // peak
                if(s[j] > s[j-1] && s[j] > s[j+1]) count += 1;

                // value
                else if(s[j] < s[j-1] && s[j] < s[j+1]) count += 1;
                
                else continue;
            }
        }

        return count;
    }
};
