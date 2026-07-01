#include<iostream>
using namespace std;

// 1780. Check if Number is a Sum of Powers of Three

/***************
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
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
