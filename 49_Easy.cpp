#include<iostream>
using namespace std;

// 342. Power of Four

/***************
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true
***************/


// to use the pow function
#include <cmath>

class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if(n == 1) return true;

        // the power of 4 cannot be negative at all
        if(n <= 0) return false;

        // loop from 1 to 31 , as that's the max value in the constraints
        for(int i = 1; i < 32; i++)
        {
            if(n == pow(4,i)) return true;
        }

        // if never true return false
        return false;
    }
};
