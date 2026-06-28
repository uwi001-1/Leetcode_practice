#include<iostream>
using namespace std;

// 1846. Maximum Element After Decreasing and Rearranging

/***************
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
    Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
    Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false
***************/


// to use the pow function
#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n == 1) return true;

        // the power of 2 cannot be negative at all
        if(n <= 0) return false;

        // loop from 1 to 31 , as that's the max value in the constraints
        for(int i = 1; i < 32; i++)
        {
            if(n == pow(2,i)) return true;
        }

        // if never true return false
        return false;
    }
};
