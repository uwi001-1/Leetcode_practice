#include<iostream>
using namespace std;

// 633. Sum of Square Numbers

/***************
Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:
Input: c = 5
Output: true
    Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
***************/


class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        // start from a = 0
        long long a = 0;
        long long b = (long long)sqrt(c);

        while(a <= b)
        {
            long long s = a*a + b*b;
            
            // if s is equal to c then it follows a^2 + b^2 = c
            if(s == c) return true;

            // if s is not enough then increase a
            else if(s < c) a += 1;

            // if s is more then decrease b
            else b -= 1;
        }
        
        return false;
    }
};
