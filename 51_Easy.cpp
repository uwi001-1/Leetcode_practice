#include<iostream>
using namespace std;

// 326. Power of Three

/***************
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true
    Explanation: 27 = 33

Example 2:
Input: n = 0
Output: false
    Explanation: There is no x where 3x = 0.

Example 3:
Input: n = -1
Output: false
    Explanation: There is no x where 3x = (-1).
***************/


// to use the pow function
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if(n == 1) return true;

        // the power of 3 cannot be negative at all
        if(n <= 0) return false;

        // loop from 1 to 31 , as that's the max value in the constraints
        for(int i = 1; i < 32; i++)
        {
            if(n == pow(3,i)) return true;
        }

        // if never true return false
        return false;
    }
};;
