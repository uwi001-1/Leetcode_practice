#include<iostream>
using namespace std;

// 69. Sqrt(x)

/***************
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:
Input: x = 4
Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
***************/


class Solution {
public:
    int mySqrt(int x) 
    {
        long long val = x;

        for(long long i = 0; i < 46341; i++)
        {
            if(i * i == val) return i;

            // as for example
            // 5 lies between 2^2 and 3^2, the square root should be 2
            if(val > i * i && val < (i+1) * (i+1)) return i;
        } 
        return 0;  
    }
};
