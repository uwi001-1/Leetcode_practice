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


// to use the pow function
#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if(num == 1) return true;

        // loop from 2
        int i = 2; 

        while(true)
        {
            // if i^2 == num then return true
            if(num == pow(i,2)) return true;

            // as square root of 2^31 that's the max is 46340.95
            if(i >= 46340) break;
            
            i += 1;
        }

        // if never true return false
        return false;
    }
};
