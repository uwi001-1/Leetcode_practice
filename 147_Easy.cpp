#include<iostream>
using namespace std;

// 3718. Smallest Missing Multiple of K

/***************
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.

Example 1:
Input: nums = [8,2,3,4,6], k = 2
Output: 10
Explanation:
The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Example 2:
Input: nums = [1,4,7,10,15], k = 5
Output: 5
Explanation:
The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.
***************/


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ope;

        int index = 0;

        // stops when we reach the end of the target array
        for(int i = 1; i <= n && index < target.size(); i++)
        {
            if(target[index] == i)
            {
                ope.push_back("Push");
                index++;
            }            
            // when we don't need the number in the target array, we push and pop it
            else
            {
                ope.push_back("Push");
                ope.push_back("Pop");
            }
        }

        return ope;
    }
};
